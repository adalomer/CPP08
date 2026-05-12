# CPP08 - CPP07 Teorik Bilgi Notları

## 42 Okulu CPP08 Modülü Kapsamlı Açıklama

CPP08 modülü, C++ programlama dilinin en güçlü özelliklerinden biri olan **Şablonlar (Templates)**, **STL Konteynerleri**, **İteratörler** ve **Algoritmalar** konularını kapsamaktadır. Bu modül, standart kütüphanenin nasıl çalıştığını anlamak ve kendi generic kodumuzu yazabilmek için temel bilgiler sunmaktadır.

---

## 1. Template'ler (Şablonlar)

### 1.1 Template Nedir?

Template'ler, C++'ta **generic programming** (jenerik programlama) paradigmasını uygulamamızı sağlayan güçlü bir araçtır. Template sayesinde, farklı veri tipleri için aynı kodu yazmadan kullanabiliriz. Bu, kod tekrarını önler ve daha esnek, yeniden kullanılabilir kod yazmamızı sağlar.

### 1.2 Function Template (Fonksiyon Şablonu)

Fonksiyon şablonları, farklı tiplerle aynı mantığı uygulayan fonksiyonlar yazmamızı sağlar. Derleyici, fonksiyonu çağırdığımızda gerekli tipi otomatik olarak çıkarır.

```cpp
// Basit bir function template örneği
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

// Kullanımı
int i = max(5, 10);          // int olarak çıkarılır
double d = max(3.14, 2.71);  // double olarak çıkarılır
```

### 1.3 Class Template (Sınıf Şablonu)

Sınıf şablonları, farklı tiplerle çalışabilen generik sınıflar oluşturmamızı sağlar. STL'deki tüm konteynerler (vector, list, stack, queue vb.) aslında class template'dir.

```cpp
template <typename T>
class Container {
private:
    T* data;
    size_t size;
public:
    void push(const T& value);
    T pop();
    size_t getSize() const;
};
```

### 1.4 Template Specialization (Şablon Özelleştirme)

Belirli tipler için farklı implementasyon yazmak istediğimizde template specialization kullanırız.

```cpp
template <typename T>
class Validator {
    // Genel implementasyon
};

template <>
class Validator<char> {
    // char tipi için özel implementasyon
};
```

---

## 2. STL Konteynerleri (Containers)

### 2.1 Konteyner Kategorileri

STL'de konteynerler üç ana kategoride incelenir:

**Sequence Containers (Sıralı Konteynerler)**: Elemanların sırasının önemli olduğu ve direkt erişim gerektirdiği durumlarda kullanılır.

| Konteyner | Açıklama | Özellikler |
|-----------|----------|------------|
| `vector` | Dinamik dizi | Rastgele erişim O(1), sonuna ekleme O(1), ortadan ekleme O(n) |
| `deque` | Çift uçlu kuyruk | Başa ve sona ekleme O(1), rastgele erişim O(1) |
| `list` | Çift yönlü bağlı liste | Ortadan ekleme/silme O(1), erişim O(n) |

**Associative Containers (İlişkili Konteynerler)**: Elemanlar anahtar-değer çiftleri olarak saklanır ve hızlı arama gerektiren durumlarda kullanılır.

| Konteyner | Açıklama | Özellikler |
|-----------|----------|------------|
| `set` | Sıralı benzersiz elemanlar | Arama O(log n), ekleme O(log n) |
| `map` | Anahtar-değer çiftleri | Arama O(log n), her anahtar benzersiz |
| `multiset` | Sıralı elemanlar (tekrarlı) | Birden fazla aynı değer olabilir |
| `multimap` | Birden fazla aynı anahtar | Bir anahtar birden fazla değere sahip olabilir |

**Container Adaptors**: Mevcut konteynerlerin üzerine farklı bir arayüz sağlar.

