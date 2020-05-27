Đề bài:
Một trong những phòng bí mật của Hogwarts là đầy đá. Sàn nhà của phòng có kích thước h x w, được lát bởi những viên đá hoa hình vuông. Trong đó h dòng tính từ trước ra sau và w cột tính từ trái sang phải. Mỗi viên đá hóa chứa 1 đến 100 viên đá trên đó. Harry phải nhặt nhiều đá nhất có thể và phải theo chỉ dẫn sau:

Anh ta chọn một viên đá hoa bất kì từ hàng trên cùng và sau đó nhặt lấy những viên đá trên đó. Sau đó, anh ta di chuyển đến viên đá hoa ở hàng tiếp theo, rồi lại nhặt những viên đá trên đó. Cứ như vậy tiếp tục cho đến khi anh ta đi đến hàng cuối cùng.

Khi anh ta di chuyển từ một viên đá hoa đến một viên đá hoa khác ở hàng tiếp theo, anh ta chỉ được phép di chuyển đến viên đá hoa ở phía dưới hoặc viên đá hoa ở chéo phía bên trái hay phải.

Cho trước giá trị của h, w và số lượng những viên đá trên mỗi ô vuông. Viết chương trình tính số lượng viên đá tối đa mà Harry có thể nhặt được khi đi từ hàng đầu tiên đến hàng cuối cùng.

Đầu vào
Dòng đầu tiên chứa số lượng test case T, 1 <= T <= 100. Mỗi test case, dòng đầu tiên chứa 2 số nguyên h và w, với h là số hàng và w là số cột, 1 <= h, w <= 100. Tiếp theo sẽ là h dòng, mỗi dòng chứa w giá trị - là số lượng những viên đá trên mỗi ô, gọi là m, 0 <= m <= 100. Các số nguyên được phân cách nhau bởi một dấu cách.

Đầu ra
Với mỗi test case, in ra một dòng chứa một số nguyên, là số lượng viên đá tối đa mà Harry có thể thu thập được theo quy tắc đã nêu ở trên.

Ví dụ
Đầu vào:

1
6 5
3 1 7 4 2
2 1 3 1 1
1 2 2 1 8
2 2 1 5 3
2 1 4 4 4
5 2 7 5 1
Đầu ra:

32
Giải thích:
Harry sẽ đi theo các ô có số lượng đá là: 7 + 1 + 8 + 5 + 4 + 7 = 32

Bạn có thể tham khảo link gốc đề bài và submit code tại đây: http://www.spoj.com/problems/BYTESM2/

Phân tích
Mình sẽ sử dụng thuật toán quy hoạch động Dynamic programming, viết theo kiểu bottom up (dùng vòng lặp) để giải quyết bài toán.

Mình sẽ sử dụng một mảng hai chiều để lưu số lượng đá lớn nhất tại mỗi ô khi đi từ trên xuống dưới ô đó. Chú ý là khi đi từ trên xuống ta chỉ có thể đi xuống dưới, hoặc chéo trái, hoặc chéo phải.
