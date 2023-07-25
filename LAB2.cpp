#include <iostream>
#include <cmath>
#include <string>
using namespace std;
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
        cout << "Nhap vao so n : ";
        cin >> n;

        int count = 0;
        for (int i = 1; n > 0; i++)
        {
            n /= 10;
            count++;
        }

        int sum = 0;
        for (int i = 0; n > 0; i++)
        {
            sum += n % 10;
            n /= 10;
        }

        cout << "So luong chu so la : " << n << " la " << count << endl;
        cout << "Tong cua so " << n << " la : " << sum << endl;
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

        return 0;
    }
        }
        default: {
            cout << "khong co bai ban chon" << endl;
            break;
        }
    }
}
