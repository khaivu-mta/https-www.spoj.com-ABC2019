Đề bài:
Màn hình ống cũ máy tính của bạn hóa ra là nguyên nhân gây ra đau đầu mãn tính của bạn. Do đó bạn quyết định mua một trong những màn hình TFT phẳng mới. Tại lối vào của cửa hàng máy tính, bạn thấy rằng có khá đông đủ khách hàng.

(Câu tiếp theo mình không hiểu lắm. Tuy nhiên nó không quan trọng, nên mình sẽ bỏ qua. Nếu bạn hiểu câu này nói gì, vui lòng viết dưới phần bình luận để mọi người cùng hiểu nhé.) Bởi vì, bạn muốn về nhà sớm để hoàn thành công việc còn dang dở ở trên SPOJ; nên bạn muốn lé tránh đám đông được nhiều nhất có thể. Bạn xem xét tình hình ở một vài nơi và nhận ra rằng đám đông là ít hơn ở một vài chỗ ở cửa hàng. Đó là lí do cho bạn để hy vọng rằng bạn sẽ đến đích đúng giờ, với quãng đường đi ngắn nhất. Nhưng đường đi ngắn nhất là đường nào?

Bạn phác họa tình hình trên một miếng giấy. Tuy nhiên nó vẫn là một vấn đề khó. Bạn lấy ra một cuốn sổ trong túi và viết một chương trình để tìm đường đi ngắn nhất cho bạn.

Đầu vào
Dòng đầu tiên của đầu vào miêu tả chiều rộng w và chiều dài h của cửa hàng. Cả hai chiều đều không vượt quá 25. h dòng tiếp theo, mỗi dòng chứa w kí tự. Trong đó, kí tự 'S' miêu tả cái giá, kí tự 'S' là vị trí bắt đầu và kí tự 'D' là đích đến (ví dụ là một hình vuông phía trước những màn hình). Tất cả  những khối hình vuông trống được đánh số từ 1 đến 9 - là số giây cần để vượt qua khu vực hình vuông đó.

Có rất nhiều test case và được ngăn cách nhau bởi dòng trống. Đầu vào kết thúc bởi giá trị độ rộng và chiều dài là 0 0.

Đầu ra
Với mỗi test case, in ra giá trị số giây nhỏ nhất để đi được tới đích. Mỗi test case in ra trên một dòng riêng biệt. Bạn có thể di chuyển theo chiều ngang hay chiều dọc. Dĩ nhiên, bạn phải di chuyển bên trong của ma trận. Và luôn có đường để tới đích.

Ví dụ
Đầu vào:

4 3
X1S3
42X4
X1D2

5 5
S5213
2X2X5
51248
4X4X2
1445D

0 0
Đầu ra:

4
23


Link gốc: http://www.spoj.com/problems/SHOP/

Phân tích
Đây là bài toán tìm đường đi ngắn nhất cơ bản trên ma trận. Nó tương đương với bài toán tìm đường đi ngắn nhất của đồ thị có trọng số (vì các đường đi có giá khác nhau). Vì vậy, mình sử dụng thuật toán Dijkstra để giải quyết bài toán.