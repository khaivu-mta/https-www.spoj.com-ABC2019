### [Mô tả thuật toán A*](https://voer.edu.vn/m/giai-thuat-tim-kiem-a/d169b9dd)
## Ý tưởng trực quan
Xét bài toán tìm đường - bài toán mà A* thường được dùng để giải. A* xây dựng tăng dần tất cả các tuyến đường từ điểm xuất phát cho tới khi nó tìm thấy một đường đi chạm tới đích. Tuy nhiên, cũng như tất cả các thuật toán tìm kiếm có thông tin (informed tìm kiếm thuật toán), nó chỉ xây dựng các tuyến đường "có vẻ" dẫn về phía đích.

Để biết những tuyến đường nào có khả năng sẽ dẫn tới đích, A* sử dụng một "đánh giá heuristic" về khoảng cách từ điểm bất kỳ cho trước tới đích. Trong trường hợp tìm đường đi, đánh giá này có thể là khoảng cách đường chim bay - một đánh giá xấp xỉ thường dùng cho khoảng cách của đường giao thông.

Điểm khác biệt của A* đối với tìm kiếm theo lựa chọn tốt nhất là nó còn tính đến khoảng cách đã đi qua. Điều đó làm cho A* "đầy đủ" và "tối ưu", nghĩa là, A* sẽ luôn luôn tìm thấy đường đi ngắn nhất nếu tồn tại một đường đi như thế. A* không đảm bảo sẽ chạy nhanh hơn các thuật toán tìm kiếm đơn giản hơn. Trong một môi trường dạng mê cung, cách duy nhất để đến đích có thể là trước hết phải đi về phía xa đích và cuối cùng mới quay lại. Trong trường hợp đó, việc thử các nút theo thứ tự "gần đích hơn thì được thử trước" có thể gây tốn thời gian.

## Mô tả thuật toán
A* lưu giữ một tập các lời giải chưa hoàn chỉnh, nghĩa là các đường đi qua đồ thị, bắt đầu từ nút xuất phát. Tập lời giải này được lưu trong một hàng đợi ưu tiên (priority queue). Thứ tự ưu tiên gán cho một đường đi x được quyết định bởi hàm f(x) = g(x) + h(x).

Trong đó, g(x) là chi phí của đường đi cho đến thời điểm hiện tại, nghĩa là tổng trọng số của các cạnh đã đi qua. h(x) là hàm đánh giá heuristic về chi phí nhỏ nhất để đến đích từ x. Ví dụ, nếu "chi phí" được tính là khoảng cách đã đi qua, khoảng cách đường chim bay giữa hai điểm trên một bản đồ là một đánh giá heuristic cho khoảng cách còn phải đi tiếp.

Hàm f(x) có giá trị càng thấp thì độ ưu tiên của x càng cao (do đó có thể sử dụng một cấu trúc heap tối thiểu để cài đặt hàng đợi ưu tiên này).
![Mô tả thuật toán A*](https://vi.wikipedia.org/wiki/T%E1%BA%ADp_tin:Astar_progress_animation.gif)
```
function A*(điểm_xuất_phát,đích)
    var đóng := tập rỗng
    var q := tạo_hàng_đợi(tạo_đường_đi(điểm_xuất_phát))
    while q không phải tập rỗng
    var p := lấy_phần_tử_đầu_tiên(q)
    var x := nút cuối cùng của p
    if x in đóng
    continue
    if x = đích
    return p
    bổ sung x vào tập đóng
    foreach y in các_đường_đi_tiếp_theo(p)
    đưa_vào_hàng_đợi(q, y)
    return failure
```
### [Mô tả thuật toán Bellman-Ford](https://vi.wikipedia.org/wiki/Thu%E1%BA%ADt_to%C3%A1n_Bellman-Ford)
# Ý tưởng trực quan
Ý tưởng thuật toán Bellman-Ford có tính tham lam:

Ta thực hiện duyệt V lần, với V là số đỉnh của đồ thị.
Với mỗi lần duyệt, ta tìm tất cả các cạnh mà đường đi qua cạnh đó sẽ rút ngắn đường đi ngắn nhất từ đỉnh gốc tới một đỉnh khác.
Ở lần duyệt thứ V, nếu còn bất kỳ cạnh nào có thể rút ngắn đường đi, điều đó chứng tỏ đồ thị có chu trình âm, và ta kết thúc thuật toán.

# Ví dụ
Ta xét ví dụ với đồ thị có hướng sau (giả định các đường đi là một chiều, chỉ đi từ đỉnh có số thứ tự thấp hơn tới đỉnh có số thứ tự cao hơn, số có màu đỏ cạnh mỗi đỉnh là độ dài đường đi ngắn nhất từ gốc tới đỉnh đó, và đỉnh gốc là đỉnh 1):

![cses-fi-bellmanford1](https://thuytrangcoding.files.wordpress.com/2018/03/cses-fi-bellmanford1.png)

Thực hiện lần duyệt đầu tiên, ta cập nhật được đường đi ngắn nhất thông qua các cạnh (1, 2); (1, 3); (1, 4):

![cses-fi-bellmanford2](https://thuytrangcoding.files.wordpress.com/2018/03/cses-fi-bellmanford2.png)

Tương tự với lần duyệt thứ 2, cạnh (2, 5) và (3, 4) là các cạnh tối ưu:

![cses-fi-bellmanford3](https://thuytrangcoding.files.wordpress.com/2018/03/cses-fi-bellmanford3.png)

Với lần duyệt thứ 3, chỉ có cạnh (4, 5) cải tiến đường đi tối ưu:

![cses-fi-bellmanford4](https://thuytrangcoding.files.wordpress.com/2018/03/cses-fi-bellmanford4.png)

Tới lần duyệt thứ 4, ta thấy không còn cạnh nào có thể tối ưu hóa bất kỳ đường đi ngắn nhất nào nữa. Tới đây, ta hoàn toàn có thể dừng duyệt (vì chắc chắn việc không còn cạnh có thể tối ưu cũng đồng nghĩa với việc không có chu trình âm trong đồ thị).

# Mô tả thuật toán
```
function BellmanFord(danh_sách_đỉnh, danh_sách_cung, nguồn)
   // hàm yêu cầu đồ thị đưa vào dưới dạng một danh sách đỉnh, một danh sách cung
   // hàm tính các giá trị khoảng_cách và đỉnh_liền_trước của các đỉnh, 
   // sao cho các giá trị đỉnh_liền_trước sẽ lưu lại các đường đi ngắn nhất.

   // bước 1: khởi tạo đồ thị
   for each v in danh_sách_đỉnh:
       if v is nguồn then khoảng_cách(v):= 0
       else khoảng_cách(v):= vô cùng
       đỉnh_liền_trước(v):= null
   
   // bước 2: kết nạp cạnh
   for i from 1 to size(danh_sách_đỉnh)-1:       
       for each (u,v) in danh_sách_cung:
           if khoảng_cách(v) > khoảng_cách(u) + trọng_số(u,v):
               khoảng_cách(v):= khoảng_cách(u) + trọng_số(u,v)
               đỉnh_liền_trước(v):= u

   // bước 3: kiểm tra chu trình âm
   for each (u,v) in danh_sách_cung:
       if khoảng_cách(v) > khoảng_cách(u) + trọng_số(u,v):
           error "Đồ thị chứa chu trình âm"
```
