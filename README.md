# Problem A : 
- Gọi *dp[i][s][ok]* là giá trị lớn nhất có thể lấy được trong đoạn từ 1 đến i, tổng độ nặng trong túi là s, ok thể hiện tay còn lại đã lấy món đồ nào chưa.
- Ta có công thức chuyển trạng thái : 

        minimize(dp[i][s][ok], dp[i-1][s][ok]); // Không lấy vật thứ i 
        if (s + c[i] <= maxsum) minimize(dp[i][s + c[i]][ok], dp[i-1][s][ok] + w[i]); // Lấy vật thứ i bỏ vào túi
        if (!ok && w[i] <= H) minimize(dp[i][s + c[i]][1], dp[i-1][s][ok]); // Lấy vật thứ i bằng tay còn lại
  
- Đáp án của ta sẽ là thằng s lớn nhất thõa *min(dp[n][s][0], dp[n][s][1]) <= W*.
