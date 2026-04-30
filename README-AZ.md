# WAPage

WhatsApp söhbətlər üçün ixrac funksiyası təqdim edir, lakin onları sonradan oxumaq üçün heç bir rəsmi vasitə təklif etmir. Bu tətbiq bu boşluğu doldurmaq üçün yaradılıb. <br> WAPage ixrac edilmiş WhatsApp söhbət fayllarını təhlil edir və onları təmiz vizual interfeysdə göstərir. <br>
Bu proqramı digər oxuculardan fərqləndirən cəhət, onun C++ ilə .exe proqram formatında işləməsi, brauzerə ehtiyac duymaması və açıq mənbəli olmasıdır.

## Yükləmə

### 1. Son versiyanı birbaşa bu linkdən yükləyin

<a>https://github.com/Baayramov/WAPage/releases/download/v1.2.0/WAPage-v1.2.0.zip</a> <br>

**2. Sağdakı releases panelindən yükləyin**

**3. Windows PowerShell istifadə edərək yükləyin** <br>

<pre><code>Invoke-WebRequest -Uri "https://github.com/Baayramov/WAPage/releases/download/v1.2.0/WAPage-v1.2.0.zip" -OutFile "WAPage-v1.2.0.zip"</code></pre>

## VirusTotal Analiz Linki

<a>https://www.virustotal.com/gui/file/66984402bbaff5c0cc3a26264832ade4eb9bb0befb5ebcfb16023ea221e19b18/detection</a>

### Xüsusiyyətlər

- Həm Android, həm də iOS ixracını dəstəkləyir
- Məlum tətbiq vizual stilini yaxından əks etdirən interfeys dizaynı
- İşıq və Qaranlıq mövzu seçimləri
- 18 dildə mövcud olan interfeys — interfeys dilinin söhbətlərdəki məzmuna heç bir təsiri yoxdur
- Həm fərdi (təkbətək), həm də qrup söhbətləri üçün dəstək
- Bu, söhbətdə göndərilən həm sadə, həm də animasiyalı stikerlərə aiddir
- Göndərilən bütün media fayllarının, səsli mesajların, paylaşılan kontaktların və mətn mesajlarının aşkarlanması və göstərilməsi
- Söhbətdəki ilk mesaja birbaşa keçmək
- Söhbətlərin adını dəyişdirmək və xüsusi profil şəkillərini təyin etmək imkanı
- Söhbətlərin içərisindəki linklər kliklənə bilər və standart brauzerdə açılır
- Yer mesajları brauzer vasitəsilə xəritədə koordinatları açır
- Tamamilə oflayndır — heç bir nöqtədə internet bağlantısı yaradılmır, bütün məlumatlar istifadəçinin öz maşınında qalır
- Aşağı səviyyəli aparatlarda belə rahat işləmək üçün hazırlanmış aşağı resurs istifadəsi
- <b>13.000+</b> kod sətirinə qədər yazılıb <br><br>


<br><br>
<b>Bəzi həssas mətnlər/şəkillər ekran görüntülərində bulanıqlaşdırılıb</b>
<br>
<div align="center">
  <img src="https://i.imgur.com/Jkbjvb3.jpeg" />
  <img src="https://i.imgur.com/sO71g5a.jpeg" />
  <img src="https://i.imgur.com/zm2PhyH.gif" />
  <img src="https://i.imgur.com/y8Z1XUm.gif" />
</div>

### Testlər

Ən yüksək test nəticəsində, orta hesabla 6 dəqiqə ərzində 400.000-dən çox mesaj və media ehtiva edən 3.66 GB ZIP faylı daxil edə bildi.

### İnterfeys Dilləri

Azərbaycanca, Türkcə, İngiliscə, İspanca, İtalyanca, Almanca, Fransızca, Polyak, Portuqal, Rusça, Ukrayna, Monqol, Hind, Ərəbcə, Çincə (Sadələşdirilmiş), Yaponca, Koreya, Özbək

### Dəstəklənən İxrac Növləri

| Platforma |  Media ilə  | Yalnız söhbətlər (Media olmadan)  |
|-----------|--------------|----------------------------------|
|  Android  | Dəstəklənir  |          Dəstəklənir             |
|  iOS      | Dəstəklənir  |          Dəstəklənir             |

**Vacibdir:** Çat təhlilçisi hazırda yalnız sistem dili ingilis dilinə təyin edilmiş cihazdan edilən ixracları dəstəkləyir. Bu tələb olunur, çünki saat qurşağı məlumatları və sistem tərəfindən yaradılan mesajlar (məsələn, qrupa qoşulma/çıxma tədbirləri, ad dəyişiklikləri və s.) yalnız ingilis ixrac formatında tanınır. Çatların içərisindəki məzmun — mesajlar, adlar və media — məhdudiyyətsiz istənilən dildə ola bilər.

