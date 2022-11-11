#include<iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
#include <string>

using namespace std;

struct sinhvien {
	string maSo, ten, lop, ngaySinh;
	double anten, tinHieu, tinHoc, lapTrinh, tiengAnh, diemRenLuyen, tBC;
};
typedef struct sinhvien SV;

struct node {
	SV data;
	node* next;
};
typedef struct node NODE;

struct list {
	NODE* pHead;
	NODE* pTail;
};
typedef struct list LIST;

void KhoiTao(LIST& ds) {
	ds.pHead = NULL;
	ds.pTail = NULL;
}

bool kiemTraRong(LIST ds) {
	if (ds.pHead == NULL) {
		return true;
	}
	return !true;
}
NODE* taoNode(SV x) {
	NODE* p;
	p = new NODE;
	if (p == NULL) {
		cout << "ERROR" << endl;
		return NULL;
	}
	p->data = x;
	p->next = NULL;
	return p;
}
void chenCuoi(LIST& ds, NODE* p) {
	if (ds.pHead == NULL) {
		ds.pHead = p;
		ds.pTail = p;
	}
	else {
		ds.pTail->next = p;
		ds.pTail = p;
	}
}

void Nhap(LIST& ds, int size) {
	cout << "NHAP THONG TIN SINH VIEN" << endl;;
	SV x;
	cout << "Ma sinh vien : "; fflush(stdin);
	cin >> x.maSo;
	cout << "Ten sinh vien : "; fflush(stdin);
	cin >> x.ten;
	cout << "Lop : "; fflush(stdin);
	cin >> x.lop;
	cout << "Ngay sinh  : "; fflush(stdin);
	cin >> x.ngaySinh;
	cout << "Diem ren luyen : "; fflush(stdin);
	cin >> x.diemRenLuyen;
	cout << "Anten : "; fflush(stdin);
	cin >> x.anten;
	cout << "Tin hieu : "; fflush(stdin);
	cin >> x.tinHieu;
	cout << "Tin Hoc : "; fflush(stdin);
	cin >> x.tinHoc;
	cout << "Lap trinh : "; fflush(stdin);
	cin >> x.lapTrinh;
	cout << "Tieng anh : "; fflush(stdin);
	cin >> x.tiengAnh;
	cout << "TBC:" << (x.tBC = (x.anten + x.tinHieu + x.tinHoc + x.lapTrinh + x.tiengAnh) / 5);
	cout << endl << endl;
	NODE* p = new NODE;
	p = taoNode(x);
	chenCuoi(ds, p);
}
void Xuat(LIST ds) {
	for (NODE* p = ds.pHead; p != NULL; p = p->next) {
		cout << "Ma sinh vien : " << p->data.maSo << endl;
		cout << "Ten sinh vien : " << p->data.ten << endl;
		cout << "Lop : " << p->data.lop << endl;
		cout << "Ngay sinh : " << p->data.ngaySinh << endl;
		cout << "Diem ren luyen : " << p->data.diemRenLuyen << endl;
		cout << "Anten : " << p->data.anten << endl;
		cout << "Tin hieu : " << p->data.tinHieu << endl;
		cout << "Tin Hoc : " << p->data.tinHoc << endl;
		cout << "Lap trinh : " << p->data.lapTrinh << endl;
		cout << "Tieng anh : " << p->data.tiengAnh << endl;
		cout << "Tbc:" << p->data.tBC << endl;
	}
}

//void SapXep(LIST &ds){
//    NODE *p, *q;
//    for(p = ds.pHead; p != ds.pTail; p=p->next){
//        for(q = p->next; q != NULL; q = q->next){
//            if(p->data.maSo > q->data.maSo){
//                SV x = p->data;
//                p->data = q->data;
//                q->data = x; 
//            }
//        }
//    }
//    Xuat(ds);
//}
//void xoaCuoi(LIST& ds)
//{
//	int n;
//	for (NODE* k = ds.pHead; k != NULL; k = k->next)
//	{
//		if (k->next == ds.pTail)
//		{
//			delete ds.pTail;
//			k->next = NULL;
//			ds.pTail = k;
//		}
//		n--;
//	}
//	//    Xuat(ds);
//}
void xoaAll(LIST& ds, int size) {
	//duyet toan bo danh sach
	for (NODE* k = ds.pHead; k != NULL; k = k->next)
	{
		//tao node p gan bang phan tu dau danh sach
		NODE* p = ds.pHead;
		//gan phan tu dau danh sach bang p->next
		ds.pHead = p->next;
		//xoa di node p
		delete p;
	}
	//gan phan tu cuoi danh sach ve NULL
	ds.pTail = NULL;
}

int Size(LIST& ds, int size) {
	for (NODE* k = ds.pHead; k != NULL; k = k->next) {
		size++;
	}
	return size;
}
void xoaMaSv(LIST& ds, int size) {
	NODE* p = new NODE;
	SV x;
	p = taoNode(x);
	cout << "NHAP SV CAN DELETE: ";
	cin >> p->data.maSo;
	for (NODE* k = ds.pHead; k != NULL; k = k->next) {
		if (k->data.maSo == p->data.maSo) {
			p->next = k->next;
			ds.pHead = p->next;
			delete k;
			cout << "DELETED~!!" << endl;
		}
		else {
			cout << "KHONG TON TAI SV" << endl;

		}
	}

}
void kiemTraTonTaiSv(LIST& ds, int size) {
	NODE* p = new NODE;
	SV x;
	p = taoNode(x);
	cout << "NHAP SV CAN CHECK: ";
	cin >> p->data.maSo;
	for (NODE* k = ds.pHead; k != NULL; k = k->next) {
		if (k->data.maSo == p->data.maSo) {
			cout << "TON TAI SV" << endl;
		}
		else {
			cout << "KHONG TON TAI SV" << endl;

		}
	}
}

