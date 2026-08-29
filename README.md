# Nesne Yönelimli Programlama Örnekleri

Python ve C++ ile nesne yönelimli programlamanın temel kavramlarını adım adım gösteren küçük, çalıştırılabilir örnekler.

## İçerik

### Python

Notebook'lar öğrenme sırasına göre numaralandırılmıştır:

1. `01-classes-and-objects.ipynb` — sınıflar, nesneler ve örnek nitelikleri
2. `02-constructors.ipynb` — `__init__` ile nesne oluşturma
3. `03-encapsulation.ipynb` — property, kapsülleme ve doğrulama
4. `04-alternative-constructors.ipynb` — varsayılan parametreler ve `classmethod`
5. `05-inheritance.ipynb` — kalıtım ve metot ezme
6. `06-product-management/product-management.ipynb` — CSV kullanan küçük ürün yönetimi projesi

> Python aynı isimle birden fazla metot tanımlayarak klasik metot aşırı yüklemeyi desteklemez. Dördüncü örnek, Python'da tercih edilen varsayılan parametre ve alternatif constructor yaklaşımını gösterir.

### C++

- `vehicles.cpp` — kalıtım, kapsülleme, sanal metotlar ve çalışma zamanı çok biçimliliği
- `people.cpp` — soyut temel sınıf, metot ezme ve `override`

## Klasör yapısı

```text
.
├── examples/
│   ├── cpp/inheritance/
│   └── python/
├── CMakeLists.txt
├── .gitattributes
└── .gitignore
```

Kaynak kod ile üretilen dosyalar birbirinden ayrıdır. Derleme çıktıları `build/` klasörüne yazılır ve Git tarafından izlenmez.

## Çalıştırma

### Python notebook'ları

Python 3.10 veya daha yeni bir sürüm ve Jupyter gerekir:

```bash
python -m pip install jupyter
jupyter notebook examples/python
```

### C++ örnekleri

CMake 3.16+ ve C++17 destekleyen bir derleyici gerekir:

```bash
cmake -S . -B build
cmake --build build
```

MinGW ile doğrudan derlemek de mümkündür:

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic examples/cpp/inheritance/vehicles.cpp -o vehicles
g++ -std=c++17 -Wall -Wextra -Wpedantic examples/cpp/inheritance/people.cpp -o people
```

## Diyagramlar

`.puml` dosyaları [PlantUML](https://plantuml.com/) sözdizimini kullanır. VS Code PlantUML eklentisiyle önizlenebilir veya PlantUML CLI ile görsele dönüştürülebilir.
