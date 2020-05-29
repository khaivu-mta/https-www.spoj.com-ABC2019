# [Mô tả thuậy toán A*](https://voer.edu.vn/m/giai-thuat-tim-kiem-a/d169b9dd)
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