void menuChinhSuaSinhVien() {
	cout << "1. Ho ten" << endl;
	cout << "2. Lop" << endl;
	cout << "3. Ngay sinh" << endl;
}
void chinhSuaSV(LIST& ds, int size) {
	NODE* p = new NODE;
	SV x;
	p = taoNode(x);
	cout << "NHAP SV CAN CHECK: ";
	cin >> p->data.maSo;
	for (NODE* k = ds.pHead; k != NULL; k = k->next) {
		if (k->data.maSo != p->data.maSo) {
			cout << "KHONG TON TAI SV" << endl;
		}
		else {
			do {
				system("cls");
				int a;
				menuChinhSuaSinhVien();
				cout << "Chon muc chinh sua: ";
				cin >> a;
				switch (a) {
				case 1: {
					cout << "Nhap ho ten: ";
					cin >> p->data.ten;
					break;
				}
				case 2: {
					cout << "Nhap lop: ";
					cin >> p->data.lop;
					break;
				}
				case 0: {
					return;
				}
				default:
					break;
				}
				//		danhSachSV.put(index, sv);
				cout << "******** Nhan phim bat ky de luu thong tin ********";
				char ch = _getch();

			} while (true);
		}
	}
}
void timKiemSv(LIST& ds, int size) {
	NODE* p = new NODE;
	SV x;
	p = taoNode(x);
	cout << "NHAP SV CAN FIND: ";
	cin >> p->data.maSo;
	for (NODE* k = ds.pHead; k != NULL; k = k->next) {
		if (k->data.maSo == p->data.maSo) {
			Xuat(ds);
		}
		else {
			cout << "KHONG TON TAI SV" << endl;

		}
	}
}

void sapxep(LIST& ds, int size) {
	for (node* i = ds.pHead; i != NULL; i = i->next) {
		node* q = i;
		for (node* j = i->next; j != NULL; j = j->next) {
			if (q->data.tBC > j->data.tBC) {
				q = j;
			}
			else if (q->data.tBC == j->data.tBC) {
				if (q->data.ten > j->data.ten) {
					q = j;
				}
			}
		}
		SV tmp = q->data;
		q->data = i->data;
		i->data = tmp;
	}
	Xuat(ds);
}
void mainMenu() {
	cout << "     ============================================= " << endl;
	cout << "     * 1.Nhap thong tin Sinhvien.                * " << endl;
	cout << "     * 2.In danh sach Sinhvien.                  * " << endl;
	cout << "     * 3.Tong Sinh vien hien tai.                * " << endl;
	cout << "     * 4.Xoa tat ca sinh vien.                   * " << endl;
	cout << "     * 5.Kiem tra ton tai Sinh vien.             * " << endl;
	cout << "     * 6.Tim Sinh Vien (theo Maso).              * " << endl;
	cout << "     * 7.Xoa 1 Sinh vien (theo Maso).            * " << endl;
	cout << "     * 8.Sap xep Sinh vien (theo TBC va ten).    * " << endl;
	cout << "     ======================================== " << endl;
}
int main() {
	LIST ds;
	int size = 0;
	int y;
//	KhoiTao(ds);
	do {
		mainMenu();
		cout << " Your choose is(Nhap '0' se thoat): ";
		cin >> y;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		switch (y) {
		case 1: {
			Nhap(ds, size);
			++size;
			break;
		}
		case 2: {
			if (kiemTraRong(ds) == true) {
				cout << "DANH SACH RONG~." << endl;
			}
			else {
				cout << "DANH SACH SINH VIEN: " << endl;
				Xuat(ds);
			}
			break;
		}
		case 3: {
			cout << "Tong Sinh vien: " << size << endl;
			break;
		}
		case 4: {
			if (kiemTraRong(ds) == true) {
				cout << "\tDANH SACH RONG~, KHONG THE XOA." << endl;
			}
			else {
				xoaAll(ds, size);
				size = 0;
				cout << "DA~ XOA'." << endl;
			}
			break;
		}
		case 5: {
			chinhSuaSV(ds, size);
			break;
		}
		case 6: {
			if (kiemTraRong(ds) == !true) {
				timKiemSv(ds, size);
			}
			else {
				cout << "DANH SACH RONG~ .KHONG THE FIND!!!!" << endl;
			}
			break;
		}
		case 7: {
			if (kiemTraRong(ds) == !true) {
				xoaMaSv(ds, size);
				
			}
			else {
				cout << "DANH SACH RONG~~!!!!" << endl;
			}
			break;
		}
		case 8: {
			if (kiemTraRong(ds) == !true) {
				sapxep(ds, size);
			}
			else {
				cout << "DANH SACH RONG~ .KHONG THE SAP XEP!!!!" << endl;
			}
			break;
		}
		}
		cout << "******** Nhan phim bat ky de tiep tuc ********";
		char ch = _getch();
		system("cls");
	} while (y != 0);
}
