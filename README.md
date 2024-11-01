# Problem A : 
- Gọi *dp[i][s][ok]* là giá trị lớn nhất có thể lấy được trong đoạn từ 1 đến i, tổng độ nặng trong túi là s, ok thể hiện tay còn lại đã lấy món đồ nào chưa.
- Ta có công thức chuyển trạng thái : 

        minimize(dp[i][s][ok], dp[i-1][s][ok]); // Không lấy vật thứ i 
        if (s + c[i] <= maxsum) minimize(dp[i][s + c[i]][ok], dp[i-1][s][ok] + w[i]); // Lấy vật thứ i bỏ vào túi
        if (!ok && w[i] <= H) minimize(dp[i][s + c[i]][1], dp[i-1][s][ok]); // Lấy vật thứ i bằng tay còn lại
  
- Đáp án của ta sẽ là thằng s lớn nhất thõa *min(dp[n][s][0], dp[n][s][1]) <= W*.

# Problem B : 
- Đề yêu cầu tìm bộ (i, j, p, q) thứ k theo thứ tự từ điểm mà ta có thể giải quyết bằng N^2.
- Từ đó, ta có thể suy ra thuật toán, for cố định (i, j), với mỗi bộ (i, j) ta đếm nhanh xem có bao nhiêu bộ (p, q) thõa. Từ đó ta có thể suy ra là bộ thứ k có mở đầu bằng bộ (i, j) không. Từ đó ta có thể suy ra đáp án của bài toán.
-  Để đếm nhanh số bộ (p, q) thõa. Ta có thể dùng cách như sau : 
  - Gọi dd[mask] là số cặp (i, j) thõa mãn (a[i] & a[j]) == mask. Từ đó ta có thể dùng dpSOS để lưu dd[mask] thành số bộ (i , j) có (a[i] & a[j]) là mask con của mask.
  - Từ đó, với mỗi bộ (i, j), ta sẽ cần phải xóa các mask còn dư là (a[i] & a[j]). => Đáp án sẽ là dd[2^(20) - 1 ^ (a[i] & a[j])];
