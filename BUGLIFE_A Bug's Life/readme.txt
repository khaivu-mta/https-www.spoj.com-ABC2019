Đề bài:
Giáo sư Hopper đang nghiên cứu về hành vi giới tính của một dạng hiếm có của loài bọ. Ông ta giả sử rằng chúng chia ra làm 2 giới tính khác nhau. Và chúng chỉ tương tác với những loài có giới tính khác. Theo nghiên cứu của ông, những con bọ riêng lẻ và hành vi của chúng rất dễ để nhận ra. Bởi vì những số được in trên lưng của chúng.

Cho trước một danh sách sự tương tác giữa những con bọ. Hãy quyết định xem nếu như những nghiên cứu ủng hộ giả sử của ông ta rằng không có tình dục đồng giới hoặc có tồn tại điều đó.

Đầu vào
Dòng đầu tiên chứa số lượng test case. Mỗi test case bắt đầu với một dòng gồm 2 số. Số thứ nhất là số con bọ (giá trị thuộc từ 1 đến 2000) và số tương tác (giá trị lên đến 1000000) được phân cách nhau bởi dấu cách. Các dòng tiếp theo, mỗi dòng mô tả một tương tác, gồm 2 số nguyên khác nhau, là chỉ số của con bọ. Các con bọ được đánh số liên tiếp và bắt đầu từ 1.

Đầu ra
Với mỗi test case, sẽ là một dòng dạng "Scenario #i:" với i là chỉ số test case, bắt đầu từ 1. Theo sau bởi một dòng là "No suspicious bugs found!" nếu phù hợp với giả sử của giáo sư là không có tình dục đồng giới. Ngược lại thì là "Suspicious bugs found!".

Ví dụ
Đầu vào:

2
3 3
1 2
2 3
1 3
4 2
1 2
3 4
Đầu ra:

Scenario #1:
Suspicious bugs found!
Scenario #2:
No suspicious bugs found!


Giải thích:
Với test case 1: có điều khả nghi được tìm thấy. Vì 1 tương tác với 2 nên chứng tỏ 1 và 2 khác giới nhau. Tiếp theo 2 tương tác với 3 chứng tỏ 2 và 3 khác giới nhau. Từ hai điều trên suy ra 1 và 3 phải cùng giới. Nhưng 1 và 3 lại có tương tác. Từ đó, suy ra có hiện tượng tình dục đồng giới.

Với test case 2: rõ ràng thỏa mãn không có tình dục đồng giới.

Link gốc đề bài và submit code tại đây: http://www.spoj.com/problems/BUGLIFE/


Phân tích
Rõ ràng đây là bài toán chia đôi đồ thị. Sử dụng thuật toán tìm kiếm theo chiều sâu DFS để duyệt các con bọ và đánh số các con bọ theo quy luật là 2 con bọ có tương tác với nhau sẽ được đánh dấu khác nhau (ví dụ 1 và 2).

Do đó, những con bọ được đánh dấu cùng loại sẽ có cùng giới tính. Như vậy, nếu 2 con bọ nào được đánh dấu cùng loại mà lại có tương tác thì suy ra kết quả là tồn tại tình dục đồng giới. Ngược lại sẽ là không.