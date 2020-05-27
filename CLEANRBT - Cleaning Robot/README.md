CLEANRBT - CLEANING ROBOT

Cho 1 ma trận chứa 1 con robot và các vết bẩn, hãy tính số bước đi tối thiểu để con robot có thể lau hết tất cả các vết bẩn này.
Giải thuật:
Bài này chúng ta có 1 điểm bắt đầu và N điểm cần đi qua.
- Không thể xác định điểm nào sẽ đi đầu tiên để số bước đi là lớn nhất vì vậy với N + 1 điểm. Hãy xây dựng ma trận N+1 x N+1. Với i và j thuộc N+1 điểm thì giá trị của ma trận [i][j] chính là đường đi ngắn nhất từ i đến j.
- Việc tính toán đường đi ngắn nhất từ i đến j có thể thông qua thuật toán BFS. cụ thể ở đây ta sẽ tạo ra N+1 bảng BFS tương ứng với N+1 điểm này.