| Konteyner | Açıklama | İç Implementasyon |
|-----------|----------|-------------------|
| `stack` | LIFO (Last In First Out) | Varsayılan: deque |
| `queue` | FIFO (First In First Out) | Varsayılan: deque |
| `priority_queue` | Öncelik sıralı | Varsayılan: vector |

### 2.2 Konteyner Üye Fonksiyonları

Tüm STL konteynerleri ortak üye fonksiyonlara sahiptir:

| Fonksiyon | Açıklama |
|-----------|----------|
| `begin()` | İlk elemana iterator döndürür |
| `end()` | Son elemanın sonrasına iterator döndürür |
| `size()` | Eleman sayısını döndürür |
| `empty()` | Konteyner boş mu kontrol eder |
| `push_back()` | Sona eleman ekler |
| `pop_back()` | Sondan eleman çıkarır |
| `insert()` | Belirtilen pozisyona eleman ekler |
| `erase()` | Belirtilen pozisyondaki elemanı siler |
| `clear()` | Tüm elemanları siler |

### 2.3 Konteyner Seçim Kriterleri

Doğru konteyneri seçmek için şu soruları sormalıyız:

1. **Erişim tipi**: Rastgele erişim gerekli mi? → `vector`
2. **Ekleme/Silme sıklığı**: Sık ortadan ekleme/silme mi? → `list`
3. **Arama gereksinimi**: Hızlı arama gerekli mi? → `set`, `map`
4. **Bellek kullanımı**: Memory overhead önemli mi?
5. **Iteration tipi**: Sık ileri-geri iterasyon mu? → `list`

---

## 3. İteratörler (Iterators)

### 3.1 İteratör Nedir?

İteratörler, STL konteynerlerinde bulunan elemanlara erişmek ve onları traverse etmek için kullanılan nesnelerdir. Pointer'lara benzer şekilde çalışırlar ancak daha abstraction sunarlar. İteratörler, konteynerin iç yapısından bağımsız olarak uniform erişim sağlar.

### 3.2 İteratör Kategorileri

C++'ta beş ana iteratör kategorisi vardır:

| Kategori | Özellikler | Örnek Konteynerler |
|----------|------------|-------------------|
| **Input Iterator** | Tek geçişli, salt okunur | - |
| **Output Iterator** | Tek geçişli, salt yazılır | - |
| **Forward Iterator** | Çoklu geçiş, ileri yön | `forward_list` |
| **Bidirectional Iterator** | İleri/geri geçiş | `list`, `set`, `map` |
| **Random Access Iterator** | Aritmetik operasyonlar (+, -, []) | `vector`, `deque` |

### 3.3 Iterator Traversal

```cpp
std::vector<int> vec = {1, 2, 3, 4, 5};

// Range-based for loop (C++11)
for (const auto& elem : vec) {
    std::cout << elem << " ";
}

// Iterator ile
for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
    std::cout << *it << " ";
}

// Const iterator ile
for (std::vector<int>::const_iterator cit = vec.cbegin(); cit != vec.cend(); ++cit) {
    std::cout << *cit << " ";
}
```

### 3.4 Iterator Araçları

STL, iteratörlerle çalışmayı kolaylaştıran fonksiyonlar sunar:

```cpp
std::advance(it, 5);      // Iterator'ü 5 adım ileri hareket ettir
std::distance(it1, it2);  // İki iterator arasındaki mesafe
std::next(it, 3);         // 3 adım sonraki iterator
std::prev(it, 2);         // 2 adım önceki iterator
```

---

## 4. STL Algoritmaları (Algorithms)

### 4.1 Algoritma Kategorileri

STL algoritmaları, üç ana kategoriye ayrılır:

**Non-modifying sequence operations**: Konteyneri değiştirmeden işlem yapan algoritmalar.

| Algoritma | Açıklama |
|-----------|----------|
| `for_each` | Her elemana fonksiyon uygula |
| `find` | Belirtilen değeri ara |
| `find_if` | Koşula uyan ilk elemanı bul |
| `count` | Belirtilen değerin sayısını bul |
| `count_if` | Koşula uyan elemanların sayısını bul |
| `search` | Alt dizi ara |

