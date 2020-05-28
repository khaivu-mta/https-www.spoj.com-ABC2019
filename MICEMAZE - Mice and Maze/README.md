Đề bài:
Một tập hợp những con chuột thí nghiệm đang được huấn luyện để thoát khỏi mê cung. Mê cung được tạo bởi những ô, mà mỗi ô được kết nối tới những ô khác. Tuy nhiên, sẽ có những vật cản trên đường đi giữa các ô. Vì vậy, sẽ cần thêm thời gian để vượt qua những vật cản này. Một vài đường chỉ cho phép con chuột đi theo một chiều và không có đường vòng.

Giả sử là tất cả lũ chuột đã được huấn luyện, khi được đặt ở một ô bất kì trên mê cung, tìm đường để đưa chúng ra khỏi mê cung với thời gian ngắn nhất.

Chúng ta sẽ làm một thí nghiệm như sau: mỗi một con chuột được đặt vào một ô trên mê cung và một đồng hồ đếm ngược được bắt đầu. Khi đồng hồ dừng lại, đếm số chuột thoát ra được mê cung.

Vấn đề:

Viết một chương trình, cho trước thông tin của những con chuột và thời gian giới hạn. Dự đoán số chuột thoát ra được khỏi mê cung. Giả sử rằng sẽ không có nút thắt cổ chai nào trên mê cung, tất cả các ô sẽ có đủ khoảng trống để chứa số lượng chuột ngẫu nhiên.

Đầu vào
Các ô trong mê cung được đánh số từ 1 đến N, trong đó N là số lượng ô, N <= 100. Ba dòng đầu tiên chứa số N - số lượng ô, E - chỉ số của ô lối thoát và giá trị T là thời gian bắt đầu của đồng hồ đếm ngược.

Dòng thứ 4 là số M - số lượng kết nối trong mê cung. Sau đó là M dòng. Mỗi dòng xác định 1 kết nối, bao gồm 3 số là số a, b và c. Trong đó a, b là chỉ số của các ô (a, b thuộc từ 1 đến N), và c là thời gian cần để đi từ a đến b.

Chú ý rằng mỗi kết nối là một chiều, tức là con chuột không thể đi từ b về a trừ khi có kết nối từ b đến a. Cũng chú ý là, thời gian di chuyển trên mỗi hướng là khác nhau.

Đầu ra
Mỗi test case in ra trên một dòng, là số lượng chuột đến được ô thoát Exit của mê cung trong thời gian T.

Ví dụ
Đầu vào:

4 
2 
1
8
1 2 1
1 3 1
2 1 1
2 4 1
3 1 1
3 4 1
4 2 1
4 3 1

Đầu ra:

3

Bạn có thể tham khảo link gốc đề bài và submit code tại đây: http://www.spoj.com/problems/MICEMAZE/

Phân tích
Theo suy luận thông thường, mình sẽ phải xét mỗi con chuột, tìm đường đi ngắn nhất của nó đến ô thoát. Kiểm tra xem thời gian đó có nhỏ hơn hoặc bằng thời gian giới hạn T hay không. Nếu thỏa mãn thì con chuột đó sẽ thoát được khỏi mê cung trong thời gian cho phép. Tuy nhiên, nếu xét riêng từng con như vậy, chắc chắn sẽ bị time limit.

Bài toán ở đây là tìm đường đi ngắn nhất từ N điểm đến 1 điểm. Thực chất, mình sẽ quy về bài toán tìm đường đi ngắn nhất từ 1 điểm đến N điểm. Bằng cách đảo ngược lại chiều của các đường đi.

Để tìm đường đi ngắn nhất từ một điểm đến N điểm, mình sử dụng thuật toán Dijkstra