### Dəstəklənən Platformalar

| Platforma                                   |     Status       |
|---------------------------------------------|------------------|
| Windows 10 64-bit (versiya 1507 və yuxarısı)|   Dəstəklənir    |
| Windows 11 64-bit                           |   Dəstəklənir    |
| Linux                                       |  Planlaşdırılır  |
| macOS                                       |  Planlaşdırılır  |

### Kompilyasiya Təlimatları
Layihəni mənbə kodundan kompilyasiya etmək üçün, bütün lazımi asılılıqların Qt Maintenance Tool vasitəsilə düzgün quraşdırıldığından əmin olmaq məqsədilə bu addımları izləyin.

**1. Tələb Olunan Qt Komponentlərinin Quraşdırılması**

- Qt Maintenance Tool-u açın. Customize bölməsinə keçin və yuxarı sağ küncdəki Show filtr menyusundan Archive seçiminin aktiv edildiyinə əmin olun.
- Qt 6.7.3 bölməsi altında aşağıdakı modulları seçib quraşdırın:
  - MSVC 2022 64-bit
  - Qt 5 Compatibility Module
  - Qt Shader Tools
- Qt 6.7.3 -> Additional Libraries bölməsi altında seçib quraşdırın:
  - Qt Image Formats
  - Qt Multimedia
- Qt Development -> Build Tools bölməsi altında seçib quraşdırın:
  - CMake 3.30.5
  - Ninja 1.12.1
- Qt Creator bölməsi altında seçib quraşdırın:
  - Qt Creator 19.0.0

**2. Layihənin Kompilyasiyası**

- Qt Creator-u başladın. Open Project... düyməsinə klikləyin və mənbə kodu qovluğunda yerləşən `CMakeLists.txt` faylını seçin.
- Kit Selection ekranında mütləq Desktop Qt 6.7.3 MSVC2022 64-bit seçimini edin.
- Build konfiqurasiyasını Release olaraq təyin etmək tövsiyə olunur. Optimal performans üçün tətbiqin release qovluğunda xüsusi DLL-lərin olması tələb edilir. (Xətaları yoxlamaq məqsədilə Debug da seçə bilərsiniz, lakin bu, proqramın performansında hiss ediləcək dərəcədə azalmalara səbəb olacaq).
- Configure Project düyməsinə klikləyin və prosesin bitməsini gözləyin.
- Konfiqurasiya uğurla başa çatdıqdan sonra sol alt küncdəki Build düyməsi (çəkic ikonu) aktiv olacaq. Kompilyasiyanı başlatmaq üçün həmin düyməyə klikləyin.
- Build prosesi uğurla bitdikdən sonra layihə qovluğunun daxilində yeni `build` qovluğu yaranacaq. Tam kompilyasiya olunmuş icra edilə bilən proqramınızı tapmaq üçün həmin qovluğun içindəki `Desktop_Qt_6_7_3_MSVC2022_64bit-Release` və ya `Desktop_Qt_6_7_3_MSVC2022_64bit-Debug` qovluğuna daxil olun.

### Gələcək Planlar

- Linux və macOS platforma dəstəyi
- İngilis dilində olmayan sistem dilləri olan cihazlardan ixrac edilən söhbətlər üçün dəstək
- Əlavə dil və format dəstəyi

### Dəstək

Əgər bu layihəni faydalı hesab edirsinizsə və mənə dəstək olmaq istəyirsinizsə:

<a href="https://www.paypal.com/ncp/payment/AZ26AYEFY35D4">
  <img src="https://i.imgur.com/1iuuok4.png" width="120">
</a>

---

Bu proqram təminatı xüsusi mülkiyyət lisenziyası altında lisenziyalaşdırılıb. Ətraflı məlumat üçün LICENSE faylına baxın. <br>
Qt 6.7.3 — LGPL v3 — <a>https://www.qt.io/licensing/open-source-lgpl-obligations</a> <br>
NotoColorEmoji şrifti (OFL 1.1) — <a>https://fonts.google.com/noto</a> <br>

*Bu layihə WhatsApp-ın söhbət ixracı xüsusiyyəti təklif etməsinə baxmayaraq, ixrac edilmiş faylları rəsmi olaraq oxumaq üçün heç bir vasitə təqdim etməməsi səbəbindən mövcuddur. Bu tətbiq məhz bunu edir.*
