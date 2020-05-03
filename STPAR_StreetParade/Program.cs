using System;

namespace STPAR_StreetParade
{
    class Program
    {
        static bool themDanhSach(int value, ref int[] arr, ref int arrCount, bool tangDan)
        {
            if (arrCount <= 0)
            {
                arrCount = 1;
                arr[arrCount - 1] = value;
                return true;
            }

            if (tangDan && value >= arr[arrCount - 1]
                || !tangDan && value <= arr[arrCount - 1])
            {
                ++arrCount;
                arr[arrCount - 1] = value;
                return true;
            }
            return false;
        }

        static void Main(string[] args)
        {
            int xeNgachPhu = 0, xeKetQua = 0;
            int soluongxe = 0;

            while (true)
            {
                soluongxe = int.Parse(System.Console.ReadLine());
                int[] ngachPhu = new int[soluongxe];
                int[] ketQua = new int[soluongxe];
                xeNgachPhu = 0;
                xeKetQua = 0;

                if (soluongxe <= 1)
                {
                    Console.WriteLine("yes");
                    continue;
                }

                int[] arr = new int[soluongxe];

                string readLine = Console.ReadLine();
                string[] stringArray = readLine.Split(' ');
                for (int i = 0; i < stringArray.Length; i++)
                {
                    arr[i] = int.Parse(stringArray[i]);
                }

                bool end = arr[1] <= arr[0]
                            ? themDanhSach(arr[0], ref ngachPhu, ref xeNgachPhu, false)
                            : themDanhSach(arr[0], ref ketQua, ref xeKetQua, true);
                for (int i = 1; i + 1 <= soluongxe && end; ++i)
                {
                    if(i + 1 == soluongxe)
                    {
                        end = themDanhSach(arr[i], ref ketQua, ref xeKetQua, true);
                        break;
                    }
                    if (arr[i] >= arr[i + 1])
                        end = themDanhSach(arr[i], ref ngachPhu, ref xeNgachPhu, false);
                    else if (end = themDanhSach(arr[i], ref ketQua, ref xeKetQua, true)) { }
                    else
                        end = themDanhSach(arr[i], ref ngachPhu, ref xeNgachPhu, false);
                }

                if (ketQua[xeKetQua - 1] > ngachPhu[xeNgachPhu - 1])
                    end = false;

                if (end)
                    System.Console.WriteLine("yes");
                else
                    Console.WriteLine("no");
            }
        }
    }
}