**Modifying sequence operations**: Konteyneri değiştiren algoritmalar.

| Algoritma | Açıklama |
|-----------|----------|
| `copy` | Elemanları kopyala |
| `transform` | Her elemana fonksiyon uygula ve sonucu kaydet |
| `replace` | Değerleri değiştir |
| `remove` | Belirtilen değerleri kaldır |
| `reverse` | Sırayı tersine çevir |
| `sort` | Sırala |
| `unique` | Ardışık tekrarları kaldır |

**Partitioning operations**: Elemanları gruplara ayıran algoritmalar.

| Algoritma | Açıklama |
|-----------|----------|
| `partition` | Koşula göre ayır |
| `stable_partition` | Koşula göre ayır, göreceli sırayı koru |
| `partition_point` | Bölme noktasını bul |

### 4.2 Algoritma Kullanım Örnekleri

```cpp
std::vector<int> vec = {5, 2, 8, 1, 9, 3};

// for_each
std::for_each(vec.begin(), vec.end(), [](int n) {
    std::cout << n << " ";
});

// find
auto it = std::find(vec.begin(), vec.end(), 8);
if (it != vec.end()) {
    std::cout << "Bulundu: " << *it;
}

// sort
std::sort(vec.begin(), vec.end());

// transform
std::vector<int> squared;
std::transform(vec.begin(), vec.end(), std::back_inserter(squared),
              [](int n) { return n * n; });
```

---

## 5. CPP08 Egzersizleri Teorisi

### 5.1 ex00 - Easy Find

**Konsept**: Function template, iteratör kullanımı ve exception handling.

**Öğrenilecekler**:
- Template fonksiyon yazımı
- STL iteratörleri ile çalışma
- Exception oluşturma ve yakalama (try-catch)
- `std::exception` ve türevleri
- `std::find` algoritmasının mantığı

**Teorik Alt Yapı**:
```cpp
template <typename T>
typename T::iterator easyfind(T& container, int value) {
    // container.begin() ve container.end() iteratörlerini kullan
    // std::find benzeri bir implementasyon
    // Değer bulunamazsa exception fırlat
}
```

**Temel Kavramlar**:
- `typename` anahtar kelimesi: Template içinde tip belirtirken kullanılır
- `iterator` nested type: Her STL konteynerinin iterator typedef'i vardır
- Exception handling: `throw`, `try`, `catch` blokları

### 5.2 ex01 - Span

**Konsept**: container adaptors, algorithmic thinking, exception handling.

**Öğrenilecekler**:
- Container adaptör kullanımı
- `std::set` ile çalışma (sorted, unique)
- İstatistiksel hesaplamalar (shortest span, longest span)
- Template class implementasyonu
- Range-based constructor

**Temel Kavramlar**:
- `std::set`: Sıralı, benzersiz elemanlar tutan container
- Span kavramı: En yakın iki eleman arasındaki fark
- Shortest span: En küçük fark
- Longest span: En büyük fark

**Span Algoritması**:
```cpp
// Sorted container'da en yakın elemanlar ardışık olur
// Bu nedenle sadece ardışık çiftleri kontrol etmek yeterli
// Span = next - current (sorted container'da minimum fark)
```

### 5.3 ex02 - Mutant Stack

**Konsept**: Iterator adaptörleri, container decorator pattern, template specialization.

**Öğrenilecekler**:
- `std::stack` üzerine iterator ekleme
- Iterator adaptor pattern
- Container'ın iterator interface'ini expose etme
- `reverse_iterator` kullanımı
- Template class'ta iterator implementasyonu

**Temel Kavramlar**:
- Decorator Pattern: Mevcut sınıfın üzerine yeni özellikler ekleme
- Iterator Adaptor: Bir iterator'ü başka bir iterator'a dönüştürme
- `reverse_iterator`: Tersten iteration

