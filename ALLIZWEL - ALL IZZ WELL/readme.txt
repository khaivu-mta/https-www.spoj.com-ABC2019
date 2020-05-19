Đề bài:
Mr.Giang luôn luôn nói "ALL IZZ WELL" mỗi khi anh ấy gặp rắc rối. Vì vậy, bạn bè và mọi người xung quanh luôn luôn cười anh ta. Tuy nhiên, Mr.Giang luôn tin vào niềm tin của mình. Anh ấy tin rằng cụm từ "ALLIZZWELL" sẽ làm mọi việc được giải quyết ổn thoả.

Nhiệm vụ của bạn là tạm bỏ qua câu truyện trên và tìm ra nếu như có đường đi trên ma trận tạo thành câu "ALLIZZWELL". Biết rằng có đường đi từ một cell đến tất cả các cell kề với nó. Hai cell kề nhau nếu chúng chia sẻ cạnh hoặc góc.

Đầu vào
Dòng đầu tiên bao gồm một số T biểu diễn số lượng test case. Dòng đầu tiên của mỗi test case bao gồm 2 số R và C biểu diễn số dòng và số cột của ma trận. Cuối cùng là miêu tả ma trận.

Đầu ra
Với mỗi test case, in ra "YES" nếu như có đường đi tạo thành "ALLIZZWELL". Ngược lại in ra "NO"

Chú ý: - Cẩn thận với test case số 4 - Có một dòng mới sau mỗi test case trong đầu vào

Ràng buộc:

T <= 1000 
R <= 100 
C <= 100
Ví dụ
Đầu vào:

5 
3 6 
AWE.QX 
LLL.EO 
IZZWLL 
1 10 
ALLIZZWELL 
2 9 
A.L.Z.E.. 
.L.I.W.L. 
3 3 
AEL 
LWZ 
LIZ 
1 10 
LLEWZZILLA 
Đầu ra:

YES 
YES 
NO 
NO 
YES 
Bạn có thể tham khảo đề bài tiếng anh và submit tại đây: http://www.spoj.com/problems/ALLIZWEL/

Phân tích
Bài toán này tương tự như bài toán ABCPATH. Tuy nhiên, đối với bài toán ABCPATH, đường đi là các kí tự phân biệt A, B, C,...Z. Còn với bài toán này, đường đi là "ALLIZZWELL", trong đó các kí tự có thể lặp lại. Do đó, ta phải kiểm tra tất cả các đường đi có thể bắt đầu từ kí tự 'A'.

Đó chính là thuật toán tìm kiếm theo chiều sâu DFS và Vét cạn - Brute Force.