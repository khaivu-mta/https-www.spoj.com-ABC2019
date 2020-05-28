Đề bài:
Ngày xửa ngày xưa, tại một thành phố, người dân quyết định lựa chọn ra một vị thị trưởng. Tại thời điểm đó, có một ý tưởng rất mới và chiến dịch bầu cử hoàn toàn chưa biết. Nhưng dĩ nhiên một vài người dân muốn trở thành thị trưởng. Và nó không mất thời gian để nhận ra rằng việc đưa ra những lời hứa tốt sẽ không trở nên có hiệu quả. Một ứng cử viên được chọn nếu như những món quà giá trị của ông ta đem lại lợi ích cho những người dân trong thành phố.

Một ngày trước ngày bầu cử, một ứng cử viên đã hứa với người dân trong thành phố. Nếu như chiến thắng trong cuộc bầu cử thì anh ta sẽ đảm bảo rằng: tại một trong những con đường của thành phố sẽ được lắp đèn. Và anh ta sẽ trả mọi khoản phí. Người dân cuối cùng đã lựa chọn anh ta. Và một ngày sau ngày bầu cử, người dân đã trình bày quyết định của họ về tuyến đường nào sẽ được chọn. Dĩ nhiên họ không chỉ chọn đoạn đường dài nhất trong thành phố mà họ còn thay đổi tên của chúng để được một đoạn đường dài nhất có thể. Bạn có thể tìm ra độ dài của đoạn phố này không? Để chi tiết hơn, bạn được đưa cho danh sách của các đoạn đường. Cho biết giữa hai điểm chỉ có một đoạn đường duy nhất. Nhiệm vụ của bạn là tìm ra khoảng cách lớn nhất giữa hai điểm trong thành phố.

Đầu vào
Dòng đầu tiên của đầu vào bao gồm 1 số T là số lượng test cases. Dòng đầu tiên của mỗi test case bao gồm số lượng các điểm n với 2 <= n <= 50000. Mỗi đường được đưa ra trên một dòng bởi 2 điểm a, b (1 <= a, b <= n) và độ dài của nó l (0 <= l < 20000).

Đầu ra
Với mỗi testcase, in ra kết quả cần tìm.

Ví dụ
Đầu vào:

1 
6 
1 2 3 
2 3 4 
2 6 2 
6 4 6 
6 5 5 
Đầu ra:

12 
Bạn có thể tham khảo đề bài tiếng anh và submit tại đây: http://www.spoj.com/problems/BENEFACT/

Phân tích
Ở đây, số lượng điểm tối đa là 50000, do đó ta bắt buộc phải dùng danh sách liên kết. Nếu không thì ta sẽ không thể lưu trữ được dữ liệu đầu vào.

Thuật toán để giải quyết bài toán là: ta sẽ sử dụng thuật toán tìm kiếm theo chiều rộng - BFS 2 lần. Lần thứ nhất, BFS tại 1 điểm bất kì, giả sử là điểm 1. Sau lần này ta sẽ tìm ra điểm ở xa điểm 1 nhất, gọi là idMax. Lần thứ hai, ta sẽ BFS từ điểm idMax. Tiếp tục ta lại tìm được một điểm nằm xa điểm idMax nhất, gọi là idMax2. Khoảng cách giữa idMax và idMax2 là kết quả cần tìm.