**Yapı**:
```cpp
template <typename T>
class MutantStack : public std::stack<T> {
public:
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;

    iterator begin();
    iterator end();
    // reverse iterators da eklenebilir
};
```

---

## 6. Exception Handling (İstisna Yönetimi)

### 6.1 Exception Temelleri

Exception handling, programın çalışma zamanında oluşan hataları yönetmek için kullanılan mekanizmadır. `try`, `catch` ve `throw` blokları ile uygulanır.

### 6.2 STL Exception Sınıfları

```cpp
#include <exception>

try {
    // Riskli kod
    throw std::exception();
} catch (const std::exception& e) {
    std::cerr << "Hata: " << e.what() << std::endl;
}
```

**Common Exception Tipleri**:

| Exception | Açıklama |
|-----------|----------|
| `std::exception` | Base exception sınıfı |
| `std::bad_alloc` | Bellek tahsisi hatası |
| `std::out_of_range` | Geçersiz index erişimi |
| `std::invalid_argument` | Geçersiz argüman |
| `std::logic_error` | Mantık hatası |
| `std::runtime_error` | Çalışma zamanı hatası |

### 6.3 Custom Exception

```cpp
class NotFoundException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Element not found in container";
    }
};

// Kullanımı
throw NotFoundException();
```

---

## 7. Template Metaprogramming Temelleri

### 7.1 Template Parameters

```cpp
// Tip parametresi
template <typename T>

// Non-type parametre
template <int N>

// Template of template
template <template <typename> class Container>
```

### 7.2 Default Template Arguments

```cpp
template <typename T = int>
class Container {
    // T default olarak int
};
```

### 7.3 Template Template Parameters

```cpp
template <typename T,
          template <typename, typename> class Container = std::deque>
class MyClass {
    Container<T, std::allocator<T>> data;
};
```

---

## 8. Type Traits ve SFINAE

### 8.1 Type Traits

Type traits, tipler hakkında compile-time bilgi almamızı sağlar:

```cpp
#include <type_traits>

std::is_integral<int>::value        // true
std::is_class<std::vector>::value    // true
std::is_pointer<int*>::value         // true

// Conditional type
typename std::conditional<true, int, double>::type  // int
```

### 8.2 SFINAE (Substitution Failure Is Not An Error)

Template argümanlarını substituted ederken hata oluşursa, derleyici bunu error olarak değil, o overload'ın seçilmediği olarak kabul eder:

```cpp
template <typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type
process(T value) {
    // Sadece integral tipler için
}
```

---

## 9. Iterator Traits

### 9.1 Iterator Categories

Her iterator'ün category'si vardır ve algorithm'ler bu category'ye göre farklı implementasyonlar kullanır:

```cpp
template <typename Iterator>
typename std::iterator_traits<Iterator>::iterator_category
getCategory(const Iterator&) {
    return std::iterator_traits<Iterator>::iterator_category();
}
```

### 9.2 Custom Iterator Oluşturma

Kendi iterator'ümüzü oluşturmak için gerekli typedef'ler:

```cpp
template <typename T>
class MyIterator {
public:
    typedef std::bidirectional_iterator_tag iterator_category;
    typedef T value_type;
    typedef std::ptrdiff_t difference_type;
    typedef T* pointer;
    typedef T& reference;

    reference operator*();
    pointer operator->();
    MyIterator& operator++();
    MyIterator operator++(int);
    // ... diğer operator'ler
};
```

---

## 10. STL Konularını Derinleştirme

### 10.1 Container'da Iterator Invalidation

Iterator invalidation, konteyner değiştiğinde iterator'lerin geçersiz hale gelmesidir:

| Operasyon | Iterator Geçerliliği |
|-----------|---------------------|
| `push_back` | `vector`: Tümü geçersiz, `deque`: Geçersiz |
| `push_front` | `deque`: Tümü geçersiz |
| `insert` | `vector`: Ekleme noktasından sonrakiler geçersiz |
| `erase` | Silinen ve sonraki iterator'ler geçersiz |
| `clear` | Tüm iterator'ler geçersiz |

