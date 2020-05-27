
SPIKES - SPIKY MAZES

Cho 1 mê cung chứa kim cương. Hãy kiểm tra xem với số lượng cọc mà Jarmtin có thể vượt qua từ đầu bài, kiểm tra xem Jarmtin có thể lấy được kim cương và thoát ra khỏi mê cung được hay không. Đầu tiên Jarmtin sẽ đi từ cổng vào (@) và đi đến lấy kim cương (x) và đi qua các vị trí trống (.) hoặc các vị trí có cọc (s). Các vị trí tường Jarmtin k thể đi (#). Sau khi lấy được kim cương Jarmtin sẽ thoát ra khỏi mê cung đúng vị trí (@). Nếu số lượng cọc Jarmtin đi qua cả đi lẫn về k vượt quá j (j là số lượng cọc Jarmtin có thể đi qua) thì in ra SUCCESS, nếu không hãy in ra IMPOSSIBLE.
Giải thuật:
- Tìm ra vị trí của lối vào, gọi hàm backtrack với chiều vào.
- tại mỗi ô tọa độ x, y hãy thử 4 ô xung quanh xem có thể đi hay không? nếu là vị trí trống thì đi tiếp, nếu là vị trí cọc hãy tăng số lượng cọc lên 1. nếu vượt quá số cọc cho phép thì thoát khỏi hàm.
- Sử dụng 2 mảng visited cho 2 chiều vào và ra, sau khi đến được ô kim cương (x) thì gọi hàm backtrack với chiều ra.
- Nếu chiều ra gặp được ô (@) tức là cách đi thỏa mãn, sử dụng cờ để thoát khỏi đệ quy.
Chú ý: Bài này giải cho trường hợp tổng quá cổng vào và cổng ra nằm ở 2 tọa độ khác nhau. Còn với yêu cầu của bài này lối vào và lối ra là 1 ta chỉ cần tìm đường đi từ @ đến x với số lượng cọc đi qua là ít nhất và nhân 2 lần cho cả đường đi và về là xong :D
