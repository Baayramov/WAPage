#include "LanguageManager.h"

void LanguageManager::initTranslations()
{
    m_langNames = {
        {"Azerbaijani", "Azərbaycan"},
        {"Afrikaans", "Afrikaans"},
        {"Albanian", "Shqip"},
        {"Arabic", "العربية"},
        {"Bengali", "বাংলা"},
        {"Bulgarian", "Български"},
        {"Catalan", "Català"},
        {"Chinese", "简体中文"},
        {"ChineseHongKong", "繁體中文 (香港)"},
        {"ChineseTaiwan", "繁體中文 (台灣)"},
        {"Croatian", "Hrvatski"},
        {"Czech", "Čeština"},
        {"Danish", "Dansk"},
        {"Dutch", "Nederlands"},
        {"English", "English"},
        {"Estonian", "Eesti"},
        {"Filipino", "Filipino"},
        {"Finnish", "Suomi"},
        {"French", "Français"},
        {"German", "Deutsch"},
        {"Greek", "Ελληνικά"},
        {"Gujarati", "ગુજરાતી"},
        {"Hebrew", "עברית"},
        {"Hindi", "हिन्दी"},
        {"Hungarian", "Magyar"},
        {"Indonesian", "Bahasa Indonesia"},
        {"Irish", "Gaeilge"},
        {"Italian", "Italiano"},
        {"Japanese", "日本語"},
        {"Kannada", "ಕನ್ನಡ"},
        {"Kazakh", "Қазақ"},
        {"Korean", "한국어"},
        {"Lao", "ລາວ"},
        {"Latvian", "Latviešu"},
        {"Lithuanian", "Lietuvių"},
        {"Macedonian", "Македонски"},
        {"Malay", "Bahasa Melayu"},
        {"Malayalam", "മലയാളം"},
        {"Marathi", "मराठी"},
        {"Mongolian", "Монгол"},
        {"Norwegian", "Norsk"},
        {"Persian", "فارسی"},
        {"Polish", "Polski"},
        {"Portuguese", "Português"},
        {"PortugueseBrazil", "Português - Brasil"},
        {"Punjabi", "ਪੰਜਾਬੀ"},
        {"Romanian", "Română"},
        {"Russian", "Русский"},
        {"Serbian", "Српски / Srpski"},
        {"Slovak", "Slovenčina"},
        {"Slovenian", "Slovenščina"},
        {"Spanish", "Español"},
        {"Swahili", "Kiswahili"},
        {"Swedish", "Svenska"},
        {"Tamil", "தமிழ்"},
        {"Telugu", "తెలుగు"},
        {"Thai", "ไทย"},
        {"Turkish", "Türkçe"},
        {"Ukrainian", "Українська"},
        {"UrduPakistan", "اردو - پاکستان"},
        {"Uzbek", "O'zbek"},
        {"Vietnamese", "Tiếng Việt"}
    };

    // Azerbaijani
    m_translations["Azerbaijani"] = {
        {"contact_info", "Kontakt məlumatı"}, {"msg_count", "Mesaj sayı"}, {"messages", "mesaj"}, {"import_date", "Daxiletmə tarixi"},
        {"no_chats", "Söhbət yoxdur\n\n+ düyməsinə basaraq\nyeni söhbət əlavə edin"}, {"light_theme", "İşıq tema"}, {"dark_theme", "Tünd tema"},
        {"new_chat_tooltip", "Yeni söhbət əlavə et"}, {"chat_search_placeholder", "Söhbətdə axtar"}, {"importing", "Daxil edilir..."},
        {"bulk_select_tooltip", "Toplu seçim"}, {"bulk_delete_tooltip", "Toplu sil"}, {"cancel_selection_tooltip", "Ləğv et"},
        {"import_new", "Yeni söhbət əlavə et"}, {"zip_description", "WhatsApp-dan export etdiyiniz ZIP faylını seçin."},
        {"select_zip", "ZIP fayl seç"}, {"change_zip", "Başqa fayl seç"}, {"continue", "Davam et"},
        {"owner_question", "Söhbətdə sizin adınız nədir?\n(WhatsApp hesabınızda görünən ad)"}, {"owner_placeholder", "Məs: Mahmud Bayramov"},
        {"import_btn", "Daxil et"}, {"back", "Geri"}, {"loading_messages", "Mesajlar yüklənir, lütfən gözləyin..."},
        {"select_zip_title", "WhatsApp ZIP faylı seçin"}, {"first_message", "İlk mesaj"}, {"delete_chat", "Söhbəti sil"}, {"search", "Axtar..."}, {"search_tooltip", "Mesajlarda axtar (Ctrl+F)"},
        {"last_message", "Son mesaj"},
        {"empty_chat_hint", "Söhbət seçin və ya yeni söhbət əlavə edin"}, {"delete_confirm_title", "Söhbəti sil"},
        {"delete_confirm_text", "Bu söhbəti silmək istədiyinizdən əminsiniz?\nBütün mesajlar silinəcək."}, {"no_results", "Nəticə tapılmadı"},
        {"yes", "Bəli"}, {"no", "Xeyr"}, {"cancel", "Ləğv et"}, {"language", "Dil"}, {"select_language", "Dil seçin"}, {"profile_photo", "Profil şəkli"},
        {"name_label", "Ad"}, {"participants_label", "Qrup iştirakçıları"}, {"contact_name_placeholder", "Kontakt adı"}, {"image_files_filter", "Şəkil faylları (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — %2 mesaj daxil edildi"}, {"conversation", "Söhbət"},
        {"default_owner_name", "Default Sahib Adı"}, {"owner_name_placeholder", "Adınız"}, {"not_set", "Təyin edilməyib"}, {"default_label", "Default"},
        {"profile_library", "Profil Kitabxanası"}, {"add_profile", "Profil əlavə et"}, {"profile_name_label", "Ad:"}, {"add_btn", "Əlavə et"},
        {"optional", "(İstəyə bağlı)"}, {"image_selected", "✓ Seçildi"}, {"no_profiles_library", "Hələ profil yoxdur. + düyməsinə klikləyin."},
        {"profile_owner_conflict", "Sahibin adı ilə eyni adlı profil əlavə edilə bilməz"}, {"profile_exists", "Bu adla profil artıq mövcuddur"},
        {"message_count_text", "mesaj"},
        {"january", "Yanvar"}, {"february", "Fevral"}, {"march", "Mart"}, {"april", "Aprel"}, {"may", "May"}, {"june", "İyun"},
        {"july", "İyul"}, {"august", "Avqust"}, {"september", "Sentyabr"}, {"october", "Oktyabr"}, {"november", "Noyabr"}, {"december", "Dekabr"},
        {"calendar_tooltip", "Tarixə keç"},
        {"last_message", "Son mesaj"},
        {"settings", "Ayarlar"},
        {"auto_play_next_voice", "Səsli mesajların ardıcıl oxunması"},
        {"open_system", "Sistemdə aç"}, {"image_not_found", "Şəkil tapılmadı"}, {"video", "Video"}, {"deleted_message", "Bu mesaj silindi"}, {"you_deleted_message", "Siz bu mesajı sildiniz"}, {"edited", "Redaktə edildi"}, {"app_version", "versiya"}, {"app_copyright", "Müəllif hüququ %1 tərəfindən"},
        {"lock_chat", "Söhbəti kilitlə"}, {"unlock_chat", "Bu söhbəti kiliddən çıxart"}, {"locked_chats", "Kilidlənmiş Söhbətlər"}, {"locked_chats_access", "Kilidlənmiş söhbətlərə giriş"},
        {"lock_chat_title", "Söhbəti kilitlə"}, {"lock_chat_message", "Bu söhbət kilidlənəcək"}, {"lock_chat_set_password", "Söhbətləri kilitləmək üçün şifrə yazın"},
        {"locked_chats_password_title", "Kilidlənmiş söhbətlər"}, {"locked_chats_enter_password", "Kilidlənmiş söhbətlərə daxil olmaq üçün şifrə yazın"},
        {"password_6_digits", "Şifrə 6 rəqəm olmalıdır"}, {"password_incorrect", "Şifrə düzgün deyil"}, {"no_master_password", "Şifrə təyin edilməyib"},
        {"locked_chats_password", "Kilidlənmiş Söhbətlərin Şifrəsi"}, {"no_password", "Şifrəniz yoxdur"}, {"change_password", "Şifrəyi dəyiş"},
        {"old_password", "Əvvəlki şifrə"}, {"new_password", "Yeni şifrə"}, {"confirm_password", "Yeni şifrəni təkrarla"}, {"change", "Dəyişdir"},
        {"old_password_incorrect", "Əvvəlki şifrə düzgün deyil"}, {"passwords_dont_match", "Yeni şifrələr uyğun gəlmir"},
        {"no_locked_chats", "Kilidlənmiş söhbət yoxdur"}, {"locked_chats_hint", "Söhbəti kilitləmək üçün 3 nöqtə menyusundan 'Söhbəti kilitlə' seçin"}, {"enter", "Daxil ol"}
    };
    m_translations["Azerbaijani"].insert(QStringLiteral("media_image"), QStringLiteral("Şəkil"));
    m_translations["Azerbaijani"].insert(QStringLiteral("media_video"), QStringLiteral("Video"));
    m_translations["Azerbaijani"].insert(QStringLiteral("media_voice"), QStringLiteral("Səs mesajı"));
    m_translations["Azerbaijani"].insert(QStringLiteral("media_audio"), QStringLiteral("Audio"));
    m_translations["Azerbaijani"].insert(QStringLiteral("media_sticker"), QStringLiteral("Stiker"));
    m_translations["Azerbaijani"].insert(QStringLiteral("media_document"), QStringLiteral("Sənəd"));
    m_translations["Azerbaijani"].insert(QStringLiteral("media_unavailable"), QStringLiteral("Media mövcud deyil"));
    m_translations["Azerbaijani"].insert(QStringLiteral("tap_to_open"), QStringLiteral("Açmaq üçün toxun"));
    m_translations["Azerbaijani"].insert(QStringLiteral("location"), QStringLiteral("Məkan"));
    m_translations["Azerbaijani"].insert(QStringLiteral("contact"), QStringLiteral("Kontaktı"));
    m_translations["Azerbaijani"].insert(QStringLiteral("favorites"), QStringLiteral("Favoritlər"));
    m_translations["Azerbaijani"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("Favorilərə əlavə et"));
    m_translations["Azerbaijani"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("Favoritlərədən sil"));
    m_translations["Azerbaijani"].insert(QStringLiteral("no_favorites"), QStringLiteral("Favoritlər yoxdur"));
    m_translations["Azerbaijani"].insert(QStringLiteral("favorites_hint"), QStringLiteral("Mesaja sağ klik edib favorilərə əlavə edin"));
    m_translations["Azerbaijani"].insert(QStringLiteral("media_browser"), QStringLiteral("Medialar"));
    m_translations["Azerbaijani"].insert(QStringLiteral("media_browser_title"), QStringLiteral("Medialar"));
    m_translations["Azerbaijani"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("Şəkillər, videolar və fayllar"));
    m_translations["Azerbaijani"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("Şəkillər"));
    m_translations["Azerbaijani"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("Videolar"));
    m_translations["Azerbaijani"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("Fayllar"));
    m_translations["Azerbaijani"].insert(QStringLiteral("media_browser_links"), QStringLiteral("Linklər"));
    m_translations["Azerbaijani"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("Konumlar"));
    m_translations["Azerbaijani"].insert(QStringLiteral("no_photos_found"), QStringLiteral("Şəkil tapılmadı"));
    m_translations["Azerbaijani"].insert(QStringLiteral("no_videos_found"), QStringLiteral("Video tapılmadı"));
    m_translations["Azerbaijani"].insert(QStringLiteral("no_documents_found"), QStringLiteral("Fayl tapılmadı"));
    m_translations["Azerbaijani"].insert(QStringLiteral("no_links_found"), QStringLiteral("Link tapılmadı"));
    m_translations["Azerbaijani"].insert(QStringLiteral("no_locations_found"), QStringLiteral("Konum tapılmadı"));

    // English
    m_translations["English"] = {
        {"contact_info", "Contact info"}, {"msg_count", "Messages"}, {"messages", "messages"}, {"import_date", "Import date"},
        {"no_chats", "No chats found\n\nClick + to add\na new chat"}, {"light_theme", "Light theme"}, {"dark_theme", "Dark theme"},
        {"new_chat_tooltip", "Add new chat"}, {"chat_search_placeholder", "Search in chats"}, {"importing", "Importing..."},
        {"bulk_select_tooltip", "Bulk selection"}, {"bulk_delete_tooltip", "Bulk delete"}, {"cancel_selection_tooltip", "Cancel"},
        {"import_new", "Add new chat"}, {"zip_description", "Select the ZIP file exported from WhatsApp."},
        {"select_zip", "Select ZIP file"}, {"change_zip", "Change file"}, {"continue", "Continue"},
        {"owner_question", "What is your name in the chat?\n(The name appearing in your WhatsApp account)"}, {"owner_placeholder", "Ex: John Doe"},
        {"import_btn", "Import"}, {"back", "Back"}, {"loading_messages", "Loading messages, please wait..."},
        {"select_zip_title", "Select WhatsApp ZIP file"}, {"first_message", "First message"}, {"delete_chat", "Delete chat"}, {"search", "Search..."}, {"search_tooltip", "Search in messages (Ctrl+F)"},
        {"empty_chat_hint", "Select a chat or add a new one"}, {"delete_confirm_title", "Delete chat"},
        {"delete_confirm_text", "Are you sure you want to delete this chat?\nAll messages will be removed."}, {"no_results", "No results found"},
        {"yes", "Yes"}, {"no", "No"}, {"cancel", "Cancel"}, {"language", "Language"}, {"select_language", "Select language"}, {"profile_photo", "Profile photo"},
        {"name_label", "Name"}, {"participants_label", "Group participants"}, {"contact_name_placeholder", "Contact name"}, {"image_files_filter", "Image files (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — %2 messages imported"}, {"conversation", "Conversation"},
        {"default_owner_name", "Default Owner Name"}, {"owner_name_placeholder", "Your name"}, {"not_set", "Not set"}, {"default_label", "Default"},
        {"profile_library", "Profile Library"}, {"add_profile", "Add Profile"}, {"profile_name_label", "Name:"}, {"add_btn", "Add"},
        {"optional", "(Optional)"}, {"image_selected", "✓ Selected"}, {"no_profiles_library", "No profiles yet. Click + to add."},
        {"profile_owner_conflict", "Cannot add profile with same name as owner"}, {"profile_exists", "Profile with this name already exists"},
        {"message_count_text", "messages"},
        {"january", "Jan"}, {"february", "Feb"}, {"march", "Mar"}, {"april", "Apr"}, {"may", "May"}, {"june", "Jun"},
        {"july", "Jul"}, {"august", "Aug"}, {"september", "Sep"}, {"october", "Oct"}, {"november", "Nov"}, {"december", "Dec"},
        {"calendar_tooltip", "Jump to date"},
        {"last_message", "Last message"},
        {"settings", "Settings"},
        {"auto_play_next_voice", "Auto-play sequential voice messages"},
        {"open_system", "Open in system"}, {"image_not_found", "Image not found"}, {"video", "Video"}, {"deleted_message", "This message was deleted"}, {"you_deleted_message", "You deleted this message"}, {"edited", "Edited"}, {"app_version", "version"}, {"app_copyright", "Copyright by %1"},
        {"lock_chat", "Lock chat"}, {"unlock_chat", "Unlock this chat"}, {"locked_chats", "Locked Chats"}, {"locked_chats_access", "Access locked chats"},
        {"lock_chat_title", "Lock chat"}, {"lock_chat_message", "This chat will be locked"}, {"lock_chat_set_password", "Set password to lock chats"},
        {"locked_chats_password_title", "Locked chats"}, {"locked_chats_enter_password", "Enter password to access locked chats"},
        {"password_6_digits", "Password must be 6 digits"}, {"password_incorrect", "Incorrect password"}, {"no_master_password", "No password set"},
        {"locked_chats_password", "Locked Chats Password"}, {"no_password", "You don't have a password"}, {"change_password", "Change password"},
        {"old_password", "Old password"}, {"new_password", "New password"}, {"confirm_password", "Confirm new password"}, {"change", "Change"},
        {"old_password_incorrect", "Old password is incorrect"}, {"passwords_dont_match", "New passwords don't match"},
        {"no_locked_chats", "No locked chats"}, {"locked_chats_hint", "Select 'Lock chat' from the 3-dot menu to lock a chat"}, {"enter", "Enter"}
    };
    m_translations["English"].insert(QStringLiteral("media_image"), QStringLiteral("Photo"));
    m_translations["English"].insert(QStringLiteral("media_video"), QStringLiteral("Video"));
    m_translations["English"].insert(QStringLiteral("media_voice"), QStringLiteral("Voice message"));
    m_translations["English"].insert(QStringLiteral("media_audio"), QStringLiteral("Audio"));
    m_translations["English"].insert(QStringLiteral("media_sticker"), QStringLiteral("Sticker"));
    m_translations["English"].insert(QStringLiteral("media_document"), QStringLiteral("Document"));
    m_translations["English"].insert(QStringLiteral("media_unavailable"), QStringLiteral("Media unavailable"));
    m_translations["English"].insert(QStringLiteral("tap_to_open"), QStringLiteral("Tap to open"));
    m_translations["English"].insert(QStringLiteral("location"), QStringLiteral("Location"));
    m_translations["English"].insert(QStringLiteral("contact"), QStringLiteral("Contact"));
    m_translations["English"].insert(QStringLiteral("favorites"), QStringLiteral("Favorites"));
    m_translations["English"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("Add to favorites"));
    m_translations["English"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("Remove from favorites"));
    m_translations["English"].insert(QStringLiteral("no_favorites"), QStringLiteral("No favorites"));
    m_translations["English"].insert(QStringLiteral("favorites_hint"), QStringLiteral("Right-click a message to add to favorites"));
    m_translations["English"].insert(QStringLiteral("media_browser"), QStringLiteral("Media"));
    m_translations["English"].insert(QStringLiteral("media_browser_title"), QStringLiteral("Media"));
    m_translations["English"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("Photos, videos and files"));
    m_translations["English"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("Photos"));
    m_translations["English"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("Videos"));
    m_translations["English"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("Documents"));
    m_translations["English"].insert(QStringLiteral("media_browser_links"), QStringLiteral("Links"));
    m_translations["English"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("Locations"));
    m_translations["English"].insert(QStringLiteral("no_photos_found"), QStringLiteral("No photos found"));
    m_translations["English"].insert(QStringLiteral("no_videos_found"), QStringLiteral("No videos found"));
    m_translations["English"].insert(QStringLiteral("no_documents_found"), QStringLiteral("No documents found"));
    m_translations["English"].insert(QStringLiteral("no_links_found"), QStringLiteral("No links found"));
    m_translations["English"].insert(QStringLiteral("no_locations_found"), QStringLiteral("No locations found"));

    // Turkish
    m_translations["Turkish"] = {
        {"contact_info", "Kişi bilgisi"}, {"msg_count", "Mesaj sayısı"}, {"messages", "mesaj"}, {"import_date", "İçe aktarma tarihi"},
        {"no_chats", "Sohbet bulunamadı\n\n+ butonuna basarak\nyeni sohbet ekleyin"}, {"light_theme", "Aydınlık tema"}, {"dark_theme", "Karanlık tema"},
        {"new_chat_tooltip", "Yeni sohbet ekle"}, {"chat_search_placeholder", "Sohbetlerde ara"}, {"importing", "İçe aktarılıyor..."},
        {"bulk_select_tooltip", "Toplu seçim"}, {"bulk_delete_tooltip", "Toplu sil"}, {"cancel_selection_tooltip", "İptal"},
        {"import_new", "Yeni sohbet ekle"}, {"zip_description", "WhatsApp'tan dışa aktarılan ZIP dosyasını seçin."},
        {"select_zip", "ZIP seç"}, {"change_zip", "Dosyayı değiştir"}, {"continue", "Devam et"},
        {"owner_question", "Sohbetteki adınız nedir?\n(WhatsApp hesabınızda görünen ad)"}, {"owner_placeholder", "Örn: Ahmet Yılmaz"},
        {"import_btn", "İçe aktar"}, {"back", "Geri"}, {"loading_messages", "Mesajlar yükleniyor, lütfen bekleyin..."},
        {"select_zip_title", "WhatsApp ZIP dosyası seçin"}, {"first_message", "İlk mesaj"}, {"delete_chat", "Sohbeti sil"}, {"search", "Ara..."}, {"search_tooltip", "Mesajlarda ara (Ctrl+F)"},
        {"empty_chat_hint", "Bir sohbet seçin veya yeni birini ekleyin"}, {"delete_confirm_title", "Sohbeti sil"},
        {"delete_confirm_text", "Bu sohbeti silmek istediğinizden emin misiniz?\nTüm mesajlar silinecektir."}, {"no_results", "Sonuç bulunamadı"},
        {"yes", "Evet"}, {"no", "Hayır"}, {"cancel", "İptal"}, {"language", "Dil"}, {"select_language", "Dil seçin"}, {"profile_photo", "Profil fotoğrafı"},
        {"name_label", "Ad"}, {"participants_label", "Grup katılımcıları"}, {"contact_name_placeholder", "Kişi adı"}, {"image_files_filter", "Görsel dosyaları (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — %2 mesaj içe aktarıldı"}, {"conversation", "Sohbet"},
        {"default_owner_name", "Varsayılan Sahip Adı"}, {"owner_name_placeholder", "Adınız"}, {"not_set", "Ayarlanmadı"}, {"default_label", "Varsayılan"},
        {"profile_library", "Profil Kütüphanesi"}, {"add_profile", "Profil Ekle"}, {"profile_name_label", "Ad:"}, {"add_btn", "Ekle"},
        {"optional", "(İsteğe bağlı)"}, {"image_selected", "✓ Seçildi"}, {"no_profiles_library", "Henüz profil yok. Eklemek için + tıklayın."},
        {"profile_owner_conflict", "Sahibin adıyla aynı isimde profil eklenemez"}, {"profile_exists", "Bu isimle profil zaten mevcut"},
        {"message_count_text", "mesaj"},
        {"january", "Oca"}, {"february", "Şub"}, {"march", "Mar"}, {"april", "Nis"}, {"may", "May"}, {"june", "Haz"},
        {"july", "Tem"}, {"august", "Ağu"}, {"september", "Eyl"}, {"october", "Eki"}, {"november", "Kas"}, {"december", "Ara"},
        {"calendar_tooltip", "Tarihe git"},
        {"last_message", "Son mesaj"},
        {"settings", "Ayarlar"},
        {"auto_play_next_voice", "Sesli mesajları ardışık çal"},
        {"open_system", "Sistemde aç"}, {"image_not_found", "Resim bulunamadı"}, {"video", "Video"}, {"deleted_message", "Bu mesaj silindi"}, {"you_deleted_message", "Bu mesajı siz sildiniz"}, {"edited", "Düzenlendi"}, {"app_version", "sürüm"}, {"app_copyright", "Telif hakkı %1 tarafından"},
        {"lock_chat", "Sohbeti kilitle"}, {"unlock_chat", "Bu sohbeti kilitle aç"}, {"locked_chats", "Kilitli Sohbetler"}, {"locked_chats_access", "Kilitli sohbetlere giriş"},
        {"lock_chat_title", "Sohbeti kilitle"}, {"lock_chat_message", "Bu sohbet kilitlenecek"}, {"lock_chat_set_password", "Sohbetleri kilitlemek için şifre belirleyin"},
        {"locked_chats_password_title", "Kilitli sohbetler"}, {"locked_chats_enter_password", "Kilitli sohbetlere girmek için şifre girin"},
        {"password_6_digits", "Şifre 6 rakam olmalıdır"}, {"password_incorrect", "Yanlış şifre"}, {"no_master_password", "Şifre ayarlanmadı"},
        {"locked_chats_password", "Kilitli Sohbetler Şifresi"}, {"no_password", "Şifreniz yok"}, {"change_password", "Şifreyi değiştir"},
        {"old_password", "Eski şifre"}, {"new_password", "Yeni şifre"}, {"confirm_password", "Yeni şifreyi onayla"}, {"change", "Değiştir"},
        {"old_password_incorrect", "Eski şifre yanlış"}, {"passwords_dont_match", "Yeni şifreler eşleşmiyor"},
        {"no_locked_chats", "Kilitli sohbet yok"}, {"locked_chats_hint", "Bir sohbeti kilitlemek için 3 nokta menüsünden 'Sohbeti kilitle' seçin"}, {"enter", "Giriş"}
    };
    m_translations["Turkish"].insert(QStringLiteral("media_image"), QStringLiteral("Fotoğraf"));
    m_translations["Turkish"].insert(QStringLiteral("media_video"), QStringLiteral("Video"));
    m_translations["Turkish"].insert(QStringLiteral("media_voice"), QStringLiteral("Sesli mesaj"));
    m_translations["Turkish"].insert(QStringLiteral("media_audio"), QStringLiteral("Ses"));
    m_translations["Turkish"].insert(QStringLiteral("media_sticker"), QStringLiteral("Etiket"));
    m_translations["Turkish"].insert(QStringLiteral("media_document"), QStringLiteral("Belge"));
    m_translations["Turkish"].insert(QStringLiteral("media_unavailable"), QStringLiteral("Medya mevcut değil"));
    m_translations["Turkish"].insert(QStringLiteral("tap_to_open"), QStringLiteral("Açmak için dokun"));
    m_translations["Turkish"].insert(QStringLiteral("location"), QStringLiteral("Konum"));
    m_translations["Turkish"].insert(QStringLiteral("contact"), QStringLiteral("Kişi"));
    m_translations["Turkish"].insert(QStringLiteral("favorites"), QStringLiteral("Favoriler"));
    m_translations["Turkish"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("Favorilere ekle"));
    m_translations["Turkish"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("Favorilerden kaldır"));
    m_translations["Turkish"].insert(QStringLiteral("no_favorites"), QStringLiteral("Favori yok"));
    m_translations["Turkish"].insert(QStringLiteral("favorites_hint"), QStringLiteral("Mesaja sağ tıklayıp favorilere ekleyin"));
    m_translations["Turkish"].insert(QStringLiteral("media_browser"), QStringLiteral("Medya"));
    m_translations["Turkish"].insert(QStringLiteral("media_browser_title"), QStringLiteral("Medya"));
    m_translations["Turkish"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("Fotoğraflar, videolar ve dosyalar"));
    m_translations["Turkish"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("Fotoğraflar"));
    m_translations["Turkish"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("Videolar"));
    m_translations["Turkish"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("Belgeler"));
    m_translations["Turkish"].insert(QStringLiteral("media_browser_links"), QStringLiteral("Bağlantılar"));
    m_translations["Turkish"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("Konumlar"));
    m_translations["Turkish"].insert(QStringLiteral("no_photos_found"), QStringLiteral("Fotoğraf bulunamadı"));
    m_translations["Turkish"].insert(QStringLiteral("no_videos_found"), QStringLiteral("Video bulunamadı"));
    m_translations["Turkish"].insert(QStringLiteral("no_documents_found"), QStringLiteral("Belge bulunamadı"));
    m_translations["Turkish"].insert(QStringLiteral("no_links_found"), QStringLiteral("Bağlantı bulunamadı"));
    m_translations["Turkish"].insert(QStringLiteral("no_locations_found"), QStringLiteral("Konum bulunamadı"));

    // Arabic
    m_translations["Arabic"] = {
        {"contact_info", "معلومات الاتصال"}, {"msg_count", "عدد الرسائل"}, {"messages", "رسائل"}, {"import_date", "تاريخ الاستيراد"},
        {"no_chats", "لم يتم العثور على دردشات\n\nانقر فوق + لإضافة\nدردشة جديدة"}, {"light_theme", "مظهر فاتح"}, {"dark_theme", "مظهر داكن"},
        {"new_chat_tooltip", "إضافة دردشة جديدة"}, {"chat_search_placeholder", "البحث في الدردشات"}, {"importing", "جارٍ الاستيراد..."},
        {"bulk_select_tooltip", "اختيار متعدد"}, {"bulk_delete_tooltip", "حذف متعدد"}, {"cancel_selection_tooltip", "إلغاء"},
        {"import_new", "إضافة دردشة جديدة"}, {"zip_description", "حدد ملف ZIP المصدر من WhatsApp."},
        {"select_zip", "حدد ملف ZIP"}, {"change_zip", "تغيير الملف"}, {"continue", "استمرار"},
        {"owner_question", "ما اسمك في الدردشة؟\n(الاسم الذي يظهر في حساب WhatsApp الخاص بك)"}, {"owner_placeholder", "مثال: محمد علي"},
        {"import_btn", "استيراد"}, {"back", "رجوع"}, {"loading_messages", "جارٍ تحميل الرسائل، يرجى الانتظار..."},
        {"select_zip_title", "حدد ملف WhatsApp ZIP"}, {"first_message", "أول رسالة"}, {"delete_chat", "حذف الدردشة"}, {"search", "بحث..."}, {"search_tooltip", "البحث في الرسائل (Ctrl+F)"},
        {"empty_chat_hint", "حدد دردشة أو أضف واحدة جديدة"}, {"delete_confirm_title", "حذف الدردشة"},
        {"delete_confirm_text", "هل أنت متأكد أنك تريد حذف هذه الدردشة؟\nسيتم حذف جميع الرسائل."}, {"no_results", "لم يتم العثور على نتائج"},
        {"yes", "نعم"}, {"no", "لا"}, {"cancel", "إلغاء"}, {"language", "اللغة"}, {"select_language", "اختر اللغة"}, {"profile_photo", "صورة الملف الشخصي"},
        {"name_label", "الاسم"}, {"participants_label", "أعضاء المجموعة"}, {"contact_name_placeholder", "اسم جهة الاتصال"}, {"image_files_filter", "ملفات الصور (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — تم استيراد %2 رسالة"}, {"conversation", "محادثة"},
        {"default_owner_name", "اسم المالك الافتراضي"}, {"owner_name_placeholder", "اسمك"}, {"not_set", "غير محدد"}, {"default_label", "افتراضي"},
        {"profile_library", "مكتبة الملفات الشخصية"}, {"add_profile", "إضافة ملف شخصي"}, {"profile_name_label", "الاسم:"}, {"add_btn", "إضافة"},
        {"optional", "(اختياري)"}, {"image_selected", "✓ تم التحديد"}, {"no_profiles_library", "لا توجد ملفات شخصية بعد. انقر فوق + للإضافة."},
        {"profile_owner_conflict", "لا يمكن إضافة ملف شخصي بنفس اسم المالك"}, {"profile_exists", "ملف شخصي بهذا الاسم موجود بالفعل"},
        {"message_count_text", "رسالة"},
        {"january", "ينا"}, {"february", "فبر"}, {"march", "مار"}, {"april", "أبر"}, {"may", "ماي"}, {"june", "يون"},
        {"july", "يول"}, {"august", "أغس"}, {"september", "سبت"}, {"october", "أكت"}, {"november", "نوف"}, {"december", "ديس"},
        {"calendar_tooltip", "الانتقال إلى التاريخ"},
        {"last_message", "الرسالة الأخيرة"},
        {"settings", "الإعدادات"},
        {"auto_play_next_voice", "تشغيل الرسائل الصوتية المتسلسلة تلقائيًا"},
        {"open_system", "فتح في النظام"}, {"image_not_found", "الصورة غير موجودة"}, {"video", "فيديو"}, {"deleted_message", "تم حذف هذه الرسالة"}, {"you_deleted_message", "لقد حذفت هذه الرسالة"}, {"edited", "تم تعديله"}, {"app_version", "إصدار"}, {"app_copyright", "حقوق النشر محفوظة لـ %1"},
        {"lock_chat", "قفل الدردشة"}, {"unlock_chat", "إلغاء قفل هذه الدردشة"}, {"locked_chats", "الدردشات المقفلة"}, {"locked_chats_access", "الوصول إلى الدردشات المقفلة"},
        {"lock_chat_title", "قفل الدردشة"}, {"lock_chat_message", "سيتم قفل هذه الدردشة"}, {"lock_chat_set_password", "تعيين كلمة مرور لقفل الدردشات"},
        {"locked_chats_password_title", "الدردشات المقفلة"}, {"locked_chats_enter_password", "أدخل كلمة المرور للوصول إلى الدردشات المقفلة"},
        {"password_6_digits", "يجب أن تتكون كلمة المرور من 6 أرقام"}, {"password_incorrect", "كلمة مرور غير صحيحة"}, {"no_master_password", "لم يتم تعيين كلمة مرور"},
        {"locked_chats_password", "كلمة مرور الدردشات المقفلة"}, {"no_password", "ليس لديك كلمة مرور"}, {"change_password", "تغيير كلمة المرور"},
        {"old_password", "كلمة المرور القديمة"}, {"new_password", "كلمة المرور الجديدة"}, {"confirm_password", "تأكيد كلمة المرور الجديدة"}, {"change", "تغيير"},
        {"old_password_incorrect", "كلمة المرور القديمة غير صحيحة"}, {"passwords_dont_match", "كلمات المرور الجديدة غير متطابقة"},
        {"no_locked_chats", "لا توجد دردشات مقفلة"}, {"locked_chats_hint", "حدد 'قفل الدردشة' من قائمة النقاط الثلاث لقفل دردشة"}, {"enter", "دخول"}
    };
    m_translations["Arabic"].insert(QStringLiteral("media_image"), QStringLiteral("صورة"));
    m_translations["Arabic"].insert(QStringLiteral("media_video"), QStringLiteral("فيديو"));
    m_translations["Arabic"].insert(QStringLiteral("media_voice"), QStringLiteral("رسالة صوتية"));
    m_translations["Arabic"].insert(QStringLiteral("media_audio"), QStringLiteral("صوت"));
    m_translations["Arabic"].insert(QStringLiteral("media_sticker"), QStringLiteral("ملصق"));
    m_translations["Arabic"].insert(QStringLiteral("media_document"), QStringLiteral("مستند"));
    m_translations["Arabic"].insert(QStringLiteral("media_unavailable"), QStringLiteral("الوسائط غير متاحة"));
    m_translations["Arabic"].insert(QStringLiteral("tap_to_open"), QStringLiteral("اضغط للفتح"));
    m_translations["Arabic"].insert(QStringLiteral("location"), QStringLiteral("الموقع"));
    m_translations["Arabic"].insert(QStringLiteral("contact"), QStringLiteral("جهة اتصال"));
    m_translations["Arabic"].insert(QStringLiteral("favorites"), QStringLiteral("المفضلة"));
    m_translations["Arabic"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("إضافة إلى المفضلة"));
    m_translations["Arabic"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("إزالة من المفضلة"));
    m_translations["Arabic"].insert(QStringLiteral("no_favorites"), QStringLiteral("لا توجد مفضلة"));
    m_translations["Arabic"].insert(QStringLiteral("favorites_hint"), QStringLiteral("انقر بزر الماوس الأيمن لإضافة إلى المفضلة"));
    m_translations["Arabic"].insert(QStringLiteral("media_browser"), QStringLiteral("الوسائط"));
    m_translations["Arabic"].insert(QStringLiteral("media_browser_title"), QStringLiteral("الوسائط"));
    m_translations["Arabic"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("الصور والفيديوهات والملفات"));
    m_translations["Arabic"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("الصور"));
    m_translations["Arabic"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("الفيديوهات"));
    m_translations["Arabic"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("المستندات"));
    m_translations["Arabic"].insert(QStringLiteral("media_browser_links"), QStringLiteral("الروابط"));
    m_translations["Arabic"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("المواقع"));
    m_translations["Arabic"].insert(QStringLiteral("no_photos_found"), QStringLiteral("لم يتم العثور على صور"));
    m_translations["Arabic"].insert(QStringLiteral("no_videos_found"), QStringLiteral("لم يتم العثور على فيديوهات"));
    m_translations["Arabic"].insert(QStringLiteral("no_documents_found"), QStringLiteral("لم يتم العثور على مستندات"));
    m_translations["Arabic"].insert(QStringLiteral("no_links_found"), QStringLiteral("لم يتم العثور على روابط"));
    m_translations["Arabic"].insert(QStringLiteral("no_locations_found"), QStringLiteral("لم يتم العثور على مواقع"));

    // Russian
    m_translations["Russian"] = {
        {"contact_info", "Данные контакта"}, {"msg_count", "Сообщения"}, {"messages", "сообщений"}, {"import_date", "Дата импорта"},
        {"no_chats", "Чаты не найдены\n\nНажмите +, чтобы добавить\nновый чат"}, {"light_theme", "Светлая тема"}, {"dark_theme", "Темная тема"},
        {"new_chat_tooltip", "Добавить новый чат"}, {"chat_search_placeholder", "Поиск в чатах"}, {"importing", "Импорт..."},
        {"bulk_select_tooltip", "Массовый выбор"}, {"bulk_delete_tooltip", "Массовое удаление"}, {"cancel_selection_tooltip", "Отмена"},
        {"import_new", "Добавить новый чат"}, {"zip_description", "Выберите ZIP-файл, экспортированный из WhatsApp."},
        {"select_zip", "Выбрать ZIP"}, {"change_zip", "Изменить файл"}, {"continue", "Продолжить"},
        {"owner_question", "Как вас зовут в чате?\n(Имя в вашем аккаунте WhatsApp)"}, {"owner_placeholder", "Напр: Иван Иванов"},
        {"import_btn", "Импорт"}, {"back", "Назад"}, {"loading_messages", "Загрузка сообщений, подождите..."},
        {"select_zip_title", "Выберите ZIP-файл WhatsApp"}, {"first_message", "Первое сообщение"}, {"delete_chat", "Удалить чат"}, {"search", "Поиск..."}, {"search_tooltip", "Поиск в сообщениях (Ctrl+F)"},
        {"empty_chat_hint", "Выберите чат или добавьте новый"}, {"delete_confirm_title", "Удалить чат"},
        {"delete_confirm_text", "Вы уверены, что хотите удалить этот чат?\nВсе сообщения будут удалены."}, {"no_results", "Результатов не найдено"},
        {"yes", "Да"}, {"no", "Нет"}, {"cancel", "Отмена"}, {"language", "Язык"}, {"select_language", "Выберите язык"}, {"profile_photo", "Фото профиля"},
        {"name_label", "Имя"}, {"participants_label", "Участники группы"}, {"contact_name_placeholder", "Имя контакта"}, {"image_files_filter", "Файлы изображений (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — импортировано %2 сообщ."}, {"conversation", "Беседа"},
        {"default_owner_name", "Имя владельца по умолчанию"}, {"owner_name_placeholder", "Ваше имя"}, {"not_set", "Не задано"}, {"default_label", "По умолчанию"},
        {"profile_library", "Библиотека профилей"}, {"add_profile", "Добавить профиль"}, {"profile_name_label", "Имя:"}, {"add_btn", "Добавить"},
        {"optional", "(Необязательно)"}, {"image_selected", "✓ Выбрано"}, {"no_profiles_library", "Профилей пока нет. Нажмите +, чтобы добавить."},
        {"profile_owner_conflict", "Нельзя добавить профиль с таким же именем, как у владельца"}, {"profile_exists", "Профиль с таким именем уже существует"},
        {"message_count_text", "сообщений"},
        {"january", "Янв"}, {"february", "Фев"}, {"march", "Мар"}, {"april", "Апр"}, {"may", "Май"}, {"june", "Июн"},
        {"july", "Июл"}, {"august", "Авг"}, {"september", "Сен"}, {"october", "Окт"}, {"november", "Ноя"}, {"december", "Дек"},
        {"calendar_tooltip", "Перейти к дате"},
        {"last_message", "Последнее сообщение"},
        {"settings", "Настройки"},
        {"auto_play_next_voice", "Автовоспроизведение последовательных голосовых сообщений"},
        {"open_system", "Открыть в системе"}, {"image_not_found", "Изображение не найдено"}, {"video", "Видео"}, {"deleted_message", "Это сообщение удалено"}, {"you_deleted_message", "Вы удалили это сообщение"}, {"edited", "Изменено"}, {"app_version", "версия"}, {"app_copyright", "Авторские права принадлежат %1"},
        {"lock_chat", "Заблокировать чат"}, {"unlock_chat", "Разблокировать этот чат"}, {"locked_chats", "Заблокированные чаты"}, {"locked_chats_access", "Доступ к заблокированным чатам"},
        {"lock_chat_title", "Заблокировать чат"}, {"lock_chat_message", "Этот чат будет заблокирован"}, {"lock_chat_set_password", "Установите пароль для блокировки чатов"},
        {"locked_chats_password_title", "Заблокированные чаты"}, {"locked_chats_enter_password", "Введите пароль для доступа к заблокированным чатам"},
        {"password_6_digits", "Пароль должен состоять из 6 цифр"}, {"password_incorrect", "Неверный пароль"}, {"no_master_password", "Пароль не установлен"},
        {"locked_chats_password", "Пароль заблокированных чатов"}, {"no_password", "У вас нет пароля"}, {"change_password", "Изменить пароль"},
        {"old_password", "Старый пароль"}, {"new_password", "Новый пароль"}, {"confirm_password", "Подтвердите новый пароль"}, {"change", "Изменить"},
        {"old_password_incorrect", "Старый пароль неверен"}, {"passwords_dont_match", "Новые пароли не совпадают"},
        {"no_locked_chats", "Нет заблокированных чатов"}, {"locked_chats_hint", "Выберите 'Заблокировать чат' в меню с тремя точками"}, {"enter", "Войти"}
    };
    m_translations["Russian"].insert(QStringLiteral("media_image"), QStringLiteral("Фото"));
    m_translations["Russian"].insert(QStringLiteral("media_video"), QStringLiteral("Видео"));
    m_translations["Russian"].insert(QStringLiteral("media_voice"), QStringLiteral("Голосовое сообщение"));
    m_translations["Russian"].insert(QStringLiteral("media_audio"), QStringLiteral("Аудио"));
    m_translations["Russian"].insert(QStringLiteral("media_sticker"), QStringLiteral("Стикер"));
    m_translations["Russian"].insert(QStringLiteral("media_document"), QStringLiteral("Документ"));
    m_translations["Russian"].insert(QStringLiteral("media_unavailable"), QStringLiteral("Медиа недоступно"));
    m_translations["Russian"].insert(QStringLiteral("tap_to_open"), QStringLiteral("Нажмите чтобы открыть"));
    m_translations["Russian"].insert(QStringLiteral("location"), QStringLiteral("Местоположение"));
    m_translations["Russian"].insert(QStringLiteral("contact"), QStringLiteral("Контакт"));
    m_translations["Russian"].insert(QStringLiteral("favorites"), QStringLiteral("Избранное"));
    m_translations["Russian"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("Добавить в избранное"));
    m_translations["Russian"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("Удалить из избранного"));
    m_translations["Russian"].insert(QStringLiteral("no_favorites"), QStringLiteral("Нет избранного"));
    m_translations["Russian"].insert(QStringLiteral("favorites_hint"), QStringLiteral("Щелкните правой кнопкой для добавления"));
    m_translations["Russian"].insert(QStringLiteral("media_browser"), QStringLiteral("Медиа"));
    m_translations["Russian"].insert(QStringLiteral("media_browser_title"), QStringLiteral("Медиа"));
    m_translations["Russian"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("Фото, видео и файлы"));
    m_translations["Russian"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("Фото"));
    m_translations["Russian"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("Видео"));
    m_translations["Russian"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("Документы"));
    m_translations["Russian"].insert(QStringLiteral("media_browser_links"), QStringLiteral("Ссылки"));
    m_translations["Russian"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("Местоположения"));
    m_translations["Russian"].insert(QStringLiteral("no_photos_found"), QStringLiteral("Фотографии не найдены"));
    m_translations["Russian"].insert(QStringLiteral("no_videos_found"), QStringLiteral("Видео не найдены"));
    m_translations["Russian"].insert(QStringLiteral("no_documents_found"), QStringLiteral("Документы не найдены"));
    m_translations["Russian"].insert(QStringLiteral("no_links_found"), QStringLiteral("Ссылки не найдены"));
    m_translations["Russian"].insert(QStringLiteral("no_locations_found"), QStringLiteral("Местоположения не найдены"));

    // Spanish
    m_translations["Spanish"] = {
        {"contact_info", "Info. contacto"}, {"msg_count", "Mensajes"}, {"messages", "mensajes"}, {"import_date", "Fecha imp."},
        {"no_chats", "No hay chats"}, {"light_theme", "Tema claro"}, {"dark_theme", "Tema oscuro"},
        {"new_chat_tooltip", "Nuevo chat"}, {"chat_search_placeholder", "Buscar chats"}, {"importing", "Importando..."},
        {"bulk_select_tooltip", "Selección múltiple"}, {"bulk_delete_tooltip", "Eliminar múltiple"}, {"cancel_selection_tooltip", "Cancelar"},
        {"import_new", "Añadir chat"}, {"zip_description", "Seleccione el archivo ZIP de WhatsApp."},
        {"select_zip", "Seleccionar ZIP"}, {"change_zip", "Cambiar archivo"}, {"continue", "Continuar"},
        {"owner_question", "¿Cuál es tu nombre?\n(El nombre que aparece en tu cuenta de WhatsApp)"}, {"owner_placeholder", "Ej: Juan Pérez"},
        {"import_btn", "Importar"}, {"back", "Atrás"}, {"loading_messages", "Cargando..."},
        {"select_zip_title", "Seleccionar ZIP de WhatsApp"}, {"first_message", "Primer mensaje"}, {"delete_chat", "Eliminar chat"}, {"search", "Buscar..."}, {"search_tooltip", "Buscar en mensajes (Ctrl+F)"},
        {"empty_chat_hint", "Selecciona un chat"}, {"delete_confirm_title", "Eliminar"},
        {"delete_confirm_text", "¿Eliminar chat?"}, {"no_results", "Sin resultados"},
        {"yes", "Sí"}, {"no", "No"}, {"cancel", "Cancelar"}, {"language", "Idioma"}, {"select_language", "Idioma"}, {"profile_photo", "Foto"},
        {"name_label", "Nombre"}, {"participants_label", "Participantes del grupo"}, {"contact_name_placeholder", "Nombre del contacto"}, {"image_files_filter", "Archivos de imagen (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — %2 mensajes importados"}, {"conversation", "Conversación"},
        {"default_owner_name", "Nombre predeterminado del propietario"}, {"owner_name_placeholder", "Tu nombre"}, {"not_set", "No establecido"}, {"default_label", "Predeterminado"},
        {"profile_library", "Biblioteca de perfiles"}, {"add_profile", "Agregar perfil"}, {"profile_name_label", "Nombre:"}, {"add_btn", "Agregar"},
        {"optional", "(Opcional)"}, {"image_selected", "✓ Seleccionado"}, {"no_profiles_library", "Aún no hay perfiles. Haga clic en + para agregar."},
        {"profile_owner_conflict", "No se puede agregar un perfil con el mismo nombre que el propietario"}, {"profile_exists", "Ya existe un perfil con este nombre"},
        {"message_count_text", "mensajes"},
        {"january", "Ene"}, {"february", "Feb"}, {"march", "Mar"}, {"april", "Abr"}, {"may", "May"}, {"june", "Jun"},
        {"july", "Jul"}, {"august", "Ago"}, {"september", "Sep"}, {"october", "Oct"}, {"november", "Nov"}, {"december", "Dic"},
        {"calendar_tooltip", "Ir a fecha"},
        {"last_message", "Último mensaje"},
        {"settings", "Configuración"},
        {"auto_play_next_voice", "Reproducir automáticamente mensajes de voz secuenciales"},
        {"open_system", "Abrir en sistema"}, {"image_not_found", "Imagen no encontrada"}, {"video", "Video"}, {"deleted_message", "Este mensaje fue eliminado"}, {"you_deleted_message", "Eliminaste este mensaje"}, {"edited", "Editado"}, {"app_version", "versión"}, {"app_copyright", "Derechos de autor de %1"},
        {"lock_chat", "Bloquear chat"}, {"unlock_chat", "Desbloquear este chat"}, {"locked_chats", "Chats bloqueados"}, {"locked_chats_access", "Acceder a chats bloqueados"},
        {"lock_chat_title", "Bloquear chat"}, {"lock_chat_message", "Este chat será bloqueado"}, {"lock_chat_set_password", "Establece contraseña para bloquear chats"},
        {"locked_chats_password_title", "Chats bloqueados"}, {"locked_chats_enter_password", "Ingresa contraseña para acceder a chats bloqueados"},
        {"password_6_digits", "La contraseña debe tener 6 dígitos"}, {"password_incorrect", "Contraseña incorrecta"}, {"no_master_password", "No hay contraseña establecida"},
        {"locked_chats_password", "Contraseña de chats bloqueados"}, {"no_password", "No tienes contraseña"}, {"change_password", "Cambiar contraseña"},
        {"old_password", "Contraseña anterior"}, {"new_password", "Nueva contraseña"}, {"confirm_password", "Confirmar nueva contraseña"}, {"change", "Cambiar"},
        {"old_password_incorrect", "La contraseña anterior es incorrecta"}, {"passwords_dont_match", "Las nuevas contraseñas no coinciden"},
        {"no_locked_chats", "No hay chats bloqueados"}, {"locked_chats_hint", "Selecciona 'Bloquear chat' del menú de 3 puntos para bloquear un chat"}, {"enter", "Entrar"}
    };
    m_translations["Spanish"].insert(QStringLiteral("media_image"), QStringLiteral("Foto"));
    m_translations["Spanish"].insert(QStringLiteral("media_video"), QStringLiteral("Video"));
    m_translations["Spanish"].insert(QStringLiteral("media_voice"), QStringLiteral("Mensaje de voz"));
    m_translations["Spanish"].insert(QStringLiteral("media_audio"), QStringLiteral("Audio"));
    m_translations["Spanish"].insert(QStringLiteral("media_sticker"), QStringLiteral("Sticker"));
    m_translations["Spanish"].insert(QStringLiteral("media_document"), QStringLiteral("Documento"));
    m_translations["Spanish"].insert(QStringLiteral("media_unavailable"), QStringLiteral("Multimedia no disponible"));
    m_translations["Spanish"].insert(QStringLiteral("tap_to_open"), QStringLiteral("Toca para abrir"));
    m_translations["Spanish"].insert(QStringLiteral("location"), QStringLiteral("Ubicación"));
    m_translations["Spanish"].insert(QStringLiteral("contact"), QStringLiteral("Contacto"));
    m_translations["Spanish"].insert(QStringLiteral("favorites"), QStringLiteral("Favoritos"));
    m_translations["Spanish"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("Añadir a favoritos"));
    m_translations["Spanish"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("Quitar de favoritos"));
    m_translations["Spanish"].insert(QStringLiteral("no_favorites"), QStringLiteral("No hay favoritos"));
    m_translations["Spanish"].insert(QStringLiteral("favorites_hint"), QStringLiteral("Haga clic derecho en un mensaje para añadir a favoritos"));
    m_translations["Spanish"].insert(QStringLiteral("media_browser"), QStringLiteral("Multimedia"));
    m_translations["Spanish"].insert(QStringLiteral("media_browser_title"), QStringLiteral("Multimedia"));
    m_translations["Spanish"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("Fotos, videos y archivos"));
    m_translations["Spanish"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("Fotos"));
    m_translations["Spanish"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("Videos"));
    m_translations["Spanish"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("Documentos"));
    m_translations["Spanish"].insert(QStringLiteral("media_browser_links"), QStringLiteral("Enlaces"));
    m_translations["Spanish"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("Ubicaciones"));
    m_translations["Spanish"].insert(QStringLiteral("no_photos_found"), QStringLiteral("No se encontraron fotos"));
    m_translations["Spanish"].insert(QStringLiteral("no_videos_found"), QStringLiteral("No se encontraron videos"));
    m_translations["Spanish"].insert(QStringLiteral("no_documents_found"), QStringLiteral("No se encontraron documentos"));
    m_translations["Spanish"].insert(QStringLiteral("no_links_found"), QStringLiteral("No se encontraron enlaces"));
    m_translations["Spanish"].insert(QStringLiteral("no_locations_found"), QStringLiteral("No se encontraron ubicaciones"));

    // Portuguese
    m_translations["Portuguese"] = {
        {"contact_info", "Dados contato"}, {"msg_count", "Mensagens"}, {"messages", "mensagens"}, {"import_date", "Data imp."},
        {"no_chats", "Sem conversas"}, {"light_theme", "Tema claro"}, {"dark_theme", "Tema escuro"},
        {"new_chat_tooltip", "Nova conversa"}, {"chat_search_placeholder", "Pesquisar"}, {"importing", "Importando..."},
        {"bulk_select_tooltip", "Seleção múltipla"}, {"bulk_delete_tooltip", "Excluir múltiplos"}, {"cancel_selection_tooltip", "Cancelar"},
        {"import_new", "Nova conversa"}, {"zip_description", "Selecione o arquivo ZIP que você exportou do WhatsApp."},
        {"select_zip", "Selecionar ZIP"}, {"change_zip", "Mudar arquivo"}, {"continue", "Continuar"},
        {"owner_question", "Qual é o seu nome?\n(O nome que aparece na sua conta WhatsApp)"}, {"owner_placeholder", "Ex: Maria"},
        {"import_btn", "Importar"}, {"back", "Voltar"}, {"loading_messages", "Carregando..."},
        {"select_zip_title", "Selecionar ZIP do WhatsApp"}, {"first_message", "Primeira mensagem"}, {"delete_chat", "Apagar chat"}, {"search", "Pesquisar..."}, {"search_tooltip", "Pesquisar mensagens (Ctrl+F)"},
        {"empty_chat_hint", "Selecione uma conversa"}, {"delete_confirm_title", "Apagar"},
        {"delete_confirm_text", "Apagar conversa?"}, {"no_results", "Sem resultados"},
        {"yes", "Sim"}, {"no", "Não"}, {"cancel", "Cancelar"}, {"language", "Idioma"}, {"select_language", "Idioma"}, {"profile_photo", "Foto"},
        {"name_label", "Nome"}, {"participants_label", "Participantes do grupo"}, {"contact_name_placeholder", "Nome do contato"}, {"image_files_filter", "Arquivos de imagem (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — %2 mensagens importadas"}, {"conversation", "Conversa"},
        {"default_owner_name", "Nome padrão do proprietário"}, {"owner_name_placeholder", "Seu nome"}, {"not_set", "Não definido"}, {"default_label", "Padrão"},
        {"profile_library", "Biblioteca de Perfis"}, {"add_profile", "Adicionar Perfil"}, {"profile_name_label", "Nome:"}, {"add_btn", "Adicionar"},
        {"optional", "(Opcional)"}, {"image_selected", "✓ Selecionado"}, {"no_profiles_library", "Ainda sem perfis. Clique + para adicionar."},
        {"profile_owner_conflict", "Não é possível adicionar um perfil com o mesmo nome do proprietário"}, {"profile_exists", "Já existe um perfil com este nome"},
        {"message_count_text", "mensagens"},
        {"january", "Jan"}, {"february", "Fev"}, {"march", "Mar"}, {"april", "Abr"}, {"may", "Mai"}, {"june", "Jun"},
        {"july", "Jul"}, {"august", "Ago"}, {"september", "Set"}, {"october", "Out"}, {"november", "Nov"}, {"december", "Dez"},
        {"calendar_tooltip", "Ir para data"},
        {"last_message", "Última mensagem"},
        {"settings", "Configurações"},
        {"auto_play_next_voice", "Reproduzir automaticamente mensagens de voz sequenciais"},
        {"open_system", "Abrir no sistema"}, {"image_not_found", "Imagem não encontrada"}, {"video", "Vídeo"}, {"deleted_message", "Esta mensagem foi apagada"}, {"you_deleted_message", "Você apagou esta mensagem"}, {"edited", "Editado"}, {"app_version", "versão"}, {"app_copyright", "Direitos autorais de %1"},
        {"lock_chat", "Bloquear conversa"}, {"unlock_chat", "Desbloquear esta conversa"}, {"locked_chats", "Conversas bloqueadas"}, {"locked_chats_access", "Acessar conversas bloqueadas"},
        {"lock_chat_title", "Bloquear conversa"}, {"lock_chat_message", "Esta conversa será bloqueada"}, {"lock_chat_set_password", "Defina senha para bloquear conversas"},
        {"locked_chats_password_title", "Conversas bloqueadas"}, {"locked_chats_enter_password", "Digite a senha para acessar conversas bloqueadas"},
        {"password_6_digits", "A senha deve ter 6 dígitos"}, {"password_incorrect", "Senha incorreta"}, {"no_master_password", "Nenhuma senha definida"},
        {"locked_chats_password", "Senha de conversas bloqueadas"}, {"no_password", "Você não tem senha"}, {"change_password", "Alterar senha"},
        {"old_password", "Senha antiga"}, {"new_password", "Nova senha"}, {"confirm_password", "Confirmar nova senha"}, {"change", "Alterar"},
        {"old_password_incorrect", "A senha antiga está incorreta"}, {"passwords_dont_match", "As novas senhas não coincidem"},
        {"no_locked_chats", "Nenhuma conversa bloqueada"}, {"locked_chats_hint", "Selecione 'Bloquear conversa' no menu de 3 pontos para bloquear uma conversa"}, {"enter", "Entrar"}
    };
    m_translations["Portuguese"].insert(QStringLiteral("media_image"), QStringLiteral("Foto"));
    m_translations["Portuguese"].insert(QStringLiteral("media_video"), QStringLiteral("Vídeo"));
    m_translations["Portuguese"].insert(QStringLiteral("media_voice"), QStringLiteral("Mensagem de voz"));
    m_translations["Portuguese"].insert(QStringLiteral("media_audio"), QStringLiteral("Áudio"));
    m_translations["Portuguese"].insert(QStringLiteral("media_sticker"), QStringLiteral("Sticker"));
    m_translations["Portuguese"].insert(QStringLiteral("media_document"), QStringLiteral("Documento"));
    m_translations["Portuguese"].insert(QStringLiteral("media_unavailable"), QStringLiteral("Mídia indisponível"));
    m_translations["Portuguese"].insert(QStringLiteral("tap_to_open"), QStringLiteral("Toque para abrir"));
    m_translations["Portuguese"].insert(QStringLiteral("location"), QStringLiteral("Localização"));
    m_translations["Portuguese"].insert(QStringLiteral("contact"), QStringLiteral("Contato"));
    m_translations["Portuguese"].insert(QStringLiteral("favorites"), QStringLiteral("Favoritos"));
    m_translations["Portuguese"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("Adicionar aos favoritos"));
    m_translations["Portuguese"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("Remover dos favoritos"));
    m_translations["Portuguese"].insert(QStringLiteral("no_favorites"), QStringLiteral("Nenhum favorito"));
    m_translations["Portuguese"].insert(QStringLiteral("favorites_hint"), QStringLiteral("Clique com o botão direito para adicionar aos favoritos"));
    m_translations["Portuguese"].insert(QStringLiteral("media_browser"), QStringLiteral("Mídia"));
    m_translations["Portuguese"].insert(QStringLiteral("media_browser_title"), QStringLiteral("Mídia"));
    m_translations["Portuguese"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("Fotos, vídeos e arquivos"));
    m_translations["Portuguese"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("Fotos"));
    m_translations["Portuguese"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("Vídeos"));
    m_translations["Portuguese"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("Documentos"));
    m_translations["Portuguese"].insert(QStringLiteral("media_browser_links"), QStringLiteral("Links"));
    m_translations["Portuguese"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("Localizações"));
    m_translations["Portuguese"].insert(QStringLiteral("no_photos_found"), QStringLiteral("Nenhuma foto encontrada"));
    m_translations["Portuguese"].insert(QStringLiteral("no_videos_found"), QStringLiteral("Nenhum vídeo encontrado"));
    m_translations["Portuguese"].insert(QStringLiteral("no_documents_found"), QStringLiteral("Nenhum documento encontrado"));
    m_translations["Portuguese"].insert(QStringLiteral("no_links_found"), QStringLiteral("Nenhum link encontrado"));
    m_translations["Portuguese"].insert(QStringLiteral("no_locations_found"), QStringLiteral("Nenhuma localização encontrada"));

    // Italian
    m_translations["Italian"] = {
        {"contact_info", "Info contatto"}, {"msg_count", "Messaggi"}, {"messages", "messaggi"}, {"import_date", "Data imp."},
        {"no_chats", "Nessuna chat"}, {"light_theme", "Tema chiaro"}, {"dark_theme", "Tema scuro"},
        {"new_chat_tooltip", "Nuova chat"}, {"chat_search_placeholder", "Cerca"}, {"importing", "Importazione..."},
        {"bulk_select_tooltip", "Selezione multipla"}, {"bulk_delete_tooltip", "Eliminazione multipla"}, {"cancel_selection_tooltip", "Annulla"},
        {"import_new", "Nuova chat"}, {"zip_description", "Seleziona il file ZIP che hai esportato da WhatsApp."},
        {"select_zip", "Seleziona ZIP"}, {"change_zip", "Cambia file"}, {"continue", "Continua"},
        {"owner_question", "Come ti chiami?\n(Il nome che appare nel tuo account WhatsApp)"}, {"owner_placeholder", "Es: Mario"},
        {"import_btn", "Importa"}, {"back", "Indietro"}, {"loading_messages", "Caricamento..."},
        {"select_zip_title", "Seleziona ZIP WhatsApp"}, {"first_message", "Primo messaggio"}, {"delete_chat", "Elimina chat"}, {"search", "Cerca..."}, {"search_tooltip", "Cerca nei messaggi (Ctrl+F)"},
        {"empty_chat_hint", "Seleziona una chat"}, {"delete_confirm_title", "Elimina"},
        {"delete_confirm_text", "Eliminare chat?"}, {"no_results", "Nessun risultato"},
        {"yes", "Sì"}, {"no", "No"}, {"cancel", "Annulla"}, {"language", "Lingua"}, {"select_language", "Lingua"}, {"profile_photo", "Foto"},
        {"name_label", "Nome"}, {"participants_label", "Partecipanti del gruppo"}, {"contact_name_placeholder", "Nome contatto"}, {"image_files_filter", "File immagine (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — %2 messaggi importati"}, {"conversation", "Conversazione"},
        {"default_owner_name", "Nome predefinito del proprietario"}, {"owner_name_placeholder", "Il tuo nome"}, {"not_set", "Non impostato"}, {"default_label", "Predefinito"},
        {"profile_library", "Biblioteca Profili"}, {"add_profile", "Aggiungi Profilo"}, {"profile_name_label", "Nome:"}, {"add_btn", "Aggiungi"},
        {"optional", "(Opzionale)"}, {"image_selected", "✓ Selezionato"}, {"no_profiles_library", "Ancora nessun profilo. Clicca + per aggiungere."},
        {"profile_owner_conflict", "Impossibile aggiungere un profilo con lo stesso nome del proprietario"}, {"profile_exists", "Esiste già un profilo con questo nome"},
        {"message_count_text", "messaggi"},
        {"january", "Gen"}, {"february", "Feb"}, {"march", "Mar"}, {"april", "Apr"}, {"may", "Mag"}, {"june", "Giu"},
        {"july", "Lug"}, {"august", "Ago"}, {"september", "Set"}, {"october", "Ott"}, {"november", "Nov"}, {"december", "Dic"},
        {"calendar_tooltip", "Vai alla data"},
        {"last_message", "Ultimo messaggio"},
        {"settings", "Impostazioni"},
        {"auto_play_next_voice", "Riproduzione automatica messaggi vocali sequenziali"},
        {"open_system", "Apri nel sistema"}, {"image_not_found", "Immagine non trovata"}, {"video", "Video"}, {"deleted_message", "Questo messaggio è stato eliminato"}, {"you_deleted_message", "Hai eliminato questo messaggio"}, {"edited", "Modificato"}, {"app_version", "versione"}, {"app_copyright", "Copyright di %1"},
        {"lock_chat", "Blocca chat"}, {"unlock_chat", "Sblocca questa chat"}, {"locked_chats", "Chat bloccate"}, {"locked_chats_access", "Accedi alle chat bloccate"},
        {"lock_chat_title", "Blocca chat"}, {"lock_chat_message", "Questa chat sarà bloccata"}, {"lock_chat_set_password", "Imposta password per bloccare le chat"},
        {"locked_chats_password_title", "Chat bloccate"}, {"locked_chats_enter_password", "Inserisci password per accedere alle chat bloccate"},
        {"password_6_digits", "La password deve essere di 6 cifre"}, {"password_incorrect", "Password errata"}, {"no_master_password", "Nessuna password impostata"},
        {"locked_chats_password", "Password chat bloccate"}, {"no_password", "Non hai una password"}, {"change_password", "Cambia password"},
        {"old_password", "Vecchia password"}, {"new_password", "Nuova password"}, {"confirm_password", "Conferma nuova password"}, {"change", "Cambia"},
        {"old_password_incorrect", "La vecchia password è errata"}, {"passwords_dont_match", "Le nuove password non corrispondono"},
        {"no_locked_chats", "Nessuna chat bloccata"}, {"locked_chats_hint", "Seleziona 'Blocca chat' dal menu a 3 punti per bloccare una chat"}, {"enter", "Entra"}
    };
    m_translations["Italian"].insert(QStringLiteral("media_image"), QStringLiteral("Foto"));
    m_translations["Italian"].insert(QStringLiteral("media_video"), QStringLiteral("Video"));
    m_translations["Italian"].insert(QStringLiteral("media_voice"), QStringLiteral("Messaggio vocale"));
    m_translations["Italian"].insert(QStringLiteral("media_audio"), QStringLiteral("Audio"));
    m_translations["Italian"].insert(QStringLiteral("media_sticker"), QStringLiteral("Sticker"));
    m_translations["Italian"].insert(QStringLiteral("media_document"), QStringLiteral("Documento"));
    m_translations["Italian"].insert(QStringLiteral("media_unavailable"), QStringLiteral("Media non disponibile"));
    m_translations["Italian"].insert(QStringLiteral("tap_to_open"), QStringLiteral("Tocca per aprire"));
    m_translations["Italian"].insert(QStringLiteral("location"), QStringLiteral("Posizione"));
    m_translations["Italian"].insert(QStringLiteral("contact"), QStringLiteral("Contatto"));
    m_translations["Italian"].insert(QStringLiteral("favorites"), QStringLiteral("Preferiti"));
    m_translations["Italian"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("Aggiungi ai preferiti"));
    m_translations["Italian"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("Rimuovi dai preferiti"));
    m_translations["Italian"].insert(QStringLiteral("no_favorites"), QStringLiteral("Nessun preferito"));
    m_translations["Italian"].insert(QStringLiteral("favorites_hint"), QStringLiteral("Fare clic destro su un messaggio per aggiungere ai preferiti"));
    m_translations["Italian"].insert(QStringLiteral("media_browser"), QStringLiteral("Media"));
    m_translations["Italian"].insert(QStringLiteral("media_browser_title"), QStringLiteral("Media"));
    m_translations["Italian"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("Foto, video e file"));
    m_translations["Italian"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("Foto"));
    m_translations["Italian"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("Video"));
    m_translations["Italian"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("Documenti"));
    m_translations["Italian"].insert(QStringLiteral("media_browser_links"), QStringLiteral("Link"));
    m_translations["Italian"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("Posizioni"));
    m_translations["Italian"].insert(QStringLiteral("no_photos_found"), QStringLiteral("Nessuna foto trovata"));
    m_translations["Italian"].insert(QStringLiteral("no_videos_found"), QStringLiteral("Nessun video trovato"));
    m_translations["Italian"].insert(QStringLiteral("no_documents_found"), QStringLiteral("Nessun documento trovato"));
    m_translations["Italian"].insert(QStringLiteral("no_links_found"), QStringLiteral("Nessun link trovato"));
    m_translations["Italian"].insert(QStringLiteral("no_locations_found"), QStringLiteral("Nessuna posizione trovata"));

    // French
    m_translations["French"] = {
        {"contact_info", "Infos contact"}, {"msg_count", "Messages"}, {"messages", "messages"}, {"import_date", "Date imp."},
        {"no_chats", "Aucun chat"}, {"light_theme", "Thème clair"}, {"dark_theme", "Thème sombre"},
        {"new_chat_tooltip", "Nouveau chat"}, {"chat_search_placeholder", "Rechercher"}, {"importing", "Importation..."},
        {"bulk_select_tooltip", "Sélection multiple"}, {"bulk_delete_tooltip", "Suppression multiple"}, {"cancel_selection_tooltip", "Annuler"},
        {"import_new", "Nouveau chat"}, {"zip_description", "Sélectionnez le fichier ZIP que vous avez exporté de WhatsApp."},
        {"select_zip", "Choisir ZIP"}, {"change_zip", "Changer"}, {"continue", "Continuer"},
        {"owner_question", "Quel est votre nom?\n(Le nom qui apparaît dans votre compte WhatsApp)"}, {"owner_placeholder", "Ex: Jean"},
        {"import_btn", "Importer"}, {"back", "Retour"}, {"loading_messages", "Chargement..."},
        {"select_zip_title", "Sélectionner ZIP WhatsApp"}, {"first_message", "Premier message"}, {"delete_chat", "Supprimer"}, {"search", "Chercher..."}, {"search_tooltip", "Rechercher dans les messages (Ctrl+F)"},
        {"empty_chat_hint", "Choisir un chat"}, {"delete_confirm_title", "Supprimer"},
        {"delete_confirm_text", "Supprimer le chat?"}, {"no_results", "Aucun résultat"},
        {"yes", "Oui"}, {"no", "Non"}, {"cancel", "Annuler"}, {"language", "Langue"}, {"select_language", "Langue"}, {"profile_photo", "Photo"},
        {"name_label", "Nom"}, {"participants_label", "Participants du groupe"}, {"contact_name_placeholder", "Nom du contact"}, {"image_files_filter", "Fichiers image (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — %2 messages importés"}, {"conversation", "Conversation"},
        {"default_owner_name", "Nom par défaut du propriétaire"}, {"owner_name_placeholder", "Votre nom"}, {"not_set", "Non défini"}, {"default_label", "Par défaut"},
        {"profile_library", "Bibliothèque de Profils"}, {"add_profile", "Ajouter un Profil"}, {"profile_name_label", "Nom:"}, {"add_btn", "Ajouter"},
        {"optional", "(Facultatif)"}, {"image_selected", "✓ Sélectionné"}, {"no_profiles_library", "Aucun profil pour le moment. Cliquez sur + pour ajouter."},
        {"profile_owner_conflict", "Impossible d'ajouter un profil avec le même nom que le propriétaire"}, {"profile_exists", "Un profil avec ce nom existe déjà"},
        {"message_count_text", "messages"},
        {"january", "Jan"}, {"february", "Fév"}, {"march", "Mar"}, {"april", "Avr"}, {"may", "Mai"}, {"june", "Juin"},
        {"july", "Juil"}, {"august", "Aoû"}, {"september", "Sep"}, {"october", "Oct"}, {"november", "Nov"}, {"december", "Déc"},
        {"calendar_tooltip", "Aller à la date"},
        {"last_message", "Dernier message"},
        {"settings", "Paramètres"},
        {"auto_play_next_voice", "Lecture automatique des messages vocaux séquentiels"},
        {"open_system", "Ouvrir dans le système"}, {"image_not_found", "Image introuvable"}, {"video", "Vidéo"}, {"deleted_message", "Ce message a été supprimé"}, {"you_deleted_message", "Vous avez supprimé ce message"}, {"edited", "Modifié"}, {"app_version", "version"}, {"app_copyright", "Droits d'auteur par %1"},
        {"lock_chat", "Verrouiller la discussion"}, {"unlock_chat", "Déverrouiller cette discussion"}, {"locked_chats", "Discussions verrouillées"}, {"locked_chats_access", "Accéder aux discussions verrouillées"},
        {"lock_chat_title", "Verrouiller la discussion"}, {"lock_chat_message", "Cette discussion sera verrouillée"}, {"lock_chat_set_password", "Définir un mot de passe pour verrouiller les discussions"},
        {"locked_chats_password_title", "Discussions verrouillées"}, {"locked_chats_enter_password", "Entrez le mot de passe pour accéder aux discussions verrouillées"},
        {"password_6_digits", "Le mot de passe doit comporter 6 chiffres"}, {"password_incorrect", "Mot de passe incorrect"}, {"no_master_password", "Aucun mot de passe défini"},
        {"locked_chats_password", "Mot de passe des discussions verrouillées"}, {"no_password", "Vous n'avez pas de mot de passe"}, {"change_password", "Changer le mot de passe"},
        {"old_password", "Ancien mot de passe"}, {"new_password", "Nouveau mot de passe"}, {"confirm_password", "Confirmer le nouveau mot de passe"}, {"change", "Changer"},
        {"old_password_incorrect", "L'ancien mot de passe est incorrect"}, {"passwords_dont_match", "Les nouveaux mots de passe ne correspondent pas"},
        {"no_locked_chats", "Aucune discussion verrouillée"}, {"locked_chats_hint", "Sélectionnez 'Verrouiller la discussion' dans le menu à 3 points pour verrouiller une discussion"}, {"enter", "Entrer"}
    };
    m_translations["French"].insert(QStringLiteral("media_image"), QStringLiteral("Photo"));
    m_translations["French"].insert(QStringLiteral("media_video"), QStringLiteral("Vidéo"));
    m_translations["French"].insert(QStringLiteral("media_voice"), QStringLiteral("Message vocal"));
    m_translations["French"].insert(QStringLiteral("media_audio"), QStringLiteral("Audio"));
    m_translations["French"].insert(QStringLiteral("media_sticker"), QStringLiteral("Autocollant"));
    m_translations["French"].insert(QStringLiteral("media_document"), QStringLiteral("Document"));
    m_translations["French"].insert(QStringLiteral("media_unavailable"), QStringLiteral("Média indisponible"));
    m_translations["French"].insert(QStringLiteral("tap_to_open"), QStringLiteral("Appuyer pour ouvrir"));
    m_translations["French"].insert(QStringLiteral("location"), QStringLiteral("Localisation"));
    m_translations["French"].insert(QStringLiteral("contact"), QStringLiteral("Contact"));
    m_translations["French"].insert(QStringLiteral("favorites"), QStringLiteral("Favoris"));
    m_translations["French"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("Ajouter aux favoris"));
    m_translations["French"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("Retirer des favoris"));
    m_translations["French"].insert(QStringLiteral("no_favorites"), QStringLiteral("Aucun favori"));
    m_translations["French"].insert(QStringLiteral("favorites_hint"), QStringLiteral("Clic droit sur un message pour ajouter aux favoris"));
    m_translations["French"].insert(QStringLiteral("media_browser"), QStringLiteral("Médias"));
    m_translations["French"].insert(QStringLiteral("media_browser_title"), QStringLiteral("Médias"));
    m_translations["French"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("Photos, vidéos et fichiers"));
    m_translations["French"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("Photos"));
    m_translations["French"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("Vidéos"));
    m_translations["French"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("Documents"));
    m_translations["French"].insert(QStringLiteral("media_browser_links"), QStringLiteral("Liens"));
    m_translations["French"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("Localisations"));
    m_translations["French"].insert(QStringLiteral("no_photos_found"), QStringLiteral("Aucune photo trouvée"));
    m_translations["French"].insert(QStringLiteral("no_videos_found"), QStringLiteral("Aucune vidéo trouvée"));
    m_translations["French"].insert(QStringLiteral("no_documents_found"), QStringLiteral("Aucun document trouvé"));
    m_translations["French"].insert(QStringLiteral("no_links_found"), QStringLiteral("Aucun lien trouvé"));
    m_translations["French"].insert(QStringLiteral("no_locations_found"), QStringLiteral("Aucune localisation trouvée"));

    // German
    m_translations["German"] = {
        {"contact_info", "Kontaktinfo"}, {"msg_count", "Nachrichten"}, {"messages", "Nachrichten"}, {"import_date", "Datum"},
        {"no_chats", "Keine Chats"}, {"light_theme", "Hell"}, {"dark_theme", "Dunkel"},
        {"new_chat_tooltip", "Neuer Chat"}, {"chat_search_placeholder", "Suchen"}, {"importing", "Import..."},
        {"bulk_select_tooltip", "Mehrfachauswahl"}, {"bulk_delete_tooltip", "Mehrfach löschen"}, {"cancel_selection_tooltip", "Abbrechen"},
        {"import_new", "Neuer Chat"}, {"zip_description", "Wählen Sie die ZIP-Datei aus, die Sie aus WhatsApp exportiert haben."},
        {"select_zip", "ZIP wählen"}, {"change_zip", "Ändern"}, {"continue", "Weiter"},
        {"owner_question", "Wie heißen Sie?\n(Der Name, der in Ihrem WhatsApp-Konto angezeigt wird)"}, {"owner_placeholder", "Z.B. Max"},
        {"import_btn", "Importieren"}, {"back", "Zurück"}, {"loading_messages", "Laden..."},
        {"select_zip_title", "WhatsApp-ZIP auswählen"}, {"first_message", "Erste Nachricht"}, {"delete_chat", "Löschen"}, {"search", "Suchen..."}, {"search_tooltip", "In Nachrichten suchen (Ctrl+F)"},
        {"empty_chat_hint", "Chat wählen"}, {"delete_confirm_title", "Löschen"},
        {"delete_confirm_text", "Chat löschen?"}, {"no_results", "Keine Ergebnisse"},
        {"yes", "Ja"}, {"no", "Nein"}, {"cancel", "Abbrechen"}, {"language", "Sprache"}, {"select_language", "Sprache"}, {"profile_photo", "Foto"},
        {"name_label", "Name"}, {"participants_label", "Gruppenteilnehmer"}, {"contact_name_placeholder", "Kontaktname"}, {"image_files_filter", "Bilddateien (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — %2 Nachrichten importiert"}, {"conversation", "Unterhaltung"},
        {"default_owner_name", "Standard-Besitzername"}, {"owner_name_placeholder", "Ihr Name"}, {"not_set", "Nicht festgelegt"}, {"default_label", "Standard"},
        {"profile_library", "Profilbibliothek"}, {"add_profile", "Profil hinzufügen"}, {"profile_name_label", "Name:"}, {"add_btn", "Hinzufügen"},
        {"optional", "(Optional)"}, {"image_selected", "✓ Ausgewählt"}, {"no_profiles_library", "Noch keine Profile. Klicken Sie auf +, um hinzuzufügen."},
        {"profile_owner_conflict", "Es kann kein Profil mit demselben Namen wie der Besitzer hinzugefügt werden"}, {"profile_exists", "Ein Profil mit diesem Namen existiert bereits"},
        {"message_count_text", "Nachrichten"},
        {"january", "Jan"}, {"february", "Feb"}, {"march", "Mär"}, {"april", "Apr"}, {"may", "Mai"}, {"june", "Jun"},
        {"july", "Jul"}, {"august", "Aug"}, {"september", "Sep"}, {"october", "Okt"}, {"november", "Nov"}, {"december", "Dez"},
        {"calendar_tooltip", "Zu Datum springen"},
        {"last_message", "Letzte Nachricht"},
        {"settings", "Einstellungen"},
        {"auto_play_next_voice", "Sequenzielle Sprachnachrichten automatisch abspielen"},
        {"open_system", "Im System öffnen"}, {"image_not_found", "Bild nicht gefunden"}, {"video", "Video"}, {"deleted_message", "Diese Nachricht wurde gelöscht"}, {"you_deleted_message", "Du hast diese Nachricht gelöscht"}, {"edited", "Bearbeitet"}, {"app_version", "Version"}, {"app_copyright", "Urheberrecht von %1"},
        {"lock_chat", "Chat sperren"}, {"unlock_chat", "Diesen Chat entsperren"}, {"locked_chats", "Gesperrte Chats"}, {"locked_chats_access", "Zugriff auf gesperrte Chats"},
        {"lock_chat_title", "Chat sperren"}, {"lock_chat_message", "Dieser Chat wird gesperrt"}, {"lock_chat_set_password", "Passwort zum Sperren von Chats festlegen"},
        {"locked_chats_password_title", "Gesperrte Chats"}, {"locked_chats_enter_password", "Passwort eingeben, um auf gesperrte Chats zuzugreifen"},
        {"password_6_digits", "Passwort muss 6 Ziffern lang sein"}, {"password_incorrect", "Falsches Passwort"}, {"no_master_password", "Kein Passwort festgelegt"},
        {"locked_chats_password", "Passwort für gesperrte Chats"}, {"no_password", "Sie haben kein Passwort"}, {"change_password", "Passwort ändern"},
        {"old_password", "Altes Passwort"}, {"new_password", "Neues Passwort"}, {"confirm_password", "Neues Passwort bestätigen"}, {"change", "Ändern"},
        {"old_password_incorrect", "Altes Passwort ist falsch"}, {"passwords_dont_match", "Neue Passwörter stimmen nicht überein"},
        {"no_locked_chats", "Keine gesperrten Chats"}, {"locked_chats_hint", "Wählen Sie 'Chat sperren' aus dem 3-Punkte-Menü, um einen Chat zu sperren"}, {"enter", "Eingeben"}
    };
    m_translations["German"].insert(QStringLiteral("media_image"), QStringLiteral("Foto"));
    m_translations["German"].insert(QStringLiteral("media_video"), QStringLiteral("Video"));
    m_translations["German"].insert(QStringLiteral("media_voice"), QStringLiteral("Sprachnachricht"));
    m_translations["German"].insert(QStringLiteral("media_audio"), QStringLiteral("Audio"));
    m_translations["German"].insert(QStringLiteral("media_sticker"), QStringLiteral("Sticker"));
    m_translations["German"].insert(QStringLiteral("media_document"), QStringLiteral("Dokument"));
    m_translations["German"].insert(QStringLiteral("media_unavailable"), QStringLiteral("Medien nicht verfügbar"));
    m_translations["German"].insert(QStringLiteral("tap_to_open"), QStringLiteral("Zum Öffnen tippen"));
    m_translations["German"].insert(QStringLiteral("location"), QStringLiteral("Standort"));
    m_translations["German"].insert(QStringLiteral("contact"), QStringLiteral("Kontakt"));
    m_translations["German"].insert(QStringLiteral("favorites"), QStringLiteral("Favoriten"));
    m_translations["German"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("Zu Favoriten hinzufügen"));
    m_translations["German"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("Aus Favoriten entfernen"));
    m_translations["German"].insert(QStringLiteral("no_favorites"), QStringLiteral("Keine Favoriten"));
    m_translations["German"].insert(QStringLiteral("favorites_hint"), QStringLiteral("Rechtsklick auf eine Nachricht zum Hinzufügen"));
    m_translations["German"].insert(QStringLiteral("media_browser"), QStringLiteral("Medien"));
    m_translations["German"].insert(QStringLiteral("media_browser_title"), QStringLiteral("Medien"));
    m_translations["German"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("Fotos, Videos und Dateien"));
    m_translations["German"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("Fotos"));
    m_translations["German"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("Videos"));
    m_translations["German"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("Dokumente"));
    m_translations["German"].insert(QStringLiteral("media_browser_links"), QStringLiteral("Links"));
    m_translations["German"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("Standorte"));
    m_translations["German"].insert(QStringLiteral("no_photos_found"), QStringLiteral("Keine Fotos gefunden"));
    m_translations["German"].insert(QStringLiteral("no_videos_found"), QStringLiteral("Keine Videos gefunden"));
    m_translations["German"].insert(QStringLiteral("no_documents_found"), QStringLiteral("Keine Dokumente gefunden"));
    m_translations["German"].insert(QStringLiteral("no_links_found"), QStringLiteral("Keine Links gefunden"));
    m_translations["German"].insert(QStringLiteral("no_locations_found"), QStringLiteral("Keine Standorte gefunden"));

    // Chinese
    m_translations["Chinese"].insert(QStringLiteral("contact_info"), QStringLiteral("信息"));
    m_translations["Chinese"].insert(QStringLiteral("msg_count"), QStringLiteral("消息"));
    m_translations["Chinese"].insert(QStringLiteral("messages"), QStringLiteral("消息"));
    m_translations["Chinese"].insert(QStringLiteral("import_date"), QStringLiteral("日期"));
    m_translations["Chinese"].insert(QStringLiteral("no_chats"), QStringLiteral("没有聊天"));
    m_translations["Chinese"].insert(QStringLiteral("light_theme"), QStringLiteral("浅色"));
    m_translations["Chinese"].insert(QStringLiteral("dark_theme"), QStringLiteral("深色"));
    m_translations["Chinese"].insert(QStringLiteral("new_chat_tooltip"), QStringLiteral("新聊天"));
    m_translations["Chinese"].insert(QStringLiteral("chat_search_placeholder"), QStringLiteral("搜索"));
    m_translations["Chinese"].insert(QStringLiteral("importing"), QStringLiteral("导入中..."));
    m_translations["Chinese"].insert(QStringLiteral("bulk_select_tooltip"), QStringLiteral("批量选择"));
    m_translations["Chinese"].insert(QStringLiteral("bulk_delete_tooltip"), QStringLiteral("批量删除"));
    m_translations["Chinese"].insert(QStringLiteral("cancel_selection_tooltip"), QStringLiteral("取消"));
    m_translations["Chinese"].insert(QStringLiteral("import_new"), QStringLiteral("新聊天"));
    m_translations["Chinese"].insert(QStringLiteral("zip_description"), QStringLiteral("选择您从 WhatsApp 导出的 ZIP 文件。"));
    m_translations["Chinese"].insert(QStringLiteral("select_zip"), QStringLiteral("选择 ZIP"));
    m_translations["Chinese"].insert(QStringLiteral("change_zip"), QStringLiteral("更改"));
    m_translations["Chinese"].insert(QStringLiteral("continue"), QStringLiteral("继续"));
    m_translations["Chinese"].insert(QStringLiteral("owner_question"), QStringLiteral("您叫什么名字？\n（在您的 WhatsApp 账户中显示的名字）"));
    m_translations["Chinese"].insert(QStringLiteral("owner_placeholder"), QStringLiteral("例如：张三"));
    m_translations["Chinese"].insert(QStringLiteral("import_btn"), QStringLiteral("导入"));
    m_translations["Chinese"].insert(QStringLiteral("back"), QStringLiteral("返回"));
    m_translations["Chinese"].insert(QStringLiteral("loading_messages"), QStringLiteral("正在加载..."));
    m_translations["Chinese"].insert(QStringLiteral("select_zip_title"), QStringLiteral("选择 WhatsApp ZIP 文件"));
    m_translations["Chinese"].insert(QStringLiteral("first_message"), QStringLiteral("第一条消息"));
    m_translations["Chinese"].insert(QStringLiteral("delete_chat"), QStringLiteral("删除"));
    m_translations["Chinese"].insert(QStringLiteral("search"), QStringLiteral("搜索..."));
    m_translations["Chinese"].insert(QStringLiteral("search_tooltip"), QStringLiteral("搜索消息 (Ctrl+F)"));
    m_translations["Chinese"].insert(QStringLiteral("empty_chat_hint"), QStringLiteral("选择聊天"));
    m_translations["Chinese"].insert(QStringLiteral("delete_confirm_title"), QStringLiteral("删除"));
    m_translations["Chinese"].insert(QStringLiteral("delete_confirm_text"), QStringLiteral("删除聊天？"));
    m_translations["Chinese"].insert(QStringLiteral("no_results"), QStringLiteral("没有结果"));
    m_translations["Chinese"].insert(QStringLiteral("yes"), QStringLiteral("是"));
    m_translations["Chinese"].insert(QStringLiteral("no"), QStringLiteral("否"));
    m_translations["Chinese"].insert(QStringLiteral("cancel"), QStringLiteral("取消"));
    m_translations["Chinese"].insert(QStringLiteral("language"), QStringLiteral("语言"));
    m_translations["Chinese"].insert(QStringLiteral("select_language"), QStringLiteral("语言"));
    m_translations["Chinese"].insert(QStringLiteral("profile_photo"), QStringLiteral("照片"));
    m_translations["Chinese"].insert(QStringLiteral("name_label"), QStringLiteral("名称"));
    m_translations["Chinese"].insert(QStringLiteral("participants_label"), QStringLiteral("群成员"));
    m_translations["Chinese"].insert(QStringLiteral("contact_name_placeholder"), QStringLiteral("联系人名称"));
    m_translations["Chinese"].insert(QStringLiteral("image_files_filter"), QStringLiteral("图片文件 (*.jpg *.jpeg *.png *.webp)"));
    m_translations["Chinese"].insert(QStringLiteral("import_success"), QStringLiteral("%1 — 已导入 %2 条消息"));
    m_translations["Chinese"].insert(QStringLiteral("conversation"), QStringLiteral("对话"));
    m_translations["Chinese"].insert(QStringLiteral("default_owner_name"), QStringLiteral("默认所有者名称"));
    m_translations["Chinese"].insert(QStringLiteral("owner_name_placeholder"), QStringLiteral("您的名字"));
    m_translations["Chinese"].insert(QStringLiteral("not_set"), QStringLiteral("未设置"));
    m_translations["Chinese"].insert(QStringLiteral("default_label"), QStringLiteral("默认"));
    m_translations["Chinese"].insert(QStringLiteral("profile_library"), QStringLiteral("个人资料库"));
    m_translations["Chinese"].insert(QStringLiteral("add_profile"), QStringLiteral("添加个人资料"));
    m_translations["Chinese"].insert(QStringLiteral("profile_name_label"), QStringLiteral("名字:"));
    m_translations["Chinese"].insert(QStringLiteral("add_btn"), QStringLiteral("添加"));
    m_translations["Chinese"].insert(QStringLiteral("optional"), QStringLiteral("(可选)"));
    m_translations["Chinese"].insert(QStringLiteral("image_selected"), QStringLiteral("✓ 已选择"));
    m_translations["Chinese"].insert(QStringLiteral("no_profiles_library"), QStringLiteral("还没有个人资料。点击 + 添加。"));
    m_translations["Chinese"].insert(QStringLiteral("profile_owner_conflict"), QStringLiteral("无法添加与所有者同名的个人资料"));
    m_translations["Chinese"].insert(QStringLiteral("profile_exists"), QStringLiteral("此名称的个人资料已存在"));
    m_translations["Chinese"].insert(QStringLiteral("message_count_text"), QStringLiteral("条消息"));
    m_translations["Chinese"].insert(QStringLiteral("january"), QStringLiteral("1月"));
    m_translations["Chinese"].insert(QStringLiteral("february"), QStringLiteral("2月"));
    m_translations["Chinese"].insert(QStringLiteral("march"), QStringLiteral("3月"));
    m_translations["Chinese"].insert(QStringLiteral("april"), QStringLiteral("4月"));
    m_translations["Chinese"].insert(QStringLiteral("may"), QStringLiteral("5月"));
    m_translations["Chinese"].insert(QStringLiteral("june"), QStringLiteral("6月"));
    m_translations["Chinese"].insert(QStringLiteral("july"), QStringLiteral("7月"));
    m_translations["Chinese"].insert(QStringLiteral("august"), QStringLiteral("8月"));
    m_translations["Chinese"].insert(QStringLiteral("september"), QStringLiteral("9月"));
    m_translations["Chinese"].insert(QStringLiteral("october"), QStringLiteral("10月"));
    m_translations["Chinese"].insert(QStringLiteral("november"), QStringLiteral("11月"));
    m_translations["Chinese"].insert(QStringLiteral("december"), QStringLiteral("12月"));
    m_translations["Chinese"].insert(QStringLiteral("calendar_tooltip"), QStringLiteral("跳转到日期"));
    m_translations["Chinese"].insert(QStringLiteral("last_message"), QStringLiteral("最后消息"));
    m_translations["Chinese"].insert(QStringLiteral("settings"), QStringLiteral("设置"));
    m_translations["Chinese"].insert(QStringLiteral("auto_play_next_voice"), QStringLiteral("自动播放连续语音消息"));
    m_translations["Chinese"].insert(QStringLiteral("open_system"), QStringLiteral("在系统中打开"));
    m_translations["Chinese"].insert(QStringLiteral("image_not_found"), QStringLiteral("图像未找到"));
    m_translations["Chinese"].insert(QStringLiteral("video"), QStringLiteral("视频"));
    m_translations["Chinese"].insert(QStringLiteral("deleted_message"), QStringLiteral("此消息已删除"));
    m_translations["Chinese"].insert(QStringLiteral("you_deleted_message"), QStringLiteral("你删除了此消息"));
    m_translations["Chinese"].insert(QStringLiteral("edited"), QStringLiteral("已编辑"));
    m_translations["Chinese"].insert(QStringLiteral("app_version"), QStringLiteral("版本"));
    m_translations["Chinese"].insert(QStringLiteral("app_copyright"), QStringLiteral("版权所有 %1"));
    m_translations["Chinese"].insert(QStringLiteral("lock_chat"), QStringLiteral("锁定聊天"));
    m_translations["Chinese"].insert(QStringLiteral("unlock_chat"), QStringLiteral("解锁此聊天"));
    m_translations["Chinese"].insert(QStringLiteral("locked_chats"), QStringLiteral("已锁定的聊天"));
    m_translations["Chinese"].insert(QStringLiteral("locked_chats_access"), QStringLiteral("访问已锁定的聊天"));
    m_translations["Chinese"].insert(QStringLiteral("lock_chat_title"), QStringLiteral("锁定聊天"));
    m_translations["Chinese"].insert(QStringLiteral("lock_chat_message"), QStringLiteral("此聊天将被锁定"));
    m_translations["Chinese"].insert(QStringLiteral("lock_chat_set_password"), QStringLiteral("设置密码以锁定聊天"));
    m_translations["Chinese"].insert(QStringLiteral("locked_chats_password_title"), QStringLiteral("已锁定的聊天"));
    m_translations["Chinese"].insert(QStringLiteral("locked_chats_enter_password"), QStringLiteral("输入密码以访问已锁定的聊天"));
    m_translations["Chinese"].insert(QStringLiteral("password_6_digits"), QStringLiteral("密码必须为6位数字"));
    m_translations["Chinese"].insert(QStringLiteral("password_incorrect"), QStringLiteral("密码不正确"));
    m_translations["Chinese"].insert(QStringLiteral("no_master_password"), QStringLiteral("未设置密码"));
    m_translations["Chinese"].insert(QStringLiteral("locked_chats_password"), QStringLiteral("已锁定聊天的密码"));
    m_translations["Chinese"].insert(QStringLiteral("no_password"), QStringLiteral("你没有密码"));
    m_translations["Chinese"].insert(QStringLiteral("change_password"), QStringLiteral("更改密码"));
    m_translations["Chinese"].insert(QStringLiteral("old_password"), QStringLiteral("旧密码"));
    m_translations["Chinese"].insert(QStringLiteral("new_password"), QStringLiteral("新密码"));
    m_translations["Chinese"].insert(QStringLiteral("confirm_password"), QStringLiteral("确认新密码"));
    m_translations["Chinese"].insert(QStringLiteral("change"), QStringLiteral("更改"));
    m_translations["Chinese"].insert(QStringLiteral("old_password_incorrect"), QStringLiteral("旧密码不正确"));
    m_translations["Chinese"].insert(QStringLiteral("passwords_dont_match"), QStringLiteral("新密码不匹配"));
    m_translations["Chinese"].insert(QStringLiteral("no_locked_chats"), QStringLiteral("没有已锁定的聊天"));
    m_translations["Chinese"].insert(QStringLiteral("locked_chats_hint"), QStringLiteral("从3点菜单中选择锁定聊天以锁定聊天"));
    m_translations["Chinese"].insert(QStringLiteral("enter"), QStringLiteral("进入"));
    m_translations["Chinese"].insert(QStringLiteral("media_image"), QStringLiteral("照片"));
    m_translations["Chinese"].insert(QStringLiteral("media_video"), QStringLiteral("视频"));
    m_translations["Chinese"].insert(QStringLiteral("media_voice"), QStringLiteral("语音消息"));
    m_translations["Chinese"].insert(QStringLiteral("media_audio"), QStringLiteral("音频"));
    m_translations["Chinese"].insert(QStringLiteral("media_sticker"), QStringLiteral("贴纸"));
    m_translations["Chinese"].insert(QStringLiteral("media_document"), QStringLiteral("文件"));
    m_translations["Chinese"].insert(QStringLiteral("media_unavailable"), QStringLiteral("媒体不可用"));
    m_translations["Chinese"].insert(QStringLiteral("tap_to_open"), QStringLiteral("点击打开"));
    m_translations["Chinese"].insert(QStringLiteral("location"), QStringLiteral("位置"));
    m_translations["Chinese"].insert(QStringLiteral("contact"), QStringLiteral("联系人"));
    m_translations["Chinese"].insert(QStringLiteral("favorites"), QStringLiteral("收藏夹"));
    m_translations["Chinese"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("添加到收藏夹"));
    m_translations["Chinese"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("从收藏夹移除"));
    m_translations["Chinese"].insert(QStringLiteral("no_favorites"), QStringLiteral("无收藏"));
    m_translations["Chinese"].insert(QStringLiteral("favorites_hint"), QStringLiteral("右键单击消息以添加到收藏夹"));
    m_translations["Chinese"].insert(QStringLiteral("media_browser"), QStringLiteral("媒体"));
    m_translations["Chinese"].insert(QStringLiteral("media_browser_title"), QStringLiteral("媒体"));
    m_translations["Chinese"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("照片、视频和文件"));
    m_translations["Chinese"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("照片"));
    m_translations["Chinese"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("视频"));
    m_translations["Chinese"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("文件"));
    m_translations["Chinese"].insert(QStringLiteral("media_browser_links"), QStringLiteral("链接"));
    m_translations["Chinese"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("位置"));
    m_translations["Chinese"].insert(QStringLiteral("no_photos_found"), QStringLiteral("未找到照片"));
    m_translations["Chinese"].insert(QStringLiteral("no_videos_found"), QStringLiteral("未找到视频"));
    m_translations["Chinese"].insert(QStringLiteral("no_documents_found"), QStringLiteral("未找到文件"));
    m_translations["Chinese"].insert(QStringLiteral("no_links_found"), QStringLiteral("未找到链接"));
    m_translations["Chinese"].insert(QStringLiteral("no_locations_found"), QStringLiteral("未找到位置"));

    // Hindi
    m_translations["Hindi"] = {
        {"contact_info", "संपर्क जानकारी"}, {"msg_count", "संदेश संख्या"}, {"messages", "संदेश"}, {"import_date", "इम्पोर्ट तिथि"},
        {"no_chats", "कोई चैट नहीं मिली\n\nनई चैट जोड़ने के लिए\n+ दबाएँ"}, {"light_theme", "लाइट थीम"}, {"dark_theme", "डार्क थीम"},
        {"new_chat_tooltip", "नई चैट जोड़ें"}, {"chat_search_placeholder", "चैट में खोजें"}, {"importing", "इम्पोर्ट हो रहा है..."},
        {"bulk_select_tooltip", "बल्क चयन"}, {"bulk_delete_tooltip", "बल्क हटाएं"}, {"cancel_selection_tooltip", "रद्द करें"},
        {"import_new", "नई चैट जोड़ें"}, {"zip_description", "WhatsApp से एक्सपोर्ट की गई ZIP फ़ाइल चुनें।"},
        {"select_zip", "ZIP चुनें"}, {"change_zip", "फ़ाइल बदलें"}, {"continue", "जारी रखें"},
        {"owner_question", "चैट में आपका नाम क्या है?\n(जो नाम आपके WhatsApp खाते में दिखता है)"}, {"owner_placeholder", "उदा: राहुल शर्मा"},
        {"import_btn", "इम्पोर्ट करें"}, {"back", "वापस"}, {"loading_messages", "संदेश लोड हो रहे हैं, कृपया प्रतीक्षा करें..."},
        {"select_zip_title", "WhatsApp ZIP फ़ाइल चुनें"}, {"first_message", "पहला संदेश"}, {"delete_chat", "चैट हटाएँ"}, {"search", "खोजें..."}, {"search_tooltip", "संदेशों में खोजें (Ctrl+F)"},
        {"empty_chat_hint", "एक चैट चुनें या नई चैट जोड़ें"}, {"delete_confirm_title", "चैट हटाएँ"},
        {"delete_confirm_text", "क्या आप वाकई इस चैट को हटाना चाहते हैं?\nसभी संदेश हट जाएँगे।"}, {"no_results", "कोई परिणाम नहीं मिला"},
        {"yes", "हाँ"}, {"no", "नहीं"}, {"cancel", "रद्द करें"}, {"language", "भाषा"}, {"select_language", "भाषा चुनें"}, {"profile_photo", "प्रोफ़ाइल फ़ोटो"},
        {"name_label", "नाम"}, {"participants_label", "समूह सदस्य"}, {"contact_name_placeholder", "संपर्क नाम"}, {"image_files_filter", "छवि फ़ाइलें (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — %2 संदेश इम्पोर्ट हुए"}, {"conversation", "वार्तालाप"},
        {"default_owner_name", "डिफ़ॉल्ट स्वामी नाम"}, {"owner_name_placeholder", "आपका नाम"}, {"not_set", "सेट नहीं किया गया"}, {"default_label", "डिफ़ॉल्ट"},
        {"profile_library", "प्रोफ़ाइल पुस्तकालय"}, {"add_profile", "प्रोफ़ाइल जोड़ें"}, {"profile_name_label", "नाम:"}, {"add_btn", "जोड़ें"},
        {"optional", "(वैकल्पिक)"}, {"image_selected", "✓ चयनित"}, {"no_profiles_library", "अभी तक कोई प्रोफ़ाइल नहीं। जोड़ने के लिए + क्लिक करें।"},
        {"profile_owner_conflict", "स्वामी के समान नाम वाली प्रोफ़ाइल नहीं जोड़ी जा सकती"}, {"profile_exists", "इस नाम की प्रोफ़ाइल पहले से मौजूद है"},
        {"message_count_text", "संदेश"},
        {"january", "जन"}, {"february", "फ़र"}, {"march", "मार"}, {"april", "अप्र"}, {"may", "मई"}, {"june", "जून"},
        {"july", "जुल"}, {"august", "अग"}, {"september", "सित"}, {"october", "अक्टू"}, {"november", "नव"}, {"december", "दिस"},
        {"calendar_tooltip", "तिथि पर जाएं"},
        {"last_message", "अंतिम संदेश"},
        {"settings", "सेटिंग्स"},
        {"auto_play_next_voice", "क्रमिक ध्वनि संदेशों को स्वचालित रूप से चलाएं"},
        {"open_system", "सिस्टम में खोलें"}, {"image_not_found", "चित्र नहीं मिला"}, {"video", "वीडियो"}, {"deleted_message", "यह संदेश हटाया गया"}, {"you_deleted_message", "आपने यह संदेश हटाया"}, {"edited", "संपादित"}, {"app_version", "संस्करण"}, {"app_copyright", "कॉपीराइट %1 द्वारा"},
        {"lock_chat", "चैट लॉक करें"}, {"unlock_chat", "इस चैट को अनलॉक करें"}, {"locked_chats", "लॉक की गई चैट"}, {"locked_chats_access", "लॉक की गई चैट तक पहुंचें"},
        {"lock_chat_title", "चैट लॉक करें"}, {"lock_chat_message", "यह चैट लॉक कर दी जाएगी"}, {"lock_chat_set_password", "चैट लॉक करने के लिए पासवर्ड सेट करें"},
        {"locked_chats_password_title", "लॉक की गई चैट"}, {"locked_chats_enter_password", "लॉक की गई चैट तक पहुंचने के लिए पासवर्ड दर्ज करें"},
        {"password_6_digits", "पासवर्ड 6 अंकों का होना चाहिए"}, {"password_incorrect", "गलत पासवर्ड"}, {"no_master_password", "कोई पासवर्ड सेट नहीं"},
        {"locked_chats_password", "लॉक की गई चैट का पासवर्ड"}, {"no_password", "आपके पास पासवर्ड नहीं है"}, {"change_password", "पासवर्ड बदलें"},
        {"old_password", "पुराना पासवर्ड"}, {"new_password", "नया पासवर्ड"}, {"confirm_password", "नए पासवर्ड की पुष्टि करें"}, {"change", "बदलें"},
        {"old_password_incorrect", "पुराना पासवर्ड गलत है"}, {"passwords_dont_match", "नए पासवर्ड मेल नहीं खाते"},
        {"no_locked_chats", "कोई लॉक की गई चैट नहीं"}, {"locked_chats_hint", "चैट को लॉक करने के लिए 3-डॉट मेनू से 'चैट लॉक करें' चुनें"}, {"enter", "दर्ज करें"}
    };
    m_translations["Hindi"].insert(QStringLiteral("media_image"), QStringLiteral("फ़ोटो"));
    m_translations["Hindi"].insert(QStringLiteral("media_video"), QStringLiteral("वीडियो"));
    m_translations["Hindi"].insert(QStringLiteral("media_voice"), QStringLiteral("वॉइस मैसेज"));
    m_translations["Hindi"].insert(QStringLiteral("media_audio"), QStringLiteral("ऑडियो"));
    m_translations["Hindi"].insert(QStringLiteral("media_sticker"), QStringLiteral("स्टिकर"));
    m_translations["Hindi"].insert(QStringLiteral("media_document"), QStringLiteral("दस्तावेज़"));
    m_translations["Hindi"].insert(QStringLiteral("media_unavailable"), QStringLiteral("मीडिया उपलब्ध नहीं"));
    m_translations["Hindi"].insert(QStringLiteral("tap_to_open"), QStringLiteral("खोलने के लिए टैप करें"));
    m_translations["Hindi"].insert(QStringLiteral("location"), QStringLiteral("स्थान"));
    m_translations["Hindi"].insert(QStringLiteral("contact"), QStringLiteral("संपर्क"));
    m_translations["Hindi"].insert(QStringLiteral("favorites"), QStringLiteral("पसंदीदा"));
    m_translations["Hindi"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("पसंदीदा में जोड़ें"));
    m_translations["Hindi"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("पसंदीदा से हटाएँ"));
    m_translations["Hindi"].insert(QStringLiteral("no_favorites"), QStringLiteral("कोई पसंदीदा नहीं"));
    m_translations["Hindi"].insert(QStringLiteral("favorites_hint"), QStringLiteral("पसंदीदा में जोड़ने के लिए संदेश पर राइट-क्लिक करें"));
    m_translations["Hindi"].insert(QStringLiteral("media_browser"), QStringLiteral("मीडिया"));
    m_translations["Hindi"].insert(QStringLiteral("media_browser_title"), QStringLiteral("मीडिया"));
    m_translations["Hindi"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("फ़ोटो, वीडियो और फ़ाइलें"));
    m_translations["Hindi"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("फ़ोटो"));
    m_translations["Hindi"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("वीडियो"));
    m_translations["Hindi"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("दस्तावेज़"));
    m_translations["Hindi"].insert(QStringLiteral("media_browser_links"), QStringLiteral("लिंक"));
    m_translations["Hindi"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("स्थान"));
    m_translations["Hindi"].insert(QStringLiteral("no_photos_found"), QStringLiteral("कोई फ़ोटो नहीं मिली"));
    m_translations["Hindi"].insert(QStringLiteral("no_videos_found"), QStringLiteral("कोई वीडियो नहीं मिला"));
    m_translations["Hindi"].insert(QStringLiteral("no_documents_found"), QStringLiteral("कोई दस्तावेज़ नहीं मिला"));
    m_translations["Hindi"].insert(QStringLiteral("no_links_found"), QStringLiteral("कोई लिंक नहीं मिला"));
    m_translations["Hindi"].insert(QStringLiteral("no_locations_found"), QStringLiteral("कोई स्थान नहीं मिला"));

    // Japanese
    m_translations["Japanese"] = {
        {"contact_info", "連絡先情報"}, {"msg_count", "メッセージ数"}, {"messages", "件"}, {"import_date", "インポート日"},
        {"no_chats", "チャットがありません\n\n+ を押して\n新しいチャットを追加"}, {"light_theme", "ライトテーマ"}, {"dark_theme", "ダークテーマ"},
        {"new_chat_tooltip", "新しいチャットを追加"}, {"chat_search_placeholder", "チャットを検索"}, {"importing", "インポート中..."},
        {"bulk_select_tooltip", "一括選択"}, {"bulk_delete_tooltip", "一括削除"}, {"cancel_selection_tooltip", "キャンセル"},
        {"import_new", "新しいチャットを追加"}, {"zip_description", "WhatsApp からエクスポートした ZIP ファイルを選択してください。"},
        {"select_zip", "ZIPを選択"}, {"change_zip", "ファイルを変更"}, {"continue", "続行"},
        {"owner_question", "チャットでのあなたの名前は？\n（WhatsApp アカウントに表示される名前）"}, {"owner_placeholder", "例: 山田 太郎"},
        {"import_btn", "インポート"}, {"back", "戻る"}, {"loading_messages", "メッセージを読み込み中です。お待ちください..."},
        {"select_zip_title", "WhatsApp ZIPファイルを選択"}, {"first_message", "最初のメッセージ"}, {"delete_chat", "チャットを削除"}, {"search", "検索..."}, {"search_tooltip", "メッセージを検索 (Ctrl+F)"},
        {"empty_chat_hint", "チャットを選択するか新しいチャットを追加"}, {"delete_confirm_title", "チャットを削除"},
        {"delete_confirm_text", "このチャットを削除しますか？\nすべてのメッセージが削除されます。"}, {"no_results", "結果が見つかりません"},
        {"yes", "はい"}, {"no", "いいえ"}, {"cancel", "キャンセル"}, {"language", "言語"}, {"select_language", "言語を選択"}, {"profile_photo", "プロフィール写真"},
        {"name_label", "名前"}, {"participants_label", "グループ参加者"}, {"contact_name_placeholder", "連絡先名"}, {"image_files_filter", "画像ファイル (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — %2 件のメッセージをインポートしました"}, {"conversation", "会話"},
        {"default_owner_name", "デフォルトの所有者名"}, {"owner_name_placeholder", "あなたの名前"}, {"not_set", "未設定"}, {"default_label", "デフォルト"},
        {"profile_library", "プロフィールライブラリ"}, {"add_profile", "プロフィールを追加"}, {"profile_name_label", "名前:"}, {"add_btn", "追加"},
        {"optional", "(オプション)"}, {"image_selected", "✓ 選択済み"}, {"no_profiles_library", "まだプロフィールがありません。+ をクリックして追加してください。"},
        {"profile_owner_conflict", "所有者と同じ名前のプロフィールは追加できません"}, {"profile_exists", "この名前のプロフィールは既に存在します"},
        {"message_count_text", "件のメッセージ"},
        {"january", "1月"}, {"february", "2月"}, {"march", "3月"}, {"april", "4月"}, {"may", "5月"}, {"june", "6月"},
        {"july", "7月"}, {"august", "8月"}, {"september", "9月"}, {"october", "10月"}, {"november", "11月"}, {"december", "12月"},
        {"calendar_tooltip", "日付に移動"},
        {"last_message", "最後のメッセージ"},
        {"settings", "設定"},
        {"auto_play_next_voice", "連続音声メッセージを自動再生"},
        {"open_system", "システムで開く"}, {"image_not_found", "画像が見つかりません"}, {"video", "動画"}, {"deleted_message", "このメッセージは削除されました"}, {"you_deleted_message", "このメッセージを削除しました"}, {"edited", "編集済み"}, {"app_version", "バージョン"}, {"app_copyright", "著作権 %1"},
        {"lock_chat", "チャットをロック"}, {"unlock_chat", "このチャットをロック解除"}, {"locked_chats", "ロックされたチャット"}, {"locked_chats_access", "ロックされたチャットにアクセス"},
        {"lock_chat_title", "チャットをロック"}, {"lock_chat_message", "このチャットはロックされます"}, {"lock_chat_set_password", "チャットをロックするパスワードを設定"},
        {"locked_chats_password_title", "ロックされたチャット"}, {"locked_chats_enter_password", "ロックされたチャットにアクセスするにはパスワードを入力してください"},
        {"password_6_digits", "パスワードは6桁である必要があります"}, {"password_incorrect", "パスワードが正しくありません"}, {"no_master_password", "パスワードが設定されていません"},
        {"locked_chats_password", "ロックされたチャットのパスワード"}, {"no_password", "パスワードがありません"}, {"change_password", "パスワードを変更"},
        {"old_password", "古いパスワード"}, {"new_password", "新しいパスワード"}, {"confirm_password", "新しいパスワードを確認"}, {"change", "変更"},
        {"old_password_incorrect", "古いパスワードが正しくありません"}, {"passwords_dont_match", "新しいパスワードが一致しません"},
        {"no_locked_chats", "ロックされたチャットはありません"}, {"locked_chats_hint", "3ドットメニューから「チャットをロック」を選択してチャットをロックします"}, {"enter", "入る"}
    };
    m_translations["Japanese"].insert(QStringLiteral("media_image"), QStringLiteral("写真"));
    m_translations["Japanese"].insert(QStringLiteral("media_video"), QStringLiteral("動画"));
    m_translations["Japanese"].insert(QStringLiteral("media_voice"), QStringLiteral("音声メッセージ"));
    m_translations["Japanese"].insert(QStringLiteral("media_audio"), QStringLiteral("オーディオ"));
    m_translations["Japanese"].insert(QStringLiteral("media_sticker"), QStringLiteral("スタンプ"));
    m_translations["Japanese"].insert(QStringLiteral("media_document"), QStringLiteral("ドキュメント"));
    m_translations["Japanese"].insert(QStringLiteral("media_unavailable"), QStringLiteral("メディアが利用できません"));
    m_translations["Japanese"].insert(QStringLiteral("tap_to_open"), QStringLiteral("タップして開く"));
    m_translations["Japanese"].insert(QStringLiteral("location"), QStringLiteral("現在地"));
    m_translations["Japanese"].insert(QStringLiteral("contact"), QStringLiteral("連絡先"));
    m_translations["Japanese"].insert(QStringLiteral("favorites"), QStringLiteral("お気に入り"));
    m_translations["Japanese"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("お気に入りに追加"));
    m_translations["Japanese"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("お気に入りから削除"));
    m_translations["Japanese"].insert(QStringLiteral("no_favorites"), QStringLiteral("お気に入りなし"));
    m_translations["Japanese"].insert(QStringLiteral("favorites_hint"), QStringLiteral("メッセージを右クリックしてお気に入りに追加"));
    m_translations["Japanese"].insert(QStringLiteral("media_browser"), QStringLiteral("メディア"));
    m_translations["Japanese"].insert(QStringLiteral("media_browser_title"), QStringLiteral("メディア"));
    m_translations["Japanese"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("写真、動画、ファイル"));
    m_translations["Japanese"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("写真"));
    m_translations["Japanese"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("動画"));
    m_translations["Japanese"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("ドキュメント"));
    m_translations["Japanese"].insert(QStringLiteral("media_browser_links"), QStringLiteral("リンク"));
    m_translations["Japanese"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("現在地"));
    m_translations["Japanese"].insert(QStringLiteral("no_photos_found"), QStringLiteral("写真が見つかりません"));
    m_translations["Japanese"].insert(QStringLiteral("no_videos_found"), QStringLiteral("動画が見つかりません"));
    m_translations["Japanese"].insert(QStringLiteral("no_documents_found"), QStringLiteral("ドキュメントが見つかりません"));
    m_translations["Japanese"].insert(QStringLiteral("no_links_found"), QStringLiteral("リンクが見つかりません"));
    m_translations["Japanese"].insert(QStringLiteral("no_locations_found"), QStringLiteral("現在地が見つかりません"));

    // Korean
    m_translations["Korean"] = {
        {"contact_info", "연락처 정보"}, {"msg_count", "메시지 수"}, {"messages", "메시지"}, {"import_date", "가져온 날짜"},
        {"no_chats", "채팅이 없습니다\n\n+ 버튼을 눌러\n새 채팅을 추가하세요"}, {"light_theme", "라이트 테마"}, {"dark_theme", "다크 테마"},
        {"new_chat_tooltip", "새 채팅 추가"}, {"chat_search_placeholder", "채팅 검색"}, {"importing", "가져오는 중..."},
        {"bulk_select_tooltip", "일괄 선택"}, {"bulk_delete_tooltip", "일괄 삭제"}, {"cancel_selection_tooltip", "취소"},
        {"import_new", "새 채팅 추가"}, {"zip_description", "WhatsApp에서 내보낸 ZIP 파일을 선택하세요."},
        {"select_zip", "ZIP 선택"}, {"change_zip", "파일 변경"}, {"continue", "계속"},
        {"owner_question", "채팅에서 당신의 이름은 무엇인가요?\n(WhatsApp 계정에 표시되는 이름)"}, {"owner_placeholder", "예: 홍길동"},
        {"import_btn", "가져오기"}, {"back", "뒤로"}, {"loading_messages", "메시지를 불러오는 중입니다. 잠시만 기다려 주세요..."},
        {"select_zip_title", "WhatsApp ZIP 파일 선택"}, {"first_message", "첫 메시지"}, {"delete_chat", "채팅 삭제"}, {"search", "검색..."}, {"search_tooltip", "메시지 검색 (Ctrl+F)"},
        {"empty_chat_hint", "채팅을 선택하거나 새 채팅을 추가하세요"}, {"delete_confirm_title", "채팅 삭제"},
        {"delete_confirm_text", "이 채팅을 삭제하시겠습니까?\n모든 메시지가 삭제됩니다."}, {"no_results", "검색 결과가 없습니다"},
        {"yes", "예"}, {"no", "아니요"}, {"cancel", "취소"}, {"language", "언어"}, {"select_language", "언어 선택"}, {"profile_photo", "프로필 사진"},
        {"name_label", "이름"}, {"participants_label", "그룹 참여자"}, {"contact_name_placeholder", "연락처 이름"}, {"image_files_filter", "이미지 파일 (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — %2개의 메시지를 가져왔습니다"}, {"conversation", "대화"},
        {"default_owner_name", "기본 소유자 이름"}, {"owner_name_placeholder", "이름"}, {"not_set", "설정되지 않음"}, {"default_label", "기본"},
        {"open_system", "시스템에서 열기"}, {"image_not_found", "이미지를 찾을 수 없습니다"}, {"video", "동영상"}, {"deleted_message", "이 메시지는 삭제되었습니다"}, {"you_deleted_message", "이 메시지를 삭제했습니다"}, {"edited", "수정됨"}, {"app_version", "버전"}, {"app_copyright", "저작권 %1"},
        {"lock_chat", "채팅 잠금"}, {"unlock_chat", "이 채팅 잠금 해제"}, {"locked_chats", "잠긴 채팅"}, {"locked_chats_access", "잠긴 채팅에 액세스"},
        {"lock_chat_title", "채팅 잠금"}, {"lock_chat_message", "이 채팅이 잠깁니다"}, {"lock_chat_set_password", "채팅을 잠그려면 비밀번호를 설정하세요"},
        {"locked_chats_password_title", "잠긴 채팅"}, {"locked_chats_enter_password", "잠긴 채팅에 액세스하려면 비밀번호를 입력하세요"},
        {"password_6_digits", "비밀번호는 6자리여야 합니다"}, {"password_incorrect", "비밀번호가 올바르지 않습니다"}, {"no_master_password", "비밀번호가 설정되지 않았습니다"},
        {"locked_chats_password", "잠긴 채팅 비밀번호"}, {"no_password", "비밀번호가 없습니다"}, {"change_password", "비밀번호 변경"},
        {"old_password", "이전 비밀번호"}, {"new_password", "새 비밀번호"}, {"confirm_password", "새 비밀번호 확인"}, {"change", "변경"},
        {"old_password_incorrect", "이전 비밀번호가 올바르지 않습니다"}, {"passwords_dont_match", "새 비밀번호가 일치하지 않습니다"},
        {"no_locked_chats", "잠긴 채팅이 없습니다"}, {"locked_chats_hint", "3점 메뉴에서 '채팅 잠금'을 선택하여 채팅을 잠그세요"}, {"enter", "입장"}
    };
    m_translations["Korean"].insert(QStringLiteral("media_image"), QStringLiteral("사진"));
    m_translations["Korean"].insert(QStringLiteral("media_video"), QStringLiteral("동영상"));
    m_translations["Korean"].insert(QStringLiteral("media_voice"), QStringLiteral("음성 메시지"));
    m_translations["Korean"].insert(QStringLiteral("media_audio"), QStringLiteral("오디오"));
    m_translations["Korean"].insert(QStringLiteral("media_sticker"), QStringLiteral("스티커"));
    m_translations["Korean"].insert(QStringLiteral("media_document"), QStringLiteral("문서"));
    m_translations["Korean"].insert(QStringLiteral("media_unavailable"), QStringLiteral("미디어를 사용할 수 없음"));
    m_translations["Korean"].insert(QStringLiteral("tap_to_open"), QStringLiteral("열려면 탭하세요"));
    m_translations["Korean"].insert(QStringLiteral("location"), QStringLiteral("위치"));
    m_translations["Korean"].insert(QStringLiteral("contact"), QStringLiteral("연락처"));
    m_translations["Korean"].insert(QStringLiteral("favorites"), QStringLiteral("즐겨찾기"));
    m_translations["Korean"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("즐겨찾기에 추가"));
    m_translations["Korean"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("즐겨찾기에서 제거"));
    m_translations["Korean"].insert(QStringLiteral("no_favorites"), QStringLiteral("즐겨찾기 없음"));
    m_translations["Korean"].insert(QStringLiteral("favorites_hint"), QStringLiteral("메시지를 마우스 오른쪽 버튼으로 클릭하여 즐겨찾기에 추가"));
    m_translations["Korean"].insert(QStringLiteral("media_browser"), QStringLiteral("미디어"));
    m_translations["Korean"].insert(QStringLiteral("media_browser_title"), QStringLiteral("미디어"));
    m_translations["Korean"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("사진, 동영상 및 파일"));
    m_translations["Korean"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("사진"));
    m_translations["Korean"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("동영상"));
    m_translations["Korean"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("문서"));
    m_translations["Korean"].insert(QStringLiteral("media_browser_links"), QStringLiteral("링크"));
    m_translations["Korean"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("위치"));
    m_translations["Korean"].insert(QStringLiteral("no_photos_found"), QStringLiteral("사진을 찾을 수 없음"));
    m_translations["Korean"].insert(QStringLiteral("no_videos_found"), QStringLiteral("동영상을 찾을 수 없음"));
    m_translations["Korean"].insert(QStringLiteral("no_documents_found"), QStringLiteral("문서를 찾을 수 없음"));
    m_translations["Korean"].insert(QStringLiteral("no_links_found"), QStringLiteral("링크를 찾을 수 없음"));
    m_translations["Korean"].insert(QStringLiteral("no_locations_found"), QStringLiteral("위치를 찾을 수 없음"));
    m_translations["Korean"].insert(QStringLiteral("profile_library"), QStringLiteral("프로필 라이브러리"));
    m_translations["Korean"].insert(QStringLiteral("add_profile"), QStringLiteral("프로필 추가"));
    m_translations["Korean"].insert(QStringLiteral("profile_name_label"), QStringLiteral("프로필 이름"));
    m_translations["Korean"].insert(QStringLiteral("add_btn"), QStringLiteral("추가"));
    m_translations["Korean"].insert(QStringLiteral("optional"), QStringLiteral("선택사항"));
    m_translations["Korean"].insert(QStringLiteral("image_selected"), QStringLiteral("이미지가 선택되었습니다"));
    m_translations["Korean"].insert(QStringLiteral("no_profiles_library"), QStringLiteral("저장된 프로필이 없습니다"));
    m_translations["Korean"].insert(QStringLiteral("profile_owner_conflict"), QStringLiteral("기본 소유자 이름과 동일한 프로필을 추가할 수 없습니다"));
    m_translations["Korean"].insert(QStringLiteral("profile_exists"), QStringLiteral("이 이름의 프로필이 이미 존재합니다"));
    m_translations["Korean"].insert(QStringLiteral("message_count_text"), QStringLiteral("개 메시지"));
    m_translations["Korean"].insert(QStringLiteral("january"), QStringLiteral("1월"));
    m_translations["Korean"].insert(QStringLiteral("february"), QStringLiteral("2월"));
    m_translations["Korean"].insert(QStringLiteral("march"), QStringLiteral("3월"));
    m_translations["Korean"].insert(QStringLiteral("april"), QStringLiteral("4월"));
    m_translations["Korean"].insert(QStringLiteral("may"), QStringLiteral("5월"));
    m_translations["Korean"].insert(QStringLiteral("june"), QStringLiteral("6월"));
    m_translations["Korean"].insert(QStringLiteral("july"), QStringLiteral("7월"));
    m_translations["Korean"].insert(QStringLiteral("august"), QStringLiteral("8월"));
    m_translations["Korean"].insert(QStringLiteral("september"), QStringLiteral("9월"));
    m_translations["Korean"].insert(QStringLiteral("october"), QStringLiteral("10월"));
    m_translations["Korean"].insert(QStringLiteral("november"), QStringLiteral("11월"));
    m_translations["Korean"].insert(QStringLiteral("december"), QStringLiteral("12월"));
    m_translations["Korean"].insert(QStringLiteral("calendar_tooltip"), QStringLiteral("날짜로 이동"));
    m_translations["Korean"].insert(QStringLiteral("last_message"), QStringLiteral("마지막 메시지"));
    m_translations["Korean"].insert(QStringLiteral("settings"), QStringLiteral("설정"));
    m_translations["Korean"].insert(QStringLiteral("auto_play_next_voice"), QStringLiteral("연속 음성 메시지 자동 재생"));

    // Mongolian
    m_translations["Mongolian"] = {
        {"contact_info", "Холбоо барих мэдээлэл"}, {"msg_count", "Мессежийн тоо"}, {"messages", "мессеж"}, {"import_date", "Импортын огноо"},
        {"no_chats", "Чат олдсонгүй\n\n+ дарж\nшинэ чат нэмнэ үү"}, {"light_theme", "Цайвар загвар"}, {"dark_theme", "Харанхуй загвар"},
        {"new_chat_tooltip", "Шинэ чат нэмэх"}, {"chat_search_placeholder", "Чатаас хайх"}, {"importing", "Импорт хийж байна..."},
        {"bulk_select_tooltip", "Олныг сонгох"}, {"bulk_delete_tooltip", "Олныг устгах"}, {"cancel_selection_tooltip", "Цуцлах"},
        {"import_new", "Шинэ чат нэмэх"}, {"zip_description", "WhatsApp-аас экспортолсон ZIP файлыг сонгоно уу."},
        {"select_zip", "ZIP сонгох"}, {"change_zip", "Файл солих"}, {"continue", "Үргэлжлүүлэх"},
        {"owner_question", "Чат дээрх таны нэр юу вэ?\n(WhatsApp дансанд харагддаг нэр)"}, {"owner_placeholder", "Ж: Батболд"},
        {"import_btn", "Импорт"}, {"back", "Буцах"}, {"loading_messages", "Мессежүүд ачаалж байна, түр хүлээнэ үү..."},
        {"select_zip_title", "WhatsApp ZIP файл сонгох"}, {"first_message", "Эхний мессеж"}, {"delete_chat", "Чат устгах"}, {"search", "Хайх..."}, {"search_tooltip", "Зурвасуудаас хайх (Ctrl+F)"},
        {"empty_chat_hint", "Чат сонгох эсвэл шинэ чат нэмэх"}, {"delete_confirm_title", "Чат устгах"},
        {"delete_confirm_text", "Энэ чатыг устгахдаа итгэлтэй байна уу?\nБүх мессеж устна."}, {"no_results", "Үр дүн олдсонгүй"},
        {"yes", "Тийм"}, {"no", "Үгүй"}, {"cancel", "Цуцлах"}, {"language", "Хэл"}, {"select_language", "Хэл сонгох"}, {"profile_photo", "Профайл зураг"},
        {"name_label", "Нэр"}, {"participants_label", "Бүлгийн оролцогчид"}, {"contact_name_placeholder", "Харилцагчийн нэр"}, {"image_files_filter", "Зургийн файлууд (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — %2 мессеж импортлогдлоо"}, {"conversation", "Яриа"},
        {"default_owner_name", "Анхдагч эзэмшигчийн нэр"}, {"owner_name_placeholder", "Таны нэр"}, {"not_set", "Тохируулаагүй"}, {"default_label", "Анхдагч"},
        {"open_system", "Системээр нээх"}, {"image_not_found", "Зураг олдсонгүй"}, {"video", "Видео"}, {"deleted_message", "Энэ мессеж устсан"}, {"you_deleted_message", "Та энэ мессежийг устгасан"}, {"edited", "Засварласан"}, {"app_version", "хувилбар"}, {"app_copyright", "Зохиогчийн эрх %1-д хамааралагдана"},
        {"lock_chat", "Чатыг түгжих"}, {"unlock_chat", "Энэ чатыг түгжээсийг тайлах"}, {"locked_chats", "Түгжээстэй чатууд"}, {"locked_chats_access", "Түгжээстэй чатуудад нэвтрэх"},
        {"lock_chat_title", "Чатыг түгжих"}, {"lock_chat_message", "Энэ чат түгжигдэх болно"}, {"lock_chat_set_password", "Чатыг түгжихийн тулд нууц үг тохируулна уу"},
        {"locked_chats_password_title", "Түгжээстэй чатууд"}, {"locked_chats_enter_password", "Түгжээстэй чатуудад нэвтрэхийн тулд нууц үг оруулна уу"},
        {"password_6_digits", "Нууц үг 6 оронтой байх ёстой"}, {"password_incorrect", "Нууц үг буруу байна"}, {"no_master_password", "Нууц үг тохируулаагүй"},
        {"locked_chats_password", "Түгжээстэй чатуудын нууц үг"}, {"no_password", "Танд нууц үг байхгүй байна"}, {"change_password", "Нууц үг солих"},
        {"old_password", "Хуучин нууц үг"}, {"new_password", "Шинэ нууц үг"}, {"confirm_password", "Шинэ нууц үгийг баталгаажуулах"}, {"change", "Солих"},
        {"old_password_incorrect", "Хуучин нууц үг буруу байна"}, {"passwords_dont_match", "Шинэ нууц үгүүд таарахгүй байна"},
        {"no_locked_chats", "Түгжээстэй чат байхгүй"}, {"locked_chats_hint", "Чатыг түгжихийн тулд 3 цэгийн цэснээс 'Чатыг түгжих'-ийг сонгоно уу"}, {"enter", "Нэвтрэх"}
    };
    m_translations["Mongolian"].insert(QStringLiteral("media_image"), QStringLiteral("Зураг"));
    m_translations["Mongolian"].insert(QStringLiteral("media_video"), QStringLiteral("Видео"));
    m_translations["Mongolian"].insert(QStringLiteral("media_voice"), QStringLiteral("Дуут мессеж"));
    m_translations["Mongolian"].insert(QStringLiteral("media_audio"), QStringLiteral("Аудио"));
    m_translations["Mongolian"].insert(QStringLiteral("media_sticker"), QStringLiteral("Стикер"));
    m_translations["Mongolian"].insert(QStringLiteral("media_document"), QStringLiteral("Баримт бичиг"));
    m_translations["Mongolian"].insert(QStringLiteral("media_unavailable"), QStringLiteral("Медиа байхгүй"));
    m_translations["Mongolian"].insert(QStringLiteral("tap_to_open"), QStringLiteral("Нээхийн тулд товшино уу"));
    m_translations["Mongolian"].insert(QStringLiteral("location"), QStringLiteral("Байршил"));
    m_translations["Mongolian"].insert(QStringLiteral("contact"), QStringLiteral("Харилцагч"));
    m_translations["Mongolian"].insert(QStringLiteral("favorites"), QStringLiteral("Дуртай"));
    m_translations["Mongolian"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("Дуртайд нэмэх"));
    m_translations["Mongolian"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("Дуртайгаас хасах"));
    m_translations["Mongolian"].insert(QStringLiteral("no_favorites"), QStringLiteral("Дуртай байхгүй"));
    m_translations["Mongolian"].insert(QStringLiteral("favorites_hint"), QStringLiteral("Мессежийг баруун товшиж дуртайд нэмнэ үү"));
    m_translations["Mongolian"].insert(QStringLiteral("media_browser"), QStringLiteral("Медиа"));
    m_translations["Mongolian"].insert(QStringLiteral("media_browser_title"), QStringLiteral("Медиа"));
    m_translations["Mongolian"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("Зураг, видео болон файлууд"));
    m_translations["Mongolian"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("Зураг"));
    m_translations["Mongolian"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("Видео"));
    m_translations["Mongolian"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("Баримт бичиг"));
    m_translations["Mongolian"].insert(QStringLiteral("media_browser_links"), QStringLiteral("Холбоос"));
    m_translations["Mongolian"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("Байршил"));
    m_translations["Mongolian"].insert(QStringLiteral("no_photos_found"), QStringLiteral("Зураг олдсонгүй"));
    m_translations["Mongolian"].insert(QStringLiteral("no_videos_found"), QStringLiteral("Видео олдсонгүй"));
    m_translations["Mongolian"].insert(QStringLiteral("no_documents_found"), QStringLiteral("Баримт бичиг олдсонгүй"));
    m_translations["Mongolian"].insert(QStringLiteral("no_links_found"), QStringLiteral("Холбоос олдсонгүй"));
    m_translations["Mongolian"].insert(QStringLiteral("no_locations_found"), QStringLiteral("Байршил олдсонгүй"));
    m_translations["Mongolian"].insert(QStringLiteral("profile_library"), QStringLiteral("Профайлын сан"));
    m_translations["Mongolian"].insert(QStringLiteral("add_profile"), QStringLiteral("Профайл нэмэх"));
    m_translations["Mongolian"].insert(QStringLiteral("profile_name_label"), QStringLiteral("Профайлын нэр"));
    m_translations["Mongolian"].insert(QStringLiteral("add_btn"), QStringLiteral("Нэмэх"));
    m_translations["Mongolian"].insert(QStringLiteral("optional"), QStringLiteral("Заавал биш"));
    m_translations["Mongolian"].insert(QStringLiteral("image_selected"), QStringLiteral("Зураг сонгогдсон"));
    m_translations["Mongolian"].insert(QStringLiteral("no_profiles_library"), QStringLiteral("Хадгалагдсан профайл байхгүй"));
    m_translations["Mongolian"].insert(QStringLiteral("profile_owner_conflict"), QStringLiteral("Анхдагч эзэмшигчийн нэртэй ижил профайл нэмэх боломжгүй"));
    m_translations["Mongolian"].insert(QStringLiteral("profile_exists"), QStringLiteral("Энэ нэртэй профайл аль хэдийн байна"));
    m_translations["Mongolian"].insert(QStringLiteral("message_count_text"), QStringLiteral("мессеж"));
    m_translations["Mongolian"].insert(QStringLiteral("january"), QStringLiteral("1-р"));
    m_translations["Mongolian"].insert(QStringLiteral("february"), QStringLiteral("2-р"));
    m_translations["Mongolian"].insert(QStringLiteral("march"), QStringLiteral("3-р"));
    m_translations["Mongolian"].insert(QStringLiteral("april"), QStringLiteral("4-р"));
    m_translations["Mongolian"].insert(QStringLiteral("may"), QStringLiteral("5-р"));
    m_translations["Mongolian"].insert(QStringLiteral("june"), QStringLiteral("6-р"));
    m_translations["Mongolian"].insert(QStringLiteral("july"), QStringLiteral("7-р"));
    m_translations["Mongolian"].insert(QStringLiteral("august"), QStringLiteral("8-р"));
    m_translations["Mongolian"].insert(QStringLiteral("september"), QStringLiteral("9-р"));
    m_translations["Mongolian"].insert(QStringLiteral("october"), QStringLiteral("10-р"));
    m_translations["Mongolian"].insert(QStringLiteral("november"), QStringLiteral("11-р"));
    m_translations["Mongolian"].insert(QStringLiteral("december"), QStringLiteral("12-р"));
    m_translations["Mongolian"].insert(QStringLiteral("calendar_tooltip"), QStringLiteral("Огноо руу шилжих"));
    m_translations["Mongolian"].insert(QStringLiteral("last_message"), QStringLiteral("Сүүлчийн мессеж"));
    m_translations["Mongolian"].insert(QStringLiteral("settings"), QStringLiteral("Тохиргоо"));
    m_translations["Mongolian"].insert(QStringLiteral("auto_play_next_voice"), QStringLiteral("Дараалсан дуут мессежүүдийг автоматаар тоглуулах"));

    // Polish
    m_translations["Polish"] = {
        {"contact_info", "Informacje o kontakcie"}, {"msg_count", "Liczba wiadomości"}, {"messages", "wiadomości"}, {"import_date", "Data importu"},
        {"no_chats", "Brak czatów\n\nKliknij + aby dodać\nnowy czat"}, {"light_theme", "Jasny motyw"}, {"dark_theme", "Ciemny motyw"},
        {"new_chat_tooltip", "Dodaj nowy czat"}, {"chat_search_placeholder", "Szukaj na czatach"}, {"importing", "Importowanie..."},
        {"bulk_select_tooltip", "Zaznaczanie zbiorcze"}, {"bulk_delete_tooltip", "Usuwanie zbiorcze"}, {"cancel_selection_tooltip", "Anuluj"},
        {"import_new", "Dodaj nowy czat"}, {"zip_description", "Wybierz plik ZIP wyeksportowany z WhatsApp."},
        {"select_zip", "Wybierz ZIP"}, {"change_zip", "Zmień plik"}, {"continue", "Kontynuuj"},
        {"owner_question", "Jak masz na imię na czacie?\n(Imię widoczne na koncie WhatsApp)"}, {"owner_placeholder", "Np: Jan Kowalski"},
        {"import_btn", "Importuj"}, {"back", "Wstecz"}, {"loading_messages", "Ładowanie wiadomości, proszę czekać..."},
        {"select_zip_title", "Wybierz plik ZIP WhatsApp"}, {"first_message", "Pierwsza wiadomość"}, {"delete_chat", "Usuń czat"}, {"search", "Szukaj..."}, {"search_tooltip", "Szukaj w wiadomościach (Ctrl+F)"},
        {"empty_chat_hint", "Wybierz czat lub dodaj nowy"}, {"delete_confirm_title", "Usuń czat"},
        {"delete_confirm_text", "Czy na pewno chcesz usunąć ten czat?\nWszystkie wiadomości zostaną usunięte."}, {"no_results", "Brak wyników"},
        {"yes", "Tak"}, {"no", "Nie"}, {"cancel", "Anuluj"}, {"language", "Język"}, {"select_language", "Wybierz język"}, {"profile_photo", "Zdjęcie profilowe"},
        {"name_label", "Nazwa"}, {"participants_label", "Uczestnicy grupy"}, {"contact_name_placeholder", "Nazwa kontaktu"}, {"image_files_filter", "Pliki obrazów (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — zaimportowano %2 wiadomości"}, {"conversation", "Rozmowa"},
        {"default_owner_name", "Domyślna nazwa właściciela"}, {"owner_name_placeholder", "Twoje imię"}, {"not_set", "Nieustawione"}, {"default_label", "Domyślny"},
        {"open_system", "Otwórz w systemie"}, {"image_not_found", "Nie znaleziono obrazu"}, {"video", "Wideo"}, {"deleted_message", "Ta wiadomość została usunięta"}, {"you_deleted_message", "Usunąłeś tę wiadomość"}, {"edited", "Edytowano"}, {"app_version", "wersja"}, {"app_copyright", "Prawa autorskie %1"},
        {"lock_chat", "Zablokuj czat"}, {"unlock_chat", "Odblokuj ten czat"}, {"locked_chats", "Zablokowane czaty"}, {"locked_chats_access", "Dostęp do zablokowanych czatów"},
        {"lock_chat_title", "Zablokuj czat"}, {"lock_chat_message", "Ten czat zostanie zablokowany"}, {"lock_chat_set_password", "Ustaw hasło, aby zablokować czaty"},
        {"locked_chats_password_title", "Zablokowane czaty"}, {"locked_chats_enter_password", "Wprowadź hasło, aby uzyskać dostęp do zablokowanych czatów"},
        {"password_6_digits", "Hasło musi składać się z 6 cyfr"}, {"password_incorrect", "Nieprawidłowe hasło"}, {"no_master_password", "Nie ustawiono hasła"},
        {"locked_chats_password", "Hasło zablokowanych czatów"}, {"no_password", "Nie masz hasła"}, {"change_password", "Zmień hasło"},
        {"old_password", "Stare hasło"}, {"new_password", "Nowe hasło"}, {"confirm_password", "Potwierdź nowe hasło"}, {"change", "Zmień"},
        {"old_password_incorrect", "Stare hasło jest nieprawidłowe"}, {"passwords_dont_match", "Nowe hasła nie pasują"},
        {"no_locked_chats", "Brak zablokowanych czatów"}, {"locked_chats_hint", "Wybierz 'Zablokuj czat' z menu 3 kropek, aby zablokować czat"}, {"enter", "Wejdź"}
    };
    m_translations["Polish"].insert(QStringLiteral("media_image"), QStringLiteral("Zdjęcie"));
    m_translations["Polish"].insert(QStringLiteral("media_video"), QStringLiteral("Wideo"));
    m_translations["Polish"].insert(QStringLiteral("media_voice"), QStringLiteral("Wiadomość głosowa"));
    m_translations["Polish"].insert(QStringLiteral("media_audio"), QStringLiteral("Audio"));
    m_translations["Polish"].insert(QStringLiteral("media_sticker"), QStringLiteral("Naklejka"));
    m_translations["Polish"].insert(QStringLiteral("media_document"), QStringLiteral("Dokument"));
    m_translations["Polish"].insert(QStringLiteral("media_unavailable"), QStringLiteral("Multimedia niedostępne"));
    m_translations["Polish"].insert(QStringLiteral("tap_to_open"), QStringLiteral("Dotknij, aby otworzyć"));
    m_translations["Polish"].insert(QStringLiteral("location"), QStringLiteral("Lokalizacja"));
    m_translations["Polish"].insert(QStringLiteral("contact"), QStringLiteral("Kontakt"));
    m_translations["Polish"].insert(QStringLiteral("favorites"), QStringLiteral("Ulubione"));
    m_translations["Polish"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("Dodaj do ulubionych"));
    m_translations["Polish"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("Usuń z ulubionych"));
    m_translations["Polish"].insert(QStringLiteral("no_favorites"), QStringLiteral("Brak ulubionych"));
    m_translations["Polish"].insert(QStringLiteral("favorites_hint"), QStringLiteral("Kliknij prawym przyciskiem myszy, aby dodać do ulubionych"));
    m_translations["Polish"].insert(QStringLiteral("media_browser"), QStringLiteral("Multimedia"));
    m_translations["Polish"].insert(QStringLiteral("media_browser_title"), QStringLiteral("Multimedia"));
    m_translations["Polish"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("Zdjęcia, filmy i pliki"));
    m_translations["Polish"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("Zdjęcia"));
    m_translations["Polish"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("Filmy"));
    m_translations["Polish"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("Dokumenty"));
    m_translations["Polish"].insert(QStringLiteral("media_browser_links"), QStringLiteral("Linki"));
    m_translations["Polish"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("Lokalizacje"));
    m_translations["Polish"].insert(QStringLiteral("no_photos_found"), QStringLiteral("Nie znaleziono zdjęć"));
    m_translations["Polish"].insert(QStringLiteral("no_videos_found"), QStringLiteral("Nie znaleziono filmów"));
    m_translations["Polish"].insert(QStringLiteral("no_documents_found"), QStringLiteral("Nie znaleziono dokumentów"));
    m_translations["Polish"].insert(QStringLiteral("no_links_found"), QStringLiteral("Nie znaleziono linków"));
    m_translations["Polish"].insert(QStringLiteral("no_locations_found"), QStringLiteral("Nie znaleziono lokalizacji"));
    m_translations["Polish"].insert(QStringLiteral("profile_library"), QStringLiteral("Biblioteka profili"));
    m_translations["Polish"].insert(QStringLiteral("add_profile"), QStringLiteral("Dodaj profil"));
    m_translations["Polish"].insert(QStringLiteral("profile_name_label"), QStringLiteral("Nazwa profilu"));
    m_translations["Polish"].insert(QStringLiteral("add_btn"), QStringLiteral("Dodaj"));
    m_translations["Polish"].insert(QStringLiteral("optional"), QStringLiteral("Opcjonalne"));
    m_translations["Polish"].insert(QStringLiteral("image_selected"), QStringLiteral("Wybrano zdjęcie"));
    m_translations["Polish"].insert(QStringLiteral("no_profiles_library"), QStringLiteral("Brak zapisanych profili"));
    m_translations["Polish"].insert(QStringLiteral("profile_owner_conflict"), QStringLiteral("Nie można dodać profilu z taką samą nazwą jak domyślna nazwa właściciela"));
    m_translations["Polish"].insert(QStringLiteral("profile_exists"), QStringLiteral("Profil o tej nazwie już istnieje"));
    m_translations["Polish"].insert(QStringLiteral("message_count_text"), QStringLiteral("wiadomości"));
    m_translations["Polish"].insert(QStringLiteral("january"), QStringLiteral("Sty"));
    m_translations["Polish"].insert(QStringLiteral("february"), QStringLiteral("Lut"));
    m_translations["Polish"].insert(QStringLiteral("march"), QStringLiteral("Mar"));
    m_translations["Polish"].insert(QStringLiteral("april"), QStringLiteral("Kwi"));
    m_translations["Polish"].insert(QStringLiteral("may"), QStringLiteral("Maj"));
    m_translations["Polish"].insert(QStringLiteral("june"), QStringLiteral("Cze"));
    m_translations["Polish"].insert(QStringLiteral("july"), QStringLiteral("Lip"));
    m_translations["Polish"].insert(QStringLiteral("august"), QStringLiteral("Sie"));
    m_translations["Polish"].insert(QStringLiteral("september"), QStringLiteral("Wrz"));
    m_translations["Polish"].insert(QStringLiteral("october"), QStringLiteral("Paź"));
    m_translations["Polish"].insert(QStringLiteral("november"), QStringLiteral("Lis"));
    m_translations["Polish"].insert(QStringLiteral("december"), QStringLiteral("Gru"));
    m_translations["Polish"].insert(QStringLiteral("calendar_tooltip"), QStringLiteral("Przejdź do daty"));
    m_translations["Polish"].insert(QStringLiteral("last_message"), QStringLiteral("Ostatnia wiadomość"));
    m_translations["Polish"].insert(QStringLiteral("settings"), QStringLiteral("Ustawienia"));
    m_translations["Polish"].insert(QStringLiteral("auto_play_next_voice"), QStringLiteral("Automatyczne odtwarzanie kolejnych wiadomości głosowych"));

    // Ukrainian
    m_translations["Ukrainian"] = {
        {"contact_info", "Інформація про контакт"}, {"msg_count", "Кількість повідомлень"}, {"messages", "повідомлень"}, {"import_date", "Дата імпорту"},
        {"no_chats", "Чатів не знайдено\n\nНатисніть +, щоб додати\nновий чат"}, {"light_theme", "Світла тема"}, {"dark_theme", "Темна тема"},
        {"new_chat_tooltip", "Додати новий чат"}, {"chat_search_placeholder", "Пошук у чатах"}, {"importing", "Імпорт..."},
        {"bulk_select_tooltip", "Масовий вибір"}, {"bulk_delete_tooltip", "Масове видалення"}, {"cancel_selection_tooltip", "Скасувати"},
        {"import_new", "Додати новий чат"}, {"zip_description", "Виберіть ZIP-файл, експортований із WhatsApp."},
        {"select_zip", "Вибрати ZIP"}, {"change_zip", "Змінити файл"}, {"continue", "Продовжити"},
        {"owner_question", "Як вас звати у чаті?\n(Ім'я у вашому акаунті WhatsApp)"}, {"owner_placeholder", "Напр.: Іван Петренко"},
        {"import_btn", "Імпорт"}, {"back", "Назад"}, {"loading_messages", "Завантаження повідомлень, зачекайте..."},
        {"select_zip_title", "Виберіть ZIP-файл WhatsApp"}, {"first_message", "Перше повідомлення"}, {"delete_chat", "Видалити чат"}, {"search", "Пошук..."}, {"search_tooltip", "Пошук у повідомленнях (Ctrl+F)"},
        {"empty_chat_hint", "Виберіть чат або додайте новий"}, {"delete_confirm_title", "Видалити чат"},
        {"delete_confirm_text", "Ви впевнені, що хочете видалити цей чат?\nУсі повідомлення буде видалено."}, {"no_results", "Результатів не знайдено"},
        {"yes", "Так"}, {"no", "Ні"}, {"cancel", "Скасувати"}, {"language", "Мова"}, {"select_language", "Виберіть мову"}, {"profile_photo", "Фото профілю"},
        {"name_label", "Ім'я"}, {"participants_label", "Учасники групи"}, {"contact_name_placeholder", "Ім'я контакту"}, {"image_files_filter", "Файли зображень (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — імпортовано %2 повідомлень"}, {"conversation", "Розмова"},
        {"default_owner_name", "Ім'я власника за замовчуванням"}, {"owner_name_placeholder", "Ваше ім'я"}, {"not_set", "Не встановлено"}, {"default_label", "За замовчуванням"},
        {"open_system", "Відкрити в системі"}, {"image_not_found", "Зображення не знайдено"}, {"video", "Відео"}, {"deleted_message", "Це повідомлення видалено"}, {"you_deleted_message", "Ви видалили це повідомлення"}, {"edited", "Змінено"}, {"app_version", "версія"}, {"app_copyright", "Авторські права належать %1"},
        {"lock_chat", "Заблокувати чат"}, {"unlock_chat", "Розблокувати цей чат"}, {"locked_chats", "Заблоковані чати"}, {"locked_chats_access", "Доступ до заблокованих чатів"},
        {"lock_chat_title", "Заблокувати чат"}, {"lock_chat_message", "Цей чат буде заблоковано"}, {"lock_chat_set_password", "Встановіть пароль для блокування чатів"},
        {"locked_chats_password_title", "Заблоковані чати"}, {"locked_chats_enter_password", "Введіть пароль для доступу до заблокованих чатів"},
        {"password_6_digits", "Пароль має складатися з 6 цифр"}, {"password_incorrect", "Неправильний пароль"}, {"no_master_password", "Пароль не встановлено"},
        {"locked_chats_password", "Пароль заблокованих чатів"}, {"no_password", "У вас немає пароля"}, {"change_password", "Змінити пароль"},
        {"old_password", "Старий пароль"}, {"new_password", "Новий пароль"}, {"confirm_password", "Підтвердіть новий пароль"}, {"change", "Змінити"},
        {"old_password_incorrect", "Старий пароль неправильний"}, {"passwords_dont_match", "Нові паролі не співпадають"},
        {"no_locked_chats", "Немає заблокованих чатів"}, {"locked_chats_hint", "Виберіть 'Заблокувати чат' з меню з трьох крапок, щоб заблокувати чат"}, {"enter", "Увійти"}
    };
    m_translations["Ukrainian"].insert(QStringLiteral("media_image"), QStringLiteral("Фото"));
    m_translations["Ukrainian"].insert(QStringLiteral("media_video"), QStringLiteral("Відео"));
    m_translations["Ukrainian"].insert(QStringLiteral("media_voice"), QStringLiteral("Голосове повідомлення"));
    m_translations["Ukrainian"].insert(QStringLiteral("media_audio"), QStringLiteral("Аудіо"));
    m_translations["Ukrainian"].insert(QStringLiteral("media_sticker"), QStringLiteral("Стікер"));
    m_translations["Ukrainian"].insert(QStringLiteral("media_document"), QStringLiteral("Документ"));
    m_translations["Ukrainian"].insert(QStringLiteral("media_unavailable"), QStringLiteral("Медіа недоступне"));
    m_translations["Ukrainian"].insert(QStringLiteral("tap_to_open"), QStringLiteral("Торкніться щоб відкрити"));
    m_translations["Ukrainian"].insert(QStringLiteral("location"), QStringLiteral("Місцезнаходження"));
    m_translations["Ukrainian"].insert(QStringLiteral("contact"), QStringLiteral("Контакт"));
    m_translations["Ukrainian"].insert(QStringLiteral("favorites"), QStringLiteral("Вибране"));
    m_translations["Ukrainian"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("Додати у вибране"));
    m_translations["Ukrainian"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("Видалити з вибраного"));
    m_translations["Ukrainian"].insert(QStringLiteral("no_favorites"), QStringLiteral("Немає вибраного"));
    m_translations["Ukrainian"].insert(QStringLiteral("favorites_hint"), QStringLiteral("Клацніть правою кнопкою для додавання у вибране"));
    m_translations["Ukrainian"].insert(QStringLiteral("media_browser"), QStringLiteral("Медіа"));
    m_translations["Ukrainian"].insert(QStringLiteral("media_browser_title"), QStringLiteral("Медіа"));
    m_translations["Ukrainian"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("Фото, відео та файли"));
    m_translations["Ukrainian"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("Фото"));
    m_translations["Ukrainian"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("Відео"));
    m_translations["Ukrainian"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("Документи"));
    m_translations["Ukrainian"].insert(QStringLiteral("media_browser_links"), QStringLiteral("Посилання"));
    m_translations["Ukrainian"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("Місцезнаходження"));
    m_translations["Ukrainian"].insert(QStringLiteral("no_photos_found"), QStringLiteral("Фото не знайдено"));
    m_translations["Ukrainian"].insert(QStringLiteral("no_videos_found"), QStringLiteral("Відео не знайдено"));
    m_translations["Ukrainian"].insert(QStringLiteral("no_documents_found"), QStringLiteral("Документи не знайдено"));
    m_translations["Ukrainian"].insert(QStringLiteral("no_links_found"), QStringLiteral("Посилання не знайдено"));
    m_translations["Ukrainian"].insert(QStringLiteral("no_locations_found"), QStringLiteral("Місцезнаходження не знайдено"));
    m_translations["Ukrainian"].insert(QStringLiteral("profile_library"), QStringLiteral("Бібліотека профілів"));
    m_translations["Ukrainian"].insert(QStringLiteral("add_profile"), QStringLiteral("Додати профіль"));
    m_translations["Ukrainian"].insert(QStringLiteral("profile_name_label"), QStringLiteral("Назва профілю"));
    m_translations["Ukrainian"].insert(QStringLiteral("add_btn"), QStringLiteral("Додати"));
    m_translations["Ukrainian"].insert(QStringLiteral("optional"), QStringLiteral("Необов'язково"));
    m_translations["Ukrainian"].insert(QStringLiteral("image_selected"), QStringLiteral("Зображення вибрано"));
    m_translations["Ukrainian"].insert(QStringLiteral("no_profiles_library"), QStringLiteral("Немає збережених профілів"));
    m_translations["Ukrainian"].insert(QStringLiteral("profile_owner_conflict"), QStringLiteral("Не можна додати профіль з таким самим ім'ям як ім'я власника за замовчуванням"));
    m_translations["Ukrainian"].insert(QStringLiteral("profile_exists"), QStringLiteral("Профіль з таким ім'ям вже існує"));
    m_translations["Ukrainian"].insert(QStringLiteral("message_count_text"), QStringLiteral("повідомлень"));
    m_translations["Ukrainian"].insert(QStringLiteral("january"), QStringLiteral("Січ"));
    m_translations["Ukrainian"].insert(QStringLiteral("february"), QStringLiteral("Лют"));
    m_translations["Ukrainian"].insert(QStringLiteral("march"), QStringLiteral("Бер"));
    m_translations["Ukrainian"].insert(QStringLiteral("april"), QStringLiteral("Кві"));
    m_translations["Ukrainian"].insert(QStringLiteral("may"), QStringLiteral("Тра"));
    m_translations["Ukrainian"].insert(QStringLiteral("june"), QStringLiteral("Чер"));
    m_translations["Ukrainian"].insert(QStringLiteral("july"), QStringLiteral("Лип"));
    m_translations["Ukrainian"].insert(QStringLiteral("august"), QStringLiteral("Сер"));
    m_translations["Ukrainian"].insert(QStringLiteral("september"), QStringLiteral("Вер"));
    m_translations["Ukrainian"].insert(QStringLiteral("october"), QStringLiteral("Жов"));
    m_translations["Ukrainian"].insert(QStringLiteral("november"), QStringLiteral("Лис"));
    m_translations["Ukrainian"].insert(QStringLiteral("december"), QStringLiteral("Гру"));
    m_translations["Ukrainian"].insert(QStringLiteral("calendar_tooltip"), QStringLiteral("Перейти до дати"));
    m_translations["Ukrainian"].insert(QStringLiteral("last_message"), QStringLiteral("Останнє повідомлення"));
    m_translations["Ukrainian"].insert(QStringLiteral("settings"), QStringLiteral("Налаштування"));
    m_translations["Ukrainian"].insert(QStringLiteral("auto_play_next_voice"), QStringLiteral("Автовідтворення послідовних голосових повідомлень"));

    // Uzbek
    m_translations["Uzbek"] = {
        {"contact_info", "Kontakt ma'lumoti"}, {"msg_count", "Xabarlar soni"}, {"messages", "xabar"}, {"import_date", "Import sanasi"},
        {"no_chats", "Chatlar topilmadi\n\nYangi chat qo'shish uchun\n+ tugmasini bosing"}, {"light_theme", "Yorug' mavzu"}, {"dark_theme", "Qorong'u mavzu"},
        {"new_chat_tooltip", "Yangi chat qo'shish"}, {"chat_search_placeholder", "Chatlardan qidirish"}, {"importing", "Import qilinmoqda..."},
        {"bulk_select_tooltip", "Ommaviy tanlov"}, {"bulk_delete_tooltip", "Ommaviy o'chirish"}, {"cancel_selection_tooltip", "Bekor qilish"},
        {"import_new", "Yangi chat qo'shish"}, {"zip_description", "WhatsApp'dan eksport qilingan ZIP faylini tanlang."},
        {"select_zip", "ZIP tanlash"}, {"change_zip", "Faylni o'zgartirish"}, {"continue", "Davom etish"},
        {"owner_question", "Chatdagi ismingiz nima?\n(WhatsApp hisobingizda ko'rinadigan ism)"}, {"owner_placeholder", "Masalan: Ali Valiyev"},
        {"import_btn", "Import"}, {"back", "Orqaga"}, {"loading_messages", "Xabarlar yuklanmoqda, iltimos kuting..."},
        {"select_zip_title", "WhatsApp ZIP faylini tanlang"}, {"first_message", "Birinchi xabar"}, {"delete_chat", "Chatni o'chirish"}, {"search", "Qidirish..."}, {"search_tooltip", "Xabarlarda qidirish (Ctrl+F)"},
        {"empty_chat_hint", "Chatni tanlang yoki yangisini qo'shing"}, {"delete_confirm_title", "Chatni o'chirish"},
        {"delete_confirm_text", "Rostdan ham bu chatni o'chirmoqchimisiz?\nBarcha xabarlar o'chiriladi."}, {"no_results", "Natija topilmadi"},
        {"yes", "Ha"}, {"no", "Yo'q"}, {"cancel", "Bekor qilish"}, {"language", "Til"}, {"select_language", "Tilni tanlang"}, {"profile_photo", "Profil rasmi"},
        {"name_label", "Ism"}, {"participants_label", "Guruh ishtirokchilari"}, {"contact_name_placeholder", "Kontakt nomi"}, {"image_files_filter", "Rasm fayllari (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — %2 ta xabar import qilindi"}, {"conversation", "Suhbat"},
        {"default_owner_name", "Standart egasi nomi"}, {"owner_name_placeholder", "Ismingiz"}, {"not_set", "Belgilanmagan"}, {"default_label", "Standart"},
        {"open_system", "Tizimda ochish"}, {"image_not_found", "Rasm topilmadi"}, {"video", "Video"}, {"deleted_message", "Bu xabar o'chirildi"}, {"you_deleted_message", "Siz bu xabarni o'chirdingiz"}, {"edited", "Tahrirlangan"}, {"app_version", "versiya"}, {"app_copyright", "Mualliflik huquqi %1 tomonidan"},
        {"lock_chat", "Chatni qulflash"}, {"unlock_chat", "Bu chatni qulfdan chiqarish"}, {"locked_chats", "Qulflangan chatlar"}, {"locked_chats_access", "Qulflangan chatlarga kirish"},
        {"lock_chat_title", "Chatni qulflash"}, {"lock_chat_message", "Bu chat qulflanadi"}, {"lock_chat_set_password", "Chatlarni qulflash uchun parol o'rnating"},
        {"locked_chats_password_title", "Qulflangan chatlar"}, {"locked_chats_enter_password", "Qulflangan chatlarga kirish uchun parolni kiriting"},
        {"password_6_digits", "Parol 6 raqamdan iborat bo'lishi kerak"}, {"password_incorrect", "Noto'g'ri parol"}, {"no_master_password", "Parol o'rnatilmagan"},
        {"locked_chats_password", "Qulflangan chatlar paroli"}, {"no_password", "Sizda parol yo'q"}, {"change_password", "Parolni o'zgartirish"},
        {"old_password", "Eski parol"}, {"new_password", "Yangi parol"}, {"confirm_password", "Yangi parolni tasdiqlang"}, {"change", "O'zgartirish"},
        {"old_password_incorrect", "Eski parol noto'g'ri"}, {"passwords_dont_match", "Yangi parollar mos kelmaydi"},
        {"no_locked_chats", "Qulflangan chatlar yo'q"}, {"locked_chats_hint", "Chatni qulflash uchun 3 nuqta menyusidan 'Chatni qulflash'ni tanlang"}, {"enter", "Kirish"}
    };
    m_translations["Uzbek"].insert(QStringLiteral("media_image"), QStringLiteral("Rasm"));
    m_translations["Uzbek"].insert(QStringLiteral("media_video"), QStringLiteral("Video"));
    m_translations["Uzbek"].insert(QStringLiteral("media_voice"), QStringLiteral("Ovozli xabar"));
    m_translations["Uzbek"].insert(QStringLiteral("media_audio"), QStringLiteral("Audio"));
    m_translations["Uzbek"].insert(QStringLiteral("media_sticker"), QStringLiteral("Stiker"));
    m_translations["Uzbek"].insert(QStringLiteral("media_document"), QStringLiteral("Hujjat"));
    m_translations["Uzbek"].insert(QStringLiteral("media_unavailable"), QStringLiteral("Media mavjud emas"));
    m_translations["Uzbek"].insert(QStringLiteral("tap_to_open"), QStringLiteral("Ochish uchun bosing"));
    m_translations["Uzbek"].insert(QStringLiteral("location"), QStringLiteral("Joylashuv"));
    m_translations["Uzbek"].insert(QStringLiteral("contact"), QStringLiteral("Kontakt"));
    m_translations["Uzbek"].insert(QStringLiteral("favorites"), QStringLiteral("Sevimlilar"));
    m_translations["Uzbek"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("Sevimlilarga qo'shish"));
    m_translations["Uzbek"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("Sevimlilardan o'chirish"));
    m_translations["Uzbek"].insert(QStringLiteral("no_favorites"), QStringLiteral("Sevimlilar yo'q"));
    m_translations["Uzbek"].insert(QStringLiteral("favorites_hint"), QStringLiteral("Sevimlilarga qo'shish uchun xabarga o'ng tugmani bosing"));
    m_translations["Uzbek"].insert(QStringLiteral("media_browser"), QStringLiteral("Media"));
    m_translations["Uzbek"].insert(QStringLiteral("media_browser_title"), QStringLiteral("Media"));
    m_translations["Uzbek"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("Rasmlar, videolar va fayllar"));
    m_translations["Uzbek"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("Rasmlar"));
    m_translations["Uzbek"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("Videolar"));
    m_translations["Uzbek"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("Hujjatlar"));
    m_translations["Uzbek"].insert(QStringLiteral("media_browser_links"), QStringLiteral("Havolalar"));
    m_translations["Uzbek"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("Joylar"));
    m_translations["Uzbek"].insert(QStringLiteral("no_photos_found"), QStringLiteral("Rasm topilmadi"));
    m_translations["Uzbek"].insert(QStringLiteral("no_videos_found"), QStringLiteral("Video topilmadi"));
    m_translations["Uzbek"].insert(QStringLiteral("no_documents_found"), QStringLiteral("Hujjat topilmadi"));
    m_translations["Uzbek"].insert(QStringLiteral("no_links_found"), QStringLiteral("Havola topilmadi"));
    m_translations["Uzbek"].insert(QStringLiteral("no_locations_found"), QStringLiteral("Joy topilmadi"));
    m_translations["Uzbek"].insert(QStringLiteral("profile_library"), QStringLiteral("Profil kutubxonasi"));
    m_translations["Uzbek"].insert(QStringLiteral("add_profile"), QStringLiteral("Profil qo'shish"));
    m_translations["Uzbek"].insert(QStringLiteral("profile_name_label"), QStringLiteral("Profil nomi"));
    m_translations["Uzbek"].insert(QStringLiteral("add_btn"), QStringLiteral("Qo'shish"));
    m_translations["Uzbek"].insert(QStringLiteral("optional"), QStringLiteral("Ixtiyoriy"));
    m_translations["Uzbek"].insert(QStringLiteral("image_selected"), QStringLiteral("Rasm tanlandi"));
    m_translations["Uzbek"].insert(QStringLiteral("no_profiles_library"), QStringLiteral("Saqlangan profillar yo'q"));
    m_translations["Uzbek"].insert(QStringLiteral("profile_owner_conflict"), QStringLiteral("Standart egasi nomi bilan bir xil nomli profil qo'shib bo'lmaydi"));
    m_translations["Uzbek"].insert(QStringLiteral("profile_exists"), QStringLiteral("Bu nomdagi profil allaqachon mavjud"));
    m_translations["Uzbek"].insert(QStringLiteral("message_count_text"), QStringLiteral("xabar"));
    m_translations["Uzbek"].insert(QStringLiteral("january"), QStringLiteral("Yan"));
    m_translations["Uzbek"].insert(QStringLiteral("february"), QStringLiteral("Fev"));
    m_translations["Uzbek"].insert(QStringLiteral("march"), QStringLiteral("Mar"));
    m_translations["Uzbek"].insert(QStringLiteral("april"), QStringLiteral("Apr"));
    m_translations["Uzbek"].insert(QStringLiteral("may"), QStringLiteral("May"));
    m_translations["Uzbek"].insert(QStringLiteral("june"), QStringLiteral("Iyun"));
    m_translations["Uzbek"].insert(QStringLiteral("july"), QStringLiteral("Iyul"));
    m_translations["Uzbek"].insert(QStringLiteral("august"), QStringLiteral("Avg"));
    m_translations["Uzbek"].insert(QStringLiteral("september"), QStringLiteral("Sen"));
    m_translations["Uzbek"].insert(QStringLiteral("october"), QStringLiteral("Okt"));
    m_translations["Uzbek"].insert(QStringLiteral("november"), QStringLiteral("Noya"));
    m_translations["Uzbek"].insert(QStringLiteral("december"), QStringLiteral("Dek"));
    m_translations["Uzbek"].insert(QStringLiteral("calendar_tooltip"), QStringLiteral("Sanaga o'tish"));
    m_translations["Uzbek"].insert(QStringLiteral("last_message"), QStringLiteral("Oxirgi xabar"));
    m_translations["Uzbek"].insert(QStringLiteral("settings"), QStringLiteral("Sozlamalar"));
    m_translations["Uzbek"].insert(QStringLiteral("auto_play_next_voice"), QStringLiteral("Ketma-ket ovozli xabarlarni avtomatik ijro etish"));

    // Afrikaans
    m_translations["Afrikaans"] = {
        {"contact_info", "Kontakinligting"}, {"msg_count", "Aantal boodskappe"}, {"messages", "boodskappe"}, {"import_date", "Invoerdatum"},
        {"no_chats", "Geen kletse gevind nie\n\nKlik + om 'n nuwe\nklets by te voeg"}, {"light_theme", "Ligte tema"}, {"dark_theme", "Donker tema"},
        {"new_chat_tooltip", "Voeg nuwe klets by"}, {"chat_search_placeholder", "Soek in kletse"}, {"importing", "Besig om in te voer..."},
        {"bulk_select_tooltip", "Bulk keuse"}, {"bulk_delete_tooltip", "Bulk uitvee"}, {"cancel_selection_tooltip", "Kanselleer"},
        {"import_new", "Voeg nuwe klets by"}, {"zip_description", "Kies die ZIP-lêer wat van WhatsApp uitgevoer is."},
        {"select_zip", "Kies ZIP-lêer"}, {"change_zip", "Verander lêer"}, {"continue", "Gaan voort"},
        {"owner_question", "Wat is jou naam in die klets?\n(Die naam wat in jou WhatsApp-rekening verskyn)"}, {"owner_placeholder", "Bv: Jan van der Merwe"},
        {"import_btn", "Voer in"}, {"back", "Terug"}, {"loading_messages", "Laai boodskappe, wag asseblief..."},
        {"select_zip_title", "Kies WhatsApp ZIP-lêer"}, {"first_message", "Eerste boodskap"}, {"delete_chat", "Vee klets uit"}, {"search", "Soek..."}, {"search_tooltip", "Soek in boodskappe (Ctrl+F)"},
        {"empty_chat_hint", "Kies 'n klets of voeg 'n nuwe een by"}, {"delete_confirm_title", "Vee klets uit"},
        {"delete_confirm_text", "Is jy seker jy wil hierdie klets uitvee?\nAlle boodskappe sal verwyder word."}, {"no_results", "Geen resultate gevind nie"},
        {"yes", "Ja"}, {"no", "Nee"}, {"cancel", "Kanselleer"}, {"language", "Taal"}, {"select_language", "Kies taal"}, {"profile_photo", "Profielfoto"},
        {"name_label", "Naam"}, {"participants_label", "Groep deelnemers"}, {"contact_name_placeholder", "Kontaknaam"}, {"image_files_filter", "Beeldlêers (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — %2 boodskappe ingevoer"}, {"conversation", "Gesprek"},
        {"default_owner_name", "Verstek eienaar naam"}, {"owner_name_placeholder", "Jou naam"}, {"not_set", "Nie ingestel nie"}, {"default_label", "Verstek"},
        {"profile_library", "Profiel biblioteek"}, {"add_profile", "Voeg profiel by"}, {"profile_name_label", "Naam:"}, {"add_btn", "Voeg by"},
        {"optional", "(Opsioneel)"}, {"image_selected", "✓ Gekies"}, {"no_profiles_library", "Nog geen profiele nie. Klik + om by te voeg."},
        {"profile_owner_conflict", "Kan nie profiel met dieselfde naam as eienaar byvoeg nie"}, {"profile_exists", "Profiel met hierdie naam bestaan reeds"},
        {"message_count_text", "boodskappe"},
        {"january", "Jan"}, {"february", "Feb"}, {"march", "Mrt"}, {"april", "Apr"}, {"may", "Mei"}, {"june", "Jun"},
        {"july", "Jul"}, {"august", "Aug"}, {"september", "Sep"}, {"october", "Okt"}, {"november", "Nov"}, {"december", "Des"},
        {"calendar_tooltip", "Spring na datum"},
        {"last_message", "Laaste boodskap"},
        {"settings", "Instellings"},
        {"auto_play_next_voice", "Speel opeenvolgende stem boodskappe outomaties"},
        {"open_system", "Maak oop in stelsel"}, {"image_not_found", "Beeld nie gevind nie"}, {"video", "Video"}, {"deleted_message", "Hierdie boodskap is uitgevee"}, {"you_deleted_message", "Jy het hierdie boodskap uitgevee"}, {"edited", "Geredigeer"}, {"app_version", "weergawe"}, {"app_copyright", "Kopiereg deur %1"},
        {"lock_chat", "Sluit klets"}, {"unlock_chat", "Ontsluit hierdie klets"}, {"locked_chats", "Geslote Kletse"}, {"locked_chats_access", "Toegang tot geslote kletse"},
        {"lock_chat_title", "Sluit klets"}, {"lock_chat_message", "Hierdie klets sal gesluit word"}, {"lock_chat_set_password", "Stel wagwoord in om kletse te sluit"},
        {"locked_chats_password_title", "Geslote kletse"}, {"locked_chats_enter_password", "Voer wagwoord in om toegang tot geslote kletse te kry"},
        {"password_6_digits", "Wagwoord moet 6 syfers wees"}, {"password_incorrect", "Verkeerde wagwoord"}, {"no_master_password", "Geen wagwoord ingestel nie"},
        {"locked_chats_password", "Geslote Kletse Wagwoord"}, {"no_password", "Jy het nie 'n wagwoord nie"}, {"change_password", "Verander wagwoord"},
        {"old_password", "Ou wagwoord"}, {"new_password", "Nuwe wagwoord"}, {"confirm_password", "Bevestig nuwe wagwoord"}, {"change", "Verander"},
        {"old_password_incorrect", "Ou wagwoord is verkeerd"}, {"passwords_dont_match", "Nuwe wagwoorde stem nie ooreen nie"},
        {"no_locked_chats", "Geen geslote kletse nie"}, {"locked_chats_hint", "Kies 'Sluit klets' uit die 3-kolletjie kieslys om 'n klets te sluit"}, {"enter", "Gaan in"}
    };
    m_translations["Afrikaans"].insert(QStringLiteral("media_image"), QStringLiteral("Foto"));
    m_translations["Afrikaans"].insert(QStringLiteral("media_video"), QStringLiteral("Video"));
    m_translations["Afrikaans"].insert(QStringLiteral("media_voice"), QStringLiteral("Stem boodskap"));
    m_translations["Afrikaans"].insert(QStringLiteral("media_audio"), QStringLiteral("Oudio"));
    m_translations["Afrikaans"].insert(QStringLiteral("media_sticker"), QStringLiteral("Plakker"));
    m_translations["Afrikaans"].insert(QStringLiteral("media_document"), QStringLiteral("Dokument"));
    m_translations["Afrikaans"].insert(QStringLiteral("media_unavailable"), QStringLiteral("Media nie beskikbaar nie"));
    m_translations["Afrikaans"].insert(QStringLiteral("tap_to_open"), QStringLiteral("Tik om oop te maak"));
    m_translations["Afrikaans"].insert(QStringLiteral("location"), QStringLiteral("Ligging"));
    m_translations["Afrikaans"].insert(QStringLiteral("contact"), QStringLiteral("Kontak"));
    m_translations["Afrikaans"].insert(QStringLiteral("favorites"), QStringLiteral("Gunstelinge"));
    m_translations["Afrikaans"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("Voeg by gunstelinge"));
    m_translations["Afrikaans"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("Verwyder uit gunstelinge"));
    m_translations["Afrikaans"].insert(QStringLiteral("no_favorites"), QStringLiteral("Geen gunstelinge nie"));
    m_translations["Afrikaans"].insert(QStringLiteral("favorites_hint"), QStringLiteral("Regsklik 'n boodskap om by gunstelinge te voeg"));
    m_translations["Afrikaans"].insert(QStringLiteral("media_browser"), QStringLiteral("Media"));
    m_translations["Afrikaans"].insert(QStringLiteral("media_browser_title"), QStringLiteral("Media"));
    m_translations["Afrikaans"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("Foto's, video's en lêers"));
    m_translations["Afrikaans"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("Foto's"));
    m_translations["Afrikaans"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("Video's"));
    m_translations["Afrikaans"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("Dokumente"));
    m_translations["Afrikaans"].insert(QStringLiteral("media_browser_links"), QStringLiteral("Skakels"));
    m_translations["Afrikaans"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("Liggings"));
    m_translations["Afrikaans"].insert(QStringLiteral("no_photos_found"), QStringLiteral("Geen foto's gevind nie"));
    m_translations["Afrikaans"].insert(QStringLiteral("no_videos_found"), QStringLiteral("Geen video's gevind nie"));
    m_translations["Afrikaans"].insert(QStringLiteral("no_documents_found"), QStringLiteral("Geen dokumente gevind nie"));
    m_translations["Afrikaans"].insert(QStringLiteral("no_links_found"), QStringLiteral("Geen skakels gevind nie"));
    m_translations["Afrikaans"].insert(QStringLiteral("no_locations_found"), QStringLiteral("Geen liggings gevind nie"));

    // Albanian
    m_translations["Albanian"] = {
        {"contact_info", "Informacion kontakti"}, {"msg_count", "Numri i mesazheve"}, {"messages", "mesazhe"}, {"import_date", "Data e importimit"},
        {"no_chats", "Nuk u gjetën biseda\n\nKliko + për të shtuar\nnjë bisedë të re"}, {"light_theme", "Temë e ndriçuar"}, {"dark_theme", "Temë e errët"},
        {"new_chat_tooltip", "Shto bisedë të re"}, {"chat_search_placeholder", "Kërko në biseda"}, {"importing", "Duke importuar..."},
        {"bulk_select_tooltip", "Zgjedhje në masë"}, {"bulk_delete_tooltip", "Fshije në masë"}, {"cancel_selection_tooltip", "Anulo"},
        {"import_new", "Shto bisedë të re"}, {"zip_description", "Zgjidh skedarin ZIP të eksportuar nga WhatsApp."},
        {"select_zip", "Zgjidh skedar ZIP"}, {"change_zip", "Ndrysho skedar"}, {"continue", "Vazhdo"},
        {"owner_question", "Cili është emri juaj në bisedë?\n(Emri që shfaqet në llogarinë tuaj WhatsApp)"}, {"owner_placeholder", "Shembull: Arben Hoxha"},
        {"import_btn", "Importo"}, {"back", "Prapa"}, {"loading_messages", "Duke ngarkuar mesazhe, ju lutemi prisni..."},
        {"select_zip_title", "Zgjidh skedar ZIP WhatsApp"}, {"first_message", "Mesazhi i parë"}, {"delete_chat", "Fshi bisedën"}, {"search", "Kërko..."}, {"search_tooltip", "Kërko në mesazhe (Ctrl+F)"},
        {"empty_chat_hint", "Zgjidh një bisedë ose shto një të re"}, {"delete_confirm_title", "Fshi bisedën"},
        {"delete_confirm_text", "Jeni i sigurt që dëshironi të fshini këtë bisedë?\nTë gjitha mesazhet do të hiqen."}, {"no_results", "Nuk u gjetën rezultate"},
        {"yes", "Po"}, {"no", "Jo"}, {"cancel", "Anulo"}, {"language", "Gjuha"}, {"select_language", "Zgjidh gjuhën"}, {"profile_photo", "Foto profili"},
        {"name_label", "Emri"}, {"participants_label", "Pjesëmarrësit e grupit"}, {"contact_name_placeholder", "Emri i kontaktit"}, {"image_files_filter", "Skedarë imazhi (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — %2 mesazhe u importuan"}, {"conversation", "Bisedë"},
        {"default_owner_name", "Emri i Pronarit të Paracaktuar"}, {"owner_name_placeholder", "Emri juaj"}, {"not_set", "Nuk është vendosur"}, {"default_label", "I paracaktuar"},
        {"profile_library", "Libraria e Profilëve"}, {"add_profile", "Shto Profil"}, {"profile_name_label", "Emri:"}, {"add_btn", "Shto"},
        {"optional", "(Opsionale)"}, {"image_selected", "✓ U zgjodh"}, {"no_profiles_library", "Ende pa profile. Kliko + për të shtuar."},
        {"profile_owner_conflict", "Nuk mund të shtohet profil me të njëjtin emër si pronari"}, {"profile_exists", "Profili me këtë emër ekziston tashmë"},
        {"message_count_text", "mesazhe"},
        {"january", "Jan"}, {"february", "Shk"}, {"march", "Mar"}, {"april", "Pri"}, {"may", "Maj"}, {"june", "Qer"},
        {"july", "Kor"}, {"august", "Gsh"}, {"september", "Sht"}, {"october", "Tet"}, {"november", "Nën"}, {"december", "Dhj"},
        {"calendar_tooltip", "Kalo tek data"},
        {"last_message", "Mesazhi i fundit"},
        {"settings", "Cilësimet"},
        {"auto_play_next_voice", "Luaj automatikisht mesazhet zanore sekuenciale"},
        {"open_system", "Hap në sistem"}, {"image_not_found", "Imazhi nuk u gjet"}, {"video", "Video"}, {"deleted_message", "Ky mesazh u fshi"}, {"you_deleted_message", "Ju fshitë këtë mesazh"}, {"edited", "E redaktuar"}, {"app_version", "versioni"}, {"app_copyright", "Të drejtat e autorit nga %1"},
        {"lock_chat", "Kyç bisedën"}, {"unlock_chat", "Shkyç këtë bisedë"}, {"locked_chats", "Bisedat e Kyçura"}, {"locked_chats_access", "Qasje në bisedat e kyçura"},
        {"lock_chat_title", "Kyç bisedën"}, {"lock_chat_message", "Kjo bisedë do të kyçet"}, {"lock_chat_set_password", "Vendos fjalëkalim për të kyçur bisedat"},
        {"locked_chats_password_title", "Bisedat e kyçura"}, {"locked_chats_enter_password", "Fut fjalëkalimin për të hyrë në bisedat e kyçura"},
        {"password_6_digits", "Fjalëkalimi duhet të jetë 6 shifra"}, {"password_incorrect", "Fjalëkalim i gabuar"}, {"no_master_password", "Nuk është vendosur fjalëkalim"},
        {"locked_chats_password", "Fjalëkalimi i Bisedave të Kyçura"}, {"no_password", "Ju nuk keni fjalëkalim"}, {"change_password", "Ndrysho fjalëkalimin"},
        {"old_password", "Fjalëkalimi i vjetër"}, {"new_password", "Fjalëkalimi i ri"}, {"confirm_password", "Konfirmo fjalëkalimin e ri"}, {"change", "Ndrysho"},
        {"old_password_incorrect", "Fjalëkalimi i vjetër është i gabuar"}, {"passwords_dont_match", "Fjalëkalimet e reja nuk përputhen"},
        {"no_locked_chats", "Nuk ka biseda të kyçura"}, {"locked_chats_hint", "Zgjidh 'Kyç bisedën' nga menyja me 3 pika për të kyçur një bisedë"}, {"enter", "Hyr"}
    };
    m_translations["Albanian"].insert(QStringLiteral("media_image"), QStringLiteral("Foto"));
    m_translations["Albanian"].insert(QStringLiteral("media_video"), QStringLiteral("Video"));
    m_translations["Albanian"].insert(QStringLiteral("media_voice"), QStringLiteral("Mesazh zanor"));
    m_translations["Albanian"].insert(QStringLiteral("media_audio"), QStringLiteral("Audio"));
    m_translations["Albanian"].insert(QStringLiteral("media_sticker"), QStringLiteral("Ngjitëse"));
    m_translations["Albanian"].insert(QStringLiteral("media_document"), QStringLiteral("Dokument"));
    m_translations["Albanian"].insert(QStringLiteral("media_unavailable"), QStringLiteral("Media e padisponueshme"));
    m_translations["Albanian"].insert(QStringLiteral("tap_to_open"), QStringLiteral("Trokit për të hapur"));
    m_translations["Albanian"].insert(QStringLiteral("location"), QStringLiteral("Vendndodhja"));
    m_translations["Albanian"].insert(QStringLiteral("contact"), QStringLiteral("Kontakt"));
    m_translations["Albanian"].insert(QStringLiteral("favorites"), QStringLiteral("Të preferuarat"));
    m_translations["Albanian"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("Shto te të preferuarat"));
    m_translations["Albanian"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("Hiq nga të preferuarat"));
    m_translations["Albanian"].insert(QStringLiteral("no_favorites"), QStringLiteral("Nuk ka të preferuara"));
    m_translations["Albanian"].insert(QStringLiteral("favorites_hint"), QStringLiteral("Kliko djathtas një mesazh për ta shtuar te të preferuarat"));
    m_translations["Albanian"].insert(QStringLiteral("media_browser"), QStringLiteral("Media"));
    m_translations["Albanian"].insert(QStringLiteral("media_browser_title"), QStringLiteral("Media"));
    m_translations["Albanian"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("Foto, video dhe skedarë"));
    m_translations["Albanian"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("Foto"));
    m_translations["Albanian"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("Video"));
    m_translations["Albanian"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("Dokumente"));
    m_translations["Albanian"].insert(QStringLiteral("media_browser_links"), QStringLiteral("Lidhje"));
    m_translations["Albanian"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("Vendndodhje"));
    m_translations["Albanian"].insert(QStringLiteral("no_photos_found"), QStringLiteral("Nuk u gjetën foto"));
    m_translations["Albanian"].insert(QStringLiteral("no_videos_found"), QStringLiteral("Nuk u gjetën video"));
    m_translations["Albanian"].insert(QStringLiteral("no_documents_found"), QStringLiteral("Nuk u gjetën dokumente"));
    m_translations["Albanian"].insert(QStringLiteral("no_links_found"), QStringLiteral("Nuk u gjetën lidhje"));
    m_translations["Albanian"].insert(QStringLiteral("no_locations_found"), QStringLiteral("Nuk u gjetën vendndodhje"));

    // Bengali
    m_translations["Bengali"] = {
        {"contact_info", "যোগাযোগের তথ্য"}, {"msg_count", "বার্তার সংখ্যা"}, {"messages", "বার্তা"}, {"import_date", "আমদানির তারিখ"},
        {"no_chats", "কোনো চ্যাট পাওয়া যায়নি\n\nনতুন চ্যাট যোগ করতে\n+ ক্লিক করুন"}, {"light_theme", "হালকা থিম"}, {"dark_theme", "অন্ধকার থিম"},
        {"new_chat_tooltip", "নতুন চ্যাট যোগ করুন"}, {"chat_search_placeholder", "চ্যাটে খুঁজুন"}, {"importing", "আমদানি করা হচ্ছে..."},
        {"bulk_select_tooltip", "একাধিক নির্বাচন"}, {"bulk_delete_tooltip", "একাধিক মুছুন"}, {"cancel_selection_tooltip", "বাতিল করুন"},
        {"import_new", "নতুন চ্যাট যোগ করুন"}, {"zip_description", "WhatsApp থেকে রপ্তানি করা ZIP ফাইল নির্বাচন করুন।"},
        {"select_zip", "ZIP ফাইল নির্বাচন করুন"}, {"change_zip", "ফাইল পরিবর্তন করুন"}, {"continue", "চালিয়ে যান"},
        {"owner_question", "চ্যাটে আপনার নাম কী?\n(আপনার WhatsApp অ্যাকাউন্টে প্রদর্শিত নাম)"}, {"owner_placeholder", "উদাহরণ: রহিম আহমেদ"},
        {"import_btn", "আমদানি করুন"}, {"back", "পিছনে"}, {"loading_messages", "বার্তা লোড হচ্ছে, অনুগ্রহ করে অপেক্ষা করুন..."},
        {"select_zip_title", "WhatsApp ZIP ফাইল নির্বাচন করুন"}, {"first_message", "প্রথম বার্তা"}, {"delete_chat", "চ্যাট মুছুন"}, {"search", "খুঁজুন..."}, {"search_tooltip", "বার্তায় খুঁজুন (Ctrl+F)"},
        {"empty_chat_hint", "একটি চ্যাট নির্বাচন করুন বা নতুন যোগ করুন"}, {"delete_confirm_title", "চ্যাট মুছুন"},
        {"delete_confirm_text", "আপনি কি নিশ্চিত যে এই চ্যাট মুছে ফেলতে চান?\nসমস্ত বার্তা সরানো হবে।"}, {"no_results", "কোনো ফলাফল পাওয়া যায়নি"},
        {"yes", "হ্যাঁ"}, {"no", "না"}, {"cancel", "বাতিল করুন"}, {"language", "ভাষা"}, {"select_language", "ভাষা নির্বাচন করুন"}, {"profile_photo", "প্রোফাইল ছবি"},
        {"name_label", "নাম"}, {"participants_label", "গ্রুপ অংশগ্রহণকারীরা"}, {"contact_name_placeholder", "যোগাযোগের নাম"}, {"image_files_filter", "চিত্র ফাইল (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — %2 বার্তা আমদানি করা হয়েছে"}, {"conversation", "কথোপকথন"},
        {"default_owner_name", "ডিফল্ট মালিকের নাম"}, {"owner_name_placeholder", "আপনার নাম"}, {"not_set", "সেট করা নেই"}, {"default_label", "ডিফল্ট"},
        {"profile_library", "প্রোফাইল লাইব্রেরি"}, {"add_profile", "প্রোফাইল যোগ করুন"}, {"profile_name_label", "নাম:"}, {"add_btn", "যোগ করুন"},
        {"optional", "(ঐচ্ছিক)"}, {"image_selected", "✓ নির্বাচিত"}, {"no_profiles_library", "এখনও কোনো প্রোফাইল নেই। যোগ করতে + ক্লিক করুন।"},
        {"profile_owner_conflict", "মালিকের নামের মতো একই নামের প্রোফাইল যোগ করা যাবে না"}, {"profile_exists", "এই নামের প্রোফাইল ইতিমধ্যে বিদ্যমান"},
        {"message_count_text", "বার্তা"},
        {"january", "জানু"}, {"february", "ফেব্রু"}, {"march", "মার্চ"}, {"april", "এপ্রিল"}, {"may", "মে"}, {"june", "জুন"},
        {"july", "জুলাই"}, {"august", "আগস্ট"}, {"september", "সেপ্টে"}, {"october", "অক্টো"}, {"november", "নভে"}, {"december", "ডিসে"},
        {"calendar_tooltip", "তারিখে যান"},
        {"last_message", "শেষ বার্তা"},
        {"settings", "সেটিংস"},
        {"auto_play_next_voice", "পরপর ভয়েস বার্তা স্বয়ংক্রিয়ভাবে চালান"},
        {"open_system", "সিস্টেমে খুলুন"}, {"image_not_found", "ছবি পাওয়া যায়নি"}, {"video", "ভিডিও"}, {"deleted_message", "এই বার্তাটি মুছে ফেলা হয়েছে"}, {"you_deleted_message", "আপনি এই বার্তাটি মুছে ফেলেছেন"}, {"edited", "সম্পাদিত"}, {"app_version", "সংস্করণ"}, {"app_copyright", "কপিরাইট %1 দ্বারা"},
        {"lock_chat", "চ্যাট লক করুন"}, {"unlock_chat", "এই চ্যাট আনলক করুন"}, {"locked_chats", "লক করা চ্যাট"}, {"locked_chats_access", "লক করা চ্যাট অ্যাক্সেস করুন"},
        {"lock_chat_title", "চ্যাট লক করুন"}, {"lock_chat_message", "এই চ্যাটটি লক করা হবে"}, {"lock_chat_set_password", "চ্যাট লক করতে পাসওয়ার্ড সেট করুন"},
        {"locked_chats_password_title", "লক করা চ্যাট"}, {"locked_chats_enter_password", "লক করা চ্যাট অ্যাক্সেস করতে পাসওয়ার্ড লিখুন"},
        {"password_6_digits", "পাসওয়ার্ড 6 সংখ্যার হতে হবে"}, {"password_incorrect", "ভুল পাসওয়ার্ড"}, {"no_master_password", "কোনো পাসওয়ার্ড সেট করা নেই"},
        {"locked_chats_password", "লক করা চ্যাট পাসওয়ার্ড"}, {"no_password", "আপনার কোনো পাসওয়ার্ড নেই"}, {"change_password", "পাসওয়ার্ড পরিবর্তন করুন"},
        {"old_password", "পুরাতন পাসওয়ার্ড"}, {"new_password", "নতুন পাসওয়ার্ড"}, {"confirm_password", "নতুন পাসওয়ার্ড নিশ্চিত করুন"}, {"change", "পরিবর্তন করুন"},
        {"old_password_incorrect", "পুরাতন পাসওয়ার্ড ভুল"}, {"passwords_dont_match", "নতুন পাসওয়ার্ড মিলছে না"},
        {"no_locked_chats", "কোনো লক করা চ্যাট নেই"}, {"locked_chats_hint", "একটি চ্যাট লক করতে 3-বিন্দু মেনু থেকে 'চ্যাট লক করুন' নির্বাচন করুন"}, {"enter", "প্রবেশ করুন"}
    };
    m_translations["Bengali"].insert(QStringLiteral("media_image"), QStringLiteral("ছবি"));
    m_translations["Bengali"].insert(QStringLiteral("media_video"), QStringLiteral("ভিডিও"));
    m_translations["Bengali"].insert(QStringLiteral("media_voice"), QStringLiteral("ভয়েস বার্তা"));
    m_translations["Bengali"].insert(QStringLiteral("media_audio"), QStringLiteral("অডিও"));
    m_translations["Bengali"].insert(QStringLiteral("media_sticker"), QStringLiteral("স্টিকার"));
    m_translations["Bengali"].insert(QStringLiteral("media_document"), QStringLiteral("নথি"));
    m_translations["Bengali"].insert(QStringLiteral("media_unavailable"), QStringLiteral("মিডিয়া উপলব্ধ নেই"));
    m_translations["Bengali"].insert(QStringLiteral("tap_to_open"), QStringLiteral("খুলতে ট্যাপ করুন"));
    m_translations["Bengali"].insert(QStringLiteral("location"), QStringLiteral("অবস্থান"));
    m_translations["Bengali"].insert(QStringLiteral("contact"), QStringLiteral("যোগাযোগ"));
    m_translations["Bengali"].insert(QStringLiteral("favorites"), QStringLiteral("প্রিয়"));
    m_translations["Bengali"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("প্রিয়তে যোগ করুন"));
    m_translations["Bengali"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("প্রিয় থেকে সরান"));
    m_translations["Bengali"].insert(QStringLiteral("no_favorites"), QStringLiteral("কোনো প্রিয় নেই"));
    m_translations["Bengali"].insert(QStringLiteral("favorites_hint"), QStringLiteral("প্রিয়তে যোগ করতে একটি বার্তায় রাইট-ক্লিক করুন"));
    m_translations["Bengali"].insert(QStringLiteral("media_browser"), QStringLiteral("মিডিয়া"));
    m_translations["Bengali"].insert(QStringLiteral("media_browser_title"), QStringLiteral("মিডিয়া"));
    m_translations["Bengali"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("ছবি, ভিডিও এবং ফাইল"));
    m_translations["Bengali"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("ছবি"));
    m_translations["Bengali"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("ভিডিও"));
    m_translations["Bengali"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("নথি"));
    m_translations["Bengali"].insert(QStringLiteral("media_browser_links"), QStringLiteral("লিঙ্ক"));
    m_translations["Bengali"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("অবস্থান"));
    m_translations["Bengali"].insert(QStringLiteral("no_photos_found"), QStringLiteral("কোনো ছবি পাওয়া যায়নি"));
    m_translations["Bengali"].insert(QStringLiteral("no_videos_found"), QStringLiteral("কোনো ভিডিও পাওয়া যায়নি"));
    m_translations["Bengali"].insert(QStringLiteral("no_documents_found"), QStringLiteral("কোনো নথি পাওয়া যায়নি"));
    m_translations["Bengali"].insert(QStringLiteral("no_links_found"), QStringLiteral("কোনো লিঙ্ক পাওয়া যায়নি"));
    m_translations["Bengali"].insert(QStringLiteral("no_locations_found"), QStringLiteral("কোনো অবস্থান পাওয়া যায়নি"));

    // Bulgarian
    m_translations["Bulgarian"] = {
        {"contact_info", "Информация за контакт"}, {"msg_count", "Брой съобщения"}, {"messages", "съобщения"}, {"import_date", "Дата на импортиране"},
        {"no_chats", "Няма намерени чатове\n\nКликнете + за да добавите\nнов чат"}, {"light_theme", "Светла тема"}, {"dark_theme", "Тъмна тема"},
        {"new_chat_tooltip", "Добавяне на нов чат"}, {"chat_search_placeholder", "Търсене в чатовете"}, {"importing", "Импортиране..."},
        {"bulk_select_tooltip", "Множествен избор"}, {"bulk_delete_tooltip", "Множествено изтриване"}, {"cancel_selection_tooltip", "Отказ"},
        {"import_new", "Добавяне на нов чат"}, {"zip_description", "Изберете ZIP файла, експортиран от WhatsApp."},
        {"select_zip", "Избор на ZIP файл"}, {"change_zip", "Промяна на файла"}, {"continue", "Продължи"},
        {"owner_question", "Как е вашето име в чата?\n(Името, което се показва във вашия WhatsApp акаунт)"}, {"owner_placeholder", "Напр.: Иван Петров"},
        {"import_btn", "Импортиране"}, {"back", "Назад"}, {"loading_messages", "Зареждане на съобщения, моля изчакайте..."},
        {"select_zip_title", "Изберете WhatsApp ZIP файл"}, {"first_message", "Първо съобщение"}, {"delete_chat", "Изтриване на чат"}, {"search", "Търсене..."}, {"search_tooltip", "Търсене в съобщенията (Ctrl+F)"},
        {"empty_chat_hint", "Изберете чат или добавете нов"}, {"delete_confirm_title", "Изтриване на чат"},
        {"delete_confirm_text", "Сигурни ли сте, че искате да изтриете този чат?\nВсички съобщения ще бъдат премахнати."}, {"no_results", "Няма намерени резултати"},
        {"yes", "Да"}, {"no", "Не"}, {"cancel", "Отказ"}, {"language", "Език"}, {"select_language", "Избор на език"}, {"profile_photo", "Профилна снимка"},
        {"name_label", "Име"}, {"participants_label", "Участници в групата"}, {"contact_name_placeholder", "Име на контакт"}, {"image_files_filter", "Изображения (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — %2 съобщения импортирани"}, {"conversation", "Разговор"},
        {"default_owner_name", "Име на собственика по подразбиране"}, {"owner_name_placeholder", "Вашето име"}, {"not_set", "Не е зададено"}, {"default_label", "По подразбиране"},
        {"profile_library", "Библиотека с профили"}, {"add_profile", "Добавяне на профил"}, {"profile_name_label", "Име:"}, {"add_btn", "Добавяне"},
        {"optional", "(По избор)"}, {"image_selected", "✓ Избрано"}, {"no_profiles_library", "Все още няма профили. Кликнете + за добавяне."},
        {"profile_owner_conflict", "Не може да се добави профил със същото име като собственика"}, {"profile_exists", "Профил с това име вече съществува"},
        {"message_count_text", "съобщения"},
        {"january", "Яну"}, {"february", "Фев"}, {"march", "Мар"}, {"april", "Апр"}, {"may", "Май"}, {"june", "Юни"},
        {"july", "Юли"}, {"august", "Авг"}, {"september", "Сеп"}, {"october", "Окт"}, {"november", "Ное"}, {"december", "Дек"},
        {"calendar_tooltip", "Преминаване към дата"},
        {"last_message", "Последно съобщение"},
        {"settings", "Настройки"},
        {"auto_play_next_voice", "Автоматично възпроизвеждане на последователни гласови съобщения"},
        {"open_system", "Отваряне в системата"}, {"image_not_found", "Изображението не е намерено"}, {"video", "Видео"}, {"deleted_message", "Това съобщение беше изтрито"}, {"you_deleted_message", "Вие изтрихте това съобщение"}, {"edited", "Редактирано"}, {"app_version", "версия"}, {"app_copyright", "Авторски права от %1"},
        {"lock_chat", "Заключване на чат"}, {"unlock_chat", "Отключване на този чат"}, {"locked_chats", "Заключени чатове"}, {"locked_chats_access", "Достъп до заключени чатове"},
        {"lock_chat_title", "Заключване на чат"}, {"lock_chat_message", "Този чат ще бъде заключен"}, {"lock_chat_set_password", "Задайте парола за заключване на чатове"},
        {"locked_chats_password_title", "Заключени чатове"}, {"locked_chats_enter_password", "Въведете парола за достъп до заключени чатове"},
        {"password_6_digits", "Паролата трябва да е 6 цифри"}, {"password_incorrect", "Грешна парола"}, {"no_master_password", "Няма зададена парола"},
        {"locked_chats_password", "Парола за заключени чатове"}, {"no_password", "Нямате парола"}, {"change_password", "Промяна на паролата"},
        {"old_password", "Стара парола"}, {"new_password", "Нова парола"}, {"confirm_password", "Потвърдете новата парола"}, {"change", "Промяна"},
        {"old_password_incorrect", "Старата парола е грешна"}, {"passwords_dont_match", "Новите пароли не съвпадат"},
        {"no_locked_chats", "Няма заключени чатове"}, {"locked_chats_hint", "Изберете 'Заключване на чат' от менюто с 3 точки, за да заключите чат"}, {"enter", "Влизане"}
    };
    m_translations["Bulgarian"].insert(QStringLiteral("media_image"), QStringLiteral("Снимка"));
    m_translations["Bulgarian"].insert(QStringLiteral("media_video"), QStringLiteral("Видео"));
    m_translations["Bulgarian"].insert(QStringLiteral("media_voice"), QStringLiteral("Гласово съобщение"));
    m_translations["Bulgarian"].insert(QStringLiteral("media_audio"), QStringLiteral("Аудио"));
    m_translations["Bulgarian"].insert(QStringLiteral("media_sticker"), QStringLiteral("Стикер"));
    m_translations["Bulgarian"].insert(QStringLiteral("media_document"), QStringLiteral("Документ"));
    m_translations["Bulgarian"].insert(QStringLiteral("media_unavailable"), QStringLiteral("Медията не е налична"));
    m_translations["Bulgarian"].insert(QStringLiteral("tap_to_open"), QStringLiteral("Докоснете за отваряне"));
    m_translations["Bulgarian"].insert(QStringLiteral("location"), QStringLiteral("Местоположение"));
    m_translations["Bulgarian"].insert(QStringLiteral("contact"), QStringLiteral("Контакт"));
    m_translations["Bulgarian"].insert(QStringLiteral("favorites"), QStringLiteral("Любими"));
    m_translations["Bulgarian"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("Добавяне към любими"));
    m_translations["Bulgarian"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("Премахване от любими"));
    m_translations["Bulgarian"].insert(QStringLiteral("no_favorites"), QStringLiteral("Няма любими"));
    m_translations["Bulgarian"].insert(QStringLiteral("favorites_hint"), QStringLiteral("Кликнете с десния бутон на съобщение, за да добавите към любими"));
    m_translations["Bulgarian"].insert(QStringLiteral("media_browser"), QStringLiteral("Медия"));
    m_translations["Bulgarian"].insert(QStringLiteral("media_browser_title"), QStringLiteral("Медия"));
    m_translations["Bulgarian"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("Снимки, видеа и файлове"));
    m_translations["Bulgarian"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("Снимки"));
    m_translations["Bulgarian"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("Видеа"));
    m_translations["Bulgarian"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("Документи"));
    m_translations["Bulgarian"].insert(QStringLiteral("media_browser_links"), QStringLiteral("Връзки"));
    m_translations["Bulgarian"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("Местоположения"));
    m_translations["Bulgarian"].insert(QStringLiteral("no_photos_found"), QStringLiteral("Няма намерени снимки"));
    m_translations["Bulgarian"].insert(QStringLiteral("no_videos_found"), QStringLiteral("Няма намерени видеа"));
    m_translations["Bulgarian"].insert(QStringLiteral("no_documents_found"), QStringLiteral("Няма намерени документи"));
    m_translations["Bulgarian"].insert(QStringLiteral("no_links_found"), QStringLiteral("Няма намерени връзки"));
    m_translations["Bulgarian"].insert(QStringLiteral("no_locations_found"), QStringLiteral("Няма намерени местоположения"));

    // Catalan
    m_translations["Catalan"] = {
        {"contact_info", "Informació de contacte"}, {"msg_count", "Nombre de missatges"}, {"messages", "missatges"}, {"import_date", "Data d'importació"},
        {"no_chats", "No s'han trobat xats\n\nFeu clic a + per afegir\nun xat nou"}, {"light_theme", "Tema clar"}, {"dark_theme", "Tema fosc"},
        {"new_chat_tooltip", "Afegir xat nou"}, {"chat_search_placeholder", "Cercar en xats"}, {"importing", "S'està important..."},
        {"bulk_select_tooltip", "Selecció múltiple"}, {"bulk_delete_tooltip", "Supressió múltiple"}, {"cancel_selection_tooltip", "Cancel·la"},
        {"import_new", "Afegir xat nou"}, {"zip_description", "Seleccioneu el fitxer ZIP exportat des de WhatsApp."},
        {"select_zip", "Seleccionar fitxer ZIP"}, {"change_zip", "Canviar fitxer"}, {"continue", "Continua"},
        {"owner_question", "Quin és el teu nom al xat?\n(El nom que apareix al teu compte de WhatsApp)"}, {"owner_placeholder", "Ex: Joan Garcia"},
        {"import_btn", "Importa"}, {"back", "Enrere"}, {"loading_messages", "S'estan carregant missatges, espereu..."},
        {"select_zip_title", "Seleccioneu fitxer ZIP de WhatsApp"}, {"first_message", "Primer missatge"}, {"delete_chat", "Suprimir xat"}, {"search", "Cercar..."}, {"search_tooltip", "Cercar en missatges (Ctrl+F)"},
        {"empty_chat_hint", "Seleccioneu un xat o afegiu-ne un de nou"}, {"delete_confirm_title", "Suprimir xat"},
        {"delete_confirm_text", "Esteu segur que voleu suprimir aquest xat?\nS'eliminaran tots els missatges."}, {"no_results", "No s'han trobat resultats"},
        {"yes", "Sí"}, {"no", "No"}, {"cancel", "Cancel·la"}, {"language", "Idioma"}, {"select_language", "Seleccionar idioma"}, {"profile_photo", "Foto de perfil"},
        {"name_label", "Nom"}, {"participants_label", "Participants del grup"}, {"contact_name_placeholder", "Nom del contacte"}, {"image_files_filter", "Fitxers d'imatge (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — %2 missatges importats"}, {"conversation", "Conversa"},
        {"default_owner_name", "Nom del propietari predeterminat"}, {"owner_name_placeholder", "El teu nom"}, {"not_set", "No establert"}, {"default_label", "Predeterminat"},
        {"profile_library", "Biblioteca de perfils"}, {"add_profile", "Afegir perfil"}, {"profile_name_label", "Nom:"}, {"add_btn", "Afegir"},
        {"optional", "(Opcional)"}, {"image_selected", "✓ Seleccionat"}, {"no_profiles_library", "Encara no hi ha perfils. Feu clic a + per afegir."},
        {"profile_owner_conflict", "No es pot afegir un perfil amb el mateix nom que el propietari"}, {"profile_exists", "Ja existeix un perfil amb aquest nom"},
        {"message_count_text", "missatges"},
        {"january", "Gen"}, {"february", "Febr"}, {"march", "Març"}, {"april", "Abr"}, {"may", "Maig"}, {"june", "Juny"},
        {"july", "Jul"}, {"august", "Ag"}, {"september", "Set"}, {"october", "Oct"}, {"november", "Nov"}, {"december", "Des"},
        {"calendar_tooltip", "Anar a la data"},
        {"last_message", "Últim missatge"},
        {"settings", "Configuració"},
        {"auto_play_next_voice", "Reproduir automàticament missatges de veu seqüencials"},
        {"open_system", "Obrir al sistema"}, {"image_not_found", "Imatge no trobada"}, {"video", "Vídeo"}, {"deleted_message", "Aquest missatge s'ha suprimit"}, {"you_deleted_message", "Heu suprimit aquest missatge"}, {"edited", "Editat"}, {"app_version", "versió"}, {"app_copyright", "Copyright de %1"},
        {"lock_chat", "Bloquejar xat"}, {"unlock_chat", "Desbloquejar aquest xat"}, {"locked_chats", "Xats bloquejats"}, {"locked_chats_access", "Accedir a xats bloquejats"},
        {"lock_chat_title", "Bloquejar xat"}, {"lock_chat_message", "Aquest xat es bloquejarà"}, {"lock_chat_set_password", "Establir contrasenya per bloquejar xats"},
        {"locked_chats_password_title", "Xats bloquejats"}, {"locked_chats_enter_password", "Introduïu la contrasenya per accedir als xats bloquejats"},
        {"password_6_digits", "La contrasenya ha de tenir 6 dígits"}, {"password_incorrect", "Contrasenya incorrecta"}, {"no_master_password", "No s'ha establert cap contrasenya"},
        {"locked_chats_password", "Contrasenya de xats bloquejats"}, {"no_password", "No teniu cap contrasenya"}, {"change_password", "Canviar contrasenya"},
        {"old_password", "Contrasenya antiga"}, {"new_password", "Contrasenya nova"}, {"confirm_password", "Confirmar contrasenya nova"}, {"change", "Canviar"},
        {"old_password_incorrect", "La contrasenya antiga és incorrecta"}, {"passwords_dont_match", "Les contrasenyes noves no coincideixen"},
        {"no_locked_chats", "No hi ha xats bloquejats"}, {"locked_chats_hint", "Seleccioneu 'Bloquejar xat' al menú de 3 punts per bloquejar un xat"}, {"enter", "Entrar"}
    };
    m_translations["Catalan"].insert(QStringLiteral("media_image"), QStringLiteral("Foto"));
    m_translations["Catalan"].insert(QStringLiteral("media_video"), QStringLiteral("Vídeo"));
    m_translations["Catalan"].insert(QStringLiteral("media_voice"), QStringLiteral("Missatge de veu"));
    m_translations["Catalan"].insert(QStringLiteral("media_audio"), QStringLiteral("Àudio"));
    m_translations["Catalan"].insert(QStringLiteral("media_sticker"), QStringLiteral("Adhesiu"));
    m_translations["Catalan"].insert(QStringLiteral("media_document"), QStringLiteral("Document"));
    m_translations["Catalan"].insert(QStringLiteral("media_unavailable"), QStringLiteral("Mitjà no disponible"));
    m_translations["Catalan"].insert(QStringLiteral("tap_to_open"), QStringLiteral("Toqueu per obrir"));
    m_translations["Catalan"].insert(QStringLiteral("location"), QStringLiteral("Ubicació"));
    m_translations["Catalan"].insert(QStringLiteral("contact"), QStringLiteral("Contacte"));
    m_translations["Catalan"].insert(QStringLiteral("favorites"), QStringLiteral("Preferits"));
    m_translations["Catalan"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("Afegir als preferits"));
    m_translations["Catalan"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("Eliminar dels preferits"));
    m_translations["Catalan"].insert(QStringLiteral("no_favorites"), QStringLiteral("No hi ha preferits"));
    m_translations["Catalan"].insert(QStringLiteral("favorites_hint"), QStringLiteral("Feu clic amb el botó dret en un missatge per afegir-lo als preferits"));
    m_translations["Catalan"].insert(QStringLiteral("media_browser"), QStringLiteral("Mitjans"));
    m_translations["Catalan"].insert(QStringLiteral("media_browser_title"), QStringLiteral("Mitjans"));
    m_translations["Catalan"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("Fotos, vídeos i fitxers"));
    m_translations["Catalan"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("Fotos"));
    m_translations["Catalan"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("Vídeos"));
    m_translations["Catalan"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("Documents"));
    m_translations["Catalan"].insert(QStringLiteral("media_browser_links"), QStringLiteral("Enllaços"));
    m_translations["Catalan"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("Ubicacions"));
    m_translations["Catalan"].insert(QStringLiteral("no_photos_found"), QStringLiteral("No s'han trobat fotos"));
    m_translations["Catalan"].insert(QStringLiteral("no_videos_found"), QStringLiteral("No s'han trobat vídeos"));
    m_translations["Catalan"].insert(QStringLiteral("no_documents_found"), QStringLiteral("No s'han trobat documents"));
    m_translations["Catalan"].insert(QStringLiteral("no_links_found"), QStringLiteral("No s'han trobat enllaços"));
    m_translations["Catalan"].insert(QStringLiteral("no_locations_found"), QStringLiteral("No s'han trobat ubicacions"));

    // ChineseHongKong
    m_translations["ChineseHongKong"] = {
        {"contact_info", "聯絡資訊"}, {"msg_count", "訊息數量"}, {"messages", "則訊息"}, {"import_date", "匯入日期"},
        {"no_chats", "找不到對話\n\n按一下 + 以新增\n新對話"}, {"light_theme", "淺色主題"}, {"dark_theme", "深色主題"},
        {"new_chat_tooltip", "新增對話"}, {"chat_search_placeholder", "在對話中搜尋"}, {"importing", "正在匯入..."},
        {"bulk_select_tooltip", "批次選取"}, {"bulk_delete_tooltip", "批次刪除"}, {"cancel_selection_tooltip", "取消"},
        {"import_new", "新增對話"}, {"zip_description", "選擇從 WhatsApp 匯出的 ZIP 檔案。"},
        {"select_zip", "選擇 ZIP 檔案"}, {"change_zip", "變更檔案"}, {"continue", "繼續"},
        {"owner_question", "您在對話中的名稱是什麼？\n（顯示在您 WhatsApp 帳號中的名稱）"}, {"owner_placeholder", "例如：陳大明"},
        {"import_btn", "匯入"}, {"back", "返回"}, {"loading_messages", "正在載入訊息，請稍候..."},
        {"select_zip_title", "選擇 WhatsApp ZIP 檔案"}, {"first_message", "第一則訊息"}, {"delete_chat", "刪除對話"}, {"search", "搜尋..."}, {"search_tooltip", "在訊息中搜尋 (Ctrl+F)"},
        {"empty_chat_hint", "選擇對話或新增一個"}, {"delete_confirm_title", "刪除對話"},
        {"delete_confirm_text", "您確定要刪除這個對話嗎？\n所有訊息都會被移除。"}, {"no_results", "找不到結果"},
        {"yes", "是"}, {"no", "否"}, {"cancel", "取消"}, {"language", "語言"}, {"select_language", "選擇語言"}, {"profile_photo", "個人資料相片"},
        {"name_label", "名稱"}, {"participants_label", "群組成員"}, {"contact_name_placeholder", "聯絡人名稱"}, {"image_files_filter", "圖片檔案 (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — 已匯入 %2 則訊息"}, {"conversation", "對話"},
        {"default_owner_name", "預設擁有者名稱"}, {"owner_name_placeholder", "您的名稱"}, {"not_set", "未設定"}, {"default_label", "預設"},
        {"profile_library", "個人資料庫"}, {"add_profile", "新增個人資料"}, {"profile_name_label", "名稱："}, {"add_btn", "新增"},
        {"optional", "（選用）"}, {"image_selected", "✓ 已選取"}, {"no_profiles_library", "尚未有個人資料。按一下 + 以新增。"},
        {"profile_owner_conflict", "無法新增與擁有者同名的個人資料"}, {"profile_exists", "已存在此名稱的個人資料"},
        {"message_count_text", "則訊息"},
        {"january", "1月"}, {"february", "2月"}, {"march", "3月"}, {"april", "4月"}, {"may", "5月"}, {"june", "6月"},
        {"july", "7月"}, {"august", "8月"}, {"september", "9月"}, {"october", "10月"}, {"november", "11月"}, {"december", "12月"},
        {"calendar_tooltip", "跳至日期"},
        {"last_message", "最後一則訊息"},
        {"settings", "設定"},
        {"auto_play_next_voice", "自動播放連續語音訊息"},
        {"open_system", "在系統中開啟"}, {"image_not_found", "找不到圖片"}, {"video", "影片"}, {"deleted_message", "此訊息已刪除"}, {"you_deleted_message", "您已刪除此訊息"}, {"edited", "已編輯"}, {"app_version", "版本"}, {"app_copyright", "版權所有 %1"},
        {"lock_chat", "鎖定對話"}, {"unlock_chat", "解鎖此對話"}, {"locked_chats", "已鎖定的對話"}, {"locked_chats_access", "存取已鎖定的對話"},
        {"lock_chat_title", "鎖定對話"}, {"lock_chat_message", "此對話將被鎖定"}, {"lock_chat_set_password", "設定密碼以鎖定對話"},
        {"locked_chats_password_title", "已鎖定的對話"}, {"locked_chats_enter_password", "輸入密碼以存取已鎖定的對話"},
        {"password_6_digits", "密碼必須是 6 位數字"}, {"password_incorrect", "密碼不正確"}, {"no_master_password", "未設定密碼"},
        {"locked_chats_password", "已鎖定對話的密碼"}, {"no_password", "您沒有密碼"}, {"change_password", "變更密碼"},
        {"old_password", "舊密碼"}, {"new_password", "新密碼"}, {"confirm_password", "確認新密碼"}, {"change", "變更"},
        {"old_password_incorrect", "舊密碼不正確"}, {"passwords_dont_match", "新密碼不符"},
        {"no_locked_chats", "沒有已鎖定的對話"}, {"locked_chats_hint", "從 3 點選單中選擇「鎖定對話」以鎖定對話"}, {"enter", "進入"}
    };
    m_translations["ChineseHongKong"].insert(QStringLiteral("media_image"), QStringLiteral("相片"));
    m_translations["ChineseHongKong"].insert(QStringLiteral("media_video"), QStringLiteral("影片"));
    m_translations["ChineseHongKong"].insert(QStringLiteral("media_voice"), QStringLiteral("語音訊息"));
    m_translations["ChineseHongKong"].insert(QStringLiteral("media_audio"), QStringLiteral("音訊"));
    m_translations["ChineseHongKong"].insert(QStringLiteral("media_sticker"), QStringLiteral("貼圖"));
    m_translations["ChineseHongKong"].insert(QStringLiteral("media_document"), QStringLiteral("文件"));
    m_translations["ChineseHongKong"].insert(QStringLiteral("media_unavailable"), QStringLiteral("媒體無法使用"));
    m_translations["ChineseHongKong"].insert(QStringLiteral("tap_to_open"), QStringLiteral("點擊以開啟"));
    m_translations["ChineseHongKong"].insert(QStringLiteral("location"), QStringLiteral("位置"));
    m_translations["ChineseHongKong"].insert(QStringLiteral("contact"), QStringLiteral("聯絡人"));
    m_translations["ChineseHongKong"].insert(QStringLiteral("favorites"), QStringLiteral("我的最愛"));
    m_translations["ChineseHongKong"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("加入我的最愛"));
    m_translations["ChineseHongKong"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("從我的最愛中移除"));
    m_translations["ChineseHongKong"].insert(QStringLiteral("no_favorites"), QStringLiteral("沒有我的最愛"));
    m_translations["ChineseHongKong"].insert(QStringLiteral("favorites_hint"), QStringLiteral("按右鍵點擊訊息以加入我的最愛"));
    m_translations["ChineseHongKong"].insert(QStringLiteral("media_browser"), QStringLiteral("媒體"));
    m_translations["ChineseHongKong"].insert(QStringLiteral("media_browser_title"), QStringLiteral("媒體"));
    m_translations["ChineseHongKong"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("相片、影片和檔案"));
    m_translations["ChineseHongKong"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("相片"));
    m_translations["ChineseHongKong"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("影片"));
    m_translations["ChineseHongKong"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("文件"));
    m_translations["ChineseHongKong"].insert(QStringLiteral("media_browser_links"), QStringLiteral("連結"));
    m_translations["ChineseHongKong"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("位置"));
    m_translations["ChineseHongKong"].insert(QStringLiteral("no_photos_found"), QStringLiteral("找不到相片"));
    m_translations["ChineseHongKong"].insert(QStringLiteral("no_videos_found"), QStringLiteral("找不到影片"));
    m_translations["ChineseHongKong"].insert(QStringLiteral("no_documents_found"), QStringLiteral("找不到文件"));
    m_translations["ChineseHongKong"].insert(QStringLiteral("no_links_found"), QStringLiteral("找不到連結"));
    m_translations["ChineseHongKong"].insert(QStringLiteral("no_locations_found"), QStringLiteral("找不到位置"));

    // ChineseTaiwan
    m_translations["ChineseTaiwan"] = {
        {"contact_info", "聯絡資訊"}, {"msg_count", "訊息數量"}, {"messages", "則訊息"}, {"import_date", "匯入日期"},
        {"no_chats", "找不到對話\n\n按一下 + 以新增\n新對話"}, {"light_theme", "淺色主題"}, {"dark_theme", "深色主題"},
        {"new_chat_tooltip", "新增對話"}, {"chat_search_placeholder", "在對話中搜尋"}, {"importing", "正在匯入..."},
        {"bulk_select_tooltip", "批次選取"}, {"bulk_delete_tooltip", "批次刪除"}, {"cancel_selection_tooltip", "取消"},
        {"import_new", "新增對話"}, {"zip_description", "選擇從 WhatsApp 匯出的 ZIP 檔案。"},
        {"select_zip", "選擇 ZIP 檔案"}, {"change_zip", "變更檔案"}, {"continue", "繼續"},
        {"owner_question", "您在對話中的名稱是什麼？\n（顯示在您 WhatsApp 帳號中的名稱）"}, {"owner_placeholder", "例如：陳大明"},
        {"import_btn", "匯入"}, {"back", "返回"}, {"loading_messages", "正在載入訊息，請稍候..."},
        {"select_zip_title", "選擇 WhatsApp ZIP 檔案"}, {"first_message", "第一則訊息"}, {"delete_chat", "刪除對話"}, {"search", "搜尋..."}, {"search_tooltip", "在訊息中搜尋 (Ctrl+F)"},
        {"empty_chat_hint", "選擇對話或新增一個"}, {"delete_confirm_title", "刪除對話"},
        {"delete_confirm_text", "您確定要刪除這個對話嗎？\n所有訊息都會被移除。"}, {"no_results", "找不到結果"},
        {"yes", "是"}, {"no", "否"}, {"cancel", "取消"}, {"language", "語言"}, {"select_language", "選擇語言"}, {"profile_photo", "個人資料相片"},
        {"name_label", "名稱"}, {"participants_label", "群組成員"}, {"contact_name_placeholder", "聯絡人名稱"}, {"image_files_filter", "圖片檔案 (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — 已匯入 %2 則訊息"}, {"conversation", "對話"},
        {"default_owner_name", "預設擁有者名稱"}, {"owner_name_placeholder", "您的名稱"}, {"not_set", "未設定"}, {"default_label", "預設"},
        {"profile_library", "個人資料庫"}, {"add_profile", "新增個人資料"}, {"profile_name_label", "名稱："}, {"add_btn", "新增"},
        {"optional", "（選用）"}, {"image_selected", "✓ 已選取"}, {"no_profiles_library", "尚未有個人資料。按一下 + 以新增。"},
        {"profile_owner_conflict", "無法新增與擁有者同名的個人資料"}, {"profile_exists", "已存在此名稱的個人資料"},
        {"message_count_text", "則訊息"},
        {"january", "1月"}, {"february", "2月"}, {"march", "3月"}, {"april", "4月"}, {"may", "5月"}, {"june", "6月"},
        {"july", "7月"}, {"august", "8月"}, {"september", "9月"}, {"october", "10月"}, {"november", "11月"}, {"december", "12月"},
        {"calendar_tooltip", "跳至日期"},
        {"last_message", "最後一則訊息"},
        {"settings", "設定"},
        {"auto_play_next_voice", "自動播放連續語音訊息"},
        {"open_system", "在系統中開啟"}, {"image_not_found", "找不到圖片"}, {"video", "影片"}, {"deleted_message", "此訊息已刪除"}, {"you_deleted_message", "您已刪除此訊息"}, {"edited", "已編輯"}, {"app_version", "版本"}, {"app_copyright", "版權所有 %1"},
        {"lock_chat", "鎖定對話"}, {"unlock_chat", "解鎖此對話"}, {"locked_chats", "已鎖定的對話"}, {"locked_chats_access", "存取已鎖定的對話"},
        {"lock_chat_title", "鎖定對話"}, {"lock_chat_message", "此對話將被鎖定"}, {"lock_chat_set_password", "設定密碼以鎖定對話"},
        {"locked_chats_password_title", "已鎖定的對話"}, {"locked_chats_enter_password", "輸入密碼以存取已鎖定的對話"},
        {"password_6_digits", "密碼必須是 6 位數字"}, {"password_incorrect", "密碼不正確"}, {"no_master_password", "未設定密碼"},
        {"locked_chats_password", "已鎖定對話的密碼"}, {"no_password", "您沒有密碼"}, {"change_password", "變更密碼"},
        {"old_password", "舊密碼"}, {"new_password", "新密碼"}, {"confirm_password", "確認新密碼"}, {"change", "變更"},
        {"old_password_incorrect", "舊密碼不正確"}, {"passwords_dont_match", "新密碼不符"},
        {"no_locked_chats", "沒有已鎖定的對話"}, {"locked_chats_hint", "從 3 點選單中選擇「鎖定對話」以鎖定對話"}, {"enter", "進入"}
    };
    m_translations["ChineseTaiwan"].insert(QStringLiteral("media_image"), QStringLiteral("相片"));
    m_translations["ChineseTaiwan"].insert(QStringLiteral("media_video"), QStringLiteral("影片"));
    m_translations["ChineseTaiwan"].insert(QStringLiteral("media_voice"), QStringLiteral("語音訊息"));
    m_translations["ChineseTaiwan"].insert(QStringLiteral("media_audio"), QStringLiteral("音訊"));
    m_translations["ChineseTaiwan"].insert(QStringLiteral("media_sticker"), QStringLiteral("貼圖"));
    m_translations["ChineseTaiwan"].insert(QStringLiteral("media_document"), QStringLiteral("文件"));
    m_translations["ChineseTaiwan"].insert(QStringLiteral("media_unavailable"), QStringLiteral("媒體無法使用"));
    m_translations["ChineseTaiwan"].insert(QStringLiteral("tap_to_open"), QStringLiteral("點選以開啟"));
    m_translations["ChineseTaiwan"].insert(QStringLiteral("location"), QStringLiteral("位置"));
    m_translations["ChineseTaiwan"].insert(QStringLiteral("contact"), QStringLiteral("聯絡人"));
    m_translations["ChineseTaiwan"].insert(QStringLiteral("favorites"), QStringLiteral("我的最愛"));
    m_translations["ChineseTaiwan"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("加入我的最愛"));
    m_translations["ChineseTaiwan"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("從我的最愛中移除"));
    m_translations["ChineseTaiwan"].insert(QStringLiteral("no_favorites"), QStringLiteral("沒有我的最愛"));
    m_translations["ChineseTaiwan"].insert(QStringLiteral("favorites_hint"), QStringLiteral("按右鍵點選訊息以加入我的最愛"));
    m_translations["ChineseTaiwan"].insert(QStringLiteral("media_browser"), QStringLiteral("媒體"));
    m_translations["ChineseTaiwan"].insert(QStringLiteral("media_browser_title"), QStringLiteral("媒體"));
    m_translations["ChineseTaiwan"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("相片、影片和檔案"));
    m_translations["ChineseTaiwan"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("相片"));
    m_translations["ChineseTaiwan"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("影片"));
    m_translations["ChineseTaiwan"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("文件"));
    m_translations["ChineseTaiwan"].insert(QStringLiteral("media_browser_links"), QStringLiteral("連結"));
    m_translations["ChineseTaiwan"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("位置"));
    m_translations["ChineseTaiwan"].insert(QStringLiteral("no_photos_found"), QStringLiteral("找不到相片"));
    m_translations["ChineseTaiwan"].insert(QStringLiteral("no_videos_found"), QStringLiteral("找不到影片"));
    m_translations["ChineseTaiwan"].insert(QStringLiteral("no_documents_found"), QStringLiteral("找不到文件"));
    m_translations["ChineseTaiwan"].insert(QStringLiteral("no_links_found"), QStringLiteral("找不到連結"));
    m_translations["ChineseTaiwan"].insert(QStringLiteral("no_locations_found"), QStringLiteral("找不到位置"));

    // Croatian
    m_translations["Croatian"] = {
        {"contact_info", "Informacije o kontaktu"}, {"msg_count", "Broj poruka"}, {"messages", "poruke"}, {"import_date", "Datum uvoza"},
        {"no_chats", "Nema pronađenih razgovora\n\nKliknite + za dodavanje\nnovog razgovora"}, {"light_theme", "Svijetla tema"}, {"dark_theme", "Tamna tema"},
        {"new_chat_tooltip", "Dodaj novi razgovor"}, {"chat_search_placeholder", "Pretraži razgovore"}, {"importing", "Uvoz u tijeku..."},
        {"bulk_select_tooltip", "Višestruki odabir"}, {"bulk_delete_tooltip", "Višestruko brisanje"}, {"cancel_selection_tooltip", "Odustani"},
        {"import_new", "Dodaj novi razgovor"}, {"zip_description", "Odaberite ZIP datoteku izvezenu iz WhatsAppa."},
        {"select_zip", "Odaberi ZIP datoteku"}, {"change_zip", "Promijeni datoteku"}, {"continue", "Nastavi"},
        {"owner_question", "Koje je vaše ime u razgovoru?\n(Ime prikazano na vašem WhatsApp računu)"}, {"owner_placeholder", "Npr: Ivan Horvat"},
        {"import_btn", "Uvezi"}, {"back", "Natrag"}, {"loading_messages", "Učitavanje poruka, molimo pričekajte..."},
        {"select_zip_title", "Odaberite WhatsApp ZIP datoteku"}, {"first_message", "Prva poruka"}, {"delete_chat", "Izbriši razgovor"}, {"search", "Pretraži..."}, {"search_tooltip", "Pretraži poruke (Ctrl+F)"},
        {"empty_chat_hint", "Odaberite razgovor ili dodajte novi"}, {"delete_confirm_title", "Izbriši razgovor"},
        {"delete_confirm_text", "Jeste li sigurni da želite izbrisati ovaj razgovor?\nSve poruke bit će uklonjene."}, {"no_results", "Nema pronađenih rezultata"},
        {"yes", "Da"}, {"no", "Ne"}, {"cancel", "Odustani"}, {"language", "Jezik"}, {"select_language", "Odaberite jezik"}, {"profile_photo", "Profilna slika"},
        {"name_label", "Ime"}, {"participants_label", "Sudionici grupe"}, {"contact_name_placeholder", "Ime kontakta"}, {"image_files_filter", "Datoteke slika (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — %2 poruka uvezeno"}, {"conversation", "Razgovor"},
        {"default_owner_name", "Zadano ime vlasnika"}, {"owner_name_placeholder", "Vaše ime"}, {"not_set", "Nije postavljeno"}, {"default_label", "Zadano"},
        {"profile_library", "Biblioteka profila"}, {"add_profile", "Dodaj profil"}, {"profile_name_label", "Ime:"}, {"add_btn", "Dodaj"},
        {"optional", "(Opcionalno)"}, {"image_selected", "✓ Odabrano"}, {"no_profiles_library", "Još nema profila. Kliknite + za dodavanje."},
        {"profile_owner_conflict", "Ne može se dodati profil s istim imenom kao vlasnik"}, {"profile_exists", "Profil s tim imenom već postoji"},
        {"message_count_text", "poruke"},
        {"january", "Sij"}, {"february", "Velj"}, {"march", "Ožu"}, {"april", "Tra"}, {"may", "Svi"}, {"june", "Lip"},
        {"july", "Srp"}, {"august", "Kol"}, {"september", "Ruj"}, {"october", "Lis"}, {"november", "Stu"}, {"december", "Pro"},
        {"calendar_tooltip", "Idi na datum"},
        {"last_message", "Posljednja poruka"},
        {"settings", "Postavke"},
        {"auto_play_next_voice", "Automatski reproduciraj uzastopne glasovne poruke"},
        {"open_system", "Otvori u sustavu"}, {"image_not_found", "Slika nije pronađena"}, {"video", "Video"}, {"deleted_message", "Ova poruka je izbrisana"}, {"you_deleted_message", "Izbrisali ste ovu poruku"}, {"edited", "Uređeno"}, {"app_version", "verzija"}, {"app_copyright", "Autorska prava %1"},
        {"lock_chat", "Zaključaj razgovor"}, {"unlock_chat", "Otključaj ovaj razgovor"}, {"locked_chats", "Zaključani razgovori"}, {"locked_chats_access", "Pristup zaključanim razgovorima"},
        {"lock_chat_title", "Zaključaj razgovor"}, {"lock_chat_message", "Ovaj razgovor bit će zaključan"}, {"lock_chat_set_password", "Postavite lozinku za zaključavanje razgovora"},
        {"locked_chats_password_title", "Zaključani razgovori"}, {"locked_chats_enter_password", "Unesite lozinku za pristup zaključanim razgovorima"},
        {"password_6_digits", "Lozinka mora imati 6 znamenki"}, {"password_incorrect", "Netočna lozinka"}, {"no_master_password", "Lozinka nije postavljena"},
        {"locked_chats_password", "Lozinka za zaključane razgovore"}, {"no_password", "Nemate lozinku"}, {"change_password", "Promijenite lozinku"},
        {"old_password", "Stara lozinka"}, {"new_password", "Nova lozinka"}, {"confirm_password", "Potvrdite novu lozinku"}, {"change", "Promijeni"},
        {"old_password_incorrect", "Stara lozinka je netočna"}, {"passwords_dont_match", "Nove lozinke se ne podudaraju"},
        {"no_locked_chats", "Nema zaključanih razgovora"}, {"locked_chats_hint", "Odaberite 'Zaključaj razgovor' iz izbornika s 3 točke za zaključavanje razgovora"}, {"enter", "Unesi"}
    };
    m_translations["Croatian"].insert(QStringLiteral("media_image"), QStringLiteral("Slika"));
    m_translations["Croatian"].insert(QStringLiteral("media_video"), QStringLiteral("Video"));
    m_translations["Croatian"].insert(QStringLiteral("media_voice"), QStringLiteral("Glasovna poruka"));
    m_translations["Croatian"].insert(QStringLiteral("media_audio"), QStringLiteral("Audio"));
    m_translations["Croatian"].insert(QStringLiteral("media_sticker"), QStringLiteral("Naljepnica"));
    m_translations["Croatian"].insert(QStringLiteral("media_document"), QStringLiteral("Dokument"));
    m_translations["Croatian"].insert(QStringLiteral("media_unavailable"), QStringLiteral("Medij nije dostupan"));
    m_translations["Croatian"].insert(QStringLiteral("tap_to_open"), QStringLiteral("Dodirnite za otvaranje"));
    m_translations["Croatian"].insert(QStringLiteral("location"), QStringLiteral("Lokacija"));
    m_translations["Croatian"].insert(QStringLiteral("contact"), QStringLiteral("Kontakt"));
    m_translations["Croatian"].insert(QStringLiteral("favorites"), QStringLiteral("Favoriti"));
    m_translations["Croatian"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("Dodaj u favorite"));
    m_translations["Croatian"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("Ukloni iz favorita"));
    m_translations["Croatian"].insert(QStringLiteral("no_favorites"), QStringLiteral("Nema favorita"));
    m_translations["Croatian"].insert(QStringLiteral("favorites_hint"), QStringLiteral("Desni klik na poruku za dodavanje u favorite"));
    m_translations["Croatian"].insert(QStringLiteral("media_browser"), QStringLiteral("Mediji"));
    m_translations["Croatian"].insert(QStringLiteral("media_browser_title"), QStringLiteral("Mediji"));
    m_translations["Croatian"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("Slike, videozapisi i datoteke"));
    m_translations["Croatian"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("Slike"));
    m_translations["Croatian"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("Videozapisi"));
    m_translations["Croatian"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("Dokumenti"));
    m_translations["Croatian"].insert(QStringLiteral("media_browser_links"), QStringLiteral("Poveznice"));
    m_translations["Croatian"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("Lokacije"));
    m_translations["Croatian"].insert(QStringLiteral("no_photos_found"), QStringLiteral("Nema pronađenih slika"));
    m_translations["Croatian"].insert(QStringLiteral("no_videos_found"), QStringLiteral("Nema pronađenih videozapisa"));
    m_translations["Croatian"].insert(QStringLiteral("no_documents_found"), QStringLiteral("Nema pronađenih dokumenata"));
    m_translations["Croatian"].insert(QStringLiteral("no_links_found"), QStringLiteral("Nema pronađenih poveznica"));
    m_translations["Croatian"].insert(QStringLiteral("no_locations_found"), QStringLiteral("Nema pronađenih lokacija"));

    // Czech
    m_translations["Czech"] = {
        {"contact_info", "Informace o kontaktu"}, {"msg_count", "Počet zpráv"}, {"messages", "zprávy"}, {"import_date", "Datum importu"},
        {"no_chats", "Nebyly nalezeny žádné chaty\n\nKliknutím na + přidáte\nnovýchat"}, {"light_theme", "Světlý motiv"}, {"dark_theme", "Tmavý motiv"},
        {"new_chat_tooltip", "Přidat nový chat"}, {"chat_search_placeholder", "Hledat v chatech"}, {"importing", "Importování..."},
        {"bulk_select_tooltip", "Hromadný výběr"}, {"bulk_delete_tooltip", "Hromadné smazání"}, {"cancel_selection_tooltip", "Zrušit"},
        {"import_new", "Přidat nový chat"}, {"zip_description", "Vyberte ZIP soubor exportovaný z WhatsApp."},
        {"select_zip", "Vybrat ZIP soubor"}, {"change_zip", "Změnit soubor"}, {"continue", "Pokračovat"},
        {"owner_question", "Jaké je vaše jméno v chatu?\n(Jméno zobrazené na vašem účtu WhatsApp)"}, {"owner_placeholder", "Např: Jan Novák"},
        {"import_btn", "Importovat"}, {"back", "Zpět"}, {"loading_messages", "Načítání zpráv, prosím čekejte..."},
        {"select_zip_title", "Vyberte ZIP soubor WhatsApp"}, {"first_message", "První zpráva"}, {"delete_chat", "Smazat chat"}, {"search", "Hledat..."}, {"search_tooltip", "Hledat ve zprávách (Ctrl+F)"},
        {"empty_chat_hint", "Vyberte chat nebo přidejte nový"}, {"delete_confirm_title", "Smazat chat"},
        {"delete_confirm_text", "Opravdu chcete smazat tento chat?\nVšechny zprávy budou odstraněny."}, {"no_results", "Nebyly nalezeny žádné výsledky"},
        {"yes", "Ano"}, {"no", "Ne"}, {"cancel", "Zrušit"}, {"language", "Jazyk"}, {"select_language", "Vyberte jazyk"}, {"profile_photo", "Profilová fotografie"},
        {"name_label", "Jméno"}, {"participants_label", "Účastníci skupiny"}, {"contact_name_placeholder", "Jméno kontaktu"}, {"image_files_filter", "Obrazové soubory (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — %2 zpráv importováno"}, {"conversation", "Konverzace"},
        {"default_owner_name", "Výchozí jméno vlastníka"}, {"owner_name_placeholder", "Vaše jméno"}, {"not_set", "Nenastaveno"}, {"default_label", "Výchozí"},
        {"profile_library", "Knihovna profilů"}, {"add_profile", "Přidat profil"}, {"profile_name_label", "Jméno:"}, {"add_btn", "Přidat"},
        {"optional", "(Volitelné)"}, {"image_selected", "✓ Vybráno"}, {"no_profiles_library", "Zatím žádné profily. Klikněte na + pro přidání."},
        {"profile_owner_conflict", "Nelze přidat profil se stejným jménem jako vlastník"}, {"profile_exists", "Profil s tímto jménem již existuje"},
        {"message_count_text", "zprávy"},
        {"january", "Led"}, {"february", "Úno"}, {"march", "Bře"}, {"april", "Dub"}, {"may", "Kvě"}, {"june", "Čer"},
        {"july", "Čvc"}, {"august", "Srp"}, {"september", "Zář"}, {"october", "Říj"}, {"november", "Lis"}, {"december", "Pro"},
        {"calendar_tooltip", "Přejít na datum"},
        {"last_message", "Poslední zpráva"},
        {"settings", "Nastavení"},
        {"auto_play_next_voice", "Automaticky přehrávat po sobě jdoucí hlasové zprávy"},
        {"open_system", "Otevřít v systému"}, {"image_not_found", "Obrázek nebyl nalezen"}, {"video", "Video"}, {"deleted_message", "Tato zpráva byla smazána"}, {"you_deleted_message", "Smazali jste tuto zprávu"}, {"edited", "Upraveno"}, {"app_version", "verze"}, {"app_copyright", "Autorská práva %1"},
        {"lock_chat", "Uzamknout chat"}, {"unlock_chat", "Odemknout tento chat"}, {"locked_chats", "Uzamčené chaty"}, {"locked_chats_access", "Přístup k uzamčeným chatům"},
        {"lock_chat_title", "Uzamknout chat"}, {"lock_chat_message", "Tento chat bude uzamčen"}, {"lock_chat_set_password", "Nastavte heslo pro uzamčení chatů"},
        {"locked_chats_password_title", "Uzamčené chaty"}, {"locked_chats_enter_password", "Zadejte heslo pro přístup k uzamčeným chatům"},
        {"password_6_digits", "Heslo musí mít 6 číslic"}, {"password_incorrect", "Nesprávné heslo"}, {"no_master_password", "Heslo není nastaveno"},
        {"locked_chats_password", "Heslo pro uzamčené chaty"}, {"no_password", "Nemáte heslo"}, {"change_password", "Změnit heslo"},
        {"old_password", "Staré heslo"}, {"new_password", "Nové heslo"}, {"confirm_password", "Potvrďte nové heslo"}, {"change", "Změnit"},
        {"old_password_incorrect", "Staré heslo je nesprávné"}, {"passwords_dont_match", "Nová hesla se neshodují"},
        {"no_locked_chats", "Žádné uzamčené chaty"}, {"locked_chats_hint", "V menu se třemi tečkami vyberte 'Uzamknout chat' pro uzamčení chatu"}, {"enter", "Vstoupit"}
    };
    m_translations["Czech"].insert(QStringLiteral("media_image"), QStringLiteral("Fotografie"));
    m_translations["Czech"].insert(QStringLiteral("media_video"), QStringLiteral("Video"));
    m_translations["Czech"].insert(QStringLiteral("media_voice"), QStringLiteral("Hlasová zpráva"));
    m_translations["Czech"].insert(QStringLiteral("media_audio"), QStringLiteral("Audio"));
    m_translations["Czech"].insert(QStringLiteral("media_sticker"), QStringLiteral("Nálepka"));
    m_translations["Czech"].insert(QStringLiteral("media_document"), QStringLiteral("Dokument"));
    m_translations["Czech"].insert(QStringLiteral("media_unavailable"), QStringLiteral("Média nejsou k dispozici"));
    m_translations["Czech"].insert(QStringLiteral("tap_to_open"), QStringLiteral("Klepněte pro otevření"));
    m_translations["Czech"].insert(QStringLiteral("location"), QStringLiteral("Poloha"));
    m_translations["Czech"].insert(QStringLiteral("contact"), QStringLiteral("Kontakt"));
    m_translations["Czech"].insert(QStringLiteral("favorites"), QStringLiteral("Oblíbené"));
    m_translations["Czech"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("Přidat do oblíbených"));
    m_translations["Czech"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("Odstranit z oblíbených"));
    m_translations["Czech"].insert(QStringLiteral("no_favorites"), QStringLiteral("Žádné oblíbené"));
    m_translations["Czech"].insert(QStringLiteral("favorites_hint"), QStringLiteral("Klikněte pravým tlačítkem na zprávu a přidejte do oblíbených"));
    m_translations["Czech"].insert(QStringLiteral("media_browser"), QStringLiteral("Média"));
    m_translations["Czech"].insert(QStringLiteral("media_browser_title"), QStringLiteral("Média"));
    m_translations["Czech"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("Fotografie, videa a soubory"));
    m_translations["Czech"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("Fotografie"));
    m_translations["Czech"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("Videa"));
    m_translations["Czech"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("Dokumenty"));
    m_translations["Czech"].insert(QStringLiteral("media_browser_links"), QStringLiteral("Odkazy"));
    m_translations["Czech"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("Polohy"));
    m_translations["Czech"].insert(QStringLiteral("no_photos_found"), QStringLiteral("Nebyly nalezeny žádné fotografie"));
    m_translations["Czech"].insert(QStringLiteral("no_videos_found"), QStringLiteral("Nebyla nalezena žádná videa"));
    m_translations["Czech"].insert(QStringLiteral("no_documents_found"), QStringLiteral("Nebyly nalezeny žádné dokumenty"));
    m_translations["Czech"].insert(QStringLiteral("no_links_found"), QStringLiteral("Nebyly nalezeny žádné odkazy"));
    m_translations["Czech"].insert(QStringLiteral("no_locations_found"), QStringLiteral("Nebyly nalezeny žádné polohy"));

    // Danish
    m_translations["Danish"] = {
        {"contact_info", "Kontaktinfo"}, {"msg_count", "Antal beskeder"}, {"messages", "beskeder"}, {"import_date", "Importdato"},
        {"no_chats", "Ingen chats fundet\n\nKlik på + for at tilføje\nen ny chat"}, {"light_theme", "Lyst tema"}, {"dark_theme", "Mørkt tema"},
        {"new_chat_tooltip", "Tilføj ny chat"}, {"chat_search_placeholder", "Søg i chats"}, {"importing", "Importerer..."},
        {"bulk_select_tooltip", "Massevalg"}, {"bulk_delete_tooltip", "Masseslet"}, {"cancel_selection_tooltip", "Annuller"},
        {"import_new", "Tilføj ny chat"}, {"zip_description", "Vælg ZIP-filen eksporteret fra WhatsApp."},
        {"select_zip", "Vælg ZIP-fil"}, {"change_zip", "Skift fil"}, {"continue", "Fortsæt"},
        {"owner_question", "Hvad er dit navn i chatten?\n(Navnet vist på din WhatsApp-konto)"}, {"owner_placeholder", "F.eks: Anders Jensen"},
        {"import_btn", "Importer"}, {"back", "Tilbage"}, {"loading_messages", "Indlæser beskeder, vent venligst..."},
        {"select_zip_title", "Vælg WhatsApp ZIP-fil"}, {"first_message", "Første besked"}, {"delete_chat", "Slet chat"}, {"search", "Søg..."}, {"search_tooltip", "Søg i beskeder (Ctrl+F)"},
        {"empty_chat_hint", "Vælg en chat eller tilføj en ny"}, {"delete_confirm_title", "Slet chat"},
        {"delete_confirm_text", "Er du sikker på, at du vil slette denne chat?\nAlle beskeder vil blive fjernet."}, {"no_results", "Ingen resultater fundet"},
        {"yes", "Ja"}, {"no", "Nej"}, {"cancel", "Annuller"}, {"language", "Sprog"}, {"select_language", "Vælg sprog"}, {"profile_photo", "Profilbillede"},
        {"name_label", "Navn"}, {"participants_label", "Gruppedeltagere"}, {"contact_name_placeholder", "Kontaktnavn"}, {"image_files_filter", "Billedfiler (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — %2 beskeder importeret"}, {"conversation", "Samtale"},
        {"default_owner_name", "Standard ejernavn"}, {"owner_name_placeholder", "Dit navn"}, {"not_set", "Ikke indstillet"}, {"default_label", "Standard"},
        {"profile_library", "Profilbibliotek"}, {"add_profile", "Tilføj profil"}, {"profile_name_label", "Navn:"}, {"add_btn", "Tilføj"},
        {"optional", "(Valgfrit)"}, {"image_selected", "✓ Valgt"}, {"no_profiles_library", "Ingen profiler endnu. Klik på + for at tilføje."},
        {"profile_owner_conflict", "Kan ikke tilføje profil med samme navn som ejer"}, {"profile_exists", "Profil med dette navn eksisterer allerede"},
        {"message_count_text", "beskeder"},
        {"january", "Jan"}, {"february", "Feb"}, {"march", "Mar"}, {"april", "Apr"}, {"may", "Maj"}, {"june", "Jun"},
        {"july", "Jul"}, {"august", "Aug"}, {"september", "Sep"}, {"october", "Okt"}, {"november", "Nov"}, {"december", "Dec"},
        {"calendar_tooltip", "Gå til dato"},
        {"last_message", "Sidste besked"},
        {"settings", "Indstillinger"},
        {"auto_play_next_voice", "Automatisk afspilning af på hinanden følgende talebeskeder"},
        {"open_system", "Åbn i system"}, {"image_not_found", "Billede ikke fundet"}, {"video", "Video"}, {"deleted_message", "Denne besked blev slettet"}, {"you_deleted_message", "Du slettede denne besked"}, {"edited", "Redigeret"}, {"app_version", "version"}, {"app_copyright", "Copyright af %1"},
        {"lock_chat", "Lås chat"}, {"unlock_chat", "Lås denne chat op"}, {"locked_chats", "Låste chats"}, {"locked_chats_access", "Adgang til låste chats"},
        {"lock_chat_title", "Lås chat"}, {"lock_chat_message", "Denne chat vil blive låst"}, {"lock_chat_set_password", "Indstil adgangskode for at låse chats"},
        {"locked_chats_password_title", "Låste chats"}, {"locked_chats_enter_password", "Indtast adgangskode for at få adgang til låste chats"},
        {"password_6_digits", "Adgangskode skal være 6 cifre"}, {"password_incorrect", "Forkert adgangskode"}, {"no_master_password", "Ingen adgangskode indstillet"},
        {"locked_chats_password", "Adgangskode til låste chats"}, {"no_password", "Du har ingen adgangskode"}, {"change_password", "Skift adgangskode"},
        {"old_password", "Gammel adgangskode"}, {"new_password", "Ny adgangskode"}, {"confirm_password", "Bekræft ny adgangskode"}, {"change", "Skift"},
        {"old_password_incorrect", "Gammel adgangskode er forkert"}, {"passwords_dont_match", "Nye adgangskoder matcher ikke"},
        {"no_locked_chats", "Ingen låste chats"}, {"locked_chats_hint", "Vælg 'Lås chat' fra 3-prikker-menuen for at låse en chat"}, {"enter", "Indtast"}
    };
    m_translations["Danish"].insert(QStringLiteral("media_image"), QStringLiteral("Billede"));
    m_translations["Danish"].insert(QStringLiteral("media_video"), QStringLiteral("Video"));
    m_translations["Danish"].insert(QStringLiteral("media_voice"), QStringLiteral("Talebesked"));
    m_translations["Danish"].insert(QStringLiteral("media_audio"), QStringLiteral("Lyd"));
    m_translations["Danish"].insert(QStringLiteral("media_sticker"), QStringLiteral("Klistermærke"));
    m_translations["Danish"].insert(QStringLiteral("media_document"), QStringLiteral("Dokument"));
    m_translations["Danish"].insert(QStringLiteral("media_unavailable"), QStringLiteral("Medie utilgængeligt"));
    m_translations["Danish"].insert(QStringLiteral("tap_to_open"), QStringLiteral("Tryk for at åbne"));
    m_translations["Danish"].insert(QStringLiteral("location"), QStringLiteral("Placering"));
    m_translations["Danish"].insert(QStringLiteral("contact"), QStringLiteral("Kontakt"));
    m_translations["Danish"].insert(QStringLiteral("favorites"), QStringLiteral("Favoritter"));
    m_translations["Danish"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("Tilføj til favoritter"));
    m_translations["Danish"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("Fjern fra favoritter"));
    m_translations["Danish"].insert(QStringLiteral("no_favorites"), QStringLiteral("Ingen favoritter"));
    m_translations["Danish"].insert(QStringLiteral("favorites_hint"), QStringLiteral("Højreklik på en besked for at tilføje til favoritter"));
    m_translations["Danish"].insert(QStringLiteral("media_browser"), QStringLiteral("Medier"));
    m_translations["Danish"].insert(QStringLiteral("media_browser_title"), QStringLiteral("Medier"));
    m_translations["Danish"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("Billeder, videoer og filer"));
    m_translations["Danish"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("Billeder"));
    m_translations["Danish"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("Videoer"));
    m_translations["Danish"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("Dokumenter"));
    m_translations["Danish"].insert(QStringLiteral("media_browser_links"), QStringLiteral("Links"));
    m_translations["Danish"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("Placeringer"));
    m_translations["Danish"].insert(QStringLiteral("no_photos_found"), QStringLiteral("Ingen billeder fundet"));
    m_translations["Danish"].insert(QStringLiteral("no_videos_found"), QStringLiteral("Ingen videoer fundet"));
    m_translations["Danish"].insert(QStringLiteral("no_documents_found"), QStringLiteral("Ingen dokumenter fundet"));
    m_translations["Danish"].insert(QStringLiteral("no_links_found"), QStringLiteral("Ingen links fundet"));
    m_translations["Danish"].insert(QStringLiteral("no_locations_found"), QStringLiteral("Ingen placeringer fundet"));

    // Dutch
    m_translations["Dutch"] = {
        {"contact_info", "Contactinfo"}, {"msg_count", "Aantal berichten"}, {"messages", "berichten"}, {"import_date", "Importdatum"},
        {"no_chats", "Geen chats gevonden\n\nKlik op + om een\nnieuwe chat toe te voegen"}, {"light_theme", "Licht thema"}, {"dark_theme", "Donker thema"},
        {"new_chat_tooltip", "Nieuwe chat toevoegen"}, {"chat_search_placeholder", "Zoeken in chats"}, {"importing", "Importeren..."},
        {"bulk_select_tooltip", "Bulkselectie"}, {"bulk_delete_tooltip", "Bulkverwijdering"}, {"cancel_selection_tooltip", "Annuleren"},
        {"import_new", "Nieuwe chat toevoegen"}, {"zip_description", "Selecteer het ZIP-bestand dat is geëxporteerd vanuit WhatsApp."},
        {"select_zip", "ZIP-bestand selecteren"}, {"change_zip", "Bestand wijzigen"}, {"continue", "Doorgaan"},
        {"owner_question", "Wat is uw naam in de chat?\n(De naam die wordt weergegeven in uw WhatsApp-account)"}, {"owner_placeholder", "Bijv: Jan de Vries"},
        {"import_btn", "Importeren"}, {"back", "Terug"}, {"loading_messages", "Berichten laden, even geduld..."},
        {"select_zip_title", "Selecteer WhatsApp ZIP-bestand"}, {"first_message", "Eerste bericht"}, {"delete_chat", "Chat verwijderen"}, {"search", "Zoeken..."}, {"search_tooltip", "Zoeken in berichten (Ctrl+F)"},
        {"empty_chat_hint", "Selecteer een chat of voeg een nieuwe toe"}, {"delete_confirm_title", "Chat verwijderen"},
        {"delete_confirm_text", "Weet u zeker dat u deze chat wilt verwijderen?\nAlle berichten worden verwijderd."}, {"no_results", "Geen resultaten gevonden"},
        {"yes", "Ja"}, {"no", "Nee"}, {"cancel", "Annuleren"}, {"language", "Taal"}, {"select_language", "Taal selecteren"}, {"profile_photo", "Profielfoto"},
        {"name_label", "Naam"}, {"participants_label", "Groepsleden"}, {"contact_name_placeholder", "Contactnaam"}, {"image_files_filter", "Afbeeldingsbestanden (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — %2 berichten geïmporteerd"}, {"conversation", "Gesprek"},
        {"default_owner_name", "Standaard eigenaarsnaam"}, {"owner_name_placeholder", "Uw naam"}, {"not_set", "Niet ingesteld"}, {"default_label", "Standaard"},
        {"profile_library", "Profielbibliotheek"}, {"add_profile", "Profiel toevoegen"}, {"profile_name_label", "Naam:"}, {"add_btn", "Toevoegen"},
        {"optional", "(Optioneel)"}, {"image_selected", "✓ Geselecteerd"}, {"no_profiles_library", "Nog geen profielen. Klik op + om toe te voegen."},
        {"profile_owner_conflict", "Kan geen profiel toevoegen met dezelfde naam als eigenaar"}, {"profile_exists", "Profiel met deze naam bestaat al"},
        {"message_count_text", "berichten"},
        {"january", "Jan"}, {"february", "Feb"}, {"march", "Mrt"}, {"april", "Apr"}, {"may", "Mei"}, {"june", "Jun"},
        {"july", "Jul"}, {"august", "Aug"}, {"september", "Sep"}, {"october", "Okt"}, {"november", "Nov"}, {"december", "Dec"},
        {"calendar_tooltip", "Ga naar datum"},
        {"last_message", "Laatste bericht"},
        {"settings", "Instellingen"},
        {"auto_play_next_voice", "Automatisch achtereenvolgende spraakberichten afspelen"},
        {"open_system", "Openen in systeem"}, {"image_not_found", "Afbeelding niet gevonden"}, {"video", "Video"}, {"deleted_message", "Dit bericht is verwijderd"}, {"you_deleted_message", "U hebt dit bericht verwijderd"}, {"edited", "Bewerkt"}, {"app_version", "versie"}, {"app_copyright", "Copyright door %1"},
        {"lock_chat", "Chat vergrendelen"}, {"unlock_chat", "Deze chat ontgrendelen"}, {"locked_chats", "Vergrendelde chats"}, {"locked_chats_access", "Toegang tot vergrendelde chats"},
        {"lock_chat_title", "Chat vergrendelen"}, {"lock_chat_message", "Deze chat wordt vergrendeld"}, {"lock_chat_set_password", "Stel wachtwoord in om chats te vergrendelen"},
        {"locked_chats_password_title", "Vergrendelde chats"}, {"locked_chats_enter_password", "Voer wachtwoord in voor toegang tot vergrendelde chats"},
        {"password_6_digits", "Wachtwoord moet 6 cijfers zijn"}, {"password_incorrect", "Onjuist wachtwoord"}, {"no_master_password", "Geen wachtwoord ingesteld"},
        {"locked_chats_password", "Wachtwoord voor vergrendelde chats"}, {"no_password", "U hebt geen wachtwoord"}, {"change_password", "Wachtwoord wijzigen"},
        {"old_password", "Oud wachtwoord"}, {"new_password", "Nieuw wachtwoord"}, {"confirm_password", "Bevestig nieuw wachtwoord"}, {"change", "Wijzigen"},
        {"old_password_incorrect", "Oud wachtwoord is onjuist"}, {"passwords_dont_match", "Nieuwe wachtwoorden komen niet overeen"},
        {"no_locked_chats", "Geen vergrendelde chats"}, {"locked_chats_hint", "Selecteer 'Chat vergrendelen' in het 3-puntenmenu om een chat te vergrendelen"}, {"enter", "Invoeren"}
    };
    m_translations["Dutch"].insert(QStringLiteral("media_image"), QStringLiteral("Foto"));
    m_translations["Dutch"].insert(QStringLiteral("media_video"), QStringLiteral("Video"));
    m_translations["Dutch"].insert(QStringLiteral("media_voice"), QStringLiteral("Spraakbericht"));
    m_translations["Dutch"].insert(QStringLiteral("media_audio"), QStringLiteral("Audio"));
    m_translations["Dutch"].insert(QStringLiteral("media_sticker"), QStringLiteral("Sticker"));
    m_translations["Dutch"].insert(QStringLiteral("media_document"), QStringLiteral("Document"));
    m_translations["Dutch"].insert(QStringLiteral("media_unavailable"), QStringLiteral("Media niet beschikbaar"));
    m_translations["Dutch"].insert(QStringLiteral("tap_to_open"), QStringLiteral("Tik om te openen"));
    m_translations["Dutch"].insert(QStringLiteral("location"), QStringLiteral("Locatie"));
    m_translations["Dutch"].insert(QStringLiteral("contact"), QStringLiteral("Contact"));
    m_translations["Dutch"].insert(QStringLiteral("favorites"), QStringLiteral("Favorieten"));
    m_translations["Dutch"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("Toevoegen aan favorieten"));
    m_translations["Dutch"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("Verwijderen uit favorieten"));
    m_translations["Dutch"].insert(QStringLiteral("no_favorites"), QStringLiteral("Geen favorieten"));
    m_translations["Dutch"].insert(QStringLiteral("favorites_hint"), QStringLiteral("Klik met rechts op een bericht om toe te voegen aan favorieten"));
    m_translations["Dutch"].insert(QStringLiteral("media_browser"), QStringLiteral("Media"));
    m_translations["Dutch"].insert(QStringLiteral("media_browser_title"), QStringLiteral("Media"));
    m_translations["Dutch"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("Foto's, video's en bestanden"));
    m_translations["Dutch"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("Foto's"));
    m_translations["Dutch"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("Video's"));
    m_translations["Dutch"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("Documenten"));
    m_translations["Dutch"].insert(QStringLiteral("media_browser_links"), QStringLiteral("Links"));
    m_translations["Dutch"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("Locaties"));
    m_translations["Dutch"].insert(QStringLiteral("no_photos_found"), QStringLiteral("Geen foto's gevonden"));
    m_translations["Dutch"].insert(QStringLiteral("no_videos_found"), QStringLiteral("Geen video's gevonden"));
    m_translations["Dutch"].insert(QStringLiteral("no_documents_found"), QStringLiteral("Geen documenten gevonden"));
    m_translations["Dutch"].insert(QStringLiteral("no_links_found"), QStringLiteral("Geen links gevonden"));
    m_translations["Dutch"].insert(QStringLiteral("no_locations_found"), QStringLiteral("Geen locaties gevonden"));

    // Estonian
    m_translations["Estonian"] = {
        {"contact_info", "Kontakti info"}, {"msg_count", "Sõnumite arv"}, {"messages", "sõnumit"}, {"import_date", "Importimise kuupäev"},
        {"no_chats", "Vestlusi ei leitud\n\nKlõpsake +, et lisada\nuus vestlus"}, {"light_theme", "Hele teema"}, {"dark_theme", "Tume teema"},
        {"new_chat_tooltip", "Lisa uus vestlus"}, {"chat_search_placeholder", "Otsi vestlustest"}, {"importing", "Importimine..."},
        {"bulk_select_tooltip", "Hulgivalik"}, {"bulk_delete_tooltip", "Hulgi kustutamine"}, {"cancel_selection_tooltip", "Tühista"},
        {"import_new", "Lisa uus vestlus"}, {"zip_description", "Valige WhatsAppist eksporditud ZIP-fail."},
        {"select_zip", "Vali ZIP-fail"}, {"change_zip", "Muuda faili"}, {"continue", "Jätka"},
        {"owner_question", "Mis on teie nimi vestluses?\n(WhatsAppi kontol kuvatav nimi)"}, {"owner_placeholder", "Nt: Jaan Tamm"},
        {"import_btn", "Impordi"}, {"back", "Tagasi"}, {"loading_messages", "Sõnumite laadimine, palun oodake..."},
        {"select_zip_title", "Valige WhatsAppi ZIP-fail"}, {"first_message", "Esimene sõnum"}, {"delete_chat", "Kustuta vestlus"}, {"search", "Otsi..."}, {"search_tooltip", "Otsi sõnumitest (Ctrl+F)"},
        {"empty_chat_hint", "Valige vestlus või lisage uus"}, {"delete_confirm_title", "Kustuta vestlus"},
        {"delete_confirm_text", "Kas olete kindel, et soovite selle vestluse kustutada?\nKõik sõnumid eemaldatakse."}, {"no_results", "Tulemusi ei leitud"},
        {"yes", "Jah"}, {"no", "Ei"}, {"cancel", "Tühista"}, {"language", "Keel"}, {"select_language", "Vali keel"}, {"profile_photo", "Profiilipilt"},
        {"name_label", "Nimi"}, {"participants_label", "Grupi liikmed"}, {"contact_name_placeholder", "Kontakti nimi"}, {"image_files_filter", "Pildifailid (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — %2 sõnumit imporditud"}, {"conversation", "Vestlus"},
        {"default_owner_name", "Vaikimisi omaniku nimi"}, {"owner_name_placeholder", "Teie nimi"}, {"not_set", "Määramata"}, {"default_label", "Vaikimisi"},
        {"profile_library", "Profiilide raamatukogu"}, {"add_profile", "Lisa profiil"}, {"profile_name_label", "Nimi:"}, {"add_btn", "Lisa"},
        {"optional", "(Valikuline)"}, {"image_selected", "✓ Valitud"}, {"no_profiles_library", "Profiilid puuduvad. Klõpsake + lisamiseks."},
        {"profile_owner_conflict", "Ei saa lisada profiili omanikuga samanimelisena"}, {"profile_exists", "Selle nimega profiil on juba olemas"},
        {"message_count_text", "sõnumit"},
        {"january", "Jaan"}, {"february", "Veebr"}, {"march", "Märts"}, {"april", "Apr"}, {"may", "Mai"}, {"june", "Juuni"},
        {"july", "Juuli"}, {"august", "Aug"}, {"september", "Sept"}, {"october", "Okt"}, {"november", "Nov"}, {"december", "Dets"},
        {"calendar_tooltip", "Mine kuupäevale"},
        {"last_message", "Viimane sõnum"},
        {"settings", "Seaded"},
        {"auto_play_next_voice", "Esita järjestikused häälsõnumid automaatselt"},
        {"open_system", "Ava süsteemis"}, {"image_not_found", "Pilti ei leitud"}, {"video", "Video"}, {"deleted_message", "See sõnum kustutati"}, {"you_deleted_message", "Te kustutasite selle sõnumi"}, {"edited", "Muudetud"}, {"app_version", "versioon"}, {"app_copyright", "Autoriõigus %1"},
        {"lock_chat", "Lukusta vestlus"}, {"unlock_chat", "Ava see vestlus"}, {"locked_chats", "Lukustatud vestlused"}, {"locked_chats_access", "Juurdepääs lukustatud vestlustele"},
        {"lock_chat_title", "Lukusta vestlus"}, {"lock_chat_message", "See vestlus lukustatakse"}, {"lock_chat_set_password", "Määrake parool vestluste lukustamiseks"},
        {"locked_chats_password_title", "Lukustatud vestlused"}, {"locked_chats_enter_password", "Sisestage parool lukustatud vestlustele juurdepääsuks"},
        {"password_6_digits", "Parool peab olema 6 numbrit"}, {"password_incorrect", "Vale parool"}, {"no_master_password", "Parooli pole määratud"},
        {"locked_chats_password", "Lukustatud vestluste parool"}, {"no_password", "Teil pole parooli"}, {"change_password", "Muuda parooli"},
        {"old_password", "Vana parool"}, {"new_password", "Uus parool"}, {"confirm_password", "Kinnita uus parool"}, {"change", "Muuda"},
        {"old_password_incorrect", "Vana parool on vale"}, {"passwords_dont_match", "Uued paroolid ei ühti"},
        {"no_locked_chats", "Lukustatud vestlused puuduvad"}, {"locked_chats_hint", "Valige 3-punkti menüüst 'Lukusta vestlus' vestluse lukustamiseks"}, {"enter", "Sisene"}
    };
    m_translations["Estonian"].insert(QStringLiteral("media_image"), QStringLiteral("Pilt"));
    m_translations["Estonian"].insert(QStringLiteral("media_video"), QStringLiteral("Video"));
    m_translations["Estonian"].insert(QStringLiteral("media_voice"), QStringLiteral("Häälsõnum"));
    m_translations["Estonian"].insert(QStringLiteral("media_audio"), QStringLiteral("Audio"));
    m_translations["Estonian"].insert(QStringLiteral("media_sticker"), QStringLiteral("Kleeps"));
    m_translations["Estonian"].insert(QStringLiteral("media_document"), QStringLiteral("Dokument"));
    m_translations["Estonian"].insert(QStringLiteral("media_unavailable"), QStringLiteral("Meedia pole saadaval"));
    m_translations["Estonian"].insert(QStringLiteral("tap_to_open"), QStringLiteral("Puuduta avamiseks"));
    m_translations["Estonian"].insert(QStringLiteral("location"), QStringLiteral("Asukoht"));
    m_translations["Estonian"].insert(QStringLiteral("contact"), QStringLiteral("Kontakt"));
    m_translations["Estonian"].insert(QStringLiteral("favorites"), QStringLiteral("Lemmikud"));
    m_translations["Estonian"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("Lisa lemmikutesse"));
    m_translations["Estonian"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("Eemalda lemmikutest"));
    m_translations["Estonian"].insert(QStringLiteral("no_favorites"), QStringLiteral("Lemmikuid pole"));
    m_translations["Estonian"].insert(QStringLiteral("favorites_hint"), QStringLiteral("Paremklõpsake sõnumil lemmikutesse lisamiseks"));
    m_translations["Estonian"].insert(QStringLiteral("media_browser"), QStringLiteral("Meedia"));
    m_translations["Estonian"].insert(QStringLiteral("media_browser_title"), QStringLiteral("Meedia"));
    m_translations["Estonian"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("Pildid, videod ja failid"));
    m_translations["Estonian"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("Pildid"));
    m_translations["Estonian"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("Videod"));
    m_translations["Estonian"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("Dokumendid"));
    m_translations["Estonian"].insert(QStringLiteral("media_browser_links"), QStringLiteral("Lingid"));
    m_translations["Estonian"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("Asukohad"));
    m_translations["Estonian"].insert(QStringLiteral("no_photos_found"), QStringLiteral("Pilte ei leitud"));
    m_translations["Estonian"].insert(QStringLiteral("no_videos_found"), QStringLiteral("Videosid ei leitud"));
    m_translations["Estonian"].insert(QStringLiteral("no_documents_found"), QStringLiteral("Dokumente ei leitud"));
    m_translations["Estonian"].insert(QStringLiteral("no_links_found"), QStringLiteral("Linke ei leitud"));
    m_translations["Estonian"].insert(QStringLiteral("no_locations_found"), QStringLiteral("Asukohti ei leitud"));

    // Filipino
    m_translations["Filipino"] = {
        {"contact_info", "Impormasyon ng contact"}, {"msg_count", "Bilang ng mensahe"}, {"messages", "mga mensahe"}, {"import_date", "Petsa ng pag-import"},
        {"no_chats", "Walang nakitang chat\n\nMag-click ng + upang magdagdag\nng bagong chat"}, {"light_theme", "Maliwanag na tema"}, {"dark_theme", "Madilim na tema"},
        {"new_chat_tooltip", "Magdagdag ng bagong chat"}, {"chat_search_placeholder", "Maghanap sa mga chat"}, {"importing", "Nag-i-import..."},
        {"bulk_select_tooltip", "Bulk na pagpili"}, {"bulk_delete_tooltip", "Bulk na pagtanggal"}, {"cancel_selection_tooltip", "Kanselahin"},
        {"import_new", "Magdagdag ng bagong chat"}, {"zip_description", "Pumili ng ZIP file na na-export mula sa WhatsApp."},
        {"select_zip", "Pumili ng ZIP file"}, {"change_zip", "Palitan ang file"}, {"continue", "Magpatuloy"},
        {"owner_question", "Ano ang iyong pangalan sa chat?\n(Ang pangalang ipinakikita sa iyong WhatsApp account)"}, {"owner_placeholder", "Hal: Juan Dela Cruz"},
        {"import_btn", "I-import"}, {"back", "Bumalik"}, {"loading_messages", "Nilo-load ang mga mensahe, mangyaring maghintay..."},
        {"select_zip_title", "Pumili ng WhatsApp ZIP file"}, {"first_message", "Unang mensahe"}, {"delete_chat", "Tanggalin ang chat"}, {"search", "Maghanap..."}, {"search_tooltip", "Maghanap sa mga mensahe (Ctrl+F)"},
        {"empty_chat_hint", "Pumili ng chat o magdagdag ng bago"}, {"delete_confirm_title", "Tanggalin ang chat"},
        {"delete_confirm_text", "Sigurado ka bang gusto mong tanggalin ang chat na ito?\nAalisin ang lahat ng mensahe."}, {"no_results", "Walang nakitang resulta"},
        {"yes", "Oo"}, {"no", "Hindi"}, {"cancel", "Kanselahin"}, {"language", "Wika"}, {"select_language", "Pumili ng wika"}, {"profile_photo", "Larawan ng profile"},
        {"name_label", "Pangalan"}, {"participants_label", "Mga miyembro ng grupo"}, {"contact_name_placeholder", "Pangalan ng contact"}, {"image_files_filter", "Mga image file (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — %2 na mensahe ang na-import"}, {"conversation", "Pag-uusap"},
        {"default_owner_name", "Default na Pangalan ng May-ari"}, {"owner_name_placeholder", "Iyong pangalan"}, {"not_set", "Hindi naka-set"}, {"default_label", "Default"},
        {"profile_library", "Library ng Profile"}, {"add_profile", "Magdagdag ng Profile"}, {"profile_name_label", "Pangalan:"}, {"add_btn", "Idagdag"},
        {"optional", "(Opsyonal)"}, {"image_selected", "✓ Napili"}, {"no_profiles_library", "Wala pang mga profile. Mag-click ng + upang magdagdag."},
        {"profile_owner_conflict", "Hindi maaaring magdagdag ng profile na may parehong pangalan sa may-ari"}, {"profile_exists", "Mayroon nang profile na may ganitong pangalan"},
        {"message_count_text", "mga mensahe"},
        {"january", "Ene"}, {"february", "Peb"}, {"march", "Mar"}, {"april", "Abr"}, {"may", "Mayo"}, {"june", "Hun"},
        {"july", "Hul"}, {"august", "Ago"}, {"september", "Set"}, {"october", "Okt"}, {"november", "Nob"}, {"december", "Dis"},
        {"calendar_tooltip", "Pumunta sa petsa"},
        {"last_message", "Huling mensahe"},
        {"settings", "Mga setting"},
        {"auto_play_next_voice", "Awtomatikong i-play ang sunod-sunod na voice message"},
        {"open_system", "Buksan sa system"}, {"image_not_found", "Hindi natagpuan ang larawan"}, {"video", "Video"}, {"deleted_message", "Natanggal ang mensaheng ito"}, {"you_deleted_message", "Tinanggal mo ang mensaheng ito"}, {"edited", "Na-edit"}, {"app_version", "bersyon"}, {"app_copyright", "Copyright ni %1"},
        {"lock_chat", "I-lock ang chat"}, {"unlock_chat", "I-unlock ang chat na ito"}, {"locked_chats", "Naka-lock na Mga Chat"}, {"locked_chats_access", "Access sa naka-lock na mga chat"},
        {"lock_chat_title", "I-lock ang chat"}, {"lock_chat_message", "Ila-lock ang chat na ito"}, {"lock_chat_set_password", "Magtakda ng password upang i-lock ang mga chat"},
        {"locked_chats_password_title", "Naka-lock na mga chat"}, {"locked_chats_enter_password", "Ilagay ang password upang ma-access ang naka-lock na mga chat"},
        {"password_6_digits", "Ang password ay dapat 6 na numero"}, {"password_incorrect", "Maling password"}, {"no_master_password", "Walang naka-set na password"},
        {"locked_chats_password", "Password ng Naka-lock na Mga Chat"}, {"no_password", "Wala kang password"}, {"change_password", "Palitan ang password"},
        {"old_password", "Lumang password"}, {"new_password", "Bagong password"}, {"confirm_password", "Kumpirmahin ang bagong password"}, {"change", "Palitan"},
        {"old_password_incorrect", "Mali ang lumang password"}, {"passwords_dont_match", "Hindi tugma ang mga bagong password"},
        {"no_locked_chats", "Walang naka-lock na chat"}, {"locked_chats_hint", "Pumili ng 'I-lock ang chat' mula sa 3-tuldok na menu upang i-lock ang chat"}, {"enter", "Pumasok"}
    };
    m_translations["Filipino"].insert(QStringLiteral("media_image"), QStringLiteral("Larawan"));
    m_translations["Filipino"].insert(QStringLiteral("media_video"), QStringLiteral("Video"));
    m_translations["Filipino"].insert(QStringLiteral("media_voice"), QStringLiteral("Voice message"));
    m_translations["Filipino"].insert(QStringLiteral("media_audio"), QStringLiteral("Audio"));
    m_translations["Filipino"].insert(QStringLiteral("media_sticker"), QStringLiteral("Sticker"));
    m_translations["Filipino"].insert(QStringLiteral("media_document"), QStringLiteral("Dokumento"));
    m_translations["Filipino"].insert(QStringLiteral("media_unavailable"), QStringLiteral("Hindi available ang media"));
    m_translations["Filipino"].insert(QStringLiteral("tap_to_open"), QStringLiteral("I-tap upang buksan"));
    m_translations["Filipino"].insert(QStringLiteral("location"), QStringLiteral("Lokasyon"));
    m_translations["Filipino"].insert(QStringLiteral("contact"), QStringLiteral("Contact"));
    m_translations["Filipino"].insert(QStringLiteral("favorites"), QStringLiteral("Mga Paborito"));
    m_translations["Filipino"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("Idagdag sa mga paborito"));
    m_translations["Filipino"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("Alisin sa mga paborito"));
    m_translations["Filipino"].insert(QStringLiteral("no_favorites"), QStringLiteral("Walang mga paborito"));
    m_translations["Filipino"].insert(QStringLiteral("favorites_hint"), QStringLiteral("Mag-right-click sa mensahe upang idagdag sa mga paborito"));
    m_translations["Filipino"].insert(QStringLiteral("media_browser"), QStringLiteral("Media"));
    m_translations["Filipino"].insert(QStringLiteral("media_browser_title"), QStringLiteral("Media"));
    m_translations["Filipino"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("Mga larawan, video at file"));
    m_translations["Filipino"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("Mga Larawan"));
    m_translations["Filipino"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("Mga Video"));
    m_translations["Filipino"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("Mga Dokumento"));
    m_translations["Filipino"].insert(QStringLiteral("media_browser_links"), QStringLiteral("Mga Link"));
    m_translations["Filipino"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("Mga Lokasyon"));
    m_translations["Filipino"].insert(QStringLiteral("no_photos_found"), QStringLiteral("Walang nakitang larawan"));
    m_translations["Filipino"].insert(QStringLiteral("no_videos_found"), QStringLiteral("Walang nakitang video"));
    m_translations["Filipino"].insert(QStringLiteral("no_documents_found"), QStringLiteral("Walang nakitang dokumento"));
    m_translations["Filipino"].insert(QStringLiteral("no_links_found"), QStringLiteral("Walang nakitang link"));
    m_translations["Filipino"].insert(QStringLiteral("no_locations_found"), QStringLiteral("Walang nakitang lokasyon"));

    // Finnish
    m_translations["Finnish"] = {
        {"contact_info", "Yhteystiedot"}, {"msg_count", "Viestien määrä"}, {"messages", "viestiä"}, {"import_date", "Tuontipäivä"},
        {"no_chats", "Keskusteluja ei löytynyt\n\nNapsauta + lisätäksesi\nuuden keskustelun"}, {"light_theme", "Vaalea teema"}, {"dark_theme", "Tumma teema"},
        {"new_chat_tooltip", "Lisää uusi keskustelu"}, {"chat_search_placeholder", "Hae keskusteluista"}, {"importing", "Tuodaan..."},
        {"bulk_select_tooltip", "Massavalinta"}, {"bulk_delete_tooltip", "Massapoisto"}, {"cancel_selection_tooltip", "Peruuta"},
        {"import_new", "Lisää uusi keskustelu"}, {"zip_description", "Valitse WhatsAppista viety ZIP-tiedosto."},
        {"select_zip", "Valitse ZIP-tiedosto"}, {"change_zip", "Vaihda tiedostoa"}, {"continue", "Jatka"},
        {"owner_question", "Mikä on nimesi keskustelussa?\n(WhatsApp-tilillä näkyvä nimi)"}, {"owner_placeholder", "Esim: Matti Virtanen"},
        {"import_btn", "Tuo"}, {"back", "Takaisin"}, {"loading_messages", "Ladataan viestejä, odota..."},
        {"select_zip_title", "Valitse WhatsApp ZIP-tiedosto"}, {"first_message", "Ensimmäinen viesti"}, {"delete_chat", "Poista keskustelu"}, {"search", "Hae..."}, {"search_tooltip", "Hae viesteistä (Ctrl+F)"},
        {"empty_chat_hint", "Valitse keskustelu tai lisää uusi"}, {"delete_confirm_title", "Poista keskustelu"},
        {"delete_confirm_text", "Haluatko varmasti poistaa tämän keskustelun?\nKaikki viestit poistetaan."}, {"no_results", "Tuloksia ei löytynyt"},
        {"yes", "Kyllä"}, {"no", "Ei"}, {"cancel", "Peruuta"}, {"language", "Kieli"}, {"select_language", "Valitse kieli"}, {"profile_photo", "Profiilikuva"},
        {"name_label", "Nimi"}, {"participants_label", "Ryhmän jäsenet"}, {"contact_name_placeholder", "Yhteyshenkilön nimi"}, {"image_files_filter", "Kuvatiedostot (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — %2 viestiä tuotu"}, {"conversation", "Keskustelu"},
        {"default_owner_name", "Oletusomistajan nimi"}, {"owner_name_placeholder", "Nimesi"}, {"not_set", "Ei asetettu"}, {"default_label", "Oletus"},
        {"profile_library", "Profiilikirjasto"}, {"add_profile", "Lisää profiili"}, {"profile_name_label", "Nimi:"}, {"add_btn", "Lisää"},
        {"optional", "(Valinnainen)"}, {"image_selected", "✓ Valittu"}, {"no_profiles_library", "Ei vielä profiileja. Napsauta + lisätäksesi."},
        {"profile_owner_conflict", "Profiilia ei voi lisätä samalla nimellä kuin omistaja"}, {"profile_exists", "Tällä nimellä on jo profiili"},
        {"message_count_text", "viestiä"},
        {"january", "Tammi"}, {"february", "Helmi"}, {"march", "Maalis"}, {"april", "Huhti"}, {"may", "Touko"}, {"june", "Kesä"},
        {"july", "Heinä"}, {"august", "Elo"}, {"september", "Syys"}, {"october", "Loka"}, {"november", "Marras"}, {"december", "Joulu"},
        {"calendar_tooltip", "Siirry päivämäärään"},
        {"last_message", "Viimeinen viesti"},
        {"settings", "Asetukset"},
        {"auto_play_next_voice", "Toista peräkkäiset ääniviestit automaattisesti"},
        {"open_system", "Avaa järjestelmässä"}, {"image_not_found", "Kuvaa ei löytynyt"}, {"video", "Video"}, {"deleted_message", "Tämä viesti poistettiin"}, {"you_deleted_message", "Poistit tämän viestin"}, {"edited", "Muokattu"}, {"app_version", "versio"}, {"app_copyright", "Tekijänoikeus %1"},
        {"lock_chat", "Lukitse keskustelu"}, {"unlock_chat", "Avaa tämä keskustelu"}, {"locked_chats", "Lukitut keskustelut"}, {"locked_chats_access", "Pääsy lukittuihin keskusteluihin"},
        {"lock_chat_title", "Lukitse keskustelu"}, {"lock_chat_message", "Tämä keskustelu lukitaan"}, {"lock_chat_set_password", "Aseta salasana keskustelujen lukitsemiseen"},
        {"locked_chats_password_title", "Lukitut keskustelut"}, {"locked_chats_enter_password", "Anna salasana päästäksesi lukittuihin keskusteluihin"},
        {"password_6_digits", "Salasanan on oltava 6 numeroa"}, {"password_incorrect", "Väärä salasana"}, {"no_master_password", "Salasanaa ei ole asetettu"},
        {"locked_chats_password", "Lukittujen keskustelujen salasana"}, {"no_password", "Sinulla ei ole salasanaa"}, {"change_password", "Vaihda salasana"},
        {"old_password", "Vanha salasana"}, {"new_password", "Uusi salasana"}, {"confirm_password", "Vahvista uusi salasana"}, {"change", "Vaihda"},
        {"old_password_incorrect", "Vanha salasana on väärä"}, {"passwords_dont_match", "Uudet salasanat eivät täsmää"},
        {"no_locked_chats", "Ei lukittuja keskusteluja"}, {"locked_chats_hint", "Valitse 'Lukitse keskustelu' 3 pisteen valikosta lukitaksesi keskustelun"}, {"enter", "Syötä"}
    };
    m_translations["Finnish"].insert(QStringLiteral("media_image"), QStringLiteral("Kuva"));
    m_translations["Finnish"].insert(QStringLiteral("media_video"), QStringLiteral("Video"));
    m_translations["Finnish"].insert(QStringLiteral("media_voice"), QStringLiteral("Ääniviesti"));
    m_translations["Finnish"].insert(QStringLiteral("media_audio"), QStringLiteral("Ääni"));
    m_translations["Finnish"].insert(QStringLiteral("media_sticker"), QStringLiteral("Tarra"));
    m_translations["Finnish"].insert(QStringLiteral("media_document"), QStringLiteral("Asiakirja"));
    m_translations["Finnish"].insert(QStringLiteral("media_unavailable"), QStringLiteral("Media ei saatavilla"));
    m_translations["Finnish"].insert(QStringLiteral("tap_to_open"), QStringLiteral("Napauta avataksesi"));
    m_translations["Finnish"].insert(QStringLiteral("location"), QStringLiteral("Sijainti"));
    m_translations["Finnish"].insert(QStringLiteral("contact"), QStringLiteral("Yhteystieto"));
    m_translations["Finnish"].insert(QStringLiteral("favorites"), QStringLiteral("Suosikit"));
    m_translations["Finnish"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("Lisää suosikkeihin"));
    m_translations["Finnish"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("Poista suosikeista"));
    m_translations["Finnish"].insert(QStringLiteral("no_favorites"), QStringLiteral("Ei suosikkeja"));
    m_translations["Finnish"].insert(QStringLiteral("favorites_hint"), QStringLiteral("Napsauta viestiä hiiren oikealla painikkeella lisätäksesi suosikkeihin"));
    m_translations["Finnish"].insert(QStringLiteral("media_browser"), QStringLiteral("Media"));
    m_translations["Finnish"].insert(QStringLiteral("media_browser_title"), QStringLiteral("Media"));
    m_translations["Finnish"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("Kuvat, videot ja tiedostot"));
    m_translations["Finnish"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("Kuvat"));
    m_translations["Finnish"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("Videot"));
    m_translations["Finnish"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("Asiakirjat"));
    m_translations["Finnish"].insert(QStringLiteral("media_browser_links"), QStringLiteral("Linkit"));
    m_translations["Finnish"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("Sijainnit"));
    m_translations["Finnish"].insert(QStringLiteral("no_photos_found"), QStringLiteral("Kuvia ei löytynyt"));
    m_translations["Finnish"].insert(QStringLiteral("no_videos_found"), QStringLiteral("Videoita ei löytynyt"));
    m_translations["Finnish"].insert(QStringLiteral("no_documents_found"), QStringLiteral("Asiakirjoja ei löytynyt"));
    m_translations["Finnish"].insert(QStringLiteral("no_links_found"), QStringLiteral("Linkkejä ei löytynyt"));
    m_translations["Finnish"].insert(QStringLiteral("no_locations_found"), QStringLiteral("Sijainteja ei löytynyt"));

    // Greek
    m_translations["Greek"] = {
        {"contact_info", "Πληροφορίες επαφής"}, {"msg_count", "Αριθμός μηνυμάτων"}, {"messages", "μηνύματα"}, {"import_date", "Ημερομηνία εισαγωγής"},
        {"no_chats", "Δεν βρέθηκαν συνομιλίες\n\nΚάντε κλικ στο + για να προσθέσετε\nμια νέα συνομιλία"}, {"light_theme", "Ανοιχτό θέμα"}, {"dark_theme", "Σκούρο θέμα"},
        {"new_chat_tooltip", "Προσθήκη νέας συνομιλίας"}, {"chat_search_placeholder", "Αναζήτηση στις συνομιλίες"}, {"importing", "Εισαγωγή..."},
        {"bulk_select_tooltip", "Μαζική επιλογή"}, {"bulk_delete_tooltip", "Μαζική διαγραφή"}, {"cancel_selection_tooltip", "Ακύρωση"},
        {"import_new", "Προσθήκη νέας συνομιλίας"}, {"zip_description", "Επιλέξτε το αρχείο ZIP που εξήχθη από το WhatsApp."},
        {"select_zip", "Επιλογή αρχείου ZIP"}, {"change_zip", "Αλλαγή αρχείου"}, {"continue", "Συνέχεια"},
        {"owner_question", "Ποιο είναι το όνομά σας στη συνομιλία;\n(Το όνομα που εμφανίζεται στον λογαριασμό σας WhatsApp)"}, {"owner_placeholder", "Π.χ.: Γιάννης Παπαδόπουλος"},
        {"import_btn", "Εισαγωγή"}, {"back", "Πίσω"}, {"loading_messages", "Φόρτωση μηνυμάτων, παρακαλώ περιμένετε..."},
        {"select_zip_title", "Επιλέξτε αρχείο ZIP WhatsApp"}, {"first_message", "Πρώτο μήνυμα"}, {"delete_chat", "Διαγραφή συνομιλίας"}, {"search", "Αναζήτηση..."}, {"search_tooltip", "Αναζήτηση στα μηνύματα (Ctrl+F)"},
        {"empty_chat_hint", "Επιλέξτε μια συνομιλία ή προσθέστε μια νέα"}, {"delete_confirm_title", "Διαγραφή συνομιλίας"},
        {"delete_confirm_text", "Είστε βέβαιοι ότι θέλετε να διαγράψετε αυτή τη συνομιλία;\nΌλα τα μηνύματα θα αφαιρεθούν."}, {"no_results", "Δεν βρέθηκαν αποτελέσματα"},
        {"yes", "Ναι"}, {"no", "Όχι"}, {"cancel", "Ακύρωση"}, {"language", "Γλώσσα"}, {"select_language", "Επιλογή γλώσσας"}, {"profile_photo", "Φωτογραφία προφίλ"},
        {"name_label", "Όνομα"}, {"participants_label", "Μέλη ομάδας"}, {"contact_name_placeholder", "Όνομα επαφής"}, {"image_files_filter", "Αρχεία εικόνας (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — %2 μηνύματα εισήχθησαν"}, {"conversation", "Συνομιλία"},
        {"default_owner_name", "Προεπιλεγμένο όνομα κατόχου"}, {"owner_name_placeholder", "Το όνομά σας"}, {"not_set", "Δεν έχει οριστεί"}, {"default_label", "Προεπιλογή"},
        {"profile_library", "Βιβλιοθήκη προφίλ"}, {"add_profile", "Προσθήκη προφίλ"}, {"profile_name_label", "Όνομα:"}, {"add_btn", "Προσθήκη"},
        {"optional", "(Προαιρετικό)"}, {"image_selected", "✓ Επιλέχθηκε"}, {"no_profiles_library", "Δεν υπάρχουν ακόμα προφίλ. Κάντε κλικ στο + για προσθήκη."},
        {"profile_owner_conflict", "Δεν είναι δυνατή η προσθήκη προφίλ με το ίδιο όνομα με τον κάτοχο"}, {"profile_exists", "Υπάρχει ήδη προφίλ με αυτό το όνομα"},
        {"message_count_text", "μηνύματα"},
        {"january", "Ιαν"}, {"february", "Φεβ"}, {"march", "Μαρ"}, {"april", "Απρ"}, {"may", "Μάι"}, {"june", "Ιουν"},
        {"july", "Ιούλ"}, {"august", "Αύγ"}, {"september", "Σεπ"}, {"october", "Οκτ"}, {"november", "Νοέ"}, {"december", "Δεκ"},
        {"calendar_tooltip", "Μετάβαση σε ημερομηνία"},
        {"last_message", "Τελευταίο μήνυμα"},
        {"settings", "Ρυθμίσεις"},
        {"auto_play_next_voice", "Αυτόματη αναπαραγωγή διαδοχικών φωνητικών μηνυμάτων"},
        {"open_system", "Άνοιγμα στο σύστημα"}, {"image_not_found", "Η εικόνα δεν βρέθηκε"}, {"video", "Βίντεο"}, {"deleted_message", "Αυτό το μήνυμα διαγράφηκε"}, {"you_deleted_message", "Διαγράψατε αυτό το μήνυμα"}, {"edited", "Επεξεργασμένο"}, {"app_version", "έκδοση"}, {"app_copyright", "Πνευματικά δικαιώματα από %1"},
        {"lock_chat", "Κλείδωμα συνομιλίας"}, {"unlock_chat", "Ξεκλείδωμα αυτής της συνομιλίας"}, {"locked_chats", "Κλειδωμένες συνομιλίες"}, {"locked_chats_access", "Πρόσβαση σε κλειδωμένες συνομιλίες"},
        {"lock_chat_title", "Κλείδωμα συνομιλίας"}, {"lock_chat_message", "Αυτή η συνομιλία θα κλειδωθεί"}, {"lock_chat_set_password", "Ορίστε κωδικό πρόσβασης για να κλειδώσετε τις συνομιλίες"},
        {"locked_chats_password_title", "Κλειδωμένες συνομιλίες"}, {"locked_chats_enter_password", "Εισαγάγετε κωδικό πρόσβασης για πρόσβαση σε κλειδωμένες συνομιλίες"},
        {"password_6_digits", "Ο κωδικός πρέπει να είναι 6 ψηφία"}, {"password_incorrect", "Λανθασμένος κωδικός"}, {"no_master_password", "Δεν έχει οριστεί κωδικός"},
        {"locked_chats_password", "Κωδικός κλειδωμένων συνομιλιών"}, {"no_password", "Δεν έχετε κωδικό"}, {"change_password", "Αλλαγή κωδικού"},
        {"old_password", "Παλιός κωδικός"}, {"new_password", "Νέος κωδικός"}, {"confirm_password", "Επιβεβαίωση νέου κωδικού"}, {"change", "Αλλαγή"},
        {"old_password_incorrect", "Ο παλιός κωδικός είναι λανθασμένος"}, {"passwords_dont_match", "Οι νέοι κωδικοί δεν ταιριάζουν"},
        {"no_locked_chats", "Δεν υπάρχουν κλειδωμένες συνομιλίες"}, {"locked_chats_hint", "Επιλέξτε 'Κλείδωμα συνομιλίας' από το μενού 3 τελειών για να κλειδώσετε μια συνομιλία"}, {"enter", "Είσοδος"}
    };
    m_translations["Greek"].insert(QStringLiteral("media_image"), QStringLiteral("Φωτογραφία"));
    m_translations["Greek"].insert(QStringLiteral("media_video"), QStringLiteral("Βίντεο"));
    m_translations["Greek"].insert(QStringLiteral("media_voice"), QStringLiteral("Φωνητικό μήνυμα"));
    m_translations["Greek"].insert(QStringLiteral("media_audio"), QStringLiteral("Ήχος"));
    m_translations["Greek"].insert(QStringLiteral("media_sticker"), QStringLiteral("Αυτοκόλλητο"));
    m_translations["Greek"].insert(QStringLiteral("media_document"), QStringLiteral("Έγγραφο"));
    m_translations["Greek"].insert(QStringLiteral("media_unavailable"), QStringLiteral("Το μέσο δεν είναι διαθέσιμο"));
    m_translations["Greek"].insert(QStringLiteral("tap_to_open"), QStringLiteral("Πατήστε για άνοιγμα"));
    m_translations["Greek"].insert(QStringLiteral("location"), QStringLiteral("Τοποθεσία"));
    m_translations["Greek"].insert(QStringLiteral("contact"), QStringLiteral("Επαφή"));
    m_translations["Greek"].insert(QStringLiteral("favorites"), QStringLiteral("Αγαπημένα"));
    m_translations["Greek"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("Προσθήκη στα αγαπημένα"));
    m_translations["Greek"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("Αφαίρεση από αγαπημένα"));
    m_translations["Greek"].insert(QStringLiteral("no_favorites"), QStringLiteral("Δεν υπάρχουν αγαπημένα"));
    m_translations["Greek"].insert(QStringLiteral("favorites_hint"), QStringLiteral("Κάντε δεξί κλικ σε ένα μήνυμα για να το προσθέσετε στα αγαπημένα"));
    m_translations["Greek"].insert(QStringLiteral("media_browser"), QStringLiteral("Πολυμέσα"));
    m_translations["Greek"].insert(QStringLiteral("media_browser_title"), QStringLiteral("Πολυμέσα"));
    m_translations["Greek"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("Φωτογραφίες, βίντεο και αρχεία"));
    m_translations["Greek"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("Φωτογραφίες"));
    m_translations["Greek"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("Βίντεο"));
    m_translations["Greek"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("Έγγραφα"));
    m_translations["Greek"].insert(QStringLiteral("media_browser_links"), QStringLiteral("Σύνδεσμοι"));
    m_translations["Greek"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("Τοποθεσίες"));
    m_translations["Greek"].insert(QStringLiteral("no_photos_found"), QStringLiteral("Δεν βρέθηκαν φωτογραφίες"));
    m_translations["Greek"].insert(QStringLiteral("no_videos_found"), QStringLiteral("Δεν βρέθηκαν βίντεο"));
    m_translations["Greek"].insert(QStringLiteral("no_documents_found"), QStringLiteral("Δεν βρέθηκαν έγγραφα"));
    m_translations["Greek"].insert(QStringLiteral("no_links_found"), QStringLiteral("Δεν βρέθηκαν σύνδεσμοι"));
    m_translations["Greek"].insert(QStringLiteral("no_locations_found"), QStringLiteral("Δεν βρέθηκαν τοποθεσίες"));

    // Gujarati
    m_translations["Gujarati"] = {
        {"contact_info", "સંપર્ક માહિતી"}, {"msg_count", "સંદેશાઓની સંખ્યા"}, {"messages", "સંદેશાઓ"}, {"import_date", "આયાત તારીખ"},
        {"no_chats", "કોઈ ચેટ મળી નથી\n\nનવી ચેટ ઉમેરવા માટે\n+ ક્લિક કરો"}, {"light_theme", "હલકી થીમ"}, {"dark_theme", "ઘેરી થીમ"},
        {"new_chat_tooltip", "નવી ચેટ ઉમેરો"}, {"chat_search_placeholder", "ચેટ્સમાં શોધો"}, {"importing", "આયાત થઈ રહી છે..."},
        {"bulk_select_tooltip", "બલ્ક પસંદગી"}, {"bulk_delete_tooltip", "બલ્ક કાઢી નાખો"}, {"cancel_selection_tooltip", "રદ કરો"},
        {"import_new", "નવી ચેટ ઉમેરો"}, {"zip_description", "WhatsApp માંથી નિકાસ કરેલ ZIP ફાઇલ પસંદ કરો."},
        {"select_zip", "ZIP ફાઇલ પસંદ કરો"}, {"change_zip", "ફાઇલ બદલો"}, {"continue", "ચાલુ રાખો"},
        {"owner_question", "ચેટમાં તમારું નામ શું છે?\n(તમારા WhatsApp એકાઉન્ટ પર દેખાતું નામ)"}, {"owner_placeholder", "દા.ત.: રાજેશ પટેલ"},
        {"import_btn", "આયાત કરો"}, {"back", "પાછા"}, {"loading_messages", "સંદેશાઓ લોડ થઈ રહ્યા છે, કૃપા કરીને રાહ જુઓ..."},
        {"select_zip_title", "WhatsApp ZIP ફાઇલ પસંદ કરો"}, {"first_message", "પ્રથમ સંદેશો"}, {"delete_chat", "ચેટ કાઢી નાખો"}, {"search", "શોધો..."}, {"search_tooltip", "સંદેશાઓમાં શોધો (Ctrl+F)"},
        {"empty_chat_hint", "ચેટ પસંદ કરો અથવા નવી ઉમેરો"}, {"delete_confirm_title", "ચેટ કાઢી નાખો"},
        {"delete_confirm_text", "શું તમે ખરેખર આ ચેટ કાઢી નાખવા માંગો છો?\nબધા સંદેશાઓ દૂર કરવામાં આવશે."}, {"no_results", "કોઈ પરિણામો મળ્યા નથી"},
        {"yes", "હા"}, {"no", "ના"}, {"cancel", "રદ કરો"}, {"language", "ભાષા"}, {"select_language", "ભાષા પસંદ કરો"}, {"profile_photo", "પ્રોફાઇલ ફોટો"},
        {"name_label", "નામ"}, {"participants_label", "જૂથ સભ્યો"}, {"contact_name_placeholder", "સંપર્કનું નામ"}, {"image_files_filter", "છબી ફાઇલો (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — %2 સંદેશાઓ આયાત થયા"}, {"conversation", "વાર્તાલાપ"},
        {"default_owner_name", "ડિફોલ્ટ માલિકનું નામ"}, {"owner_name_placeholder", "તમારું નામ"}, {"not_set", "સેટ નથી"}, {"default_label", "ડિફોલ્ટ"},
        {"profile_library", "પ્રોફાઇલ લાઇબ્રેરી"}, {"add_profile", "પ્રોફાઇલ ઉમેરો"}, {"profile_name_label", "નામ:"}, {"add_btn", "ઉમેરો"},
        {"optional", "(વૈકલ્પિક)"}, {"image_selected", "✓ પસંદ થયું"}, {"no_profiles_library", "હજી સુધી કોઈ પ્રોફાઇલ નથી. ઉમેરવા માટે + ક્લિક કરો."},
        {"profile_owner_conflict", "માલિક જેવા જ નામથી પ્રોફાઇલ ઉમેરી શકાતી નથી"}, {"profile_exists", "આ નામની પ્રોફાઇલ પહેલેથી અસ્તિત્વમાં છે"},
        {"message_count_text", "સંદેશાઓ"},
        {"january", "જાન્યુ"}, {"february", "ફેબ્રુ"}, {"march", "માર્ચ"}, {"april", "એપ્રિલ"}, {"may", "મે"}, {"june", "જૂન"},
        {"july", "જુલાઈ"}, {"august", "ઑગસ્ટ"}, {"september", "સપ્ટે"}, {"october", "ઑક્ટો"}, {"november", "નવે"}, {"december", "ડિસે"},
        {"calendar_tooltip", "તારીખ પર જાઓ"},
        {"last_message", "છેલ્લો સંદેશો"},
        {"settings", "સેટિંગ્સ"},
        {"auto_play_next_voice", "ક્રમિક વૉઇસ સંદેશાઓ આપમેળે ચલાવો"},
        {"open_system", "સિસ્ટમમાં ખોલો"}, {"image_not_found", "છબી મળી નથી"}, {"video", "વિડિયો"}, {"deleted_message", "આ સંદેશો કાઢી નાખવામાં આવ્યો હતો"}, {"you_deleted_message", "તમે આ સંદેશો કાઢી નાખ્યો"}, {"edited", "સંપાદિત"}, {"app_version", "સંસ્કરણ"}, {"app_copyright", "%1 દ્વારા કોપિરાઇટ"},
        {"lock_chat", "ચેટ લૉક કરો"}, {"unlock_chat", "આ ચેટ અનલૉક કરો"}, {"locked_chats", "લૉક કરેલી ચેટ્સ"}, {"locked_chats_access", "લૉક કરેલી ચેટ્સની ઍક્સેસ"},
        {"lock_chat_title", "ચેટ લૉક કરો"}, {"lock_chat_message", "આ ચેટ લૉક કરવામાં આવશે"}, {"lock_chat_set_password", "ચેટ્સ લૉક કરવા માટે પાસવર્ડ સેટ કરો"},
        {"locked_chats_password_title", "લૉક કરેલી ચેટ્સ"}, {"locked_chats_enter_password", "લૉક કરેલી ચેટ્સને ઍક્સેસ કરવા પાસવર્ડ દાખલ કરો"},
        {"password_6_digits", "પાસવર્ડ 6 અંકનો હોવો જોઈએ"}, {"password_incorrect", "ખોટો પાસવર્ડ"}, {"no_master_password", "કોઈ પાસવર્ડ સેટ નથી"},
        {"locked_chats_password", "લૉક કરેલી ચેટ્સનો પાસવર્ડ"}, {"no_password", "તમારી પાસે પાસવર્ડ નથી"}, {"change_password", "પાસવર્ડ બદલો"},
        {"old_password", "જૂનો પાસવર્ડ"}, {"new_password", "નવો પાસવર્ડ"}, {"confirm_password", "નવા પાસવર્ડની પુષ્ટિ કરો"}, {"change", "બદલો"},
        {"old_password_incorrect", "જૂનો પાસવર્ડ ખોટો છે"}, {"passwords_dont_match", "નવા પાસવર્ડ મેળ ખાતા નથી"},
        {"no_locked_chats", "કોઈ લૉક કરેલી ચેટ્સ નથી"}, {"locked_chats_hint", "ચેટ લૉક કરવા માટે 3-ડૉટ મેનૂમાંથી 'ચેટ લૉક કરો' પસંદ કરો"}, {"enter", "દાખલ કરો"}
    };
    m_translations["Gujarati"].insert(QStringLiteral("media_image"), QStringLiteral("ફોટો"));
    m_translations["Gujarati"].insert(QStringLiteral("media_video"), QStringLiteral("વિડિયો"));
    m_translations["Gujarati"].insert(QStringLiteral("media_voice"), QStringLiteral("વૉઇસ સંદેશો"));
    m_translations["Gujarati"].insert(QStringLiteral("media_audio"), QStringLiteral("ઑડિયો"));
    m_translations["Gujarati"].insert(QStringLiteral("media_sticker"), QStringLiteral("સ્ટીકર"));
    m_translations["Gujarati"].insert(QStringLiteral("media_document"), QStringLiteral("દસ્તાવેજ"));
    m_translations["Gujarati"].insert(QStringLiteral("media_unavailable"), QStringLiteral("મીડિયા ઉપલબ્ધ નથી"));
    m_translations["Gujarati"].insert(QStringLiteral("tap_to_open"), QStringLiteral("ખોલવા માટે ટૅપ કરો"));
    m_translations["Gujarati"].insert(QStringLiteral("location"), QStringLiteral("સ્થાન"));
    m_translations["Gujarati"].insert(QStringLiteral("contact"), QStringLiteral("સંપર્ક"));
    m_translations["Gujarati"].insert(QStringLiteral("favorites"), QStringLiteral("મનપસંદ"));
    m_translations["Gujarati"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("મનપસંદમાં ઉમેરો"));
    m_translations["Gujarati"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("મનપસંદમાંથી દૂર કરો"));
    m_translations["Gujarati"].insert(QStringLiteral("no_favorites"), QStringLiteral("કોઈ મનપસંદ નથી"));
    m_translations["Gujarati"].insert(QStringLiteral("favorites_hint"), QStringLiteral("મનપસંદમાં ઉમેરવા સંદેશ પર જમણું-ક્લિક કરો"));
    m_translations["Gujarati"].insert(QStringLiteral("media_browser"), QStringLiteral("મીડિયા"));
    m_translations["Gujarati"].insert(QStringLiteral("media_browser_title"), QStringLiteral("મીડિયા"));
    m_translations["Gujarati"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("ફોટા, વિડિયો અને ફાઇલો"));
    m_translations["Gujarati"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("ફોટા"));
    m_translations["Gujarati"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("વિડિયો"));
    m_translations["Gujarati"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("દસ્તાવેજો"));
    m_translations["Gujarati"].insert(QStringLiteral("media_browser_links"), QStringLiteral("લિંક્સ"));
    m_translations["Gujarati"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("સ્થાનો"));
    m_translations["Gujarati"].insert(QStringLiteral("no_photos_found"), QStringLiteral("કોઈ ફોટા મળ્યા નથી"));
    m_translations["Gujarati"].insert(QStringLiteral("no_videos_found"), QStringLiteral("કોઈ વિડિયો મળ્યા નથી"));
    m_translations["Gujarati"].insert(QStringLiteral("no_documents_found"), QStringLiteral("કોઈ દસ્તાવેજો મળ્યા નથી"));
    m_translations["Gujarati"].insert(QStringLiteral("no_links_found"), QStringLiteral("કોઈ લિંક્સ મળી નથી"));
    m_translations["Gujarati"].insert(QStringLiteral("no_locations_found"), QStringLiteral("કોઈ સ્થાનો મળ્યાં નથી"));

    // Hebrew
    m_translations["Hebrew"] = {
        {"contact_info", "פרטי איש קשר"}, {"msg_count", "מספר הודעות"}, {"messages", "הודעות"}, {"import_date", "תאריך יבוא"},
        {"no_chats", "לא נמצאו צ'אטים\n\nלחץ על + כדי להוסיף\nצ'אט חדש"}, {"light_theme", "ערכת נושא בהירה"}, {"dark_theme", "ערכת נושא כהה"},
        {"new_chat_tooltip", "הוסף צ'אט חדש"}, {"chat_search_placeholder", "חיפוש בצ'אטים"}, {"importing", "מייבא..."},
        {"bulk_select_tooltip", "בחירה מרובה"}, {"bulk_delete_tooltip", "מחיקה מרובה"}, {"cancel_selection_tooltip", "ביטול"},
        {"import_new", "הוסף צ'אט חדש"}, {"zip_description", "בחר את קובץ ה-ZIP שיוצא מ-WhatsApp."},
        {"select_zip", "בחר קובץ ZIP"}, {"change_zip", "שנה קובץ"}, {"continue", "המשך"},
        {"owner_question", "מה שמך בצ'אט?\n(השם המוצג בחשבון ה-WhatsApp שלך)"}, {"owner_placeholder", "לדוגמה: משה כהן"},
        {"import_btn", "ייבא"}, {"back", "חזור"}, {"loading_messages", "טוען הודעות, אנא המתן..."},
        {"select_zip_title", "בחר קובץ ZIP של WhatsApp"}, {"first_message", "הודעה ראשונה"}, {"delete_chat", "מחק צ'אט"}, {"search", "חיפוש..."}, {"search_tooltip", "חיפוש בהודעות (Ctrl+F)"},
        {"empty_chat_hint", "בחר צ'אט או הוסף חדש"}, {"delete_confirm_title", "מחק צ'אט"},
        {"delete_confirm_text", "האם אתה בטוח שברצונך למחוק את הצ'אט הזה?\nכל ההודעות יוסרו."}, {"no_results", "לא נמצאו תוצאות"},
        {"yes", "כן"}, {"no", "לא"}, {"cancel", "ביטול"}, {"language", "שפה"}, {"select_language", "בחר שפה"}, {"profile_photo", "תמונת פרופיל"},
        {"name_label", "שם"}, {"participants_label", "חברי קבוצה"}, {"contact_name_placeholder", "שם איש קשר"}, {"image_files_filter", "קבצי תמונה (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — %2 הודעות יובאו"}, {"conversation", "שיחה"},
        {"default_owner_name", "שם בעלים ברירת מחדל"}, {"owner_name_placeholder", "השם שלך"}, {"not_set", "לא הוגדר"}, {"default_label", "ברירת מחדל"},
        {"profile_library", "ספריית פרופילים"}, {"add_profile", "הוסף פרופיל"}, {"profile_name_label", "שם:"}, {"add_btn", "הוסף"},
        {"optional", "(אופציונלי)"}, {"image_selected", "✓ נבחר"}, {"no_profiles_library", "אין פרופילים עדיין. לחץ על + כדי להוסיף."},
        {"profile_owner_conflict", "לא ניתן להוסיף פרופיל עם אותו שם כמו הבעלים"}, {"profile_exists", "פרופיל עם שם זה כבר קיים"},
        {"message_count_text", "הודעות"},
        {"january", "ינו׳"}, {"february", "פבר׳"}, {"march", "מרץ"}, {"april", "אפר׳"}, {"may", "מאי"}, {"june", "יוני"},
        {"july", "יולי"}, {"august", "אוג׳"}, {"september", "ספט׳"}, {"october", "אוק׳"}, {"november", "נוב׳"}, {"december", "דצמ׳"},
        {"calendar_tooltip", "עבור לתאריך"},
        {"last_message", "הודעה אחרונה"},
        {"settings", "הגדרות"},
        {"auto_play_next_voice", "הפעל אוטומטית הודעות קוליות רצופות"},
        {"open_system", "פתח במערכת"}, {"image_not_found", "התמונה לא נמצאה"}, {"video", "וידאו"}, {"deleted_message", "הודעה זו נמחקה"}, {"you_deleted_message", "מחקת את ההודעה הזו"}, {"edited", "נערך"}, {"app_version", "גרסה"}, {"app_copyright", "זכויות יוצרים על ידי %1"},
        {"lock_chat", "נעל צ'אט"}, {"unlock_chat", "בטל נעילת צ'אט זה"}, {"locked_chats", "צ'אטים נעולים"}, {"locked_chats_access", "גישה לצ'אטים נעולים"},
        {"lock_chat_title", "נעל צ'אט"}, {"lock_chat_message", "צ'אט זה ינעל"}, {"lock_chat_set_password", "הגדר סיסמה כדי לנעול צ'אטים"},
        {"locked_chats_password_title", "צ'אטים נעולים"}, {"locked_chats_enter_password", "הזן סיסמה כדי לגשת לצ'אטים נעולים"},
        {"password_6_digits", "הסיסמה חייבת להיות בת 6 ספרות"}, {"password_incorrect", "סיסמה שגויה"}, {"no_master_password", "לא הוגדרה סיסמה"},
        {"locked_chats_password", "סיסמת צ'אטים נעולים"}, {"no_password", "אין לך סיסמה"}, {"change_password", "שנה סיסמה"},
        {"old_password", "סיסמה ישנה"}, {"new_password", "סיסמה חדשה"}, {"confirm_password", "אשר סיסמה חדשה"}, {"change", "שנה"},
        {"old_password_incorrect", "הסיסמה הישנה שגויה"}, {"passwords_dont_match", "הסיסמאות החדשות אינן תואמות"},
        {"no_locked_chats", "אין צ'אטים נעולים"}, {"locked_chats_hint", "בחר 'נעל צ'אט' מתפריט 3 הנקודות כדי לנעול צ'אט"}, {"enter", "הכנס"}
    };
    m_translations["Hebrew"].insert(QStringLiteral("media_image"), QStringLiteral("תמונה"));
    m_translations["Hebrew"].insert(QStringLiteral("media_video"), QStringLiteral("וידאו"));
    m_translations["Hebrew"].insert(QStringLiteral("media_voice"), QStringLiteral("הודעה קולית"));
    m_translations["Hebrew"].insert(QStringLiteral("media_audio"), QStringLiteral("אודיו"));
    m_translations["Hebrew"].insert(QStringLiteral("media_sticker"), QStringLiteral("מדבקה"));
    m_translations["Hebrew"].insert(QStringLiteral("media_document"), QStringLiteral("מסמך"));
    m_translations["Hebrew"].insert(QStringLiteral("media_unavailable"), QStringLiteral("מדיה לא זמינה"));
    m_translations["Hebrew"].insert(QStringLiteral("tap_to_open"), QStringLiteral("הקש כדי לפתוח"));
    m_translations["Hebrew"].insert(QStringLiteral("location"), QStringLiteral("מיקום"));
    m_translations["Hebrew"].insert(QStringLiteral("contact"), QStringLiteral("איש קשר"));
    m_translations["Hebrew"].insert(QStringLiteral("favorites"), QStringLiteral("מועדפים"));
    m_translations["Hebrew"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("הוסף למועדפים"));
    m_translations["Hebrew"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("הסר ממועדפים"));
    m_translations["Hebrew"].insert(QStringLiteral("no_favorites"), QStringLiteral("אין מועדפים"));
    m_translations["Hebrew"].insert(QStringLiteral("favorites_hint"), QStringLiteral("לחץ לחיצה ימנית על הודעה כדי להוסיף למועדפים"));
    m_translations["Hebrew"].insert(QStringLiteral("media_browser"), QStringLiteral("מדיה"));
    m_translations["Hebrew"].insert(QStringLiteral("media_browser_title"), QStringLiteral("מדיה"));
    m_translations["Hebrew"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("תמונות, סרטונים וקבצים"));
    m_translations["Hebrew"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("תמונות"));
    m_translations["Hebrew"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("סרטונים"));
    m_translations["Hebrew"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("מסמכים"));
    m_translations["Hebrew"].insert(QStringLiteral("media_browser_links"), QStringLiteral("קישורים"));
    m_translations["Hebrew"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("מיקומים"));
    m_translations["Hebrew"].insert(QStringLiteral("no_photos_found"), QStringLiteral("לא נמצאו תמונות"));
    m_translations["Hebrew"].insert(QStringLiteral("no_videos_found"), QStringLiteral("לא נמצאו סרטונים"));
    m_translations["Hebrew"].insert(QStringLiteral("no_documents_found"), QStringLiteral("לא נמצאו מסמכים"));
    m_translations["Hebrew"].insert(QStringLiteral("no_links_found"), QStringLiteral("לא נמצאו קישורים"));
    m_translations["Hebrew"].insert(QStringLiteral("no_locations_found"), QStringLiteral("לא נמצאו מיקומים"));

    // Hungarian
    m_translations["Hungarian"] = {
        {"contact_info", "Kapcsolat adatai"}, {"msg_count", "Üzenetek száma"}, {"messages", "üzenet"}, {"import_date", "Importálás dátuma"},
        {"no_chats", "Nincs csevegés\n\nKattints a + gombra\núj csevegés hozzáadásához"}, {"light_theme", "Világos téma"}, {"dark_theme", "Sötét téma"},
        {"new_chat_tooltip", "Új csevegés hozzáadása"}, {"chat_search_placeholder", "Keresés a csevegésekben"}, {"importing", "Importálás..."},
        {"bulk_select_tooltip", "Tömeges kijelölés"}, {"bulk_delete_tooltip", "Tömeges törlés"}, {"cancel_selection_tooltip", "Mégse"},
        {"import_new", "Új csevegés hozzáadása"}, {"zip_description", "Válaszd ki a WhatsApp-ból exportált ZIP fájlt."},
        {"select_zip", "ZIP fájl kiválasztása"}, {"change_zip", "Fájl módosítása"}, {"continue", "Folytatás"},
        {"owner_question", "Mi a neved a csevegésben?\n(A WhatsApp fiókodban megjelenő név)"}, {"owner_placeholder", "Pl.: Kiss János"},
        {"import_btn", "Importálás"}, {"back", "Vissza"}, {"loading_messages", "Üzenetek betöltése, kérlek várj..."},
        {"select_zip_title", "WhatsApp ZIP fájl kiválasztása"}, {"first_message", "Első üzenet"}, {"delete_chat", "Csevegés törlése"}, {"search", "Keresés..."}, {"search_tooltip", "Keresés az üzenetekben (Ctrl+F)"},
        {"empty_chat_hint", "Válassz egy csevegést vagy adj hozzá újat"}, {"delete_confirm_title", "Csevegés törlése"},
        {"delete_confirm_text", "Biztosan törölni szeretnéd ezt a csevegést?\nMinden üzenet törlődni fog."}, {"no_results", "Nincs találat"},
        {"yes", "Igen"}, {"no", "Nem"}, {"cancel", "Mégse"}, {"language", "Nyelv"}, {"select_language", "Nyelv kiválasztása"}, {"profile_photo", "Profilkép"},
        {"name_label", "Név"}, {"participants_label", "Csoport résztvevői"}, {"contact_name_placeholder", "Kapcsolat neve"}, {"image_files_filter", "Képfájlok (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — %2 üzenet importálva"}, {"conversation", "Beszélgetés"},
        {"default_owner_name", "Alapértelmezett tulajdonos név"}, {"owner_name_placeholder", "A neved"}, {"not_set", "Nincs beállítva"}, {"default_label", "Alapértelmezett"},
        {"profile_library", "Profilkönyvtár"}, {"add_profile", "Profil hozzáadása"}, {"profile_name_label", "Név:"}, {"add_btn", "Hozzáadás"},
        {"optional", "(Opcionális)"}, {"image_selected", "✓ Kiválasztva"}, {"no_profiles_library", "Még nincs profil. Kattints a + gombra a hozzáadáshoz."},
        {"profile_owner_conflict", "Nem lehet azonos nevű profilt hozzáadni, mint a tulajdonos"}, {"profile_exists", "Ezzel a névvel már létezik profil"},
        {"message_count_text", "üzenet"},
        {"january", "Jan"}, {"february", "Feb"}, {"march", "Már"}, {"april", "Ápr"}, {"may", "Máj"}, {"june", "Jún"},
        {"july", "Júl"}, {"august", "Aug"}, {"september", "Szep"}, {"october", "Okt"}, {"november", "Nov"}, {"december", "Dec"},
        {"calendar_tooltip", "Ugrás dátumhoz"},
        {"last_message", "Utolsó üzenet"},
        {"settings", "Beállítások"},
        {"auto_play_next_voice", "Hangüzenetek automatikus lejátszása sorban"},
        {"open_system", "Megnyitás a rendszerben"}, {"image_not_found", "Kép nem található"}, {"video", "Videó"}, {"deleted_message", "Ez az üzenet törölve lett"}, {"you_deleted_message", "Törölted ezt az üzenetet"}, {"edited", "Szerkesztve"}, {"app_version", "verzió"}, {"app_copyright", "Szerzői jog %1"},
        {"lock_chat", "Csevegés zárolása"}, {"unlock_chat", "Csevegés feloldása"}, {"locked_chats", "Zárolt csevegések"}, {"locked_chats_access", "Hozzáférés a zárolt csevegésekhez"},
        {"lock_chat_title", "Csevegés zárolása"}, {"lock_chat_message", "Ez a csevegés zárolva lesz"}, {"lock_chat_set_password", "Állíts be jelszót a csevegések zárolásához"},
        {"locked_chats_password_title", "Zárolt csevegések"}, {"locked_chats_enter_password", "Írd be a jelszót a zárolt csevegések eléréséhez"},
        {"password_6_digits", "A jelszónak 6 számjegyből kell állnia"}, {"password_incorrect", "Helytelen jelszó"}, {"no_master_password", "Nincs beállítva jelszó"},
        {"locked_chats_password", "Zárolt csevegések jelszava"}, {"no_password", "Nincs jelszavad"}, {"change_password", "Jelszó módosítása"},
        {"old_password", "Régi jelszó"}, {"new_password", "Új jelszó"}, {"confirm_password", "Új jelszó megerősítése"}, {"change", "Módosítás"},
        {"old_password_incorrect", "A régi jelszó helytelen"}, {"passwords_dont_match", "Az új jelszavak nem egyeznek"},
        {"no_locked_chats", "Nincs zárolt csevegés"}, {"locked_chats_hint", "Válaszd a 'Csevegés zárolása' opciót a 3 pontos menüből a zároláshoz"}, {"enter", "Belépés"}
    };
    m_translations["Hungarian"].insert(QStringLiteral("media_image"), QStringLiteral("Fénykép"));
    m_translations["Hungarian"].insert(QStringLiteral("media_video"), QStringLiteral("Videó"));
    m_translations["Hungarian"].insert(QStringLiteral("media_voice"), QStringLiteral("Hangüzenet"));
    m_translations["Hungarian"].insert(QStringLiteral("media_audio"), QStringLiteral("Audió"));
    m_translations["Hungarian"].insert(QStringLiteral("media_sticker"), QStringLiteral("Matrica"));
    m_translations["Hungarian"].insert(QStringLiteral("media_document"), QStringLiteral("Dokumentum"));
    m_translations["Hungarian"].insert(QStringLiteral("media_unavailable"), QStringLiteral("Média nem elérhető"));
    m_translations["Hungarian"].insert(QStringLiteral("tap_to_open"), QStringLiteral("Koppints a megnyitáshoz"));
    m_translations["Hungarian"].insert(QStringLiteral("location"), QStringLiteral("Helyszín"));
    m_translations["Hungarian"].insert(QStringLiteral("contact"), QStringLiteral("Kapcsolat"));
    m_translations["Hungarian"].insert(QStringLiteral("favorites"), QStringLiteral("Kedvencek"));
    m_translations["Hungarian"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("Hozzáadás a kedvencekhez"));
    m_translations["Hungarian"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("Eltávolítás a kedvencekből"));
    m_translations["Hungarian"].insert(QStringLiteral("no_favorites"), QStringLiteral("Nincs kedvenc"));
    m_translations["Hungarian"].insert(QStringLiteral("favorites_hint"), QStringLiteral("Jobb gombbal kattints egy üzenetre a kedvencekhez adáshoz"));
    m_translations["Hungarian"].insert(QStringLiteral("media_browser"), QStringLiteral("Média"));
    m_translations["Hungarian"].insert(QStringLiteral("media_browser_title"), QStringLiteral("Média"));
    m_translations["Hungarian"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("Fényképek, videók és fájlok"));
    m_translations["Hungarian"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("Fényképek"));
    m_translations["Hungarian"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("Videók"));
    m_translations["Hungarian"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("Dokumentumok"));
    m_translations["Hungarian"].insert(QStringLiteral("media_browser_links"), QStringLiteral("Linkek"));
    m_translations["Hungarian"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("Helyszínek"));
    m_translations["Hungarian"].insert(QStringLiteral("no_photos_found"), QStringLiteral("Nem található fénykép"));
    m_translations["Hungarian"].insert(QStringLiteral("no_videos_found"), QStringLiteral("Nem található videó"));
    m_translations["Hungarian"].insert(QStringLiteral("no_documents_found"), QStringLiteral("Nem található dokumentum"));
    m_translations["Hungarian"].insert(QStringLiteral("no_links_found"), QStringLiteral("Nem található link"));
    m_translations["Hungarian"].insert(QStringLiteral("no_locations_found"), QStringLiteral("Nem található helyszín"));

    // Indonesian
    m_translations["Indonesian"] = {
        {"contact_info", "Info kontak"}, {"msg_count", "Jumlah pesan"}, {"messages", "pesan"}, {"import_date", "Tanggal impor"},
        {"no_chats", "Tidak ada obrolan\n\nKlik + untuk menambahkan\nobrolan baru"}, {"light_theme", "Tema terang"}, {"dark_theme", "Tema gelap"},
        {"new_chat_tooltip", "Tambahkan obrolan baru"}, {"chat_search_placeholder", "Cari di obrolan"}, {"importing", "Mengimpor..."},
        {"bulk_select_tooltip", "Pilih massal"}, {"bulk_delete_tooltip", "Hapus massal"}, {"cancel_selection_tooltip", "Batal"},
        {"import_new", "Tambahkan obrolan baru"}, {"zip_description", "Pilih file ZIP yang diekspor dari WhatsApp."},
        {"select_zip", "Pilih file ZIP"}, {"change_zip", "Ubah file"}, {"continue", "Lanjutkan"},
        {"owner_question", "Apa nama Anda dalam obrolan?\n(Nama yang muncul di akun WhatsApp Anda)"}, {"owner_placeholder", "Mis: Budi Santoso"},
        {"import_btn", "Impor"}, {"back", "Kembali"}, {"loading_messages", "Memuat pesan, harap tunggu..."},
        {"select_zip_title", "Pilih file ZIP WhatsApp"}, {"first_message", "Pesan pertama"}, {"delete_chat", "Hapus obrolan"}, {"search", "Cari..."}, {"search_tooltip", "Cari di pesan (Ctrl+F)"},
        {"empty_chat_hint", "Pilih obrolan atau tambahkan yang baru"}, {"delete_confirm_title", "Hapus obrolan"},
        {"delete_confirm_text", "Apakah Anda yakin ingin menghapus obrolan ini?\nSemua pesan akan dihapus."}, {"no_results", "Tidak ada hasil"},
        {"yes", "Ya"}, {"no", "Tidak"}, {"cancel", "Batal"}, {"language", "Bahasa"}, {"select_language", "Pilih bahasa"}, {"profile_photo", "Foto profil"},
        {"name_label", "Nama"}, {"participants_label", "Peserta grup"}, {"contact_name_placeholder", "Nama kontak"}, {"image_files_filter", "File gambar (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — %2 pesan diimpor"}, {"conversation", "Percakapan"},
        {"default_owner_name", "Nama Pemilik Default"}, {"owner_name_placeholder", "Nama Anda"}, {"not_set", "Belum diatur"}, {"default_label", "Default"},
        {"profile_library", "Perpustakaan Profil"}, {"add_profile", "Tambah Profil"}, {"profile_name_label", "Nama:"}, {"add_btn", "Tambah"},
        {"optional", "(Opsional)"}, {"image_selected", "✓ Dipilih"}, {"no_profiles_library", "Belum ada profil. Klik + untuk menambahkan."},
        {"profile_owner_conflict", "Tidak dapat menambahkan profil dengan nama yang sama dengan pemilik"}, {"profile_exists", "Profil dengan nama ini sudah ada"},
        {"message_count_text", "pesan"},
        {"january", "Jan"}, {"february", "Feb"}, {"march", "Mar"}, {"april", "Apr"}, {"may", "Mei"}, {"june", "Jun"},
        {"july", "Jul"}, {"august", "Agu"}, {"september", "Sep"}, {"october", "Okt"}, {"november", "Nov"}, {"december", "Des"},
        {"calendar_tooltip", "Lompat ke tanggal"},
        {"last_message", "Pesan terakhir"},
        {"settings", "Pengaturan"},
        {"auto_play_next_voice", "Putar otomatis pesan suara berurutan"},
        {"open_system", "Buka di sistem"}, {"image_not_found", "Gambar tidak ditemukan"}, {"video", "Video"}, {"deleted_message", "Pesan ini telah dihapus"}, {"you_deleted_message", "Anda menghapus pesan ini"}, {"edited", "Diedit"}, {"app_version", "versi"}, {"app_copyright", "Hak cipta oleh %1"},
        {"lock_chat", "Kunci obrolan"}, {"unlock_chat", "Buka kunci obrolan ini"}, {"locked_chats", "Obrolan Terkunci"}, {"locked_chats_access", "Akses obrolan terkunci"},
        {"lock_chat_title", "Kunci obrolan"}, {"lock_chat_message", "Obrolan ini akan dikunci"}, {"lock_chat_set_password", "Atur kata sandi untuk mengunci obrolan"},
        {"locked_chats_password_title", "Obrolan terkunci"}, {"locked_chats_enter_password", "Masukkan kata sandi untuk mengakses obrolan terkunci"},
        {"password_6_digits", "Kata sandi harus 6 digit"}, {"password_incorrect", "Kata sandi salah"}, {"no_master_password", "Kata sandi belum diatur"},
        {"locked_chats_password", "Kata Sandi Obrolan Terkunci"}, {"no_password", "Anda belum memiliki kata sandi"}, {"change_password", "Ubah kata sandi"},
        {"old_password", "Kata sandi lama"}, {"new_password", "Kata sandi baru"}, {"confirm_password", "Konfirmasi kata sandi baru"}, {"change", "Ubah"},
        {"old_password_incorrect", "Kata sandi lama salah"}, {"passwords_dont_match", "Kata sandi baru tidak cocok"},
        {"no_locked_chats", "Tidak ada obrolan terkunci"}, {"locked_chats_hint", "Pilih 'Kunci obrolan' dari menu 3 titik untuk mengunci obrolan"}, {"enter", "Masuk"}
    };
    m_translations["Indonesian"].insert(QStringLiteral("media_image"), QStringLiteral("Foto"));
    m_translations["Indonesian"].insert(QStringLiteral("media_video"), QStringLiteral("Video"));
    m_translations["Indonesian"].insert(QStringLiteral("media_voice"), QStringLiteral("Pesan suara"));
    m_translations["Indonesian"].insert(QStringLiteral("media_audio"), QStringLiteral("Audio"));
    m_translations["Indonesian"].insert(QStringLiteral("media_sticker"), QStringLiteral("Stiker"));
    m_translations["Indonesian"].insert(QStringLiteral("media_document"), QStringLiteral("Dokumen"));
    m_translations["Indonesian"].insert(QStringLiteral("media_unavailable"), QStringLiteral("Media tidak tersedia"));
    m_translations["Indonesian"].insert(QStringLiteral("tap_to_open"), QStringLiteral("Ketuk untuk membuka"));
    m_translations["Indonesian"].insert(QStringLiteral("location"), QStringLiteral("Lokasi"));
    m_translations["Indonesian"].insert(QStringLiteral("contact"), QStringLiteral("Kontak"));
    m_translations["Indonesian"].insert(QStringLiteral("favorites"), QStringLiteral("Favorit"));
    m_translations["Indonesian"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("Tambahkan ke favorit"));
    m_translations["Indonesian"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("Hapus dari favorit"));
    m_translations["Indonesian"].insert(QStringLiteral("no_favorites"), QStringLiteral("Tidak ada favorit"));
    m_translations["Indonesian"].insert(QStringLiteral("favorites_hint"), QStringLiteral("Klik kanan pesan untuk menambahkan ke favorit"));
    m_translations["Indonesian"].insert(QStringLiteral("media_browser"), QStringLiteral("Media"));
    m_translations["Indonesian"].insert(QStringLiteral("media_browser_title"), QStringLiteral("Media"));
    m_translations["Indonesian"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("Foto, video, dan file"));
    m_translations["Indonesian"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("Foto"));
    m_translations["Indonesian"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("Video"));
    m_translations["Indonesian"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("Dokumen"));
    m_translations["Indonesian"].insert(QStringLiteral("media_browser_links"), QStringLiteral("Tautan"));
    m_translations["Indonesian"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("Lokasi"));
    m_translations["Indonesian"].insert(QStringLiteral("no_photos_found"), QStringLiteral("Tidak ada foto"));
    m_translations["Indonesian"].insert(QStringLiteral("no_videos_found"), QStringLiteral("Tidak ada video"));
    m_translations["Indonesian"].insert(QStringLiteral("no_documents_found"), QStringLiteral("Tidak ada dokumen"));
    m_translations["Indonesian"].insert(QStringLiteral("no_links_found"), QStringLiteral("Tidak ada tautan"));
    m_translations["Indonesian"].insert(QStringLiteral("no_locations_found"), QStringLiteral("Tidak ada lokasi"));

    // Irish
    m_translations["Irish"] = {
        {"contact_info", "Eolas teagmhála"}, {"msg_count", "Líon teachtaireachtaí"}, {"messages", "teachtaireachtaí"}, {"import_date", "Dáta iompórtála"},
        {"no_chats", "Níor aimsíodh comhráite\n\nCliceáil + chun\ncomhrá nua a chur leis"}, {"light_theme", "Téama éadrom"}, {"dark_theme", "Téama dorcha"},
        {"new_chat_tooltip", "Cuir comhrá nua leis"}, {"chat_search_placeholder", "Cuardaigh sna comhráite"}, {"importing", "Ag iompórtáil..."},
        {"bulk_select_tooltip", "Roghnú il"}, {"bulk_delete_tooltip", "Scrios il"}, {"cancel_selection_tooltip", "Cealaigh"},
        {"import_new", "Cuir comhrá nua leis"}, {"zip_description", "Roghnaigh an comhad ZIP a easportáladh ó WhatsApp."},
        {"select_zip", "Roghnaigh comhad ZIP"}, {"change_zip", "Athraigh comhad"}, {"continue", "Lean ar aghaidh"},
        {"owner_question", "Cad é d'ainm sa chomhrá?\n(An t-ainm a thaispeántar i do chuntas WhatsApp)"}, {"owner_placeholder", "e.g. Seán Ó Briain"},
        {"import_btn", "Iompórtáil"}, {"back", "Ar ais"}, {"loading_messages", "Teachtaireachtaí á lódáil, fan le do thoil..."},
        {"select_zip_title", "Roghnaigh comhad ZIP WhatsApp"}, {"first_message", "Chéad teachtaireacht"}, {"delete_chat", "Scrios comhrá"}, {"search", "Cuardaigh..."}, {"search_tooltip", "Cuardaigh sna teachtaireachtaí (Ctrl+F)"},
        {"empty_chat_hint", "Roghnaigh comhrá nó cuir ceann nua leis"}, {"delete_confirm_title", "Scrios comhrá"},
        {"delete_confirm_text", "An bhfuil tú cinnte gur mhaith leat an comhrá seo a scriosadh?\nScriosfar na teachtaireachtaí go léir."}, {"no_results", "Níor aimsíodh torthaí"},
        {"yes", "Tá"}, {"no", "Níl"}, {"cancel", "Cealaigh"}, {"language", "Teanga"}, {"select_language", "Roghnaigh teanga"}, {"profile_photo", "Grianghraf próifíle"},
        {"name_label", "Ainm"}, {"participants_label", "Rannpháirtithe grúpa"}, {"contact_name_placeholder", "Ainm teagmhála"}, {"image_files_filter", "Comhaid íomhá (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — %2 teachtaireacht iompórtáilte"}, {"conversation", "Comhrá"},
        {"default_owner_name", "Ainm Úinéara Réamhshocraithe"}, {"owner_name_placeholder", "D'ainm"}, {"not_set", "Gan socrú"}, {"default_label", "Réamhshocrú"},
        {"profile_library", "Leabharlann Próifíle"}, {"add_profile", "Cuir Próifíl Leis"}, {"profile_name_label", "Ainm:"}, {"add_btn", "Cuir leis"},
        {"optional", "(Roghnach)"}, {"image_selected", "✓ Roghnaithe"}, {"no_profiles_library", "Níl aon phróifílí fós. Cliceáil + chun ceann a chur leis."},
        {"profile_owner_conflict", "Ní féidir próifíl leis an ainm céanna leis an úinéir a chur leis"}, {"profile_exists", "Tá próifíl leis an ainm seo ann cheana"},
        {"message_count_text", "teachtaireachtaí"},
        {"january", "Ean"}, {"february", "Fea"}, {"march", "Már"}, {"april", "Aib"}, {"may", "Bea"}, {"june", "Mei"},
        {"july", "Iúi"}, {"august", "Lún"}, {"september", "MFó"}, {"october", "DFó"}, {"november", "Sam"}, {"december", "Nol"},
        {"calendar_tooltip", "Léim go dáta"},
        {"last_message", "Teachtaireacht dheireanach"},
        {"settings", "Socruithe"},
        {"auto_play_next_voice", "Seinn teachtaireachtaí glóir as a chéile go huathoibríoch"},
        {"open_system", "Oscail sa chóras"}, {"image_not_found", "Níor aimsíodh an íomhá"}, {"video", "Físeán"}, {"deleted_message", "Scriosadh an teachtaireacht seo"}, {"you_deleted_message", "Scrios tú an teachtaireacht seo"}, {"edited", "Curtha in eagar"}, {"app_version", "leagan"}, {"app_copyright", "Cóipcheart le %1"},
        {"lock_chat", "Glasáil comhrá"}, {"unlock_chat", "Díghlasáil an comhrá seo"}, {"locked_chats", "Comhráite Glasáilte"}, {"locked_chats_access", "Rochtain ar chomhráite glasáilte"},
        {"lock_chat_title", "Glasáil comhrá"}, {"lock_chat_message", "Glasálfar an comhrá seo"}, {"lock_chat_set_password", "Socraigh pasfhocal chun comhráite a ghlasáil"},
        {"locked_chats_password_title", "Comhráite glasáilte"}, {"locked_chats_enter_password", "Cuir isteach pasfhocal chun rochtain a fháil ar chomhráite glasáilte"},
        {"password_6_digits", "Caithfidh an pasfhocal 6 dhigit a bheith ann"}, {"password_incorrect", "Pasfhocal mícheart"}, {"no_master_password", "Níor socraíodh pasfhocal"},
        {"locked_chats_password", "Pasfhocal Comhráite Glasáilte"}, {"no_password", "Níl pasfhocal agat"}, {"change_password", "Athraigh pasfhocal"},
        {"old_password", "Sean-phasfhocal"}, {"new_password", "Pasfhocal nua"}, {"confirm_password", "Deimhnigh an pasfhocal nua"}, {"change", "Athraigh"},
        {"old_password_incorrect", "Tá an sean-phasfhocal mícheart"}, {"passwords_dont_match", "Ní mheaitseálann na pasfhocail nua"},
        {"no_locked_chats", "Níl aon chomhráite glasáilte"}, {"locked_chats_hint", "Roghnaigh 'Glasáil comhrá' ón roghchlár 3 phointe chun comhrá a ghlasáil"}, {"enter", "Isteach"}
    };
    m_translations["Irish"].insert(QStringLiteral("media_image"), QStringLiteral("Grianghraf"));
    m_translations["Irish"].insert(QStringLiteral("media_video"), QStringLiteral("Físeán"));
    m_translations["Irish"].insert(QStringLiteral("media_voice"), QStringLiteral("Teachtaireacht ghuthán"));
    m_translations["Irish"].insert(QStringLiteral("media_audio"), QStringLiteral("Fuaim"));
    m_translations["Irish"].insert(QStringLiteral("media_sticker"), QStringLiteral("Greamán"));
    m_translations["Irish"].insert(QStringLiteral("media_document"), QStringLiteral("Cáipéis"));
    m_translations["Irish"].insert(QStringLiteral("media_unavailable"), QStringLiteral("Meáin nach bhfuil ar fáil"));
    m_translations["Irish"].insert(QStringLiteral("tap_to_open"), QStringLiteral("Tapáil chun oscailt"));
    m_translations["Irish"].insert(QStringLiteral("location"), QStringLiteral("Suíomh"));
    m_translations["Irish"].insert(QStringLiteral("contact"), QStringLiteral("Teagmháil"));
    m_translations["Irish"].insert(QStringLiteral("favorites"), QStringLiteral("Ceanáin"));
    m_translations["Irish"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("Cuir le ceanáin"));
    m_translations["Irish"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("Bain ó cheanáin"));
    m_translations["Irish"].insert(QStringLiteral("no_favorites"), QStringLiteral("Níl aon cheanáin"));
    m_translations["Irish"].insert(QStringLiteral("favorites_hint"), QStringLiteral("Deaschliceáil teachtaireacht chun cur le ceanáin"));
    m_translations["Irish"].insert(QStringLiteral("media_browser"), QStringLiteral("Meáin"));
    m_translations["Irish"].insert(QStringLiteral("media_browser_title"), QStringLiteral("Meáin"));
    m_translations["Irish"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("Grianghraif, físeáin agus comhaid"));
    m_translations["Irish"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("Grianghraif"));
    m_translations["Irish"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("Físeáin"));
    m_translations["Irish"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("Cáipéisí"));
    m_translations["Irish"].insert(QStringLiteral("media_browser_links"), QStringLiteral("Naisc"));
    m_translations["Irish"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("Suíomhanna"));
    m_translations["Irish"].insert(QStringLiteral("no_photos_found"), QStringLiteral("Níor aimsíodh grianghraif"));
    m_translations["Irish"].insert(QStringLiteral("no_videos_found"), QStringLiteral("Níor aimsíodh físeáin"));
    m_translations["Irish"].insert(QStringLiteral("no_documents_found"), QStringLiteral("Níor aimsíodh cáipéisí"));
    m_translations["Irish"].insert(QStringLiteral("no_links_found"), QStringLiteral("Níor aimsíodh naisc"));
    m_translations["Irish"].insert(QStringLiteral("no_locations_found"), QStringLiteral("Níor aimsíodh suíomhanna"));

    // Kannada
    m_translations["Kannada"] = {
        {"contact_info", "ಸಂಪರ್ಕ ಮಾಹಿತಿ"}, {"msg_count", "ಸಂದೇಶಗಳ ಸಂಖ್ಯೆ"}, {"messages", "ಸಂದೇಶಗಳು"}, {"import_date", "ಆಮದು ದಿನಾಂಕ"},
        {"no_chats", "ಯಾವುದೇ ಚಾಟ್‌ಗಳು ಕಂಡುಬಂದಿಲ್ಲ\n\nಹೊಸ ಚಾಟ್ ಸೇರಿಸಲು\n+ ಕ್ಲಿಕ್ ಮಾಡಿ"}, {"light_theme", "ಹಗುರ ಥೀಮ್"}, {"dark_theme", "ಗಾಢ ಥೀಮ್"},
        {"new_chat_tooltip", "ಹೊಸ ಚಾಟ್ ಸೇರಿಸಿ"}, {"chat_search_placeholder", "ಚಾಟ್‌ಗಳಲ್ಲಿ ಹುಡುಕಿ"}, {"importing", "ಆಮದು ಮಾಡಲಾಗುತ್ತಿದೆ..."},
        {"bulk_select_tooltip", "ಬೃಹತ್ ಆಯ್ಕೆ"}, {"bulk_delete_tooltip", "ಬೃಹತ್ ಅಳಿಸು"}, {"cancel_selection_tooltip", "ರದ್ದುಮಾಡಿ"},
        {"import_new", "ಹೊಸ ಚಾಟ್ ಸೇರಿಸಿ"}, {"zip_description", "WhatsApp ನಿಂದ ರಫ್ತು ಮಾಡಿದ ZIP ಫೈಲ್ ಆಯ್ಕೆಮಾಡಿ."},
        {"select_zip", "ZIP ಫೈಲ್ ಆಯ್ಕೆಮಾಡಿ"}, {"change_zip", "ಫೈಲ್ ಬದಲಿಸಿ"}, {"continue", "ಮುಂದುವರಿಸಿ"},
        {"owner_question", "ಚಾಟ್‌ನಲ್ಲಿ ನಿಮ್ಮ ಹೆಸರೇನು?\n(ನಿಮ್ಮ WhatsApp ಖಾತೆಯಲ್ಲಿ ಕಾಣಿಸುವ ಹೆಸರು)"}, {"owner_placeholder", "ಉದಾ: ರಾಜೇಶ್ ಕುಮಾರ್"},
        {"import_btn", "ಆಮದು ಮಾಡಿ"}, {"back", "ಹಿಂದೆ"}, {"loading_messages", "ಸಂದೇಶಗಳನ್ನು ಲೋಡ್ ಮಾಡಲಾಗುತ್ತಿದೆ, ದಯವಿಟ್ಟು ನಿರೀಕ್ಷಿಸಿ..."},
        {"select_zip_title", "WhatsApp ZIP ಫೈಲ್ ಆಯ್ಕೆಮಾಡಿ"}, {"first_message", "ಮೊದಲ ಸಂದೇಶ"}, {"delete_chat", "ಚಾಟ್ ಅಳಿಸಿ"}, {"search", "ಹುಡುಕಿ..."}, {"search_tooltip", "ಸಂದೇಶಗಳಲ್ಲಿ ಹುಡುಕಿ (Ctrl+F)"},
        {"empty_chat_hint", "ಚಾಟ್ ಆಯ್ಕೆಮಾಡಿ ಅಥವಾ ಹೊಸದನ್ನು ಸೇರಿಸಿ"}, {"delete_confirm_title", "ಚಾಟ್ ಅಳಿಸಿ"},
        {"delete_confirm_text", "ಈ ಚಾಟ್ ಅಳಿಸಲು ನೀವು ಖಚಿತವಾಗಿ ಬಯಸುವಿರಾ?\nಎಲ್ಲಾ ಸಂದೇಶಗಳನ್ನು ತೆಗೆದುಹಾಕಲಾಗುವುದು."}, {"no_results", "ಯಾವುದೇ ಫಲಿತಾಂಶಗಳು ಕಂಡುಬಂದಿಲ್ಲ"},
        {"yes", "ಹೌದು"}, {"no", "ಇಲ್ಲ"}, {"cancel", "ರದ್ದುಮಾಡಿ"}, {"language", "ಭಾಷೆ"}, {"select_language", "ಭಾಷೆ ಆಯ್ಕೆಮಾಡಿ"}, {"profile_photo", "ಪ್ರೊಫೈಲ್ ಫೋಟೋ"},
        {"name_label", "ಹೆಸರು"}, {"participants_label", "ಗುಂಪು ಭಾಗವಹಿಸುವವರು"}, {"contact_name_placeholder", "ಸಂಪರ್ಕ ಹೆಸರು"}, {"image_files_filter", "ಚಿತ್ರ ಫೈಲ್‌ಗಳು (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — %2 ಸಂದೇಶಗಳನ್ನು ಆಮದು ಮಾಡಲಾಗಿದೆ"}, {"conversation", "ಸಂಭಾಷಣೆ"},
        {"default_owner_name", "ಡೀಫಾಲ್ಟ್ ಮಾಲೀಕ ಹೆಸರು"}, {"owner_name_placeholder", "ನಿಮ್ಮ ಹೆಸರು"}, {"not_set", "ಹೊಂದಿಸಲಾಗಿಲ್ಲ"}, {"default_label", "ಡೀಫಾಲ್ಟ್"},
        {"profile_library", "ಪ್ರೊಫೈಲ್ ಲೈಬ್ರರಿ"}, {"add_profile", "ಪ್ರೊಫೈಲ್ ಸೇರಿಸಿ"}, {"profile_name_label", "ಹೆಸರು:"}, {"add_btn", "ಸೇರಿಸಿ"},
        {"optional", "(ಐಚ್ಛಿಕ)"}, {"image_selected", "✓ ಆಯ್ಕೆಮಾಡಲಾಗಿದೆ"}, {"no_profiles_library", "ಇನ್ನೂ ಯಾವುದೇ ಪ್ರೊಫೈಲ್‌ಗಳಿಲ್ಲ. ಸೇರಿಸಲು + ಕ್ಲಿಕ್ ಮಾಡಿ."},
        {"profile_owner_conflict", "ಮಾಲೀಕರಂತೆಯೇ ಅದೇ ಹೆಸರಿನ ಪ್ರೊಫೈಲ್ ಸೇರಿಸಲು ಸಾಧ್ಯವಿಲ್ಲ"}, {"profile_exists", "ಈ ಹೆಸರಿನ ಪ್ರೊಫೈಲ್ ಈಗಾಗಲೇ ಅಸ್ತಿತ್ವದಲ್ಲಿದೆ"},
        {"message_count_text", "ಸಂದೇಶಗಳು"},
        {"january", "ಜನವರಿ"}, {"february", "ಫೆಬ್ರವರಿ"}, {"march", "ಮಾರ್ಚ್"}, {"april", "ಏಪ್ರಿಲ್"}, {"may", "ಮೇ"}, {"june", "ಜೂನ್"},
        {"july", "ಜುಲೈ"}, {"august", "ಆಗಸ್ಟ್"}, {"september", "ಸೆಪ್ಟೆಂಬರ್"}, {"october", "ಅಕ್ಟೋಬರ್"}, {"november", "ನವೆಂಬರ್"}, {"december", "ಡಿಸೆಂಬರ್"},
        {"calendar_tooltip", "ದಿನಾಂಕಕ್ಕೆ ಹೋಗಿ"},
        {"last_message", "ಕೊನೆಯ ಸಂದೇಶ"},
        {"settings", "ಸೆಟ್ಟಿಂಗ್‌ಗಳು"},
        {"auto_play_next_voice", "ಅನುಕ್ರಮ ಧ್ವನಿ ಸಂದೇಶಗಳನ್ನು ಸ್ವಯಂಚಾಲಿತವಾಗಿ ಪ್ಲೇ ಮಾಡಿ"},
        {"open_system", "ಸಿಸ್ಟಮ್‌ನಲ್ಲಿ ತೆರೆಯಿರಿ"}, {"image_not_found", "ಚಿತ್ರ ಕಂಡುಬಂದಿಲ್ಲ"}, {"video", "ವೀಡಿಯೊ"}, {"deleted_message", "ಈ ಸಂದೇಶ ಅಳಿಸಲಾಗಿದೆ"}, {"you_deleted_message", "ನೀವು ಈ ಸಂದೇಶವನ್ನು ಅಳಿಸಿದ್ದೀರಿ"}, {"edited", "ಸಂಪಾದಿಸಲಾಗಿದೆ"}, {"app_version", "ಆವೃತ್ತಿ"}, {"app_copyright", "ಹಕ್ಕುಸ್ವಾಮ್ಯ %1 ರವರಿಂದ"},
        {"lock_chat", "ಚಾಟ್ ಲಾಕ್ ಮಾಡಿ"}, {"unlock_chat", "ಈ ಚಾಟ್ ಅನ್‌ಲಾಕ್ ಮಾಡಿ"}, {"locked_chats", "ಲಾಕ್ ಮಾಡಿದ ಚಾಟ್‌ಗಳು"}, {"locked_chats_access", "ಲಾಕ್ ಮಾಡಿದ ಚಾಟ್‌ಗಳಿಗೆ ಪ್ರವೇಶ"},
        {"lock_chat_title", "ಚಾಟ್ ಲಾಕ್ ಮಾಡಿ"}, {"lock_chat_message", "ಈ ಚಾಟ್ ಲಾಕ್ ಮಾಡಲಾಗುತ್ತದೆ"}, {"lock_chat_set_password", "ಚಾಟ್‌ಗಳನ್ನು ಲಾಕ್ ಮಾಡಲು ಪಾಸ್‌ವರ್ಡ್ ಹೊಂದಿಸಿ"},
        {"locked_chats_password_title", "ಲಾಕ್ ಮಾಡಿದ ಚಾಟ್‌ಗಳು"}, {"locked_chats_enter_password", "ಲಾಕ್ ಮಾಡಿದ ಚಾಟ್‌ಗಳನ್ನು ಪ್ರವೇಶಿಸಲು ಪಾಸ್‌ವರ್ಡ್ ನಮೂದಿಸಿ"},
        {"password_6_digits", "ಪಾಸ್‌ವರ್ಡ್ 6 ಅಂಕೆಗಳಾಗಿರಬೇಕು"}, {"password_incorrect", "ತಪ್ಪು ಪಾಸ್‌ವರ್ಡ್"}, {"no_master_password", "ಪಾಸ್‌ವರ್ಡ್ ಹೊಂದಿಸಲಾಗಿಲ್ಲ"},
        {"locked_chats_password", "ಲಾಕ್ ಮಾಡಿದ ಚಾಟ್‌ಗಳ ಪಾಸ್‌ವರ್ಡ್"}, {"no_password", "ನಿಮ್ಮ ಬಳಿ ಪಾಸ್‌ವರ್ಡ್ ಇಲ್ಲ"}, {"change_password", "ಪಾಸ್‌ವರ್ಡ್ ಬದಲಿಸಿ"},
        {"old_password", "ಹಳೆಯ ಪಾಸ್‌ವರ್ಡ್"}, {"new_password", "ಹೊಸ ಪಾಸ್‌ವರ್ಡ್"}, {"confirm_password", "ಹೊಸ ಪಾಸ್‌ವರ್ಡ್ ದೃಢೀಕರಿಸಿ"}, {"change", "ಬದಲಿಸಿ"},
        {"old_password_incorrect", "ಹಳೆಯ ಪಾಸ್‌ವರ್ಡ್ ತಪ್ಪಾಗಿದೆ"}, {"passwords_dont_match", "ಹೊಸ ಪಾಸ್‌ವರ್ಡ್‌ಗಳು ಹೊಂದಿಕೆಯಾಗುತ್ತಿಲ್ಲ"},
        {"no_locked_chats", "ಯಾವುದೇ ಲಾಕ್ ಮಾಡಿದ ಚಾಟ್‌ಗಳಿಲ್ಲ"}, {"locked_chats_hint", "ಚಾಟ್ ಲಾಕ್ ಮಾಡಲು 3-ಡಾಟ್ ಮೆನುವಿನಿಂದ 'ಚಾಟ್ ಲಾಕ್ ಮಾಡಿ' ಆಯ್ಕೆಮಾಡಿ"}, {"enter", "ಪ್ರವೇಶಿಸಿ"}
    };
    m_translations["Kannada"].insert(QStringLiteral("media_image"), QStringLiteral("ಫೋಟೋ"));
    m_translations["Kannada"].insert(QStringLiteral("media_video"), QStringLiteral("ವೀಡಿಯೊ"));
    m_translations["Kannada"].insert(QStringLiteral("media_voice"), QStringLiteral("ಧ್ವನಿ ಸಂದೇಶ"));
    m_translations["Kannada"].insert(QStringLiteral("media_audio"), QStringLiteral("ಆಡಿಯೊ"));
    m_translations["Kannada"].insert(QStringLiteral("media_sticker"), QStringLiteral("ಸ್ಟಿಕ್ಕರ್"));
    m_translations["Kannada"].insert(QStringLiteral("media_document"), QStringLiteral("ಡಾಕ್ಯುಮೆಂಟ್"));
    m_translations["Kannada"].insert(QStringLiteral("media_unavailable"), QStringLiteral("ಮಾಧ್ಯಮ ಲಭ್ಯವಿಲ್ಲ"));
    m_translations["Kannada"].insert(QStringLiteral("tap_to_open"), QStringLiteral("ತೆರೆಯಲು ಟ್ಯಾಪ್ ಮಾಡಿ"));
    m_translations["Kannada"].insert(QStringLiteral("location"), QStringLiteral("ಸ್ಥಳ"));
    m_translations["Kannada"].insert(QStringLiteral("contact"), QStringLiteral("ಸಂಪರ್ಕ"));
    m_translations["Kannada"].insert(QStringLiteral("favorites"), QStringLiteral("ಮೆಚ್ಚಿನವುಗಳು"));
    m_translations["Kannada"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("ಮೆಚ್ಚಿನವುಗಳಿಗೆ ಸೇರಿಸಿ"));
    m_translations["Kannada"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("ಮೆಚ್ಚಿನವುಗಳಿಂದ ತೆಗೆದುಹಾಕಿ"));
    m_translations["Kannada"].insert(QStringLiteral("no_favorites"), QStringLiteral("ಯಾವುದೇ ಮೆಚ್ಚಿನವುಗಳಿಲ್ಲ"));
    m_translations["Kannada"].insert(QStringLiteral("favorites_hint"), QStringLiteral("ಮೆಚ್ಚಿನವುಗಳಿಗೆ ಸೇರಿಸಲು ಸಂದೇಶವನ್ನು ರೈಟ್-ಕ್ಲಿಕ್ ಮಾಡಿ"));
    m_translations["Kannada"].insert(QStringLiteral("media_browser"), QStringLiteral("ಮಾಧ್ಯಮ"));
    m_translations["Kannada"].insert(QStringLiteral("media_browser_title"), QStringLiteral("ಮಾಧ್ಯಮ"));
    m_translations["Kannada"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("ಫೋಟೋಗಳು, ವೀಡಿಯೊಗಳು ಮತ್ತು ಫೈಲ್‌ಗಳು"));
    m_translations["Kannada"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("ಫೋಟೋಗಳು"));
    m_translations["Kannada"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("ವೀಡಿಯೊಗಳು"));
    m_translations["Kannada"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("ಡಾಕ್ಯುಮೆಂಟ್‌ಗಳು"));
    m_translations["Kannada"].insert(QStringLiteral("media_browser_links"), QStringLiteral("ಲಿಂಕ್‌ಗಳು"));
    m_translations["Kannada"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("ಸ್ಥಳಗಳು"));
    m_translations["Kannada"].insert(QStringLiteral("no_photos_found"), QStringLiteral("ಯಾವುದೇ ಫೋಟೋಗಳು ಕಂಡುಬಂದಿಲ್ಲ"));
    m_translations["Kannada"].insert(QStringLiteral("no_videos_found"), QStringLiteral("ಯಾವುದೇ ವೀಡಿಯೊಗಳು ಕಂಡುಬಂದಿಲ್ಲ"));
    m_translations["Kannada"].insert(QStringLiteral("no_documents_found"), QStringLiteral("ಯಾವುದೇ ಡಾಕ್ಯುಮೆಂಟ್‌ಗಳು ಕಂಡುಬಂದಿಲ್ಲ"));
    m_translations["Kannada"].insert(QStringLiteral("no_links_found"), QStringLiteral("ಯಾವುದೇ ಲಿಂಕ್‌ಗಳು ಕಂಡುಬಂದಿಲ್ಲ"));
    m_translations["Kannada"].insert(QStringLiteral("no_locations_found"), QStringLiteral("ಯಾವುದೇ ಸ್ಥಳಗಳು ಕಂಡುಬಂದಿಲ್ಲ"));

    // Kazakh
    m_translations["Kazakh"] = {
        {"contact_info", "Байланыс ақпараты"}, {"msg_count", "Хабарлар саны"}, {"messages", "хабарлар"}, {"import_date", "Импорт күні"},
        {"no_chats", "Чаттар табылмады\n\nЖаңа чат қосу үшін\n+ басыңыз"}, {"light_theme", "Ашық тақырып"}, {"dark_theme", "Қараңғы тақырып"},
        {"new_chat_tooltip", "Жаңа чат қосу"}, {"chat_search_placeholder", "Чаттарда іздеу"}, {"importing", "Импорттау..."},
        {"bulk_select_tooltip", "Топтама таңдау"}, {"bulk_delete_tooltip", "Топтама өшіру"}, {"cancel_selection_tooltip", "Болдырмау"},
        {"import_new", "Жаңа чат қосу"}, {"zip_description", "WhatsApp-тан экспортталған ZIP файлын таңдаңыз."},
        {"select_zip", "ZIP файлын таңдау"}, {"change_zip", "Файлды өзгерту"}, {"continue", "Жалғастыру"},
        {"owner_question", "Чаттағы атыңыз қандай?\n(WhatsApp аккаунтыңызда көрсетілген ат)"}, {"owner_placeholder", "Мысалы: Әсет Нұрланұлы"},
        {"import_btn", "Импорттау"}, {"back", "Артқа"}, {"loading_messages", "Хабарлар жүктелуде, күте тұрыңыз..."},
        {"select_zip_title", "WhatsApp ZIP файлын таңдау"}, {"first_message", "Бірінші хабар"}, {"delete_chat", "Чатты өшіру"}, {"search", "Іздеу..."}, {"search_tooltip", "Хабарларда іздеу (Ctrl+F)"},
        {"empty_chat_hint", "Чат таңдаңыз немесе жаңасын қосыңыз"}, {"delete_confirm_title", "Чатты өшіру"},
        {"delete_confirm_text", "Бұл чатты өшіргіңіз келетініне сенімдісіз бе?\nБарлық хабарлар жойылады."}, {"no_results", "Нәтиже табылмады"},
        {"yes", "Иә"}, {"no", "Жоқ"}, {"cancel", "Болдырмау"}, {"language", "Тіл"}, {"select_language", "Тілді таңдау"}, {"profile_photo", "Профиль суреті"},
        {"name_label", "Ат"}, {"participants_label", "Топ қатысушылары"}, {"contact_name_placeholder", "Байланыс аты"}, {"image_files_filter", "Сурет файлдары (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — %2 хабар импортталды"}, {"conversation", "Әңгіме"},
        {"default_owner_name", "Әдепкі иесінің аты"}, {"owner_name_placeholder", "Сіздің атыңыз"}, {"not_set", "Орнатылмаған"}, {"default_label", "Әдепкі"},
        {"profile_library", "Профиль кітапханасы"}, {"add_profile", "Профиль қосу"}, {"profile_name_label", "Ат:"}, {"add_btn", "Қосу"},
        {"optional", "(Міндетті емес)"}, {"image_selected", "✓ Таңдалды"}, {"no_profiles_library", "Әлі профильдер жоқ. Қосу үшін + басыңыз."},
        {"profile_owner_conflict", "Иемен бірдей атпен профиль қосу мүмкін емес"}, {"profile_exists", "Бұл атпен профиль бар"},
        {"message_count_text", "хабарлар"},
        {"january", "Қаң"}, {"february", "Ақп"}, {"march", "Нау"}, {"april", "Сәу"}, {"may", "Мам"}, {"june", "Мау"},
        {"july", "Шіл"}, {"august", "Там"}, {"september", "Қыр"}, {"october", "Қаз"}, {"november", "Қар"}, {"december", "Жел"},
        {"calendar_tooltip", "Күнге өту"},
        {"last_message", "Соңғы хабар"},
        {"settings", "Баптаулар"},
        {"auto_play_next_voice", "Дауыстық хабарларды қатарынан автоматты ойнату"},
        {"open_system", "Жүйеде ашу"}, {"image_not_found", "Сурет табылмады"}, {"video", "Бейне"}, {"deleted_message", "Бұл хабар өшірілді"}, {"you_deleted_message", "Сіз бұл хабарды өшірдіңіз"}, {"edited", "Өңделген"}, {"app_version", "нұсқа"}, {"app_copyright", "Авторлық құқық %1"},
        {"lock_chat", "Чатты құлыптау"}, {"unlock_chat", "Бұл чатты құлыптан шығару"}, {"locked_chats", "Құлыпталған чаттар"}, {"locked_chats_access", "Құлыпталған чаттарға кіру"},
        {"lock_chat_title", "Чатты құлыптау"}, {"lock_chat_message", "Бұл чат құлыпталады"}, {"lock_chat_set_password", "Чаттарды құлыптау үшін құпия сөз орнатыңыз"},
        {"locked_chats_password_title", "Құлыпталған чаттар"}, {"locked_chats_enter_password", "Құлыпталған чаттарға кіру үшін құпия сөзді енгізіңіз"},
        {"password_6_digits", "Құпия сөз 6 саннан тұруы керек"}, {"password_incorrect", "Құпия сөз қате"}, {"no_master_password", "Құпия сөз орнатылмаған"},
        {"locked_chats_password", "Құлыпталған чаттар құпия сөзі"}, {"no_password", "Сізде құпия сөз жоқ"}, {"change_password", "Құпия сөзді өзгерту"},
        {"old_password", "Ескі құпия сөз"}, {"new_password", "Жаңа құпия сөз"}, {"confirm_password", "Жаңа құпия сөзді растау"}, {"change", "Өзгерту"},
        {"old_password_incorrect", "Ескі құпия сөз қате"}, {"passwords_dont_match", "Жаңа құпия сөздер сәйкес келмейді"},
        {"no_locked_chats", "Құлыпталған чаттар жоқ"}, {"locked_chats_hint", "Чатты құлыптау үшін 3 нүкте мәзірінен 'Чатты құлыптау' таңдаңыз"}, {"enter", "Кіру"}
    };
    m_translations["Kazakh"].insert(QStringLiteral("media_image"), QStringLiteral("Фото"));
    m_translations["Kazakh"].insert(QStringLiteral("media_video"), QStringLiteral("Бейне"));
    m_translations["Kazakh"].insert(QStringLiteral("media_voice"), QStringLiteral("Дауыстық хабар"));
    m_translations["Kazakh"].insert(QStringLiteral("media_audio"), QStringLiteral("Аудио"));
    m_translations["Kazakh"].insert(QStringLiteral("media_sticker"), QStringLiteral("Стикер"));
    m_translations["Kazakh"].insert(QStringLiteral("media_document"), QStringLiteral("Құжат"));
    m_translations["Kazakh"].insert(QStringLiteral("media_unavailable"), QStringLiteral("Медиа қолжетімсіз"));
    m_translations["Kazakh"].insert(QStringLiteral("tap_to_open"), QStringLiteral("Ашу үшін түртіңіз"));
    m_translations["Kazakh"].insert(QStringLiteral("location"), QStringLiteral("Орын"));
    m_translations["Kazakh"].insert(QStringLiteral("contact"), QStringLiteral("Байланыс"));
    m_translations["Kazakh"].insert(QStringLiteral("favorites"), QStringLiteral("Таңдаулылар"));
    m_translations["Kazakh"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("Таңдаулыларға қосу"));
    m_translations["Kazakh"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("Таңдаулылардан алу"));
    m_translations["Kazakh"].insert(QStringLiteral("no_favorites"), QStringLiteral("Таңдаулылар жоқ"));
    m_translations["Kazakh"].insert(QStringLiteral("favorites_hint"), QStringLiteral("Таңдаулыларға қосу үшін хабарды оң жақпен басыңыз"));
    m_translations["Kazakh"].insert(QStringLiteral("media_browser"), QStringLiteral("Медиа"));
    m_translations["Kazakh"].insert(QStringLiteral("media_browser_title"), QStringLiteral("Медиа"));
    m_translations["Kazakh"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("Фотолар, бейнелер және файлдар"));
    m_translations["Kazakh"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("Фотолар"));
    m_translations["Kazakh"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("Бейнелер"));
    m_translations["Kazakh"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("Құжаттар"));
    m_translations["Kazakh"].insert(QStringLiteral("media_browser_links"), QStringLiteral("Сілтемелер"));
    m_translations["Kazakh"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("Орындар"));
    m_translations["Kazakh"].insert(QStringLiteral("no_photos_found"), QStringLiteral("Фотолар табылмады"));
    m_translations["Kazakh"].insert(QStringLiteral("no_videos_found"), QStringLiteral("Бейнелер табылмады"));
    m_translations["Kazakh"].insert(QStringLiteral("no_documents_found"), QStringLiteral("Құжаттар табылмады"));
    m_translations["Kazakh"].insert(QStringLiteral("no_links_found"), QStringLiteral("Сілтемелер табылмады"));
    m_translations["Kazakh"].insert(QStringLiteral("no_locations_found"), QStringLiteral("Орындар табылмады"));

    // Lao
    m_translations["Lao"] = {
        {"contact_info", "ຂໍ້ມູນຕິດຕໍ່"}, {"msg_count", "ຈຳນວນຂໍ້ຄວາມ"}, {"messages", "ຂໍ້ຄວາມ"}, {"import_date", "ວັນທີນຳເຂົ້າ"},
        {"no_chats", "ບໍ່ພົບການສົນທະນາ\n\nຄລິກ + ເພື່ອເພີ່ມ\nການສົນທະນາໃໝ່"}, {"light_theme", "ຊຸດຮູບແບບສະຫວ່າງ"}, {"dark_theme", "ຊຸດຮູບແບບມືດ"},
        {"new_chat_tooltip", "ເພີ່ມການສົນທະນາໃໝ່"}, {"chat_search_placeholder", "ຄົ້ນຫາໃນການສົນທະນາ"}, {"importing", "ກຳລັງນຳເຂົ້າ..."},
        {"bulk_select_tooltip", "ເລືອກຫຼາຍລາຍການ"}, {"bulk_delete_tooltip", "ລຶບຫຼາຍລາຍການ"}, {"cancel_selection_tooltip", "ຍົກເລີກ"},
        {"import_new", "ເພີ່ມການສົນທະນາໃໝ່"}, {"zip_description", "ເລືອກໄຟລ୍ ZIP ທີ່ສົ່ງອອກຈາກ WhatsApp."},
        {"select_zip", "ເລືອກໄຟລ୍ ZIP"}, {"change_zip", "ປ່ຽນໄຟລ୍"}, {"continue", "ສືບຕໍ່"},
        {"owner_question", "ຊື່ຂອງທ່ານໃນການສົນທະນາແມ່ນຫຍັງ?\n(ຊື່ທີ່ສະແດງໃນບັນຊີ WhatsApp ຂອງທ່ານ)"}, {"owner_placeholder", "ຕົວຢ່າງ: ສົມຊາຍ ພົມມະວົງ"},
        {"import_btn", "ນຳເຂົ້າ"}, {"back", "ກັບຄືນ"}, {"loading_messages", "ກຳລັງໂຫຼດຂໍ້ຄວາມ, ກະລຸນາລໍຖ້າ..."},
        {"select_zip_title", "ເລືອກໄຟລ୍ ZIP WhatsApp"}, {"first_message", "ຂໍ້ຄວາມທຳອິດ"}, {"delete_chat", "ລຶບການສົນທະນາ"}, {"search", "ຄົ້ນຫາ..."}, {"search_tooltip", "ຄົ້ນຫາໃນຂໍ້ຄວາມ (Ctrl+F)"},
        {"empty_chat_hint", "ເລືອກການສົນທະນາຫຼືເພີ່ມການສົນທະນາໃໝ່"}, {"delete_confirm_title", "ລຶບການສົນທະນາ"},
        {"delete_confirm_text", "ທ່ານແນ່ໃຈບໍ່ວ່າຕ້ອງການລຶບການສົນທະນານີ້?\nຂໍ້ຄວາມທັງໝົດຈະຖືກລຶບອອກ."}, {"no_results", "ບໍ່ພົບຜົນໄດ້ຮັບ"},
        {"yes", "ແມ່ນ"}, {"no", "ບໍ່"}, {"cancel", "ຍົກເລີກ"}, {"language", "ພາສາ"}, {"select_language", "ເລືອກພາສາ"}, {"profile_photo", "ຮູບໂປຣໄຟລ໌"},
        {"name_label", "ຊື່"}, {"participants_label", "ສະມາຊິກກຸ່ມ"}, {"contact_name_placeholder", "ຊື່ຜູ້ຕິດຕໍ່"}, {"image_files_filter", "ໄຟລ໌ຮູບພາບ (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — ນຳເຂົ້າ %2 ຂໍ້ຄວາມແລ້ວ"}, {"conversation", "ການສົນທະນາ"},
        {"default_owner_name", "ຊື່ເຈົ້າຂອງເລີ່ມຕົ້ນ"}, {"owner_name_placeholder", "ຊື່ຂອງທ່ານ"}, {"not_set", "ບໍ່ໄດ້ຕັ້ງຄ່າ"}, {"default_label", "ເລີ່ມຕົ້ນ"},
        {"profile_library", "ຫ້ອງສະໝຸດໂປຣໄຟລ໌"}, {"add_profile", "ເພີ່ມໂປຣໄຟລ໌"}, {"profile_name_label", "ຊື່:"}, {"add_btn", "ເພີ່ມ"},
        {"optional", "(ທາງເລືອກ)"}, {"image_selected", "✓ ເລືອກແລ້ວ"}, {"no_profiles_library", "ຍັງບໍ່ມີໂປຣໄຟລ໌. ຄລິກ + ເພື່ອເພີ່ມ."},
        {"profile_owner_conflict", "ບໍ່ສາມາດເພີ່ມໂປຣໄຟລ໌ທີ່ມີຊື່ດຽວກັນກັບເຈົ້າຂອງໄດ້"}, {"profile_exists", "ໂປຣໄຟລ໌ທີ່ມີຊື່ນີ້ມີຢູ່ແລ້ວ"},
        {"message_count_text", "ຂໍ້ຄວາມ"},
        {"january", "ມ.ກ."}, {"february", "ກ.ພ."}, {"march", "ມ.ນ."}, {"april", "ມ.ສ."}, {"may", "ພ.ພ."}, {"june", "ມິ.ຖ."},
        {"july", "ກ.ລ."}, {"august", "ສ.ຫ."}, {"september", "ກ.ຍ."}, {"october", "ຕ.ລ."}, {"november", "ພ.ຈ."}, {"december", "ທ.ວ."},
        {"calendar_tooltip", "ໄປທີ່ວັນທີ"},
        {"last_message", "ຂໍ້ຄວາມສຸດທ້າຍ"},
        {"settings", "ການຕັ້ງຄ່າ"},
        {"auto_play_next_voice", "ເປີດຂໍ້ຄວາມສຽງຕໍ່ເນື່ອງໂດຍອັດຕະໂນມັດ"},
        {"open_system", "ເປີດໃນລະບົບ"}, {"image_not_found", "ບໍ່ພົບຮູບພາບ"}, {"video", "ວິດີໂອ"}, {"deleted_message", "ຂໍ້ຄວາມນີ້ຖືກລຶບແລ້ວ"}, {"you_deleted_message", "ທ່ານໄດ້ລຶບຂໍ້ຄວາມນີ້"}, {"edited", "ແກ້ໄຂແລ້ວ"}, {"app_version", "ເວີຊັນ"}, {"app_copyright", "ລິຂະສິດໂດຍ %1"},
        {"lock_chat", "ລັອກການສົນທະນາ"}, {"unlock_chat", "ປົດລັອກການສົນທະນານີ້"}, {"locked_chats", "ການສົນທະນາທີ່ລັອກ"}, {"locked_chats_access", "ເຂົ້າເຖິງການສົນທະນາທີ່ລັອກ"},
        {"lock_chat_title", "ລັອກການສົນທະນາ"}, {"lock_chat_message", "ການສົນທະນານີ້ຈະຖືກລັອກ"}, {"lock_chat_set_password", "ຕັ້ງລະຫັດຜ່ານເພື່ອລັອກການສົນທະນາ"},
        {"locked_chats_password_title", "ການສົນທະນາທີ່ລັອກ"}, {"locked_chats_enter_password", "ໃສ່ລະຫັດຜ່ານເພື່ອເຂົ້າເຖິງການສົນທະນາທີ່ລັອກ"},
        {"password_6_digits", "ລະຫັດຜ່ານຕ້ອງເປັນ 6 ຕົວເລກ"}, {"password_incorrect", "ລະຫັດຜ່ານບໍ່ຖືກຕ້ອງ"}, {"no_master_password", "ບໍ່ໄດ້ຕັ້ງລະຫັດຜ່ານ"},
        {"locked_chats_password", "ລະຫັດຜ່ານການສົນທະນາທີ່ລັອກ"}, {"no_password", "ທ່ານບໍ່ມີລະຫັດຜ່ານ"}, {"change_password", "ປ່ຽນລະຫັດຜ່ານ"},
        {"old_password", "ລະຫັດຜ່ານເກົ່າ"}, {"new_password", "ລະຫັດຜ່ານໃໝ່"}, {"confirm_password", "ຢືນຢັນລະຫັດຜ່ານໃໝ່"}, {"change", "ປ່ຽນ"},
        {"old_password_incorrect", "ລະຫັດຜ່ານເກົ່າບໍ່ຖືກຕ້ອງ"}, {"passwords_dont_match", "ລະຫັດຜ່ານໃໝ່ບໍ່ກົງກັນ"},
        {"no_locked_chats", "ບໍ່ມີການສົນທະນາທີ່ລັອກ"}, {"locked_chats_hint", "ເລືອກ 'ລັອກການສົນທະນາ' ຈາກເມນູ 3 ຈຸດເພື່ອລັອກການສົນທະນາ"}, {"enter", "ເຂົ້າສູ່"}
    };
    m_translations["Lao"].insert(QStringLiteral("media_image"), QStringLiteral("ຮູບພາບ"));
    m_translations["Lao"].insert(QStringLiteral("media_video"), QStringLiteral("ວິດີໂອ"));
    m_translations["Lao"].insert(QStringLiteral("media_voice"), QStringLiteral("ຂໍ້ຄວາມສຽງ"));
    m_translations["Lao"].insert(QStringLiteral("media_audio"), QStringLiteral("ສຽງ"));
    m_translations["Lao"].insert(QStringLiteral("media_sticker"), QStringLiteral("ສະຕິກເກີ"));
    m_translations["Lao"].insert(QStringLiteral("media_document"), QStringLiteral("ເອກະສານ"));
    m_translations["Lao"].insert(QStringLiteral("media_unavailable"), QStringLiteral("ສື່ບໍ່ພ້ອມໃຊ້ງານ"));
    m_translations["Lao"].insert(QStringLiteral("tap_to_open"), QStringLiteral("ແຕະເພື່ອເປີດ"));
    m_translations["Lao"].insert(QStringLiteral("location"), QStringLiteral("ທີ່ຕັ້ງ"));
    m_translations["Lao"].insert(QStringLiteral("contact"), QStringLiteral("ຜູ້ຕິດຕໍ່"));
    m_translations["Lao"].insert(QStringLiteral("favorites"), QStringLiteral("ລາຍການທີ່ມັກ"));
    m_translations["Lao"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("ເພີ່ມໃສ່ລາຍການທີ່ມັກ"));
    m_translations["Lao"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("ລຶບອອກຈາກລາຍການທີ່ມັກ"));
    m_translations["Lao"].insert(QStringLiteral("no_favorites"), QStringLiteral("ບໍ່ມີລາຍການທີ່ມັກ"));
    m_translations["Lao"].insert(QStringLiteral("favorites_hint"), QStringLiteral("ຄລິກຂວາຂໍ້ຄວາມເພື່ອເພີ່ມໃສ່ລາຍການທີ່ມັກ"));
    m_translations["Lao"].insert(QStringLiteral("media_browser"), QStringLiteral("ສື່"));
    m_translations["Lao"].insert(QStringLiteral("media_browser_title"), QStringLiteral("ສື່"));
    m_translations["Lao"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("ຮູບພາບ, ວິດີໂອ ແລະ ໄຟລ໌"));
    m_translations["Lao"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("ຮູບພາບ"));
    m_translations["Lao"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("ວິດີໂອ"));
    m_translations["Lao"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("ເອກະສານ"));
    m_translations["Lao"].insert(QStringLiteral("media_browser_links"), QStringLiteral("ລິ້ງ"));
    m_translations["Lao"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("ທີ່ຕັ້ງ"));
    m_translations["Lao"].insert(QStringLiteral("no_photos_found"), QStringLiteral("ບໍ່ພົບຮູບພາບ"));
    m_translations["Lao"].insert(QStringLiteral("no_videos_found"), QStringLiteral("ບໍ່ພົບວິດີໂອ"));
    m_translations["Lao"].insert(QStringLiteral("no_documents_found"), QStringLiteral("ບໍ່ພົບເອກະສານ"));
    m_translations["Lao"].insert(QStringLiteral("no_links_found"), QStringLiteral("ບໍ່ພົບລິ້ງ"));
    m_translations["Lao"].insert(QStringLiteral("no_locations_found"), QStringLiteral("ບໍ່ພົບທີ່ຕັ້ງ"));

    // Latvian
    m_translations["Latvian"] = {
        {"contact_info", "Kontaktinformācija"}, {"msg_count", "Ziņojumu skaits"}, {"messages", "ziņojumi"}, {"import_date", "Importēšanas datums"},
        {"no_chats", "Nav atrasti čati\n\nNoklikšķiniet uz +, lai\npievienotu jaunu čatu"}, {"light_theme", "Gaišs motīvs"}, {"dark_theme", "Tumšs motīvs"},
        {"new_chat_tooltip", "Pievienot jaunu čatu"}, {"chat_search_placeholder", "Meklēt čatos"}, {"importing", "Importē..."},
        {"bulk_select_tooltip", "Masveida atlase"}, {"bulk_delete_tooltip", "Masveida dzēšana"}, {"cancel_selection_tooltip", "Atcelt"},
        {"import_new", "Pievienot jaunu čatu"}, {"zip_description", "Atlasiet ZIP failu, kas eksportēts no WhatsApp."},
        {"select_zip", "Atlasīt ZIP failu"}, {"change_zip", "Mainīt failu"}, {"continue", "Turpināt"},
        {"owner_question", "Kāds ir jūsu vārds čatā?\n(Vārds, kas parādās jūsu WhatsApp kontā)"}, {"owner_placeholder", "Piemēram: Jānis Bērziņš"},
        {"import_btn", "Importēt"}, {"back", "Atpakaļ"}, {"loading_messages", "Ielādē ziņojumus, lūdzu, uzgaidiet..."},
        {"select_zip_title", "Atlasīt WhatsApp ZIP failu"}, {"first_message", "Pirmais ziņojums"}, {"delete_chat", "Dzēst čatu"}, {"search", "Meklēt..."}, {"search_tooltip", "Meklēt ziņojumos (Ctrl+F)"},
        {"empty_chat_hint", "Atlasiet čatu vai pievienojiet jaunu"}, {"delete_confirm_title", "Dzēst čatu"},
        {"delete_confirm_text", "Vai tiešām vēlaties dzēst šo čatu?\nVisi ziņojumi tiks noņemti."}, {"no_results", "Nav atrasti rezultāti"},
        {"yes", "Jā"}, {"no", "Nē"}, {"cancel", "Atcelt"}, {"language", "Valoda"}, {"select_language", "Atlasīt valodu"}, {"profile_photo", "Profila foto"},
        {"name_label", "Vārds"}, {"participants_label", "Grupas dalībnieki"}, {"contact_name_placeholder", "Kontakta vārds"}, {"image_files_filter", "Attēlu faili (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — importēti %2 ziņojumi"}, {"conversation", "Saruna"},
        {"default_owner_name", "Noklusējuma īpašnieka vārds"}, {"owner_name_placeholder", "Jūsu vārds"}, {"not_set", "Nav iestatīts"}, {"default_label", "Noklusējums"},
        {"profile_library", "Profilu bibliotēka"}, {"add_profile", "Pievienot profilu"}, {"profile_name_label", "Vārds:"}, {"add_btn", "Pievienot"},
        {"optional", "(Neobligāti)"}, {"image_selected", "✓ Atlasīts"}, {"no_profiles_library", "Nav profilu. Noklikšķiniet uz +, lai pievienotu."},
        {"profile_owner_conflict", "Nevar pievienot profilu ar tādu pašu vārdu kā īpašniekam"}, {"profile_exists", "Profils ar šādu vārdu jau pastāv"},
        {"message_count_text", "ziņojumi"},
        {"january", "Jan"}, {"february", "Feb"}, {"march", "Mar"}, {"april", "Apr"}, {"may", "Mai"}, {"june", "Jūn"},
        {"july", "Jūl"}, {"august", "Aug"}, {"september", "Sep"}, {"october", "Okt"}, {"november", "Nov"}, {"december", "Dec"},
        {"calendar_tooltip", "Pāriet uz datumu"},
        {"last_message", "Pēdējais ziņojums"},
        {"settings", "Iestatījumi"},
        {"auto_play_next_voice", "Automātiski atskaņot balss ziņojumus pēc kārtas"},
        {"open_system", "Atvērt sistēmā"}, {"image_not_found", "Attēls nav atrasts"}, {"video", "Video"}, {"deleted_message", "Šis ziņojums tika dzēsts"}, {"you_deleted_message", "Jūs izdzēsāt šo ziņojumu"}, {"edited", "Rediģēts"}, {"app_version", "versija"}, {"app_copyright", "Autortiesības pieder %1"},
        {"lock_chat", "Slēgt čatu"}, {"unlock_chat", "Atslēgt šo čatu"}, {"locked_chats", "Slēgtie čati"}, {"locked_chats_access", "Piekļūt slēgtajiem čatiem"},
        {"lock_chat_title", "Slēgt čatu"}, {"lock_chat_message", "Šis čats tiks slēgts"}, {"lock_chat_set_password", "Iestatiet paroli, lai slēgtu čatus"},
        {"locked_chats_password_title", "Slēgtie čati"}, {"locked_chats_enter_password", "Ievadiet paroli, lai piekļūtu slēgtajiem čatiem"},
        {"password_6_digits", "Parolei jābūt 6 cipariem"}, {"password_incorrect", "Nepareiza parole"}, {"no_master_password", "Parole nav iestatīta"},
        {"locked_chats_password", "Slēgto čatu parole"}, {"no_password", "Jums nav paroles"}, {"change_password", "Mainīt paroli"},
        {"old_password", "Vecā parole"}, {"new_password", "Jaunā parole"}, {"confirm_password", "Apstipriniet jauno paroli"}, {"change", "Mainīt"},
        {"old_password_incorrect", "Vecā parole ir nepareiza"}, {"passwords_dont_match", "Jaunās paroles nesakrīt"},
        {"no_locked_chats", "Nav slēgtu čatu"}, {"locked_chats_hint", "Atlasiet 'Slēgt čatu' no 3 punktu izvēlnes, lai slēgtu čatu"}, {"enter", "Ievadīt"}
    };
    m_translations["Latvian"].insert(QStringLiteral("media_image"), QStringLiteral("Foto"));
    m_translations["Latvian"].insert(QStringLiteral("media_video"), QStringLiteral("Video"));
    m_translations["Latvian"].insert(QStringLiteral("media_voice"), QStringLiteral("Balss ziņojums"));
    m_translations["Latvian"].insert(QStringLiteral("media_audio"), QStringLiteral("Audio"));
    m_translations["Latvian"].insert(QStringLiteral("media_sticker"), QStringLiteral("Uzlīme"));
    m_translations["Latvian"].insert(QStringLiteral("media_document"), QStringLiteral("Dokuments"));
    m_translations["Latvian"].insert(QStringLiteral("media_unavailable"), QStringLiteral("Medijs nav pieejams"));
    m_translations["Latvian"].insert(QStringLiteral("tap_to_open"), QStringLiteral("Pieskarieties, lai atvērtu"));
    m_translations["Latvian"].insert(QStringLiteral("location"), QStringLiteral("Atrašanās vieta"));
    m_translations["Latvian"].insert(QStringLiteral("contact"), QStringLiteral("Kontakts"));
    m_translations["Latvian"].insert(QStringLiteral("favorites"), QStringLiteral("Favorīti"));
    m_translations["Latvian"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("Pievienot favorītiem"));
    m_translations["Latvian"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("Noņemt no favorītiem"));
    m_translations["Latvian"].insert(QStringLiteral("no_favorites"), QStringLiteral("Nav favorītu"));
    m_translations["Latvian"].insert(QStringLiteral("favorites_hint"), QStringLiteral("Ar peles labo pogu noklikšķiniet uz ziņojuma, lai pievienotu favorītiem"));
    m_translations["Latvian"].insert(QStringLiteral("media_browser"), QStringLiteral("Mediji"));
    m_translations["Latvian"].insert(QStringLiteral("media_browser_title"), QStringLiteral("Mediji"));
    m_translations["Latvian"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("Fotoattēli, videoklipi un faili"));
    m_translations["Latvian"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("Fotoattēli"));
    m_translations["Latvian"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("Videoklipi"));
    m_translations["Latvian"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("Dokumenti"));
    m_translations["Latvian"].insert(QStringLiteral("media_browser_links"), QStringLiteral("Saites"));
    m_translations["Latvian"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("Atrašanās vietas"));
    m_translations["Latvian"].insert(QStringLiteral("no_photos_found"), QStringLiteral("Nav atrasti fotoattēli"));
    m_translations["Latvian"].insert(QStringLiteral("no_videos_found"), QStringLiteral("Nav atrasti videoklipi"));
    m_translations["Latvian"].insert(QStringLiteral("no_documents_found"), QStringLiteral("Nav atrasti dokumenti"));
    m_translations["Latvian"].insert(QStringLiteral("no_links_found"), QStringLiteral("Nav atrastas saites"));
    m_translations["Latvian"].insert(QStringLiteral("no_locations_found"), QStringLiteral("Nav atrastas atrašanās vietas"));

    // Lithuanian
    m_translations["Lithuanian"] = {
        {"contact_info", "Kontakto informacija"}, {"msg_count", "Pranešimų skaičius"}, {"messages", "pranešimai"}, {"import_date", "Importavimo data"},
        {"no_chats", "Pokalbių nerasta\n\nSpustelėkite +, kad\npridėtumėte naują pokalbį"}, {"light_theme", "Šviesi tema"}, {"dark_theme", "Tamsi tema"},
        {"new_chat_tooltip", "Pridėti naują pokalbį"}, {"chat_search_placeholder", "Ieškoti pokalbiuose"}, {"importing", "Importuojama..."},
        {"bulk_select_tooltip", "Masinis pasirinkimas"}, {"bulk_delete_tooltip", "Masinis ištrynimas"}, {"cancel_selection_tooltip", "Atšaukti"},
        {"import_new", "Pridėti naują pokalbį"}, {"zip_description", "Pasirinkite ZIP failą, eksportuotą iš WhatsApp."},
        {"select_zip", "Pasirinkti ZIP failą"}, {"change_zip", "Pakeisti failą"}, {"continue", "Tęsti"},
        {"owner_question", "Koks jūsų vardas pokalbyje?\n(Vardas, rodomas jūsų WhatsApp paskyroje)"}, {"owner_placeholder", "Pvz.: Jonas Petraitis"},
        {"import_btn", "Importuoti"}, {"back", "Atgal"}, {"loading_messages", "Įkeliami pranešimai, prašome palaukti..."},
        {"select_zip_title", "Pasirinkite WhatsApp ZIP failą"}, {"first_message", "Pirmas pranešimas"}, {"delete_chat", "Ištrinti pokalbį"}, {"search", "Ieškoti..."}, {"search_tooltip", "Ieškoti pranešimuose (Ctrl+F)"},
        {"empty_chat_hint", "Pasirinkite pokalbį arba pridėkite naują"}, {"delete_confirm_title", "Ištrinti pokalbį"},
        {"delete_confirm_text", "Ar tikrai norite ištrinti šį pokalbį?\nVisi pranešimai bus pašalinti."}, {"no_results", "Rezultatų nerasta"},
        {"yes", "Taip"}, {"no", "Ne"}, {"cancel", "Atšaukti"}, {"language", "Kalba"}, {"select_language", "Pasirinkti kalbą"}, {"profile_photo", "Profilio nuotrauka"},
        {"name_label", "Vardas"}, {"participants_label", "Grupės dalyviai"}, {"contact_name_placeholder", "Kontakto vardas"}, {"image_files_filter", "Vaizdo failai (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — importuota %2 pranešimų"}, {"conversation", "Pokalbis"},
        {"default_owner_name", "Numatytasis savininko vardas"}, {"owner_name_placeholder", "Jūsų vardas"}, {"not_set", "Nenustatyta"}, {"default_label", "Numatytasis"},
        {"profile_library", "Profilių biblioteka"}, {"add_profile", "Pridėti profilį"}, {"profile_name_label", "Vardas:"}, {"add_btn", "Pridėti"},
        {"optional", "(Neprivaloma)"}, {"image_selected", "✓ Pasirinkta"}, {"no_profiles_library", "Dar nėra profilių. Spustelėkite +, kad pridėtumėte."},
        {"profile_owner_conflict", "Negalima pridėti profilio su tokiu pačiu vardu kaip savininko"}, {"profile_exists", "Profilis su šiuo vardu jau yra"},
        {"message_count_text", "pranešimai"},
        {"january", "Sau"}, {"february", "Vas"}, {"march", "Kov"}, {"april", "Bal"}, {"may", "Geg"}, {"june", "Bir"},
        {"july", "Lie"}, {"august", "Rgp"}, {"september", "Rgs"}, {"october", "Spa"}, {"november", "Lap"}, {"december", "Grd"},
        {"calendar_tooltip", "Pereiti prie datos"},
        {"last_message", "Paskutinis pranešimas"},
        {"settings", "Nustatymai"},
        {"auto_play_next_voice", "Automatiškai leisti balso pranešimus iš eilės"},
        {"open_system", "Atidaryti sistemoje"}, {"image_not_found", "Vaizdas nerastas"}, {"video", "Vaizdo įrašas"}, {"deleted_message", "Šis pranešimas buvo ištrintas"}, {"you_deleted_message", "Jūs ištrynėte šį pranešimą"}, {"edited", "Redaguota"}, {"app_version", "versija"}, {"app_copyright", "Autorių teisės priklauso %1"},
        {"lock_chat", "Užrakinti pokalbį"}, {"unlock_chat", "Atrakinti šį pokalbį"}, {"locked_chats", "Užrakinti pokalbiai"}, {"locked_chats_access", "Pasiekti užrakintus pokalbius"},
        {"lock_chat_title", "Užrakinti pokalbį"}, {"lock_chat_message", "Šis pokalbis bus užrakintas"}, {"lock_chat_set_password", "Nustatykite slaptažodį, kad užrakintumėte pokalbius"},
        {"locked_chats_password_title", "Užrakinti pokalbiai"}, {"locked_chats_enter_password", "Įveskite slaptažodį, kad pasiektumėte užrakintus pokalbius"},
        {"password_6_digits", "Slaptažodis turi būti 6 skaitmenų"}, {"password_incorrect", "Neteisingas slaptažodis"}, {"no_master_password", "Slaptažodis nenustatytas"},
        {"locked_chats_password", "Užrakintų pokalbių slaptažodis"}, {"no_password", "Neturite slaptažodžio"}, {"change_password", "Pakeisti slaptažodį"},
        {"old_password", "Senas slaptažodis"}, {"new_password", "Naujas slaptažodis"}, {"confirm_password", "Patvirtinkite naują slaptažodį"}, {"change", "Pakeisti"},
        {"old_password_incorrect", "Senas slaptažodis neteisingas"}, {"passwords_dont_match", "Nauji slaptažodžiai nesutampa"},
        {"no_locked_chats", "Nėra užrakintų pokalbių"}, {"locked_chats_hint", "Pasirinkite 'Užrakinti pokalbį' iš 3 taškų meniu, kad užrakintumėte pokalbį"}, {"enter", "Įeiti"}
    };
    m_translations["Lithuanian"].insert(QStringLiteral("media_image"), QStringLiteral("Nuotrauka"));
    m_translations["Lithuanian"].insert(QStringLiteral("media_video"), QStringLiteral("Vaizdo įrašas"));
    m_translations["Lithuanian"].insert(QStringLiteral("media_voice"), QStringLiteral("Balso pranešimas"));
    m_translations["Lithuanian"].insert(QStringLiteral("media_audio"), QStringLiteral("Garsas"));
    m_translations["Lithuanian"].insert(QStringLiteral("media_sticker"), QStringLiteral("Lipdukas"));
    m_translations["Lithuanian"].insert(QStringLiteral("media_document"), QStringLiteral("Dokumentas"));
    m_translations["Lithuanian"].insert(QStringLiteral("media_unavailable"), QStringLiteral("Medija nepasiekiama"));
    m_translations["Lithuanian"].insert(QStringLiteral("tap_to_open"), QStringLiteral("Bakstelėkite, kad atidarytumėte"));
    m_translations["Lithuanian"].insert(QStringLiteral("location"), QStringLiteral("Vieta"));
    m_translations["Lithuanian"].insert(QStringLiteral("contact"), QStringLiteral("Kontaktas"));
    m_translations["Lithuanian"].insert(QStringLiteral("favorites"), QStringLiteral("Mėgstamiausi"));
    m_translations["Lithuanian"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("Pridėti prie mėgstamiausių"));
    m_translations["Lithuanian"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("Pašalinti iš mėgstamiausių"));
    m_translations["Lithuanian"].insert(QStringLiteral("no_favorites"), QStringLiteral("Nėra mėgstamiausių"));
    m_translations["Lithuanian"].insert(QStringLiteral("favorites_hint"), QStringLiteral("Dešiniuoju pelės mygtuku spustelėkite pranešimą, kad pridėtumėte prie mėgstamiausių"));
    m_translations["Lithuanian"].insert(QStringLiteral("media_browser"), QStringLiteral("Medija"));
    m_translations["Lithuanian"].insert(QStringLiteral("media_browser_title"), QStringLiteral("Medija"));
    m_translations["Lithuanian"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("Nuotraukos, vaizdo įrašai ir failai"));
    m_translations["Lithuanian"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("Nuotraukos"));
    m_translations["Lithuanian"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("Vaizdo įrašai"));
    m_translations["Lithuanian"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("Dokumentai"));
    m_translations["Lithuanian"].insert(QStringLiteral("media_browser_links"), QStringLiteral("Nuorodos"));
    m_translations["Lithuanian"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("Vietos"));
    m_translations["Lithuanian"].insert(QStringLiteral("no_photos_found"), QStringLiteral("Nuotraukų nerasta"));
    m_translations["Lithuanian"].insert(QStringLiteral("no_videos_found"), QStringLiteral("Vaizdo įrašų nerasta"));
    m_translations["Lithuanian"].insert(QStringLiteral("no_documents_found"), QStringLiteral("Dokumentų nerasta"));
    m_translations["Lithuanian"].insert(QStringLiteral("no_links_found"), QStringLiteral("Nuorodų nerasta"));
    m_translations["Lithuanian"].insert(QStringLiteral("no_locations_found"), QStringLiteral("Vietų nerasta"));

    // Macedonian
    m_translations["Macedonian"] = {
        {"contact_info", "Информации за контакт"}, {"msg_count", "Број на пораки"}, {"messages", "пораки"}, {"import_date", "Датум на увоз"},
        {"no_chats", "Нема пронајдено разговори\n\nКликнете + за да\nдодадете нов разговор"}, {"light_theme", "Светла тема"}, {"dark_theme", "Темна тема"},
        {"new_chat_tooltip", "Додај нов разговор"}, {"chat_search_placeholder", "Пребарај во разговори"}, {"importing", "Увезува..."},
        {"bulk_select_tooltip", "Групно избирање"}, {"bulk_delete_tooltip", "Групно бришење"}, {"cancel_selection_tooltip", "Откажи"},
        {"import_new", "Додај нов разговор"}, {"zip_description", "Изберете ZIP датотека извезена од WhatsApp."},
        {"select_zip", "Избери ZIP датотека"}, {"change_zip", "Промени датотека"}, {"continue", "Продолжи"},
        {"owner_question", "Како се викате во разговорот?\n(Името прикажано во вашата WhatsApp сметка)"}, {"owner_placeholder", "Пр.: Марко Петковски"},
        {"import_btn", "Увези"}, {"back", "Назад"}, {"loading_messages", "Се вчитуваат пораки, ве молиме почекајте..."},
        {"select_zip_title", "Изберете WhatsApp ZIP датотека"}, {"first_message", "Прва порака"}, {"delete_chat", "Избриши разговор"}, {"search", "Пребарај..."}, {"search_tooltip", "Пребарај во пораки (Ctrl+F)"},
        {"empty_chat_hint", "Изберете разговор или додајте нов"}, {"delete_confirm_title", "Избриши разговор"},
        {"delete_confirm_text", "Дали сте сигурни дека сакате да го избришете овој разговор?\nСите пораки ќе бидат отстранети."}, {"no_results", "Нема пронајдени резултати"},
        {"yes", "Да"}, {"no", "Не"}, {"cancel", "Откажи"}, {"language", "Јазик"}, {"select_language", "Избери јазик"}, {"profile_photo", "Профилна фотографија"},
        {"name_label", "Име"}, {"participants_label", "Учесници во група"}, {"contact_name_placeholder", "Име на контакт"}, {"image_files_filter", "Датотеки со слики (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — увезени %2 пораки"}, {"conversation", "Разговор"},
        {"default_owner_name", "Име на сопственик по основно"}, {"owner_name_placeholder", "Вашето име"}, {"not_set", "Не е поставено"}, {"default_label", "Основно"},
        {"profile_library", "Библиотека на профили"}, {"add_profile", "Додај профил"}, {"profile_name_label", "Име:"}, {"add_btn", "Додај"},
        {"optional", "(Опционално)"}, {"image_selected", "✓ Избрано"}, {"no_profiles_library", "Сè уште нема профили. Кликнете + за да додадете."},
        {"profile_owner_conflict", "Не може да се додаде профил со исто име како сопственикот"}, {"profile_exists", "Профил со ова име веќе постои"},
        {"message_count_text", "пораки"},
        {"january", "јан"}, {"february", "фев"}, {"march", "мар"}, {"april", "апр"}, {"may", "мај"}, {"june", "јун"},
        {"july", "јул"}, {"august", "авг"}, {"september", "сеп"}, {"october", "окт"}, {"november", "ное"}, {"december", "дек"},
        {"calendar_tooltip", "Оди на датум"},
        {"last_message", "Последна порака"},
        {"settings", "Поставки"},
        {"auto_play_next_voice", "Автоматски репродуцирај гласовни пораки по ред"},
        {"open_system", "Отвори во систем"}, {"image_not_found", "Сликата не е пронајдена"}, {"video", "Видео"}, {"deleted_message", "Оваа порака беше избришана"}, {"you_deleted_message", "Ја избришавте оваа порака"}, {"edited", "Изменето"}, {"app_version", "верзија"}, {"app_copyright", "Авторски права %1"},
        {"lock_chat", "Заклучи разговор"}, {"unlock_chat", "Отклучи разговор"}, {"locked_chats", "Заклучени разговори"}, {"locked_chats_access", "Пристап до заклучени разговори"},
        {"lock_chat_title", "Заклучи разговор"}, {"lock_chat_message", "Овој разговор ќе биде заклучен"}, {"lock_chat_set_password", "Поставете лозинка за да заклучите разговори"},
        {"locked_chats_password_title", "Заклучени разговори"}, {"locked_chats_enter_password", "Внесете лозинка за пристап до заклучени разговори"},
        {"password_6_digits", "Лозинката мора да биде 6 цифри"}, {"password_incorrect", "Неточна лозинка"}, {"no_master_password", "Лозинката не е поставена"},
        {"locked_chats_password", "Лозинка за заклучени разговори"}, {"no_password", "Немате лозинка"}, {"change_password", "Промени лозинка"},
        {"old_password", "Стара лозинка"}, {"new_password", "Нова лозинка"}, {"confirm_password", "Потврди нова лозинка"}, {"change", "Промени"},
        {"old_password_incorrect", "Старата лозинка е неточна"}, {"passwords_dont_match", "Новите лозинки не се совпаѓаат"},
        {"no_locked_chats", "Нема заклучени разговори"}, {"locked_chats_hint", "Изберете 'Заклучи разговор' од менито со 3 точки за да заклучите разговор"}, {"enter", "Внеси"}
    };
    m_translations["Macedonian"].insert(QStringLiteral("media_image"), QStringLiteral("Фотографија"));
    m_translations["Macedonian"].insert(QStringLiteral("media_video"), QStringLiteral("Видео"));
    m_translations["Macedonian"].insert(QStringLiteral("media_voice"), QStringLiteral("Гласовна порака"));
    m_translations["Macedonian"].insert(QStringLiteral("media_audio"), QStringLiteral("Аудио"));
    m_translations["Macedonian"].insert(QStringLiteral("media_sticker"), QStringLiteral("Стикер"));
    m_translations["Macedonian"].insert(QStringLiteral("media_document"), QStringLiteral("Документ"));
    m_translations["Macedonian"].insert(QStringLiteral("media_unavailable"), QStringLiteral("Медиумот не е достапен"));
    m_translations["Macedonian"].insert(QStringLiteral("tap_to_open"), QStringLiteral("Допрете за отворање"));
    m_translations["Macedonian"].insert(QStringLiteral("location"), QStringLiteral("Локација"));
    m_translations["Macedonian"].insert(QStringLiteral("contact"), QStringLiteral("Контакт"));
    m_translations["Macedonian"].insert(QStringLiteral("favorites"), QStringLiteral("Омилени"));
    m_translations["Macedonian"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("Додај во омилени"));
    m_translations["Macedonian"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("Отстрани од омилени"));
    m_translations["Macedonian"].insert(QStringLiteral("no_favorites"), QStringLiteral("Нема омилени"));
    m_translations["Macedonian"].insert(QStringLiteral("favorites_hint"), QStringLiteral("Кликнете со десно на порака за да додадете во омилени"));
    m_translations["Macedonian"].insert(QStringLiteral("media_browser"), QStringLiteral("Медиуми"));
    m_translations["Macedonian"].insert(QStringLiteral("media_browser_title"), QStringLiteral("Медиуми"));
    m_translations["Macedonian"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("Фотографии, видеа и датотеки"));
    m_translations["Macedonian"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("Фотографии"));
    m_translations["Macedonian"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("Видеа"));
    m_translations["Macedonian"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("Документи"));
    m_translations["Macedonian"].insert(QStringLiteral("media_browser_links"), QStringLiteral("Врски"));
    m_translations["Macedonian"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("Локации"));
    m_translations["Macedonian"].insert(QStringLiteral("no_photos_found"), QStringLiteral("Нема пронајдени фотографии"));
    m_translations["Macedonian"].insert(QStringLiteral("no_videos_found"), QStringLiteral("Нема пронајдени видеа"));
    m_translations["Macedonian"].insert(QStringLiteral("no_documents_found"), QStringLiteral("Нема пронајдени документи"));
    m_translations["Macedonian"].insert(QStringLiteral("no_links_found"), QStringLiteral("Нема пронајдени врски"));
    m_translations["Macedonian"].insert(QStringLiteral("no_locations_found"), QStringLiteral("Нема пронајдени локации"));

    // Malay
    m_translations["Malay"] = {
        {"contact_info", "Maklumat kenalan"}, {"msg_count", "Bilangan mesej"}, {"messages", "mesej"}, {"import_date", "Tarikh import"},
        {"no_chats", "Tiada sembang ditemui\n\nKlik + untuk menambah\nsembang baharu"}, {"light_theme", "Tema cerah"}, {"dark_theme", "Tema gelap"},
        {"new_chat_tooltip", "Tambah sembang baharu"}, {"chat_search_placeholder", "Cari dalam sembang"}, {"importing", "Mengimport..."},
        {"bulk_select_tooltip", "Pemilihan pukal"}, {"bulk_delete_tooltip", "Padam pukal"}, {"cancel_selection_tooltip", "Batal"},
        {"import_new", "Tambah sembang baharu"}, {"zip_description", "Pilih fail ZIP yang dieksport dari WhatsApp."},
        {"select_zip", "Pilih fail ZIP"}, {"change_zip", "Tukar fail"}, {"continue", "Teruskan"},
        {"owner_question", "Apakah nama anda dalam sembang?\n(Nama yang dipaparkan dalam akaun WhatsApp anda)"}, {"owner_placeholder", "Cth: Ahmad Abdullah"},
        {"import_btn", "Import"}, {"back", "Kembali"}, {"loading_messages", "Memuatkan mesej, sila tunggu..."},
        {"select_zip_title", "Pilih fail ZIP WhatsApp"}, {"first_message", "Mesej pertama"}, {"delete_chat", "Padam sembang"}, {"search", "Cari..."}, {"search_tooltip", "Cari dalam mesej (Ctrl+F)"},
        {"empty_chat_hint", "Pilih sembang atau tambah yang baharu"}, {"delete_confirm_title", "Padam sembang"},
        {"delete_confirm_text", "Adakah anda pasti mahu memadam sembang ini?\nSemua mesej akan dialihkan."}, {"no_results", "Tiada hasil ditemui"},
        {"yes", "Ya"}, {"no", "Tidak"}, {"cancel", "Batal"}, {"language", "Bahasa"}, {"select_language", "Pilih bahasa"}, {"profile_photo", "Foto profil"},
        {"name_label", "Nama"}, {"participants_label", "Ahli kumpulan"}, {"contact_name_placeholder", "Nama kenalan"}, {"image_files_filter", "Fail imej (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — %2 mesej diimport"}, {"conversation", "Perbualan"},
        {"default_owner_name", "Nama Pemilik Lalai"}, {"owner_name_placeholder", "Nama anda"}, {"not_set", "Tidak ditetapkan"}, {"default_label", "Lalai"},
        {"profile_library", "Perpustakaan Profil"}, {"add_profile", "Tambah Profil"}, {"profile_name_label", "Nama:"}, {"add_btn", "Tambah"},
        {"optional", "(Pilihan)"}, {"image_selected", "✓ Dipilih"}, {"no_profiles_library", "Belum ada profil. Klik + untuk menambah."},
        {"profile_owner_conflict", "Tidak boleh menambah profil dengan nama yang sama dengan pemilik"}, {"profile_exists", "Profil dengan nama ini sudah wujud"},
        {"message_count_text", "mesej"},
        {"january", "Jan"}, {"february", "Feb"}, {"march", "Mac"}, {"april", "Apr"}, {"may", "Mei"}, {"june", "Jun"},
        {"july", "Jul"}, {"august", "Ogos"}, {"september", "Sep"}, {"october", "Okt"}, {"november", "Nov"}, {"december", "Dis"},
        {"calendar_tooltip", "Pergi ke tarikh"},
        {"last_message", "Mesej terakhir"},
        {"settings", "Tetapan"},
        {"auto_play_next_voice", "Main mesej suara berturut-turut secara automatik"},
        {"open_system", "Buka dalam sistem"}, {"image_not_found", "Imej tidak dijumpai"}, {"video", "Video"}, {"deleted_message", "Mesej ini telah dipadam"}, {"you_deleted_message", "Anda memadam mesej ini"}, {"edited", "Diedit"}, {"app_version", "versi"}, {"app_copyright", "Hak cipta oleh %1"},
        {"lock_chat", "Kunci sembang"}, {"unlock_chat", "Buka kunci sembang ini"}, {"locked_chats", "Sembang Berkunci"}, {"locked_chats_access", "Akses sembang berkunci"},
        {"lock_chat_title", "Kunci sembang"}, {"lock_chat_message", "Sembang ini akan dikunci"}, {"lock_chat_set_password", "Tetapkan kata laluan untuk mengunci sembang"},
        {"locked_chats_password_title", "Sembang berkunci"}, {"locked_chats_enter_password", "Masukkan kata laluan untuk mengakses sembang berkunci"},
        {"password_6_digits", "Kata laluan mesti 6 digit"}, {"password_incorrect", "Kata laluan salah"}, {"no_master_password", "Kata laluan tidak ditetapkan"},
        {"locked_chats_password", "Kata Laluan Sembang Berkunci"}, {"no_password", "Anda tidak mempunyai kata laluan"}, {"change_password", "Tukar kata laluan"},
        {"old_password", "Kata laluan lama"}, {"new_password", "Kata laluan baharu"}, {"confirm_password", "Sahkan kata laluan baharu"}, {"change", "Tukar"},
        {"old_password_incorrect", "Kata laluan lama salah"}, {"passwords_dont_match", "Kata laluan baharu tidak sepadan"},
        {"no_locked_chats", "Tiada sembang berkunci"}, {"locked_chats_hint", "Pilih 'Kunci sembang' dari menu 3 titik untuk mengunci sembang"}, {"enter", "Masuk"}
    };
    m_translations["Malay"].insert(QStringLiteral("media_image"), QStringLiteral("Foto"));
    m_translations["Malay"].insert(QStringLiteral("media_video"), QStringLiteral("Video"));
    m_translations["Malay"].insert(QStringLiteral("media_voice"), QStringLiteral("Mesej suara"));
    m_translations["Malay"].insert(QStringLiteral("media_audio"), QStringLiteral("Audio"));
    m_translations["Malay"].insert(QStringLiteral("media_sticker"), QStringLiteral("Pelekat"));
    m_translations["Malay"].insert(QStringLiteral("media_document"), QStringLiteral("Dokumen"));
    m_translations["Malay"].insert(QStringLiteral("media_unavailable"), QStringLiteral("Media tidak tersedia"));
    m_translations["Malay"].insert(QStringLiteral("tap_to_open"), QStringLiteral("Ketik untuk membuka"));
    m_translations["Malay"].insert(QStringLiteral("location"), QStringLiteral("Lokasi"));
    m_translations["Malay"].insert(QStringLiteral("contact"), QStringLiteral("Kenalan"));
    m_translations["Malay"].insert(QStringLiteral("favorites"), QStringLiteral("Kegemaran"));
    m_translations["Malay"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("Tambah ke kegemaran"));
    m_translations["Malay"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("Buang dari kegemaran"));
    m_translations["Malay"].insert(QStringLiteral("no_favorites"), QStringLiteral("Tiada kegemaran"));
    m_translations["Malay"].insert(QStringLiteral("favorites_hint"), QStringLiteral("Klik kanan mesej untuk menambah ke kegemaran"));
    m_translations["Malay"].insert(QStringLiteral("media_browser"), QStringLiteral("Media"));
    m_translations["Malay"].insert(QStringLiteral("media_browser_title"), QStringLiteral("Media"));
    m_translations["Malay"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("Foto, video dan fail"));
    m_translations["Malay"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("Foto"));
    m_translations["Malay"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("Video"));
    m_translations["Malay"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("Dokumen"));
    m_translations["Malay"].insert(QStringLiteral("media_browser_links"), QStringLiteral("Pautan"));
    m_translations["Malay"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("Lokasi"));
    m_translations["Malay"].insert(QStringLiteral("no_photos_found"), QStringLiteral("Tiada foto dijumpai"));
    m_translations["Malay"].insert(QStringLiteral("no_videos_found"), QStringLiteral("Tiada video dijumpai"));
    m_translations["Malay"].insert(QStringLiteral("no_documents_found"), QStringLiteral("Tiada dokumen dijumpai"));
    m_translations["Malay"].insert(QStringLiteral("no_links_found"), QStringLiteral("Tiada pautan dijumpai"));
    m_translations["Malay"].insert(QStringLiteral("no_locations_found"), QStringLiteral("Tiada lokasi dijumpai"));

    // Malayalam
    m_translations["Malayalam"] = {
        {"contact_info", "കോൺടാക്റ്റ് വിവരം"}, {"msg_count", "സന്ദേശങ്ങൾ"}, {"messages", "സന്ദേശങ്ങൾ"}, {"import_date", "ഇമ്പോർട്ട് തീയതി"},
        {"no_chats", "ചാറ്റുകളൊന്നും കണ്ടെത്തിയില്ല\n\nപുതിയ ചാറ്റ് ചേർക്കാൻ\n+ ക്ലിക്ക് ചെയ്യുക"}, {"light_theme", "ലൈറ്റ് തീം"}, {"dark_theme", "ഡാർക്ക് തീം"},
        {"new_chat_tooltip", "പുതിയ ചാറ്റ് ചേർക്കുക"}, {"chat_search_placeholder", "ചാറ്റുകളിൽ തിരയുക"}, {"importing", "ഇമ്പോർട്ട് ചെയ്യുന്നു..."},
        {"bulk_select_tooltip", "ബൾക്ക് തിരഞ്ഞെടുക്കൽ"}, {"bulk_delete_tooltip", "ബൾക്ക് ഡിലീറ്റ്"}, {"cancel_selection_tooltip", "റദ്ദാക്കുക"},
        {"import_new", "പുതിയ ചാറ്റ് ചേർക്കുക"}, {"zip_description", "WhatsApp-ൽ നിന്ന് എക്‌സ്‌പോർട്ട് ചെയ്ത ZIP ഫയൽ തിരഞ്ഞെടുക്കുക."},
        {"select_zip", "ZIP ഫയൽ തിരഞ്ഞെടുക്കുക"}, {"change_zip", "ഫയൽ മാറ്റുക"}, {"continue", "തുടരുക"},
        {"owner_question", "ചാറ്റിൽ നിങ്ങളുടെ പേരെന്താണ്?\n(നിങ്ങളുടെ WhatsApp അക്കൗണ്ടിൽ ദൃശ്യമാകുന്ന പേര്)"}, {"owner_placeholder", "ഉദാ: രാജേഷ് കുമാർ"},
        {"import_btn", "ഇമ്പോർട്ട്"}, {"back", "പിന്നോട്ട്"}, {"loading_messages", "സന്ദേശങ്ങൾ ലോഡ് ചെയ്യുന്നു, കാത്തിരിക്കുക..."},
        {"select_zip_title", "WhatsApp ZIP ഫയൽ തിരഞ്ഞെടുക്കുക"}, {"first_message", "ആദ്യ സന്ദേശം"}, {"delete_chat", "ചാറ്റ് ഡിലീറ്റ് ചെയ്യുക"}, {"search", "തിരയുക..."}, {"search_tooltip", "സന്ദേശങ്ങളിൽ തിരയുക (Ctrl+F)"},
        {"empty_chat_hint", "ഒരു ചാറ്റ് തിരഞ്ഞെടുക്കുക അല്ലെങ്കിൽ പുതിയത് ചേർക്കുക"}, {"delete_confirm_title", "ചാറ്റ് ഡിലീറ്റ് ചെയ്യുക"},
        {"delete_confirm_text", "നിങ്ങൾക്ക് ഈ ചാറ്റ് ഡിലീറ്റ് ചെയ്യണമെന്ന് ഉറപ്പാണോ?\nഎല്ലാ സന്ദേശങ്ങളും നീക്കം ചെയ്യപ്പെടും."}, {"no_results", "ഫലങ്ങളൊന്നും കണ്ടെത്തിയില്ല"},
        {"yes", "അതെ"}, {"no", "ഇല്ല"}, {"cancel", "റദ്ദാക്കുക"}, {"language", "ഭാഷ"}, {"select_language", "ഭാഷ തിരഞ്ഞെടുക്കുക"}, {"profile_photo", "പ്രൊഫൈൽ ഫോട്ടോ"},
        {"name_label", "പേര്"}, {"participants_label", "ഗ്രൂപ്പ് അംഗങ്ങൾ"}, {"contact_name_placeholder", "കോൺടാക്റ്റ് പേര്"}, {"image_files_filter", "ഇമേജ് ഫയലുകൾ (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — %2 സന്ദേശങ്ങൾ ഇമ്പോർട്ട് ചെയ്തു"}, {"conversation", "സംഭാഷണം"},
        {"default_owner_name", "ഡിഫോൾട്ട് ഉടമ പേര്"}, {"owner_name_placeholder", "നിങ്ങളുടെ പേര്"}, {"not_set", "സജ്ജീകരിച്ചിട്ടില്ല"}, {"default_label", "ഡിഫോൾട്ട്"},
        {"profile_library", "പ്രൊഫൈൽ ലൈബ്രറി"}, {"add_profile", "പ്രൊഫൈൽ ചേർക്കുക"}, {"profile_name_label", "പേര്:"}, {"add_btn", "ചേർക്കുക"},
        {"optional", "(ഓപ്ഷണൽ)"}, {"image_selected", "✓ തിരഞ്ഞെടുത്തു"}, {"no_profiles_library", "ഇതുവരെ പ്രൊഫൈലുകളൊന്നുമില്ല. ചേർക്കാൻ + ക്ലിക്ക് ചെയ്യുക."},
        {"profile_owner_conflict", "ഉടമയുടെ പേര് ഉപയോഗിച്ച് പ്രൊഫൈൽ ചേർക്കാനാകില്ല"}, {"profile_exists", "ഈ പേരിൽ പ്രൊഫൈൽ ഇതിനകം നിലവിലുണ്ട്"},
        {"message_count_text", "സന്ദേശങ്ങൾ"},
        {"january", "ജനു"}, {"february", "ഫെബ്രു"}, {"march", "മാർച്ച്"}, {"april", "ഏപ്രിൽ"}, {"may", "മെയ്"}, {"june", "ജൂൺ"},
        {"july", "ജൂലൈ"}, {"august", "ഓഗസ്റ്റ്"}, {"september", "സെപ്റ്റം"}, {"october", "ഒക്ടോ"}, {"november", "നവം"}, {"december", "ഡിസം"},
        {"calendar_tooltip", "തീയതിയിലേക്ക് പോകുക"},
        {"last_message", "അവസാന സന്ദേശം"},
        {"settings", "ക്രമീകരണങ്ങൾ"},
        {"auto_play_next_voice", "തുടർച്ചയായ വോയ്‌സ് സന്ദേശങ്ങൾ ഓട്ടോ-പ്ലേ ചെയ്യുക"},
        {"open_system", "സിസ്റ്റത്തിൽ തുറക്കുക"}, {"image_not_found", "ഇമേജ് കണ്ടെത്തിയില്ല"}, {"video", "വീഡിയോ"}, {"deleted_message", "ഈ സന്ദേശം ഡിലീറ്റ് ചെയ്തു"}, {"you_deleted_message", "നിങ്ങൾ ഈ സന്ദേശം ഡിലീറ്റ് ചെയ്തു"}, {"edited", "എഡിറ്റ് ചെയ്തു"}, {"app_version", "പതിപ്പ്"}, {"app_copyright", "പകർപ്പവകാശം %1"},
        {"lock_chat", "ചാറ്റ് ലോക്ക് ചെയ്യുക"}, {"unlock_chat", "ഈ ചാറ്റ് അൺലോക്ക് ചെയ്യുക"}, {"locked_chats", "ലോക്ക്ഡ് ചാറ്റുകൾ"}, {"locked_chats_access", "ലോക്ക്ഡ് ചാറ്റുകൾ ആക്‌സസ് ചെയ്യുക"},
        {"lock_chat_title", "ചാറ്റ് ലോക്ക് ചെയ്യുക"}, {"lock_chat_message", "ഈ ചാറ്റ് ലോക്ക് ചെയ്യപ്പെടും"}, {"lock_chat_set_password", "ചാറ്റുകൾ ലോക്ക് ചെയ്യാൻ പാസ്‌വേഡ് സജ്ജീകരിക്കുക"},
        {"locked_chats_password_title", "ലോക്ക്ഡ് ചാറ്റുകൾ"}, {"locked_chats_enter_password", "ലോക്ക്ഡ് ചാറ്റുകൾ ആക്‌സസ് ചെയ്യാൻ പാസ്‌വേഡ് നൽകുക"},
        {"password_6_digits", "പാസ്‌വേഡ് 6 അക്കങ്ങൾ ആയിരിക്കണം"}, {"password_incorrect", "തെറ്റായ പാസ്‌വേഡ്"}, {"no_master_password", "പാസ്‌വേഡ് സജ്ജീകരിച്ചിട്ടില്ല"},
        {"locked_chats_password", "ലോക്ക്ഡ് ചാറ്റുകളുടെ പാസ്‌വേഡ്"}, {"no_password", "നിങ്ങൾക്ക് പാസ്‌വേഡില്ല"}, {"change_password", "പാസ്‌വേഡ് മാറ്റുക"},
        {"old_password", "പഴയ പാസ്‌വേഡ്"}, {"new_password", "പുതിയ പാസ്‌വേഡ്"}, {"confirm_password", "പുതിയ പാസ്‌വേഡ് സ്ഥിരീകരിക്കുക"}, {"change", "മാറ്റുക"},
        {"old_password_incorrect", "പഴയ പാസ്‌വേഡ് തെറ്റാണ്"}, {"passwords_dont_match", "പുതിയ പാസ്‌വേഡുകൾ പൊരുത്തപ്പെടുന്നില്ല"},
        {"no_locked_chats", "ലോക്ക്ഡ് ചാറ്റുകളൊന്നുമില്ല"}, {"locked_chats_hint", "ഒരു ചാറ്റ് ലോക്ക് ചെയ്യാൻ 3-ഡോട്ട് മെനുവിൽ നിന്ന് 'ചാറ്റ് ലോക്ക് ചെയ്യുക' തിരഞ്ഞെടുക്കുക"}, {"enter", "പ്രവേശിക്കുക"}
    };
    m_translations["Malayalam"].insert(QStringLiteral("media_image"), QStringLiteral("ഫോട്ടോ"));
    m_translations["Malayalam"].insert(QStringLiteral("media_video"), QStringLiteral("വീഡിയോ"));
    m_translations["Malayalam"].insert(QStringLiteral("media_voice"), QStringLiteral("വോയ്‌സ് സന്ദേശം"));
    m_translations["Malayalam"].insert(QStringLiteral("media_audio"), QStringLiteral("ഓഡിയോ"));
    m_translations["Malayalam"].insert(QStringLiteral("media_sticker"), QStringLiteral("സ്റ്റിക്കർ"));
    m_translations["Malayalam"].insert(QStringLiteral("media_document"), QStringLiteral("ഡോക്യുമെന്റ്"));
    m_translations["Malayalam"].insert(QStringLiteral("media_unavailable"), QStringLiteral("മീഡിയ ലഭ്യമല്ല"));
    m_translations["Malayalam"].insert(QStringLiteral("tap_to_open"), QStringLiteral("തുറക്കാൻ ടാപ്പ് ചെയ്യുക"));
    m_translations["Malayalam"].insert(QStringLiteral("location"), QStringLiteral("ലൊക്കേഷൻ"));
    m_translations["Malayalam"].insert(QStringLiteral("contact"), QStringLiteral("കോൺടാക്റ്റ്"));
    m_translations["Malayalam"].insert(QStringLiteral("favorites"), QStringLiteral("പ്രിയങ്കരം"));
    m_translations["Malayalam"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("പ്രിയങ്കരത്തിൽ ചേർക്കുക"));
    m_translations["Malayalam"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("പ്രിയങ്കരത്തിൽ നിന്ന് നീക്കം ചെയ്യുക"));
    m_translations["Malayalam"].insert(QStringLiteral("no_favorites"), QStringLiteral("പ്രിയങ്കരമൊന്നുമില്ല"));
    m_translations["Malayalam"].insert(QStringLiteral("favorites_hint"), QStringLiteral("പ്രിയങ്കരത്തിൽ ചേർക്കാൻ സന്ദേശത്തിൽ വലത് ക്ലിക്ക് ചെയ്യുക"));
    m_translations["Malayalam"].insert(QStringLiteral("media_browser"), QStringLiteral("മീഡിയ"));
    m_translations["Malayalam"].insert(QStringLiteral("media_browser_title"), QStringLiteral("മീഡിയ"));
    m_translations["Malayalam"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("ഫോട്ടോകൾ, വീഡിയോകൾ, ഫയലുകൾ"));
    m_translations["Malayalam"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("ഫോട്ടോകൾ"));
    m_translations["Malayalam"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("വീഡിയോകൾ"));
    m_translations["Malayalam"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("ഡോക്യുമെന്റുകൾ"));
    m_translations["Malayalam"].insert(QStringLiteral("media_browser_links"), QStringLiteral("ലിങ്കുകൾ"));
    m_translations["Malayalam"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("ലൊക്കേഷനുകൾ"));
    m_translations["Malayalam"].insert(QStringLiteral("no_photos_found"), QStringLiteral("ഫോട്ടോകൾ കണ്ടെത്തിയില്ല"));
    m_translations["Malayalam"].insert(QStringLiteral("no_videos_found"), QStringLiteral("വീഡിയോകൾ കണ്ടെത്തിയില്ല"));
    m_translations["Malayalam"].insert(QStringLiteral("no_documents_found"), QStringLiteral("ഡോക്യുമെന്റുകൾ കണ്ടെത്തിയില്ല"));
    m_translations["Malayalam"].insert(QStringLiteral("no_links_found"), QStringLiteral("ലിങ്കുകൾ കണ്ടെത്തിയില്ല"));
    m_translations["Malayalam"].insert(QStringLiteral("no_locations_found"), QStringLiteral("ലൊക്കേഷനുകൾ കണ്ടെത്തിയില്ല"));

    // Marathi
    m_translations["Marathi"] = {
        {"contact_info", "संपर्क माहिती"}, {"msg_count", "संदेश संख्या"}, {"messages", "संदेश"}, {"import_date", "आयात तारीख"},
        {"no_chats", "चॅट सापडले नाहीत\n\nनवीन चॅट जोडण्यासाठी\n+ वर क्लिक करा"}, {"light_theme", "लाइट थीम"}, {"dark_theme", "डार्क थीम"},
        {"new_chat_tooltip", "नवीन चॅट जोडा"}, {"chat_search_placeholder", "चॅटमध्ये शोधा"}, {"importing", "आयात करत आहे..."},
        {"bulk_select_tooltip", "बल्क निवड"}, {"bulk_delete_tooltip", "बल्क हटवा"}, {"cancel_selection_tooltip", "रद्द करा"},
        {"import_new", "नवीन चॅट जोडा"}, {"zip_description", "WhatsApp मधून निर्यात केलेली ZIP फाइल निवडा."},
        {"select_zip", "ZIP फाइल निवडा"}, {"change_zip", "फाइल बदला"}, {"continue", "सुरू ठेवा"},
        {"owner_question", "चॅटमध्ये तुमचे नाव काय आहे?\n(तुमच्या WhatsApp अकाउंटमध्ये दिसणारे नाव)"}, {"owner_placeholder", "उदा: राजेश कुमार"},
        {"import_btn", "आयात करा"}, {"back", "मागे"}, {"loading_messages", "संदेश लोड करत आहे, कृपया प्रतीक्षा करा..."},
        {"select_zip_title", "WhatsApp ZIP फाइल निवडा"}, {"first_message", "पहिला संदेश"}, {"delete_chat", "चॅट हटवा"}, {"search", "शोधा..."}, {"search_tooltip", "संदेशांमध्ये शोधा (Ctrl+F)"},
        {"empty_chat_hint", "चॅट निवडा किंवा नवीन जोडा"}, {"delete_confirm_title", "चॅट हटवा"},
        {"delete_confirm_text", "तुम्हाला नक्की ही चॅट हटवायची आहे?\nसर्व संदेश काढून टाकले जातील."}, {"no_results", "निकाल सापडले नाहीत"},
        {"yes", "होय"}, {"no", "नाही"}, {"cancel", "रद्द करा"}, {"language", "भाषा"}, {"select_language", "भाषा निवडा"}, {"profile_photo", "प्रोफाइल फोटो"},
        {"name_label", "नाव"}, {"participants_label", "गट सदस्य"}, {"contact_name_placeholder", "संपर्क नाव"}, {"image_files_filter", "इमेज फायली (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — %2 संदेश आयात केले"}, {"conversation", "संभाषण"},
        {"default_owner_name", "डीफॉल्ट मालक नाव"}, {"owner_name_placeholder", "तुमचे नाव"}, {"not_set", "सेट केलेले नाही"}, {"default_label", "डीफॉल्ट"},
        {"profile_library", "प्रोफाइल लायब्ररी"}, {"add_profile", "प्रोफाइल जोडा"}, {"profile_name_label", "नाव:"}, {"add_btn", "जोडा"},
        {"optional", "(पर्यायी)"}, {"image_selected", "✓ निवडले"}, {"no_profiles_library", "अद्याप प्रोफाइल नाहीत. जोडण्यासाठी + क्लिक करा."},
        {"profile_owner_conflict", "मालकाच्या नावासह प्रोफाइल जोडू शकत नाही"}, {"profile_exists", "या नावाचे प्रोफाइल आधीच अस्तित्वात आहे"},
        {"message_count_text", "संदेश"},
        {"january", "जाने"}, {"february", "फेब्रु"}, {"march", "मार्च"}, {"april", "एप्रिल"}, {"may", "मे"}, {"june", "जून"},
        {"july", "जुलै"}, {"august", "ऑगस्ट"}, {"september", "सप्टें"}, {"october", "ऑक्टो"}, {"november", "नोव्हें"}, {"december", "डिसें"},
        {"calendar_tooltip", "तारखेवर जा"},
        {"last_message", "शेवटचा संदेश"},
        {"settings", "सेटिंग्ज"},
        {"auto_play_next_voice", "अनुक्रमे व्हॉइस संदेश ऑटो-प्ले करा"},
        {"open_system", "सिस्टममध्ये उघडा"}, {"image_not_found", "इमेज सापडली नाही"}, {"video", "व्हिडिओ"}, {"deleted_message", "हा संदेश हटवला गेला"}, {"you_deleted_message", "तुम्ही हा संदेश हटवला"}, {"edited", "संपादित"}, {"app_version", "आवृत्ती"}, {"app_copyright", "कॉपीराइट %1"},
        {"lock_chat", "चॅट लॉक करा"}, {"unlock_chat", "ही चॅट अनलॉक करा"}, {"locked_chats", "लॉक केलेल्या चॅट"}, {"locked_chats_access", "लॉक केलेल्या चॅटमध्ये प्रवेश"},
        {"lock_chat_title", "चॅट लॉक करा"}, {"lock_chat_message", "ही चॅट लॉक केली जाईल"}, {"lock_chat_set_password", "चॅट लॉक करण्यासाठी पासवर्ड सेट करा"},
        {"locked_chats_password_title", "लॉक केलेल्या चॅट"}, {"locked_chats_enter_password", "लॉक केलेल्या चॅटमध्ये प्रवेश करण्यासाठी पासवर्ड टाका"},
        {"password_6_digits", "पासवर्ड 6 अंकी असावा"}, {"password_incorrect", "चुकीचा पासवर्ड"}, {"no_master_password", "पासवर्ड सेट केलेला नाही"},
        {"locked_chats_password", "लॉक केलेल्या चॅटचा पासवर्ड"}, {"no_password", "तुमच्याकडे पासवर्ड नाही"}, {"change_password", "पासवर्ड बदला"},
        {"old_password", "जुना पासवर्ड"}, {"new_password", "नवीन पासवर्ड"}, {"confirm_password", "नवीन पासवर्ड पुष्टी करा"}, {"change", "बदला"},
        {"old_password_incorrect", "जुना पासवर्ड चुकीचा आहे"}, {"passwords_dont_match", "नवीन पासवर्ड जुळत नाहीत"},
        {"no_locked_chats", "लॉक केलेल्या चॅट नाहीत"}, {"locked_chats_hint", "चॅट लॉक करण्यासाठी 3-डॉट मेनूमधून 'चॅट लॉक करा' निवडा"}, {"enter", "प्रवेश करा"}
    };
    m_translations["Marathi"].insert(QStringLiteral("media_image"), QStringLiteral("फोटो"));
    m_translations["Marathi"].insert(QStringLiteral("media_video"), QStringLiteral("व्हिडिओ"));
    m_translations["Marathi"].insert(QStringLiteral("media_voice"), QStringLiteral("व्हॉइस संदेश"));
    m_translations["Marathi"].insert(QStringLiteral("media_audio"), QStringLiteral("ऑडिओ"));
    m_translations["Marathi"].insert(QStringLiteral("media_sticker"), QStringLiteral("स्टिकर"));
    m_translations["Marathi"].insert(QStringLiteral("media_document"), QStringLiteral("दस्तऐवज"));
    m_translations["Marathi"].insert(QStringLiteral("media_unavailable"), QStringLiteral("मीडिया उपलब्ध नाही"));
    m_translations["Marathi"].insert(QStringLiteral("tap_to_open"), QStringLiteral("उघडण्यासाठी टॅप करा"));
    m_translations["Marathi"].insert(QStringLiteral("location"), QStringLiteral("स्थान"));
    m_translations["Marathi"].insert(QStringLiteral("contact"), QStringLiteral("संपर्क"));
    m_translations["Marathi"].insert(QStringLiteral("favorites"), QStringLiteral("आवडीचे"));
    m_translations["Marathi"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("आवडीच्या मध्ये जोडा"));
    m_translations["Marathi"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("आवडीच्या मधून काढा"));
    m_translations["Marathi"].insert(QStringLiteral("no_favorites"), QStringLiteral("आवडीचे नाहीत"));
    m_translations["Marathi"].insert(QStringLiteral("favorites_hint"), QStringLiteral("आवडीच्या मध्ये जोडण्यासाठी संदेशावर उजवे-क्लिक करा"));
    m_translations["Marathi"].insert(QStringLiteral("media_browser"), QStringLiteral("मीडिया"));
    m_translations["Marathi"].insert(QStringLiteral("media_browser_title"), QStringLiteral("मीडिया"));
    m_translations["Marathi"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("फोटो, व्हिडिओ आणि फायली"));
    m_translations["Marathi"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("फोटो"));
    m_translations["Marathi"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("व्हिडिओ"));
    m_translations["Marathi"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("दस्तऐवज"));
    m_translations["Marathi"].insert(QStringLiteral("media_browser_links"), QStringLiteral("लिंक"));
    m_translations["Marathi"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("स्थाने"));
    m_translations["Marathi"].insert(QStringLiteral("no_photos_found"), QStringLiteral("फोटो सापडले नाहीत"));
    m_translations["Marathi"].insert(QStringLiteral("no_videos_found"), QStringLiteral("व्हिडिओ सापडले नाहीत"));
    m_translations["Marathi"].insert(QStringLiteral("no_documents_found"), QStringLiteral("दस्तऐवज सापडले नाहीत"));
    m_translations["Marathi"].insert(QStringLiteral("no_links_found"), QStringLiteral("लिंक सापडले नाहीत"));
    m_translations["Marathi"].insert(QStringLiteral("no_locations_found"), QStringLiteral("स्थाने सापडली नाहीत"));

    // Norwegian
    m_translations["Norwegian"] = {
        {"contact_info", "Kontaktinfo"}, {"msg_count", "Antall meldinger"}, {"messages", "meldinger"}, {"import_date", "Importdato"},
        {"no_chats", "Ingen chatter funnet\n\nKlikk + for å legge til\nen ny chat"}, {"light_theme", "Lyst tema"}, {"dark_theme", "Mørkt tema"},
        {"new_chat_tooltip", "Legg til ny chat"}, {"chat_search_placeholder", "Søk i chatter"}, {"importing", "Importerer..."},
        {"bulk_select_tooltip", "Masseutvalg"}, {"bulk_delete_tooltip", "Massesletting"}, {"cancel_selection_tooltip", "Avbryt"},
        {"import_new", "Legg til ny chat"}, {"zip_description", "Velg ZIP-filen eksportert fra WhatsApp."},
        {"select_zip", "Velg ZIP-fil"}, {"change_zip", "Endre fil"}, {"continue", "Fortsett"},
        {"owner_question", "Hva er navnet ditt i chatten?\n(Navnet som vises i WhatsApp-kontoen din)"}, {"owner_placeholder", "F.eks: Ola Nordmann"},
        {"import_btn", "Importer"}, {"back", "Tilbake"}, {"loading_messages", "Laster meldinger, vennligst vent..."},
        {"select_zip_title", "Velg WhatsApp ZIP-fil"}, {"first_message", "Første melding"}, {"delete_chat", "Slett chat"}, {"search", "Søk..."}, {"search_tooltip", "Søk i meldinger (Ctrl+F)"},
        {"empty_chat_hint", "Velg en chat eller legg til en ny"}, {"delete_confirm_title", "Slett chat"},
        {"delete_confirm_text", "Er du sikker på at du vil slette denne chatten?\nAlle meldinger vil bli fjernet."}, {"no_results", "Ingen resultater funnet"},
        {"yes", "Ja"}, {"no", "Nei"}, {"cancel", "Avbryt"}, {"language", "Språk"}, {"select_language", "Velg språk"}, {"profile_photo", "Profilbilde"},
        {"name_label", "Navn"}, {"participants_label", "Gruppemedlemmer"}, {"contact_name_placeholder", "Kontaktnavn"}, {"image_files_filter", "Bildefiler (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — %2 meldinger importert"}, {"conversation", "Samtale"},
        {"default_owner_name", "Standard eiernavn"}, {"owner_name_placeholder", "Ditt navn"}, {"not_set", "Ikke satt"}, {"default_label", "Standard"},
        {"profile_library", "Profilbibliotek"}, {"add_profile", "Legg til profil"}, {"profile_name_label", "Navn:"}, {"add_btn", "Legg til"},
        {"optional", "(Valgfritt)"}, {"image_selected", "✓ Valgt"}, {"no_profiles_library", "Ingen profiler ennå. Klikk + for å legge til."},
        {"profile_owner_conflict", "Kan ikke legge til profil med samme navn som eier"}, {"profile_exists", "Profil med dette navnet eksisterer allerede"},
        {"message_count_text", "meldinger"},
        {"january", "Jan"}, {"february", "Feb"}, {"march", "Mar"}, {"april", "Apr"}, {"may", "Mai"}, {"june", "Jun"},
        {"july", "Jul"}, {"august", "Aug"}, {"september", "Sep"}, {"october", "Okt"}, {"november", "Nov"}, {"december", "Des"},
        {"calendar_tooltip", "Gå til dato"},
        {"last_message", "Siste melding"},
        {"settings", "Innstillinger"},
        {"auto_play_next_voice", "Spill av påfølgende talemeldinger automatisk"},
        {"open_system", "Åpne i system"}, {"image_not_found", "Bilde ikke funnet"}, {"video", "Video"}, {"deleted_message", "Denne meldingen ble slettet"}, {"you_deleted_message", "Du slettet denne meldingen"}, {"edited", "Redigert"}, {"app_version", "versjon"}, {"app_copyright", "Opphavsrett av %1"},
        {"lock_chat", "Lås chat"}, {"unlock_chat", "Lås opp denne chatten"}, {"locked_chats", "Låste chatter"}, {"locked_chats_access", "Få tilgang til låste chatter"},
        {"lock_chat_title", "Lås chat"}, {"lock_chat_message", "Denne chatten vil bli låst"}, {"lock_chat_set_password", "Angi passord for å låse chatter"},
        {"locked_chats_password_title", "Låste chatter"}, {"locked_chats_enter_password", "Skriv inn passord for å få tilgang til låste chatter"},
        {"password_6_digits", "Passordet må være 6 siffer"}, {"password_incorrect", "Feil passord"}, {"no_master_password", "Ingen passord angitt"},
        {"locked_chats_password", "Passord for låste chatter"}, {"no_password", "Du har ikke noe passord"}, {"change_password", "Endre passord"},
        {"old_password", "Gammelt passord"}, {"new_password", "Nytt passord"}, {"confirm_password", "Bekreft nytt passord"}, {"change", "Endre"},
        {"old_password_incorrect", "Gammelt passord er feil"}, {"passwords_dont_match", "Nye passord stemmer ikke overens"},
        {"no_locked_chats", "Ingen låste chatter"}, {"locked_chats_hint", "Velg 'Lås chat' fra 3-prikk-menyen for å låse en chat"}, {"enter", "Gå inn"}
    };
    m_translations["Norwegian"].insert(QStringLiteral("media_image"), QStringLiteral("Bilde"));
    m_translations["Norwegian"].insert(QStringLiteral("media_video"), QStringLiteral("Video"));
    m_translations["Norwegian"].insert(QStringLiteral("media_voice"), QStringLiteral("Talemelding"));
    m_translations["Norwegian"].insert(QStringLiteral("media_audio"), QStringLiteral("Lyd"));
    m_translations["Norwegian"].insert(QStringLiteral("media_sticker"), QStringLiteral("Klistremerke"));
    m_translations["Norwegian"].insert(QStringLiteral("media_document"), QStringLiteral("Dokument"));
    m_translations["Norwegian"].insert(QStringLiteral("media_unavailable"), QStringLiteral("Media utilgjengelig"));
    m_translations["Norwegian"].insert(QStringLiteral("tap_to_open"), QStringLiteral("Trykk for å åpne"));
    m_translations["Norwegian"].insert(QStringLiteral("location"), QStringLiteral("Plassering"));
    m_translations["Norwegian"].insert(QStringLiteral("contact"), QStringLiteral("Kontakt"));
    m_translations["Norwegian"].insert(QStringLiteral("favorites"), QStringLiteral("Favoritter"));
    m_translations["Norwegian"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("Legg til favoritter"));
    m_translations["Norwegian"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("Fjern fra favoritter"));
    m_translations["Norwegian"].insert(QStringLiteral("no_favorites"), QStringLiteral("Ingen favoritter"));
    m_translations["Norwegian"].insert(QStringLiteral("favorites_hint"), QStringLiteral("Høyreklikk en melding for å legge til favoritter"));
    m_translations["Norwegian"].insert(QStringLiteral("media_browser"), QStringLiteral("Media"));
    m_translations["Norwegian"].insert(QStringLiteral("media_browser_title"), QStringLiteral("Media"));
    m_translations["Norwegian"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("Bilder, videoer og filer"));
    m_translations["Norwegian"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("Bilder"));
    m_translations["Norwegian"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("Videoer"));
    m_translations["Norwegian"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("Dokumenter"));
    m_translations["Norwegian"].insert(QStringLiteral("media_browser_links"), QStringLiteral("Lenker"));
    m_translations["Norwegian"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("Plasseringer"));
    m_translations["Norwegian"].insert(QStringLiteral("no_photos_found"), QStringLiteral("Ingen bilder funnet"));
    m_translations["Norwegian"].insert(QStringLiteral("no_videos_found"), QStringLiteral("Ingen videoer funnet"));
    m_translations["Norwegian"].insert(QStringLiteral("no_documents_found"), QStringLiteral("Ingen dokumenter funnet"));
    m_translations["Norwegian"].insert(QStringLiteral("no_links_found"), QStringLiteral("Ingen lenker funnet"));
    m_translations["Norwegian"].insert(QStringLiteral("no_locations_found"), QStringLiteral("Ingen plasseringer funnet"));

    // Persian
    m_translations["Persian"] = {
        {"contact_info", "اطلاعات تماس"}, {"msg_count", "تعداد پیام"}, {"messages", "پیام"}, {"import_date", "تاریخ واردات"},
        {"no_chats", "هیچ چتی پیدا نشد\n\nروی + کلیک کنید\nتا چت جدید اضافه کنید"}, {"light_theme", "تم روشن"}, {"dark_theme", "تم تیره"},
        {"new_chat_tooltip", "افزودن چت جدید"}, {"chat_search_placeholder", "جستجو در چت‌ها"}, {"importing", "در حال واردات..."},
        {"bulk_select_tooltip", "انتخاب دسته‌ای"}, {"bulk_delete_tooltip", "حذف دسته‌ای"}, {"cancel_selection_tooltip", "لغو"},
        {"import_new", "افزودن چت جدید"}, {"zip_description", "فایل ZIP صادر شده از واتساپ را انتخاب کنید."},
        {"select_zip", "انتخاب فایل ZIP"}, {"change_zip", "تغییر فایل"}, {"continue", "ادامه"},
        {"owner_question", "نام شما در چت چیست؟\n(نامی که در حساب واتساپ شما نمایش داده می‌شود)"}, {"owner_placeholder", "مثال: علی احمدی"},
        {"import_btn", "واردات"}, {"back", "بازگشت"}, {"loading_messages", "در حال بارگذاری پیام‌ها، لطفاً صبر کنید..."},
        {"select_zip_title", "انتخاب فایل ZIP واتساپ"}, {"first_message", "اولین پیام"}, {"delete_chat", "حذف چت"}, {"search", "جستجو..."}, {"search_tooltip", "جستجو در پیام‌ها (Ctrl+F)"},
        {"empty_chat_hint", "یک چت انتخاب کنید یا چت جدیدی اضافه کنید"}, {"delete_confirm_title", "حذف چت"},
        {"delete_confirm_text", "آیا مطمئن هستید که می‌خواهید این چت را حذف کنید؟\nهمه پیام‌ها حذف خواهند شد."}, {"no_results", "نتیجه‌ای پیدا نشد"},
        {"yes", "بله"}, {"no", "خیر"}, {"cancel", "لغو"}, {"language", "زبان"}, {"select_language", "انتخاب زبان"}, {"profile_photo", "عکس پروفایل"},
        {"name_label", "نام"}, {"participants_label", "اعضای گروه"}, {"contact_name_placeholder", "نام مخاطب"}, {"image_files_filter", "فایل‌های تصویر (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — %2 پیام وارد شد"}, {"conversation", "مکالمه"},
        {"default_owner_name", "نام مالک پیش‌فرض"}, {"owner_name_placeholder", "نام شما"}, {"not_set", "تنظیم نشده"}, {"default_label", "پیش‌فرض"},
        {"profile_library", "کتابخانه پروفایل"}, {"add_profile", "افزودن پروفایل"}, {"profile_name_label", "نام:"}, {"add_btn", "افزودن"},
        {"optional", "(اختیاری)"}, {"image_selected", "✓ انتخاب شد"}, {"no_profiles_library", "هنوز پروفایلی وجود ندارد. برای افزودن روی + کلیک کنید."},
        {"profile_owner_conflict", "نمی‌توان پروفایلی با نام مالک اضافه کرد"}, {"profile_exists", "پروفایل با این نام قبلاً وجود دارد"},
        {"message_count_text", "پیام"},
        {"january", "ژانویه"}, {"february", "فوریه"}, {"march", "مارس"}, {"april", "آوریل"}, {"may", "مه"}, {"june", "ژوئن"},
        {"july", "ژوئیه"}, {"august", "اوت"}, {"september", "سپتامبر"}, {"october", "اکتبر"}, {"november", "نوامبر"}, {"december", "دسامبر"},
        {"calendar_tooltip", "رفتن به تاریخ"},
        {"last_message", "آخرین پیام"},
        {"settings", "تنظیمات"},
        {"auto_play_next_voice", "پخش خودکار پیام‌های صوتی پی‌درپی"},
        {"open_system", "باز کردن در سیستم"}, {"image_not_found", "تصویر پیدا نشد"}, {"video", "ویدیو"}, {"deleted_message", "این پیام حذف شد"}, {"you_deleted_message", "شما این پیام را حذف کردید"}, {"edited", "ویرایش شده"}, {"app_version", "نسخه"}, {"app_copyright", "حق نسخه‌برداری توسط %1"},
        {"lock_chat", "قفل کردن چت"}, {"unlock_chat", "بازکردن قفل این چت"}, {"locked_chats", "چت‌های قفل شده"}, {"locked_chats_access", "دسترسی به چت‌های قفل شده"},
        {"lock_chat_title", "قفل کردن چت"}, {"lock_chat_message", "این چت قفل خواهد شد"}, {"lock_chat_set_password", "برای قفل کردن چت‌ها رمز عبور تنظیم کنید"},
        {"locked_chats_password_title", "چت‌های قفل شده"}, {"locked_chats_enter_password", "برای دسترسی به چت‌های قفل شده رمز عبور وارد کنید"},
        {"password_6_digits", "رمز عبور باید ۶ رقمی باشد"}, {"password_incorrect", "رمز عبور اشتباه است"}, {"no_master_password", "رمز عبوری تنظیم نشده"},
        {"locked_chats_password", "رمز عبور چت‌های قفل شده"}, {"no_password", "شما رمز عبوری ندارید"}, {"change_password", "تغییر رمز عبور"},
        {"old_password", "رمز عبور قدیم"}, {"new_password", "رمز عبور جدید"}, {"confirm_password", "تأیید رمز عبور جدید"}, {"change", "تغییر"},
        {"old_password_incorrect", "رمز عبور قدیم اشتباه است"}, {"passwords_dont_match", "رمزهای عبور جدید مطابقت ندارند"},
        {"no_locked_chats", "چت قفل شده‌ای وجود ندارد"}, {"locked_chats_hint", "برای قفل کردن چت، از منوی ۳ نقطه 'قفل کردن چت' را انتخاب کنید"}, {"enter", "ورود"}
    };
    m_translations["Persian"].insert(QStringLiteral("media_image"), QStringLiteral("عکس"));
    m_translations["Persian"].insert(QStringLiteral("media_video"), QStringLiteral("ویدیو"));
    m_translations["Persian"].insert(QStringLiteral("media_voice"), QStringLiteral("پیام صوتی"));
    m_translations["Persian"].insert(QStringLiteral("media_audio"), QStringLiteral("صدا"));
    m_translations["Persian"].insert(QStringLiteral("media_sticker"), QStringLiteral("برچسب"));
    m_translations["Persian"].insert(QStringLiteral("media_document"), QStringLiteral("سند"));
    m_translations["Persian"].insert(QStringLiteral("media_unavailable"), QStringLiteral("رسانه در دسترس نیست"));
    m_translations["Persian"].insert(QStringLiteral("tap_to_open"), QStringLiteral("برای باز کردن ضربه بزنید"));
    m_translations["Persian"].insert(QStringLiteral("location"), QStringLiteral("موقعیت مکانی"));
    m_translations["Persian"].insert(QStringLiteral("contact"), QStringLiteral("مخاطب"));
    m_translations["Persian"].insert(QStringLiteral("favorites"), QStringLiteral("علاقه‌مندی‌ها"));
    m_translations["Persian"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("افزودن به علاقه‌مندی‌ها"));
    m_translations["Persian"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("حذف از علاقه‌مندی‌ها"));
    m_translations["Persian"].insert(QStringLiteral("no_favorites"), QStringLiteral("علاقه‌مندی وجود ندارد"));
    m_translations["Persian"].insert(QStringLiteral("favorites_hint"), QStringLiteral("برای افزودن به علاقه‌مندی‌ها روی پیام راست‌کلیک کنید"));
    m_translations["Persian"].insert(QStringLiteral("media_browser"), QStringLiteral("رسانه"));
    m_translations["Persian"].insert(QStringLiteral("media_browser_title"), QStringLiteral("رسانه"));
    m_translations["Persian"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("عکس‌ها، ویدیوها و فایل‌ها"));
    m_translations["Persian"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("عکس‌ها"));
    m_translations["Persian"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("ویدیوها"));
    m_translations["Persian"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("اسناد"));
    m_translations["Persian"].insert(QStringLiteral("media_browser_links"), QStringLiteral("لینک‌ها"));
    m_translations["Persian"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("موقعیت‌ها"));
    m_translations["Persian"].insert(QStringLiteral("no_photos_found"), QStringLiteral("عکسی پیدا نشد"));
    m_translations["Persian"].insert(QStringLiteral("no_videos_found"), QStringLiteral("ویدیویی پیدا نشد"));
    m_translations["Persian"].insert(QStringLiteral("no_documents_found"), QStringLiteral("سندی پیدا نشد"));
    m_translations["Persian"].insert(QStringLiteral("no_links_found"), QStringLiteral("لینکی پیدا نشد"));
    m_translations["Persian"].insert(QStringLiteral("no_locations_found"), QStringLiteral("موقعیتی پیدا نشد"));

    // PortugueseBrazil
    m_translations["PortugueseBrazil"] = {
        {"contact_info", "Informações do contato"}, {"msg_count", "Número de mensagens"}, {"messages", "mensagens"}, {"import_date", "Data de importação"},
        {"no_chats", "Nenhum chat encontrado\n\nClique em + para adicionar\num novo chat"}, {"light_theme", "Tema claro"}, {"dark_theme", "Tema escuro"},
        {"new_chat_tooltip", "Adicionar novo chat"}, {"chat_search_placeholder", "Pesquisar nos chats"}, {"importing", "Importando..."},
        {"bulk_select_tooltip", "Seleção em massa"}, {"bulk_delete_tooltip", "Exclusão em massa"}, {"cancel_selection_tooltip", "Cancelar"},
        {"import_new", "Adicionar novo chat"}, {"zip_description", "Selecione o arquivo ZIP exportado do WhatsApp."},
        {"select_zip", "Selecionar arquivo ZIP"}, {"change_zip", "Alterar arquivo"}, {"continue", "Continuar"},
        {"owner_question", "Qual é o seu nome no chat?\n(O nome exibido na sua conta do WhatsApp)"}, {"owner_placeholder", "Ex: João Silva"},
        {"import_btn", "Importar"}, {"back", "Voltar"}, {"loading_messages", "Carregando mensagens, aguarde..."},
        {"select_zip_title", "Selecionar arquivo ZIP do WhatsApp"}, {"first_message", "Primeira mensagem"}, {"delete_chat", "Excluir chat"}, {"search", "Pesquisar..."}, {"search_tooltip", "Pesquisar nas mensagens (Ctrl+F)"},
        {"empty_chat_hint", "Selecione um chat ou adicione um novo"}, {"delete_confirm_title", "Excluir chat"},
        {"delete_confirm_text", "Tem certeza de que deseja excluir este chat?\nTodas as mensagens serão removidas."}, {"no_results", "Nenhum resultado encontrado"},
        {"yes", "Sim"}, {"no", "Não"}, {"cancel", "Cancelar"}, {"language", "Idioma"}, {"select_language", "Selecionar idioma"}, {"profile_photo", "Foto do perfil"},
        {"name_label", "Nome"}, {"participants_label", "Participantes do grupo"}, {"contact_name_placeholder", "Nome do contato"}, {"image_files_filter", "Arquivos de imagem (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — %2 mensagens importadas"}, {"conversation", "Conversa"},
        {"default_owner_name", "Nome do proprietário padrão"}, {"owner_name_placeholder", "Seu nome"}, {"not_set", "Não definido"}, {"default_label", "Padrão"},
        {"profile_library", "Biblioteca de perfis"}, {"add_profile", "Adicionar perfil"}, {"profile_name_label", "Nome:"}, {"add_btn", "Adicionar"},
        {"optional", "(Opcional)"}, {"image_selected", "✓ Selecionado"}, {"no_profiles_library", "Ainda não há perfis. Clique em + para adicionar."},
        {"profile_owner_conflict", "Não é possível adicionar perfil com o mesmo nome do proprietário"}, {"profile_exists", "Já existe um perfil com este nome"},
        {"message_count_text", "mensagens"},
        {"january", "Jan"}, {"february", "Fev"}, {"march", "Mar"}, {"april", "Abr"}, {"may", "Mai"}, {"june", "Jun"},
        {"july", "Jul"}, {"august", "Ago"}, {"september", "Set"}, {"october", "Out"}, {"november", "Nov"}, {"december", "Dez"},
        {"calendar_tooltip", "Ir para a data"},
        {"last_message", "Última mensagem"},
        {"settings", "Configurações"},
        {"auto_play_next_voice", "Reproduzir automaticamente mensagens de voz sequenciais"},
        {"open_system", "Abrir no sistema"}, {"image_not_found", "Imagem não encontrada"}, {"video", "Vídeo"}, {"deleted_message", "Esta mensagem foi excluída"}, {"you_deleted_message", "Você excluiu esta mensagem"}, {"edited", "Editada"}, {"app_version", "versão"}, {"app_copyright", "Copyright por %1"},
        {"lock_chat", "Bloquear chat"}, {"unlock_chat", "Desbloquear este chat"}, {"locked_chats", "Chats bloqueados"}, {"locked_chats_access", "Acessar chats bloqueados"},
        {"lock_chat_title", "Bloquear chat"}, {"lock_chat_message", "Este chat será bloqueado"}, {"lock_chat_set_password", "Defina uma senha para bloquear chats"},
        {"locked_chats_password_title", "Chats bloqueados"}, {"locked_chats_enter_password", "Digite a senha para acessar chats bloqueados"},
        {"password_6_digits", "A senha deve ter 6 dígitos"}, {"password_incorrect", "Senha incorreta"}, {"no_master_password", "Nenhuma senha definida"},
        {"locked_chats_password", "Senha dos chats bloqueados"}, {"no_password", "Você não tem uma senha"}, {"change_password", "Alterar senha"},
        {"old_password", "Senha antiga"}, {"new_password", "Nova senha"}, {"confirm_password", "Confirmar nova senha"}, {"change", "Alterar"},
        {"old_password_incorrect", "A senha antiga está incorreta"}, {"passwords_dont_match", "As novas senhas não coincidem"},
        {"no_locked_chats", "Nenhum chat bloqueado"}, {"locked_chats_hint", "Selecione 'Bloquear chat' no menu de 3 pontos para bloquear um chat"}, {"enter", "Entrar"}
    };
    m_translations["PortugueseBrazil"].insert(QStringLiteral("media_image"), QStringLiteral("Foto"));
    m_translations["PortugueseBrazil"].insert(QStringLiteral("media_video"), QStringLiteral("Vídeo"));
    m_translations["PortugueseBrazil"].insert(QStringLiteral("media_voice"), QStringLiteral("Mensagem de voz"));
    m_translations["PortugueseBrazil"].insert(QStringLiteral("media_audio"), QStringLiteral("Áudio"));
    m_translations["PortugueseBrazil"].insert(QStringLiteral("media_sticker"), QStringLiteral("Figurinha"));
    m_translations["PortugueseBrazil"].insert(QStringLiteral("media_document"), QStringLiteral("Documento"));
    m_translations["PortugueseBrazil"].insert(QStringLiteral("media_unavailable"), QStringLiteral("Mídia indisponível"));
    m_translations["PortugueseBrazil"].insert(QStringLiteral("tap_to_open"), QStringLiteral("Toque para abrir"));
    m_translations["PortugueseBrazil"].insert(QStringLiteral("location"), QStringLiteral("Localização"));
    m_translations["PortugueseBrazil"].insert(QStringLiteral("contact"), QStringLiteral("Contato"));
    m_translations["PortugueseBrazil"].insert(QStringLiteral("favorites"), QStringLiteral("Favoritos"));
    m_translations["PortugueseBrazil"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("Adicionar aos favoritos"));
    m_translations["PortugueseBrazil"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("Remover dos favoritos"));
    m_translations["PortugueseBrazil"].insert(QStringLiteral("no_favorites"), QStringLiteral("Nenhum favorito"));
    m_translations["PortugueseBrazil"].insert(QStringLiteral("favorites_hint"), QStringLiteral("Clique com o botão direito em uma mensagem para adicionar aos favoritos"));
    m_translations["PortugueseBrazil"].insert(QStringLiteral("media_browser"), QStringLiteral("Mídia"));
    m_translations["PortugueseBrazil"].insert(QStringLiteral("media_browser_title"), QStringLiteral("Mídia"));
    m_translations["PortugueseBrazil"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("Fotos, vídeos e arquivos"));
    m_translations["PortugueseBrazil"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("Fotos"));
    m_translations["PortugueseBrazil"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("Vídeos"));
    m_translations["PortugueseBrazil"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("Documentos"));
    m_translations["PortugueseBrazil"].insert(QStringLiteral("media_browser_links"), QStringLiteral("Links"));
    m_translations["PortugueseBrazil"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("Localizações"));
    m_translations["PortugueseBrazil"].insert(QStringLiteral("no_photos_found"), QStringLiteral("Nenhuma foto encontrada"));
    m_translations["PortugueseBrazil"].insert(QStringLiteral("no_videos_found"), QStringLiteral("Nenhum vídeo encontrado"));
    m_translations["PortugueseBrazil"].insert(QStringLiteral("no_documents_found"), QStringLiteral("Nenhum documento encontrado"));
    m_translations["PortugueseBrazil"].insert(QStringLiteral("no_links_found"), QStringLiteral("Nenhum link encontrado"));
    m_translations["PortugueseBrazil"].insert(QStringLiteral("no_locations_found"), QStringLiteral("Nenhuma localização encontrada"));

    // Punjabi
    m_translations["Punjabi"] = {
        {"contact_info", "ਸੰਪਰਕ ਜਾਣਕਾਰੀ"}, {"msg_count", "ਸੁਨੇਹੇ ਗਿਣਤੀ"}, {"messages", "ਸੁਨੇਹੇ"}, {"import_date", "ਇੰਪੋਰਟ ਤਾਰੀਖ"},
        {"no_chats", "ਕੋਈ ਚੈਟ ਨਹੀਂ ਮਿਲੀ\n\nਨਵੀਂ ਚੈਟ ਜੋੜਨ ਲਈ\n+ 'ਤੇ ਕਲਿੱਕ ਕਰੋ"}, {"light_theme", "ਹਲਕੀ ਥੀਮ"}, {"dark_theme", "ਗੂੜ੍ਹੀ ਥੀਮ"},
        {"new_chat_tooltip", "ਨਵੀਂ ਚੈਟ ਜੋੜੋ"}, {"chat_search_placeholder", "ਚੈਟਾਂ ਵਿੱਚ ਖੋਜੋ"}, {"importing", "ਇੰਪੋਰਟ ਕੀਤਾ ਜਾ ਰਿਹਾ ਹੈ..."},
        {"bulk_select_tooltip", "ਬਲਕ ਚੋਣ"}, {"bulk_delete_tooltip", "ਬਲਕ ਮਿਟਾਓ"}, {"cancel_selection_tooltip", "ਰੱਦ ਕਰੋ"},
        {"import_new", "ਨਵੀਂ ਚੈਟ ਜੋੜੋ"}, {"zip_description", "WhatsApp ਤੋਂ ਐਕਸਪੋਰਟ ਕੀਤੀ ZIP ਫਾਈਲ ਚੁਣੋ।"},
        {"select_zip", "ZIP ਫਾਈਲ ਚੁਣੋ"}, {"change_zip", "ਫਾਈਲ ਬਦਲੋ"}, {"continue", "ਜਾਰੀ ਰੱਖੋ"},
        {"owner_question", "ਚੈਟ ਵਿੱਚ ਤੁਹਾਡਾ ਨਾਮ ਕੀ ਹੈ?\n(ਤੁਹਾਡੇ WhatsApp ਖਾਤੇ ਵਿੱਚ ਦਿਖਾਈ ਦੇਣ ਵਾਲਾ ਨਾਮ)"}, {"owner_placeholder", "ਉਦਾ: ਗੁਰਪ੍ਰੀਤ ਸਿੰਘ"},
        {"import_btn", "ਇੰਪੋਰਟ ਕਰੋ"}, {"back", "ਪਿੱਛੇ"}, {"loading_messages", "ਸੁਨੇਹੇ ਲੋਡ ਹੋ ਰਹੇ ਹਨ, ਕਿਰਪਾ ਕਰਕੇ ਉਡੀਕ ਕਰੋ..."},
        {"select_zip_title", "WhatsApp ZIP ਫਾਈਲ ਚੁਣੋ"}, {"first_message", "ਪਹਿਲਾ ਸੁਨੇਹਾ"}, {"delete_chat", "ਚੈਟ ਮਿਟਾਓ"}, {"search", "ਖੋਜੋ..."}, {"search_tooltip", "ਸੁਨੇਹਿਆਂ ਵਿੱਚ ਖੋਜੋ (Ctrl+F)"},
        {"empty_chat_hint", "ਇੱਕ ਚੈਟ ਚੁਣੋ ਜਾਂ ਨਵੀਂ ਜੋੜੋ"}, {"delete_confirm_title", "ਚੈਟ ਮਿਟਾਓ"},
        {"delete_confirm_text", "ਕੀ ਤੁਸੀਂ ਯਕੀਨੀ ਤੌਰ 'ਤੇ ਇਹ ਚੈਟ ਮਿਟਾਉਣਾ ਚਾਹੁੰਦੇ ਹੋ?\nਸਾਰੇ ਸੁਨੇਹੇ ਹਟਾ ਦਿੱਤੇ ਜਾਣਗੇ।"}, {"no_results", "ਕੋਈ ਨਤੀਜੇ ਨਹੀਂ ਮਿਲੇ"},
        {"yes", "ਹਾਂ"}, {"no", "ਨਹੀਂ"}, {"cancel", "ਰੱਦ ਕਰੋ"}, {"language", "ਭਾਸ਼ਾ"}, {"select_language", "ਭਾਸ਼ਾ ਚੁਣੋ"}, {"profile_photo", "ਪ੍ਰੋਫਾਈਲ ਫੋਟੋ"},
        {"name_label", "ਨਾਮ"}, {"participants_label", "ਗਰੁੱਪ ਮੈਂਬਰ"}, {"contact_name_placeholder", "ਸੰਪਰਕ ਨਾਮ"}, {"image_files_filter", "ਚਿੱਤਰ ਫਾਈਲਾਂ (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — %2 ਸੁਨੇਹੇ ਇੰਪੋਰਟ ਕੀਤੇ"}, {"conversation", "ਗੱਲਬਾਤ"},
        {"default_owner_name", "ਡਿਫੌਲਟ ਮਾਲਕ ਨਾਮ"}, {"owner_name_placeholder", "ਤੁਹਾਡਾ ਨਾਮ"}, {"not_set", "ਸੈੱਟ ਨਹੀਂ"}, {"default_label", "ਡਿਫੌਲਟ"},
        {"profile_library", "ਪ੍ਰੋਫਾਈਲ ਲਾਇਬ੍ਰੇਰੀ"}, {"add_profile", "ਪ੍ਰੋਫਾਈਲ ਜੋੜੋ"}, {"profile_name_label", "ਨਾਮ:"}, {"add_btn", "ਜੋੜੋ"},
        {"optional", "(ਵਿਕਲਪਿਕ)"}, {"image_selected", "✓ ਚੁਣਿਆ"}, {"no_profiles_library", "ਅਜੇ ਕੋਈ ਪ੍ਰੋਫਾਈਲ ਨਹੀਂ। ਜੋੜਨ ਲਈ + 'ਤੇ ਕਲਿੱਕ ਕਰੋ।"},
        {"profile_owner_conflict", "ਮਾਲਕ ਦੇ ਨਾਮ ਵਾਲਾ ਪ੍ਰੋਫਾਈਲ ਨਹੀਂ ਜੋੜ ਸਕਦੇ"}, {"profile_exists", "ਇਸ ਨਾਮ ਵਾਲਾ ਪ੍ਰੋਫਾਈਲ ਪਹਿਲਾਂ ਹੀ ਮੌਜੂਦ ਹੈ"},
        {"message_count_text", "ਸੁਨੇਹੇ"},
        {"january", "ਜਨਵਰੀ"}, {"february", "ਫਰਵਰੀ"}, {"march", "ਮਾਰਚ"}, {"april", "ਅਪ੍ਰੈਲ"}, {"may", "ਮਈ"}, {"june", "ਜੂਨ"},
        {"july", "ਜੁਲਾਈ"}, {"august", "ਅਗਸਤ"}, {"september", "ਸਤੰਬਰ"}, {"october", "ਅਕਤੂਬਰ"}, {"november", "ਨਵੰਬਰ"}, {"december", "ਦਸੰਬਰ"},
        {"calendar_tooltip", "ਤਾਰੀਖ 'ਤੇ ਜਾਓ"},
        {"last_message", "ਆਖਰੀ ਸੁਨੇਹਾ"},
        {"settings", "ਸੈਟਿੰਗਾਂ"},
        {"auto_play_next_voice", "ਲੜੀਵਾਰ ਵੌਇਸ ਸੁਨੇਹੇ ਆਪਣੇ-ਆਪ ਚਲਾਓ"},
        {"open_system", "ਸਿਸਟਮ ਵਿੱਚ ਖੋਲ੍ਹੋ"}, {"image_not_found", "ਚਿੱਤਰ ਨਹੀਂ ਮਿਲਿਆ"}, {"video", "ਵੀਡੀਓ"}, {"deleted_message", "ਇਹ ਸੁਨੇਹਾ ਮਿਟਾਇਆ ਗਿਆ"}, {"you_deleted_message", "ਤੁਸੀਂ ਇਹ ਸੁਨੇਹਾ ਮਿਟਾਇਆ"}, {"edited", "ਸੰਪਾਦਿਤ"}, {"app_version", "ਵਰਜ਼ਨ"}, {"app_copyright", "ਕਾਪੀਰਾਈਟ %1 ਵੱਲੋਂ"},
        {"lock_chat", "ਚੈਟ ਲਾਕ ਕਰੋ"}, {"unlock_chat", "ਇਸ ਚੈਟ ਨੂੰ ਅਨਲਾਕ ਕਰੋ"}, {"locked_chats", "ਲਾਕ ਕੀਤੀਆਂ ਚੈਟਾਂ"}, {"locked_chats_access", "ਲਾਕ ਕੀਤੀਆਂ ਚੈਟਾਂ ਦੀ ਪਹੁੰਚ"},
        {"lock_chat_title", "ਚੈਟ ਲਾਕ ਕਰੋ"}, {"lock_chat_message", "ਇਹ ਚੈਟ ਲਾਕ ਹੋ ਜਾਵੇਗੀ"}, {"lock_chat_set_password", "ਚੈਟਾਂ ਨੂੰ ਲਾਕ ਕਰਨ ਲਈ ਪਾਸਵਰਡ ਸੈੱਟ ਕਰੋ"},
        {"locked_chats_password_title", "ਲਾਕ ਕੀਤੀਆਂ ਚੈਟਾਂ"}, {"locked_chats_enter_password", "ਲਾਕ ਕੀਤੀਆਂ ਚੈਟਾਂ ਤੱਕ ਪਹੁੰਚਣ ਲਈ ਪਾਸਵਰਡ ਦਾਖਲ ਕਰੋ"},
        {"password_6_digits", "ਪਾਸਵਰਡ 6 ਅੰਕਾਂ ਦਾ ਹੋਣਾ ਚਾਹੀਦਾ ਹੈ"}, {"password_incorrect", "ਗਲਤ ਪਾਸਵਰਡ"}, {"no_master_password", "ਕੋਈ ਪਾਸਵਰਡ ਸੈੱਟ ਨਹੀਂ"},
        {"locked_chats_password", "ਲਾਕ ਕੀਤੀਆਂ ਚੈਟਾਂ ਦਾ ਪਾਸਵਰਡ"}, {"no_password", "ਤੁਹਾਡੇ ਕੋਲ ਪਾਸਵਰਡ ਨਹੀਂ ਹੈ"}, {"change_password", "ਪਾਸਵਰਡ ਬਦਲੋ"},
        {"old_password", "ਪੁਰਾਣਾ ਪਾਸਵਰਡ"}, {"new_password", "ਨਵਾਂ ਪਾਸਵਰਡ"}, {"confirm_password", "ਨਵੇਂ ਪਾਸਵਰਡ ਦੀ ਪੁਸ਼ਟੀ ਕਰੋ"}, {"change", "ਬਦਲੋ"},
        {"old_password_incorrect", "ਪੁਰਾਣਾ ਪਾਸਵਰਡ ਗਲਤ ਹੈ"}, {"passwords_dont_match", "ਨਵੇਂ ਪਾਸਵਰਡ ਮੇਲ ਨਹੀਂ ਖਾਂਦੇ"},
        {"no_locked_chats", "ਕੋਈ ਲਾਕ ਕੀਤੀਆਂ ਚੈਟਾਂ ਨਹੀਂ"}, {"locked_chats_hint", "ਚੈਟ ਨੂੰ ਲਾਕ ਕਰਨ ਲਈ 3-ਬਿੰਦੂ ਮੀਨੂ ਤੋਂ 'ਚੈਟ ਲਾਕ ਕਰੋ' ਚੁਣੋ"}, {"enter", "ਦਾਖਲ ਹੋਵੋ"}
    };
    m_translations["Punjabi"].insert(QStringLiteral("media_image"), QStringLiteral("ਫੋਟੋ"));
    m_translations["Punjabi"].insert(QStringLiteral("media_video"), QStringLiteral("ਵੀਡੀਓ"));
    m_translations["Punjabi"].insert(QStringLiteral("media_voice"), QStringLiteral("ਵੌਇਸ ਸੁਨੇਹਾ"));
    m_translations["Punjabi"].insert(QStringLiteral("media_audio"), QStringLiteral("ਆਡੀਓ"));
    m_translations["Punjabi"].insert(QStringLiteral("media_sticker"), QStringLiteral("ਸਟਿੱਕਰ"));
    m_translations["Punjabi"].insert(QStringLiteral("media_document"), QStringLiteral("ਦਸਤਾਵੇਜ਼"));
    m_translations["Punjabi"].insert(QStringLiteral("media_unavailable"), QStringLiteral("ਮੀਡੀਆ ਉਪਲਬਧ ਨਹੀਂ"));
    m_translations["Punjabi"].insert(QStringLiteral("tap_to_open"), QStringLiteral("ਖੋਲ੍ਹਣ ਲਈ ਟੈਪ ਕਰੋ"));
    m_translations["Punjabi"].insert(QStringLiteral("location"), QStringLiteral("ਟਿਕਾਣਾ"));
    m_translations["Punjabi"].insert(QStringLiteral("contact"), QStringLiteral("ਸੰਪਰਕ"));
    m_translations["Punjabi"].insert(QStringLiteral("favorites"), QStringLiteral("ਮਨਪਸੰਦ"));
    m_translations["Punjabi"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("ਮਨਪਸੰਦ ਵਿੱਚ ਜੋੜੋ"));
    m_translations["Punjabi"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("ਮਨਪਸੰਦ ਤੋਂ ਹਟਾਓ"));
    m_translations["Punjabi"].insert(QStringLiteral("no_favorites"), QStringLiteral("ਕੋਈ ਮਨਪਸੰਦ ਨਹੀਂ"));
    m_translations["Punjabi"].insert(QStringLiteral("favorites_hint"), QStringLiteral("ਮਨਪਸੰਦ ਵਿੱਚ ਜੋੜਨ ਲਈ ਸੁਨੇਹੇ 'ਤੇ ਸੱਜਾ-ਕਲਿੱਕ ਕਰੋ"));
    m_translations["Punjabi"].insert(QStringLiteral("media_browser"), QStringLiteral("ਮੀਡੀਆ"));
    m_translations["Punjabi"].insert(QStringLiteral("media_browser_title"), QStringLiteral("ਮੀਡੀਆ"));
    m_translations["Punjabi"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("ਫੋਟੋਆਂ, ਵੀਡੀਓ ਅਤੇ ਫਾਈਲਾਂ"));
    m_translations["Punjabi"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("ਫੋਟੋਆਂ"));
    m_translations["Punjabi"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("ਵੀਡੀਓ"));
    m_translations["Punjabi"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("ਦਸਤਾਵੇਜ਼"));
    m_translations["Punjabi"].insert(QStringLiteral("media_browser_links"), QStringLiteral("ਲਿੰਕ"));
    m_translations["Punjabi"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("ਟਿਕਾਣੇ"));
    m_translations["Punjabi"].insert(QStringLiteral("no_photos_found"), QStringLiteral("ਕੋਈ ਫੋਟੋ ਨਹੀਂ ਮਿਲੀ"));
    m_translations["Punjabi"].insert(QStringLiteral("no_videos_found"), QStringLiteral("ਕੋਈ ਵੀਡੀਓ ਨਹੀਂ ਮਿਲੀ"));
    m_translations["Punjabi"].insert(QStringLiteral("no_documents_found"), QStringLiteral("ਕੋਈ ਦਸਤਾਵੇਜ਼ ਨਹੀਂ ਮਿਲੇ"));
    m_translations["Punjabi"].insert(QStringLiteral("no_links_found"), QStringLiteral("ਕੋਈ ਲਿੰਕ ਨਹੀਂ ਮਿਲੇ"));
    m_translations["Punjabi"].insert(QStringLiteral("no_locations_found"), QStringLiteral("ਕੋਈ ਟਿਕਾਣੇ ਨਹੀਂ ਮਿਲੇ"));

    // Romanian
    m_translations["Romanian"] = {
        {"contact_info", "Informații contact"}, {"msg_count", "Număr mesaje"}, {"messages", "mesaje"}, {"import_date", "Data importului"},
        {"no_chats", "Nu s-au găsit conversații\n\nApasă + pentru a adăuga\no conversație nouă"}, {"light_theme", "Temă luminoasă"}, {"dark_theme", "Temă întunecată"},
        {"new_chat_tooltip", "Adaugă conversație nouă"}, {"chat_search_placeholder", "Caută în conversații"}, {"importing", "Se importă..."},
        {"bulk_select_tooltip", "Selecție în masă"}, {"bulk_delete_tooltip", "Ștergere în masă"}, {"cancel_selection_tooltip", "Anulează"},
        {"import_new", "Adaugă conversație nouă"}, {"zip_description", "Selectează fișierul ZIP exportat din WhatsApp."},
        {"select_zip", "Selectează fișier ZIP"}, {"change_zip", "Schimbă fișierul"}, {"continue", "Continuă"},
        {"owner_question", "Care este numele tău în chat?\n(Numele afișat în contul tău WhatsApp)"}, {"owner_placeholder", "Ex: Ion Popescu"},
        {"import_btn", "Importă"}, {"back", "Înapoi"}, {"loading_messages", "Se încarcă mesajele, te rog așteaptă..."},
        {"select_zip_title", "Selectează fișierul ZIP WhatsApp"}, {"first_message", "Primul mesaj"}, {"delete_chat", "Șterge conversația"}, {"search", "Caută..."}, {"search_tooltip", "Caută în mesaje (Ctrl+F)"},
        {"empty_chat_hint", "Selectează o conversație sau adaugă una nouă"}, {"delete_confirm_title", "Șterge conversația"},
        {"delete_confirm_text", "Sigur vrei să ștergi această conversație?\nToate mesajele vor fi eliminate."}, {"no_results", "Nu s-au găsit rezultate"},
        {"yes", "Da"}, {"no", "Nu"}, {"cancel", "Anulează"}, {"language", "Limbă"}, {"select_language", "Selectează limba"}, {"profile_photo", "Fotografie profil"},
        {"name_label", "Nume"}, {"participants_label", "Participanți grup"}, {"contact_name_placeholder", "Nume contact"}, {"image_files_filter", "Fișiere imagine (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — %2 mesaje importate"}, {"conversation", "Conversație"},
        {"default_owner_name", "Nume proprietar implicit"}, {"owner_name_placeholder", "Numele tău"}, {"not_set", "Nesetat"}, {"default_label", "Implicit"},
        {"profile_library", "Bibliotecă profiluri"}, {"add_profile", "Adaugă profil"}, {"profile_name_label", "Nume:"}, {"add_btn", "Adaugă"},
        {"optional", "(Opțional)"}, {"image_selected", "✓ Selectat"}, {"no_profiles_library", "Încă nu există profiluri. Apasă + pentru a adăuga."},
        {"profile_owner_conflict", "Nu se poate adăuga profil cu același nume ca proprietarul"}, {"profile_exists", "Există deja un profil cu acest nume"},
        {"message_count_text", "mesaje"},
        {"january", "Ian"}, {"february", "Feb"}, {"march", "Mar"}, {"april", "Apr"}, {"may", "Mai"}, {"june", "Iun"},
        {"july", "Iul"}, {"august", "Aug"}, {"september", "Sep"}, {"october", "Oct"}, {"november", "Noi"}, {"december", "Dec"},
        {"calendar_tooltip", "Mergi la dată"},
        {"last_message", "Ultimul mesaj"},
        {"settings", "Setări"},
        {"auto_play_next_voice", "Redare automată mesaje vocale secvențiale"},
        {"open_system", "Deschide în sistem"}, {"image_not_found", "Imagine negăsită"}, {"video", "Video"}, {"deleted_message", "Acest mesaj a fost șters"}, {"you_deleted_message", "Ai șters acest mesaj"}, {"edited", "Editat"}, {"app_version", "versiunea"}, {"app_copyright", "Copyright de %1"},
        {"lock_chat", "Blochează conversația"}, {"unlock_chat", "Deblochează această conversație"}, {"locked_chats", "Conversații blocate"}, {"locked_chats_access", "Accesează conversații blocate"},
        {"lock_chat_title", "Blochează conversația"}, {"lock_chat_message", "Această conversație va fi blocată"}, {"lock_chat_set_password", "Setează o parolă pentru a bloca conversațiile"},
        {"locked_chats_password_title", "Conversații blocate"}, {"locked_chats_enter_password", "Introdu parola pentru a accesa conversațiile blocate"},
        {"password_6_digits", "Parola trebuie să aibă 6 cifre"}, {"password_incorrect", "Parolă incorectă"}, {"no_master_password", "Nicio parolă setată"},
        {"locked_chats_password", "Parolă conversații blocate"}, {"no_password", "Nu ai o parolă"}, {"change_password", "Schimbă parola"},
        {"old_password", "Parola veche"}, {"new_password", "Parolă nouă"}, {"confirm_password", "Confirmă parola nouă"}, {"change", "Schimbă"},
        {"old_password_incorrect", "Parola veche este incorectă"}, {"passwords_dont_match", "Parolele noi nu se potrivesc"},
        {"no_locked_chats", "Nicio conversație blocată"}, {"locked_chats_hint", "Selectează 'Blochează conversația' din meniul cu 3 puncte pentru a bloca o conversație"}, {"enter", "Intră"}
    };
    m_translations["Romanian"].insert(QStringLiteral("media_image"), QStringLiteral("Fotografie"));
    m_translations["Romanian"].insert(QStringLiteral("media_video"), QStringLiteral("Video"));
    m_translations["Romanian"].insert(QStringLiteral("media_voice"), QStringLiteral("Mesaj vocal"));
    m_translations["Romanian"].insert(QStringLiteral("media_audio"), QStringLiteral("Audio"));
    m_translations["Romanian"].insert(QStringLiteral("media_sticker"), QStringLiteral("Sticker"));
    m_translations["Romanian"].insert(QStringLiteral("media_document"), QStringLiteral("Document"));
    m_translations["Romanian"].insert(QStringLiteral("media_unavailable"), QStringLiteral("Media indisponibilă"));
    m_translations["Romanian"].insert(QStringLiteral("tap_to_open"), QStringLiteral("Apasă pentru a deschide"));
    m_translations["Romanian"].insert(QStringLiteral("location"), QStringLiteral("Locație"));
    m_translations["Romanian"].insert(QStringLiteral("contact"), QStringLiteral("Contact"));
    m_translations["Romanian"].insert(QStringLiteral("favorites"), QStringLiteral("Favorite"));
    m_translations["Romanian"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("Adaugă la favorite"));
    m_translations["Romanian"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("Elimină din favorite"));
    m_translations["Romanian"].insert(QStringLiteral("no_favorites"), QStringLiteral("Nicio favorită"));
    m_translations["Romanian"].insert(QStringLiteral("favorites_hint"), QStringLiteral("Clic dreapta pe un mesaj pentru a adăuga la favorite"));
    m_translations["Romanian"].insert(QStringLiteral("media_browser"), QStringLiteral("Media"));
    m_translations["Romanian"].insert(QStringLiteral("media_browser_title"), QStringLiteral("Media"));
    m_translations["Romanian"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("Fotografii, videoclipuri și fișiere"));
    m_translations["Romanian"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("Fotografii"));
    m_translations["Romanian"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("Videoclipuri"));
    m_translations["Romanian"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("Documente"));
    m_translations["Romanian"].insert(QStringLiteral("media_browser_links"), QStringLiteral("Link-uri"));
    m_translations["Romanian"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("Locații"));
    m_translations["Romanian"].insert(QStringLiteral("no_photos_found"), QStringLiteral("Nicio fotografie găsită"));
    m_translations["Romanian"].insert(QStringLiteral("no_videos_found"), QStringLiteral("Niciun videoclip găsit"));
    m_translations["Romanian"].insert(QStringLiteral("no_documents_found"), QStringLiteral("Niciun document găsit"));
    m_translations["Romanian"].insert(QStringLiteral("no_links_found"), QStringLiteral("Niciun link găsit"));
    m_translations["Romanian"].insert(QStringLiteral("no_locations_found"), QStringLiteral("Nicio locație găsită"));

    // Serbian
    m_translations["Serbian"] = {
        {"contact_info", "Информације о контакту"}, {"msg_count", "Број порука"}, {"messages", "поруке"}, {"import_date", "Датум увоза"},
        {"no_chats", "Нема пронађених ћаскања\n\nКликните + да додате\nново ћаскање"}, {"light_theme", "Светла тема"}, {"dark_theme", "Тамна тема"},
        {"new_chat_tooltip", "Додај ново ћаскање"}, {"chat_search_placeholder", "Претражи ћаскања"}, {"importing", "Увоз у току..."},
        {"bulk_select_tooltip", "Масовни избор"}, {"bulk_delete_tooltip", "Масовно брисање"}, {"cancel_selection_tooltip", "Откажи"},
        {"import_new", "Додај ново ћаскање"}, {"zip_description", "Изаберите ZIP фајл извезен из WhatsApp-а."},
        {"select_zip", "Изабери ZIP фајл"}, {"change_zip", "Промени фајл"}, {"continue", "Настави"},
        {"owner_question", "Како се зовете у ћаскању?\n(Име које се приказује на вашем WhatsApp налогу)"}, {"owner_placeholder", "Нпр: Петар Петровић"},
        {"import_btn", "Увези"}, {"back", "Назад"}, {"loading_messages", "Учитавање порука, молимо сачекајте..."},
        {"select_zip_title", "Изаберите WhatsApp ZIP фајл"}, {"first_message", "Прва порука"}, {"delete_chat", "Обриши ћаскање"}, {"search", "Претражи..."}, {"search_tooltip", "Претражи поруке (Ctrl+F)"},
        {"empty_chat_hint", "Изаберите ћаскање или додајте ново"}, {"delete_confirm_title", "Обриши ћаскање"},
        {"delete_confirm_text", "Да ли сте сигурни да желите да обришете ово ћаскање?\nСве поруке ће бити уклоњене."}, {"no_results", "Нема пронађених резултата"},
        {"yes", "Да"}, {"no", "Не"}, {"cancel", "Откажи"}, {"language", "Језик"}, {"select_language", "Изабери језик"}, {"profile_photo", "Профилна слика"},
        {"name_label", "Име"}, {"participants_label", "Чланови групе"}, {"contact_name_placeholder", "Име контакта"}, {"image_files_filter", "Фајлови слика (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — %2 порука увезено"}, {"conversation", "Разговор"},
        {"default_owner_name", "Подразумевано име власника"}, {"owner_name_placeholder", "Ваше име"}, {"not_set", "Није постављено"}, {"default_label", "Подразумевано"},
        {"profile_library", "Библиотека профила"}, {"add_profile", "Додај профил"}, {"profile_name_label", "Име:"}, {"add_btn", "Додај"},
        {"optional", "(Опционо)"}, {"image_selected", "✓ Изабрано"}, {"no_profiles_library", "Још увек нема профила. Кликните + да додате."},
        {"profile_owner_conflict", "Не може се додати профил са истим именом као власник"}, {"profile_exists", "Профил са овим именом већ постоји"},
        {"message_count_text", "поруке"},
        {"january", "јан"}, {"february", "феб"}, {"march", "мар"}, {"april", "апр"}, {"may", "мај"}, {"june", "јун"},
        {"july", "јул"}, {"august", "авг"}, {"september", "сеп"}, {"october", "окт"}, {"november", "нов"}, {"december", "дец"},
        {"calendar_tooltip", "Иди на датум"},
        {"last_message", "Последња порука"},
        {"settings", "Подешавања"},
        {"auto_play_next_voice", "Аутоматски пусти наредне гласовне поруке"},
        {"open_system", "Отвори у систему"}, {"image_not_found", "Слика није пронађена"}, {"video", "Видео"}, {"deleted_message", "Ова порука је обрисана"}, {"you_deleted_message", "Обрисали сте ову поруку"}, {"edited", "Уређено"}, {"app_version", "верзија"}, {"app_copyright", "Ауторска права %1"},
        {"lock_chat", "Закључај ћаскање"}, {"unlock_chat", "Откључај ово ћаскање"}, {"locked_chats", "Закључана ћаскања"}, {"locked_chats_access", "Приступи закључаним ћаскањима"},
        {"lock_chat_title", "Закључај ћаскање"}, {"lock_chat_message", "Ово ћаскање ће бити закључано"}, {"lock_chat_set_password", "Поставите лозинку за закључавање ћаскања"},
        {"locked_chats_password_title", "Закључана ћаскања"}, {"locked_chats_enter_password", "Унесите лозинку за приступ закључаним ћаскањима"},
        {"password_6_digits", "Лозинка мора имати 6 цифара"}, {"password_incorrect", "Нетачна лозинка"}, {"no_master_password", "Лозинка није постављена"},
        {"locked_chats_password", "Лозинка закључаних ћаскања"}, {"no_password", "Немате лозинку"}, {"change_password", "Промени лозинку"},
        {"old_password", "Стара лозинка"}, {"new_password", "Нова лозинка"}, {"confirm_password", "Потврди нову лозинку"}, {"change", "Промени"},
        {"old_password_incorrect", "Стара лозинка је нетачна"}, {"passwords_dont_match", "Нове лозинке се не подударају"},
        {"no_locked_chats", "Нема закључаних ћаскања"}, {"locked_chats_hint", "Изаберите 'Закључај ћаскање' из менија са 3 тачке да закључате ћаскање"}, {"enter", "Уђи"}
    };
    m_translations["Serbian"].insert(QStringLiteral("media_image"), QStringLiteral("Фотографија"));
    m_translations["Serbian"].insert(QStringLiteral("media_video"), QStringLiteral("Видео"));
    m_translations["Serbian"].insert(QStringLiteral("media_voice"), QStringLiteral("Гласовна порука"));
    m_translations["Serbian"].insert(QStringLiteral("media_audio"), QStringLiteral("Аудио"));
    m_translations["Serbian"].insert(QStringLiteral("media_sticker"), QStringLiteral("Налепница"));
    m_translations["Serbian"].insert(QStringLiteral("media_document"), QStringLiteral("Документ"));
    m_translations["Serbian"].insert(QStringLiteral("media_unavailable"), QStringLiteral("Медији недоступни"));
    m_translations["Serbian"].insert(QStringLiteral("tap_to_open"), QStringLiteral("Додирните за отварање"));
    m_translations["Serbian"].insert(QStringLiteral("location"), QStringLiteral("Локација"));
    m_translations["Serbian"].insert(QStringLiteral("contact"), QStringLiteral("Контакт"));
    m_translations["Serbian"].insert(QStringLiteral("favorites"), QStringLiteral("Омиљено"));
    m_translations["Serbian"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("Додај у омиљено"));
    m_translations["Serbian"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("Уклони из омиљеног"));
    m_translations["Serbian"].insert(QStringLiteral("no_favorites"), QStringLiteral("Нема омиљених"));
    m_translations["Serbian"].insert(QStringLiteral("favorites_hint"), QStringLiteral("Кликните десним тастером на поруку да додате у омиљено"));
    m_translations["Serbian"].insert(QStringLiteral("media_browser"), QStringLiteral("Медији"));
    m_translations["Serbian"].insert(QStringLiteral("media_browser_title"), QStringLiteral("Медији"));
    m_translations["Serbian"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("Фотографије, видео записи и фајлови"));
    m_translations["Serbian"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("Фотографије"));
    m_translations["Serbian"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("Видео записи"));
    m_translations["Serbian"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("Документи"));
    m_translations["Serbian"].insert(QStringLiteral("media_browser_links"), QStringLiteral("Линкови"));
    m_translations["Serbian"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("Локације"));
    m_translations["Serbian"].insert(QStringLiteral("no_photos_found"), QStringLiteral("Нема пронађених фотографија"));
    m_translations["Serbian"].insert(QStringLiteral("no_videos_found"), QStringLiteral("Нема пронађених видео записа"));
    m_translations["Serbian"].insert(QStringLiteral("no_documents_found"), QStringLiteral("Нема пронађених докумената"));
    m_translations["Serbian"].insert(QStringLiteral("no_links_found"), QStringLiteral("Нема пронађених линкова"));
    m_translations["Serbian"].insert(QStringLiteral("no_locations_found"), QStringLiteral("Нема пронађених локација"));

    // Slovak
    m_translations["Slovak"] = {
        {"contact_info", "Informácie o kontakte"}, {"msg_count", "Počet správ"}, {"messages", "správy"}, {"import_date", "Dátum importu"},
        {"no_chats", "Nenašli sa žiadne chaty\n\nKliknite na + a pridajte\nnový chat"}, {"light_theme", "Svetlá téma"}, {"dark_theme", "Tmavá téma"},
        {"new_chat_tooltip", "Pridať nový chat"}, {"chat_search_placeholder", "Hľadať v chatoch"}, {"importing", "Prebieha import..."},
        {"bulk_select_tooltip", "Hromadný výber"}, {"bulk_delete_tooltip", "Hromadné odstránenie"}, {"cancel_selection_tooltip", "Zrušiť"},
        {"import_new", "Pridať nový chat"}, {"zip_description", "Vyberte súbor ZIP exportovaný z WhatsAppu."},
        {"select_zip", "Vybrať súbor ZIP"}, {"change_zip", "Zmeniť súbor"}, {"continue", "Pokračovať"},
        {"owner_question", "Ako sa voláte v chate?\n(Meno zobrazené vo vašom účte WhatsApp)"}, {"owner_placeholder", "Napr.: Ján Novák"},
        {"import_btn", "Importovať"}, {"back", "Späť"}, {"loading_messages", "Načítavajú sa správy, počkajte prosím..."},
        {"select_zip_title", "Vyberte súbor ZIP WhatsApp"}, {"first_message", "Prvá správa"}, {"delete_chat", "Odstrániť chat"}, {"search", "Hľadať..."}, {"search_tooltip", "Hľadať v správach (Ctrl+F)"},
        {"empty_chat_hint", "Vyberte chat alebo pridajte nový"}, {"delete_confirm_title", "Odstrániť chat"},
        {"delete_confirm_text", "Naozaj chcete odstrániť tento chat?\nVšetky správy budú odstránené."}, {"no_results", "Nenašli sa žiadne výsledky"},
        {"yes", "Áno"}, {"no", "Nie"}, {"cancel", "Zrušiť"}, {"language", "Jazyk"}, {"select_language", "Vybrať jazyk"}, {"profile_photo", "Profilová fotografia"},
        {"name_label", "Meno"}, {"participants_label", "Členovia skupiny"}, {"contact_name_placeholder", "Meno kontaktu"}, {"image_files_filter", "Súbory obrázkov (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — %2 správ importovaných"}, {"conversation", "Konverzácia"},
        {"default_owner_name", "Predvolené meno vlastníka"}, {"owner_name_placeholder", "Vaše meno"}, {"not_set", "Nenastavené"}, {"default_label", "Predvolené"},
        {"profile_library", "Knižnica profilov"}, {"add_profile", "Pridať profil"}, {"profile_name_label", "Meno:"}, {"add_btn", "Pridať"},
        {"optional", "(Voliteľné)"}, {"image_selected", "✓ Vybrané"}, {"no_profiles_library", "Zatiaľ žiadne profily. Kliknite na + a pridajte."},
        {"profile_owner_conflict", "Nie je možné pridať profil s rovnakým menom ako vlastník"}, {"profile_exists", "Profil s týmto menom už existuje"},
        {"message_count_text", "správy"},
        {"january", "jan"}, {"february", "feb"}, {"march", "mar"}, {"april", "apr"}, {"may", "máj"}, {"june", "jún"},
        {"july", "júl"}, {"august", "aug"}, {"september", "sep"}, {"october", "okt"}, {"november", "nov"}, {"december", "dec"},
        {"calendar_tooltip", "Prejsť na dátum"},
        {"last_message", "Posledná správa"},
        {"settings", "Nastavenia"},
        {"auto_play_next_voice", "Automaticky prehrať nasledujúce hlasové správy"},
        {"open_system", "Otvoriť v systéme"}, {"image_not_found", "Obrázok sa nenašiel"}, {"video", "Video"}, {"deleted_message", "Táto správa bola odstránená"}, {"you_deleted_message", "Odstránili ste túto správu"}, {"edited", "Upravené"}, {"app_version", "verzia"}, {"app_copyright", "Copyright od %1"},
        {"lock_chat", "Zamknúť chat"}, {"unlock_chat", "Odomknúť tento chat"}, {"locked_chats", "Zamknuté chaty"}, {"locked_chats_access", "Pristúpiť k zamknutým chatom"},
        {"lock_chat_title", "Zamknúť chat"}, {"lock_chat_message", "Tento chat bude zamknutý"}, {"lock_chat_set_password", "Nastavte heslo pre zamknutie chatov"},
        {"locked_chats_password_title", "Zamknuté chaty"}, {"locked_chats_enter_password", "Zadajte heslo pre prístup k zamknutým chatom"},
        {"password_6_digits", "Heslo musí mať 6 číslic"}, {"password_incorrect", "Nesprávne heslo"}, {"no_master_password", "Žiadne heslo nastavené"},
        {"locked_chats_password", "Heslo zamknutých chatov"}, {"no_password", "Nemáte heslo"}, {"change_password", "Zmeniť heslo"},
        {"old_password", "Staré heslo"}, {"new_password", "Nové heslo"}, {"confirm_password", "Potvrďte nové heslo"}, {"change", "Zmeniť"},
        {"old_password_incorrect", "Staré heslo je nesprávne"}, {"passwords_dont_match", "Nové heslá sa nezhodujú"},
        {"no_locked_chats", "Žiadne zamknuté chaty"}, {"locked_chats_hint", "Vyberte 'Zamknúť chat' z ponuky s 3 bodkami pre zamknutie chatu"}, {"enter", "Vstúpiť"}
    };
    m_translations["Slovak"].insert(QStringLiteral("media_image"), QStringLiteral("Fotografia"));
    m_translations["Slovak"].insert(QStringLiteral("media_video"), QStringLiteral("Video"));
    m_translations["Slovak"].insert(QStringLiteral("media_voice"), QStringLiteral("Hlasová správa"));
    m_translations["Slovak"].insert(QStringLiteral("media_audio"), QStringLiteral("Zvuk"));
    m_translations["Slovak"].insert(QStringLiteral("media_sticker"), QStringLiteral("Nálepka"));
    m_translations["Slovak"].insert(QStringLiteral("media_document"), QStringLiteral("Dokument"));
    m_translations["Slovak"].insert(QStringLiteral("media_unavailable"), QStringLiteral("Médiá nedostupné"));
    m_translations["Slovak"].insert(QStringLiteral("tap_to_open"), QStringLiteral("Ťuknutím otvoríte"));
    m_translations["Slovak"].insert(QStringLiteral("location"), QStringLiteral("Poloha"));
    m_translations["Slovak"].insert(QStringLiteral("contact"), QStringLiteral("Kontakt"));
    m_translations["Slovak"].insert(QStringLiteral("favorites"), QStringLiteral("Obľúbené"));
    m_translations["Slovak"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("Pridať do obľúbených"));
    m_translations["Slovak"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("Odstrániť z obľúbených"));
    m_translations["Slovak"].insert(QStringLiteral("no_favorites"), QStringLiteral("Žiadne obľúbené"));
    m_translations["Slovak"].insert(QStringLiteral("favorites_hint"), QStringLiteral("Kliknite pravým tlačidlom na správu a pridajte do obľúbených"));
    m_translations["Slovak"].insert(QStringLiteral("media_browser"), QStringLiteral("Médiá"));
    m_translations["Slovak"].insert(QStringLiteral("media_browser_title"), QStringLiteral("Médiá"));
    m_translations["Slovak"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("Fotografie, videá a súbory"));
    m_translations["Slovak"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("Fotografie"));
    m_translations["Slovak"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("Videá"));
    m_translations["Slovak"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("Dokumenty"));
    m_translations["Slovak"].insert(QStringLiteral("media_browser_links"), QStringLiteral("Odkazy"));
    m_translations["Slovak"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("Polohy"));
    m_translations["Slovak"].insert(QStringLiteral("no_photos_found"), QStringLiteral("Nenašli sa žiadne fotografie"));
    m_translations["Slovak"].insert(QStringLiteral("no_videos_found"), QStringLiteral("Nenašli sa žiadne videá"));
    m_translations["Slovak"].insert(QStringLiteral("no_documents_found"), QStringLiteral("Nenašli sa žiadne dokumenty"));
    m_translations["Slovak"].insert(QStringLiteral("no_links_found"), QStringLiteral("Nenašli sa žiadne odkazy"));
    m_translations["Slovak"].insert(QStringLiteral("no_locations_found"), QStringLiteral("Nenašli sa žiadne polohy"));

    // Slovenian
    m_translations["Slovenian"] = {
        {"contact_info", "Informacije o stiku"}, {"msg_count", "Število sporočil"}, {"messages", "sporočila"}, {"import_date", "Datum uvoza"},
        {"no_chats", "Ni najdenih klepetov\n\nKliknite + za dodajanje\nnovega klepeta"}, {"light_theme", "Svetla tema"}, {"dark_theme", "Temna tema"},
        {"new_chat_tooltip", "Dodaj nov klepet"}, {"chat_search_placeholder", "Išči v klepetih"}, {"importing", "Uvažanje..."},
        {"bulk_select_tooltip", "Množična izbira"}, {"bulk_delete_tooltip", "Množično brisanje"}, {"cancel_selection_tooltip", "Prekliči"},
        {"import_new", "Dodaj nov klepet"}, {"zip_description", "Izberite datoteko ZIP, izvoženo iz WhatsAppa."},
        {"select_zip", "Izberite datoteko ZIP"}, {"change_zip", "Spremeni datoteko"}, {"continue", "Nadaljuj"},
        {"owner_question", "Kakšno je vaše ime v klepetu?\n(Ime, prikazano v vašem računu WhatsApp)"}, {"owner_placeholder", "Npr.: Janez Novak"},
        {"import_btn", "Uvozi"}, {"back", "Nazaj"}, {"loading_messages", "Nalaganje sporočil, počakajte..."},
        {"select_zip_title", "Izberite datoteko ZIP WhatsApp"}, {"first_message", "Prvo sporočilo"}, {"delete_chat", "Izbriši klepet"}, {"search", "Išči..."}, {"search_tooltip", "Išči v sporočilih (Ctrl+F)"},
        {"empty_chat_hint", "Izberite klepet ali dodajte novega"}, {"delete_confirm_title", "Izbriši klepet"},
        {"delete_confirm_text", "Ali ste prepričani, da želite izbrisati ta klepet?\nVsa sporočila bodo odstranjena."}, {"no_results", "Ni najdenih rezultatov"},
        {"yes", "Da"}, {"no", "Ne"}, {"cancel", "Prekliči"}, {"language", "Jezik"}, {"select_language", "Izberite jezik"}, {"profile_photo", "Profilna fotografija"},
        {"name_label", "Ime"}, {"participants_label", "Člani skupine"}, {"contact_name_placeholder", "Ime stika"}, {"image_files_filter", "Slikovne datoteke (*.jpg *.jpeg *.png *.webp)"},
        {"import_success", "%1 — %2 sporočil uvoženih"}, {"conversation", "Pogovor"},
        {"default_owner_name", "Privzeto ime lastnika"}, {"owner_name_placeholder", "Vaše ime"}, {"not_set", "Ni nastavljeno"}, {"default_label", "Privzeto"},
        {"profile_library", "Knjižnica profilov"}, {"add_profile", "Dodaj profil"}, {"profile_name_label", "Ime:"}, {"add_btn", "Dodaj"},
        {"optional", "(Izbirno)"}, {"image_selected", "✓ Izbrano"}, {"no_profiles_library", "Še ni profilov. Kliknite + za dodajanje."},
        {"profile_owner_conflict", "Ni mogoče dodati profila z enakim imenom kot lastnik"}, {"profile_exists", "Profil s tem imenom že obstaja"},
        {"message_count_text", "sporočila"},
        {"january", "jan"}, {"february", "feb"}, {"march", "mar"}, {"april", "apr"}, {"may", "maj"}, {"june", "jun"},
        {"july", "jul"}, {"august", "avg"}, {"september", "sep"}, {"october", "okt"}, {"november", "nov"}, {"december", "dec"},
        {"calendar_tooltip", "Pojdi na datum"},
        {"last_message", "Zadnje sporočilo"},
        {"settings", "Nastavitve"},
        {"auto_play_next_voice", "Samodejno predvajaj zaporedna glasovna sporočila"},
        {"open_system", "Odpri v sistemu"}, {"image_not_found", "Slike ni mogoče najti"}, {"video", "Video"}, {"deleted_message", "To sporočilo je bilo izbrisano"}, {"you_deleted_message", "Izbrisali ste to sporočilo"}, {"edited", "Urejeno"}, {"app_version", "različica"}, {"app_copyright", "Avtorske pravice %1"},
        {"lock_chat", "Zakleni klepet"}, {"unlock_chat", "Odkleni ta klepet"}, {"locked_chats", "Zaklenjeni klepeti"}, {"locked_chats_access", "Dostop do zaklenjenih klepetov"},
        {"lock_chat_title", "Zakleni klepet"}, {"lock_chat_message", "Ta klepet bo zaklenjen"}, {"lock_chat_set_password", "Nastavite geslo za zaklepanje klepetov"},
        {"locked_chats_password_title", "Zaklenjeni klepeti"}, {"locked_chats_enter_password", "Vnesite geslo za dostop do zaklenjenih klepetov"},
        {"password_6_digits", "Geslo mora imeti 6 števk"}, {"password_incorrect", "Napačno geslo"}, {"no_master_password", "Ni nastavljenega gesla"},
        {"locked_chats_password", "Geslo zaklenjenih klepetov"}, {"no_password", "Nimate gesla"}, {"change_password", "Spremeni geslo"},
        {"old_password", "Staro geslo"}, {"new_password", "Novo geslo"}, {"confirm_password", "Potrdi novo geslo"}, {"change", "Spremeni"},
        {"old_password_incorrect", "Staro geslo je napačno"}, {"passwords_dont_match", "Novi gesli se ne ujemata"},
        {"no_locked_chats", "Ni zaklenjenih klepetov"}, {"locked_chats_hint", "Izberite 'Zakleni klepet' iz menija s 3 pikami za zaklepanje klepeta"}, {"enter", "Vstopi"}
    };
    m_translations["Slovenian"].insert(QStringLiteral("media_image"), QStringLiteral("Fotografija"));
    m_translations["Slovenian"].insert(QStringLiteral("media_video"), QStringLiteral("Video"));
    m_translations["Slovenian"].insert(QStringLiteral("media_voice"), QStringLiteral("Glasovno sporočilo"));
    m_translations["Slovenian"].insert(QStringLiteral("media_audio"), QStringLiteral("Zvok"));
    m_translations["Slovenian"].insert(QStringLiteral("media_sticker"), QStringLiteral("Nalepka"));
    m_translations["Slovenian"].insert(QStringLiteral("media_document"), QStringLiteral("Dokument"));
    m_translations["Slovenian"].insert(QStringLiteral("media_unavailable"), QStringLiteral("Mediji niso na voljo"));
    m_translations["Slovenian"].insert(QStringLiteral("tap_to_open"), QStringLiteral("Tapnite za odpiranje"));
    m_translations["Slovenian"].insert(QStringLiteral("location"), QStringLiteral("Lokacija"));
    m_translations["Slovenian"].insert(QStringLiteral("contact"), QStringLiteral("Stik"));
    m_translations["Slovenian"].insert(QStringLiteral("favorites"), QStringLiteral("Priljubljene"));
    m_translations["Slovenian"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("Dodaj med priljubljene"));
    m_translations["Slovenian"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("Odstrani iz priljubljenih"));
    m_translations["Slovenian"].insert(QStringLiteral("no_favorites"), QStringLiteral("Ni priljubljenih"));
    m_translations["Slovenian"].insert(QStringLiteral("favorites_hint"), QStringLiteral("Desni klik na sporočilo za dodajanje med priljubljene"));
    m_translations["Slovenian"].insert(QStringLiteral("media_browser"), QStringLiteral("Mediji"));
    m_translations["Slovenian"].insert(QStringLiteral("media_browser_title"), QStringLiteral("Mediji"));
    m_translations["Slovenian"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("Fotografije, videoposnetki in datoteke"));
    m_translations["Slovenian"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("Fotografije"));
    m_translations["Slovenian"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("Videoposnetki"));
    m_translations["Slovenian"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("Dokumenti"));
    m_translations["Slovenian"].insert(QStringLiteral("media_browser_links"), QStringLiteral("Povezave"));
    m_translations["Slovenian"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("Lokacije"));
    m_translations["Slovenian"].insert(QStringLiteral("no_photos_found"), QStringLiteral("Ni najdenih fotografij"));
    m_translations["Slovenian"].insert(QStringLiteral("no_videos_found"), QStringLiteral("Ni najdenih videoposnetkov"));
    m_translations["Slovenian"].insert(QStringLiteral("no_documents_found"), QStringLiteral("Ni najdenih dokumentov"));
    m_translations["Slovenian"].insert(QStringLiteral("no_links_found"), QStringLiteral("Ni najdenih povezav"));
    m_translations["Slovenian"].insert(QStringLiteral("no_locations_found"), QStringLiteral("Ni najdenih lokacij"));

    // Swahili
    m_translations["Swahili"] = {
        {"app_name", "WAPage"}, {"owner_name_label", "Jina Lako:"}, {"owner_name_placeholder", "Ingiza jina lako"},
        {"contact_info", "Maelezo ya Mwasiliani"}, {"msg_count", "Idadi ya Ujumbe"}, {"messages", "ujumbe"}, {"import_date", "Tarehe ya Uagizaji"},
        {"no_chats", "Hakuna mazungumzo yaliyopatikana\n\nBofya + kuongeza\nmazungumzo mapya"}, {"light_theme", "Mandhari ya Mwangaza"}, {"dark_theme", "Mandhari ya Giza"},
        {"select_language", "Chagua Lugha"}, {"theme", "Mandhari"}, {"lock_chat", "Funga Mazungumzo"}, {"unlock_chat", "Fungua Mazungumzo"},
        {"search_messages", "Tafuta ujumbe..."}, {"search_chats", "Tafuta mazungumzo..."}, {"jump_first_msg", "Nenda kwa ujumbe wa kwanza"}, {"jump_last_msg", "Nenda kwa ujumbe wa mwisho"},
        {"jump_first_unread_msg", "Nenda kwa ujumbe wa kwanza usiosomwa"}, {"jump_to_message", "Nenda kwa Ujumbe"}, {"enter_msg_number", "Ingiza nambari ya ujumbe (1-{0}):"},
        {"invalid_input", "Pembejeo si sahihi"}, {"msg_out_of_range", "Ujumbe nje ya masafa"}, {"cancel", "Ghairi"}, {"ok", "Sawa"},
        {"about", "Kuhusu"}, {"import_chat", "Agiza Mazungumzo..."}, {"export_chat", "Hamisha Mazungumzo..."}, {"delete_chat", "Futa Mazungumzo"},
        {"delete_confirm_title", "Futa Mazungumzo"}, {"delete_confirm_msg", "Je, una uhakika unataka kufuta \"{0}\"? Hatua hii haiwezi kughairiwa."},
        {"jump", "Ruka"}, {"import_zip_dialog_title", "Agiza Faili ya ZIP ya WhatsApp"}, {"select_zip", "Chagua faili ya ZIP ya WhatsApp..."},
        {"or_drag_drop", "au buruta na udondoshe hapa"}, {"drop_here", "Dondosha faili hapa"}, {"importing", "Inaagiza..."},
        {"success_imported", "Imeagizwa kwa mafanikio: {0}"}, {"error_title", "Hitilafu"}, {"err_open_zip", "Imeshindwa kufungua faili ya ZIP"},
        {"err_extract_zip", "Imeshindwa kutoa faili ya ZIP"}, {"err_no_txt", "Hakuna faili ya _chat.txt iliyopatikana"}, {"err_empty_txt", "Faili ya _chat.txt ni tupu"},
        {"err_parse_txt", "Imeshindwa kuchambua faili ya _chat.txt"}, {"close", "Funga"}, {"calendar_dialog_title", "Chagua Tarehe"},
        {"pinned_message", "Ujumbe Uliobanwa"}, {"this_message_deleted", "Ujumbe huu ulifutwa"}, {"audio_unavailable", "Sauti haipo"},
        {"play_pause", "Cheza / Simamisha"}, {"locked_chats", "Mazungumzo Yaliyofungwa"}, {"no_locked_chats", "Hakuna mazungumzo yaliyofungwa"},
        {"locked_chats_hint", "Chagua 'Funga Mazungumzo' kutoka kwenye menyu ya nukta 3 ili kufunga mazungumzo"}, {"enter", "Ingia"}
    };
    m_translations["Swahili"].insert(QStringLiteral("media_image"), QStringLiteral("Picha"));
    m_translations["Swahili"].insert(QStringLiteral("media_video"), QStringLiteral("Video"));
    m_translations["Swahili"].insert(QStringLiteral("media_voice"), QStringLiteral("Ujumbe wa Sauti"));
    m_translations["Swahili"].insert(QStringLiteral("media_audio"), QStringLiteral("Sauti"));
    m_translations["Swahili"].insert(QStringLiteral("media_sticker"), QStringLiteral("Stika"));
    m_translations["Swahili"].insert(QStringLiteral("media_document"), QStringLiteral("Hati"));
    m_translations["Swahili"].insert(QStringLiteral("media_unavailable"), QStringLiteral("Media haipo"));
    m_translations["Swahili"].insert(QStringLiteral("tap_to_open"), QStringLiteral("Gusa kufungua"));
    m_translations["Swahili"].insert(QStringLiteral("location"), QStringLiteral("Mahali"));
    m_translations["Swahili"].insert(QStringLiteral("contact"), QStringLiteral("Mwasiliani"));
    m_translations["Swahili"].insert(QStringLiteral("favorites"), QStringLiteral("Vipendwa"));
    m_translations["Swahili"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("Ongeza kwenye Vipendwa"));
    m_translations["Swahili"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("Ondoa kutoka Vipendwa"));
    m_translations["Swahili"].insert(QStringLiteral("no_favorites"), QStringLiteral("Hakuna vipendwa"));
    m_translations["Swahili"].insert(QStringLiteral("favorites_hint"), QStringLiteral("Bofya kulia kwenye ujumbe ili kuongeza kwenye vipendwa"));
    m_translations["Swahili"].insert(QStringLiteral("media_browser"), QStringLiteral("Media"));
    m_translations["Swahili"].insert(QStringLiteral("media_browser_title"), QStringLiteral("Media"));
    m_translations["Swahili"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("Picha, video na faili"));
    m_translations["Swahili"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("Picha"));
    m_translations["Swahili"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("Video"));
    m_translations["Swahili"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("Hati"));
    m_translations["Swahili"].insert(QStringLiteral("media_browser_links"), QStringLiteral("Viungo"));
    m_translations["Swahili"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("Maeneo"));
    m_translations["Swahili"].insert(QStringLiteral("no_photos_found"), QStringLiteral("Hakuna picha zilizopatikana"));
    m_translations["Swahili"].insert(QStringLiteral("no_videos_found"), QStringLiteral("Hakuna video zilizopatikana"));
    m_translations["Swahili"].insert(QStringLiteral("no_documents_found"), QStringLiteral("Hakuna hati zilizopatikana"));
    m_translations["Swahili"].insert(QStringLiteral("no_links_found"), QStringLiteral("Hakuna viungo vilivyopatikana"));
    m_translations["Swahili"].insert(QStringLiteral("no_locations_found"), QStringLiteral("Hakuna maeneo yaliyopatikana"));

    // Swedish
    m_translations["Swedish"] = {
        {"app_name", "WAPage"}, {"owner_name_label", "Ditt Namn:"}, {"owner_name_placeholder", "Ange ditt namn"},
        {"contact_info", "Kontaktinformation"}, {"msg_count", "Meddelandeantal"}, {"messages", "meddelanden"}, {"import_date", "Importdatum"},
        {"no_chats", "Inga chattar hittades\n\nKlicka på + för att lägga till\nen ny chatt"}, {"light_theme", "Ljust tema"}, {"dark_theme", "Mörkt tema"},
        {"select_language", "Välj Språk"}, {"theme", "Tema"}, {"lock_chat", "Lås Chatt"}, {"unlock_chat", "Lås Upp Chatt"},
        {"search_messages", "Sök meddelanden..."}, {"search_chats", "Sök chattar..."}, {"jump_first_msg", "Hoppa till första meddelandet"}, {"jump_last_msg", "Hoppa till sista meddelandet"},
        {"jump_first_unread_msg", "Hoppa till första olästa meddelandet"}, {"jump_to_message", "Hoppa till Meddelande"}, {"enter_msg_number", "Ange meddelandenummer (1-{0}):"},
        {"invalid_input", "Ogiltig inmatning"}, {"msg_out_of_range", "Meddelande utanför intervallet"}, {"cancel", "Avbryt"}, {"ok", "OK"},
        {"about", "Om"}, {"import_chat", "Importera Chatt..."}, {"export_chat", "Exportera Chatt..."}, {"delete_chat", "Ta Bort Chatt"},
        {"delete_confirm_title", "Ta Bort Chatt"}, {"delete_confirm_msg", "Är du säker på att du vill ta bort \"{0}\"? Detta kan inte ångras."},
        {"jump", "Hoppa"}, {"import_zip_dialog_title", "Importera WhatsApp ZIP-fil"}, {"select_zip", "Välj WhatsApp ZIP-fil..."},
        {"or_drag_drop", "eller dra och släpp här"}, {"drop_here", "Släpp fil här"}, {"importing", "Importerar..."},
        {"success_imported", "Importerades framgångsrikt: {0}"}, {"error_title", "Fel"}, {"err_open_zip", "Misslyckades med att öppna ZIP-filen"},
        {"err_extract_zip", "Misslyckades med att extrahera ZIP-filen"}, {"err_no_txt", "Ingen _chat.txt-fil hittades"}, {"err_empty_txt", "_chat.txt-filen är tom"},
        {"err_parse_txt", "Misslyckades med att tolka _chat.txt-filen"}, {"close", "Stäng"}, {"calendar_dialog_title", "Välj Datum"},
        {"pinned_message", "Fastsatt Meddelande"}, {"this_message_deleted", "Detta meddelande raderades"}, {"audio_unavailable", "Ljud är inte tillgängligt"},
        {"play_pause", "Spela / Pausa"}, {"locked_chats", "Låsta Chattar"}, {"no_locked_chats", "Inga låsta chattar"},
        {"locked_chats_hint", "Välj 'Lås Chatt' från 3-punktsmenyn för att låsa en chatt"}, {"enter", "Gå In"}
    };
    m_translations["Swedish"].insert(QStringLiteral("media_image"), QStringLiteral("Foto"));
    m_translations["Swedish"].insert(QStringLiteral("media_video"), QStringLiteral("Video"));
    m_translations["Swedish"].insert(QStringLiteral("media_voice"), QStringLiteral("Röstmeddelande"));
    m_translations["Swedish"].insert(QStringLiteral("media_audio"), QStringLiteral("Ljud"));
    m_translations["Swedish"].insert(QStringLiteral("media_sticker"), QStringLiteral("Klistermärke"));
    m_translations["Swedish"].insert(QStringLiteral("media_document"), QStringLiteral("Dokument"));
    m_translations["Swedish"].insert(QStringLiteral("media_unavailable"), QStringLiteral("Media är inte tillgänglig"));
    m_translations["Swedish"].insert(QStringLiteral("tap_to_open"), QStringLiteral("Tryck för att öppna"));
    m_translations["Swedish"].insert(QStringLiteral("location"), QStringLiteral("Plats"));
    m_translations["Swedish"].insert(QStringLiteral("contact"), QStringLiteral("Kontakt"));
    m_translations["Swedish"].insert(QStringLiteral("favorites"), QStringLiteral("Favoriter"));
    m_translations["Swedish"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("Lägg Till i Favoriter"));
    m_translations["Swedish"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("Ta Bort från Favoriter"));
    m_translations["Swedish"].insert(QStringLiteral("no_favorites"), QStringLiteral("Inga favoriter"));
    m_translations["Swedish"].insert(QStringLiteral("favorites_hint"), QStringLiteral("Högerklicka på ett meddelande för att lägga till i favoriter"));
    m_translations["Swedish"].insert(QStringLiteral("media_browser"), QStringLiteral("Media"));
    m_translations["Swedish"].insert(QStringLiteral("media_browser_title"), QStringLiteral("Media"));
    m_translations["Swedish"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("Foton, videor och filer"));
    m_translations["Swedish"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("Foton"));
    m_translations["Swedish"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("Videor"));
    m_translations["Swedish"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("Dokument"));
    m_translations["Swedish"].insert(QStringLiteral("media_browser_links"), QStringLiteral("Länkar"));
    m_translations["Swedish"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("Platser"));
    m_translations["Swedish"].insert(QStringLiteral("no_photos_found"), QStringLiteral("Inga foton hittades"));
    m_translations["Swedish"].insert(QStringLiteral("no_videos_found"), QStringLiteral("Inga videor hittades"));
    m_translations["Swedish"].insert(QStringLiteral("no_documents_found"), QStringLiteral("Inga dokument hittades"));
    m_translations["Swedish"].insert(QStringLiteral("no_links_found"), QStringLiteral("Inga länkar hittades"));
    m_translations["Swedish"].insert(QStringLiteral("no_locations_found"), QStringLiteral("Inga platser hittades"));

    // Tamil
    m_translations["Tamil"] = {
        {"app_name", "WAPage"}, {"owner_name_label", "உங்கள் பெயர்:"}, {"owner_name_placeholder", "உங்கள் பெயரை உள்ளிடவும்"},
        {"contact_info", "தொடர்பு தகவல்"}, {"msg_count", "செய்தி எண்ணிக்கை"}, {"messages", "செய்திகள்"}, {"import_date", "இறக்குமதி தேதி"},
        {"no_chats", "அரட்டைகள் எதுவும் கிடைக்கவில்லை\n\nபுதிய அரட்டையைச் சேர்க்க\n+ ஐக் கிளிக் செய்யவும்"}, {"light_theme", "ஒளி தீம்"}, {"dark_theme", "இருள் தீம்"},
        {"select_language", "மொழியைத் தேர்ந்தெடுக்கவும்"}, {"theme", "தீம்"}, {"lock_chat", "அரட்டையைப் பூட்டு"}, {"unlock_chat", "அரட்டையைத் திற"},
        {"search_messages", "செய்திகளைத் தேடு..."}, {"search_chats", "அரட்டைகளைத் தேடு..."}, {"jump_first_msg", "முதல் செய்திக்குச் செல்"}, {"jump_last_msg", "கடைசி செய்திக்குச் செல்"},
        {"jump_first_unread_msg", "முதல் படிக்காத செய்திக்குச் செல்"}, {"jump_to_message", "செய்திக்குச் செல்"}, {"enter_msg_number", "செய்தி எண்ணை உள்ளிடவும் (1-{0}):"},
        {"invalid_input", "தவறான உள்ளீடு"}, {"msg_out_of_range", "செய்தி வரம்புக்கு வெளியே"}, {"cancel", "ரத்துசெய்"}, {"ok", "சரி"},
        {"about", "பற்றி"}, {"import_chat", "அரட்டையை இறக்குமதி செய்..."}, {"export_chat", "அரட்டையை ஏற்றுமதி செய்..."}, {"delete_chat", "அரட்டையை நீக்கு"},
        {"delete_confirm_title", "அரட்டையை நீக்கு"}, {"delete_confirm_msg", "\"{0}\" ஐ நிச்சயமாக நீக்க விரும்புகிறீர்களா? இதைச் செயல்தவிர்க்க முடியாது."},
        {"jump", "தாண்டு"}, {"import_zip_dialog_title", "WhatsApp ZIP கோப்பை இறக்குமதி செய்"}, {"select_zip", "WhatsApp ZIP கோப்பைத் தேர்ந்தெடு..."},
        {"or_drag_drop", "அல்லது இங்கே இழுத்து விடவும்"}, {"drop_here", "கோப்பை இங்கே விடவும்"}, {"importing", "இறக்குமதி செய்கிறது..."},
        {"success_imported", "வெற்றிகரமாக இறக்குமதி செய்யப்பட்டது: {0}"}, {"error_title", "பிழை"}, {"err_open_zip", "ZIP கோப்பைத் திறக்க முடியவில்லை"},
        {"err_extract_zip", "ZIP கோப்பை பிரிக்க முடியவில்லை"}, {"err_no_txt", "_chat.txt கோப்பு கிடைக்கவில்லை"}, {"err_empty_txt", "_chat.txt கோப்பு காலியாக உள்ளது"},
        {"err_parse_txt", "_chat.txt கோப்பை பகுக்க முடியவில்லை"}, {"close", "மூடு"}, {"calendar_dialog_title", "தேதியைத் தேர்ந்தெடு"},
        {"pinned_message", "பின் செய்யப்பட்ட செய்தி"}, {"this_message_deleted", "இந்தச் செய்தி நீக்கப்பட்டது"}, {"audio_unavailable", "ஆடியோ கிடைக்கவில்லை"},
        {"play_pause", "இயக்கு / இடைநிறுத்து"}, {"locked_chats", "பூட்டப்பட்ட அரட்டைகள்"}, {"no_locked_chats", "பூட்டப்பட்ட அரட்டைகள் இல்லை"},
        {"locked_chats_hint", "அரட்டையைப் பூட்ட 3-புள்ளி மெனுவிலிருந்து 'அரட்டையைப் பூட்டு' என்பதைத் தேர்ந்தெடுக்கவும்"}, {"enter", "உள்ளே செல்"}
    };
    m_translations["Tamil"].insert(QStringLiteral("media_image"), QStringLiteral("புகைப்படம்"));
    m_translations["Tamil"].insert(QStringLiteral("media_video"), QStringLiteral("வீடியோ"));
    m_translations["Tamil"].insert(QStringLiteral("media_voice"), QStringLiteral("குரல் செய்தி"));
    m_translations["Tamil"].insert(QStringLiteral("media_audio"), QStringLiteral("ஆடியோ"));
    m_translations["Tamil"].insert(QStringLiteral("media_sticker"), QStringLiteral("ஸ்டிக்கர்"));
    m_translations["Tamil"].insert(QStringLiteral("media_document"), QStringLiteral("ஆவணம்"));
    m_translations["Tamil"].insert(QStringLiteral("media_unavailable"), QStringLiteral("மீடியா கிடைக்கவில்லை"));
    m_translations["Tamil"].insert(QStringLiteral("tap_to_open"), QStringLiteral("திறக்க தட்டவும்"));
    m_translations["Tamil"].insert(QStringLiteral("location"), QStringLiteral("இடம்"));
    m_translations["Tamil"].insert(QStringLiteral("contact"), QStringLiteral("தொடர்பு"));
    m_translations["Tamil"].insert(QStringLiteral("favorites"), QStringLiteral("பிடித்தவை"));
    m_translations["Tamil"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("பிடித்தவையில் சேர்"));
    m_translations["Tamil"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("பிடித்தவையிலிருந்து நீக்கு"));
    m_translations["Tamil"].insert(QStringLiteral("no_favorites"), QStringLiteral("பிடித்தவை இல்லை"));
    m_translations["Tamil"].insert(QStringLiteral("favorites_hint"), QStringLiteral("பிடித்தவையில் சேர்க்க செய்தியை வலது கிளிக் செய்யவும்"));
    m_translations["Tamil"].insert(QStringLiteral("media_browser"), QStringLiteral("மீடியா"));
    m_translations["Tamil"].insert(QStringLiteral("media_browser_title"), QStringLiteral("மீடியா"));
    m_translations["Tamil"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("புகைப்படங்கள், வீடியோக்கள் மற்றும் கோப்புகள்"));
    m_translations["Tamil"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("புகைப்படங்கள்"));
    m_translations["Tamil"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("வீடியோக்கள்"));
    m_translations["Tamil"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("ஆவணங்கள்"));
    m_translations["Tamil"].insert(QStringLiteral("media_browser_links"), QStringLiteral("இணைப்புகள்"));
    m_translations["Tamil"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("இடங்கள்"));
    m_translations["Tamil"].insert(QStringLiteral("no_photos_found"), QStringLiteral("புகைப்படங்கள் கிடைக்கவில்லை"));
    m_translations["Tamil"].insert(QStringLiteral("no_videos_found"), QStringLiteral("வீடியோக்கள் கிடைக்கவில்லை"));
    m_translations["Tamil"].insert(QStringLiteral("no_documents_found"), QStringLiteral("ஆவணங்கள் கிடைக்கவில்லை"));
    m_translations["Tamil"].insert(QStringLiteral("no_links_found"), QStringLiteral("இணைப்புகள் கிடைக்கவில்லை"));
    m_translations["Tamil"].insert(QStringLiteral("no_locations_found"), QStringLiteral("இடங்கள் கிடைக்கவில்லை"));

    // Telugu
    m_translations["Telugu"] = {
        {"app_name", "WAPage"}, {"owner_name_label", "మీ పేరు:"}, {"owner_name_placeholder", "మీ పేరును నమోదు చేయండి"},
        {"contact_info", "సంప్రదింపు సమాచారం"}, {"msg_count", "సందేశ సంఖ్య"}, {"messages", "సందేశాలు"}, {"import_date", "దిగుమతి తేదీ"},
        {"no_chats", "చాట్‌లు కనుగొనబడలేదు\n\nకొత్త చాట్ జోడించడానికి\n+ క్లిక్ చేయండి"}, {"light_theme", "తేలికపాటి థీమ్"}, {"dark_theme", "ముదురు థీమ్"},
        {"select_language", "భాషను ఎంచుకోండి"}, {"theme", "థీమ్"}, {"lock_chat", "చాట్‌ను లాక్ చేయండి"}, {"unlock_chat", "చాట్‌ను అన్‌లాక్ చేయండి"},
        {"search_messages", "సందేశాలను శోధించండి..."}, {"search_chats", "చాట్‌లను శోధించండి..."}, {"jump_first_msg", "మొదటి సందేశానికి వెళ్లండి"}, {"jump_last_msg", "చివరి సందేశానికి వెళ్లండి"},
        {"jump_first_unread_msg", "మొదటి చదవని సందేశానికి వెళ్లండి"}, {"jump_to_message", "సందేశానికి వెళ్లండి"}, {"enter_msg_number", "సందేశ సంఖ్యను నమోదు చేయండి (1-{0}):"},
        {"invalid_input", "చెల్లని ఇన్‌పుట్"}, {"msg_out_of_range", "సందేశం పరిధి వెలుపల"}, {"cancel", "రద్దు చేయండి"}, {"ok", "సరే"},
        {"about", "గురించి"}, {"import_chat", "చాట్‌ను దిగుమతి చేయండి..."}, {"export_chat", "చాట్‌ను ఎగుమతి చేయండి..."}, {"delete_chat", "చాట్‌ను తొలగించండి"},
        {"delete_confirm_title", "చాట్‌ను తొలగించండి"}, {"delete_confirm_msg", "\"{0}\" ను ఖచ్చితంగా తొలగించాలనుకుంటున్నారా? ఇది రద్దు చేయబడదు."},
        {"jump", "దూకండి"}, {"import_zip_dialog_title", "WhatsApp ZIP ఫైల్‌ను దిగుమతి చేయండి"}, {"select_zip", "WhatsApp ZIP ఫైల్‌ను ఎంచుకోండి..."},
        {"or_drag_drop", "లేదా ఇక్కడ లాగి వదలండి"}, {"drop_here", "ఫైల్‌ను ఇక్కడ వదలండి"}, {"importing", "దిగుమతి చేస్తోంది..."},
        {"success_imported", "విజయవంతంగా దిగుమతి చేయబడింది: {0}"}, {"error_title", "లోపం"}, {"err_open_zip", "ZIP ఫైల్‌ను తెరవడంలో విఫలమైంది"},
        {"err_extract_zip", "ZIP ఫైల్‌ను సంగ్రహించడంలో విఫలమైంది"}, {"err_no_txt", "_chat.txt ఫైల్ కనుగొనబడలేదు"}, {"err_empty_txt", "_chat.txt ఫైల్ ఖాళీగా ఉంది"},
        {"err_parse_txt", "_chat.txt ఫైల్‌ను విశ్లేషించడంలో విఫలమైంది"}, {"close", "మూసివేయండి"}, {"calendar_dialog_title", "తేదీని ఎంచుకోండి"},
        {"pinned_message", "పిన్ చేసిన సందేశం"}, {"this_message_deleted", "ఈ సందేశం తొలగించబడింది"}, {"audio_unavailable", "ఆడియో అందుబాటులో లేదు"},
        {"play_pause", "ప్లే / పాజ్"}, {"locked_chats", "లాక్ చేసిన చాట్‌లు"}, {"no_locked_chats", "లాక్ చేసిన చాట్‌లు లేవు"},
        {"locked_chats_hint", "చాట్‌ను లాక్ చేయడానికి 3-డాట్ మెనూ నుండి 'చాట్‌ను లాక్ చేయండి'ని ఎంచుకోండి"}, {"enter", "ప్రవేశించండి"}
    };
    m_translations["Telugu"].insert(QStringLiteral("media_image"), QStringLiteral("ఫోటో"));
    m_translations["Telugu"].insert(QStringLiteral("media_video"), QStringLiteral("వీడియో"));
    m_translations["Telugu"].insert(QStringLiteral("media_voice"), QStringLiteral("వాయిస్ సందేశం"));
    m_translations["Telugu"].insert(QStringLiteral("media_audio"), QStringLiteral("ఆడియో"));
    m_translations["Telugu"].insert(QStringLiteral("media_sticker"), QStringLiteral("స్టిక్కర్"));
    m_translations["Telugu"].insert(QStringLiteral("media_document"), QStringLiteral("పత్రం"));
    m_translations["Telugu"].insert(QStringLiteral("media_unavailable"), QStringLiteral("మీడియా అందుబాటులో లేదు"));
    m_translations["Telugu"].insert(QStringLiteral("tap_to_open"), QStringLiteral("తెరవడానికి ట్యాప్ చేయండి"));
    m_translations["Telugu"].insert(QStringLiteral("location"), QStringLiteral("స్థానం"));
    m_translations["Telugu"].insert(QStringLiteral("contact"), QStringLiteral("సంప్రదింపు"));
    m_translations["Telugu"].insert(QStringLiteral("favorites"), QStringLiteral("ఇష్టమైనవి"));
    m_translations["Telugu"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("ఇష్టమైనవాటికి జోడించండి"));
    m_translations["Telugu"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("ఇష్టమైనవాటి నుండి తొలగించండి"));
    m_translations["Telugu"].insert(QStringLiteral("no_favorites"), QStringLiteral("ఇష్టమైనవి లేవు"));
    m_translations["Telugu"].insert(QStringLiteral("favorites_hint"), QStringLiteral("ఇష్టమైనవాటికి జోడించడానికి సందేశంపై రైట్ క్లిక్ చేయండి"));
    m_translations["Telugu"].insert(QStringLiteral("media_browser"), QStringLiteral("మీడియా"));
    m_translations["Telugu"].insert(QStringLiteral("media_browser_title"), QStringLiteral("మీడియా"));
    m_translations["Telugu"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("ఫోటోలు, వీడియోలు మరియు ఫైల్‌లు"));
    m_translations["Telugu"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("ఫోటోలు"));
    m_translations["Telugu"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("వీడియోలు"));
    m_translations["Telugu"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("పత్రాలు"));
    m_translations["Telugu"].insert(QStringLiteral("media_browser_links"), QStringLiteral("లింక్‌లు"));
    m_translations["Telugu"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("స్థానాలు"));
    m_translations["Telugu"].insert(QStringLiteral("no_photos_found"), QStringLiteral("ఫోటోలు కనుగొనబడలేదు"));
    m_translations["Telugu"].insert(QStringLiteral("no_videos_found"), QStringLiteral("వీడియోలు కనుగొనబడలేదు"));
    m_translations["Telugu"].insert(QStringLiteral("no_documents_found"), QStringLiteral("పత్రాలు కనుగొనబడలేదు"));
    m_translations["Telugu"].insert(QStringLiteral("no_links_found"), QStringLiteral("లింక్‌లు కనుగొనబడలేదు"));
    m_translations["Telugu"].insert(QStringLiteral("no_locations_found"), QStringLiteral("స్థానాలు కనుగొనబడలేదు"));

    // Thai
    m_translations["Thai"] = {
        {"app_name", "WAPage"}, {"owner_name_label", "ชื่อของคุณ:"}, {"owner_name_placeholder", "ใส่ชื่อของคุณ"},
        {"contact_info", "ข้อมูลติดต่อ"}, {"msg_count", "จำนวนข้อความ"}, {"messages", "ข้อความ"}, {"import_date", "วันที่นำเข้า"},
        {"no_chats", "ไม่พบแชท\n\nคลิก + เพื่อเพิ่ม\nแชทใหม่"}, {"light_theme", "ธีมสว่าง"}, {"dark_theme", "ธีมมืด"},
        {"select_language", "เลือกภาษา"}, {"theme", "ธีม"}, {"lock_chat", "ล็อคแชท"}, {"unlock_chat", "ปลดล็อคแชท"},
        {"search_messages", "ค้นหาข้อความ..."}, {"search_chats", "ค้นหาแชท..."}, {"jump_first_msg", "ไปที่ข้อความแรก"}, {"jump_last_msg", "ไปที่ข้อความสุดท้าย"},
        {"jump_first_unread_msg", "ไปที่ข้อความแรกที่ยังไม่ได้อ่าน"}, {"jump_to_message", "ไปที่ข้อความ"}, {"enter_msg_number", "ใส่หมายเลขข้อความ (1-{0}):"},
        {"invalid_input", "ข้อมูลไม่ถูกต้อง"}, {"msg_out_of_range", "ข้อความอยู่นอกช่วง"}, {"cancel", "ยกเลิก"}, {"ok", "ตกลง"},
        {"about", "เกี่ยวกับ"}, {"import_chat", "นำเข้าแชท..."}, {"export_chat", "ส่งออกแชท..."}, {"delete_chat", "ลบแชท"},
        {"delete_confirm_title", "ลบแชท"}, {"delete_confirm_msg", "คุณแน่ใจหรือไม่ว่าต้องการลบ \"{0}\"? การดำเนินการนี้ไม่สามารถยกเลิกได้"},
        {"jump", "ข้าม"}, {"import_zip_dialog_title", "นำเข้าไฟล์ ZIP จาก WhatsApp"}, {"select_zip", "เลือกไฟล์ ZIP จาก WhatsApp..."},
        {"or_drag_drop", "หรือลากแล้ววางที่นี่"}, {"drop_here", "วางไฟล์ที่นี่"}, {"importing", "กำลังนำเข้า..."},
        {"success_imported", "นำเข้าสำเร็จ: {0}"}, {"error_title", "ข้อผิดพลาด"}, {"err_open_zip", "ไม่สามารถเปิดไฟล์ ZIP"},
        {"err_extract_zip", "ไม่สามารถแตกไฟล์ ZIP"}, {"err_no_txt", "ไม่พบไฟล์ _chat.txt"}, {"err_empty_txt", "ไฟล์ _chat.txt ว่างเปล่า"},
        {"err_parse_txt", "ไม่สามารถแยกวิเคราะห์ไฟล์ _chat.txt"}, {"close", "ปิด"}, {"calendar_dialog_title", "เลือกวันที่"},
        {"pinned_message", "ข้อความที่ปักหมุด"}, {"this_message_deleted", "ข้อความนี้ถูกลบแล้ว"}, {"audio_unavailable", "ไม่มีเสียง"},
        {"play_pause", "เล่น / หยุดชั่วคราว"}, {"locked_chats", "แชทที่ล็อค"}, {"no_locked_chats", "ไม่มีแชทที่ล็อค"},
        {"locked_chats_hint", "เลือก 'ล็อคแชท' จากเมนู 3 จุดเพื่อล็อคแชท"}, {"enter", "เข้า"}
    };
    m_translations["Thai"].insert(QStringLiteral("media_image"), QStringLiteral("รูปภาพ"));
    m_translations["Thai"].insert(QStringLiteral("media_video"), QStringLiteral("วิดีโอ"));
    m_translations["Thai"].insert(QStringLiteral("media_voice"), QStringLiteral("ข้อความเสียง"));
    m_translations["Thai"].insert(QStringLiteral("media_audio"), QStringLiteral("เสียง"));
    m_translations["Thai"].insert(QStringLiteral("media_sticker"), QStringLiteral("สติกเกอร์"));
    m_translations["Thai"].insert(QStringLiteral("media_document"), QStringLiteral("เอกสาร"));
    m_translations["Thai"].insert(QStringLiteral("media_unavailable"), QStringLiteral("ไม่มีสื่อ"));
    m_translations["Thai"].insert(QStringLiteral("tap_to_open"), QStringLiteral("แตะเพื่อเปิด"));
    m_translations["Thai"].insert(QStringLiteral("location"), QStringLiteral("ตำแหน่ง"));
    m_translations["Thai"].insert(QStringLiteral("contact"), QStringLiteral("ผู้ติดต่อ"));
    m_translations["Thai"].insert(QStringLiteral("favorites"), QStringLiteral("รายการโปรด"));
    m_translations["Thai"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("เพิ่มในรายการโปรด"));
    m_translations["Thai"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("ลบออกจากรายการโปรด"));
    m_translations["Thai"].insert(QStringLiteral("no_favorites"), QStringLiteral("ไม่มีรายการโปรด"));
    m_translations["Thai"].insert(QStringLiteral("favorites_hint"), QStringLiteral("คลิกขวาที่ข้อความเพื่อเพิ่มในรายการโปรด"));
    m_translations["Thai"].insert(QStringLiteral("media_browser"), QStringLiteral("สื่อ"));
    m_translations["Thai"].insert(QStringLiteral("media_browser_title"), QStringLiteral("สื่อ"));
    m_translations["Thai"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("รูปภาพ วิดีโอ และไฟล์"));
    m_translations["Thai"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("รูปภาพ"));
    m_translations["Thai"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("วิดีโอ"));
    m_translations["Thai"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("เอกสาร"));
    m_translations["Thai"].insert(QStringLiteral("media_browser_links"), QStringLiteral("ลิงก์"));
    m_translations["Thai"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("ตำแหน่ง"));
    m_translations["Thai"].insert(QStringLiteral("no_photos_found"), QStringLiteral("ไม่พบรูปภาพ"));
    m_translations["Thai"].insert(QStringLiteral("no_videos_found"), QStringLiteral("ไม่พบวิดีโอ"));
    m_translations["Thai"].insert(QStringLiteral("no_documents_found"), QStringLiteral("ไม่พบเอกสาร"));
    m_translations["Thai"].insert(QStringLiteral("no_links_found"), QStringLiteral("ไม่พบลิงก์"));
    m_translations["Thai"].insert(QStringLiteral("no_locations_found"), QStringLiteral("ไม่พบตำแหน่ง"));

    // UrduPakistan
    m_translations["UrduPakistan"] = {
        {"app_name", "WAPage"}, {"owner_name_label", "آپ کا نام:"}, {"owner_name_placeholder", "اپنا نام درج کریں"},
        {"contact_info", "رابطے کی معلومات"}, {"msg_count", "پیغام کی تعداد"}, {"messages", "پیغامات"}, {"import_date", "درآمد کی تاریخ"},
        {"no_chats", "کوئی چیٹس نہیں ملیں\n\nنئی چیٹ شامل کرنے کے لیے\n+ پر کلک کریں"}, {"light_theme", "ہلکا تھیم"}, {"dark_theme", "گہرا تھیم"},
        {"select_language", "زبان منتخب کریں"}, {"theme", "تھیم"}, {"lock_chat", "چیٹ لاک کریں"}, {"unlock_chat", "چیٹ ان لاک کریں"},
        {"search_messages", "پیغامات تلاش کریں..."}, {"search_chats", "چیٹس تلاش کریں..."}, {"jump_first_msg", "پہلے پیغام پر جائیں"}, {"jump_last_msg", "آخری پیغام پر جائیں"},
        {"jump_first_unread_msg", "پہلے نہ پڑھے گئے پیغام پر جائیں"}, {"jump_to_message", "پیغام پر جائیں"}, {"enter_msg_number", "پیغام نمبر درج کریں (1-{0}):"},
        {"invalid_input", "غلط ان پٹ"}, {"msg_out_of_range", "پیغام حد سے باہر"}, {"cancel", "منسوخ کریں"}, {"ok", "ٹھیک ہے"},
        {"about", "کے بارے میں"}, {"import_chat", "چیٹ درآمد کریں..."}, {"export_chat", "چیٹ برآمد کریں..."}, {"delete_chat", "چیٹ حذف کریں"},
        {"delete_confirm_title", "چیٹ حذف کریں"}, {"delete_confirm_msg", "کیا آپ واقعی \"{0}\" کو حذف کرنا چاہتے ہیں؟ یہ کالعدم نہیں کیا جا سکتا۔"},
        {"jump", "چھلانگ"}, {"import_zip_dialog_title", "WhatsApp ZIP فائل درآمد کریں"}, {"select_zip", "WhatsApp ZIP فائل منتخب کریں..."},
        {"or_drag_drop", "یا یہاں گھسیٹیں اور چھوڑیں"}, {"drop_here", "فائل یہاں چھوڑیں"}, {"importing", "درآمد ہو رہی ہے..."},
        {"success_imported", "کامیابی سے درآمد ہو گیا: {0}"}, {"error_title", "خرابی"}, {"err_open_zip", "ZIP فائل کھولنے میں ناکام"},
        {"err_extract_zip", "ZIP فائل نکالنے میں ناکام"}, {"err_no_txt", "_chat.txt فائل نہیں ملی"}, {"err_empty_txt", "_chat.txt فائل خالی ہے"},
        {"err_parse_txt", "_chat.txt فائل کو پارس کرنے میں ناکام"}, {"close", "بند کریں"}, {"calendar_dialog_title", "تاریخ منتخب کریں"},
        {"pinned_message", "پن شدہ پیغام"}, {"this_message_deleted", "یہ پیغام حذف کر دیا گیا"}, {"audio_unavailable", "آڈیو دستیاب نہیں"},
        {"play_pause", "چلائیں / روکیں"}, {"locked_chats", "مقفل چیٹس"}, {"no_locked_chats", "کوئی مقفل چیٹس نہیں"},
        {"locked_chats_hint", "چیٹ کو لاک کرنے کے لیے 3-ڈاٹ مینو سے 'چیٹ لاک کریں' منتخب کریں"}, {"enter", "داخل ہوں"}
    };
    m_translations["UrduPakistan"].insert(QStringLiteral("media_image"), QStringLiteral("تصویر"));
    m_translations["UrduPakistan"].insert(QStringLiteral("media_video"), QStringLiteral("ویڈیو"));
    m_translations["UrduPakistan"].insert(QStringLiteral("media_voice"), QStringLiteral("صوتی پیغام"));
    m_translations["UrduPakistan"].insert(QStringLiteral("media_audio"), QStringLiteral("آڈیو"));
    m_translations["UrduPakistan"].insert(QStringLiteral("media_sticker"), QStringLiteral("اسٹیکر"));
    m_translations["UrduPakistan"].insert(QStringLiteral("media_document"), QStringLiteral("دستاویز"));
    m_translations["UrduPakistan"].insert(QStringLiteral("media_unavailable"), QStringLiteral("میڈیا دستیاب نہیں"));
    m_translations["UrduPakistan"].insert(QStringLiteral("tap_to_open"), QStringLiteral("کھولنے کے لیے ٹیپ کریں"));
    m_translations["UrduPakistan"].insert(QStringLiteral("location"), QStringLiteral("مقام"));
    m_translations["UrduPakistan"].insert(QStringLiteral("contact"), QStringLiteral("رابطہ"));
    m_translations["UrduPakistan"].insert(QStringLiteral("favorites"), QStringLiteral("پسندیدہ"));
    m_translations["UrduPakistan"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("پسندیدہ میں شامل کریں"));
    m_translations["UrduPakistan"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("پسندیدہ سے ہٹائیں"));
    m_translations["UrduPakistan"].insert(QStringLiteral("no_favorites"), QStringLiteral("کوئی پسندیدہ نہیں"));
    m_translations["UrduPakistan"].insert(QStringLiteral("favorites_hint"), QStringLiteral("پسندیدہ میں شامل کرنے کے لیے پیغام پر دائیں کلک کریں"));
    m_translations["UrduPakistan"].insert(QStringLiteral("media_browser"), QStringLiteral("میڈیا"));
    m_translations["UrduPakistan"].insert(QStringLiteral("media_browser_title"), QStringLiteral("میڈیا"));
    m_translations["UrduPakistan"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("تصاویر، ویڈیوز اور فائلیں"));
    m_translations["UrduPakistan"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("تصاویر"));
    m_translations["UrduPakistan"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("ویڈیوز"));
    m_translations["UrduPakistan"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("دستاویزات"));
    m_translations["UrduPakistan"].insert(QStringLiteral("media_browser_links"), QStringLiteral("لنکس"));
    m_translations["UrduPakistan"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("مقامات"));
    m_translations["UrduPakistan"].insert(QStringLiteral("no_photos_found"), QStringLiteral("کوئی تصاویر نہیں ملیں"));
    m_translations["UrduPakistan"].insert(QStringLiteral("no_videos_found"), QStringLiteral("کوئی ویڈیوز نہیں ملیں"));
    m_translations["UrduPakistan"].insert(QStringLiteral("no_documents_found"), QStringLiteral("کوئی دستاویزات نہیں ملے"));
    m_translations["UrduPakistan"].insert(QStringLiteral("no_links_found"), QStringLiteral("کوئی لنکس نہیں ملے"));
    m_translations["UrduPakistan"].insert(QStringLiteral("no_locations_found"), QStringLiteral("کوئی مقامات نہیں ملے"));

    // Vietnamese
    m_translations["Vietnamese"] = {
        {"app_name", "WAPage"}, {"owner_name_label", "Tên của bạn:"}, {"owner_name_placeholder", "Nhập tên của bạn"},
        {"contact_info", "Thông tin liên hệ"}, {"msg_count", "Số tin nhắn"}, {"messages", "tin nhắn"}, {"import_date", "Ngày nhập"},
        {"no_chats", "Không tìm thấy cuộc trò chuyện\n\nNhấp vào + để thêm\ncuộc trò chuyện mới"}, {"light_theme", "Chủ đề sáng"}, {"dark_theme", "Chủ đề tối"},
        {"select_language", "Chọn ngôn ngữ"}, {"theme", "Chủ đề"}, {"lock_chat", "Khóa cuộc trò chuyện"}, {"unlock_chat", "Mở khóa cuộc trò chuyện"},
        {"search_messages", "Tìm kiếm tin nhắn..."}, {"search_chats", "Tìm kiếm cuộc trò chuyện..."}, {"jump_first_msg", "Đi đến tin nhắn đầu tiên"}, {"jump_last_msg", "Đi đến tin nhắn cuối cùng"},
        {"jump_first_unread_msg", "Đi đến tin nhắn chưa đọc đầu tiên"}, {"jump_to_message", "Đi đến tin nhắn"}, {"enter_msg_number", "Nhập số tin nhắn (1-{0}):"},
        {"invalid_input", "Đầu vào không hợp lệ"}, {"msg_out_of_range", "Tin nhắn ngoài phạm vi"}, {"cancel", "Hủy"}, {"ok", "OK"},
        {"about", "Giới thiệu"}, {"import_chat", "Nhập cuộc trò chuyện..."}, {"export_chat", "Xuất cuộc trò chuyện..."}, {"delete_chat", "Xóa cuộc trò chuyện"},
        {"delete_confirm_title", "Xóa cuộc trò chuyện"}, {"delete_confirm_msg", "Bạn có chắc chắn muốn xóa \"{0}\" không? Hành động này không thể hoàn tác."},
        {"jump", "Nhảy"}, {"import_zip_dialog_title", "Nhập tệp ZIP WhatsApp"}, {"select_zip", "Chọn tệp ZIP WhatsApp..."},
        {"or_drag_drop", "hoặc kéo và thả vào đây"}, {"drop_here", "Thả tệp vào đây"}, {"importing", "Đang nhập..."},
        {"success_imported", "Đã nhập thành công: {0}"}, {"error_title", "Lỗi"}, {"err_open_zip", "Không thể mở tệp ZIP"},
        {"err_extract_zip", "Không thể giải nén tệp ZIP"}, {"err_no_txt", "Không tìm thấy tệp _chat.txt"}, {"err_empty_txt", "Tệp _chat.txt trống"},
        {"err_parse_txt", "Không thể phân tích tệp _chat.txt"}, {"close", "Đóng"}, {"calendar_dialog_title", "Chọn ngày"},
        {"pinned_message", "Tin nhắn đã ghim"}, {"this_message_deleted", "Tin nhắn này đã bị xóa"}, {"audio_unavailable", "Âm thanh không khả dụng"},
        {"play_pause", "Phát / Tạm dừng"}, {"locked_chats", "Cuộc trò chuyện đã khóa"}, {"no_locked_chats", "Không có cuộc trò chuyện đã khóa"},
        {"locked_chats_hint", "Chọn 'Khóa cuộc trò chuyện' từ menu 3 chấm để khóa cuộc trò chuyện"}, {"enter", "Vào"}
    };
    m_translations["Vietnamese"].insert(QStringLiteral("media_image"), QStringLiteral("Ảnh"));
    m_translations["Vietnamese"].insert(QStringLiteral("media_video"), QStringLiteral("Video"));
    m_translations["Vietnamese"].insert(QStringLiteral("media_voice"), QStringLiteral("Tin nhắn thoại"));
    m_translations["Vietnamese"].insert(QStringLiteral("media_audio"), QStringLiteral("Âm thanh"));
    m_translations["Vietnamese"].insert(QStringLiteral("media_sticker"), QStringLiteral("Nhãn dán"));
    m_translations["Vietnamese"].insert(QStringLiteral("media_document"), QStringLiteral("Tài liệu"));
    m_translations["Vietnamese"].insert(QStringLiteral("media_unavailable"), QStringLiteral("Phương tiện không khả dụng"));
    m_translations["Vietnamese"].insert(QStringLiteral("tap_to_open"), QStringLiteral("Nhấn để mở"));
    m_translations["Vietnamese"].insert(QStringLiteral("location"), QStringLiteral("Vị trí"));
    m_translations["Vietnamese"].insert(QStringLiteral("contact"), QStringLiteral("Liên hệ"));
    m_translations["Vietnamese"].insert(QStringLiteral("favorites"), QStringLiteral("Yêu thích"));
    m_translations["Vietnamese"].insert(QStringLiteral("add_to_favorites"), QStringLiteral("Thêm vào yêu thích"));
    m_translations["Vietnamese"].insert(QStringLiteral("remove_from_favorites"), QStringLiteral("Xóa khỏi yêu thích"));
    m_translations["Vietnamese"].insert(QStringLiteral("no_favorites"), QStringLiteral("Không có yêu thích"));
    m_translations["Vietnamese"].insert(QStringLiteral("favorites_hint"), QStringLiteral("Nhấp chuột phải vào tin nhắn để thêm vào yêu thích"));
    m_translations["Vietnamese"].insert(QStringLiteral("media_browser"), QStringLiteral("Phương tiện"));
    m_translations["Vietnamese"].insert(QStringLiteral("media_browser_title"), QStringLiteral("Phương tiện"));
    m_translations["Vietnamese"].insert(QStringLiteral("media_browser_subtitle"), QStringLiteral("Ảnh, video và tệp"));
    m_translations["Vietnamese"].insert(QStringLiteral("media_browser_photos"), QStringLiteral("Ảnh"));
    m_translations["Vietnamese"].insert(QStringLiteral("media_browser_videos"), QStringLiteral("Video"));
    m_translations["Vietnamese"].insert(QStringLiteral("media_browser_documents"), QStringLiteral("Tài liệu"));
    m_translations["Vietnamese"].insert(QStringLiteral("media_browser_links"), QStringLiteral("Liên kết"));
    m_translations["Vietnamese"].insert(QStringLiteral("media_browser_locations"), QStringLiteral("Vị trí"));
    m_translations["Vietnamese"].insert(QStringLiteral("no_photos_found"), QStringLiteral("Không tìm thấy ảnh"));
    m_translations["Vietnamese"].insert(QStringLiteral("no_videos_found"), QStringLiteral("Không tìm thấy video"));
    m_translations["Vietnamese"].insert(QStringLiteral("no_documents_found"), QStringLiteral("Không tìm thấy tài liệu"));
    m_translations["Vietnamese"].insert(QStringLiteral("no_links_found"), QStringLiteral("Không tìm thấy liên kết"));
    m_translations["Vietnamese"].insert(QStringLiteral("no_locations_found"), QStringLiteral("Không tìm thấy vị trí"));
}

// ─────────────────────────────────────────────────────────────────────────────
// translateSystemMessage
//
// Input:  a normalised token produced by ChatParser, e.g.
//           "__sys:added:Alice:Bob"
//           "__sys:created_group:Alice:Family Chat"
//           "__sys:disappear_on:Alice:7 Days"
//           "__sys:voice_call:41 sec:2"
// Output: localised, human-readable sentence.
//
// Token format:  __sys:<key>:<p0>:<p1>:...
// Parameters keep their original value (names, numbers) – only the
// surrounding words are translated.
// ─────────────────────────────────────────────────────────────────────────────