### 10.2 Memory Management

STL konteynerleri otomatik memory yönetimi sağlar:

```cpp
std::vector<int> vec;
vec.reserve(100);  // Bellek ayır, yeniden allocation önle
vec.shrink_to_fit();  // Fazla belleği serbest bırak
```

### 10.3 Allocator Pattern

STL, bellek tahsisi için allocator kullanır:

```cpp
std::vector<int, std::allocator<int>> vec;
```

---

## 11. CPP08 İçin Ek Kaynaklar ve İpuçları

### 11.1 Referans Materyaller

- **cppreference.com**: STL referansı için en kapsamlı kaynak
- **C++ Primer (Stanley Lippman)**: STL konuları için mükemmel kaynak
- **Effective STL (Scott Meyers)**: STL kullanım best practices

### 11.2 Derleme ve Test

```bash
# Norminette kontrolü
norminette -R CheckForbiddenSourceHeader src/

# Derleme
g++ -Wall -Wextra -Werror -std=c++98 -I. src/*.cpp main.cpp -o program

# Test
./program
```

### 11.3 Yaygın Hatalar ve Çözümler

1. **Iterator kullanım hataları**: Her zaman valid range kullan
2. **const-correctness**: Mevcut değeri değiştirmeyecek fonksiyonlarda const kullan
3. **Exception safety**: Resource leak oluşmayacak şekilde RAII kullan
4. **Template syntax**: `typename` anahtar kelimesini unutma

---

## 12. Özet ve Anahtar Kavramlar

### CPP08 Modülünde Öğrenilecek Temel Kavramlar

| Kavram | Açıklama |
|--------|----------|
| **Template Functions** | Farklı tiplerle çalışan genel fonksiyonlar |
| **Template Classes** | Generik sınıflar |
| **STL Containers** | vector, list, stack, queue, set, map |
| **Iterators** | Konteyner elemanlarına erişim |
| **Algorithms** | for_each, find, sort, transform |
| **Exception Handling** | try-catch-throw mekanizması |
| **Container Adaptors** | Mevcut konteynerlerin wrapper'ları |

### Kariyer Açısından Önemi

1. **Code Reusability**: Aynı kodu farklı tiplerle kullanma
2. **STL Uzmanlığı**: Modern C++ programlamanın temeli
3. **Algorithmic Thinking**: Problem solving becerileri
4. **Design Patterns**: Container adaptörleri anlama
5. **Memory Management**: Smart pointer ve RAII kavramları

---

## Ek: STL Container Comparison Chart

```
+------------------+----------+----------+----------+----------+----------+
| Özellik          | vector   | deque    | list     | set      | map      |
+------------------+----------+----------+----------+----------+----------+
| Random Access    | O(1)     | O(1)     | O(n)     | O(log n) | O(log n) |
+------------------+----------+----------+----------+----------+----------+
| Insert Front     | O(n)     | O(1)     | O(1)     | -        | -        |
+------------------+----------+----------+----------+----------+----------+
| Insert Back      | O(1)     | O(1)     | O(1)     | -        | -        |
+------------------+----------+----------+----------+----------+----------+
| Insert Middle    | O(n)     | O(n)     | O(1)     | O(log n) | O(log n) |
+------------------+----------+----------+----------+----------+----------+
| Memory Overhead  | Düşük    | Orta     | Yüksek   | Yüksek   | Yüksek   |
+------------------+----------+----------+----------+----------+----------+
| Cache Friendly   | Evet     | Kısmen   | Hayır    | Hayır    | Hayır    |
+------------------+----------+----------+----------+----------+----------+
```

---

*Bu doküman, 42 Okulu CPP08 modülü için hazırlanmıştır. Tüm içerik, STL ve modern C++ programlama kavramlarını kapsamaktadır.*
