Đề bài:
Alice và Bob cần gửi những tin nhắn bí mật cho nhau. Và họ đã thảo luận ra cách để mã hoá chúng:

Alice: "Chúng ta hãy sử dụng một cách đơn giản. Chúng ta sẽ cho 'A' ứng với 1, 'B' ứng với 2,..., cứ như vậy thì 'Z' sẽ ứng với 26"

Bob: "Đó là một cách mã hoá ngớ ngẩn, Alice. Giả sử tớ muốn gửi cho cậu từ 'BEAN' thì mã sẽ là 25114. Cậu có thể giải mã nó với nhiều cách khác nhau."

Alice: "Dĩ nhiên là cậu có thể. Tuy nhiên, cậu sẽ chọn từ nào? Ngoài 'BEAN' ra thì còn có 'BEAAD', 'YAAD', 'YAN', 'YKD' và 'BEKD'. Tớ nghĩ cậu sẽ tìm ra cách giải mã đúng nhất. Và tại sao cậu lại gửi cho tớ từ 'BEAN'"

Bob: "OK, có lẽ đây là một ví dụ không tốt. Nhưng tớ cá là nếu như độ dài xâu là 5000 thì sẽ có hàng tấn cách giải mã khác nhau. Và với rất nhiều những cách đó, chắc hẳn cậu sẽ tìm ra ít nhất 2 cái có nghĩa"

Alice: "Có bao nhiêu cách giải mã?"

Bob: "Hàng tỉ tỉ cách" Vì một số lí do, Alice vẫn không bị thuyết phục bởi Bob. Vì vậy, cô ấy yêu cầu Bob viết một chương trình để xác định xem có bao nhiêu cách giải mã đối với một xâu cho trước.

Đầu vào
Bao gồm nhiều test case, mỗi cái sẽ bao gồm 1 dòng chứa một xâu có tối đa 5000 chữ số, biểu diễn một cách mã hoá hợp lệ. Ví dụ: không có dòng nào bắt đầu bởi '0'. Và không có khoảng cách giữa các kí tự. Đầu vào kết thúc bởi '0'.

Đầu ra
In đáp án. tất cả đáp án sẽ trong phạm vi giới hạn của số nguyên có dấu 64 bit.

Ví dụ
Đầu vào:

25114
1111111111
3333333333
0

Đầu ra:

6
89
1
Bạn có thể tham khảo link gốc đề bài và submit code tại đây: http://www.spoj.com/problems/ACODE/

Phân tích
Ở đây mình sử dụng thuật toán quy hoạch động Dynamic programming và triển khai theo kiểu top - down. Nghĩa là mình sẽ viết hàm đệ quy để giải quyết bài toán này.

Mình sẽ dùng một mảng một chiều là Memo[MAX]. Trong đó, Memo[i] là số cách giải mã được khi tính từ kí tự i đến cuối (i được tính từ 0). Và hàm đệ quy tương ứng là Solve(i)

Ở đây, vì các chữ cái từ 'A' đến 'Z' tương ứng với các số từ 1 đến 26. Do đó, khi duyệt mình cần chú ý đến hai trường hợp là chọn 1 chữ số hay 2 chữ số để giải mã.

Có một chú ý ở đây là chữ số '0' không thể đứng một mình và không thể đứng trước một chữ số khác. Tức là nếu mình có đầu vào là: 1026 thì ở đây, chữ cái đầu tiên chắc chắn là K, tương ứng với số 10. Do đó, kết quả có thể là KBF hoặc KZ. Không thể lấy số 1 ra để giải mã. Vì khi đó ta có A026. Mà số 0 hay 02 thì không hợp lệ.

Công thức đệ quy mình sẽ viết rõ ở trong code. Bạn có thể tham khảo ở dưới.
