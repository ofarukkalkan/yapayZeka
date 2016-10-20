#include <vector>
#include <functional>



namespace MLP { // nesne tabanli multi-layer perceptron

	using std::vector;
	using std::function;
	
	
	enum class TransferFonksiyonu { // turevi alinabilir, belirli sinirlar icinde ornek transfer fonksiyonlari
	
		IDENTITY, // y=x
		BINARY_STEP, // if x > t then y = 1 else y = 0
		SOFT_STEP, // y = 1 / ( 1 + e ^ (-x) )
		
		
	};

	class baglanti {
	
		float m_weight = 0.0f; // agirlik degeri
		float m_value = 0.0f; // baglanti degeri
		
		float m_weighted_value = 0.0f; // agirlikli deger
	
		public:

			
			baglanti(); // bos kurucu fonksiyon
			baglanti(float weight,float value); // baglanti parametrelerini alan kurucu fonksiyon
			
			// 
			
			void agirlikDegistir(float weight){
			
				this->m_weight = weight;
				agirlikliDegeriHesapla(); // agirlik degistiğinde otomatik agirlikli deger degisir
			
			}
			
			void degerDegistir(float value) {
			
				this->m_value = value;
				agirlikliDegeriHesapla(); // agirlik degistiğinde otomatik agirlikli deger degisir
			}
			
			float agirlikOku() const {
			
				return this->m_weight;
			}
			
			float degerOku() const {
			
				return this->m_value;
			}
			
			float agirlikliDegerOku(){
			
				return this->m_weighted_value;
			}
			
			void agirlikliDegeriHesapla(){ // baglantinin agirlikli degeri hesaplanir
			
			}
			
			
			//  yardimci fonksiyonlar
			
			bool compareTo(const baglanti & other) {
				if(equals(other)){
					return true;
				} else {
					return false;
				} 
			
			}
			
			bool equals(const baglanti & other) { // baglantilar ayni ise true degeri doner
				if( other.degerOku()==this->degerOku() && other.degerOku()==this->degerOku()) {
					return true;
				} else {
					return false;
				}
			}
			
	};


	class noron {
	
		
			vector<baglanti*> m_girisler; // norona giren baglantilar
			baglanti* m_dengeBaglantisi = nullptr; // dengeyi sağlayan baglanti
	
			float m_toplamAgirlik = 0.0f; // norona giren baglantilarin agirlikli toplami
			function<float(float)> m_transferFonksiyonu = nullptr; // toplam değerine uygulanan transfer fonksiyonu
			float m_fonksiyonDegeri = 0.0f; // transfer fonksiyonundan elde edilen deger
			
		public:
		
			noron() = default; // varsayilan kurucu fonksiyon
			~noron() = default ; // varsayilan yok edici fonksiyon
			
			noron(function<float(float)> transferFonksiyonu); // 
			

			
			// baglanti ekle cikar
			
			void baglantiEkle(baglanti eklenecek) {
			
			
			}
			
			void baglantiCikar(baglanti cikacak) {
			
			}
			

			// giris ekle cikar
			
			void girisEkle(noron eklenecek) {
			
			}
			
			void girisCikar(noron cikacak) {
			
			}
			
			// transfer fonksiyonunu degistir
			
			void transferFonksiyonuAyarla(TransferFonksiyonu fn) {
			
			
			}
			
			// dengeyi degistir
			
			void dengeBaglantisiAyarla(baglanti ayar) {
			
			}
			
			
			
			//  yardimci fonksiyonlar
			
			bool compareTo(const noron & other) {
				
			
			}
			
			bool equals(const noron & other) {
			
			}
		
		
	};

	class katman {
	
			vector<noron*> m_noronlar;
		
		public:
		
			void noronEkle() {
			
			}
			
			void noronCikar() {
			
			}
			
			



	};



	class cokKatmanliPerceptron {
	
		public:
		
		void katmanEkle(){
		
		}

	};
}

int main() {
	
	using namespace MLP;
	/*
	katman katman_giris;
	katman katman_gizli;
	katman katman_cikis;
	
	cokKatmanliPerceptron network;
	*/
	
	
	return 0;
}
