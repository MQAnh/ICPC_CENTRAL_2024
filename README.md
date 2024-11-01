# Problem A : 
- Gọi *dp[i][s][ok]* là giá trị lớn nhất có thể lấy được trong đoạn từ 1 đến i, tổng độ nặng trong túi là s, ok thể hiện tay còn lại đã lấy món đồ nào chưa.
- Ta có công thức chuyển trạng thái : 

        minimize(dp[i][s][ok], dp[i-1][s][ok]); // Không lấy vật thứ i 
        if (s + c[i] <= maxsum) minimize(dp[i][s + c[i]][ok], dp[i-1][s][ok] + w[i]); // Lấy vật thứ i bỏ vào túi
        if (!ok && w[i] <= H) minimize(dp[i][s + c[i]][1], dp[i-1][s][ok]); // Lấy vật thứ i bằng tay còn lại
  
- Đáp án của ta sẽ là thằng s lớn nhất thõa *min(dp[n][s][0], dp[n][s][1]) <= W*.

# Problem B : 
- Đề yêu cầu tìm bộ *(i, j, p, q)* thứ k theo thứ tự từ điểm mà ta có thể giải quyết bằng *N^2*.
- Từ đó, ta có thể suy ra thuật toán, for cố định *(i, j)*, với mỗi bộ *(i, j)* ta đếm nhanh xem có bao nhiêu bộ *(p, q)* thõa. Từ đó ta có thể suy ra là bộ thứ *k* có mở đầu bằng bộ *(i, j)* không. Từ đó ta có thể suy ra đáp án của bài toán.
-  Để đếm nhanh số bộ *(p, q)* thõa. Ta có thể dùng cách như sau : 
  - Gọi *dd[mask]* là số cặp *(i, j)* thõa mãn *(a[i] & a[j]) == mask*. Từ đó ta có thể dùng dpSOS để lưu *dd[mask]* thành số bộ *(i , j)* có *(a[i] & a[j])* là mask con của *mask*.
  - Từ đó, với mỗi bộ *(i, j)*, ta sẽ cần phải xóa các mask còn dư là *(a[i] & a[j])*.
  - Đáp án sẽ là *dd[2^(20) - 1 ^ (a[i] & a[j])]*;

# Promblem E : 
- Đầu tiên ta lưu lại các điểm là 'S' vào trong một cái vector.
- Sau đó ta sẽ thực hiện bfs để tìm khoảng cách giữa các điểm S.
- Sau đó ta sẽ bfs từ đỉnh (1, 1).
- Sau đó ta sẽ thực hiện như bài toán tsp để tìm một hành trình đơn đi hết các đảo S mà tổng quảng đường là nhỏ nhất.

# Problem F : 
- Ta sẽ chia nhóm người thành 2^3 - 1 nhóm thể hiện sở thích chung của mỗi người. (Nhóm thứ mask với bit 1 thể hiện người trong nhóm đó thích công ty thứ bit đó).
- Ta có một nhận xét rằng vì giá trị của mỗi người là như nhau, điều đó đồng nghĩa là khi thay thế một người này bằng một người khác thì tổng giá trị cũng không đổi. Do đó ai có thể tham gia được thì ta cứ cho họ tham gia.
- Ta thực hiện chiến thuật tham lam như sau : 
- Các nhóm mà thích 1 công ty thì cứ tham gia.
- Đôi với nhóm thích 2 công ty : 
- Nếu nhóm thích công ty ab > lim[a] + lim[b]
  - Thì cứ tham gia hết công ty a và b. Còn lại thì ai tham gia được công ty c thì cứ tham gia.
- Nếu nhóm thích công ty ab < lim[a] + lim[b]
  - Ta cố định có x người sẽ tham gia công ty A, suy ra sẽ có dd[ab] - x người thích tham gia công ty b. Từ đó ta sẽ tham theo kiểu với bc, ac, thì ai có thể tham gia a, b, c được thì cứ tham gia. (dd[ab] là số lượng người thích tham gia công ty ab).
- Các nhóm mà thích 3 công ty thì có thể tham gia nhóm nào được thì cứ tham gia.
