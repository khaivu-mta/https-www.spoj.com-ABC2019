Đề bài:
Bạn được yêu cầu tìm thuật toán để giải quyết bài toán sudoku cơ bản.

Đầu vào
Dòng đầu vào bao gồm số lượng test case t, 1 <= t <= 15. Mỗi test case bao gồm 81 số từ 0 đến 9 được phân cách nhau bởi dấu cách, và 9 số trên 1 dòng. Số 0 nghĩa là số cần phải điền.

Đầu ra
Nếu không tồn tại giải pháp để giải quyết bài toán thì in ra "No solution". Ngược lại thì bạn phải in 81 số đó ra, và phân cách nhau giống như đầu vào.

Bạn có thể tham khảo đề bài tiếng anh và submit code tại: http://www.spoj.com/problems/EASUDOKU/

Phân tích
Trước khi giải bài toán này, bạn chắc đã biết về sudoku. Còn nếu bạn chưa biết về sudoku thì sau đây mình sẽ giới thiệu qua về luật chơi, như sau:

Có nhiều loại sudoku, ở đây là bài toán sudoku cơ bản. Kích thước là 9×9. Và được chia ra làm 9 khối nhỏ hơn có kích thước 3×3. Sudoku được giải khi tất cả các số trên ma trận đã được điền hết.

Thoả mãn yêu cầu: Trên mỗi hàng, mỗi cột, và mỗi khối 3×3 nhỏ phải được điền các số từ 1 đến 9, mỗi số xuất hiện đúng 1 lần, tức là không số nào được lặp lại từ 2 lần trở lên;

Qua đó, thuật toán có thể sử dụng ở đây đó là thuật toán quay lui có điều kiện - backtracking. Nghĩa là, tại mỗi ô cần giải, ta sẽ điền thử từ 1 đến 9. Nếu ta có thể điền hết thì đó chính là giải pháp. Ngược lại thì sẽ không có giải pháp cho bài toán.
