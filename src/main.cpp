#include <vector>
#include <string>
#include <functional>
#include <fstream>
#include <sstream>
#include <iostream>
#include <exception>

// bu fonksyionlar disardan alindi. satirlardaki kelimeleri parse etmek icin
void split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}
////////////////////////////////////////////////////////////////////////

namespace MLP { // multi-layer perceptron
	using std::vector;
	using std::function;
	using std::string;
	using std::ifstream;
	using std::cout;
	using std::endl;
	using std::exception;
	
	class  Connection { // noronlar arasinda baglantiyi saglar
	
		float m_value = 0.0f;
		float m_weight = 0.0f;
		
		public:
			// kurucu fonksiyon
			Connection(float value,float weight);	
			// erisim saglayicilar
			void setValue(float value);
			void setWeight(float value);
			float getValue() const;
			float getWeight() const;
	};
	
	typedef vector<Connection*> Connections;
	typedef function<float(float)> TransferFunction;
	
	class Neuron { // yapay noron
	
		Connections m_inputs;	
		TransferFunction m_function = nullptr;
		float m_output = 0.0f;
		

		
		public:
			// kurucu ve yikici fonksiyon
			Neuron(TransferFunction function);
			
			void sum(); // norondaki toplam degeri hesaplanir
			void transfer(); // toplam degeri transfer fonksiyonundan gecirilir
			
			// erisim saglayicilar
			float getOutput() const;
	};
	
	typedef vector<Neuron*> Neurons;
	
	class Layer { // icinde noronlari barindirir
		
		Neurons m_neurons;
		
		public:
			void addNeuron(TransferFunction function); // noron ekler
	
	};
	
	typedef vector<Layer*> Layers;
	typedef vector<float> Input;
	
	class Perceptron {
	
		Layers m_layers;
		vector<string> m_data; // okunan giris ve cikis degeri
		
		vector<float> m_outputs; // cikis degerleri
		float m_error; // cikisin olmasi gereken sonuca gore hatasi
		float m_averageError;
		
		float m_eta; // ogrenme hizi
		float m_alpha; // momentum degeri
		
		// datainfo dosyasindan okunacaklar
		string m_outfile;
		string m_inputfile;	
		
		vector<string> m_fonksiyonlar;
		
		int m_giris_sayisi;	// = 2	
		int m_cikis_sayisi; // = 1
		int m_gizli_katman_sayisi; // = 2

		vector<int> m_gizli_katman_noronlari;	 // = [ 3 , 2 ]		
		float m_ogrenme_hizi;
		float m_testveri_orani;
		int m_iterasyon;
			
		// data dosyasindan okunacaklar
		int m_sutun_sayisi; // = 3
		int m_satir_sayisi;
		
		vector<string> m_okunan_satirlar;

		
		
		void feedFoward(){
			// noronlarin hesaplamalarini yap
			
			// baslangic agirliklarini rastgele ata
		}
		void backPropagation(){
		
		}
		
		public:

			
			void oku(string datainfo){
			
				string okunanSatir = "";
			
				// datainfo dosyasindaki bilgileri oku
			
				ifstream dosya; 
				dosya.open(datainfo); // dosyayi ac
				// 1. alinan satir data dosyasinin konumu
				getline(dosya, okunanSatir); 
				m_inputfile = split(okunanSatir,'\t').at(1);
				cout << "okunacak data dosyasi =\t" << m_inputfile << endl;
				// 2. alinan satir data dosyasindaki giris sayisi
				getline(dosya, okunanSatir); 
				m_giris_sayisi = stoi(split(okunanSatir,'\t')[1]);
				cout <<  "giris sayisi =\t" << m_giris_sayisi << endl;
				
				// 3. alinan satir gizli katmandaki noron sayilari
				getline(dosya, okunanSatir);
				vector<string> kelimeler = split(okunanSatir,'\t');
				cout << "gizli katmandaki noron sayilari =";
				for(int i = 1; i < kelimeler.size(); i++){ // ilk kelime atlandiktan sonra diger kelimeler noron sayilarini belirtir
					m_gizli_katman_noronlari.push_back(stoi(kelimeler.at(i)));
					cout << "\t" <<  m_gizli_katman_noronlari.at(i-1);
				}
				cout << endl;
				// 4. alinan satir katmanlarin transfer fonksiyonlari
				getline(dosya, okunanSatir);
				vector<string> kelimeler2 = split(okunanSatir,'\t');
				cout << "katmanlardaki transfer fonksiyonlari =";
				for(int i = 1; i < kelimeler2.size(); i++){ // ilk kelime atlandiktan sonra diger kelimeler noron sayilarini belirtir
					m_fonksiyonlar.push_back(kelimeler2.at(i));
					cout << "\t" <<  m_fonksiyonlar.at(i-1);
				}
				cout << endl;
				// 5. alinan satir ogrenme hizi
				getline(dosya, okunanSatir); 
				m_ogrenme_hizi = stof(split(okunanSatir,'\t')[1]);
				cout << "ogrenme hizi =\t" << m_ogrenme_hizi << endl;
				// 6. alinan satir test veri orani
				getline(dosya, okunanSatir); 
				m_testveri_orani = stof(split(okunanSatir,'\t')[1]);
				cout << "test veri orani =\t" << m_testveri_orani << endl;
				// 7. alinan satir iterasyon sayisi
				getline(dosya, okunanSatir); 
				m_iterasyon = stoi(split(okunanSatir,'\t')[1]);
				cout << "iterasyon sayisi =\t" << m_iterasyon << endl;
				// 8. alinan satir cikis dosyasinin konumu
				getline(dosya, okunanSatir); 
				m_outfile = split(okunanSatir,'\t')[1];
				cout << "output file =\t" << m_outfile << endl;
				
				// dosyayi kapat				
				dosya.close();
				
				// data dosyasini oku
				ifstream data;
				// dosyayi ac
				data.open(m_inputfile);
				
				// okuma islemleri
				cout << endl << "data dosyasindan okunan datalar"<< endl;
				while (getline(data, okunanSatir))
				{
					m_data.push_back(okunanSatir);
					cout << m_data.back() << endl;
				}
				
				// dosyayi kapat				
				data.close();			
		}
			
	};

};

float sigmoid(float value){
	return 1 ;
}

int main(){
	using namespace MLP;
	using std::cout;
	
	Perceptron  net;

	net.oku("data/datainfo");
	//data.txt
	
	/*
	oku("data_info.txt");
	run();
	*/
	return 0;
}
