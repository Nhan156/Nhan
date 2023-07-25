#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;
//5
int demSoLuongChuSo(int n) {
    int count = 0;
    while (n > 0) {
        n /= 10;
        count++;
    }
    return count;
}

int tinhTongCacChuSo(int n) {
    int sum = 0;
    while (n > 0) {
        int chuSo = n % 10;
        sum += chuSo;
        n /= 10;
    }
    return sum;
}
//6
double tinhCuocTruyCap(int gioBatDau, int gioKetThuc, int thoiGian, double mienGia, double giamGia) {
    double cuocTruyCap = thoiGian * mienGia;
    if (thoiGian > giamGia) {
        cuocTruyCap *= (1.0 - giamGia / 100.0);
    }
    return cuocTruyCap;
}
//7
double tinhTienThuePhong(int soNgay, char loaiPhong) {
    double giaPhong;
    switch (loaiPhong) {
        case 'A':
            giaPhong = 250000;
            break;
        case 'B':
            giaPhong = 200000;
            break;
        case 'C':
            giaPhong = 150000;
            break;
        default:
            cout << "Loai phong khong hop le" << endl;
            return 0.0;
    }

    double tongTien = soNgay * giaPhong;
    double phanTramGiam;
    
    if (soNgay >= 12) {
        if (loaiPhong == 'A') {
            phanTramGiam = 10;
        } else {
            phanTramGiam = 8;
        }
        tongTien -= tongTien * phanTramGiam / 100.0;
    }

    return tongTien;
}

//8
bool laNamNhuan(int nam) {
    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}

