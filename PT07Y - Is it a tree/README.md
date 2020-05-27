Đề bài:
Bạn được cho một đồ thị không trọng số, và vô hướng. Viết chương trình để kiểm tra xem nó có phải là cây hay không.

Đầu vào
Dòng đầu tiên của đầu vào sẽ bao gồm 2 số nguyên N và M, tương ứng là số lượng các điểm và số lượng cạnh trên đồ thị, với 0 < N <= 10000, 0 <= M <= 20000. Tiếp theo là M dòng chứa thông tin M cạnh của đồ thị. Mỗi dòng bao gồm một cặp u,v, nghĩa là có 1 cạnh giữa 2 điểm u, v với 1 <= u,v <= N.

Đầu ra
In ra "YES" nếu như đồ thị đó là cây, ngược lại in ra "NO".

Ví dụ
Đầu vào:

3 2 
1 2 
2 3 
Đầu ra:

YES 
Bạn có thể tham khảo đề bài tiếng anh và submit code tại: http://www.spoj.com/problems/PT07Y/

Phân tích
Trước tiên, để giải được bài toán này, bạn phải hiểu thế nào là cây. Theo mình hiểu một cách đơn giản là: cây là một đồ thị liên thông, và không có chu trình nào. Do đó, nếu cây có N đỉnh thì sẽ có đúng N-1 cạnh.

Ta sẽ dùng thuật toán tìm kiếm theo chiều sâu DFS để duyệt đồ thị.
