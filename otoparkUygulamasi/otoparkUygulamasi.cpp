

#include <iostream>
#include <fstream>
#include "otoparkUygulamasiOdevi.h";
using namespace std;
struct node
{
	string plaka;
	string aracTipi;
	int ucret;
	string arac;
	struct node* next; 
	struct node* prev;
};
struct node* head = NULL;
void aracEkle(string plaka, string aracTipi, int ucret)
{
	system("cls");
	struct node* arac = new node();
	arac->plaka = plaka;
	arac->aracTipi = aracTipi;
	arac->ucret = ucret;

	if (head == NULL)
	{
		head = arac;
		head->next = NULL;
		head->prev = NULL;
		cout << " Ilk arac eklendi." << endl << endl;
	}
	else
	{
		struct node* temp = head;
		while (temp->next = NULL)
		{
			temp = temp->next;
		}
		temp->next = arac;
		arac->prev = temp;
		arac->next=NULL;
		cout << "Arac eklendi" << endl << endl;
	}

}
void aracCikar(string plaka)
{
	system("cls");
	bool sonuc = false;
	if (head==NULL)
	{
		cout << "Otopark bos" << endl << endl;
	}
	else
	{
		if (head->next==NULL && head->plaka==plaka)
		{
			delete head;
			head = NULL;
			cout << "Son kalan araba cikarildi." << endl << endl;
		}
		else if(head->next!=NULL && head->plaka==plaka)
		{
			struct node* temp = head->next;
			delete head;
			head = temp;
			head->prev = NULL;
		}
		else
		{
			struct node* temp = head;
			while (temp->next!=NULL)
			{
				if (temp->plaka == plaka)
				{
					struct node* temp2 = temp->prev;
					struct node* temp3 = temp->next;
					delete temp;

					temp2->next = temp3;
					temp3->prev = temp2;
					cout << "Arac cikarildi." << endl << endl;
					sonuc = true;
					break;
				}
				temp = temp->next;
			}
			if (temp->plaka==plaka)
			{
				struct node* temp2 = temp->prev;
				delete temp;
				temp2->next = NULL;
				cout << "Arac cikarildi." << endl;
				sonuc = true;
			}
		}
	}
	if (!sonuc)
	{
		cout << "Arac otoparkta yoktur." << endl << endl;
	}
}
void aracListele()
{
	system("cls");
	if (head==NULL)
	{
		cout << "Otopark bos" << endl << endl;
	}
	else
	{
		struct node* temp = head;
		while (temp->next!=NULL)
		{
			cout << temp->plaka << " " << temp->aracTipi << " " << temp->ucret << endl;
			temp = temp->next;
		}
		cout << temp->plaka << " " << temp->aracTipi << " " << temp->ucret << endl;
		
	}
}
void toplamArac() 
{
	system("cls");
	int toplamArac = 0;
	if (head == NULL)
	{
		cout << "Otopark bos" << endl << endl;
	}
	else
	{
		struct node* temp = head;
		while (temp->next!= NULL)
		{
			toplamArac++;
			temp = temp->next;
		}
		toplamArac++;
		cout <<"Toplam arac sayisi : "<< toplamArac << endl << endl;

	}
}
void toplamUcret()
{
	system("cls");
	int toplam = 0;
	if (head == NULL)
	{
		cout << "Otopark bos" << endl << endl;
	}
	else
	{
		struct node* temp = head;
		while (temp->next != NULL)
		{
			toplam+=temp->ucret;
			temp = temp->next;
		}
		toplam+=temp->ucret;
		cout << "Araclarin toplam ucreti : " << toplam << endl << endl;

	}
}
void aracKaydet()
{
	system("cls");
	ofstream kaydet("otopark.txt");
	if (head==NULL)
	{
		cout << "Otopark bostur." << endl << endl;
	}
	else
	{
		struct node* temp = head;
		while (temp->next!=NULL)
		{
			kaydet << temp->plaka << " " << temp->aracTipi << " " << temp->ucret << endl;

			temp=temp->next;
		}
		kaydet << temp->plaka << " " << temp->aracTipi << " " << temp->ucret << endl;
		kaydet.close();
		cout << "Araclar 'otopark.txt' dosyasina kaydedildi." << endl << endl;
	}
}
int main()
{
	int ucret,secim;
	string plaka, aracTipi;
	while (1)
	{
		cout << "--------------------" << endl;
		cout << "Otopark Uygulamasi" << endl;
		cout << "1- Arac ekle" << endl;
		cout << "2- Arac cikar" << endl;
		cout << "3- Otoparkta bekleyen araclari listele" << endl;
		cout << "4- Mevcut arac sayisi: " << endl;
		cout << "5- Mevcut araclarin toplam ucreti:  " << endl;
		cout << "6- Mevcut araclari kaydet." << endl;
		cout << "8-Cikis" << endl;
		cin >> secim;
		switch (secim)
		{
		case 1:cout << "Arac bilgilerini giriniz: " << endl;
			cout << "plaka :"; cin >> plaka;
			cout << "arac tipi :"; cin >> aracTipi;
			cout << "ucret:"; cin >> ucret;
			aracEkle(plaka, aracTipi, ucret);
			break;
		case 2:cout << "Otoparktan cikarilacak arac: "; cin >> plaka; 
			aracCikar(plaka);
			break;
		case 3:cout << "Otoparkta bekleyen araclarin listesi:" << endl;
			aracListele();
			break;
		case 4: 
			toplamArac();
				break;
		case 5:
			toplamUcret();
			break;
		case 6:aracKaydet();
			break;
		case 8:cout << "Uygulamadan cikildi!" << endl;
			break;
		default:cout << "Hatali giris!!" << endl;
			break;
		}
	}
	return 0;
}