int soNgayTrongThang(int thang, int nam) {
    int ngayTrongThang[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (thang == 2 && laNamNhuan(nam)) {
        return 29;
    }
    return ngayTrongThang[thang];
}

bool ngayHopLe(int ngay, int thang, int nam) {
    if (thang < 1 || thang > 12) {
        return false;
    }
    if (ngay < 1 || ngay > soNgayTrongThang(thang, nam)) {
        return false;
    }
    return true;
}

void timNgayHomSau(int &ngay, int &thang, int &nam) {
    ngay++;
    if (ngay > soNgayTrongThang(thang, nam)) {
        ngay = 1;
        thang++;
        if (thang > 12) {
            thang = 1;
            nam++;
        }
    }
}

void timNgayHomTruoc(int &ngay, int &thang, int &nam) {
    ngay--;
    if (ngay == 0) {
        thang--;
        if (thang == 0) {
            thang = 12;
            nam--;
        }
        ngay = soNgayTrongThang(thang, nam);
    }
}


//9
double tinhTienTaxi(int soKm) {
    double giaKmDau = 15000;
    double giaTuKm2Den5 = 13500;
    double giaTuKm6TroDi = 11000;
    double giamGiaTren120Km = 0.10;

    double tongTien = 0.0;

    if (soKm > 0) {
        tongTien += giaKmDau;
        soKm--;

        if (soKm > 0) {
            int kmDen5 = min(4, soKm);
            tongTien += kmDen5 * giaTuKm2Den5;
            soKm -= kmDen5;
        }

        if (soKm > 0) {
            tongTien += soKm * giaTuKm6TroDi;
        }

        if (soKm > 120) {
            double giamGia = tongTien * giamGiaTren120Km;
            tongTien -= giamGia;
        }
    }

    return tongTien;
}
//10
// Hàm tính điểm trung bình 3 môn
double diemTrungBinh(double diemToan, double diemLy, double diemHoa) {
    return (diemToan + diemLy + diemHoa) / 3.0;
}

// Hàm phân loại học sinh dựa trên điểm trung bình
string phanLoai(double diemTrungBinh) {
    if (diemTrungBinh >= 9.0) {
        return "Xuat sac";
    } else if (diemTrungBinh >= 8.0) {
        return "Gioi";
    } else if (diemTrungBinh >= 6.5) {
        return "Kha";
    } else if (diemTrungBinh >= 5.0) {
        return "Trung binh";
    } else if (diemTrungBinh >= 3.0) {
        return "Yeu";
    } else {
        return "Kem";
    }
}
//1 Ứng dụng
void inBangMaASCII(int trang) {
    int kyTuBatDau = (trang - 1) * 22;
    int kyTuKetThuc = trang * 22 - 1;

    cout << "Ma\tKy tu" << endl;
    for (int i = kyTuBatDau; i <= kyTuKetThuc && i <= 127; i++) {
        cout << i << "\t" << (char)i << endl;
    }
}
//2 Ứng dụng
// Hàm tính giai thừa
int tinhGiaiThua(int n) {
    if (n == 0) {
        return 1;
    }
    int giaiThua = 1;
    for (int i = 1; i <= n; i++) {
        giaiThua *= i;
    }
    return giaiThua;
}

// Hàm tính tổng S(n)
double tinhTong(int n) {
    double tong = 0.0;
    double temp = 0.0;
    for (int i = 1; i <= n; i++) {
        temp += i;
        tong += temp / tinhGiaiThua(i);
    }
    return tong;
}
//3 Ứng dụng 
void phuongAnRutTien(int n) {
    int soTien100000 = n / 100000;
    n %= 100000;

    int soTien50000 = n / 50000;
    n %= 50000;

    int soTien20000 = n / 20000;
    n %= 20000;

    int soTien10000 = n / 10000;
    n %= 10000;

    cout << "So to tien 100,000 VND: " << soTien100000 << endl;
    cout << "So to tien 50,000 VND: " << soTien50000 << endl;
    cout << "So to tien 20,000 VND: " << soTien20000 << endl;
    cout << "So to tien 10,000 VND: " << soTien10000 << endl;
}
//4 Ứng dụng 
// Hàm tính tiền thưởng dựa trên số ngày công
double tinhTienThuong(int soNgayCong, double luongCoBan) {
    double tienThuong = 0.0;
    if (soNgayCong >= 25) {
        tienThuong = luongCoBan * 0.2;
    } else if (soNgayCong >= 22) {
        tienThuong = luongCoBan * 0.1;
    }
    return tienThuong;
}

// Hàm tính tổng thu nhập của nhân viên
double tinhTongThuNhap(double luongCoBan, int soNgayCong, string chucVu) {
    double tienThuong = tinhTienThuong(soNgayCong, luongCoBan);
    double phuCap = 0.0;
    if (chucVu == "GD") {
        phuCap = 250000;
    } else if (chucVu == "PGD") {
        phuCap = 200000;
    } else if (chucVu == "TP") {
        phuCap = 180000;
    } else if (chucVu == "NV") {
        phuCap = 150000;
    }
    return luongCoBan * soNgayCong + tienThuong + phuCap;
}
//5 Ứng dụng 
// Hàm tính điểm ưu tiên dựa trên khu vực
double tinhDiemUuTien(string maThiSinh) {
    double diemUuTien = 0.0;
    string khuVuc = maThiSinh.substr(0, 3);
    if (khuVuc == "KV1") {
        diemUuTien = 0.5;
    } else if (khuVuc == "KV2") {
        diemUuTien = 1.0;
    } else if (khuVuc == "KV3") {
        diemUuTien = 2.5;
    }
    return diemUuTien;
}
int main()
{
    cout << "BAI TAP LAB 2" << endl;
    int a;
    cout << "NHAP BAI BAN MUON THUC HIEN : ";
    cin >> a;
    switch (a)
    {
    case 1:
    {

        int b, c, n, c1, c2;
        cout << "nhap so nguyen duong can tinh tu 10 toi 99 : ";
        cin >> n;
        if (n < 10 || n > 99)
        {
            cout << "bat buoc so trong khoang tu 10 toi 99";
        }
        else
        {
            c = n / 10;
            b = n % 10;
            c1 = c * b;
            c2 = 2 * (c + b);
            if (c1 == c2)
            {
                cout << "so " << n << " thoa man dieu kien " << endl;
            }
            else
            {
                cout << "so " << n << " khong thoa man dieu kien " << endl;
            }
        }
    }
    break;
    case 2:
    {
        int n;
        cout << "nhap so nguyen : ";
        cin >> n;
        for (int i = 2; i < n; i++)
        {
            bool ppp = true;
            for (int j = 2; j * j <= i; j++)
            {
                if (i % j == 0)
                {
                    ppp = false;
                    break;
                }
            }

            if (ppp)
            {
                cout << i << " ";
            }
        }
    }
    break;
    case 3:
    {
        for (int i = 0; i <= 256; i++)
        {
            cout << "Ky tu: " << (char)i << " | Ma ASCII: " << i << endl;
            if (i % 32 == 0)
            {
                cout << endl;
            }
        }
    }
    break;
    case 4:
    {
        int n;
        cout << "Nhap so nguyen duong: ";
        cin >> n;

        int sodaonguoc = 0;
        while (n > 0)
        {
            int s = n % 10;
            sodaonguoc = sodaonguoc * 10 + s;
            n /= 10;
        }

        cout << "So dao nguoc cua " << n << " la: " << sodaonguoc << endl;
    }
    break;
    case 5:
    {
        int n;
    cout << "Nhap so nguyen duong n: ";
    cin >> n;

    if (n <= 0) {
        cout << "Nhap khong hop le. Vui long nhap so nguyen duong." << endl;
    } else {
        int soLuongChuSo = demSoLuongChuSo(n);
        int tongCacChuSo = tinhTongCacChuSo(n);

        cout << "So luong chu so cua " << n << " la: " << soLuongChuSo << endl;
        cout << "Tong cac chu so cua " << n << " la: " << tongCacChuSo << endl;
    }

    
}
    break;
    case 6:
    {
     int gioBatDau, gioKetThuc;
            cout << "Nhap gio bat dau truy cap: ";
            cin >> gioBatDau;
            cout << "Nhap gio ket thuc truy cap: ";
            cin >> gioKetThuc;

            // Xác định khoảng thời gian truy cập và tính cước truy cập
            int thoiGian = (gioKetThuc - gioBatDau + 24) % 24;
            double cuocTruyCap = 0.0;

            if (gioBatDau >= 7 && gioBatDau < 17) {
                // Khoảng thời gian từ 7 giờ - 17 giờ
                cuocTruyCap = tinhCuocTruyCap(gioBatDau, gioKetThuc, thoiGian, 400, 10);
            } else if (gioBatDau >= 17 || gioKetThuc < 7) {
                // Khoảng thời gian từ 17 giờ - 24 giờ và từ 0 giờ - 7 giờ
                cuocTruyCap = tinhCuocTruyCap(gioBatDau, gioKetThuc, thoiGian, 350, 12);
            } else {
                // Trường hợp còn lại (từ 0 giờ - 7 giờ đang ở trong khoảng 7 giờ - 17 giờ)
                int truoc17Gio = (17 - gioBatDau + 24) % 24;
                double cuocTruoc17Gio = tinhCuocTruyCap(gioBatDau, gioBatDau + truoc17Gio, truoc17Gio, 400, 10);

                int sau7Gio = (gioKetThuc - 7 + 24) % 24;
                double cuocSau7Gio = tinhCuocTruyCap(gioKetThuc - sau7Gio, gioKetThuc, sau7Gio, 300, 15);

                cuocTruyCap = cuocTruoc17Gio + cuocSau7Gio;
            }

            cout << "Cước truy cập Internet: " << cuocTruyCap << " đồng" << endl;
            break;
        }
         case 7:
         {
        int soNgay;
        char loaiPhong;
        
        cout << "Nhap so ngay thue phong: ";
        cin >> soNgay;

        cout << "Nhap loai phong (A, B, C): ";
        cin >> loaiPhong;

        double tienThuePhong = tinhTienThuePhong(soNgay, toupper(loaiPhong));
        if (tienThuePhong > 0) {
            cout << "Tien thue phong la: " << tienThuePhong << " dong" << endl;
        }

       
    }
    break;
    case 8: {
        
        int ngay, thang, nam;
        cout << "Nhap ngay: ";
        cin >> ngay;
        cout << "Nhap thang: ";
        cin >> thang;
        cout << "Nhap nam: ";
        cin >> nam;

        if (ngayHopLe(ngay, thang, nam)) {
        cout << "Ngay thang nam hop le." << endl;
        cout << "Thang " << thang << " co " << soNgayTrongThang(thang, nam) << " ngay." << endl;

        int ngayHomSau = ngay, thangHomSau = thang, namHomSau = nam;
        timNgayHomSau(ngayHomSau, thangHomSau, namHomSau);
        cout << "Ngay hom sau la: " << ngayHomSau << "/" << thangHomSau << "/" << namHomSau << endl;

        int ngayHomTruoc = ngay, thangHomTruoc = thang, namHomTruoc = nam;
        timNgayHomTruoc(ngayHomTruoc, thangHomTruoc, namHomTruoc);
        cout << "Ngay hom truoc la: " << ngayHomTruoc << "/" << thangHomTruoc << "/" << namHomTruoc << endl;
        } else {
        cout << "Ngay thang nam khong hop le." << endl;
         }
        break;
        case 9:
        {
        int soKm;
        cout << "Nhap so km da di: ";
        cin >> soKm;

        if (soKm > 0) {
            double tienTaxi = tinhTienTaxi(soKm);
            cout << "Tien di taxi: " << tienTaxi << " dong" << endl;
        } else {
            cout << "So km khong hop le." << endl;
        }

        
    }
        break;
        case 10:
        {

            string hoTen;
        double diemToan, diemLy, diemHoa;

        cout << "Nhap ho ten hoc sinh: ";
        cin.ignore(); // Loại bỏ dấu Enter còn sót lại từ lần nhập trước đó
        getline(cin, hoTen);

        cout << "Nhap diem Toan: ";
        cin >> diemToan;

        cout << "Nhap diem Ly: ";
        cin >> diemLy;

        cout << "Nhap diem Hoa: ";
        cin >> diemHoa;

        double dtb = diemTrungBinh(diemToan, diemLy, diemHoa);

        cout << "Diem trung binh cua hoc sinh " << hoTen << " la: " << dtb << endl;
        cout << "Phan loai cua hoc sinh " << hoTen << " la: " << phanLoai(dtb) << endl;

        
    }
     }
        break;
            case 11 :{
            int soTrang = 1;
        char ch;
        do {
            inBangMaASCII(soTrang);

            cout << "Nhan Enter de xem trang ke tiep, nhan 'q' de thoat." << endl;
            ch = cin.get();
            if (ch == '\n') {
                soTrang++;
            }
        } while (ch != 'q');

        return 0;
    }
        break;
        case 12: 
        {
             int n;
    cout << "Nhap n: ";
    cin >> n;

    double ketQua = tinhTong(n);
    cout << "S(" << n << ") = " << ketQua << endl;

    return 0;
    }
    
        break;
        case 13 : 
        {
                int n;
        cout << "Nhap so tien can rut (chia het cho 10,000 VND): ";
        cin >> n;

        if (n % 10000 != 0) {
            cout << "So tien nhap vao khong hop le!" << endl;
        } else {
            phuongAnRutTien(n);
        }

        
    }
        
        break;
        case 14 : {
          int maNhanVien;
        string hoTen, chucVu;
        double luongCoBan;
        int soNgayCong;

        cout << "Nhap ma nhan vien: NV";
        cin >> maNhanVien;

        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, hoTen);

        cout << "Nhap luong co ban: ";
        cin >> luongCoBan;

        cout << "Nhap so ngay cong: ";
        cin >> soNgayCong;

        cout << "Nhap chuc vu (GD, PGD, TP, NV): ";
        cin.ignore();
        getline(cin, chucVu);

        double tongThuNhap = tinhTongThuNhap(luongCoBan, soNgayCong, chucVu);

        cout << "\nThong tin nhan vien:" << endl;
        cout << "Ma nhan vien: NV" << setw(2) << setfill('0') << maNhanVien << endl;
        cout << "Ho ten: " << hoTen << endl;
        cout << "Luong co ban: " << luongCoBan << " VND" << endl;
        cout << "So ngay cong: " << soNgayCong << " ngay" << endl;
        cout << "Chuc vu: " << chucVu << endl;
        cout << "Tong thu nhap: " << tongThuNhap << " VND" << endl;

        return 0;
    }
        
        break;
        case 15:
        {
            string maThiSinh, hoTen;
        double diemToan, diemLy, diemHoa;

        // Nhập thông tin thí sinh
        cout << "Nhap ma thi sinh: ";
        cin >> maThiSinh;

        cin.ignore(); // Loại bỏ kí tự '\n' trong bộ nhớ đệm

        cout << "Nhap ho ten: ";
        getline(cin, hoTen);

        cout << "Nhap diem Toan: ";
        cin >> diemToan;

        cout << "Nhap diem Ly: ";
        cin >> diemLy;

        cout << "Nhap diem Hoa: ";
        cin >> diemHoa;

        // Nhập khu vực ưu tiên
        double diemUuTien = 0.0;
        cout << "Nhap khu vuc uu tien (KV1, KV2, KV3): ";
        string khuVuc;
        cin >> khuVuc;
        diemUuTien = tinhDiemUuTien(khuVuc);

        // Tính tổng điểm
        double tongDiem = diemToan * 2 + diemLy + diemHoa + diemUuTien;

        // Xác định trạng thái
        string trangThai = (tongDiem >= 24) ? "TRUNG TUYEN" : "TRUOT";

        // In kết quả
        cout << "\nThong tin thi sinh:" << endl;
        cout << "Ma thi sinh: " << maThiSinh << endl;
        cout << "Ho ten: " << hoTen << endl;
        cout << "Diem uu tien: " << diemUuTien << endl;
        cout << "Tong diem: " << tongDiem << endl;
        cout << "Trang thai: " << trangThai << endl;

        return 0;
    }
        
        break;
        case 16 : {
            int N;
        cout << "Nhap so luong con so N: ";
        cin >> N;

        int A[100];
        cout << "Nhap day tang dan A: ";
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        int maxNum = A[N - 1]; // Số lớn nhất trong dãy ban đầu

        // Tạo một mảng bool để đánh dấu các số đã xuất hiện trong dãy
        bool isPresent[200] = {false};

        // Đánh dấu các số đã xuất hiện trong dãy
        for (int i = 0; i < N; i++) {
            isPresent[A[i]] = true;
        }

        // Liệt kê các số còn thiếu trong khoảng từ 1 đến số lớn nhất
        bool isMissing = false;
        for (int i = 1; i <= maxNum; i++) {
            if (!isPresent[i]) {
                isMissing = true;
                cout << i << endl;
            }
        }

        // Kiểm tra và in kết quả
        if (!isMissing) {
            cout << "Excellent! Excellent!" << endl;
        }

        return 0;
    }
        
        break;
        default: {
            cout << "khong co bai ban chon" << endl;
            break;
        }
    }
}

