#include "LanguageManager.h"
#include <QLocale>
#include <QDateTime>
#include <QRegularExpression>
#include <QSet>

LanguageManager::LanguageManager(QObject* parent)
    : QObject(parent)
{
    initTranslations();
    initSystemTranslations();
}

void LanguageManager::setCurrentLanguage(const QString& lang)
{
    if (m_currentLang != lang && m_translations.contains(lang)) {
        m_currentLang = lang;
        emit languageChanged();
    }
}

QString LanguageManager::tr(const QString& key) const
{
    if (!m_translations.contains(m_currentLang)) return key;
    return m_translations[m_currentLang].value(key, key);
}

QString LanguageManager::getLanguageName(const QString& code) const
{
    return m_langNames.value(code, code);
}

QVariantMap LanguageManager::currentTranslations() const
{
    QVariantMap map;
    if (m_translations.contains(m_currentLang)) {
        const auto& langMap = m_translations[m_currentLang];
        for (auto it = langMap.constBegin(); it != langMap.constEnd(); ++it) {
            map.insert(it.key(), it.value());
        }
    }
    return map;
}

QString LanguageManager::formatDate(const QDateTime& dt) const
{
    if (!dt.isValid()) return "";

    const QString format = "d MMMM yyyy";
    
    static const QMap<QString, QLocale> localeMap = {
        {"Azerbaijani", QLocale(QLocale::Azerbaijani)},
        {"Turkish",     QLocale(QLocale::Turkish)},
        {"English",     QLocale(QLocale::English)},
        {"Spanish",     QLocale(QLocale::Spanish)},
        {"Portuguese",  QLocale(QLocale::Portuguese)},
        {"Russian",     QLocale(QLocale::Russian)},
        {"Italian",     QLocale(QLocale::Italian)},
        {"Arabic",      QLocale(QLocale::Arabic)},
        {"French",      QLocale(QLocale::French)},
        {"German",      QLocale(QLocale::German)},
        {"Chinese",     QLocale(QLocale::Chinese)},
        {"Hindi",       QLocale(QLocale::Hindi)},
        {"Japanese",    QLocale(QLocale::Japanese)},
        {"Korean",      QLocale(QLocale::Korean)},
        {"Mongolian",   QLocale(QLocale::Mongolian)},
        {"Polish",      QLocale(QLocale::Polish)},
        {"Ukrainian",   QLocale(QLocale::Ukrainian)},
        {"Uzbek",       QLocale(QLocale::Uzbek)}
    };

    const QLocale locale = localeMap.value(m_currentLang, QLocale::system());
    QString formatted = locale.toString(dt.date(), format);

    // Capitalize the first letter of the month name (e.g.: "1 april 2026" -> "1 April 2026").
    const int firstSpace = formatted.indexOf(' ');
    const int lastSpace  = formatted.lastIndexOf(' ');
    if (firstSpace > 0 && lastSpace > firstSpace + 1) {
        QString month = formatted.mid(firstSpace + 1, lastSpace - firstSpace - 1);
        if (!month.isEmpty()) {
            month = locale.toUpper(month.left(1)) + month.mid(1);
            formatted = formatted.left(firstSpace + 1) + month + formatted.mid(lastSpace);
        }
    }

    return formatted;
}

void LanguageManager::initTranslations()
{
    m_langNames = {
        {"Azerbaijani", "Azərbaycan"},
        {"Turkish",     "Türkçe"},
        {"English",     "English"},
        {"Spanish",     "Español"},
        {"Portuguese",  "Português"},
        {"Russian",     "Русский"},
        {"Italian",     "Italiano"},
        {"Arabic",      "العربية"},
        {"French",      "Français"},
        {"German",      "Deutsch"},
        {"Chinese",     "简体中文"},
        {"Hindi",       "हिन्दी"},
        {"Japanese",    "日本語"},
        {"Korean",      "한국어"},
        {"Mongolian",   "Монгол"},
        {"Polish",      "Polski"},
        {"Ukrainian",   "Українська"},
        {"Uzbek",       "O'zbek"}
    };

    // Azerbaijani
    m_translations["Azerbaijani"] = {
        {"contact_info", "Kontakt məlumatı"}, {"msg_count", "Mesaj sayı"}, {"messages", "mesaj"}, {"import_date", "Daxiletmə tarixi"},
        {"no_chats", "Söhbət yoxdur\n\n+ düyməsinə basaraq\nyeni söhbət əlavə edin"}, {"light_theme", "İşıq tema"}, {"dark_theme", "Tünd tema"},
        {"new_chat_tooltip", "Yeni söhbət əlavə et"}, {"chat_search_placeholder", "Söhbətdə axtar"}, {"importing", "Daxil edilir..."},
        {"import_new", "Yeni söhbət əlavə et"}, {"zip_description", "WAPage-dan export etdiyiniz ZIP faylını seçin."},
        {"select_zip", "ZIP fayl seç"}, {"change_zip", "Başqa fayl seç"}, {"continue", "Davam et"},
        {"owner_question", "Söhbətdə sizin adınız nədir?\n(WAPage hesabınızda görünən ad)"}, {"owner_placeholder", "Məs: Mahmud Bayramov"},
        {"import_btn", "Daxil et"}, {"back", "Geri"}, {"loading_messages", "Mesajlar yüklənir, lütfən gözləyin..."},
        {"select_zip_title", "WAPage ZIP faylı seçin"}, {"first_message", "İlk mesaj"}, {"delete_chat", "Söhbəti sil"}, {"search", "Axtar..."},
        {"empty_chat_hint", "Söhbət seçin və ya yeni söhbət əlavə edin"}, {"delete_confirm_title", "Söhbəti sil"},
        {"delete_confirm_text", "Bu söhbəti silmək istədiyinizdən əminsiniz?\nBütün mesajlar silinəcək."}, {"no_results", "Nəticə tapılmadı"},
        {"yes", "Bəli"}, {"no", "Xeyr"}, {"language", "Dil"}, {"select_language", "Dil seçin"}, {"profile_photo", "Profil şəkli"},
        {"name_label", "Ad"}, {"participants_label", "Qrup iştirakçıları"}, {"contact_name_placeholder", "Kontakt adı"}, {"image_files_filter", "Şəkil faylları (*.jpg *.jpeg *.png *.webp)"},
        {"my_profile", "Mənim profilim"}, {"import_success", "%1 — %2 mesaj daxil edildi"}, {"conversation", "Söhbət"},
        {"open_system", "Sistemdə aç"}, {"image_not_found", "Şəkil tapılmadı"}, {"video", "Video"}, {"deleted_message", "Bu mesaj silindi"}, {"you_deleted_message", "Siz bu mesajı sildiniz"}, {"edited", "Redaktə edildi"}, {"app_version", "versiya"}, {"app_copyright", "Müəllif hüququ %1 tərəfindən"}
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

    // English
    m_translations["English"] = {
        {"contact_info", "Contact info"}, {"msg_count", "Messages"}, {"messages", "messages"}, {"import_date", "Import date"},
        {"no_chats", "No chats found\n\nClick + to add\na new chat"}, {"light_theme", "Light theme"}, {"dark_theme", "Dark theme"},
        {"new_chat_tooltip", "Add new chat"}, {"chat_search_placeholder", "Search in chats"}, {"importing", "Importing..."},
        {"import_new", "Add new chat"}, {"zip_description", "Select the ZIP file exported from WAPage."},
        {"select_zip", "Select ZIP file"}, {"change_zip", "Change file"}, {"continue", "Continue"},
        {"owner_question", "What is your name in the chat?\n(The name appearing in your WAPage account)"}, {"owner_placeholder", "Ex: John Doe"},
        {"import_btn", "Import"}, {"back", "Back"}, {"loading_messages", "Loading messages, please wait..."},
        {"select_zip_title", "Select WAPage ZIP file"}, {"first_message", "First message"}, {"delete_chat", "Delete chat"}, {"search", "Search..."},
        {"empty_chat_hint", "Select a chat or add a new one"}, {"delete_confirm_title", "Delete chat"},
        {"delete_confirm_text", "Are you sure you want to delete this chat?\nAll messages will be removed."}, {"no_results", "No results found"},
        {"yes", "Yes"}, {"no", "No"}, {"language", "Language"}, {"select_language", "Select language"}, {"profile_photo", "Profile photo"},
        {"name_label", "Name"}, {"participants_label", "Group participants"}, {"contact_name_placeholder", "Contact name"}, {"image_files_filter", "Image files (*.jpg *.jpeg *.png *.webp)"},
        {"my_profile", "My Profile"}, {"import_success", "%1 — %2 messages imported"}, {"conversation", "Conversation"},
        {"open_system", "Open in system"}, {"image_not_found", "Image not found"}, {"video", "Video"}, {"deleted_message", "This message was deleted"}, {"you_deleted_message", "You deleted this message"}, {"edited", "Edited"}, {"app_version", "version"}, {"app_copyright", "Copyright by %1"}
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

    // Turkish
    m_translations["Turkish"] = {
        {"contact_info", "Kişi bilgisi"}, {"msg_count", "Mesaj sayısı"}, {"messages", "mesaj"}, {"import_date", "İçe aktarma tarihi"},
        {"no_chats", "Sohbet bulunamadı\n\n+ butonuna basarak\nyeni sohbet ekleyin"}, {"light_theme", "Aydınlık tema"}, {"dark_theme", "Karanlık tema"},
        {"new_chat_tooltip", "Yeni sohbet ekle"}, {"chat_search_placeholder", "Sohbetlerde ara"}, {"importing", "İçe aktarılıyor..."},
        {"import_new", "Yeni sohbet ekle"}, {"zip_description", "WAPage'tan dışa aktarılan ZIP dosyasını seçin."},
        {"select_zip", "ZIP seç"}, {"change_zip", "Dosyayı değiştir"}, {"continue", "Devam et"},
        {"owner_question", "Sohbetteki adınız nedir?\n(WAPage hesabınızda görünen ad)"}, {"owner_placeholder", "Örn: Ahmet Yılmaz"},
        {"import_btn", "İçe aktar"}, {"back", "Geri"}, {"loading_messages", "Mesajlar yükleniyor, lütfen bekleyin..."},
        {"select_zip_title", "WAPage ZIP dosyası seçin"}, {"first_message", "İlk mesaj"}, {"delete_chat", "Sohbeti sil"}, {"search", "Ara..."},
        {"empty_chat_hint", "Bir sohbet seçin veya yeni birini ekleyin"}, {"delete_confirm_title", "Sohbeti sil"},
        {"delete_confirm_text", "Bu sohbeti silmek istediğinizden emin misiniz?\nTüm mesajlar silinecektir."}, {"no_results", "Sonuç bulunamadı"},
        {"yes", "Evet"}, {"no", "Hayır"}, {"language", "Dil"}, {"select_language", "Dil seçin"}, {"profile_photo", "Profil fotoğrafı"},
        {"name_label", "Ad"}, {"participants_label", "Grup katılımcıları"}, {"contact_name_placeholder", "Kişi adı"}, {"image_files_filter", "Görsel dosyaları (*.jpg *.jpeg *.png *.webp)"},
        {"my_profile", "Profilim"}, {"import_success", "%1 — %2 mesaj içe aktarıldı"}, {"conversation", "Sohbet"},
        {"open_system", "Sistemde aç"}, {"image_not_found", "Resim bulunamadı"}, {"video", "Video"}, {"deleted_message", "Bu mesaj silindi"}, {"you_deleted_message", "Bu mesajı siz sildiniz"}, {"edited", "Düzenlendi"}, {"app_version", "sürüm"}, {"app_copyright", "Telif hakkı %1 tarafından"}
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

    // Arabic
    m_translations["Arabic"] = {
        {"contact_info", "معلومات الاتصال"}, {"msg_count", "عدد الرسائل"}, {"messages", "رسائل"}, {"import_date", "تاريخ الاستيراد"},
        {"no_chats", "لم يتم العثور على دردشات\n\nانقر فوق + لإضافة\nدردشة جديدة"}, {"light_theme", "مظهر فاتح"}, {"dark_theme", "مظهر داكن"},
        {"new_chat_tooltip", "إضافة دردشة جديدة"}, {"chat_search_placeholder", "البحث في الدردشات"}, {"importing", "جارٍ الاستيراد..."},
        {"import_new", "إضافة دردشة جديدة"}, {"zip_description", "حدد ملف ZIP المصدر من WAPage."},
        {"select_zip", "حدد ملف ZIP"}, {"change_zip", "تغيير الملف"}, {"continue", "استمرار"},
        {"owner_question", "ما اسمك في الدردشة؟\n(الاسم الذي يظهر في حساب WAPage الخاص بك)"}, {"owner_placeholder", "مثال: محمد علي"},
        {"import_btn", "استيراد"}, {"back", "رجوع"}, {"loading_messages", "جارٍ تحميل الرسائل، يرجى الانتظار..."},
        {"select_zip_title", "حدد ملف WAPage ZIP"}, {"first_message", "أول رسالة"}, {"delete_chat", "حذف الدردشة"}, {"search", "بحث..."},
        {"empty_chat_hint", "حدد دردشة أو أضف واحدة جديدة"}, {"delete_confirm_title", "حذف الدردشة"},
        {"delete_confirm_text", "هل أنت متأكد أنك تريد حذف هذه الدردشة؟\nسيتم حذف جميع الرسائل."}, {"no_results", "لم يتم العثور على نتائج"},
        {"yes", "نعم"}, {"no", "لا"}, {"language", "اللغة"}, {"select_language", "اختر اللغة"}, {"profile_photo", "صورة الملف الشخصي"},
        {"name_label", "الاسم"}, {"participants_label", "أعضاء المجموعة"}, {"contact_name_placeholder", "اسم جهة الاتصال"}, {"image_files_filter", "ملفات الصور (*.jpg *.jpeg *.png *.webp)"},
        {"my_profile", "ملف شخصي"}, {"import_success", "%1 — تم استيراد %2 رسالة"}, {"conversation", "محادثة"},
        {"open_system", "فتح في النظام"}, {"image_not_found", "الصورة غير موجودة"}, {"video", "فيديو"}, {"deleted_message", "تم حذف هذه الرسالة"}, {"you_deleted_message", "لقد حذفت هذه الرسالة"}, {"edited", "تم تعديله"}, {"app_version", "إصدار"}, {"app_copyright", "حقوق النشر محفوظة لـ %1"}
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

    // Russian
    m_translations["Russian"] = {
        {"contact_info", "Данные контакта"}, {"msg_count", "Сообщения"}, {"messages", "сообщений"}, {"import_date", "Дата импорта"},
        {"no_chats", "Чаты не найдены\n\nНажмите +, чтобы добавить\nновый чат"}, {"light_theme", "Светлая тема"}, {"dark_theme", "Темная тема"},
        {"new_chat_tooltip", "Добавить новый чат"}, {"chat_search_placeholder", "Поиск в чатах"}, {"importing", "Импорт..."},
        {"import_new", "Добавить новый чат"}, {"zip_description", "Выберите ZIP-файл, экспортированный из WAPage."},
        {"select_zip", "Выбрать ZIP"}, {"change_zip", "Изменить файл"}, {"continue", "Продолжить"},
        {"owner_question", "Как вас зовут в чате?\n(Имя в вашем аккаунте WAPage)"}, {"owner_placeholder", "Напр: Иван Иванов"},
        {"import_btn", "Импорт"}, {"back", "Назад"}, {"loading_messages", "Загрузка сообщений, подождите..."},
        {"select_zip_title", "Выберите ZIP-файл WAPage"}, {"first_message", "Первое сообщение"}, {"delete_chat", "Удалить чат"}, {"search", "Поиск..."},
        {"empty_chat_hint", "Выберите чат или добавьте новый"}, {"delete_confirm_title", "Удалить чат"},
        {"delete_confirm_text", "Вы уверены, что хотите удалить этот чат?\nВсе сообщения будут удалены."}, {"no_results", "Результатов не найдено"},
        {"yes", "Да"}, {"no", "Нет"}, {"language", "Язык"}, {"select_language", "Выберите язык"}, {"profile_photo", "Фото профиля"},
        {"name_label", "Имя"}, {"participants_label", "Участники группы"}, {"contact_name_placeholder", "Имя контакта"}, {"image_files_filter", "Файлы изображений (*.jpg *.jpeg *.png *.webp)"},
        {"my_profile", "Мой профиль"}, {"import_success", "%1 — импортировано %2 сообщ."}, {"conversation", "Беседа"},
        {"open_system", "Открыть в системе"}, {"image_not_found", "Изображение не найдено"}, {"video", "Видео"}, {"deleted_message", "Это сообщение удалено"}, {"you_deleted_message", "Вы удалили это сообщение"}, {"edited", "Изменено"}, {"app_version", "версия"}, {"app_copyright", "Авторские права принадлежат %1"}
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

    // Spanish
    m_translations["Spanish"] = {
        {"contact_info", "Info. contacto"}, {"msg_count", "Mensajes"}, {"messages", "mensajes"}, {"import_date", "Fecha imp."},
        {"no_chats", "No hay chats"}, {"light_theme", "Tema claro"}, {"dark_theme", "Tema oscuro"},
        {"new_chat_tooltip", "Nuevo chat"}, {"chat_search_placeholder", "Buscar chats"}, {"importing", "Importando..."},
        {"import_new", "Añadir chat"}, {"zip_description", "Seleccione el archivo ZIP de WAPage."},
        {"select_zip", "Seleccionar ZIP"}, {"change_zip", "Cambiar archivo"}, {"continue", "Continuar"},
        {"owner_question", "¿Cuál es tu nombre?"}, {"owner_placeholder", "Ej: Juan Pérez"},
        {"import_btn", "Importar"}, {"back", "Atrás"}, {"loading_messages", "Cargando..."},
        {"select_zip_title", "Seleccionar ZIP de WAPage"}, {"first_message", "Primer mensaje"}, {"delete_chat", "Eliminar chat"}, {"search", "Buscar..."},
        {"empty_chat_hint", "Selecciona un chat"}, {"delete_confirm_title", "Eliminar"},
        {"delete_confirm_text", "¿Eliminar chat?"}, {"no_results", "Sin resultados"},
        {"yes", "Sí"}, {"no", "No"}, {"language", "Idioma"}, {"select_language", "Idioma"}, {"profile_photo", "Foto"},
        {"name_label", "Nombre"}, {"participants_label", "Participantes del grupo"}, {"contact_name_placeholder", "Nombre del contacto"}, {"image_files_filter", "Archivos de imagen (*.jpg *.jpeg *.png *.webp)"},
        {"my_profile", "Mi perfil"}, {"import_success", "%1 — %2 mensajes importados"}, {"conversation", "Conversación"},
        {"open_system", "Abrir en sistema"}, {"image_not_found", "Imagen no encontrada"}, {"video", "Video"}, {"deleted_message", "Este mensaje fue eliminado"}, {"you_deleted_message", "Eliminaste este mensaje"}, {"edited", "Editado"}, {"app_version", "versión"}, {"app_copyright", "Derechos de autor de %1"}
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

    // Portuguese
    m_translations["Portuguese"] = {
        {"contact_info", "Dados contato"}, {"msg_count", "Mensagens"}, {"messages", "mensagens"}, {"import_date", "Data imp."},
        {"no_chats", "Sem conversas"}, {"light_theme", "Tema claro"}, {"dark_theme", "Tema escuro"},
        {"new_chat_tooltip", "Nova conversa"}, {"chat_search_placeholder", "Pesquisar"}, {"importing", "Importando..."},
        {"import_new", "Nova conversa"}, {"zip_description", "Selecione o arquivo ZIP."},
        {"select_zip", "Selecionar ZIP"}, {"change_zip", "Mudar arquivo"}, {"continue", "Continuar"},
        {"owner_question", "Qual seu nome?"}, {"owner_placeholder", "Ex: Maria"},
        {"import_btn", "Importar"}, {"back", "Voltar"}, {"loading_messages", "Carregando..."},
        {"select_zip_title", "Selecionar ZIP do WAPage"}, {"first_message", "Primeira mensagem"}, {"delete_chat", "Apagar chat"}, {"search", "Pesquisar..."},
        {"empty_chat_hint", "Selecione uma conversa"}, {"delete_confirm_title", "Apagar"},
        {"delete_confirm_text", "Apagar conversa?"}, {"no_results", "Sem resultados"},
        {"yes", "Sim"}, {"no", "Não"}, {"language", "Idioma"}, {"select_language", "Idioma"}, {"profile_photo", "Foto"},
        {"name_label", "Nome"}, {"participants_label", "Participantes do grupo"}, {"contact_name_placeholder", "Nome do contato"}, {"image_files_filter", "Arquivos de imagem (*.jpg *.jpeg *.png *.webp)"},
        {"my_profile", "Meu perfil"}, {"import_success", "%1 — %2 mensagens importadas"}, {"conversation", "Conversa"},
        {"open_system", "Abrir no sistema"}, {"image_not_found", "Imagem não encontrada"}, {"video", "Vídeo"}, {"deleted_message", "Esta mensagem foi apagada"}, {"you_deleted_message", "Você apagou esta mensagem"}, {"edited", "Editado"}, {"app_version", "versão"}, {"app_copyright", "Direitos autorais de %1"}
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

    // Italian
    m_translations["Italian"] = {
        {"contact_info", "Info contatto"}, {"msg_count", "Messaggi"}, {"messages", "messaggi"}, {"import_date", "Data imp."},
        {"no_chats", "Nessuna chat"}, {"light_theme", "Tema chiaro"}, {"dark_theme", "Tema scuro"},
        {"new_chat_tooltip", "Nuova chat"}, {"chat_search_placeholder", "Cerca"}, {"importing", "Importazione..."},
        {"import_new", "Nuova chat"}, {"zip_description", "Seleziona il file ZIP."},
        {"select_zip", "Seleziona ZIP"}, {"change_zip", "Cambia file"}, {"continue", "Continua"},
        {"owner_question", "Come ti chiami?"}, {"owner_placeholder", "Es: Mario"},
        {"import_btn", "Importa"}, {"back", "Indietro"}, {"loading_messages", "Caricamento..."},
        {"select_zip_title", "Seleziona ZIP WAPage"}, {"first_message", "Primo messaggio"}, {"delete_chat", "Elimina chat"}, {"search", "Cerca..."},
        {"empty_chat_hint", "Seleziona una chat"}, {"delete_confirm_title", "Elimina"},
        {"delete_confirm_text", "Eliminare chat?"}, {"no_results", "Nessun risultato"},
        {"yes", "Sì"}, {"no", "No"}, {"language", "Lingua"}, {"select_language", "Lingua"}, {"profile_photo", "Foto"},
        {"name_label", "Nome"}, {"participants_label", "Partecipanti del gruppo"}, {"contact_name_placeholder", "Nome contatto"}, {"image_files_filter", "File immagine (*.jpg *.jpeg *.png *.webp)"},
        {"my_profile", "Il mio profilo"}, {"import_success", "%1 — %2 messaggi importati"}, {"conversation", "Conversazione"},
        {"open_system", "Apri nel sistema"}, {"image_not_found", "Immagine non trovata"}, {"video", "Video"}, {"deleted_message", "Questo messaggio è stato eliminato"}, {"you_deleted_message", "Hai eliminato questo messaggio"}, {"edited", "Modificato"}, {"app_version", "versione"}, {"app_copyright", "Copyright di %1"}
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

    // French
    m_translations["French"] = {
        {"contact_info", "Infos contact"}, {"msg_count", "Messages"}, {"messages", "messages"}, {"import_date", "Date imp."},
        {"no_chats", "Aucun chat"}, {"light_theme", "Thème clair"}, {"dark_theme", "Thème sombre"},
        {"new_chat_tooltip", "Nouveau chat"}, {"chat_search_placeholder", "Rechercher"}, {"importing", "Importation..."},
        {"import_new", "Nouveau chat"}, {"zip_description", "Sélectionnez le fichier ZIP."},
        {"select_zip", "Choisir ZIP"}, {"change_zip", "Changer"}, {"continue", "Continuer"},
        {"owner_question", "Votre nom?"}, {"owner_placeholder", "Ex: Jean"},
        {"import_btn", "Importer"}, {"back", "Retour"}, {"loading_messages", "Chargement..."},
        {"select_zip_title", "Sélectionner ZIP WAPage"}, {"first_message", "Premier message"}, {"delete_chat", "Supprimer"}, {"search", "Chercher..."},
        {"empty_chat_hint", "Choisir un chat"}, {"delete_confirm_title", "Supprimer"},
        {"delete_confirm_text", "Supprimer le chat?"}, {"no_results", "Aucun résultat"},
        {"yes", "Oui"}, {"no", "Non"}, {"language", "Langue"}, {"select_language", "Langue"}, {"profile_photo", "Photo"},
        {"name_label", "Nom"}, {"participants_label", "Participants du groupe"}, {"contact_name_placeholder", "Nom du contact"}, {"image_files_filter", "Fichiers image (*.jpg *.jpeg *.png *.webp)"},
        {"my_profile", "Mon profil"}, {"import_success", "%1 — %2 messages importés"}, {"conversation", "Conversation"},
        {"open_system", "Ouvrir dans le système"}, {"image_not_found", "Image introuvable"}, {"video", "Vidéo"}, {"deleted_message", "Ce message a été supprimé"}, {"you_deleted_message", "Vous avez supprimé ce message"}, {"edited", "Modifié"}, {"app_version", "version"}, {"app_copyright", "Droits d'auteur par %1"}
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

    // German
    m_translations["German"] = {
        {"contact_info", "Kontaktinfo"}, {"msg_count", "Nachrichten"}, {"messages", "Nachrichten"}, {"import_date", "Datum"},
        {"no_chats", "Keine Chats"}, {"light_theme", "Hell"}, {"dark_theme", "Dunkel"},
        {"new_chat_tooltip", "Neuer Chat"}, {"chat_search_placeholder", "Suchen"}, {"importing", "Import..."},
        {"import_new", "Neuer Chat"}, {"zip_description", "ZIP-Datei wählen."},
        {"select_zip", "ZIP wählen"}, {"change_zip", "Ändern"}, {"continue", "Weiter"},
        {"owner_question", "Ihr Name?"}, {"owner_placeholder", "Z.B. Max"},
        {"import_btn", "Importieren"}, {"back", "Zurück"}, {"loading_messages", "Laden..."},
        {"select_zip_title", "ZIP auswählen"}, {"first_message", "Erste Nachricht"}, {"delete_chat", "Löschen"}, {"search", "Suchen..."},
        {"empty_chat_hint", "Chat wählen"}, {"delete_confirm_title", "Löschen"},
        {"delete_confirm_text", "Chat löschen?"}, {"no_results", "Keine Ergebnisse"},
        {"yes", "Ja"}, {"no", "Nein"}, {"language", "Sprache"}, {"select_language", "Sprache"}, {"profile_photo", "Foto"},
        {"name_label", "Name"}, {"participants_label", "Gruppenteilnehmer"}, {"contact_name_placeholder", "Kontaktname"}, {"image_files_filter", "Bilddateien (*.jpg *.jpeg *.png *.webp)"},
        {"my_profile", "Mein Profil"}, {"import_success", "%1 — %2 Nachrichten importiert"}, {"conversation", "Unterhaltung"},
        {"open_system", "Im System öffnen"}, {"image_not_found", "Bild nicht gefunden"}, {"video", "Video"}, {"deleted_message", "Diese Nachricht wurde gelöscht"}, {"you_deleted_message", "Du hast diese Nachricht gelöscht"}, {"edited", "Bearbeitet"}, {"app_version", "Version"}, {"app_copyright", "Urheberrecht von %1"}
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

    // Chinese
    m_translations["Chinese"] = {
        {"contact_info", "信息"}, {"msg_count", "消息"}, {"messages", "消息"}, {"import_date", "日期"},
        {"no_chats", "没有聊天"}, {"light_theme", "浅色"}, {"dark_theme", "深色"},
        {"new_chat_tooltip", "新聊天"}, {"chat_search_placeholder", "搜索"}, {"importing", "导入中..."},
        {"import_new", "新聊天"}, {"zip_description", "选择 ZIP 文件。"},
        {"select_zip", "选择 ZIP"}, {"change_zip", "更改"}, {"continue", "继续"},
        {"owner_question", "您叫什么名字？"}, {"owner_placeholder", "例如：张三"},
        {"import_btn", "导入"}, {"back", "返回"}, {"loading_messages", "正在加载..."},
        {"select_zip_title", "选择 ZIP 文件"}, {"first_message", "第一条消息"}, {"delete_chat", "删除"}, {"search", "搜索..."},
        {"empty_chat_hint", "选择聊天"}, {"delete_confirm_title", "删除"},
        {"delete_confirm_text", "删除聊天？"}, {"no_results", "没有结果"},
        {"yes", "是"}, {"no", "否"}, {"language", "语言"}, {"select_language", "语言"}, {"profile_photo", "照片"},
        {"name_label", "名称"}, {"participants_label", "群成员"}, {"contact_name_placeholder", "联系人名称"}, {"image_files_filter", "图片文件 (*.jpg *.jpeg *.png *.webp)"},
        {"my_profile", "我的个人资料"}, {"import_success", "%1 — 已导入 %2 条消息"}, {"conversation", "对话"},
        {"open_system", "在系统中打开"}, {"image_not_found", "图像未找到"}, {"video", "视频"}, {"deleted_message", "此消息已删除"}, {"you_deleted_message", "你删除了此消息"}, {"edited", "已编辑"}, {"app_version", "版本"}, {"app_copyright", "版权所有 %1"}
    };
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

    // Hindi
    m_translations["Hindi"] = {
        {"contact_info", "संपर्क जानकारी"}, {"msg_count", "संदेश संख्या"}, {"messages", "संदेश"}, {"import_date", "इम्पोर्ट तिथि"},
        {"no_chats", "कोई चैट नहीं मिली\n\nनई चैट जोड़ने के लिए\n+ दबाएँ"}, {"light_theme", "लाइट थीम"}, {"dark_theme", "डार्क थीम"},
        {"new_chat_tooltip", "नई चैट जोड़ें"}, {"chat_search_placeholder", "चैट में खोजें"}, {"importing", "इम्पोर्ट हो रहा है..."},
        {"import_new", "नई चैट जोड़ें"}, {"zip_description", "WAPage से एक्सपोर्ट की गई ZIP फ़ाइल चुनें।"},
        {"select_zip", "ZIP चुनें"}, {"change_zip", "फ़ाइल बदलें"}, {"continue", "जारी रखें"},
        {"owner_question", "चैट में आपका नाम क्या है?\n(जो नाम आपके WAPage खाते में दिखता है)"}, {"owner_placeholder", "उदा: राहुल शर्मा"},
        {"import_btn", "इम्पोर्ट करें"}, {"back", "वापस"}, {"loading_messages", "संदेश लोड हो रहे हैं, कृपया प्रतीक्षा करें..."},
        {"select_zip_title", "WAPage ZIP फ़ाइल चुनें"}, {"first_message", "पहला संदेश"}, {"delete_chat", "चैट हटाएँ"}, {"search", "खोजें..."},
        {"empty_chat_hint", "एक चैट चुनें या नई चैट जोड़ें"}, {"delete_confirm_title", "चैट हटाएँ"},
        {"delete_confirm_text", "क्या आप वाकई इस चैट को हटाना चाहते हैं?\nसभी संदेश हट जाएँगे।"}, {"no_results", "कोई परिणाम नहीं मिला"},
        {"yes", "हाँ"}, {"no", "नहीं"}, {"language", "भाषा"}, {"select_language", "भाषा चुनें"}, {"profile_photo", "प्रोफ़ाइल फ़ोटो"},
        {"name_label", "नाम"}, {"participants_label", "समूह सदस्य"}, {"contact_name_placeholder", "संपर्क नाम"}, {"image_files_filter", "छवि फ़ाइलें (*.jpg *.jpeg *.png *.webp)"},
        {"my_profile", "मेरी प्रोफ़ाइल"}, {"import_success", "%1 — %2 संदेश इम्पोर्ट हुए"}, {"conversation", "वार्तालाप"},
        {"open_system", "सिस्टम में खोलें"}, {"image_not_found", "चित्र नहीं मिला"}, {"video", "वीडियो"}, {"deleted_message", "यह संदेश हटाया गया"}, {"you_deleted_message", "आपने यह संदेश हटाया"}, {"edited", "संपादित"}, {"app_version", "संस्करण"}, {"app_copyright", "कॉपीराइट %1 द्वारा"}
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

    // Japanese
    m_translations["Japanese"] = {
        {"contact_info", "連絡先情報"}, {"msg_count", "メッセージ数"}, {"messages", "件"}, {"import_date", "インポート日"},
        {"no_chats", "チャットがありません\n\n+ を押して\n新しいチャットを追加"}, {"light_theme", "ライトテーマ"}, {"dark_theme", "ダークテーマ"},
        {"new_chat_tooltip", "新しいチャットを追加"}, {"chat_search_placeholder", "チャットを検索"}, {"importing", "インポート中..."},
        {"import_new", "新しいチャットを追加"}, {"zip_description", "WAPage からエクスポートした ZIP ファイルを選択してください。"},
        {"select_zip", "ZIPを選択"}, {"change_zip", "ファイルを変更"}, {"continue", "続行"},
        {"owner_question", "チャットでのあなたの名前は？\n（WAPage アカウントに表示される名前）"}, {"owner_placeholder", "例: 山田 太郎"},
        {"import_btn", "インポート"}, {"back", "戻る"}, {"loading_messages", "メッセージを読み込み中です。お待ちください..."},
        {"select_zip_title", "WAPage ZIPファイルを選択"}, {"first_message", "最初のメッセージ"}, {"delete_chat", "チャットを削除"}, {"search", "検索..."},
        {"empty_chat_hint", "チャットを選択するか新しいチャットを追加"}, {"delete_confirm_title", "チャットを削除"},
        {"delete_confirm_text", "このチャットを削除しますか？\nすべてのメッセージが削除されます。"}, {"no_results", "結果が見つかりません"},
        {"yes", "はい"}, {"no", "いいえ"}, {"language", "言語"}, {"select_language", "言語を選択"}, {"profile_photo", "プロフィール写真"},
        {"name_label", "名前"}, {"participants_label", "グループ参加者"}, {"contact_name_placeholder", "連絡先名"}, {"image_files_filter", "画像ファイル (*.jpg *.jpeg *.png *.webp)"},
        {"my_profile", "マイプロフィール"}, {"import_success", "%1 — %2 件のメッセージをインポートしました"}, {"conversation", "会話"},
        {"open_system", "システムで開く"}, {"image_not_found", "画像が見つかりません"}, {"video", "動画"}, {"deleted_message", "このメッセージは削除されました"}, {"you_deleted_message", "このメッセージを削除しました"}, {"edited", "編集済み"}, {"app_version", "バージョン"}, {"app_copyright", "著作権 %1"}
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

    // Korean
    m_translations["Korean"] = {
        {"contact_info", "연락처 정보"}, {"msg_count", "메시지 수"}, {"messages", "메시지"}, {"import_date", "가져온 날짜"},
        {"no_chats", "채팅이 없습니다\n\n+ 버튼을 눌러\n새 채팅을 추가하세요"}, {"light_theme", "라이트 테마"}, {"dark_theme", "다크 테마"},
        {"new_chat_tooltip", "새 채팅 추가"}, {"chat_search_placeholder", "채팅 검색"}, {"importing", "가져오는 중..."},
        {"import_new", "새 채팅 추가"}, {"zip_description", "WAPage에서 내보낸 ZIP 파일을 선택하세요."},
        {"select_zip", "ZIP 선택"}, {"change_zip", "파일 변경"}, {"continue", "계속"},
        {"owner_question", "채팅에서 당신의 이름은 무엇인가요?\n(WAPage 계정에 표시되는 이름)"}, {"owner_placeholder", "예: 홍길동"},
        {"import_btn", "가져오기"}, {"back", "뒤로"}, {"loading_messages", "메시지를 불러오는 중입니다. 잠시만 기다려 주세요..."},
        {"select_zip_title", "WAPage ZIP 파일 선택"}, {"first_message", "첫 메시지"}, {"delete_chat", "채팅 삭제"}, {"search", "검색..."},
        {"empty_chat_hint", "채팅을 선택하거나 새 채팅을 추가하세요"}, {"delete_confirm_title", "채팅 삭제"},
        {"delete_confirm_text", "이 채팅을 삭제하시겠습니까?\n모든 메시지가 삭제됩니다."}, {"no_results", "검색 결과가 없습니다"},
        {"yes", "예"}, {"no", "아니요"}, {"language", "언어"}, {"select_language", "언어 선택"}, {"profile_photo", "프로필 사진"},
        {"name_label", "이름"}, {"participants_label", "그룹 참여자"}, {"contact_name_placeholder", "연락처 이름"}, {"image_files_filter", "이미지 파일 (*.jpg *.jpeg *.png *.webp)"},
        {"my_profile", "내 프로필"}, {"import_success", "%1 — %2개의 메시지를 가져왔습니다"}, {"conversation", "대화"},
        {"open_system", "시스템에서 열기"}, {"image_not_found", "이미지를 찾을 수 없습니다"}, {"video", "동영상"}, {"deleted_message", "이 메시지는 삭제되었습니다"}, {"you_deleted_message", "이 메시지를 삭제했습니다"}, {"edited", "수정됨"}, {"app_version", "버전"}, {"app_copyright", "저작권 %1"}
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

    // Mongolian
    m_translations["Mongolian"] = {
        {"contact_info", "Холбоо барих мэдээлэл"}, {"msg_count", "Мессежийн тоо"}, {"messages", "мессеж"}, {"import_date", "Импортын огноо"},
        {"no_chats", "Чат олдсонгүй\n\n+ дарж\nшинэ чат нэмнэ үү"}, {"light_theme", "Цайвар загвар"}, {"dark_theme", "Харанхуй загвар"},
        {"new_chat_tooltip", "Шинэ чат нэмэх"}, {"chat_search_placeholder", "Чатаас хайх"}, {"importing", "Импорт хийж байна..."},
        {"import_new", "Шинэ чат нэмэх"}, {"zip_description", "WAPage-аас экспортолсон ZIP файлыг сонгоно уу."},
        {"select_zip", "ZIP сонгох"}, {"change_zip", "Файл солих"}, {"continue", "Үргэлжлүүлэх"},
        {"owner_question", "Чат дээрх таны нэр юу вэ?\n(WAPage дансанд харагддаг нэр)"}, {"owner_placeholder", "Ж: Батболд"},
        {"import_btn", "Импорт"}, {"back", "Буцах"}, {"loading_messages", "Мессежүүд ачаалж байна, түр хүлээнэ үү..."},
        {"select_zip_title", "WAPage ZIP файл сонгох"}, {"first_message", "Эхний мессеж"}, {"delete_chat", "Чат устгах"}, {"search", "Хайх..."},
        {"empty_chat_hint", "Чат сонгох эсвэл шинэ чат нэмэх"}, {"delete_confirm_title", "Чат устгах"},
        {"delete_confirm_text", "Энэ чатыг устгахдаа итгэлтэй байна уу?\nБүх мессеж устна."}, {"no_results", "Үр дүн олдсонгүй"},
        {"yes", "Тийм"}, {"no", "Үгүй"}, {"language", "Хэл"}, {"select_language", "Хэл сонгох"}, {"profile_photo", "Профайл зураг"},
        {"name_label", "Нэр"}, {"participants_label", "Бүлгийн оролцогчид"}, {"contact_name_placeholder", "Харилцагчийн нэр"}, {"image_files_filter", "Зургийн файлууд (*.jpg *.jpeg *.png *.webp)"},
        {"my_profile", "Миний профайл"}, {"import_success", "%1 — %2 мессеж импортлогдлоо"}, {"conversation", "Яриа"},
        {"open_system", "Системээр нээх"}, {"image_not_found", "Зураг олдсонгүй"}, {"video", "Видео"}, {"deleted_message", "Энэ мессеж устсан"}, {"you_deleted_message", "Та энэ мессежийг устгасан"}, {"edited", "Засварласан"}, {"app_version", "хувилбар"}, {"app_copyright", "Зохиогчийн эрх %1-д хамааралагдана"}
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

    // Polish
    m_translations["Polish"] = {
        {"contact_info", "Informacje o kontakcie"}, {"msg_count", "Liczba wiadomości"}, {"messages", "wiadomości"}, {"import_date", "Data importu"},
        {"no_chats", "Brak czatów\n\nKliknij + aby dodać\nnowy czat"}, {"light_theme", "Jasny motyw"}, {"dark_theme", "Ciemny motyw"},
        {"new_chat_tooltip", "Dodaj nowy czat"}, {"chat_search_placeholder", "Szukaj na czatach"}, {"importing", "Importowanie..."},
        {"import_new", "Dodaj nowy czat"}, {"zip_description", "Wybierz plik ZIP wyeksportowany z WAPage."},
        {"select_zip", "Wybierz ZIP"}, {"change_zip", "Zmień plik"}, {"continue", "Kontynuuj"},
        {"owner_question", "Jak masz na imię na czacie?\n(Imię widoczne na koncie WAPage)"}, {"owner_placeholder", "Np: Jan Kowalski"},
        {"import_btn", "Importuj"}, {"back", "Wstecz"}, {"loading_messages", "Ładowanie wiadomości, proszę czekać..."},
        {"select_zip_title", "Wybierz plik ZIP WAPage"}, {"first_message", "Pierwsza wiadomość"}, {"delete_chat", "Usuń czat"}, {"search", "Szukaj..."},
        {"empty_chat_hint", "Wybierz czat lub dodaj nowy"}, {"delete_confirm_title", "Usuń czat"},
        {"delete_confirm_text", "Czy na pewno chcesz usunąć ten czat?\nWszystkie wiadomości zostaną usunięte."}, {"no_results", "Brak wyników"},
        {"yes", "Tak"}, {"no", "Nie"}, {"language", "Język"}, {"select_language", "Wybierz język"}, {"profile_photo", "Zdjęcie profilowe"},
        {"name_label", "Nazwa"}, {"participants_label", "Uczestnicy grupy"}, {"contact_name_placeholder", "Nazwa kontaktu"}, {"image_files_filter", "Pliki obrazów (*.jpg *.jpeg *.png *.webp)"},
        {"my_profile", "Mój profil"}, {"import_success", "%1 — zaimportowano %2 wiadomości"}, {"conversation", "Rozmowa"},
        {"open_system", "Otwórz w systemie"}, {"image_not_found", "Nie znaleziono obrazu"}, {"video", "Wideo"}, {"deleted_message", "Ta wiadomość została usunięta"}, {"you_deleted_message", "Usunąłeś tę wiadomość"}, {"edited", "Edytowano"}, {"app_version", "wersja"}, {"app_copyright", "Prawa autorskie %1"}
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

    // Ukrainian
    m_translations["Ukrainian"] = {
        {"contact_info", "Інформація про контакт"}, {"msg_count", "Кількість повідомлень"}, {"messages", "повідомлень"}, {"import_date", "Дата імпорту"},
        {"no_chats", "Чатів не знайдено\n\nНатисніть +, щоб додати\nновий чат"}, {"light_theme", "Світла тема"}, {"dark_theme", "Темна тема"},
        {"new_chat_tooltip", "Додати новий чат"}, {"chat_search_placeholder", "Пошук у чатах"}, {"importing", "Імпорт..."},
        {"import_new", "Додати новий чат"}, {"zip_description", "Виберіть ZIP-файл, експортований із WAPage."},
        {"select_zip", "Вибрати ZIP"}, {"change_zip", "Змінити файл"}, {"continue", "Продовжити"},
        {"owner_question", "Як вас звати у чаті?\n(Ім'я у вашому акаунті WAPage)"}, {"owner_placeholder", "Напр.: Іван Петренко"},
        {"import_btn", "Імпорт"}, {"back", "Назад"}, {"loading_messages", "Завантаження повідомлень, зачекайте..."},
        {"select_zip_title", "Виберіть ZIP-файл WAPage"}, {"first_message", "Перше повідомлення"}, {"delete_chat", "Видалити чат"}, {"search", "Пошук..."},
        {"empty_chat_hint", "Виберіть чат або додайте новий"}, {"delete_confirm_title", "Видалити чат"},
        {"delete_confirm_text", "Ви впевнені, що хочете видалити цей чат?\nУсі повідомлення буде видалено."}, {"no_results", "Результатів не знайдено"},
        {"yes", "Так"}, {"no", "Ні"}, {"language", "Мова"}, {"select_language", "Виберіть мову"}, {"profile_photo", "Фото профілю"},
        {"name_label", "Ім'я"}, {"participants_label", "Учасники групи"}, {"contact_name_placeholder", "Ім'я контакту"}, {"image_files_filter", "Файли зображень (*.jpg *.jpeg *.png *.webp)"},
        {"my_profile", "Мій профіль"}, {"import_success", "%1 — імпортовано %2 повідомлень"}, {"conversation", "Розмова"},
        {"open_system", "Відкрити в системі"}, {"image_not_found", "Зображення не знайдено"}, {"video", "Відео"}, {"deleted_message", "Це повідомлення видалено"}, {"you_deleted_message", "Ви видалили це повідомлення"}, {"edited", "Змінено"}, {"app_version", "версія"}, {"app_copyright", "Авторські права належать %1"}
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

    // Uzbek
    m_translations["Uzbek"] = {
        {"contact_info", "Kontakt ma'lumoti"}, {"msg_count", "Xabarlar soni"}, {"messages", "xabar"}, {"import_date", "Import sanasi"},
        {"no_chats", "Chatlar topilmadi\n\nYangi chat qo'shish uchun\n+ tugmasini bosing"}, {"light_theme", "Yorug' mavzu"}, {"dark_theme", "Qorong'u mavzu"},
        {"new_chat_tooltip", "Yangi chat qo'shish"}, {"chat_search_placeholder", "Chatlardan qidirish"}, {"importing", "Import qilinmoqda..."},
        {"import_new", "Yangi chat qo'shish"}, {"zip_description", "WAPage'dan eksport qilingan ZIP faylini tanlang."},
        {"select_zip", "ZIP tanlash"}, {"change_zip", "Faylni o'zgartirish"}, {"continue", "Davom etish"},
        {"owner_question", "Chatdagi ismingiz nima?\n(WAPage hisobingizda ko'rinadigan ism)"}, {"owner_placeholder", "Masalan: Ali Valiyev"},
        {"import_btn", "Import"}, {"back", "Orqaga"}, {"loading_messages", "Xabarlar yuklanmoqda, iltimos kuting..."},
        {"select_zip_title", "WAPage ZIP faylini tanlang"}, {"first_message", "Birinchi xabar"}, {"delete_chat", "Chatni o'chirish"}, {"search", "Qidirish..."},
        {"empty_chat_hint", "Chatni tanlang yoki yangisini qo'shing"}, {"delete_confirm_title", "Chatni o'chirish"},
        {"delete_confirm_text", "Rostdan ham bu chatni o'chirmoqchimisiz?\nBarcha xabarlar o'chiriladi."}, {"no_results", "Natija topilmadi"},
        {"yes", "Ha"}, {"no", "Yo'q"}, {"language", "Til"}, {"select_language", "Tilni tanlang"}, {"profile_photo", "Profil rasmi"},
        {"name_label", "Ism"}, {"participants_label", "Guruh ishtirokchilari"}, {"contact_name_placeholder", "Kontakt nomi"}, {"image_files_filter", "Rasm fayllari (*.jpg *.jpeg *.png *.webp)"},
        {"my_profile", "Mening profilim"}, {"import_success", "%1 — %2 ta xabar import qilindi"}, {"conversation", "Suhbat"},
        {"open_system", "Tizimda ochish"}, {"image_not_found", "Rasm topilmadi"}, {"video", "Video"}, {"deleted_message", "Bu xabar o'chirildi"}, {"you_deleted_message", "Siz bu xabarni o'chirdingiz"}, {"edited", "Tahrirlangan"}, {"app_version", "versiya"}, {"app_copyright", "Mualliflik huquqi %1 tomonidan"}
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
QString LanguageManager::translateSystemMessage(const QString& token) const
{
    if (!token.startsWith(QStringLiteral("__sys:")))
        return token;   // Not a normalised system token — return as-is

    // Split into parts using a limit so that a group name or other param
    // containing ":" is preserved intact in the last slot.
    // Format: __sys:key:p0[:p1[:p2]]
    // We never need more than 4 tokens (key + 3 params), so cap at 4.
    const QString body = token.mid(6); // skip "__sys:"
    const int keyEnd = body.indexOf(QLatin1Char(':'));
    const QString key = (keyEnd < 0) ? body : body.left(keyEnd);
    if (key.isEmpty()) return token;

    // Determine how many params this key uses, then split the remainder accordingly.
    // Keys with 3 params: changed_name_from_to (person, old_name, new_name)
    // Keys with 2 params: most others (person, name/timer)
    // Keys with 1 param:  left, you_now_admin, no_longer_admin_you, etc.
    // Keys with 0 params:  e2e_note, anyone_invite_link
    static const QSet<QString> keys3 = {
        QStringLiteral("changed_name_from_to")
    };
    static const QSet<QString> keys1 = {
        QStringLiteral("you_now_admin"), QStringLiteral("no_longer_admin_you"),
        QStringLiteral("e2e_note"), QStringLiteral("anyone_invite_link"),
        QStringLiteral("left"), QStringLiteral("was_added"),
        QStringLiteral("now_admin"), QStringLiteral("no_longer_admin"),
        QStringLiteral("joined_link"), QStringLiteral("changed_icon"),
        QStringLiteral("changed_desc"), QStringLiteral("reset_link"),
        QStringLiteral("disappear_off"), QStringLiteral("disappear_off2"),
        QStringLiteral("phone_number_changed"),
        QStringLiteral("admin_approval_on"), QStringLiteral("admin_approval_off"),
        QStringLiteral("settings_only_admins_edit"), QStringLiteral("settings_all_edit"),
        QStringLiteral("settings_only_admins_send"), QStringLiteral("settings_all_send"),
        QStringLiteral("settings_only_admins_add"), QStringLiteral("settings_all_add"),
        QStringLiteral("settings_only_admins_invite_link"), QStringLiteral("settings_all_invite_link"),
    };

    QString p0, p1, p2;
    if (keyEnd >= 0) {
        const QString rest = body.mid(keyEnd + 1); // everything after key:
        if (keys3.contains(key)) {
            // 3 params: split into at most 3 pieces; p2 gets the rest (may contain colons)
            const int c1 = rest.indexOf(QLatin1Char(':'));
            if (c1 >= 0) {
                p0 = rest.left(c1);
                const QString rest2 = rest.mid(c1 + 1);
                const int c2 = rest2.indexOf(QLatin1Char(':'));
                if (c2 >= 0) {
                    p1 = rest2.left(c2);
                    p2 = rest2.mid(c2 + 1); // rest — may contain colons
                } else {
                    p1 = rest2;
                }
            } else {
                p0 = rest;
            }
        } else if (keys1.contains(key)) {
            // 1 param: everything is p0 (may contain colons — e.g. a person named "A: B")
            p0 = rest;
        } else {
            // 2 params: p0 is up to first colon; p1 is the rest (may contain colons)
            const int c1 = rest.indexOf(QLatin1Char(':'));
            if (c1 >= 0) {
                p0 = rest.left(c1);
                p1 = rest.mid(c1 + 1); // rest — may contain colons (e.g. "8:00 AM Group")
            } else {
                p0 = rest;
            }
        }
    }

    const QMap<QString, QString>& T =
        m_sysTranslations.contains(m_currentLang)
        ? m_sysTranslations[m_currentLang]
        : m_sysTranslations["English"];

    // ── 2nd-person handling ──────────────────────────────────────────────────
    // WhatsApp exports literally write "You" / "you" when the actor or target
    // of a system event is the device owner, regardless of locale. To produce
    // a grammatically natural sentence in each language (e.g. Azerbaijani
    // "Sən bu qrupu yaratdın" instead of "You bu qrupu yaratdı"), we redirect
    // to a "_you" variant of the template when the actor (p0) is "You", or to
    // a "_target_you" variant when the action target (p1) is "you" for keys
    // that have an addressed counterpart (added / removed). When no variant
    // exists for the active language, we fall back to the original 3rd-person
    // template so the message is still understandable.
    QString lookupKey = key;
    const bool actorIsYou =
        !p0.isEmpty() && p0.compare(QLatin1String("You"), Qt::CaseInsensitive) == 0;
    const bool targetIsYou =
        !p1.isEmpty() && p1.compare(QLatin1String("you"), Qt::CaseInsensitive) == 0;
    if (actorIsYou) {
        const QString youKey = key + QLatin1String("_you");
        if (T.contains(youKey)) lookupKey = youKey;
    } else if (targetIsYou &&
               (key == QLatin1String("added") || key == QLatin1String("removed"))) {
        const QString tyKey = key + QLatin1String("_target_you");
        if (T.contains(tyKey)) lookupKey = tyKey;
    }

    if (!T.contains(lookupKey)) return token;   // Unknown key — return raw token

    QString tpl = T[lookupKey];

    // Replace placeholders in order
    tpl.replace(QStringLiteral("{0}"), p0);
    tpl.replace(QStringLiteral("{1}"), p1);
    tpl.replace(QStringLiteral("{2}"), p2);

    // ── Voice / video call duration unit translation ────────────────────────
    // Parser produces tokens like "__sys:voice_call:You:41 sec" where the
    // duration string ("41 sec" / "5 min" / "1 hr") is *always* English
    // because it comes from the WhatsApp export verbatim. WhatsApp only ever
    // emits a single unit per message (never combined like "1 hr 5 min"),
    // but the regex below still handles per-unit replacement so a combined
    // future format would also work without code changes.
    //
    // The unit substitution operates on the already-rendered template (after
    // {0}/{1} replacement) because the duration arrived via p1 → {1}, and we
    // want to leave any other text untouched. We only run the substitution
    // for call keys to avoid accidentally rewriting a person's name or a
    // group title that happens to contain "min"/"sec".
    if (key.startsWith(QLatin1String("voice_call")) ||
        key.startsWith(QLatin1String("video_call"))) {
        // Match a digit followed by a unit so we do not accidentally rewrite
        // standalone words inside group/contact names.
        // Patterns recognised (case-insensitive, with or without trailing 's'):
        //   sec, secs, second, seconds   →  unit_sec
        //   min, mins, minute, minutes   →  unit_min
        //   hr,  hrs,  hour,   hours     →  unit_hr
        auto applyUnit = [&tpl, &T](const QString& pattern, const QString& unitKey) {
            if (!T.contains(unitKey)) return;
            const QRegularExpression re(pattern, QRegularExpression::CaseInsensitiveOption);
            // Qt's QString::replace(QRegularExpression, QString) honours
            // numeric backreferences (\1..\9) in the replacement string, so
            // "\1 <unit>" preserves the original number.
            tpl.replace(re, QStringLiteral("\\1 ") + T.value(unitKey));
        };
        applyUnit(QStringLiteral("(\\d+)\\s*(?:seconds?|secs?)\\b"), QStringLiteral("unit_sec"));
        applyUnit(QStringLiteral("(\\d+)\\s*(?:minutes?|mins?)\\b"),  QStringLiteral("unit_min"));
        applyUnit(QStringLiteral("(\\d+)\\s*(?:hours?|hrs?)\\b"),     QStringLiteral("unit_hr"));
    }

    // Translate the timer value tokens that appear in disappearing-message entries
    // e.g.  "24 Hours" / "7 Days" / "90 Days"
    if (tpl.contains(QStringLiteral("{timer}"))) {
        // p1 holds the timer value for disappear_on / update_timer keys
        const QString timerVal = p1;
        // Case-insensitive comparison — export files may use lowercase (e.g. "7 days")
        const QString timerLower = timerVal.toLower();
        QString timerKey;
        if (timerLower == QLatin1String("24 hours") || timerLower == QLatin1String("24 hour"))
            timerKey = QStringLiteral("timer_24h");
        else if (timerLower == QLatin1String("7 days") || timerLower == QLatin1String("7 day"))
            timerKey = QStringLiteral("timer_7d");
        else if (timerLower == QLatin1String("90 days") || timerLower == QLatin1String("90 day"))
            timerKey = QStringLiteral("timer_90d");
        tpl.replace(QStringLiteral("{timer}"),
                    (!timerKey.isEmpty() && T.contains(timerKey)) ? T[timerKey] : timerVal);
    }

    return tpl.trimmed();
}

// ─────────────────────────────────────────────────────────────────────────────
// System-message translation tables
//
// Key naming mirrors the __sys: tokens that ChatParser emits.
// Placeholders: {0} = first person/name,  {1} = second name / group name / timer,
//               {2} = third param (rare).
// ─────────────────────────────────────────────────────────────────────────────
void LanguageManager::initSystemTranslations()
{
    // ── Azerbaijani ──────────────────────────────────────────────────────────
    m_sysTranslations[QString::fromUtf8("Azerbaijani")].insert(QStringLiteral("created_group"), QString::fromUtf8("{0} \"{1}\" qrupunu yaratdı"));
    m_sysTranslations[QStringLiteral("Azerbaijani")].insert(QStringLiteral("created_group_noname"), QStringLiteral("{0} bu qrupu yaratdı"));
    m_sysTranslations[QStringLiteral("Azerbaijani")].insert(QStringLiteral("e2e_note"), QStringLiteral("Mesajlar və zənglər ucdan-uca şifrəlidir. Bu söhbətdəki insanlar yalnız onları oxuya, dinləyə və ya paylaşa bilər."));
    m_sysTranslations[QStringLiteral("Azerbaijani")].insert(QStringLiteral("left"), QStringLiteral("{0} çıxdı"));
    m_sysTranslations[QStringLiteral("Azerbaijani")].insert(QStringLiteral("added"), QStringLiteral("{0}, {1}-ni əlavə etdi"));
    m_sysTranslations[QStringLiteral("Azerbaijani")].insert(QStringLiteral("was_added"), QStringLiteral("{0} əlavə edildi"));
    m_sysTranslations[QStringLiteral("Azerbaijani")].insert(QStringLiteral("removed"), QStringLiteral("{0}, {1}-ni çıxardı"));
    m_sysTranslations[QStringLiteral("Azerbaijani")].insert(QStringLiteral("you_now_admin"), QStringLiteral("İndi siz adminsiniz"));
    m_sysTranslations[QStringLiteral("Azerbaijani")].insert(QStringLiteral("now_admin"), QStringLiteral("{0} indi admindir"));
    m_sysTranslations[QStringLiteral("Azerbaijani")].insert(QStringLiteral("admin_approval_on"), QStringLiteral("{0} qrupa qoşulmaq üçün admin təsdiqini açdı. Dəyişmək üçün toxunun."));
    m_sysTranslations[QStringLiteral("Azerbaijani")].insert(QStringLiteral("no_longer_admin_you"), QStringLiteral("Siz artıq admin deyilsiniz"));
    m_sysTranslations[QStringLiteral("Azerbaijani")].insert(QStringLiteral("no_longer_admin"), QStringLiteral("{0} artıq admin deyil"));
    m_sysTranslations[QStringLiteral("Azerbaijani")].insert(QStringLiteral("admin_approval_off"), QStringLiteral("{0} qrupa qoşulmaq üçün admin təsdiqini bağladı. Dəyişmək üçün toxunun."));
    m_sysTranslations[QStringLiteral("Azerbaijani")].insert(QStringLiteral("joined_link"), QStringLiteral("{0} qrup linki ilə qoşuldu."));
    m_sysTranslations[QStringLiteral("Azerbaijani")].insert(QStringLiteral("changed_icon"), QStringLiteral("{0} qrupun ikonunu dəyişdi"));
    m_sysTranslations[QString::fromUtf8("Azerbaijani")].insert(QStringLiteral("changed_name"), QString::fromUtf8("{0} qrupun adını \"{1}\" olaraq dəyişdi"));
    m_sysTranslations[QString::fromUtf8("Azerbaijani")].insert(QStringLiteral("changed_name_from_to"), QString::fromUtf8("{0} qrupun adını \"{1}\"-dən \"{2}\"-yə dəyişdi"));
    m_sysTranslations[QStringLiteral("Azerbaijani")].insert(QStringLiteral("changed_desc"), QStringLiteral("{0} qrupun təsvirini dəyişdi"));
    m_sysTranslations[QStringLiteral("Azerbaijani")].insert(QStringLiteral("settings_only_admins_edit"), QStringLiteral("{0} parametrləri elə dəyişdi ki, yalnız adminlər qrup parametrlərini redaktə edə bilsin"));
    m_sysTranslations[QStringLiteral("Azerbaijani")].insert(QStringLiteral("settings_all_edit"), QStringLiteral("{0} parametrləri elə dəyişdi ki, bütün üzvlər qrup parametrlərini redaktə edə bilsin"));
    m_sysTranslations[QStringLiteral("Azerbaijani")].insert(QStringLiteral("settings_only_admins_send"), QStringLiteral("{0} bu qrupun parametrlərini elə dəyişdi ki, yalnız adminlər mesaj göndərə bilsin"));
    m_sysTranslations[QStringLiteral("Azerbaijani")].insert(QStringLiteral("settings_only_admins_add"), QStringLiteral("{0} bu qrupun parametrlərini elə dəyişdi ki, yalnız adminlər başqalarını əlavə edə bilsin."));
    m_sysTranslations[QStringLiteral("Azerbaijani")].insert(QStringLiteral("settings_all_add"), QStringLiteral("{0} bu qrupun parametrlərini elə dəyişdi ki, bütün üzvlər başqalarını əlavə edə bilsin."));
    m_sysTranslations[QStringLiteral("Azerbaijani")].insert(QStringLiteral("settings_all_send"), QStringLiteral("{0} bu qrupun parametrlərini elə dəyişdi ki, bütün üzvlər mesaj göndərə bilsin"));
    m_sysTranslations[QStringLiteral("Azerbaijani")].insert(QStringLiteral("settings_all_invite_link"), QStringLiteral("{0} bu qrupun parametrlərini elə dəyişdi ki, bütün üzvlər qrup linki ilə dəvət edə bilsin."));
    m_sysTranslations[QStringLiteral("Azerbaijani")].insert(QStringLiteral("anyone_invite_link"), QStringLiteral("Bu qrupdakı hər kəs qrup linki ilə yeni üzvlər dəvət edə bilər."));
    m_sysTranslations[QStringLiteral("Azerbaijani")].insert(QStringLiteral("settings_only_admins_invite_link"), QStringLiteral("{0} bu qrupun parametrlərini elə dəyişdi ki, yalnız adminlər qrup linki ilə dəvət edə bilsin."));
    m_sysTranslations[QStringLiteral("Azerbaijani")].insert(QStringLiteral("reset_link"), QStringLiteral("{0} qrupun dəvət linkini sıfırladı"));
    m_sysTranslations[QStringLiteral("Azerbaijani")].insert(QStringLiteral("disappear_on"), QStringLiteral("{0} yoxa çıxan mesajları açdı. ‎Yeni mesajlar göndərildikdən {timer} sonra bu söhbətdən yox olacaq (saxlanılanlar istisna). ‎Dəyişmək üçün toxunun."));
    m_sysTranslations[QStringLiteral("Azerbaijani")].insert(QStringLiteral("disappear_off"), QStringLiteral("{0} yoxa çıxan mesajları bağladı. ‎Dəyişmək üçün toxunun."));
    m_sysTranslations[QStringLiteral("Azerbaijani")].insert(QStringLiteral("disappear_off2"), QStringLiteral("{0} yoxa çıxan mesajları bağladı. Ətraflı öyrənmək üçün toxunun."));
    m_sysTranslations[QStringLiteral("Azerbaijani")].insert(QStringLiteral("update_timer"), QStringLiteral("{0} mesaj taymerini yenilədi. ‎Yeni mesajlar göndərildikdən {timer} sonra bu söhbətdən yox olacaq (saxlanılanlar istisna). ‎Dəyişmək üçün toxunun."));
    m_sysTranslations[QStringLiteral("Azerbaijani")].insert(QStringLiteral("update_timer2"), QStringLiteral("{0} mesaj taymerini yenilədi. Yeni mesajlar göndərildikdən {timer} sonra bu söhbətdən yox olacaq (saxlanılanlar istisna). Ətraflı öyrənmək üçün toxunun."));
    m_sysTranslations[QStringLiteral("Azerbaijani")].insert(QStringLiteral("voice_call"), QStringLiteral("Səsli zəng. {1} • {0} qoşuldu"));
    m_sysTranslations[QStringLiteral("Azerbaijani")].insert(QStringLiteral("video_call"), QStringLiteral("Video zəng. {1} • {0} qoşuldu"));
    m_sysTranslations[QStringLiteral("Azerbaijani")].insert(QStringLiteral("timer_24h"), QStringLiteral("24 saat"));
    m_sysTranslations[QStringLiteral("Azerbaijani")].insert(QStringLiteral("timer_7d"), QStringLiteral("7 gün"));
    m_sysTranslations[QStringLiteral("Azerbaijani")].insert(QStringLiteral("timer_90d"), QStringLiteral("90 gün"));
    m_sysTranslations[QStringLiteral("Azerbaijani")].insert(QStringLiteral("phone_number_changed"), QString::fromUtf8("{0} telefon nömrəsini yenilədi. Yeni nömrəyə mesaj göndər və ya əlavə et."));

    // ── English ──────────────────────────────────────────────────────────────
    m_sysTranslations[QString::fromUtf8("English")].insert(QStringLiteral("created_group"), QString::fromUtf8("{0} created group \"{1}\""));
    m_sysTranslations[QStringLiteral("English")].insert(QStringLiteral("created_group_noname"), QStringLiteral("{0} created this group"));
    m_sysTranslations[QStringLiteral("English")].insert(QStringLiteral("e2e_note"), QStringLiteral("Messages and calls are end-to-end encrypted. Only people in this chat can read, listen to, or share them."));
    m_sysTranslations[QStringLiteral("English")].insert(QStringLiteral("left"), QStringLiteral("{0} left"));
    m_sysTranslations[QStringLiteral("English")].insert(QStringLiteral("added"), QStringLiteral("{0} added {1}"));
    m_sysTranslations[QStringLiteral("English")].insert(QStringLiteral("was_added"), QStringLiteral("{0} was added"));
    m_sysTranslations[QStringLiteral("English")].insert(QStringLiteral("removed"), QStringLiteral("{0} removed {1}"));
    m_sysTranslations[QStringLiteral("English")].insert(QStringLiteral("you_now_admin"), QStringLiteral("You're now an admin"));
    m_sysTranslations[QStringLiteral("English")].insert(QStringLiteral("now_admin"), QStringLiteral("{0} is now an admin"));
    m_sysTranslations[QStringLiteral("English")].insert(QStringLiteral("admin_approval_on"), QStringLiteral("{0} turned on admin approval to join this group. Tap to change."));
    m_sysTranslations[QStringLiteral("English")].insert(QStringLiteral("no_longer_admin_you"), QStringLiteral("You're no longer an admin"));
    m_sysTranslations[QStringLiteral("English")].insert(QStringLiteral("no_longer_admin"), QStringLiteral("{0} is no longer an admin"));
    m_sysTranslations[QStringLiteral("English")].insert(QStringLiteral("admin_approval_off"), QStringLiteral("{0} turned off admin approval to join this group. Tap to change."));
    m_sysTranslations[QStringLiteral("English")].insert(QStringLiteral("joined_link"), QStringLiteral("{0} joined using a group link."));
    m_sysTranslations[QStringLiteral("English")].insert(QStringLiteral("changed_icon"), QStringLiteral("{0} changed this group's icon"));
    m_sysTranslations[QString::fromUtf8("English")].insert(QStringLiteral("changed_name"), QString::fromUtf8("{0} changed the group name to \"{1}\""));
    m_sysTranslations[QString::fromUtf8("English")].insert(QStringLiteral("changed_name_from_to"), QString::fromUtf8("{0} changed the group name from \"{1}\" to \"{2}\""));
    m_sysTranslations[QStringLiteral("English")].insert(QStringLiteral("changed_desc"), QStringLiteral("{0} changed the group description"));
    m_sysTranslations[QStringLiteral("English")].insert(QStringLiteral("settings_only_admins_edit"), QStringLiteral("{0} changed the settings so only admins can edit the group settings"));
    m_sysTranslations[QStringLiteral("English")].insert(QStringLiteral("settings_all_edit"), QStringLiteral("{0} changed the settings so all members can edit the group settings"));
    m_sysTranslations[QStringLiteral("English")].insert(QStringLiteral("settings_only_admins_send"), QStringLiteral("{0} changed this group's settings to allow only admins to send messages to this group"));
    m_sysTranslations[QStringLiteral("English")].insert(QStringLiteral("settings_only_admins_add"), QStringLiteral("{0} changed this group's settings to allow only admins to add others to this group."));
    m_sysTranslations[QStringLiteral("English")].insert(QStringLiteral("settings_all_add"), QStringLiteral("{0} changed this group's settings to allow all members to add others to this group."));
    m_sysTranslations[QStringLiteral("English")].insert(QStringLiteral("settings_all_send"), QStringLiteral("{0} changed this group's settings to allow all members to send messages to this group"));
    m_sysTranslations[QStringLiteral("English")].insert(QStringLiteral("settings_all_invite_link"), QStringLiteral("{0} changed this group's settings to allow all members to invite people to this group using a group link."));
    m_sysTranslations[QStringLiteral("English")].insert(QStringLiteral("anyone_invite_link"), QStringLiteral("Anyone in this group can invite new members using a group link."));
    m_sysTranslations[QStringLiteral("English")].insert(QStringLiteral("settings_only_admins_invite_link"), QStringLiteral("{0} changed this group's settings to allow only admins to invite people to this group using a group link."));
    m_sysTranslations[QStringLiteral("English")].insert(QStringLiteral("reset_link"), QStringLiteral("{0} reset this group's invite link"));
    m_sysTranslations[QStringLiteral("English")].insert(QStringLiteral("disappear_on"), QStringLiteral("{0} turned on disappearing messages. New messages will disappear from this chat {timer} after they're sent, except when kept. Tap to change."));
    m_sysTranslations[QStringLiteral("English")].insert(QStringLiteral("disappear_off"), QStringLiteral("{0} turned off disappearing messages. Tap to change."));
    m_sysTranslations[QStringLiteral("English")].insert(QStringLiteral("disappear_off2"), QStringLiteral("{0} turned off disappearing messages. Tap to learn more."));
    m_sysTranslations[QStringLiteral("English")].insert(QStringLiteral("update_timer"), QStringLiteral("{0} updated the message timer. New messages will disappear from this chat {timer} after they're sent, except when kept. Tap to change."));
    m_sysTranslations[QStringLiteral("English")].insert(QStringLiteral("update_timer2"), QStringLiteral("{0} updated the message timer. New messages will disappear from this chat {timer} after they're sent, except when kept. Tap to learn more."));
    m_sysTranslations[QStringLiteral("English")].insert(QStringLiteral("voice_call"), QStringLiteral("Voice call. {1} • {0} joined"));
    m_sysTranslations[QStringLiteral("English")].insert(QStringLiteral("video_call"), QStringLiteral("Video call. {1} • {0} joined"));
    m_sysTranslations[QStringLiteral("English")].insert(QStringLiteral("timer_24h"), QStringLiteral("24 Hours"));
    m_sysTranslations[QStringLiteral("English")].insert(QStringLiteral("timer_7d"), QStringLiteral("7 Days"));
    m_sysTranslations[QStringLiteral("English")].insert(QStringLiteral("timer_90d"), QStringLiteral("90 Days"));
    m_sysTranslations[QStringLiteral("English")].insert(QStringLiteral("phone_number_changed"), QStringLiteral("{0} changed their phone number to a new number. Message or add the new number."));

    // ── Turkish ──────────────────────────────────────────────────────────────
    m_sysTranslations[QString::fromUtf8("Turkish")].insert(QStringLiteral("created_group"), QString::fromUtf8("{0}, \"{1}\" grubunu oluşturdu"));
    m_sysTranslations[QStringLiteral("Turkish")].insert(QStringLiteral("created_group_noname"), QStringLiteral("{0} bu grubu oluşturdu"));
    m_sysTranslations[QStringLiteral("Turkish")].insert(QStringLiteral("e2e_note"), QStringLiteral("Mesajlar ve aramalar uçtan uca şifrelidir. Bu sohbetteki yalnızca kişiler bunları okuyabilir, dinleyebilir veya paylaşabilir."));
    m_sysTranslations[QStringLiteral("Turkish")].insert(QStringLiteral("left"), QStringLiteral("{0} ayrıldı"));
    m_sysTranslations[QStringLiteral("Turkish")].insert(QStringLiteral("added"), QStringLiteral("{0}, {1} kişisini ekledi"));
    m_sysTranslations[QStringLiteral("Turkish")].insert(QStringLiteral("was_added"), QStringLiteral("{0} eklendi"));
    m_sysTranslations[QStringLiteral("Turkish")].insert(QStringLiteral("removed"), QStringLiteral("{0}, {1} kişisini çıkardı"));
    m_sysTranslations[QStringLiteral("Turkish")].insert(QStringLiteral("you_now_admin"), QStringLiteral("Artık bir yöneticisiniz"));
    m_sysTranslations[QStringLiteral("Turkish")].insert(QStringLiteral("now_admin"), QStringLiteral("{0} artık yönetici"));
    m_sysTranslations[QStringLiteral("Turkish")].insert(QStringLiteral("admin_approval_on"), QStringLiteral("{0}, bu gruba katılmak için yönetici onayını açtı. Değiştirmek için dokunun."));
    m_sysTranslations[QStringLiteral("Turkish")].insert(QStringLiteral("no_longer_admin_you"), QStringLiteral("Artık yönetici değilsiniz"));
    m_sysTranslations[QStringLiteral("Turkish")].insert(QStringLiteral("no_longer_admin"), QStringLiteral("{0} artık yönetici değil"));
    m_sysTranslations[QStringLiteral("Turkish")].insert(QStringLiteral("admin_approval_off"), QStringLiteral("{0}, bu gruba katılmak için yönetici onayını kapattı. Değiştirmek için dokunun."));
    m_sysTranslations[QStringLiteral("Turkish")].insert(QStringLiteral("joined_link"), QStringLiteral("{0} grup bağlantısı kullanarak katıldı."));
    m_sysTranslations[QStringLiteral("Turkish")].insert(QStringLiteral("changed_icon"), QStringLiteral("{0} grubun simgesini değiştirdi"));
    m_sysTranslations[QString::fromUtf8("Turkish")].insert(QStringLiteral("changed_name"), QString::fromUtf8("{0} grup adını \"{1}\" olarak değiştirdi"));
    m_sysTranslations[QStringLiteral("Turkish")].insert(QStringLiteral("changed_name_from_to"), QString::fromUtf8("{0} grup adını \"{1}\"-dan \"{2}\"-na değiştirdi"));
    m_sysTranslations[QStringLiteral("Turkish")].insert(QStringLiteral("changed_desc"), QStringLiteral("{0} grup açıklamasını değiştirdi"));
    m_sysTranslations[QStringLiteral("Turkish")].insert(QStringLiteral("settings_only_admins_edit"), QStringLiteral("{0} ayarları yalnızca yöneticilerin grup ayarlarını düzenleyebileceği şekilde değiştirdi"));
    m_sysTranslations[QStringLiteral("Turkish")].insert(QStringLiteral("settings_all_edit"), QStringLiteral("{0} ayarları tüm üyelerin grup ayarlarını düzenleyebileceği şekilde değiştirdi"));
    m_sysTranslations[QStringLiteral("Turkish")].insert(QStringLiteral("settings_only_admins_send"), QStringLiteral("{0} bu grubun ayarlarını yalnızca yöneticilerin mesaj gönderebileceği şekilde değiştirdi"));
    m_sysTranslations[QStringLiteral("Turkish")].insert(QStringLiteral("settings_only_admins_add"), QStringLiteral("{0} bu grubun ayarlarını yalnızca yöneticilerin başkalarını ekleyebileceği şekilde değiştirdi."));
    m_sysTranslations[QStringLiteral("Turkish")].insert(QStringLiteral("settings_all_add"), QStringLiteral("{0} bu grubun ayarlarını tüm üyelerin başkalarını ekleyebileceği şekilde değiştirdi."));
    m_sysTranslations[QStringLiteral("Turkish")].insert(QStringLiteral("settings_all_send"), QStringLiteral("{0} bu grubun ayarlarını tüm üyelerin mesaj gönderebileceği şekilde değiştirdi"));
    m_sysTranslations[QStringLiteral("Turkish")].insert(QStringLiteral("settings_all_invite_link"), QStringLiteral("{0} bu grubun ayarlarını tüm üyelerin grup bağlantısıyla davet edebileceği şekilde değiştirdi."));
    m_sysTranslations[QStringLiteral("Turkish")].insert(QStringLiteral("anyone_invite_link"), QStringLiteral("Bu gruptaki herkes grup bağlantısı kullanarak yeni üye davet edebilir."));
    m_sysTranslations[QStringLiteral("Turkish")].insert(QStringLiteral("settings_only_admins_invite_link"), QStringLiteral("{0} bu grubun ayarlarını yalnızca yöneticilerin grup bağlantısıyla davet edebileceği şekilde değiştirdi."));
    m_sysTranslations[QStringLiteral("Turkish")].insert(QStringLiteral("reset_link"), QStringLiteral("{0} grubun davet bağlantısını sıfırladı"));
    m_sysTranslations[QStringLiteral("Turkish")].insert(QStringLiteral("disappear_on"), QStringLiteral("{0} kaybolan mesajları açtı. Yeni mesajlar gönderildikten {timer} sonra bu sohbetten kaybolacak (saklananlar hariç). Değiştirmek için dokunun."));
    m_sysTranslations[QStringLiteral("Turkish")].insert(QStringLiteral("disappear_off"), QStringLiteral("{0} kaybolan mesajları kapattı. Değiştirmek için dokunun."));
    m_sysTranslations[QStringLiteral("Turkish")].insert(QStringLiteral("disappear_off2"), QStringLiteral("{0} kaybolan mesajları kapattı. Daha fazla bilgi için dokunun."));
    m_sysTranslations[QStringLiteral("Turkish")].insert(QStringLiteral("update_timer"), QStringLiteral("{0} mesaj zamanlayıcısını güncelledi. Yeni mesajlar gönderildikten {timer} sonra bu sohbetten kaybolacak (saklananlar hariç). Değiştirmek için dokunun."));
    m_sysTranslations[QStringLiteral("Turkish")].insert(QStringLiteral("update_timer2"), QStringLiteral("{0} mesaj zamanlayıcısını güncelledi. Yeni mesajlar gönderildikten {timer} sonra bu sohbetten kaybolacak (saklananlar hariç). Daha fazla bilgi için dokunun."));
    m_sysTranslations[QStringLiteral("Turkish")].insert(QStringLiteral("voice_call"), QStringLiteral("Sesli arama. {1} • {0} katıldı"));
    m_sysTranslations[QStringLiteral("Turkish")].insert(QStringLiteral("video_call"), QStringLiteral("Görüntülü arama. {1} • {0} katıldı"));
    m_sysTranslations[QStringLiteral("Turkish")].insert(QStringLiteral("timer_24h"), QStringLiteral("24 Saat"));
    m_sysTranslations[QStringLiteral("Turkish")].insert(QStringLiteral("timer_7d"), QStringLiteral("7 Gün"));
    m_sysTranslations[QStringLiteral("Turkish")].insert(QStringLiteral("timer_90d"), QStringLiteral("90 Gün"));
    m_sysTranslations[QStringLiteral("Turkish")].insert(QStringLiteral("phone_number_changed"), QString::fromUtf8("{0} telefon numarasını değiştirdi. Yeni numarayı mesajla veya ekle."));

    // ── Russian ──────────────────────────────────────────────────────────────
    m_sysTranslations[QString::fromUtf8("Russian")].insert(QStringLiteral("created_group"), QString::fromUtf8("{0} создал(а) группу \"{1}\""));
    m_sysTranslations[QStringLiteral("Russian")].insert(QStringLiteral("created_group_noname"), QStringLiteral("{0} создал(а) эту группу"));
    m_sysTranslations[QStringLiteral("Russian")].insert(QStringLiteral("e2e_note"), QStringLiteral("Сообщения и звонки защищены сквозным шифрованием. Прочитать или прослушать их могут только участники чата."));
    m_sysTranslations[QStringLiteral("Russian")].insert(QStringLiteral("left"), QStringLiteral("{0} вышел(а)"));
    m_sysTranslations[QStringLiteral("Russian")].insert(QStringLiteral("added"), QStringLiteral("{0} добавил(а) {1}"));
    m_sysTranslations[QStringLiteral("Russian")].insert(QStringLiteral("was_added"), QStringLiteral("{0} был(а) добавлен(а)"));
    m_sysTranslations[QStringLiteral("Russian")].insert(QStringLiteral("removed"), QStringLiteral("{0} удалил(а) {1}"));
    m_sysTranslations[QStringLiteral("Russian")].insert(QStringLiteral("you_now_admin"), QStringLiteral("Теперь вы администратор"));
    m_sysTranslations[QStringLiteral("Russian")].insert(QStringLiteral("now_admin"), QStringLiteral("{0} теперь администратор"));
    m_sysTranslations[QStringLiteral("Russian")].insert(QStringLiteral("admin_approval_on"), QStringLiteral("{0} включил(а) подтверждение администратором для вступления в группу. Нажмите, чтобы изменить."));
    m_sysTranslations[QStringLiteral("Russian")].insert(QStringLiteral("no_longer_admin_you"), QStringLiteral("Вы больше не администратор"));
    m_sysTranslations[QStringLiteral("Russian")].insert(QStringLiteral("no_longer_admin"), QStringLiteral("{0} больше не администратор"));
    m_sysTranslations[QStringLiteral("Russian")].insert(QStringLiteral("admin_approval_off"), QStringLiteral("{0} отключил(а) подтверждение администратором для вступления в группу. Нажмите, чтобы изменить."));
    m_sysTranslations[QStringLiteral("Russian")].insert(QStringLiteral("joined_link"), QStringLiteral("{0} вступил(а) по ссылке."));
    m_sysTranslations[QStringLiteral("Russian")].insert(QStringLiteral("changed_icon"), QStringLiteral("{0} изменил(а) значок группы"));
    m_sysTranslations[QString::fromUtf8("Russian")].insert(QStringLiteral("changed_name"), QString::fromUtf8("{0} изменил(а) название группы на \"{1}\""));
    m_sysTranslations[QString::fromUtf8("Russian")].insert(QStringLiteral("changed_name_from_to"), QString::fromUtf8("{0} изменил(а) название группы с \"{1}\" на \"{2}\""));
    m_sysTranslations[QStringLiteral("Russian")].insert(QStringLiteral("changed_desc"), QStringLiteral("{0} изменил(а) описание группы"));
    m_sysTranslations[QStringLiteral("Russian")].insert(QStringLiteral("settings_only_admins_edit"), QStringLiteral("{0} изменил(а) настройки: редактировать параметры группы могут только администраторы"));
    m_sysTranslations[QStringLiteral("Russian")].insert(QStringLiteral("settings_all_edit"), QStringLiteral("{0} изменил(а) настройки: редактировать параметры группы могут все участники"));
    m_sysTranslations[QStringLiteral("Russian")].insert(QStringLiteral("settings_only_admins_send"), QStringLiteral("{0} изменил(а) настройки группы: отправлять сообщения могут только администраторы"));
    m_sysTranslations[QStringLiteral("Russian")].insert(QStringLiteral("settings_only_admins_add"), QStringLiteral("{0} изменил(а) настройки группы: добавлять участников могут только администраторы."));
    m_sysTranslations[QStringLiteral("Russian")].insert(QStringLiteral("settings_all_add"), QStringLiteral("{0} изменил(а) настройки группы: добавлять участников могут все."));
    m_sysTranslations[QStringLiteral("Russian")].insert(QStringLiteral("settings_all_send"), QStringLiteral("{0} изменил(а) настройки группы: отправлять сообщения могут все участники"));
    m_sysTranslations[QStringLiteral("Russian")].insert(QStringLiteral("settings_all_invite_link"), QStringLiteral("{0} изменил(а) настройки группы: приглашать по ссылке могут все участники."));
    m_sysTranslations[QStringLiteral("Russian")].insert(QStringLiteral("anyone_invite_link"), QStringLiteral("Любой участник этой группы может приглашать новых участников по ссылке."));
    m_sysTranslations[QStringLiteral("Russian")].insert(QStringLiteral("settings_only_admins_invite_link"), QStringLiteral("{0} изменил(а) настройки группы: приглашать по ссылке могут только администраторы."));
    m_sysTranslations[QStringLiteral("Russian")].insert(QStringLiteral("reset_link"), QStringLiteral("{0} сбросил(а) ссылку для приглашения в группу"));
    m_sysTranslations[QStringLiteral("Russian")].insert(QStringLiteral("disappear_on"), QStringLiteral("{0} включил(а) исчезающие сообщения. Новые сообщения будут удалены через {timer} после отправки (кроме сохранённых). Нажмите, чтобы изменить."));
    m_sysTranslations[QStringLiteral("Russian")].insert(QStringLiteral("disappear_off"), QStringLiteral("{0} выключил(а) исчезающие сообщения. Нажмите, чтобы изменить."));
    m_sysTranslations[QStringLiteral("Russian")].insert(QStringLiteral("disappear_off2"), QStringLiteral("{0} выключил(а) исчезающие сообщения. Нажмите, чтобы узнать больше."));
    m_sysTranslations[QStringLiteral("Russian")].insert(QStringLiteral("update_timer"), QStringLiteral("{0} обновил(а) таймер сообщений. Новые сообщения будут удалены через {timer} после отправки (кроме сохранённых). Нажмите, чтобы изменить."));
    m_sysTranslations[QStringLiteral("Russian")].insert(QStringLiteral("update_timer2"), QStringLiteral("{0} обновил(а) таймер сообщений. Новые сообщения будут удалены через {timer} после отправки (кроме сохранённых). Нажмите, чтобы узнать больше."));
    m_sysTranslations[QStringLiteral("Russian")].insert(QStringLiteral("voice_call"), QStringLiteral("Голосовой вызов. {1} • {0} присоединился(ась)"));
    m_sysTranslations[QStringLiteral("Russian")].insert(QStringLiteral("video_call"), QStringLiteral("Видеовызов. {1} • {0} присоединился(ась)"));
    m_sysTranslations[QStringLiteral("Russian")].insert(QStringLiteral("timer_24h"), QStringLiteral("24 часа"));
    m_sysTranslations[QStringLiteral("Russian")].insert(QStringLiteral("timer_7d"), QStringLiteral("7 дней"));
    m_sysTranslations[QStringLiteral("Russian")].insert(QStringLiteral("timer_90d"), QStringLiteral("90 дней"));
    m_sysTranslations[QStringLiteral("Russian")].insert(QStringLiteral("phone_number_changed"), QString::fromUtf8("{0} изменил(а) номер телефона. Напишите или добавьте новый номер."));

    // ── Arabic ───────────────────────────────────────────────────────────────
    m_sysTranslations[QString::fromUtf8("Arabic")].insert(QStringLiteral("created_group"), QString::fromUtf8("أنشأ {0} المجموعة \"{1}\""));
    m_sysTranslations[QStringLiteral("Arabic")].insert(QStringLiteral("created_group_noname"), QStringLiteral("أنشأ {0} هذه المجموعة"));
    m_sysTranslations[QStringLiteral("Arabic")].insert(QStringLiteral("e2e_note"), QStringLiteral("الرسائل والمكالمات مشفرة تشفيرًا تامًا من طرف إلى طرف. لا يمكن لأحد سوى أعضاء هذه المجموعة قراءتها أو الاستماع إليها أو مشاركتها."));
    m_sysTranslations[QStringLiteral("Arabic")].insert(QStringLiteral("left"), QStringLiteral("غادر {0}"));
    m_sysTranslations[QStringLiteral("Arabic")].insert(QStringLiteral("added"), QStringLiteral("أضاف {0} عضو {1}"));
    m_sysTranslations[QStringLiteral("Arabic")].insert(QStringLiteral("was_added"), QStringLiteral("تمت إضافة {0}"));
    m_sysTranslations[QStringLiteral("Arabic")].insert(QStringLiteral("removed"), QStringLiteral("أزال {0} عضو {1}"));
    m_sysTranslations[QStringLiteral("Arabic")].insert(QStringLiteral("you_now_admin"), QStringLiteral("أصبحت الآن مسؤولاً"));
    m_sysTranslations[QStringLiteral("Arabic")].insert(QStringLiteral("now_admin"), QStringLiteral("{0} مسؤول الآن"));
    m_sysTranslations[QStringLiteral("Arabic")].insert(QStringLiteral("admin_approval_on"), QStringLiteral("فعّل {0} موافقة المسؤول للانضمام إلى هذه المجموعة. اضغط للتغيير."));
    m_sysTranslations[QStringLiteral("Arabic")].insert(QStringLiteral("no_longer_admin_you"), QStringLiteral("لم تعد مسؤولاً"));
    m_sysTranslations[QStringLiteral("Arabic")].insert(QStringLiteral("no_longer_admin"), QStringLiteral("{0} لم يعد مسؤولاً"));
    m_sysTranslations[QStringLiteral("Arabic")].insert(QStringLiteral("admin_approval_off"), QStringLiteral("عطّل {0} موافقة المسؤول للانضمام إلى هذه المجموعة. اضغط للتغيير."));
    m_sysTranslations[QStringLiteral("Arabic")].insert(QStringLiteral("joined_link"), QStringLiteral("انضم {0} باستخدام رابط المجموعة."));
    m_sysTranslations[QStringLiteral("Arabic")].insert(QStringLiteral("changed_icon"), QStringLiteral("غيّر {0} أيقونة المجموعة"));
    m_sysTranslations[QString::fromUtf8("Arabic")].insert(QStringLiteral("changed_name"), QString::fromUtf8("غيّر {0} اسم المجموعة إلى \"{1}\""));
    m_sysTranslations[QString::fromUtf8("Arabic")].insert(QStringLiteral("changed_name_from_to"), QString::fromUtf8("غيّر {0} اسم المجموعة من \"{1}\" إلى \"{2}\""));
    m_sysTranslations[QStringLiteral("Arabic")].insert(QStringLiteral("changed_desc"), QStringLiteral("غيّر {0} وصف المجموعة"));
    m_sysTranslations[QStringLiteral("Arabic")].insert(QStringLiteral("settings_only_admins_edit"), QStringLiteral("غيّر {0} الإعدادات بحيث يمكن للمسؤولين فقط تعديل إعدادات المجموعة"));
    m_sysTranslations[QStringLiteral("Arabic")].insert(QStringLiteral("settings_all_edit"), QStringLiteral("غيّر {0} الإعدادات بحيث يمكن لجميع الأعضاء تعديل إعدادات المجموعة"));
    m_sysTranslations[QStringLiteral("Arabic")].insert(QStringLiteral("settings_only_admins_send"), QStringLiteral("غيّر {0} إعدادات المجموعة بحيث يمكن للمسؤولين فقط إرسال الرسائل"));
    m_sysTranslations[QStringLiteral("Arabic")].insert(QStringLiteral("settings_only_admins_add"), QStringLiteral("غيّر {0} إعدادات المجموعة بحيث يمكن للمسؤولين فقط إضافة أعضاء آخرين."));
    m_sysTranslations[QStringLiteral("Arabic")].insert(QStringLiteral("settings_all_add"), QStringLiteral("غيّر {0} إعدادات المجموعة بحيث يمكن لجميع الأعضاء إضافة أعضاء آخرين."));
    m_sysTranslations[QStringLiteral("Arabic")].insert(QStringLiteral("settings_all_send"), QStringLiteral("غيّر {0} إعدادات المجموعة بحيث يمكن لجميع الأعضاء إرسال الرسائل"));
    m_sysTranslations[QStringLiteral("Arabic")].insert(QStringLiteral("settings_all_invite_link"), QStringLiteral("غيّر {0} إعدادات المجموعة بحيث يمكن لجميع الأعضاء دعوة أشخاص بالرابط."));
    m_sysTranslations[QStringLiteral("Arabic")].insert(QStringLiteral("anyone_invite_link"), QStringLiteral("يمكن لأي عضو في هذه المجموعة دعوة أعضاء جدد باستخدام رابط المجموعة."));
    m_sysTranslations[QStringLiteral("Arabic")].insert(QStringLiteral("settings_only_admins_invite_link"), QStringLiteral("غيّر {0} إعدادات المجموعة بحيث يمكن للمسؤولين فقط دعوة أشخاص بالرابط."));
    m_sysTranslations[QStringLiteral("Arabic")].insert(QStringLiteral("reset_link"), QStringLiteral("أعاد {0} تعيين رابط دعوة المجموعة"));
    m_sysTranslations[QStringLiteral("Arabic")].insert(QStringLiteral("disappear_on"), QStringLiteral("فعّل {0} الرسائل المؤقتة. ستختفي الرسائل الجديدة من هذه المحادثة بعد {timer} من إرسالها، إلا إذا احتُفظ بها. اضغط للتغيير."));
    m_sysTranslations[QStringLiteral("Arabic")].insert(QStringLiteral("disappear_off"), QStringLiteral("عطّل {0} الرسائل المؤقتة. اضغط للتغيير."));
    m_sysTranslations[QStringLiteral("Arabic")].insert(QStringLiteral("disappear_off2"), QStringLiteral("عطّل {0} الرسائل المؤقتة. اضغط لمعرفة المزيد."));
    m_sysTranslations[QStringLiteral("Arabic")].insert(QStringLiteral("update_timer"), QStringLiteral("حدّث {0} مؤقت الرسائل. ستختفي الرسائل الجديدة من هذه المحادثة بعد {timer} من إرسالها، إلا إذا احتُفظ بها. اضغط للتغيير."));
    m_sysTranslations[QStringLiteral("Arabic")].insert(QStringLiteral("update_timer2"), QStringLiteral("حدّث {0} مؤقت الرسائل. ستختفي الرسائل الجديدة بعد {timer} من إرسالها، إلا إذا احتُفظ بها. اضغط لمعرفة المزيد."));
    m_sysTranslations[QStringLiteral("Arabic")].insert(QStringLiteral("voice_call"), QStringLiteral("مكالمة صوتية. {1} • انضم {0}"));
    m_sysTranslations[QStringLiteral("Arabic")].insert(QStringLiteral("video_call"), QStringLiteral("مكالمة مرئية. {1} • انضم {0}"));
    m_sysTranslations[QStringLiteral("Arabic")].insert(QStringLiteral("timer_24h"), QStringLiteral("24 ساعة"));
    m_sysTranslations[QStringLiteral("Arabic")].insert(QStringLiteral("timer_7d"), QStringLiteral("7 أيام"));
    m_sysTranslations[QStringLiteral("Arabic")].insert(QStringLiteral("timer_90d"), QStringLiteral("90 يومًا"));
    m_sysTranslations[QStringLiteral("Arabic")].insert(QStringLiteral("phone_number_changed"), QString::fromUtf8("غيّر {0} رقم هاتفه. راسل الرقم الجديد أو أضفه."));

    // ── Spanish ──────────────────────────────────────────────────────────────
    m_sysTranslations[QString::fromUtf8("Spanish")].insert(QStringLiteral("created_group"), QString::fromUtf8("{0} creó el grupo \"{1}\""));
    m_sysTranslations[QStringLiteral("Spanish")].insert(QStringLiteral("created_group_noname"), QStringLiteral("{0} creó este grupo"));
    m_sysTranslations[QStringLiteral("Spanish")].insert(QStringLiteral("e2e_note"), QStringLiteral("Los mensajes y las llamadas están cifrados de extremo a extremo. Solo las personas en este chat pueden leerlos, escucharlos o compartirlos."));
    m_sysTranslations[QStringLiteral("Spanish")].insert(QStringLiteral("left"), QStringLiteral("{0} salió"));
    m_sysTranslations[QStringLiteral("Spanish")].insert(QStringLiteral("added"), QStringLiteral("{0} agregó a {1}"));
    m_sysTranslations[QStringLiteral("Spanish")].insert(QStringLiteral("was_added"), QStringLiteral("{0} fue agregado(a)"));
    m_sysTranslations[QStringLiteral("Spanish")].insert(QStringLiteral("removed"), QStringLiteral("{0} eliminó a {1}"));
    m_sysTranslations[QStringLiteral("Spanish")].insert(QStringLiteral("you_now_admin"), QStringLiteral("Ahora eres administrador(a)"));
    m_sysTranslations[QStringLiteral("Spanish")].insert(QStringLiteral("now_admin"), QStringLiteral("{0} ahora es administrador(a)"));
    m_sysTranslations[QStringLiteral("Spanish")].insert(QStringLiteral("admin_approval_on"), QStringLiteral("{0} activó la aprobación de administrador para unirse al grupo. Toca para cambiar."));
    m_sysTranslations[QStringLiteral("Spanish")].insert(QStringLiteral("no_longer_admin_you"), QStringLiteral("Ya no eres administrador(a)"));
    m_sysTranslations[QStringLiteral("Spanish")].insert(QStringLiteral("no_longer_admin"), QStringLiteral("{0} ya no es administrador(a)"));
    m_sysTranslations[QStringLiteral("Spanish")].insert(QStringLiteral("admin_approval_off"), QStringLiteral("{0} desactivó la aprobación de administrador para unirse al grupo. Toca para cambiar."));
    m_sysTranslations[QStringLiteral("Spanish")].insert(QStringLiteral("joined_link"), QStringLiteral("{0} se unió usando el enlace del grupo."));
    m_sysTranslations[QStringLiteral("Spanish")].insert(QStringLiteral("changed_icon"), QStringLiteral("{0} cambió el ícono del grupo"));
    m_sysTranslations[QString::fromUtf8("Spanish")].insert(QStringLiteral("changed_name"), QString::fromUtf8("{0} cambió el nombre del grupo a \"{1}\""));
    m_sysTranslations[QString::fromUtf8("Spanish")].insert(QStringLiteral("changed_name_from_to"), QString::fromUtf8("{0} cambió el nombre del grupo de \"{1}\" a \"{2}\""));
    m_sysTranslations[QStringLiteral("Spanish")].insert(QStringLiteral("changed_desc"), QStringLiteral("{0} cambió la descripción del grupo"));
    m_sysTranslations[QStringLiteral("Spanish")].insert(QStringLiteral("settings_only_admins_edit"), QStringLiteral("{0} cambió los ajustes para que solo los administradores puedan editar los ajustes del grupo"));
    m_sysTranslations[QStringLiteral("Spanish")].insert(QStringLiteral("settings_all_edit"), QStringLiteral("{0} cambió los ajustes para que todos los miembros puedan editar los ajustes del grupo"));
    m_sysTranslations[QStringLiteral("Spanish")].insert(QStringLiteral("settings_only_admins_send"), QStringLiteral("{0} cambió los ajustes del grupo para que solo los administradores puedan enviar mensajes"));
    m_sysTranslations[QStringLiteral("Spanish")].insert(QStringLiteral("settings_only_admins_add"), QStringLiteral("{0} cambió los ajustes del grupo para que solo los administradores puedan agregar a otros."));
    m_sysTranslations[QStringLiteral("Spanish")].insert(QStringLiteral("settings_all_add"), QStringLiteral("{0} cambió los ajustes del grupo para que todos los miembros puedan agregar a otros."));
    m_sysTranslations[QStringLiteral("Spanish")].insert(QStringLiteral("settings_all_send"), QStringLiteral("{0} cambió los ajustes del grupo para que todos los miembros puedan enviar mensajes"));
    m_sysTranslations[QStringLiteral("Spanish")].insert(QStringLiteral("settings_all_invite_link"), QStringLiteral("{0} cambió los ajustes del grupo para que todos los miembros puedan invitar personas con el enlace."));
    m_sysTranslations[QStringLiteral("Spanish")].insert(QStringLiteral("anyone_invite_link"), QStringLiteral("Cualquier persona en este grupo puede invitar a nuevos miembros usando el enlace del grupo."));
    m_sysTranslations[QStringLiteral("Spanish")].insert(QStringLiteral("settings_only_admins_invite_link"), QStringLiteral("{0} cambió los ajustes para que solo los administradores puedan invitar personas con el enlace."));
    m_sysTranslations[QStringLiteral("Spanish")].insert(QStringLiteral("reset_link"), QStringLiteral("{0} restableció el enlace de invitación del grupo"));
    m_sysTranslations[QStringLiteral("Spanish")].insert(QStringLiteral("disappear_on"), QStringLiteral("{0} activó los mensajes temporales. Los mensajes nuevos desaparecerán {timer} después de ser enviados, excepto los guardados. Toca para cambiar."));
    m_sysTranslations[QStringLiteral("Spanish")].insert(QStringLiteral("disappear_off"), QStringLiteral("{0} desactivó los mensajes temporales. Toca para cambiar."));
    m_sysTranslations[QStringLiteral("Spanish")].insert(QStringLiteral("disappear_off2"), QStringLiteral("{0} desactivó los mensajes temporales. Toca para obtener más información."));
    m_sysTranslations[QStringLiteral("Spanish")].insert(QStringLiteral("update_timer"), QStringLiteral("{0} actualizó el temporizador. Los mensajes nuevos desaparecerán {timer} después de ser enviados, excepto los guardados. Toca para cambiar."));
    m_sysTranslations[QStringLiteral("Spanish")].insert(QStringLiteral("update_timer2"), QStringLiteral("{0} actualizó el temporizador. Los mensajes nuevos desaparecerán {timer} después de ser enviados, excepto los guardados. Toca para obtener más información."));
    m_sysTranslations[QStringLiteral("Spanish")].insert(QStringLiteral("voice_call"), QStringLiteral("Llamada de voz. {1} • {0} se unió"));
    m_sysTranslations[QStringLiteral("Spanish")].insert(QStringLiteral("video_call"), QStringLiteral("Videollamada. {1} • {0} se unió"));
    m_sysTranslations[QStringLiteral("Spanish")].insert(QStringLiteral("timer_24h"), QStringLiteral("24 horas"));
    m_sysTranslations[QStringLiteral("Spanish")].insert(QStringLiteral("timer_7d"), QStringLiteral("7 días"));
    m_sysTranslations[QStringLiteral("Spanish")].insert(QStringLiteral("timer_90d"), QStringLiteral("90 días"));
    m_sysTranslations[QStringLiteral("Spanish")].insert(QStringLiteral("phone_number_changed"), QString::fromUtf8("{0} cambió su número de teléfono. Escribe o agrega el nuevo número."));

    // ── Portuguese ───────────────────────────────────────────────────────────
    m_sysTranslations[QString::fromUtf8("Portuguese")].insert(QStringLiteral("created_group"), QString::fromUtf8("{0} criou o grupo \"{1}\""));
    m_sysTranslations[QStringLiteral("Portuguese")].insert(QStringLiteral("created_group_noname"), QStringLiteral("{0} criou este grupo"));
    m_sysTranslations[QStringLiteral("Portuguese")].insert(QStringLiteral("e2e_note"), QStringLiteral("As mensagens e chamadas são criptografadas de ponta a ponta. Somente as pessoas neste chat podem lê-las, ouvi-las ou compartilhá-las."));
    m_sysTranslations[QStringLiteral("Portuguese")].insert(QStringLiteral("left"), QStringLiteral("{0} saiu"));
    m_sysTranslations[QStringLiteral("Portuguese")].insert(QStringLiteral("added"), QStringLiteral("{0} adicionou {1}"));
    m_sysTranslations[QStringLiteral("Portuguese")].insert(QStringLiteral("was_added"), QStringLiteral("{0} foi adicionado(a)"));
    m_sysTranslations[QStringLiteral("Portuguese")].insert(QStringLiteral("removed"), QStringLiteral("{0} removeu {1}"));
    m_sysTranslations[QStringLiteral("Portuguese")].insert(QStringLiteral("you_now_admin"), QStringLiteral("Agora você é administrador(a)"));
    m_sysTranslations[QStringLiteral("Portuguese")].insert(QStringLiteral("now_admin"), QStringLiteral("{0} agora é administrador(a)"));
    m_sysTranslations[QStringLiteral("Portuguese")].insert(QStringLiteral("admin_approval_on"), QStringLiteral("{0} ativou a aprovação de administrador para entrar neste grupo. Toque para alterar."));
    m_sysTranslations[QStringLiteral("Portuguese")].insert(QStringLiteral("no_longer_admin_you"), QStringLiteral("Você não é mais administrador(a)"));
    m_sysTranslations[QStringLiteral("Portuguese")].insert(QStringLiteral("no_longer_admin"), QStringLiteral("{0} não é mais administrador(a)"));
    m_sysTranslations[QStringLiteral("Portuguese")].insert(QStringLiteral("admin_approval_off"), QStringLiteral("{0} desativou a aprovação de administrador para entrar neste grupo. Toque para alterar."));
    m_sysTranslations[QStringLiteral("Portuguese")].insert(QStringLiteral("joined_link"), QStringLiteral("{0} entrou usando o link do grupo."));
    m_sysTranslations[QStringLiteral("Portuguese")].insert(QStringLiteral("changed_icon"), QStringLiteral("{0} alterou o ícone do grupo"));
    m_sysTranslations[QString::fromUtf8("Portuguese")].insert(QStringLiteral("changed_name"), QString::fromUtf8("{0} alterou o nome do grupo para \"{1}\""));
    m_sysTranslations[QString::fromUtf8("Portuguese")].insert(QStringLiteral("changed_name_from_to"), QString::fromUtf8("{0} alterou o nome do grupo de \"{1}\" para \"{2}\""));
    m_sysTranslations[QStringLiteral("Portuguese")].insert(QStringLiteral("changed_desc"), QStringLiteral("{0} alterou a descrição do grupo"));
    m_sysTranslations[QStringLiteral("Portuguese")].insert(QStringLiteral("settings_only_admins_edit"), QStringLiteral("{0} alterou as configurações para que apenas administradores possam editar as configurações do grupo"));
    m_sysTranslations[QStringLiteral("Portuguese")].insert(QStringLiteral("settings_all_edit"), QStringLiteral("{0} alterou as configurações para que todos os membros possam editar as configurações do grupo"));
    m_sysTranslations[QStringLiteral("Portuguese")].insert(QStringLiteral("settings_only_admins_send"), QStringLiteral("{0} alterou as configurações do grupo para que apenas administradores possam enviar mensagens"));
    m_sysTranslations[QStringLiteral("Portuguese")].insert(QStringLiteral("settings_only_admins_add"), QStringLiteral("{0} alterou as configurações do grupo para que apenas administradores possam adicionar outros."));
    m_sysTranslations[QStringLiteral("Portuguese")].insert(QStringLiteral("settings_all_add"), QStringLiteral("{0} alterou as configurações do grupo para que todos os membros possam adicionar outros."));
    m_sysTranslations[QStringLiteral("Portuguese")].insert(QStringLiteral("settings_all_send"), QStringLiteral("{0} alterou as configurações do grupo para que todos os membros possam enviar mensagens"));
    m_sysTranslations[QStringLiteral("Portuguese")].insert(QStringLiteral("settings_all_invite_link"), QStringLiteral("{0} alterou as configurações do grupo para que todos possam convidar pelo link."));
    m_sysTranslations[QStringLiteral("Portuguese")].insert(QStringLiteral("anyone_invite_link"), QStringLiteral("Qualquer pessoa neste grupo pode convidar novos membros usando o link do grupo."));
    m_sysTranslations[QStringLiteral("Portuguese")].insert(QStringLiteral("settings_only_admins_invite_link"), QStringLiteral("{0} alterou as configurações para que apenas administradores possam convidar pelo link."));
    m_sysTranslations[QStringLiteral("Portuguese")].insert(QStringLiteral("reset_link"), QStringLiteral("{0} redefiniu o link de convite do grupo"));
    m_sysTranslations[QStringLiteral("Portuguese")].insert(QStringLiteral("disappear_on"), QStringLiteral("{0} ativou as mensagens temporárias. As novas mensagens desaparecerão {timer} após o envio, exceto as salvas. Toque para alterar."));
    m_sysTranslations[QStringLiteral("Portuguese")].insert(QStringLiteral("disappear_off"), QStringLiteral("{0} desativou as mensagens temporárias. Toque para alterar."));
    m_sysTranslations[QStringLiteral("Portuguese")].insert(QStringLiteral("disappear_off2"), QStringLiteral("{0} desativou as mensagens temporárias. Toque para saber mais."));
    m_sysTranslations[QStringLiteral("Portuguese")].insert(QStringLiteral("update_timer"), QStringLiteral("{0} atualizou o temporizador. As novas mensagens desaparecerão {timer} após o envio, exceto as salvas. Toque para alterar."));
    m_sysTranslations[QStringLiteral("Portuguese")].insert(QStringLiteral("update_timer2"), QStringLiteral("{0} atualizou o temporizador. As novas mensagens desaparecerão {timer} após o envio, exceto as salvas. Toque para saber mais."));
    m_sysTranslations[QStringLiteral("Portuguese")].insert(QStringLiteral("voice_call"), QStringLiteral("Chamada de voz. {1} • {0} entrou"));
    m_sysTranslations[QStringLiteral("Portuguese")].insert(QStringLiteral("video_call"), QStringLiteral("Videochamada. {1} • {0} entrou"));
    m_sysTranslations[QStringLiteral("Portuguese")].insert(QStringLiteral("timer_24h"), QStringLiteral("24 horas"));
    m_sysTranslations[QStringLiteral("Portuguese")].insert(QStringLiteral("timer_7d"), QStringLiteral("7 dias"));
    m_sysTranslations[QStringLiteral("Portuguese")].insert(QStringLiteral("timer_90d"), QStringLiteral("90 dias"));
    m_sysTranslations[QStringLiteral("Portuguese")].insert(QStringLiteral("phone_number_changed"), QString::fromUtf8("{0} mudou o número de telefone. Envie uma mensagem ou adicione o novo número."));

    // ── Italian ──────────────────────────────────────────────────────────────
    m_sysTranslations[QString::fromUtf8("Italian")].insert(QStringLiteral("created_group"), QString::fromUtf8("{0} ha creato il gruppo \"{1}\""));
    m_sysTranslations[QStringLiteral("Italian")].insert(QStringLiteral("created_group_noname"), QStringLiteral("{0} ha creato questo gruppo"));
    m_sysTranslations[QStringLiteral("Italian")].insert(QStringLiteral("e2e_note"), QStringLiteral("I messaggi e le chiamate sono crittografati end-to-end. Solo le persone in questa chat possono leggerli, ascoltarli o condividerli."));
    m_sysTranslations[QStringLiteral("Italian")].insert(QStringLiteral("left"), QStringLiteral("{0} è uscito/a"));
    m_sysTranslations[QStringLiteral("Italian")].insert(QStringLiteral("added"), QStringLiteral("{0} ha aggiunto {1}"));
    m_sysTranslations[QStringLiteral("Italian")].insert(QStringLiteral("was_added"), QStringLiteral("{0} è stato/a aggiunto/a"));
    m_sysTranslations[QStringLiteral("Italian")].insert(QStringLiteral("removed"), QStringLiteral("{0} ha rimosso {1}"));
    m_sysTranslations[QStringLiteral("Italian")].insert(QStringLiteral("you_now_admin"), QStringLiteral("Ora sei un amministratore"));
    m_sysTranslations[QStringLiteral("Italian")].insert(QStringLiteral("now_admin"), QStringLiteral("{0} è ora un amministratore"));
    m_sysTranslations[QStringLiteral("Italian")].insert(QStringLiteral("admin_approval_on"), QStringLiteral("{0} ha attivato l'approvazione dell'amministratore per unirsi al gruppo. Tocca per modificare."));
    m_sysTranslations[QStringLiteral("Italian")].insert(QStringLiteral("no_longer_admin_you"), QStringLiteral("Non sei più un amministratore"));
    m_sysTranslations[QStringLiteral("Italian")].insert(QStringLiteral("no_longer_admin"), QStringLiteral("{0} non è più un amministratore"));
    m_sysTranslations[QStringLiteral("Italian")].insert(QStringLiteral("admin_approval_off"), QStringLiteral("{0} ha disattivato l'approvazione dell'amministratore. Tocca per modificare."));
    m_sysTranslations[QStringLiteral("Italian")].insert(QStringLiteral("joined_link"), QStringLiteral("{0} si è unito/a usando il link del gruppo."));
    m_sysTranslations[QStringLiteral("Italian")].insert(QStringLiteral("changed_icon"), QStringLiteral("{0} ha cambiato l'icona del gruppo"));
    m_sysTranslations[QString::fromUtf8("Italian")].insert(QStringLiteral("changed_name"), QString::fromUtf8("{0} ha cambiato il nome del gruppo in \"{1}\""));
    m_sysTranslations[QString::fromUtf8("Italian")].insert(QStringLiteral("changed_name_from_to"), QString::fromUtf8("{0} ha cambiato il nome del gruppo da \"{1}\" a \"{2}\""));
    m_sysTranslations[QStringLiteral("Italian")].insert(QStringLiteral("changed_desc"), QStringLiteral("{0} ha cambiato la descrizione del gruppo"));
    m_sysTranslations[QStringLiteral("Italian")].insert(QStringLiteral("settings_only_admins_edit"), QStringLiteral("{0} ha modificato le impostazioni in modo che solo gli amministratori possano modificarle"));
    m_sysTranslations[QStringLiteral("Italian")].insert(QStringLiteral("settings_all_edit"), QStringLiteral("{0} ha modificato le impostazioni in modo che tutti i membri possano modificarle"));
    m_sysTranslations[QStringLiteral("Italian")].insert(QStringLiteral("settings_only_admins_send"), QStringLiteral("{0} ha modificato le impostazioni del gruppo: solo gli amministratori possono inviare messaggi"));
    m_sysTranslations[QStringLiteral("Italian")].insert(QStringLiteral("settings_only_admins_add"), QStringLiteral("{0} ha modificato le impostazioni: solo gli amministratori possono aggiungere altri."));
    m_sysTranslations[QStringLiteral("Italian")].insert(QStringLiteral("settings_all_add"), QStringLiteral("{0} ha modificato le impostazioni: tutti i membri possono aggiungere altri."));
    m_sysTranslations[QStringLiteral("Italian")].insert(QStringLiteral("settings_all_send"), QStringLiteral("{0} ha modificato le impostazioni: tutti i membri possono inviare messaggi"));
    m_sysTranslations[QStringLiteral("Italian")].insert(QStringLiteral("settings_all_invite_link"), QStringLiteral("{0} ha modificato le impostazioni: tutti possono invitare con il link."));
    m_sysTranslations[QStringLiteral("Italian")].insert(QStringLiteral("anyone_invite_link"), QStringLiteral("Tutti in questo gruppo possono invitare nuovi membri usando il link del gruppo."));
    m_sysTranslations[QStringLiteral("Italian")].insert(QStringLiteral("settings_only_admins_invite_link"), QStringLiteral("{0} ha modificato le impostazioni: solo gli amministratori possono invitare con il link."));
    m_sysTranslations[QStringLiteral("Italian")].insert(QStringLiteral("reset_link"), QStringLiteral("{0} ha reimpostato il link di invito del gruppo"));
    m_sysTranslations[QStringLiteral("Italian")].insert(QStringLiteral("disappear_on"), QStringLiteral("{0} ha attivato i messaggi temporanei. I nuovi messaggi spariranno {timer} dopo l'invio, tranne quelli salvati. Tocca per modificare."));
    m_sysTranslations[QStringLiteral("Italian")].insert(QStringLiteral("disappear_off"), QStringLiteral("{0} ha disattivato i messaggi temporanei. Tocca per modificare."));
    m_sysTranslations[QStringLiteral("Italian")].insert(QStringLiteral("disappear_off2"), QStringLiteral("{0} ha disattivato i messaggi temporanei. Tocca per saperne di più."));
    m_sysTranslations[QStringLiteral("Italian")].insert(QStringLiteral("update_timer"), QStringLiteral("{0} ha aggiornato il timer. I nuovi messaggi spariranno {timer} dopo l'invio, tranne quelli salvati. Tocca per modificare."));
    m_sysTranslations[QStringLiteral("Italian")].insert(QStringLiteral("update_timer2"), QStringLiteral("{0} ha aggiornato il timer. I nuovi messaggi spariranno {timer} dopo l'invio, tranne quelli salvati. Tocca per saperne di più."));
    m_sysTranslations[QStringLiteral("Italian")].insert(QStringLiteral("voice_call"), QStringLiteral("Chiamata vocale. {1} • {0} si è unito/a"));
    m_sysTranslations[QStringLiteral("Italian")].insert(QStringLiteral("video_call"), QStringLiteral("Videochiamata. {1} • {0} si è unito/a"));
    m_sysTranslations[QStringLiteral("Italian")].insert(QStringLiteral("timer_24h"), QStringLiteral("24 ore"));
    m_sysTranslations[QStringLiteral("Italian")].insert(QStringLiteral("timer_7d"), QStringLiteral("7 giorni"));
    m_sysTranslations[QStringLiteral("Italian")].insert(QStringLiteral("timer_90d"), QStringLiteral("90 giorni"));
    m_sysTranslations[QStringLiteral("Italian")].insert(QStringLiteral("phone_number_changed"), QStringLiteral("{0} ha cambiato il numero di telefono. Scrivi o aggiungi il nuovo numero."));

    // ── French ───────────────────────────────────────────────────────────────
    m_sysTranslations[QString::fromUtf8("French")].insert(QStringLiteral("created_group"), QString::fromUtf8("{0} a créé le groupe \"{1}\""));
    m_sysTranslations[QStringLiteral("French")].insert(QStringLiteral("created_group_noname"), QStringLiteral("{0} a créé ce groupe"));
    m_sysTranslations[QStringLiteral("French")].insert(QStringLiteral("e2e_note"), QStringLiteral("Les messages et les appels sont chiffrés de bout en bout. Seules les personnes de cette discussion peuvent les lire, les écouter ou les partager."));
    m_sysTranslations[QStringLiteral("French")].insert(QStringLiteral("left"), QStringLiteral("{0} a quitté le groupe"));
    m_sysTranslations[QStringLiteral("French")].insert(QStringLiteral("added"), QStringLiteral("{0} a ajouté {1}"));
    m_sysTranslations[QStringLiteral("French")].insert(QStringLiteral("was_added"), QStringLiteral("{0} a été ajouté(e)"));
    m_sysTranslations[QStringLiteral("French")].insert(QStringLiteral("removed"), QStringLiteral("{0} a supprimé {1}"));
    m_sysTranslations[QStringLiteral("French")].insert(QStringLiteral("you_now_admin"), QStringLiteral("Vous êtes maintenant administrateur"));
    m_sysTranslations[QStringLiteral("French")].insert(QStringLiteral("now_admin"), QStringLiteral("{0} est maintenant administrateur"));
    m_sysTranslations[QStringLiteral("French")].insert(QStringLiteral("admin_approval_on"), QStringLiteral("{0} a activé l'approbation admin pour rejoindre ce groupe. Appuyez pour modifier."));
    m_sysTranslations[QStringLiteral("French")].insert(QStringLiteral("no_longer_admin_you"), QStringLiteral("Vous n'êtes plus administrateur"));
    m_sysTranslations[QStringLiteral("French")].insert(QStringLiteral("no_longer_admin"), QStringLiteral("{0} n'est plus administrateur"));
    m_sysTranslations[QStringLiteral("French")].insert(QStringLiteral("admin_approval_off"), QStringLiteral("{0} a désactivé l'approbation admin. Appuyez pour modifier."));
    m_sysTranslations[QStringLiteral("French")].insert(QStringLiteral("joined_link"), QStringLiteral("{0} a rejoint via le lien du groupe."));
    m_sysTranslations[QStringLiteral("French")].insert(QStringLiteral("changed_icon"), QStringLiteral("{0} a modifié l'icône du groupe"));
    m_sysTranslations[QString::fromUtf8("French")].insert(QStringLiteral("changed_name"), QString::fromUtf8("{0} a changé le nom du groupe en \"{1}\""));
    m_sysTranslations[QString::fromUtf8("French")].insert(QStringLiteral("changed_name_from_to"), QString::fromUtf8("{0} a changé le nom du groupe de \"{1}\" en \"{2}\""));
    m_sysTranslations[QStringLiteral("French")].insert(QStringLiteral("changed_desc"), QStringLiteral("{0} a modifié la description du groupe"));
    m_sysTranslations[QStringLiteral("French")].insert(QStringLiteral("settings_only_admins_edit"), QStringLiteral("{0} a modifié les paramètres pour que seuls les admins puissent modifier les paramètres du groupe"));
    m_sysTranslations[QStringLiteral("French")].insert(QStringLiteral("settings_all_edit"), QStringLiteral("{0} a modifié les paramètres pour que tous les membres puissent modifier les paramètres du groupe"));
    m_sysTranslations[QStringLiteral("French")].insert(QStringLiteral("settings_only_admins_send"), QStringLiteral("{0} a modifié les paramètres du groupe : seuls les admins peuvent envoyer des messages"));
    m_sysTranslations[QStringLiteral("French")].insert(QStringLiteral("settings_only_admins_add"), QStringLiteral("{0} a modifié les paramètres du groupe : seuls les admins peuvent ajouter des membres."));
    m_sysTranslations[QStringLiteral("French")].insert(QStringLiteral("settings_all_add"), QStringLiteral("{0} a modifié les paramètres du groupe : tous les membres peuvent ajouter des membres."));
    m_sysTranslations[QStringLiteral("French")].insert(QStringLiteral("settings_all_send"), QStringLiteral("{0} a modifié les paramètres du groupe : tous les membres peuvent envoyer des messages"));
    m_sysTranslations[QStringLiteral("French")].insert(QStringLiteral("settings_all_invite_link"), QStringLiteral("{0} a modifié les paramètres du groupe : tous peuvent inviter par lien."));
    m_sysTranslations[QStringLiteral("French")].insert(QStringLiteral("anyone_invite_link"), QStringLiteral("Toute personne dans ce groupe peut inviter de nouveaux membres via le lien du groupe."));
    m_sysTranslations[QStringLiteral("French")].insert(QStringLiteral("settings_only_admins_invite_link"), QStringLiteral("{0} a modifié les paramètres : seuls les admins peuvent inviter par lien."));
    m_sysTranslations[QStringLiteral("French")].insert(QStringLiteral("reset_link"), QStringLiteral("{0} a réinitialisé le lien d'invitation du groupe"));
    m_sysTranslations[QStringLiteral("French")].insert(QStringLiteral("disappear_on"), QStringLiteral("{0} a activé les messages éphémères. Les nouveaux messages disparaîtront {timer} après l'envoi, sauf s'ils sont conservés. Appuyez pour modifier."));
    m_sysTranslations[QStringLiteral("French")].insert(QStringLiteral("disappear_off"), QStringLiteral("{0} a désactivé les messages éphémères. Appuyez pour modifier."));
    m_sysTranslations[QStringLiteral("French")].insert(QStringLiteral("disappear_off2"), QStringLiteral("{0} a désactivé les messages éphémères. Appuyez pour en savoir plus."));
    m_sysTranslations[QStringLiteral("French")].insert(QStringLiteral("update_timer"), QStringLiteral("{0} a mis à jour le minuteur. Les nouveaux messages disparaîtront {timer} après l'envoi, sauf s'ils sont conservés. Appuyez pour modifier."));
    m_sysTranslations[QStringLiteral("French")].insert(QStringLiteral("update_timer2"), QStringLiteral("{0} a mis à jour le minuteur. Les nouveaux messages disparaîtront {timer} après l'envoi, sauf s'ils sont conservés. Appuyez pour en savoir plus."));
    m_sysTranslations[QStringLiteral("French")].insert(QStringLiteral("voice_call"), QStringLiteral("Appel vocal. {1} • {0} a rejoint"));
    m_sysTranslations[QStringLiteral("French")].insert(QStringLiteral("video_call"), QStringLiteral("Appel vidéo. {1} • {0} a rejoint"));
    m_sysTranslations[QStringLiteral("French")].insert(QStringLiteral("timer_24h"), QStringLiteral("24 heures"));
    m_sysTranslations[QStringLiteral("French")].insert(QStringLiteral("timer_7d"), QStringLiteral("7 jours"));
    m_sysTranslations[QStringLiteral("French")].insert(QStringLiteral("timer_90d"), QStringLiteral("90 jours"));
    m_sysTranslations[QStringLiteral("French")].insert(QStringLiteral("phone_number_changed"), QString::fromUtf8("{0} a changé de numéro de téléphone. Envoyez un message ou ajoutez le nouveau numéro."));

    // ── German ───────────────────────────────────────────────────────────────
    m_sysTranslations[QString::fromUtf8("German")].insert(QStringLiteral("created_group"), QString::fromUtf8("{0} hat die Gruppe \"{1}\" erstellt"));
    m_sysTranslations[QStringLiteral("German")].insert(QStringLiteral("created_group_noname"), QStringLiteral("{0} hat diese Gruppe erstellt"));
    m_sysTranslations[QStringLiteral("German")].insert(QStringLiteral("e2e_note"), QStringLiteral("Nachrichten und Anrufe sind Ende-zu-Ende-verschlüsselt. Nur Personen in diesem Chat können sie lesen, anhören oder teilen."));
    m_sysTranslations[QStringLiteral("German")].insert(QStringLiteral("left"), QStringLiteral("{0} hat die Gruppe verlassen"));
    m_sysTranslations[QStringLiteral("German")].insert(QStringLiteral("added"), QStringLiteral("{0} hat {1} hinzugefügt"));
    m_sysTranslations[QStringLiteral("German")].insert(QStringLiteral("was_added"), QStringLiteral("{0} wurde hinzugefügt"));
    m_sysTranslations[QStringLiteral("German")].insert(QStringLiteral("removed"), QStringLiteral("{0} hat {1} entfernt"));
    m_sysTranslations[QStringLiteral("German")].insert(QStringLiteral("you_now_admin"), QStringLiteral("Du bist jetzt ein Administrator"));
    m_sysTranslations[QStringLiteral("German")].insert(QStringLiteral("now_admin"), QStringLiteral("{0} ist jetzt Administrator"));
    m_sysTranslations[QStringLiteral("German")].insert(QStringLiteral("admin_approval_on"), QStringLiteral("{0} hat die Admin-Genehmigung zum Beitreten dieser Gruppe aktiviert. Tippe zum Ändern."));
    m_sysTranslations[QStringLiteral("German")].insert(QStringLiteral("no_longer_admin_you"), QStringLiteral("Du bist kein Administrator mehr"));
    m_sysTranslations[QStringLiteral("German")].insert(QStringLiteral("no_longer_admin"), QStringLiteral("{0} ist kein Administrator mehr"));
    m_sysTranslations[QStringLiteral("German")].insert(QStringLiteral("admin_approval_off"), QStringLiteral("{0} hat die Admin-Genehmigung zum Beitreten deaktiviert. Tippe zum Ändern."));
    m_sysTranslations[QStringLiteral("German")].insert(QStringLiteral("joined_link"), QStringLiteral("{0} ist über den Gruppenlink beigetreten."));
    m_sysTranslations[QStringLiteral("German")].insert(QStringLiteral("changed_icon"), QStringLiteral("{0} hat das Gruppen-Icon geändert"));
    m_sysTranslations[QString::fromUtf8("German")].insert(QStringLiteral("changed_name"), QString::fromUtf8("{0} hat den Gruppennamen in \"{1}\" geändert"));
    m_sysTranslations[QString::fromUtf8("German")].insert(QStringLiteral("changed_name_from_to"), QString::fromUtf8("{0} hat den Gruppennamen von \"{1}\" in \"{2}\" geändert"));
    m_sysTranslations[QStringLiteral("German")].insert(QStringLiteral("changed_desc"), QStringLiteral("{0} hat die Gruppenbeschreibung geändert"));
    m_sysTranslations[QStringLiteral("German")].insert(QStringLiteral("settings_only_admins_edit"), QStringLiteral("{0} hat die Einstellungen geändert: Nur Admins können Gruppeneinstellungen bearbeiten"));
    m_sysTranslations[QStringLiteral("German")].insert(QStringLiteral("settings_all_edit"), QStringLiteral("{0} hat die Einstellungen geändert: Alle Mitglieder können Gruppeneinstellungen bearbeiten"));
    m_sysTranslations[QStringLiteral("German")].insert(QStringLiteral("settings_only_admins_send"), QStringLiteral("{0} hat die Gruppeneinstellungen geändert: Nur Admins können Nachrichten senden"));
    m_sysTranslations[QStringLiteral("German")].insert(QStringLiteral("settings_only_admins_add"), QStringLiteral("{0} hat die Gruppeneinstellungen geändert: Nur Admins können andere hinzufügen."));
    m_sysTranslations[QStringLiteral("German")].insert(QStringLiteral("settings_all_add"), QStringLiteral("{0} hat die Gruppeneinstellungen geändert: Alle Mitglieder können andere hinzufügen."));
    m_sysTranslations[QStringLiteral("German")].insert(QStringLiteral("settings_all_send"), QStringLiteral("{0} hat die Gruppeneinstellungen geändert: Alle Mitglieder können Nachrichten senden"));
    m_sysTranslations[QStringLiteral("German")].insert(QStringLiteral("settings_all_invite_link"), QStringLiteral("{0} hat die Einstellungen geändert: Alle können per Link einladen."));
    m_sysTranslations[QStringLiteral("German")].insert(QStringLiteral("anyone_invite_link"), QStringLiteral("Jeder in dieser Gruppe kann neue Mitglieder über den Gruppenlink einladen."));
    m_sysTranslations[QStringLiteral("German")].insert(QStringLiteral("settings_only_admins_invite_link"), QStringLiteral("{0} hat die Einstellungen geändert: Nur Admins können per Link einladen."));
    m_sysTranslations[QStringLiteral("German")].insert(QStringLiteral("reset_link"), QStringLiteral("{0} hat den Einladungslink der Gruppe zurückgesetzt"));
    m_sysTranslations[QStringLiteral("German")].insert(QStringLiteral("disappear_on"), QStringLiteral("{0} hat verschwindende Nachrichten aktiviert. Neue Nachrichten verschwinden {timer} nach dem Senden, außer wenn gespeichert. Tippe zum Ändern."));
    m_sysTranslations[QStringLiteral("German")].insert(QStringLiteral("disappear_off"), QStringLiteral("{0} hat verschwindende Nachrichten deaktiviert. Tippe zum Ändern."));
    m_sysTranslations[QStringLiteral("German")].insert(QStringLiteral("disappear_off2"), QStringLiteral("{0} hat verschwindende Nachrichten deaktiviert. Tippe, um mehr zu erfahren."));
    m_sysTranslations[QStringLiteral("German")].insert(QStringLiteral("update_timer"), QStringLiteral("{0} hat den Nachrichten-Timer aktualisiert. Neue Nachrichten verschwinden {timer} nach dem Senden, außer wenn gespeichert. Tippe zum Ändern."));
    m_sysTranslations[QStringLiteral("German")].insert(QStringLiteral("update_timer2"), QStringLiteral("{0} hat den Nachrichten-Timer aktualisiert. Neue Nachrichten verschwinden {timer} nach dem Senden. Tippe, um mehr zu erfahren."));
    m_sysTranslations[QStringLiteral("German")].insert(QStringLiteral("voice_call"), QStringLiteral("Sprachanruf. {1} • {0} ist beigetreten"));
    m_sysTranslations[QStringLiteral("German")].insert(QStringLiteral("video_call"), QStringLiteral("Videoanruf. {1} • {0} ist beigetreten"));
    m_sysTranslations[QStringLiteral("German")].insert(QStringLiteral("timer_24h"), QStringLiteral("24 Stunden"));
    m_sysTranslations[QStringLiteral("German")].insert(QStringLiteral("timer_7d"), QStringLiteral("7 Tage"));
    m_sysTranslations[QStringLiteral("German")].insert(QStringLiteral("timer_90d"), QStringLiteral("90 Tage"));
    m_sysTranslations[QStringLiteral("German")].insert(QStringLiteral("phone_number_changed"), QString::fromUtf8("{0} hat die Telefonnummer geändert. Schreibe oder füge die neue Nummer hinzu."));

    // ── Chinese ───────────────────────────────────────────────────────────────
    m_sysTranslations[QStringLiteral("Chinese")].insert(QStringLiteral("created_group"), QString::fromUtf8("{0}创建了群组\"{1}\""));
    m_sysTranslations[QStringLiteral("Chinese")].insert(QStringLiteral("created_group_noname"), QStringLiteral("{0}创建了此群组"));
    m_sysTranslations[QStringLiteral("Chinese")].insert(QStringLiteral("e2e_note"), QStringLiteral("消息和通话均已端对端加密，只有此聊天中的人才能读取、收听或分享这些内容。"));
    m_sysTranslations[QStringLiteral("Chinese")].insert(QStringLiteral("left"), QStringLiteral("{0}已退出"));
    m_sysTranslations[QStringLiteral("Chinese")].insert(QStringLiteral("added"), QStringLiteral("{0}添加了{1}"));
    m_sysTranslations[QStringLiteral("Chinese")].insert(QStringLiteral("was_added"), QStringLiteral("{0}已被添加"));
    m_sysTranslations[QStringLiteral("Chinese")].insert(QStringLiteral("removed"), QStringLiteral("{0}已移除{1}"));
    m_sysTranslations[QStringLiteral("Chinese")].insert(QStringLiteral("you_now_admin"), QStringLiteral("您现在是管理员"));
    m_sysTranslations[QStringLiteral("Chinese")].insert(QStringLiteral("now_admin"), QStringLiteral("{0}现在是管理员"));
    m_sysTranslations[QStringLiteral("Chinese")].insert(QStringLiteral("admin_approval_on"), QStringLiteral("{0}已开启管理员审批以加入此群组。点击更改。"));
    m_sysTranslations[QStringLiteral("Chinese")].insert(QStringLiteral("no_longer_admin_you"), QStringLiteral("您不再是管理员"));
    m_sysTranslations[QStringLiteral("Chinese")].insert(QStringLiteral("no_longer_admin"), QStringLiteral("{0}不再是管理员"));
    m_sysTranslations[QStringLiteral("Chinese")].insert(QStringLiteral("admin_approval_off"), QStringLiteral("{0}已关闭管理员审批。点击更改。"));
    m_sysTranslations[QStringLiteral("Chinese")].insert(QStringLiteral("joined_link"), QStringLiteral("{0}通过群组链接加入。"));
    m_sysTranslations[QStringLiteral("Chinese")].insert(QStringLiteral("changed_icon"), QStringLiteral("{0}更改了群组头像"));
    m_sysTranslations[QStringLiteral("Chinese")].insert(QStringLiteral("changed_name"), QString::fromUtf8("{0}将群组名称更改为\"{1}\""));
    m_sysTranslations[QStringLiteral("Chinese")].insert(QStringLiteral("changed_name_from_to"), QString::fromUtf8("{0}将群组名称从\"{1}\"更改为\"{2}\""));
    m_sysTranslations[QStringLiteral("Chinese")].insert(QStringLiteral("changed_desc"), QStringLiteral("{0}更改了群组描述"));
    m_sysTranslations[QStringLiteral("Chinese")].insert(QStringLiteral("settings_only_admins_edit"), QStringLiteral("{0}更改了设置，现在只有管理员可以编辑群组设置"));
    m_sysTranslations[QStringLiteral("Chinese")].insert(QStringLiteral("settings_all_edit"), QStringLiteral("{0}更改了设置，现在所有成员均可编辑群组设置"));
    m_sysTranslations[QStringLiteral("Chinese")].insert(QStringLiteral("settings_only_admins_send"), QStringLiteral("{0}更改了群组设置，现在只有管理员可以发送消息"));
    m_sysTranslations[QStringLiteral("Chinese")].insert(QStringLiteral("settings_only_admins_add"), QStringLiteral("{0}更改了群组设置，现在只有管理员可以添加其他人。"));
    m_sysTranslations[QStringLiteral("Chinese")].insert(QStringLiteral("settings_all_add"), QStringLiteral("{0}更改了群组设置，现在所有成员均可添加其他人。"));
    m_sysTranslations[QStringLiteral("Chinese")].insert(QStringLiteral("settings_all_send"), QStringLiteral("{0}更改了群组设置，现在所有成员均可发送消息"));
    m_sysTranslations[QStringLiteral("Chinese")].insert(QStringLiteral("settings_all_invite_link"), QStringLiteral("{0}更改了群组设置，现在所有成员均可通过群组链接邀请他人。"));
    m_sysTranslations[QStringLiteral("Chinese")].insert(QStringLiteral("anyone_invite_link"), QStringLiteral("此群组中的任何人都可以使用群组链接邀请新成员。"));
    m_sysTranslations[QStringLiteral("Chinese")].insert(QStringLiteral("settings_only_admins_invite_link"), QStringLiteral("{0}更改了设置，现在只有管理员可以通过链接邀请他人。"));
    m_sysTranslations[QStringLiteral("Chinese")].insert(QStringLiteral("reset_link"), QStringLiteral("{0}重置了群组邀请链接"));
    m_sysTranslations[QStringLiteral("Chinese")].insert(QStringLiteral("disappear_on"), QStringLiteral("{0}已开启阅后即焚。新消息将在发送后{timer}从此聊天中消失（已保留的消息除外）。点击更改。"));
    m_sysTranslations[QStringLiteral("Chinese")].insert(QStringLiteral("disappear_off"), QStringLiteral("{0}已关闭阅后即焚。点击更改。"));
    m_sysTranslations[QStringLiteral("Chinese")].insert(QStringLiteral("disappear_off2"), QStringLiteral("{0}已关闭阅后即焚。点击了解更多。"));
    m_sysTranslations[QStringLiteral("Chinese")].insert(QStringLiteral("update_timer"), QStringLiteral("{0}更新了消息计时器。新消息将在发送后{timer}消失（已保留的消息除外）。点击更改。"));
    m_sysTranslations[QStringLiteral("Chinese")].insert(QStringLiteral("update_timer2"), QStringLiteral("{0}更新了消息计时器。新消息将在发送后{timer}消失（已保留的消息除外）。点击了解更多。"));
    m_sysTranslations[QStringLiteral("Chinese")].insert(QStringLiteral("voice_call"), QStringLiteral("语音通话。{1} • {0}已加入"));
    m_sysTranslations[QStringLiteral("Chinese")].insert(QStringLiteral("video_call"), QStringLiteral("视频通话。{1} • {0}已加入"));
    m_sysTranslations[QStringLiteral("Chinese")].insert(QStringLiteral("timer_24h"), QStringLiteral("24小时"));
    m_sysTranslations[QStringLiteral("Chinese")].insert(QStringLiteral("timer_7d"), QStringLiteral("7天"));
    m_sysTranslations[QStringLiteral("Chinese")].insert(QStringLiteral("timer_90d"), QStringLiteral("90天"));
    m_sysTranslations[QStringLiteral("Chinese")].insert(QStringLiteral("phone_number_changed"), QString::fromUtf8("{0}更换了电话号码。发送消息或添加新号码。"));

    // ── Hindi ────────────────────────────────────────────────────────────────
    m_sysTranslations[QString::fromUtf8("Hindi")].insert(QStringLiteral("created_group"), QString::fromUtf8("{0} ने \"{1}\" ग्रुप बनाया"));
    m_sysTranslations[QStringLiteral("Hindi")].insert(QStringLiteral("created_group_noname"), QStringLiteral("{0} ने यह ग्रुप बनाया"));
    m_sysTranslations[QStringLiteral("Hindi")].insert(QStringLiteral("e2e_note"), QStringLiteral("मैसेज और कॉल एंड-टू-एंड एन्क्रिप्टेड हैं। इस चैट में मौजूद लोग ही इन्हें पढ़, सुन या शेयर कर सकते हैं।"));
    m_sysTranslations[QStringLiteral("Hindi")].insert(QStringLiteral("left"), QStringLiteral("{0} ने ग्रुप छोड़ा"));
    m_sysTranslations[QStringLiteral("Hindi")].insert(QStringLiteral("added"), QStringLiteral("{0} ने {1} को जोड़ा"));
    m_sysTranslations[QStringLiteral("Hindi")].insert(QStringLiteral("was_added"), QStringLiteral("{0} को जोड़ा गया"));
    m_sysTranslations[QStringLiteral("Hindi")].insert(QStringLiteral("removed"), QStringLiteral("{0} ने {1} को हटाया"));
    m_sysTranslations[QStringLiteral("Hindi")].insert(QStringLiteral("you_now_admin"), QStringLiteral("अब आप एडमिन हैं"));
    m_sysTranslations[QStringLiteral("Hindi")].insert(QStringLiteral("now_admin"), QStringLiteral("{0} अब एडमिन हैं"));
    m_sysTranslations[QStringLiteral("Hindi")].insert(QStringLiteral("admin_approval_on"), QStringLiteral("{0} ने इस ग्रुप में शामिल होने के लिए एडमिन अनुमोदन चालू किया। बदलने के लिए टैप करें।"));
    m_sysTranslations[QStringLiteral("Hindi")].insert(QStringLiteral("no_longer_admin_you"), QStringLiteral("आप अब एडमिन नहीं हैं"));
    m_sysTranslations[QStringLiteral("Hindi")].insert(QStringLiteral("no_longer_admin"), QStringLiteral("{0} अब एडमिन नहीं हैं"));
    m_sysTranslations[QStringLiteral("Hindi")].insert(QStringLiteral("admin_approval_off"), QStringLiteral("{0} ने एडमिन अनुमोदन बंद किया। बदलने के लिए टैप करें।"));
    m_sysTranslations[QStringLiteral("Hindi")].insert(QStringLiteral("joined_link"), QStringLiteral("{0} ग्रुप लिंक से जुड़े।"));
    m_sysTranslations[QStringLiteral("Hindi")].insert(QStringLiteral("changed_icon"), QStringLiteral("{0} ने ग्रुप का आइकन बदला"));
    m_sysTranslations[QString::fromUtf8("Hindi")].insert(QStringLiteral("changed_name"), QString::fromUtf8("{0} ने ग्रुप का नाम बदलकर \"{1}\" किया"));
    m_sysTranslations[QString::fromUtf8("Hindi")].insert(QStringLiteral("changed_name_from_to"), QString::fromUtf8("{0} ने ग्रुप का नाम \"{1}\" से बदलकर \"{2}\" किया"));
    m_sysTranslations[QStringLiteral("Hindi")].insert(QStringLiteral("changed_desc"), QStringLiteral("{0} ने ग्रुप का विवरण बदला"));
    m_sysTranslations[QStringLiteral("Hindi")].insert(QStringLiteral("settings_only_admins_edit"), QStringLiteral("{0} ने सेटिंग बदली: केवल एडमिन ग्रुप सेटिंग बदल सकते हैं"));
    m_sysTranslations[QStringLiteral("Hindi")].insert(QStringLiteral("settings_all_edit"), QStringLiteral("{0} ने सेटिंग बदली: सभी सदस्य ग्रुप सेटिंग बदल सकते हैं"));
    m_sysTranslations[QStringLiteral("Hindi")].insert(QStringLiteral("settings_only_admins_send"), QStringLiteral("{0} ने ग्रुप सेटिंग बदली: केवल एडमिन मैसेज भेज सकते हैं"));
    m_sysTranslations[QStringLiteral("Hindi")].insert(QStringLiteral("settings_only_admins_add"), QStringLiteral("{0} ने ग्रुप सेटिंग बदली: केवल एडमिन दूसरों को जोड़ सकते हैं।"));
    m_sysTranslations[QStringLiteral("Hindi")].insert(QStringLiteral("settings_all_add"), QStringLiteral("{0} ने ग्रुप सेटिंग बदली: सभी सदस्य दूसरों को जोड़ सकते हैं।"));
    m_sysTranslations[QStringLiteral("Hindi")].insert(QStringLiteral("settings_all_send"), QStringLiteral("{0} ने ग्रुप सेटिंग बदली: सभी सदस्य मैसेज भेज सकते हैं"));
    m_sysTranslations[QStringLiteral("Hindi")].insert(QStringLiteral("settings_all_invite_link"), QStringLiteral("{0} ने ग्रुप सेटिंग बदली: सभी ग्रुप लिंक से आमंत्रित कर सकते हैं।"));
    m_sysTranslations[QStringLiteral("Hindi")].insert(QStringLiteral("anyone_invite_link"), QStringLiteral("इस ग्रुप में कोई भी ग्रुप लिंक से नए सदस्यों को आमंत्रित कर सकता है।"));
    m_sysTranslations[QStringLiteral("Hindi")].insert(QStringLiteral("settings_only_admins_invite_link"), QStringLiteral("{0} ने सेटिंग बदली: केवल एडमिन लिंक से आमंत्रित कर सकते हैं।"));
    m_sysTranslations[QStringLiteral("Hindi")].insert(QStringLiteral("reset_link"), QStringLiteral("{0} ने ग्रुप का आमंत्रण लिंक रीसेट किया"));
    m_sysTranslations[QStringLiteral("Hindi")].insert(QStringLiteral("disappear_on"), QStringLiteral("{0} ने गायब होने वाले मैसेज चालू किए। नए मैसेज भेजने के {timer} बाद इस चैट से गायब हो जाएंगे (सहेजे गए को छोड़कर)। बदलने के लिए टैप करें।"));
    m_sysTranslations[QStringLiteral("Hindi")].insert(QStringLiteral("disappear_off"), QStringLiteral("{0} ने गायब होने वाले मैसेज बंद किए। बदलने के लिए टैप करें।"));
    m_sysTranslations[QStringLiteral("Hindi")].insert(QStringLiteral("disappear_off2"), QStringLiteral("{0} ने गायब होने वाले मैसेज बंद किए। अधिक जानने के लिए टैप करें।"));
    m_sysTranslations[QStringLiteral("Hindi")].insert(QStringLiteral("update_timer"), QStringLiteral("{0} ने मैसेज टाइमर अपडेट किया। नए मैसेज भेजने के {timer} बाद गायब हो जाएंगे (सहेजे गए को छोड़कर)। बदलने के लिए टैप करें।"));
    m_sysTranslations[QStringLiteral("Hindi")].insert(QStringLiteral("update_timer2"), QStringLiteral("{0} ने मैसेज टाइमर अपडेट किया। नए मैसेज {timer} बाद गायब हो जाएंगे। अधिक जानने के लिए टैप करें।"));
    m_sysTranslations[QStringLiteral("Hindi")].insert(QStringLiteral("voice_call"), QStringLiteral("वॉइस कॉल। {1} • {0} जुड़े"));
    m_sysTranslations[QStringLiteral("Hindi")].insert(QStringLiteral("video_call"), QStringLiteral("वीडियो कॉल। {1} • {0} जुड़े"));
    m_sysTranslations[QStringLiteral("Hindi")].insert(QStringLiteral("timer_24h"), QStringLiteral("24 घंटे"));
    m_sysTranslations[QStringLiteral("Hindi")].insert(QStringLiteral("timer_7d"), QStringLiteral("7 दिन"));
    m_sysTranslations[QStringLiteral("Hindi")].insert(QStringLiteral("timer_90d"), QStringLiteral("90 दिन"));
    m_sysTranslations[QStringLiteral("Hindi")].insert(QStringLiteral("phone_number_changed"), QString::fromUtf8("{0} ने अपना फ़ोन नंबर बदल लिया। नए नंबर पर मैसेज भेजें या उसे जोड़ें।"));

    // ── Japanese ─────────────────────────────────────────────────────────────
    m_sysTranslations[QStringLiteral("Japanese")].insert(QStringLiteral("created_group"), QStringLiteral("{0}がグループ「{1}」を作成しました"));
    m_sysTranslations[QStringLiteral("Japanese")].insert(QStringLiteral("created_group_noname"), QStringLiteral("{0}がこのグループを作成しました"));
    m_sysTranslations[QStringLiteral("Japanese")].insert(QStringLiteral("e2e_note"), QStringLiteral("メッセージと通話はエンドツーエンド暗号化されています。このチャットのメンバーのみが読み取り、聴取、共有できます。"));
    m_sysTranslations[QStringLiteral("Japanese")].insert(QStringLiteral("left"), QStringLiteral("{0}が退出しました"));
    m_sysTranslations[QStringLiteral("Japanese")].insert(QStringLiteral("added"), QStringLiteral("{0}が{1}を追加しました"));
    m_sysTranslations[QStringLiteral("Japanese")].insert(QStringLiteral("was_added"), QStringLiteral("{0}が追加されました"));
    m_sysTranslations[QStringLiteral("Japanese")].insert(QStringLiteral("removed"), QStringLiteral("{0}が{1}を削除しました"));
    m_sysTranslations[QStringLiteral("Japanese")].insert(QStringLiteral("you_now_admin"), QStringLiteral("あなたは管理者になりました"));
    m_sysTranslations[QStringLiteral("Japanese")].insert(QStringLiteral("now_admin"), QStringLiteral("{0}は管理者になりました"));
    m_sysTranslations[QStringLiteral("Japanese")].insert(QStringLiteral("admin_approval_on"), QStringLiteral("{0}がこのグループへの参加に管理者承認を有効にしました。変更するにはタップしてください。"));
    m_sysTranslations[QStringLiteral("Japanese")].insert(QStringLiteral("no_longer_admin_you"), QStringLiteral("あなたは管理者ではなくなりました"));
    m_sysTranslations[QStringLiteral("Japanese")].insert(QStringLiteral("no_longer_admin"), QStringLiteral("{0}は管理者ではなくなりました"));
    m_sysTranslations[QStringLiteral("Japanese")].insert(QStringLiteral("admin_approval_off"), QStringLiteral("{0}が管理者承認を無効にしました。変更するにはタップしてください。"));
    m_sysTranslations[QStringLiteral("Japanese")].insert(QStringLiteral("joined_link"), QStringLiteral("{0}がグループリンクを使って参加しました。"));
    m_sysTranslations[QStringLiteral("Japanese")].insert(QStringLiteral("changed_icon"), QStringLiteral("{0}がグループアイコンを変更しました"));
    m_sysTranslations[QStringLiteral("Japanese")].insert(QStringLiteral("changed_name"), QStringLiteral("{0}がグループ名を「{1}」に変更しました"));
    m_sysTranslations[QStringLiteral("Japanese")].insert(QStringLiteral("changed_name_from_to"), QStringLiteral("{0}がグループ名を「{1}」から「{2}」に変更しました"));
    m_sysTranslations[QStringLiteral("Japanese")].insert(QStringLiteral("changed_desc"), QStringLiteral("{0}がグループの説明を変更しました"));
    m_sysTranslations[QStringLiteral("Japanese")].insert(QStringLiteral("settings_only_admins_edit"), QStringLiteral("{0}が設定を変更しました：管理者のみがグループ設定を編集できます"));
    m_sysTranslations[QStringLiteral("Japanese")].insert(QStringLiteral("settings_all_edit"), QStringLiteral("{0}が設定を変更しました：全メンバーがグループ設定を編集できます"));
    m_sysTranslations[QStringLiteral("Japanese")].insert(QStringLiteral("settings_only_admins_send"), QStringLiteral("{0}がグループ設定を変更しました：管理者のみがメッセージを送信できます"));
    m_sysTranslations[QStringLiteral("Japanese")].insert(QStringLiteral("settings_only_admins_add"), QStringLiteral("{0}がグループ設定を変更しました：管理者のみが他のメンバーを追加できます。"));
    m_sysTranslations[QStringLiteral("Japanese")].insert(QStringLiteral("settings_all_add"), QStringLiteral("{0}がグループ設定を変更しました：全メンバーが他のメンバーを追加できます。"));
    m_sysTranslations[QStringLiteral("Japanese")].insert(QStringLiteral("settings_all_send"), QStringLiteral("{0}がグループ設定を変更しました：全メンバーがメッセージを送信できます"));
    m_sysTranslations[QStringLiteral("Japanese")].insert(QStringLiteral("settings_all_invite_link"), QStringLiteral("{0}がグループ設定を変更しました：全メンバーがリンクで招待できます。"));
    m_sysTranslations[QStringLiteral("Japanese")].insert(QStringLiteral("anyone_invite_link"), QStringLiteral("このグループの誰もがグループリンクを使って新しいメンバーを招待できます。"));
    m_sysTranslations[QStringLiteral("Japanese")].insert(QStringLiteral("settings_only_admins_invite_link"), QStringLiteral("{0}が設定を変更しました：管理者のみがリンクで招待できます。"));
    m_sysTranslations[QStringLiteral("Japanese")].insert(QStringLiteral("reset_link"), QStringLiteral("{0}がグループの招待リンクをリセットしました"));
    m_sysTranslations[QStringLiteral("Japanese")].insert(QStringLiteral("disappear_on"), QStringLiteral("{0}が消えるメッセージをオンにしました。新しいメッセージは送信後{timer}でこのチャットから消えます（保存されたものを除く）。変更するにはタップしてください。"));
    m_sysTranslations[QStringLiteral("Japanese")].insert(QStringLiteral("disappear_off"), QStringLiteral("{0}が消えるメッセージをオフにしました。変更するにはタップしてください。"));
    m_sysTranslations[QStringLiteral("Japanese")].insert(QStringLiteral("disappear_off2"), QStringLiteral("{0}が消えるメッセージをオフにしました。詳細はタップしてください。"));
    m_sysTranslations[QStringLiteral("Japanese")].insert(QStringLiteral("update_timer"), QStringLiteral("{0}がメッセージタイマーを更新しました。新しいメッセージは送信後{timer}で消えます（保存されたものを除く）。変更するにはタップしてください。"));
    m_sysTranslations[QStringLiteral("Japanese")].insert(QStringLiteral("update_timer2"), QStringLiteral("{0}がメッセージタイマーを更新しました。新しいメッセージは送信後{timer}で消えます。詳細はタップしてください。"));
    m_sysTranslations[QStringLiteral("Japanese")].insert(QStringLiteral("voice_call"), QStringLiteral("音声通話。{1} • {0}が参加しました"));
    m_sysTranslations[QStringLiteral("Japanese")].insert(QStringLiteral("video_call"), QStringLiteral("ビデオ通話。{1} • {0}が参加しました"));
    m_sysTranslations[QStringLiteral("Japanese")].insert(QStringLiteral("timer_24h"), QStringLiteral("24時間"));
    m_sysTranslations[QStringLiteral("Japanese")].insert(QStringLiteral("timer_7d"), QStringLiteral("7日間"));
    m_sysTranslations[QStringLiteral("Japanese")].insert(QStringLiteral("timer_90d"), QStringLiteral("90日間"));
    m_sysTranslations[QStringLiteral("Japanese")].insert(QStringLiteral("phone_number_changed"), QString::fromUtf8("{0}が電話番号を変更しました。新しい番号にメッセージを送るか追加してください。"));

    // ── Korean ───────────────────────────────────────────────────────────────
    m_sysTranslations[QString::fromUtf8("Korean")].insert(QStringLiteral("created_group"), QString::fromUtf8("{0}님이 \"{1}\" 그룹을 만들었습니다"));
    m_sysTranslations[QStringLiteral("Korean")].insert(QStringLiteral("created_group_noname"), QStringLiteral("{0}님이 이 그룹을 만들었습니다"));
    m_sysTranslations[QStringLiteral("Korean")].insert(QStringLiteral("e2e_note"), QStringLiteral("메시지와 통화는 엔드투엔드 암호화됩니다. 이 채팅의 참여자만 읽거나 듣거나 공유할 수 있습니다."));
    m_sysTranslations[QStringLiteral("Korean")].insert(QStringLiteral("left"), QStringLiteral("{0}님이 나갔습니다"));
    m_sysTranslations[QStringLiteral("Korean")].insert(QStringLiteral("added"), QStringLiteral("{0}님이 {1}님을 추가했습니다"));
    m_sysTranslations[QStringLiteral("Korean")].insert(QStringLiteral("was_added"), QStringLiteral("{0}님이 추가되었습니다"));
    m_sysTranslations[QStringLiteral("Korean")].insert(QStringLiteral("removed"), QStringLiteral("{0}님이 {1}님을 삭제했습니다"));
    m_sysTranslations[QStringLiteral("Korean")].insert(QStringLiteral("you_now_admin"), QStringLiteral("이제 관리자입니다"));
    m_sysTranslations[QStringLiteral("Korean")].insert(QStringLiteral("now_admin"), QStringLiteral("{0}님이 관리자가 되었습니다"));
    m_sysTranslations[QStringLiteral("Korean")].insert(QStringLiteral("admin_approval_on"), QStringLiteral("{0}님이 이 그룹 참여에 관리자 승인을 켰습니다. 변경하려면 탭하세요."));
    m_sysTranslations[QStringLiteral("Korean")].insert(QStringLiteral("no_longer_admin_you"), QStringLiteral("더 이상 관리자가 아닙니다"));
    m_sysTranslations[QStringLiteral("Korean")].insert(QStringLiteral("no_longer_admin"), QStringLiteral("{0}님은 더 이상 관리자가 아닙니다"));
    m_sysTranslations[QStringLiteral("Korean")].insert(QStringLiteral("admin_approval_off"), QStringLiteral("{0}님이 관리자 승인을 껐습니다. 변경하려면 탭하세요."));
    m_sysTranslations[QStringLiteral("Korean")].insert(QStringLiteral("joined_link"), QStringLiteral("{0}님이 그룹 링크를 사용하여 참여했습니다."));
    m_sysTranslations[QStringLiteral("Korean")].insert(QStringLiteral("changed_icon"), QStringLiteral("{0}님이 그룹 아이콘을 변경했습니다"));
    m_sysTranslations[QString::fromUtf8("Korean")].insert(QStringLiteral("changed_name"), QString::fromUtf8("{0}님이 그룹 이름을 \"{1}\"(으)로 변경했습니다"));
    m_sysTranslations[QString::fromUtf8("Korean")].insert(QStringLiteral("changed_name_from_to"), QString::fromUtf8("{0}님이 그룹 이름을 \"{1}\"에서 \"{2}\"(으)로 변경했습니다"));
    m_sysTranslations[QStringLiteral("Korean")].insert(QStringLiteral("changed_desc"), QStringLiteral("{0}님이 그룹 설명을 변경했습니다"));
    m_sysTranslations[QStringLiteral("Korean")].insert(QStringLiteral("settings_only_admins_edit"), QStringLiteral("{0}님이 설정을 변경했습니다: 관리자만 그룹 설정을 편집할 수 있습니다"));
    m_sysTranslations[QStringLiteral("Korean")].insert(QStringLiteral("settings_all_edit"), QStringLiteral("{0}님이 설정을 변경했습니다: 모든 구성원이 그룹 설정을 편집할 수 있습니다"));
    m_sysTranslations[QStringLiteral("Korean")].insert(QStringLiteral("settings_only_admins_send"), QStringLiteral("{0}님이 그룹 설정을 변경했습니다: 관리자만 메시지를 보낼 수 있습니다"));
    m_sysTranslations[QStringLiteral("Korean")].insert(QStringLiteral("settings_only_admins_add"), QStringLiteral("{0}님이 그룹 설정을 변경했습니다: 관리자만 다른 구성원을 추가할 수 있습니다."));
    m_sysTranslations[QStringLiteral("Korean")].insert(QStringLiteral("settings_all_add"), QStringLiteral("{0}님이 그룹 설정을 변경했습니다: 모든 구성원이 다른 구성원을 추가할 수 있습니다."));
    m_sysTranslations[QStringLiteral("Korean")].insert(QStringLiteral("settings_all_send"), QStringLiteral("{0}님이 그룹 설정을 변경했습니다: 모든 구성원이 메시지를 보낼 수 있습니다"));
    m_sysTranslations[QStringLiteral("Korean")].insert(QStringLiteral("settings_all_invite_link"), QStringLiteral("{0}님이 그룹 설정을 변경했습니다: 모든 구성원이 링크로 초대할 수 있습니다."));
    m_sysTranslations[QStringLiteral("Korean")].insert(QStringLiteral("anyone_invite_link"), QStringLiteral("이 그룹의 누구나 그룹 링크를 사용하여 새 구성원을 초대할 수 있습니다."));
    m_sysTranslations[QStringLiteral("Korean")].insert(QStringLiteral("settings_only_admins_invite_link"), QStringLiteral("{0}님이 설정을 변경했습니다: 관리자만 링크로 초대할 수 있습니다."));
    m_sysTranslations[QStringLiteral("Korean")].insert(QStringLiteral("reset_link"), QStringLiteral("{0}님이 그룹 초대 링크를 재설정했습니다"));
    m_sysTranslations[QStringLiteral("Korean")].insert(QStringLiteral("disappear_on"), QStringLiteral("{0}님이 사라지는 메시지를 켰습니다. 새 메시지는 전송 후 {timer}이 지나면 이 채팅에서 사라집니다(보관된 메시지 제외). 변경하려면 탭하세요."));
    m_sysTranslations[QStringLiteral("Korean")].insert(QStringLiteral("disappear_off"), QStringLiteral("{0}님이 사라지는 메시지를 껐습니다. 변경하려면 탭하세요."));
    m_sysTranslations[QStringLiteral("Korean")].insert(QStringLiteral("disappear_off2"), QStringLiteral("{0}님이 사라지는 메시지를 껐습니다. 자세히 알아보려면 탭하세요."));
    m_sysTranslations[QStringLiteral("Korean")].insert(QStringLiteral("update_timer"), QStringLiteral("{0}님이 메시지 타이머를 업데이트했습니다. 새 메시지는 전송 후 {timer}이 지나면 사라집니다(보관된 메시지 제외). 변경하려면 탭하세요."));
    m_sysTranslations[QStringLiteral("Korean")].insert(QStringLiteral("update_timer2"), QStringLiteral("{0}님이 메시지 타이머를 업데이트했습니다. 새 메시지는 전송 후 {timer}이 지나면 사라집니다. 자세히 알아보려면 탭하세요."));
    m_sysTranslations[QStringLiteral("Korean")].insert(QStringLiteral("voice_call"), QStringLiteral("음성 통화. {1} • {0}님이 참여함"));
    m_sysTranslations[QStringLiteral("Korean")].insert(QStringLiteral("video_call"), QStringLiteral("영상 통화. {1} • {0}님이 참여함"));
    m_sysTranslations[QStringLiteral("Korean")].insert(QStringLiteral("timer_24h"), QStringLiteral("24시간"));
    m_sysTranslations[QStringLiteral("Korean")].insert(QStringLiteral("timer_7d"), QStringLiteral("7일"));
    m_sysTranslations[QStringLiteral("Korean")].insert(QStringLiteral("timer_90d"), QStringLiteral("90일"));
    m_sysTranslations[QStringLiteral("Korean")].insert(QStringLiteral("phone_number_changed"), QString::fromUtf8("{0}님이 전화번호를 변경했습니다. 새 번호로 메시지를 보내거나 추가하세요."));

    // ── Mongolian ────────────────────────────────────────────────────────────
    m_sysTranslations[QString::fromUtf8("Mongolian")].insert(QStringLiteral("created_group"), QString::fromUtf8("{0} \"{1}\" бүлгийг үүсгэлээ"));
    m_sysTranslations[QStringLiteral("Mongolian")].insert(QStringLiteral("created_group_noname"), QStringLiteral("{0} энэ бүлгийг үүсгэлээ"));
    m_sysTranslations[QStringLiteral("Mongolian")].insert(QStringLiteral("e2e_note"), QStringLiteral("Мессеж болон дуудлагууд эцэс-эцсийн шифрлэлттэй. Зөвхөн энэ чатын хүмүүс тэдгээрийг унших, сонсох, хуваалцах боломжтой."));
    m_sysTranslations[QStringLiteral("Mongolian")].insert(QStringLiteral("left"), QStringLiteral("{0} гарлаа"));
    m_sysTranslations[QStringLiteral("Mongolian")].insert(QStringLiteral("added"), QStringLiteral("{0} {1}-г нэмлээ"));
    m_sysTranslations[QStringLiteral("Mongolian")].insert(QStringLiteral("was_added"), QStringLiteral("{0} нэмэгдлээ"));
    m_sysTranslations[QStringLiteral("Mongolian")].insert(QStringLiteral("removed"), QStringLiteral("{0} {1}-г хаслаа"));
    m_sysTranslations[QStringLiteral("Mongolian")].insert(QStringLiteral("you_now_admin"), QStringLiteral("Та одоо администратор болсон"));
    m_sysTranslations[QStringLiteral("Mongolian")].insert(QStringLiteral("now_admin"), QStringLiteral("{0} одоо администратор болсон"));
    m_sysTranslations[QStringLiteral("Mongolian")].insert(QStringLiteral("admin_approval_on"), QStringLiteral("{0} энэ бүлэгт нэгдэхийн тулд администраторын зөвшөөрлийг идэвхжүүллээ. Өөрчлөхийн тулд товшино уу."));
    m_sysTranslations[QStringLiteral("Mongolian")].insert(QStringLiteral("no_longer_admin_you"), QStringLiteral("Та цаашид администратор биш болсон"));
    m_sysTranslations[QStringLiteral("Mongolian")].insert(QStringLiteral("no_longer_admin"), QStringLiteral("{0} цаашид администратор биш болсон"));
    m_sysTranslations[QStringLiteral("Mongolian")].insert(QStringLiteral("admin_approval_off"), QStringLiteral("{0} администраторын зөвшөөрлийг унтраалаа. Өөрчлөхийн тулд товшино уу."));
    m_sysTranslations[QStringLiteral("Mongolian")].insert(QStringLiteral("joined_link"), QStringLiteral("{0} бүлгийн холбоосоор нэгдлээ."));
    m_sysTranslations[QStringLiteral("Mongolian")].insert(QStringLiteral("changed_icon"), QStringLiteral("{0} бүлгийн дүрсийг өөрчиллөө"));
    m_sysTranslations[QString::fromUtf8("Mongolian")].insert(QStringLiteral("changed_name"), QString::fromUtf8("{0} бүлгийн нэрийг \"{1}\" болгон өөрчиллөө"));
    m_sysTranslations[QString::fromUtf8("Mongolian")].insert(QStringLiteral("changed_name_from_to"), QString::fromUtf8("{0} бүлгийн нэрийг \"{1}\"-ээс \"{2}\" болгон өөрчиллөө"));
    m_sysTranslations[QStringLiteral("Mongolian")].insert(QStringLiteral("changed_desc"), QStringLiteral("{0} бүлгийн тайлбарыг өөрчиллөө"));
    m_sysTranslations[QStringLiteral("Mongolian")].insert(QStringLiteral("settings_only_admins_edit"), QStringLiteral("{0} зөвхөн администраторууд бүлгийн тохиргоог засварлах боломжтой болгон тохиргоог өөрчиллөө"));
    m_sysTranslations[QStringLiteral("Mongolian")].insert(QStringLiteral("settings_all_edit"), QStringLiteral("{0} бүх гишүүд бүлгийн тохиргоог засварлах боломжтой болгон тохиргоог өөрчиллөө"));
    m_sysTranslations[QStringLiteral("Mongolian")].insert(QStringLiteral("settings_only_admins_send"), QStringLiteral("{0} зөвхөн администраторууд мессеж илгээх боломжтой болгон тохиргоог өөрчиллөө"));
    m_sysTranslations[QStringLiteral("Mongolian")].insert(QStringLiteral("settings_only_admins_add"), QStringLiteral("{0} зөвхөн администраторууд бусдыг нэмэх боломжтой болгон тохиргоог өөрчиллөө."));
    m_sysTranslations[QStringLiteral("Mongolian")].insert(QStringLiteral("settings_all_add"), QStringLiteral("{0} бүх гишүүд бусдыг нэмэх боломжтой болгон тохиргоог өөрчиллөө."));
    m_sysTranslations[QStringLiteral("Mongolian")].insert(QStringLiteral("settings_all_send"), QStringLiteral("{0} бүх гишүүд мессеж илгээх боломжтой болгон тохиргоог өөрчиллөө"));
    m_sysTranslations[QStringLiteral("Mongolian")].insert(QStringLiteral("settings_all_invite_link"), QStringLiteral("{0} бүх гишүүд холбоосоор урих боломжтой болгон тохиргоог өөрчиллөө."));
    m_sysTranslations[QStringLiteral("Mongolian")].insert(QStringLiteral("anyone_invite_link"), QStringLiteral("Энэ бүлгийн хүн бүр бүлгийн холбоосоор шинэ гишүүдийг урих боломжтой."));
    m_sysTranslations[QStringLiteral("Mongolian")].insert(QStringLiteral("settings_only_admins_invite_link"), QStringLiteral("{0} зөвхөн администраторууд холбоосоор урих боломжтой болгон тохиргоог өөрчиллөө."));
    m_sysTranslations[QStringLiteral("Mongolian")].insert(QStringLiteral("reset_link"), QStringLiteral("{0} бүлгийн урилгын холбоосыг дахин тохируулав"));
    m_sysTranslations[QStringLiteral("Mongolian")].insert(QStringLiteral("disappear_on"), QStringLiteral("{0} алга болдог мессежийг идэвхжүүллээ. Шинэ мессежүүд илгээгдсэнээс хойш {timer}-н дараа энэ чатаас алга болно (хадгалсанаас бусад). Өөрчлөхийн тулд товшино уу."));
    m_sysTranslations[QStringLiteral("Mongolian")].insert(QStringLiteral("disappear_off"), QStringLiteral("{0} алга болдог мессежийг унтраалаа. Өөрчлөхийн тулд товшино уу."));
    m_sysTranslations[QStringLiteral("Mongolian")].insert(QStringLiteral("disappear_off2"), QStringLiteral("{0} алга болдог мессежийг унтраалаа. Дэлгэрэнгүй мэдэхийн тулд товшино уу."));
    m_sysTranslations[QStringLiteral("Mongolian")].insert(QStringLiteral("update_timer"), QStringLiteral("{0} мессежийн таймерыг шинэчиллэв. Шинэ мессежүүд илгээгдсэнээс хойш {timer}-н дараа алга болно (хадгалсанаас бусад). Өөрчлөхийн тулд товшино уу."));
    m_sysTranslations[QStringLiteral("Mongolian")].insert(QStringLiteral("update_timer2"), QStringLiteral("{0} мессежийн таймерыг шинэчиллэв. Шинэ мессежүүд {timer}-н дараа алга болно. Дэлгэрэнгүй мэдэхийн тулд товшино уу."));
    m_sysTranslations[QStringLiteral("Mongolian")].insert(QStringLiteral("voice_call"), QStringLiteral("Дуут дуудлага. {1} • {0} нэгдлээ"));
    m_sysTranslations[QStringLiteral("Mongolian")].insert(QStringLiteral("video_call"), QStringLiteral("Видео дуудлага. {1} • {0} нэгдлээ"));
    m_sysTranslations[QStringLiteral("Mongolian")].insert(QStringLiteral("timer_24h"), QStringLiteral("24 цаг"));
    m_sysTranslations[QStringLiteral("Mongolian")].insert(QStringLiteral("timer_7d"), QStringLiteral("7 хоног"));
    m_sysTranslations[QStringLiteral("Mongolian")].insert(QStringLiteral("timer_90d"), QStringLiteral("90 хоног"));
    m_sysTranslations[QStringLiteral("Mongolian")].insert(QStringLiteral("phone_number_changed"), QString::fromUtf8("{0} утасны дугаараа өөрчиллөө. Шинэ дугаарт мессеж илгээх эсвэл нэмэх."));

    // ── Polish ───────────────────────────────────────────────────────────────
    m_sysTranslations[QString::fromUtf8("Polish")].insert(QStringLiteral("created_group"), QString::fromUtf8("{0} utworzył(a) grupę \"{1}\""));
    m_sysTranslations[QStringLiteral("Polish")].insert(QStringLiteral("created_group_noname"), QStringLiteral("{0} utworzył(a) tę grupę"));
    m_sysTranslations[QStringLiteral("Polish")].insert(QStringLiteral("e2e_note"), QStringLiteral("Wiadomości i połączenia są szyfrowane od końca do końca. Tylko osoby w tym czacie mogą je czytać, słuchać lub udostępniać."));
    m_sysTranslations[QStringLiteral("Polish")].insert(QStringLiteral("left"), QStringLiteral("{0} opuścił(a) grupę"));
    m_sysTranslations[QStringLiteral("Polish")].insert(QStringLiteral("added"), QStringLiteral("{0} dodał(a) {1}"));
    m_sysTranslations[QStringLiteral("Polish")].insert(QStringLiteral("was_added"), QStringLiteral("{0} został(a) dodany(a)"));
    m_sysTranslations[QStringLiteral("Polish")].insert(QStringLiteral("removed"), QStringLiteral("{0} usunął(a) {1}"));
    m_sysTranslations[QStringLiteral("Polish")].insert(QStringLiteral("you_now_admin"), QStringLiteral("Jesteś teraz administratorem"));
    m_sysTranslations[QStringLiteral("Polish")].insert(QStringLiteral("now_admin"), QStringLiteral("{0} jest teraz administratorem"));
    m_sysTranslations[QStringLiteral("Polish")].insert(QStringLiteral("admin_approval_on"), QStringLiteral("{0} włączył(a) zatwierdzenie przez admina przy dołączaniu do grupy. Dotknij, aby zmienić."));
    m_sysTranslations[QStringLiteral("Polish")].insert(QStringLiteral("no_longer_admin_you"), QStringLiteral("Nie jesteś już administratorem"));
    m_sysTranslations[QStringLiteral("Polish")].insert(QStringLiteral("no_longer_admin"), QStringLiteral("{0} nie jest już administratorem"));
    m_sysTranslations[QStringLiteral("Polish")].insert(QStringLiteral("admin_approval_off"), QStringLiteral("{0} wyłączył(a) zatwierdzenie przez admina. Dotknij, aby zmienić."));
    m_sysTranslations[QStringLiteral("Polish")].insert(QStringLiteral("joined_link"), QStringLiteral("{0} dołączył(a) za pomocą linku do grupy."));
    m_sysTranslations[QStringLiteral("Polish")].insert(QStringLiteral("changed_icon"), QStringLiteral("{0} zmienił(a) ikonę grupy"));
    m_sysTranslations[QString::fromUtf8("Polish")].insert(QStringLiteral("changed_name"), QString::fromUtf8("{0} zmienił(a) nazwę grupy na \"{1}\""));
    m_sysTranslations[QString::fromUtf8("Polish")].insert(QStringLiteral("changed_name_from_to"), QString::fromUtf8("{0} zmienił(a) nazwę grupy z \"{1}\" na \"{2}\""));
    m_sysTranslations[QStringLiteral("Polish")].insert(QStringLiteral("changed_desc"), QStringLiteral("{0} zmienił(a) opis grupy"));
    m_sysTranslations[QStringLiteral("Polish")].insert(QStringLiteral("settings_only_admins_edit"), QStringLiteral("{0} zmienił(a) ustawienia: tylko admini mogą edytować ustawienia grupy"));
    m_sysTranslations[QStringLiteral("Polish")].insert(QStringLiteral("settings_all_edit"), QStringLiteral("{0} zmienił(a) ustawienia: wszyscy członkowie mogą edytować ustawienia grupy"));
    m_sysTranslations[QStringLiteral("Polish")].insert(QStringLiteral("settings_only_admins_send"), QStringLiteral("{0} zmienił(a) ustawienia grupy: tylko admini mogą wysyłać wiadomości"));
    m_sysTranslations[QStringLiteral("Polish")].insert(QStringLiteral("settings_only_admins_add"), QStringLiteral("{0} zmienił(a) ustawienia grupy: tylko admini mogą dodawać innych."));
    m_sysTranslations[QStringLiteral("Polish")].insert(QStringLiteral("settings_all_add"), QStringLiteral("{0} zmienił(a) ustawienia grupy: wszyscy członkowie mogą dodawać innych."));
    m_sysTranslations[QStringLiteral("Polish")].insert(QStringLiteral("settings_all_send"), QStringLiteral("{0} zmienił(a) ustawienia grupy: wszyscy członkowie mogą wysyłać wiadomości"));
    m_sysTranslations[QStringLiteral("Polish")].insert(QStringLiteral("settings_all_invite_link"), QStringLiteral("{0} zmienił(a) ustawienia grupy: wszyscy mogą zapraszać przez link."));
    m_sysTranslations[QStringLiteral("Polish")].insert(QStringLiteral("anyone_invite_link"), QStringLiteral("Każdy w tej grupie może zapraszać nowych członków za pomocą linku do grupy."));
    m_sysTranslations[QStringLiteral("Polish")].insert(QStringLiteral("settings_only_admins_invite_link"), QStringLiteral("{0} zmienił(a) ustawienia: tylko admini mogą zapraszać przez link."));
    m_sysTranslations[QStringLiteral("Polish")].insert(QStringLiteral("reset_link"), QStringLiteral("{0} zresetował(a) link zaproszenia do grupy"));
    m_sysTranslations[QStringLiteral("Polish")].insert(QStringLiteral("disappear_on"), QStringLiteral("{0} włączył(a) znikające wiadomości. Nowe wiadomości znikną {timer} po wysłaniu, z wyjątkiem zachowanych. Dotknij, aby zmienić."));
    m_sysTranslations[QStringLiteral("Polish")].insert(QStringLiteral("disappear_off"), QStringLiteral("{0} wyłączył(a) znikające wiadomości. Dotknij, aby zmienić."));
    m_sysTranslations[QStringLiteral("Polish")].insert(QStringLiteral("disappear_off2"), QStringLiteral("{0} wyłączył(a) znikające wiadomości. Dotknij, aby dowiedzieć się więcej."));
    m_sysTranslations[QStringLiteral("Polish")].insert(QStringLiteral("update_timer"), QStringLiteral("{0} zaktualizował(a) timer wiadomości. Nowe wiadomości znikną {timer} po wysłaniu, z wyjątkiem zachowanych. Dotknij, aby zmienić."));
    m_sysTranslations[QStringLiteral("Polish")].insert(QStringLiteral("update_timer2"), QStringLiteral("{0} zaktualizował(a) timer wiadomości. Nowe wiadomości znikną {timer} po wysłaniu. Dotknij, aby dowiedzieć się więcej."));
    m_sysTranslations[QStringLiteral("Polish")].insert(QStringLiteral("voice_call"), QStringLiteral("Połączenie głosowe. {1} • {0} dołączył(a)"));
    m_sysTranslations[QStringLiteral("Polish")].insert(QStringLiteral("video_call"), QStringLiteral("Połączenie wideo. {1} • {0} dołączył(a)"));
    m_sysTranslations[QStringLiteral("Polish")].insert(QStringLiteral("timer_24h"), QStringLiteral("24 godziny"));
    m_sysTranslations[QStringLiteral("Polish")].insert(QStringLiteral("timer_7d"), QStringLiteral("7 dni"));
    m_sysTranslations[QStringLiteral("Polish")].insert(QStringLiteral("timer_90d"), QStringLiteral("90 dni"));
    m_sysTranslations[QStringLiteral("Polish")].insert(QStringLiteral("phone_number_changed"), QString::fromUtf8("{0} zmienił(a) numer telefonu. Napisz lub dodaj nowy numer."));

    // ── Ukrainian ────────────────────────────────────────────────────────────
    m_sysTranslations[QString::fromUtf8("Ukrainian")].insert(QStringLiteral("created_group"), QString::fromUtf8("{0} створив(ла) групу \"{1}\""));
    m_sysTranslations[QStringLiteral("Ukrainian")].insert(QStringLiteral("created_group_noname"), QStringLiteral("{0} створив(ла) цю групу"));
    m_sysTranslations[QStringLiteral("Ukrainian")].insert(QStringLiteral("e2e_note"), QStringLiteral("Повідомлення та дзвінки захищені наскрізним шифруванням. Читати, слухати або ділитися ними можуть лише учасники цього чату."));
    m_sysTranslations[QStringLiteral("Ukrainian")].insert(QStringLiteral("left"), QStringLiteral("{0} вийшов(ла)"));
    m_sysTranslations[QStringLiteral("Ukrainian")].insert(QStringLiteral("added"), QStringLiteral("{0} додав(ла) {1}"));
    m_sysTranslations[QStringLiteral("Ukrainian")].insert(QStringLiteral("was_added"), QStringLiteral("{0} було додано"));
    m_sysTranslations[QStringLiteral("Ukrainian")].insert(QStringLiteral("removed"), QStringLiteral("{0} видалив(ла) {1}"));
    m_sysTranslations[QStringLiteral("Ukrainian")].insert(QStringLiteral("you_now_admin"), QStringLiteral("Ви тепер адміністратор"));
    m_sysTranslations[QStringLiteral("Ukrainian")].insert(QStringLiteral("now_admin"), QStringLiteral("{0} тепер адміністратор"));
    m_sysTranslations[QStringLiteral("Ukrainian")].insert(QStringLiteral("admin_approval_on"), QStringLiteral("{0} увімкнув(ла) підтвердження адміністратора для вступу до групи. Торкніться, щоб змінити."));
    m_sysTranslations[QStringLiteral("Ukrainian")].insert(QStringLiteral("no_longer_admin_you"), QStringLiteral("Ви більше не адміністратор"));
    m_sysTranslations[QStringLiteral("Ukrainian")].insert(QStringLiteral("no_longer_admin"), QStringLiteral("{0} більше не адміністратор"));
    m_sysTranslations[QStringLiteral("Ukrainian")].insert(QStringLiteral("admin_approval_off"), QStringLiteral("{0} вимкнув(ла) підтвердження адміністратора. Торкніться, щоб змінити."));
    m_sysTranslations[QStringLiteral("Ukrainian")].insert(QStringLiteral("joined_link"), QStringLiteral("{0} приєднався(лась) за посиланням групи."));
    m_sysTranslations[QStringLiteral("Ukrainian")].insert(QStringLiteral("changed_icon"), QStringLiteral("{0} змінив(ла) іконку групи"));
    m_sysTranslations[QString::fromUtf8("Ukrainian")].insert(QStringLiteral("changed_name"), QString::fromUtf8("{0} змінив(ла) назву групи на \"{1}\""));
    m_sysTranslations[QString::fromUtf8("Ukrainian")].insert(QStringLiteral("changed_name_from_to"), QString::fromUtf8("{0} змінив(ла) назву групи з \"{1}\" на \"{2}\""));
    m_sysTranslations[QStringLiteral("Ukrainian")].insert(QStringLiteral("changed_desc"), QStringLiteral("{0} змінив(ла) опис групи"));
    m_sysTranslations[QStringLiteral("Ukrainian")].insert(QStringLiteral("settings_only_admins_edit"), QStringLiteral("{0} змінив(ла) налаштування: лише адміни можуть редагувати налаштування групи"));
    m_sysTranslations[QStringLiteral("Ukrainian")].insert(QStringLiteral("settings_all_edit"), QStringLiteral("{0} змінив(ла) налаштування: всі учасники можуть редагувати налаштування групи"));
    m_sysTranslations[QStringLiteral("Ukrainian")].insert(QStringLiteral("settings_only_admins_send"), QStringLiteral("{0} змінив(ла) налаштування групи: лише адміни можуть надсилати повідомлення"));
    m_sysTranslations[QStringLiteral("Ukrainian")].insert(QStringLiteral("settings_only_admins_add"), QStringLiteral("{0} змінив(ла) налаштування групи: лише адміни можуть додавати інших."));
    m_sysTranslations[QStringLiteral("Ukrainian")].insert(QStringLiteral("settings_all_add"), QStringLiteral("{0} змінив(ла) налаштування групи: всі учасники можуть додавати інших."));
    m_sysTranslations[QStringLiteral("Ukrainian")].insert(QStringLiteral("settings_all_send"), QStringLiteral("{0} змінив(ла) налаштування групи: всі учасники можуть надсилати повідомлення"));
    m_sysTranslations[QStringLiteral("Ukrainian")].insert(QStringLiteral("settings_all_invite_link"), QStringLiteral("{0} змінив(ла) налаштування групи: всі можуть запрошувати за посиланням."));
    m_sysTranslations[QStringLiteral("Ukrainian")].insert(QStringLiteral("anyone_invite_link"), QStringLiteral("Будь-хто в цій групі може запрошувати нових учасників за посиланням групи."));
    m_sysTranslations[QStringLiteral("Ukrainian")].insert(QStringLiteral("settings_only_admins_invite_link"), QStringLiteral("{0} змінив(ла) налаштування: лише адміни можуть запрошувати за посиланням."));
    m_sysTranslations[QStringLiteral("Ukrainian")].insert(QStringLiteral("reset_link"), QStringLiteral("{0} скинув(ла) посилання запрошення групи"));
    m_sysTranslations[QStringLiteral("Ukrainian")].insert(QStringLiteral("disappear_on"), QStringLiteral("{0} увімкнув(ла) зникаючі повідомлення. Нові повідомлення зникнуть через {timer} після надсилання (крім збережених). Торкніться, щоб змінити."));
    m_sysTranslations[QStringLiteral("Ukrainian")].insert(QStringLiteral("disappear_off"), QStringLiteral("{0} вимкнув(ла) зникаючі повідомлення. Торкніться, щоб змінити."));
    m_sysTranslations[QStringLiteral("Ukrainian")].insert(QStringLiteral("disappear_off2"), QStringLiteral("{0} вимкнув(ла) зникаючі повідомлення. Торкніться, щоб дізнатися більше."));
    m_sysTranslations[QStringLiteral("Ukrainian")].insert(QStringLiteral("update_timer"), QStringLiteral("{0} оновив(ла) таймер повідомлень. Нові повідомлення зникнуть через {timer} після надсилання (крім збережених). Торкніться, щоб змінити."));
    m_sysTranslations[QStringLiteral("Ukrainian")].insert(QStringLiteral("update_timer2"), QStringLiteral("{0} оновив(ла) таймер повідомлень. Нові повідомлення зникнуть через {timer}. Торкніться, щоб дізнатися більше."));
    m_sysTranslations[QStringLiteral("Ukrainian")].insert(QStringLiteral("voice_call"), QStringLiteral("Голосовий дзвінок. {1} • {0} приєднався(лась)"));
    m_sysTranslations[QStringLiteral("Ukrainian")].insert(QStringLiteral("video_call"), QStringLiteral("Відеодзвінок. {1} • {0} приєднався(лась)"));
    m_sysTranslations[QStringLiteral("Ukrainian")].insert(QStringLiteral("timer_24h"), QStringLiteral("24 години"));
    m_sysTranslations[QStringLiteral("Ukrainian")].insert(QStringLiteral("timer_7d"), QStringLiteral("7 днів"));
    m_sysTranslations[QStringLiteral("Ukrainian")].insert(QStringLiteral("timer_90d"), QStringLiteral("90 днів"));
    m_sysTranslations[QStringLiteral("Ukrainian")].insert(QStringLiteral("phone_number_changed"), QString::fromUtf8("{0} змінив(ла) номер телефону. Надішліть повідомлення або додайте новий номер."));

    // ── Uzbek ────────────────────────────────────────────────────────────────
    m_sysTranslations[QString::fromUtf8("Uzbek")].insert(QStringLiteral("created_group"), QString::fromUtf8("{0} \"{1}\" guruhini yaratdi"));
    m_sysTranslations[QStringLiteral("Uzbek")].insert(QStringLiteral("created_group_noname"), QStringLiteral("{0} bu guruhni yaratdi"));
    m_sysTranslations[QStringLiteral("Uzbek")].insert(QStringLiteral("e2e_note"), QStringLiteral("Xabarlar va qo'ng'iroqlar uchidan-uchiga shifrlangan. Faqat bu chatdagi odamlar ularni o'qishi, tinglashi yoki ulashishi mumkin."));
    m_sysTranslations[QStringLiteral("Uzbek")].insert(QStringLiteral("left"), QStringLiteral("{0} chiqib ketdi"));
    m_sysTranslations[QStringLiteral("Uzbek")].insert(QStringLiteral("added"), QStringLiteral("{0} {1}ni qo'shdi"));
    m_sysTranslations[QStringLiteral("Uzbek")].insert(QStringLiteral("was_added"), QStringLiteral("{0} qo'shildi"));
    m_sysTranslations[QStringLiteral("Uzbek")].insert(QStringLiteral("removed"), QStringLiteral("{0} {1}ni o'chirdi"));
    m_sysTranslations[QStringLiteral("Uzbek")].insert(QStringLiteral("you_now_admin"), QStringLiteral("Siz endi adminsiZ"));
    m_sysTranslations[QStringLiteral("Uzbek")].insert(QStringLiteral("now_admin"), QStringLiteral("{0} endi admin"));
    m_sysTranslations[QStringLiteral("Uzbek")].insert(QStringLiteral("admin_approval_on"), QStringLiteral("{0} guruhga qo'shilish uchun admin tasdig'ini yoqdi. O'zgartirish uchun bosing."));
    m_sysTranslations[QStringLiteral("Uzbek")].insert(QStringLiteral("no_longer_admin_you"), QStringLiteral("Siz endi admin emassiz"));
    m_sysTranslations[QStringLiteral("Uzbek")].insert(QStringLiteral("no_longer_admin"), QStringLiteral("{0} endi admin emas"));
    m_sysTranslations[QStringLiteral("Uzbek")].insert(QStringLiteral("admin_approval_off"), QStringLiteral("{0} admin tasdig'ini o'chirdi. O'zgartirish uchun bosing."));
    m_sysTranslations[QStringLiteral("Uzbek")].insert(QStringLiteral("joined_link"), QStringLiteral("{0} guruh havolasi orqali qo'shildi."));
    m_sysTranslations[QStringLiteral("Uzbek")].insert(QStringLiteral("changed_icon"), QStringLiteral("{0} guruh ikonkasini o'zgartirdi"));
    m_sysTranslations[QString::fromUtf8("Uzbek")].insert(QStringLiteral("changed_name"), QString::fromUtf8("{0} guruh nomini \"{1}\" deb o'zgartirdi"));
    m_sysTranslations[QString::fromUtf8("Uzbek")].insert(QStringLiteral("changed_name_from_to"), QString::fromUtf8("{0} guruh nomini \"{1}\"dan \"{2}\"ga o'zgartirdi"));
    m_sysTranslations[QStringLiteral("Uzbek")].insert(QStringLiteral("changed_desc"), QStringLiteral("{0} guruh tavsifini o'zgartirdi"));
    m_sysTranslations[QStringLiteral("Uzbek")].insert(QStringLiteral("settings_only_admins_edit"), QStringLiteral("{0} sozlamalarni faqat adminlar guruh sozlamalarini tahrirlashi mumkin qilib o'zgartirdi"));
    m_sysTranslations[QStringLiteral("Uzbek")].insert(QStringLiteral("settings_all_edit"), QStringLiteral("{0} sozlamalarni barcha a'zolar guruh sozlamalarini tahrirlashi mumkin qilib o'zgartirdi"));
    m_sysTranslations[QStringLiteral("Uzbek")].insert(QStringLiteral("settings_only_admins_send"), QStringLiteral("{0} guruh sozlamalarini faqat adminlar xabar yuborishi mumkin qilib o'zgartirdi"));
    m_sysTranslations[QStringLiteral("Uzbek")].insert(QStringLiteral("settings_only_admins_add"), QStringLiteral("{0} guruh sozlamalarini faqat adminlar boshqalarni qo'sha olishi uchun o'zgartirdi."));
    m_sysTranslations[QStringLiteral("Uzbek")].insert(QStringLiteral("settings_all_add"), QStringLiteral("{0} guruh sozlamalarini barcha a'zolar boshqalarni qo'sha olishi uchun o'zgartirdi."));
    m_sysTranslations[QStringLiteral("Uzbek")].insert(QStringLiteral("settings_all_send"), QStringLiteral("{0} guruh sozlamalarini barcha a'zolar xabar yuborishi mumkin qilib o'zgartirdi"));
    m_sysTranslations[QStringLiteral("Uzbek")].insert(QStringLiteral("settings_all_invite_link"), QStringLiteral("{0} guruh sozlamalarini barcha a'zolar havola orqali taklif qila olishi uchun o'zgartirdi."));
    m_sysTranslations[QStringLiteral("Uzbek")].insert(QStringLiteral("anyone_invite_link"), QStringLiteral("Bu guruhning har bir a'zosi guruh havolasi yordamida yangi a'zolarni taklif qila oladi."));
    m_sysTranslations[QStringLiteral("Uzbek")].insert(QStringLiteral("settings_only_admins_invite_link"), QStringLiteral("{0} sozlamalarni faqat adminlar havola orqali taklif qila olishi uchun o'zgartirdi."));
    m_sysTranslations[QStringLiteral("Uzbek")].insert(QStringLiteral("reset_link"), QStringLiteral("{0} guruhning taklif havolasini tikladi"));
    m_sysTranslations[QStringLiteral("Uzbek")].insert(QStringLiteral("disappear_on"), QStringLiteral("{0} yo'qoladigan xabarlarni yoqdi. Yangi xabarlar yuborilgandan {timer} o'tgach bu chatdan yo'qoladi (saqlanganlar bundan mustasno). O'zgartirish uchun bosing."));
    m_sysTranslations[QStringLiteral("Uzbek")].insert(QStringLiteral("disappear_off"), QStringLiteral("{0} yo'qoladigan xabarlarni o'chirdi. O'zgartirish uchun bosing."));
    m_sysTranslations[QStringLiteral("Uzbek")].insert(QStringLiteral("disappear_off2"), QStringLiteral("{0} yo'qoladigan xabarlarni o'chirdi. Ko'proq bilish uchun bosing."));
    m_sysTranslations[QStringLiteral("Uzbek")].insert(QStringLiteral("update_timer"), QStringLiteral("{0} xabar taymerini yangiladi. Yangi xabarlar yuborilgandan {timer} o'tgach yo'qoladi (saqlanganlar bundan mustasno). O'zgartirish uchun bosing."));
    m_sysTranslations[QStringLiteral("Uzbek")].insert(QStringLiteral("update_timer2"), QStringLiteral("{0} xabar taymerini yangiladi. Yangi xabarlar {timer} o'tgach yo'qoladi. Ko'proq bilish uchun bosing."));
    m_sysTranslations[QStringLiteral("Uzbek")].insert(QStringLiteral("voice_call"), QStringLiteral("Ovozli qo'ng'iroq. {1} • {0} qo'shildi"));
    m_sysTranslations[QStringLiteral("Uzbek")].insert(QStringLiteral("video_call"), QStringLiteral("Video qo'ng'iroq. {1} • {0} qo'shildi"));
    m_sysTranslations[QStringLiteral("Uzbek")].insert(QStringLiteral("timer_24h"), QStringLiteral("24 soat"));
    m_sysTranslations[QStringLiteral("Uzbek")].insert(QStringLiteral("timer_7d"), QStringLiteral("7 kun"));
    m_sysTranslations[QStringLiteral("Uzbek")].insert(QStringLiteral("timer_90d"), QStringLiteral("90 kun"));
    m_sysTranslations[QStringLiteral("Uzbek")].insert(QStringLiteral("phone_number_changed"), QStringLiteral("{0} telefon raqamini o'zgartirdi. Yangi raqamga xabar yuboring yoki qo'shing."));

    // ─────────────────────────────────────────────────────────────────────────
    // 2nd-person ("You ...") variants for every supported language.
    //
    // These templates are selected automatically by translateSystemMessage()
    // when the WhatsApp export contains "You" as the actor (key + "_you") or
    // "you" as the target of an addressed action (key + "_target_you", used
    // only for added/removed). The 3rd-person templates above remain unchanged
    // so messages about other participants keep their original wording.
    // ─────────────────────────────────────────────────────────────────────────
    initSystemTranslationsYou();
}

// ─────────────────────────────────────────────────────────────────────────────
// 2nd-person system-message templates.
//
// For each supported language we provide:
//   <key>_you          — actor is "You" (e.g. "You created group X")
//   <key>_target_you   — target is "you" (e.g. "Alice added you")
//                        (only for keys with an addressed object: added,
//                         removed)
//
// The {0} placeholder is intentionally omitted from _you templates because the
// localised pronoun is baked into the sentence (e.g. "Sən", "Du", "Вы"). The
// {1} / {2} / {timer} placeholders behave the same way as in the 3rd-person
// templates, so translateSystemMessage()'s replacement logic is unchanged.
// ─────────────────────────────────────────────────────────────────────────────
void LanguageManager::initSystemTranslationsYou()
{
    // Helper to keep each insert on a single line (mirrors initSystemTranslations style).
    #define WAY(LANG, KEY, VAL) m_sysTranslations[QStringLiteral(LANG)].insert(QStringLiteral(KEY), QString::fromUtf8(VAL))

    // ── Azerbaijani — 2nd person (sən) ───────────────────────────────────────
    WAY("Azerbaijani", "created_group_you", "Sən \"{1}\" qrupunu yaratdın");
    WAY("Azerbaijani", "created_group_noname_you", "Sən bu qrupu yaratdın");
    WAY("Azerbaijani", "left_you", "Sən çıxdın");
    WAY("Azerbaijani", "added_you", "Sən {1}-ni əlavə etdin");
    WAY("Azerbaijani", "added_target_you", "{0} səni əlavə etdi");
    WAY("Azerbaijani", "was_added_you", "Sən əlavə edildin");
    WAY("Azerbaijani", "removed_you", "Sən {1}-ni çıxardın");
    WAY("Azerbaijani", "removed_target_you", "{0} səni çıxardı");
    WAY("Azerbaijani", "joined_link_you", "Sən qrup linki ilə qoşuldun.");
    WAY("Azerbaijani", "changed_icon_you", "Sən qrupun ikonunu dəyişdin");
    WAY("Azerbaijani", "changed_name_you", "Sən qrupun adını \"{1}\" olaraq dəyişdin");
    WAY("Azerbaijani", "changed_name_from_to_you", "Sən qrupun adını \"{1}\"-dən \"{2}\"-yə dəyişdin");
    WAY("Azerbaijani", "changed_desc_you", "Sən qrupun təsvirini dəyişdin");
    WAY("Azerbaijani", "admin_approval_on_you", "Sən qrupa qoşulmaq üçün admin təsdiqini açdın. Dəyişmək üçün toxunun.");
    WAY("Azerbaijani", "admin_approval_off_you", "Sən qrupa qoşulmaq üçün admin təsdiqini bağladın. Dəyişmək üçün toxunun.");
    WAY("Azerbaijani", "reset_link_you", "Sən qrupun dəvət linkini sıfırladın");
    WAY("Azerbaijani", "settings_only_admins_edit_you", "Sən parametrləri elə dəyişdin ki, yalnız adminlər qrup parametrlərini redaktə edə bilsin");
    WAY("Azerbaijani", "settings_all_edit_you", "Sən parametrləri elə dəyişdin ki, bütün üzvlər qrup parametrlərini redaktə edə bilsin");
    WAY("Azerbaijani", "settings_only_admins_send_you", "Sən bu qrupun parametrlərini elə dəyişdin ki, yalnız adminlər mesaj göndərə bilsin");
    WAY("Azerbaijani", "settings_only_admins_add_you", "Sən bu qrupun parametrlərini elə dəyişdin ki, yalnız adminlər başqalarını əlavə edə bilsin.");
    WAY("Azerbaijani", "settings_all_add_you", "Sən bu qrupun parametrlərini elə dəyişdin ki, bütün üzvlər başqalarını əlavə edə bilsin.");
    WAY("Azerbaijani", "settings_all_send_you", "Sən bu qrupun parametrlərini elə dəyişdin ki, bütün üzvlər mesaj göndərə bilsin");
    WAY("Azerbaijani", "settings_all_invite_link_you", "Sən bu qrupun parametrlərini elə dəyişdin ki, bütün üzvlər qrup linki ilə dəvət edə bilsin.");
    WAY("Azerbaijani", "settings_only_admins_invite_link_you", "Sən bu qrupun parametrlərini elə dəyişdin ki, yalnız adminlər qrup linki ilə dəvət edə bilsin.");
    WAY("Azerbaijani", "disappear_on_you", "Sən yoxa çıxan mesajları açdın. Yeni mesajlar göndərildikdən {timer} sonra bu söhbətdən yox olacaq (saxlanılanlar istisna). Dəyişmək üçün toxunun.");
    WAY("Azerbaijani", "disappear_off_you", "Sən yoxa çıxan mesajları bağladın. Dəyişmək üçün toxunun.");
    WAY("Azerbaijani", "disappear_off2_you", "Sən yoxa çıxan mesajları bağladın. Ətraflı öyrənmək üçün toxunun.");
    WAY("Azerbaijani", "update_timer_you", "Sən mesaj taymerini yenilədin. Yeni mesajlar göndərildikdən {timer} sonra bu söhbətdən yox olacaq (saxlanılanlar istisna). Dəyişmək üçün toxunun.");
    WAY("Azerbaijani", "update_timer2_you", "Sən mesaj taymerini yenilədin. Yeni mesajlar göndərildikdən {timer} sonra bu söhbətdən yox olacaq (saxlanılanlar istisna). Ətraflı öyrənmək üçün toxunun.");

    // ── English — 2nd person (You) ───────────────────────────────────────────
    WAY("English", "created_group_you", "You created group \"{1}\"");
    WAY("English", "created_group_noname_you", "You created this group");
    WAY("English", "left_you", "You left");
    WAY("English", "added_you", "You added {1}");
    WAY("English", "added_target_you", "{0} added you");
    WAY("English", "was_added_you", "You were added");
    WAY("English", "removed_you", "You removed {1}");
    WAY("English", "removed_target_you", "{0} removed you");
    WAY("English", "joined_link_you", "You joined using a group link.");
    WAY("English", "changed_icon_you", "You changed this group's icon");
    WAY("English", "changed_name_you", "You changed the group name to \"{1}\"");
    WAY("English", "changed_name_from_to_you", "You changed the group name from \"{1}\" to \"{2}\"");
    WAY("English", "changed_desc_you", "You changed the group description");
    WAY("English", "admin_approval_on_you", "You turned on admin approval to join this group. Tap to change.");
    WAY("English", "admin_approval_off_you", "You turned off admin approval to join this group. Tap to change.");
    WAY("English", "reset_link_you", "You reset this group's invite link");
    WAY("English", "settings_only_admins_edit_you", "You changed the settings so only admins can edit the group settings");
    WAY("English", "settings_all_edit_you", "You changed the settings so all members can edit the group settings");
    WAY("English", "settings_only_admins_send_you", "You changed this group's settings to allow only admins to send messages to this group");
    WAY("English", "settings_only_admins_add_you", "You changed this group's settings to allow only admins to add others to this group.");
    WAY("English", "settings_all_add_you", "You changed this group's settings to allow all members to add others to this group.");
    WAY("English", "settings_all_send_you", "You changed this group's settings to allow all members to send messages to this group");
    WAY("English", "settings_all_invite_link_you", "You changed this group's settings to allow all members to invite people to this group using a group link.");
    WAY("English", "settings_only_admins_invite_link_you", "You changed this group's settings to allow only admins to invite people to this group using a group link.");
    WAY("English", "disappear_on_you", "You turned on disappearing messages. New messages will disappear from this chat {timer} after they're sent, except when kept. Tap to change.");
    WAY("English", "disappear_off_you", "You turned off disappearing messages. Tap to change.");
    WAY("English", "disappear_off2_you", "You turned off disappearing messages. Tap to learn more.");
    WAY("English", "update_timer_you", "You updated the message timer. New messages will disappear from this chat {timer} after they're sent, except when kept. Tap to change.");
    WAY("English", "update_timer2_you", "You updated the message timer. New messages will disappear from this chat {timer} after they're sent, except when kept. Tap to learn more.");

    // ── Turkish — 2nd person (sen) ───────────────────────────────────────────
    WAY("Turkish", "created_group_you", "Sen \"{1}\" grubunu oluşturdun");
    WAY("Turkish", "created_group_noname_you", "Sen bu grubu oluşturdun");
    WAY("Turkish", "left_you", "Sen ayrıldın");
    WAY("Turkish", "added_you", "Sen {1} kişisini ekledin");
    WAY("Turkish", "added_target_you", "{0}, seni ekledi");
    WAY("Turkish", "was_added_you", "Sen eklendin");
    WAY("Turkish", "removed_you", "Sen {1} kişisini çıkardın");
    WAY("Turkish", "removed_target_you", "{0}, seni çıkardı");
    WAY("Turkish", "joined_link_you", "Sen grup bağlantısı kullanarak katıldın.");
    WAY("Turkish", "changed_icon_you", "Sen grubun simgesini değiştirdin");
    WAY("Turkish", "changed_name_you", "Sen grup adını \"{1}\" olarak değiştirdin");
    WAY("Turkish", "changed_name_from_to_you", "Sen grup adını \"{1}\"-dan \"{2}\"-na değiştirdin");
    WAY("Turkish", "changed_desc_you", "Sen grup açıklamasını değiştirdin");
    WAY("Turkish", "admin_approval_on_you", "Sen bu gruba katılmak için yönetici onayını açtın. Değiştirmek için dokunun.");
    WAY("Turkish", "admin_approval_off_you", "Sen bu gruba katılmak için yönetici onayını kapattın. Değiştirmek için dokunun.");
    WAY("Turkish", "reset_link_you", "Sen grubun davet bağlantısını sıfırladın");
    WAY("Turkish", "settings_only_admins_edit_you", "Sen ayarları yalnızca yöneticilerin grup ayarlarını düzenleyebileceği şekilde değiştirdin");
    WAY("Turkish", "settings_all_edit_you", "Sen ayarları tüm üyelerin grup ayarlarını düzenleyebileceği şekilde değiştirdin");
    WAY("Turkish", "settings_only_admins_send_you", "Sen bu grubun ayarlarını yalnızca yöneticilerin mesaj gönderebileceği şekilde değiştirdin");
    WAY("Turkish", "settings_only_admins_add_you", "Sen bu grubun ayarlarını yalnızca yöneticilerin başkalarını ekleyebileceği şekilde değiştirdin.");
    WAY("Turkish", "settings_all_add_you", "Sen bu grubun ayarlarını tüm üyelerin başkalarını ekleyebileceği şekilde değiştirdin.");
    WAY("Turkish", "settings_all_send_you", "Sen bu grubun ayarlarını tüm üyelerin mesaj gönderebileceği şekilde değiştirdin");
    WAY("Turkish", "settings_all_invite_link_you", "Sen bu grubun ayarlarını tüm üyelerin grup bağlantısıyla davet edebileceği şekilde değiştirdin.");
    WAY("Turkish", "settings_only_admins_invite_link_you", "Sen bu grubun ayarlarını yalnızca yöneticilerin grup bağlantısıyla davet edebileceği şekilde değiştirdin.");
    WAY("Turkish", "disappear_on_you", "Sen kaybolan mesajları açtın. Yeni mesajlar gönderildikten {timer} sonra bu sohbetten kaybolacak (saklananlar hariç). Değiştirmek için dokunun.");
    WAY("Turkish", "disappear_off_you", "Sen kaybolan mesajları kapattın. Değiştirmek için dokunun.");
    WAY("Turkish", "disappear_off2_you", "Sen kaybolan mesajları kapattın. Daha fazla bilgi için dokunun.");
    WAY("Turkish", "update_timer_you", "Sen mesaj zamanlayıcısını güncelledin. Yeni mesajlar gönderildikten {timer} sonra bu sohbetten kaybolacak (saklananlar hariç). Değiştirmek için dokunun.");
    WAY("Turkish", "update_timer2_you", "Sen mesaj zamanlayıcısını güncelledin. Yeni mesajlar gönderildikten {timer} sonra bu sohbetten kaybolacak (saklananlar hariç). Daha fazla bilgi için dokunun.");

    // ── Russian — 2nd person (Вы, formal) ────────────────────────────────────
    WAY("Russian", "created_group_you", "Вы создали группу \"{1}\"");
    WAY("Russian", "created_group_noname_you", "Вы создали эту группу");
    WAY("Russian", "left_you", "Вы вышли");
    WAY("Russian", "added_you", "Вы добавили {1}");
    WAY("Russian", "added_target_you", "{0} добавил(а) вас");
    WAY("Russian", "was_added_you", "Вы были добавлены");
    WAY("Russian", "removed_you", "Вы удалили {1}");
    WAY("Russian", "removed_target_you", "{0} удалил(а) вас");
    WAY("Russian", "joined_link_you", "Вы вступили по ссылке.");
    WAY("Russian", "changed_icon_you", "Вы изменили значок группы");
    WAY("Russian", "changed_name_you", "Вы изменили название группы на \"{1}\"");
    WAY("Russian", "changed_name_from_to_you", "Вы изменили название группы с \"{1}\" на \"{2}\"");
    WAY("Russian", "changed_desc_you", "Вы изменили описание группы");
    WAY("Russian", "admin_approval_on_you", "Вы включили подтверждение администратором для вступления в группу. Нажмите, чтобы изменить.");
    WAY("Russian", "admin_approval_off_you", "Вы отключили подтверждение администратором для вступления в группу. Нажмите, чтобы изменить.");
    WAY("Russian", "reset_link_you", "Вы сбросили ссылку для приглашения в группу");
    WAY("Russian", "settings_only_admins_edit_you", "Вы изменили настройки: редактировать параметры группы могут только администраторы");
    WAY("Russian", "settings_all_edit_you", "Вы изменили настройки: редактировать параметры группы могут все участники");
    WAY("Russian", "settings_only_admins_send_you", "Вы изменили настройки группы: отправлять сообщения могут только администраторы");
    WAY("Russian", "settings_only_admins_add_you", "Вы изменили настройки группы: добавлять участников могут только администраторы.");
    WAY("Russian", "settings_all_add_you", "Вы изменили настройки группы: добавлять участников могут все.");
    WAY("Russian", "settings_all_send_you", "Вы изменили настройки группы: отправлять сообщения могут все участники");
    WAY("Russian", "settings_all_invite_link_you", "Вы изменили настройки группы: приглашать по ссылке могут все участники.");
    WAY("Russian", "settings_only_admins_invite_link_you", "Вы изменили настройки группы: приглашать по ссылке могут только администраторы.");
    WAY("Russian", "disappear_on_you", "Вы включили исчезающие сообщения. Новые сообщения будут удалены через {timer} после отправки (кроме сохранённых). Нажмите, чтобы изменить.");
    WAY("Russian", "disappear_off_you", "Вы выключили исчезающие сообщения. Нажмите, чтобы изменить.");
    WAY("Russian", "disappear_off2_you", "Вы выключили исчезающие сообщения. Нажмите, чтобы узнать больше.");
    WAY("Russian", "update_timer_you", "Вы обновили таймер сообщений. Новые сообщения будут удалены через {timer} после отправки (кроме сохранённых). Нажмите, чтобы изменить.");
    WAY("Russian", "update_timer2_you", "Вы обновили таймер сообщений. Новые сообщения будут удалены через {timer} после отправки (кроме сохранённых). Нажмите, чтобы узнать больше.");

    // ── Arabic — 2nd person (verb conjugated for أنت) ────────────────────────
    WAY("Arabic", "created_group_you", "أنشأت المجموعة \"{1}\"");
    WAY("Arabic", "created_group_noname_you", "أنشأت هذه المجموعة");
    WAY("Arabic", "left_you", "غادرت");
    WAY("Arabic", "added_you", "أضفت {1}");
    WAY("Arabic", "added_target_you", "أضافك {0}");
    WAY("Arabic", "was_added_you", "تمت إضافتك");
    WAY("Arabic", "removed_you", "أزلت {1}");
    WAY("Arabic", "removed_target_you", "أزالك {0}");
    WAY("Arabic", "joined_link_you", "انضممت باستخدام رابط المجموعة.");
    WAY("Arabic", "changed_icon_you", "غيّرت أيقونة المجموعة");
    WAY("Arabic", "changed_name_you", "غيّرت اسم المجموعة إلى \"{1}\"");
    WAY("Arabic", "changed_name_from_to_you", "غيّرت اسم المجموعة من \"{1}\" إلى \"{2}\"");
    WAY("Arabic", "changed_desc_you", "غيّرت وصف المجموعة");
    WAY("Arabic", "admin_approval_on_you", "فعّلت موافقة المسؤول للانضمام إلى هذه المجموعة. اضغط للتغيير.");
    WAY("Arabic", "admin_approval_off_you", "عطّلت موافقة المسؤول للانضمام إلى هذه المجموعة. اضغط للتغيير.");
    WAY("Arabic", "reset_link_you", "أعدت تعيين رابط دعوة المجموعة");
    WAY("Arabic", "settings_only_admins_edit_you", "غيّرت الإعدادات بحيث يمكن للمسؤولين فقط تعديل إعدادات المجموعة");
    WAY("Arabic", "settings_all_edit_you", "غيّرت الإعدادات بحيث يمكن لجميع الأعضاء تعديل إعدادات المجموعة");
    WAY("Arabic", "settings_only_admins_send_you", "غيّرت إعدادات المجموعة بحيث يمكن للمسؤولين فقط إرسال الرسائل");
    WAY("Arabic", "settings_only_admins_add_you", "غيّرت إعدادات المجموعة بحيث يمكن للمسؤولين فقط إضافة أعضاء آخرين.");
    WAY("Arabic", "settings_all_add_you", "غيّرت إعدادات المجموعة بحيث يمكن لجميع الأعضاء إضافة أعضاء آخرين.");
    WAY("Arabic", "settings_all_send_you", "غيّرت إعدادات المجموعة بحيث يمكن لجميع الأعضاء إرسال الرسائل");
    WAY("Arabic", "settings_all_invite_link_you", "غيّرت إعدادات المجموعة بحيث يمكن لجميع الأعضاء دعوة أشخاص بالرابط.");
    WAY("Arabic", "settings_only_admins_invite_link_you", "غيّرت إعدادات المجموعة بحيث يمكن للمسؤولين فقط دعوة أشخاص بالرابط.");
    WAY("Arabic", "disappear_on_you", "فعّلت الرسائل المؤقتة. ستختفي الرسائل الجديدة من هذه المحادثة بعد {timer} من إرسالها، إلا إذا احتُفظ بها. اضغط للتغيير.");
    WAY("Arabic", "disappear_off_you", "عطّلت الرسائل المؤقتة. اضغط للتغيير.");
    WAY("Arabic", "disappear_off2_you", "عطّلت الرسائل المؤقتة. اضغط لمعرفة المزيد.");
    WAY("Arabic", "update_timer_you", "حدّثت مؤقت الرسائل. ستختفي الرسائل الجديدة من هذه المحادثة بعد {timer} من إرسالها، إلا إذا احتُفظ بها. اضغط للتغيير.");
    WAY("Arabic", "update_timer2_you", "حدّثت مؤقت الرسائل. ستختفي الرسائل الجديدة بعد {timer} من إرسالها، إلا إذا احتُفظ بها. اضغط لمعرفة المزيد.");

    // ── Spanish — 2nd person (tú, informal) ──────────────────────────────────
    WAY("Spanish", "created_group_you", "Creaste el grupo \"{1}\"");
    WAY("Spanish", "created_group_noname_you", "Creaste este grupo");
    WAY("Spanish", "left_you", "Saliste");
    WAY("Spanish", "added_you", "Agregaste a {1}");
    WAY("Spanish", "added_target_you", "{0} te agregó");
    WAY("Spanish", "was_added_you", "Fuiste agregado(a)");
    WAY("Spanish", "removed_you", "Eliminaste a {1}");
    WAY("Spanish", "removed_target_you", "{0} te eliminó");
    WAY("Spanish", "joined_link_you", "Te uniste usando el enlace del grupo.");
    WAY("Spanish", "changed_icon_you", "Cambiaste el ícono del grupo");
    WAY("Spanish", "changed_name_you", "Cambiaste el nombre del grupo a \"{1}\"");
    WAY("Spanish", "changed_name_from_to_you", "Cambiaste el nombre del grupo de \"{1}\" a \"{2}\"");
    WAY("Spanish", "changed_desc_you", "Cambiaste la descripción del grupo");
    WAY("Spanish", "admin_approval_on_you", "Activaste la aprobación de administrador para unirse al grupo. Toca para cambiar.");
    WAY("Spanish", "admin_approval_off_you", "Desactivaste la aprobación de administrador para unirse al grupo. Toca para cambiar.");
    WAY("Spanish", "reset_link_you", "Restableciste el enlace de invitación del grupo");
    WAY("Spanish", "settings_only_admins_edit_you", "Cambiaste los ajustes para que solo los administradores puedan editar los ajustes del grupo");
    WAY("Spanish", "settings_all_edit_you", "Cambiaste los ajustes para que todos los miembros puedan editar los ajustes del grupo");
    WAY("Spanish", "settings_only_admins_send_you", "Cambiaste los ajustes del grupo para que solo los administradores puedan enviar mensajes");
    WAY("Spanish", "settings_only_admins_add_you", "Cambiaste los ajustes del grupo para que solo los administradores puedan agregar a otros.");
    WAY("Spanish", "settings_all_add_you", "Cambiaste los ajustes del grupo para que todos los miembros puedan agregar a otros.");
    WAY("Spanish", "settings_all_send_you", "Cambiaste los ajustes del grupo para que todos los miembros puedan enviar mensajes");
    WAY("Spanish", "settings_all_invite_link_you", "Cambiaste los ajustes del grupo para que todos los miembros puedan invitar personas con el enlace.");
    WAY("Spanish", "settings_only_admins_invite_link_you", "Cambiaste los ajustes para que solo los administradores puedan invitar personas con el enlace.");
    WAY("Spanish", "disappear_on_you", "Activaste los mensajes temporales. Los mensajes nuevos desaparecerán {timer} después de ser enviados, excepto los guardados. Toca para cambiar.");
    WAY("Spanish", "disappear_off_you", "Desactivaste los mensajes temporales. Toca para cambiar.");
    WAY("Spanish", "disappear_off2_you", "Desactivaste los mensajes temporales. Toca para obtener más información.");
    WAY("Spanish", "update_timer_you", "Actualizaste el temporizador. Los mensajes nuevos desaparecerán {timer} después de ser enviados, excepto los guardados. Toca para cambiar.");
    WAY("Spanish", "update_timer2_you", "Actualizaste el temporizador. Los mensajes nuevos desaparecerán {timer} después de ser enviados, excepto los guardados. Toca para obtener más información.");

    // ── Portuguese — 2nd person (você) ───────────────────────────────────────
    WAY("Portuguese", "created_group_you", "Você criou o grupo \"{1}\"");
    WAY("Portuguese", "created_group_noname_you", "Você criou este grupo");
    WAY("Portuguese", "left_you", "Você saiu");
    WAY("Portuguese", "added_you", "Você adicionou {1}");
    WAY("Portuguese", "added_target_you", "{0} adicionou você");
    WAY("Portuguese", "was_added_you", "Você foi adicionado(a)");
    WAY("Portuguese", "removed_you", "Você removeu {1}");
    WAY("Portuguese", "removed_target_you", "{0} removeu você");
    WAY("Portuguese", "joined_link_you", "Você entrou usando o link do grupo.");
    WAY("Portuguese", "changed_icon_you", "Você alterou o ícone do grupo");
    WAY("Portuguese", "changed_name_you", "Você alterou o nome do grupo para \"{1}\"");
    WAY("Portuguese", "changed_name_from_to_you", "Você alterou o nome do grupo de \"{1}\" para \"{2}\"");
    WAY("Portuguese", "changed_desc_you", "Você alterou a descrição do grupo");
    WAY("Portuguese", "admin_approval_on_you", "Você ativou a aprovação de administrador para entrar neste grupo. Toque para alterar.");
    WAY("Portuguese", "admin_approval_off_you", "Você desativou a aprovação de administrador para entrar neste grupo. Toque para alterar.");
    WAY("Portuguese", "reset_link_you", "Você redefiniu o link de convite do grupo");
    WAY("Portuguese", "settings_only_admins_edit_you", "Você alterou as configurações para que apenas administradores possam editar as configurações do grupo");
    WAY("Portuguese", "settings_all_edit_you", "Você alterou as configurações para que todos os membros possam editar as configurações do grupo");
    WAY("Portuguese", "settings_only_admins_send_you", "Você alterou as configurações do grupo para que apenas administradores possam enviar mensagens");
    WAY("Portuguese", "settings_only_admins_add_you", "Você alterou as configurações do grupo para que apenas administradores possam adicionar outros.");
    WAY("Portuguese", "settings_all_add_you", "Você alterou as configurações do grupo para que todos os membros possam adicionar outros.");
    WAY("Portuguese", "settings_all_send_you", "Você alterou as configurações do grupo para que todos os membros possam enviar mensagens");
    WAY("Portuguese", "settings_all_invite_link_you", "Você alterou as configurações do grupo para que todos possam convidar pelo link.");
    WAY("Portuguese", "settings_only_admins_invite_link_you", "Você alterou as configurações para que apenas administradores possam convidar pelo link.");
    WAY("Portuguese", "disappear_on_you", "Você ativou as mensagens temporárias. As novas mensagens desaparecerão {timer} após o envio, exceto as salvas. Toque para alterar.");
    WAY("Portuguese", "disappear_off_you", "Você desativou as mensagens temporárias. Toque para alterar.");
    WAY("Portuguese", "disappear_off2_you", "Você desativou as mensagens temporárias. Toque para saber mais.");
    WAY("Portuguese", "update_timer_you", "Você atualizou o temporizador. As novas mensagens desaparecerão {timer} após o envio, exceto as salvas. Toque para alterar.");
    WAY("Portuguese", "update_timer2_you", "Você atualizou o temporizador. As novas mensagens desaparecerão {timer} após o envio, exceto as salvas. Toque para saber mais.");

    // ── Italian — 2nd person (tu) ────────────────────────────────────────────
    WAY("Italian", "created_group_you", "Hai creato il gruppo \"{1}\"");
    WAY("Italian", "created_group_noname_you", "Hai creato questo gruppo");
    WAY("Italian", "left_you", "Sei uscito/a");
    WAY("Italian", "added_you", "Hai aggiunto {1}");
    WAY("Italian", "added_target_you", "{0} ti ha aggiunto");
    WAY("Italian", "was_added_you", "Sei stato/a aggiunto/a");
    WAY("Italian", "removed_you", "Hai rimosso {1}");
    WAY("Italian", "removed_target_you", "{0} ti ha rimosso");
    WAY("Italian", "joined_link_you", "Ti sei unito/a usando il link del gruppo.");
    WAY("Italian", "changed_icon_you", "Hai cambiato l'icona del gruppo");
    WAY("Italian", "changed_name_you", "Hai cambiato il nome del gruppo in \"{1}\"");
    WAY("Italian", "changed_name_from_to_you", "Hai cambiato il nome del gruppo da \"{1}\" a \"{2}\"");
    WAY("Italian", "changed_desc_you", "Hai cambiato la descrizione del gruppo");
    WAY("Italian", "admin_approval_on_you", "Hai attivato l'approvazione dell'amministratore per unirsi al gruppo. Tocca per modificare.");
    WAY("Italian", "admin_approval_off_you", "Hai disattivato l'approvazione dell'amministratore. Tocca per modificare.");
    WAY("Italian", "reset_link_you", "Hai reimpostato il link di invito del gruppo");
    WAY("Italian", "settings_only_admins_edit_you", "Hai modificato le impostazioni in modo che solo gli amministratori possano modificarle");
    WAY("Italian", "settings_all_edit_you", "Hai modificato le impostazioni in modo che tutti i membri possano modificarle");
    WAY("Italian", "settings_only_admins_send_you", "Hai modificato le impostazioni del gruppo: solo gli amministratori possono inviare messaggi");
    WAY("Italian", "settings_only_admins_add_you", "Hai modificato le impostazioni: solo gli amministratori possono aggiungere altri.");
    WAY("Italian", "settings_all_add_you", "Hai modificato le impostazioni: tutti i membri possono aggiungere altri.");
    WAY("Italian", "settings_all_send_you", "Hai modificato le impostazioni: tutti i membri possono inviare messaggi");
    WAY("Italian", "settings_all_invite_link_you", "Hai modificato le impostazioni: tutti possono invitare con il link.");
    WAY("Italian", "settings_only_admins_invite_link_you", "Hai modificato le impostazioni: solo gli amministratori possono invitare con il link.");
    WAY("Italian", "disappear_on_you", "Hai attivato i messaggi temporanei. I nuovi messaggi spariranno {timer} dopo l'invio, tranne quelli salvati. Tocca per modificare.");
    WAY("Italian", "disappear_off_you", "Hai disattivato i messaggi temporanei. Tocca per modificare.");
    WAY("Italian", "disappear_off2_you", "Hai disattivato i messaggi temporanei. Tocca per saperne di più.");
    WAY("Italian", "update_timer_you", "Hai aggiornato il timer. I nuovi messaggi spariranno {timer} dopo l'invio, tranne quelli salvati. Tocca per modificare.");
    WAY("Italian", "update_timer2_you", "Hai aggiornato il timer. I nuovi messaggi spariranno {timer} dopo l'invio, tranne quelli salvati. Tocca per saperne di più.");

    // ── French — 2nd person (vous, formal) ───────────────────────────────────
    WAY("French", "created_group_you", "Vous avez créé le groupe \"{1}\"");
    WAY("French", "created_group_noname_you", "Vous avez créé ce groupe");
    WAY("French", "left_you", "Vous avez quitté le groupe");
    WAY("French", "added_you", "Vous avez ajouté {1}");
    WAY("French", "added_target_you", "{0} vous a ajouté");
    WAY("French", "was_added_you", "Vous avez été ajouté(e)");
    WAY("French", "removed_you", "Vous avez supprimé {1}");
    WAY("French", "removed_target_you", "{0} vous a supprimé");
    WAY("French", "joined_link_you", "Vous avez rejoint via le lien du groupe.");
    WAY("French", "changed_icon_you", "Vous avez modifié l'icône du groupe");
    WAY("French", "changed_name_you", "Vous avez changé le nom du groupe en \"{1}\"");
    WAY("French", "changed_name_from_to_you", "Vous avez changé le nom du groupe de \"{1}\" en \"{2}\"");
    WAY("French", "changed_desc_you", "Vous avez modifié la description du groupe");
    WAY("French", "admin_approval_on_you", "Vous avez activé l'approbation admin pour rejoindre ce groupe. Appuyez pour modifier.");
    WAY("French", "admin_approval_off_you", "Vous avez désactivé l'approbation admin. Appuyez pour modifier.");
    WAY("French", "reset_link_you", "Vous avez réinitialisé le lien d'invitation du groupe");
    WAY("French", "settings_only_admins_edit_you", "Vous avez modifié les paramètres pour que seuls les admins puissent modifier les paramètres du groupe");
    WAY("French", "settings_all_edit_you", "Vous avez modifié les paramètres pour que tous les membres puissent modifier les paramètres du groupe");
    WAY("French", "settings_only_admins_send_you", "Vous avez modifié les paramètres du groupe : seuls les admins peuvent envoyer des messages");
    WAY("French", "settings_only_admins_add_you", "Vous avez modifié les paramètres du groupe : seuls les admins peuvent ajouter des membres.");
    WAY("French", "settings_all_add_you", "Vous avez modifié les paramètres du groupe : tous les membres peuvent ajouter des membres.");
    WAY("French", "settings_all_send_you", "Vous avez modifié les paramètres du groupe : tous les membres peuvent envoyer des messages");
    WAY("French", "settings_all_invite_link_you", "Vous avez modifié les paramètres du groupe : tous peuvent inviter par lien.");
    WAY("French", "settings_only_admins_invite_link_you", "Vous avez modifié les paramètres : seuls les admins peuvent inviter par lien.");
    WAY("French", "disappear_on_you", "Vous avez activé les messages éphémères. Les nouveaux messages disparaîtront {timer} après l'envoi, sauf s'ils sont conservés. Appuyez pour modifier.");
    WAY("French", "disappear_off_you", "Vous avez désactivé les messages éphémères. Appuyez pour modifier.");
    WAY("French", "disappear_off2_you", "Vous avez désactivé les messages éphémères. Appuyez pour en savoir plus.");
    WAY("French", "update_timer_you", "Vous avez mis à jour le minuteur. Les nouveaux messages disparaîtront {timer} après l'envoi, sauf s'ils sont conservés. Appuyez pour modifier.");
    WAY("French", "update_timer2_you", "Vous avez mis à jour le minuteur. Les nouveaux messages disparaîtront {timer} après l'envoi, sauf s'ils sont conservés. Appuyez pour en savoir plus.");

    // ── German — 2nd person (du, informal) ───────────────────────────────────
    WAY("German", "created_group_you", "Du hast die Gruppe \"{1}\" erstellt");
    WAY("German", "created_group_noname_you", "Du hast diese Gruppe erstellt");
    WAY("German", "left_you", "Du hast die Gruppe verlassen");
    WAY("German", "added_you", "Du hast {1} hinzugefügt");
    WAY("German", "added_target_you", "{0} hat dich hinzugefügt");
    WAY("German", "was_added_you", "Du wurdest hinzugefügt");
    WAY("German", "removed_you", "Du hast {1} entfernt");
    WAY("German", "removed_target_you", "{0} hat dich entfernt");
    WAY("German", "joined_link_you", "Du bist über den Gruppenlink beigetreten.");
    WAY("German", "changed_icon_you", "Du hast das Gruppen-Icon geändert");
    WAY("German", "changed_name_you", "Du hast den Gruppennamen in \"{1}\" geändert");
    WAY("German", "changed_name_from_to_you", "Du hast den Gruppennamen von \"{1}\" in \"{2}\" geändert");
    WAY("German", "changed_desc_you", "Du hast die Gruppenbeschreibung geändert");
    WAY("German", "admin_approval_on_you", "Du hast die Admin-Genehmigung zum Beitreten dieser Gruppe aktiviert. Tippe zum Ändern.");
    WAY("German", "admin_approval_off_you", "Du hast die Admin-Genehmigung zum Beitreten deaktiviert. Tippe zum Ändern.");
    WAY("German", "reset_link_you", "Du hast den Einladungslink der Gruppe zurückgesetzt");
    WAY("German", "settings_only_admins_edit_you", "Du hast die Einstellungen geändert: Nur Admins können Gruppeneinstellungen bearbeiten");
    WAY("German", "settings_all_edit_you", "Du hast die Einstellungen geändert: Alle Mitglieder können Gruppeneinstellungen bearbeiten");
    WAY("German", "settings_only_admins_send_you", "Du hast die Gruppeneinstellungen geändert: Nur Admins können Nachrichten senden");
    WAY("German", "settings_only_admins_add_you", "Du hast die Gruppeneinstellungen geändert: Nur Admins können andere hinzufügen.");
    WAY("German", "settings_all_add_you", "Du hast die Gruppeneinstellungen geändert: Alle Mitglieder können andere hinzufügen.");
    WAY("German", "settings_all_send_you", "Du hast die Gruppeneinstellungen geändert: Alle Mitglieder können Nachrichten senden");
    WAY("German", "settings_all_invite_link_you", "Du hast die Einstellungen geändert: Alle können per Link einladen.");
    WAY("German", "settings_only_admins_invite_link_you", "Du hast die Einstellungen geändert: Nur Admins können per Link einladen.");
    WAY("German", "disappear_on_you", "Du hast verschwindende Nachrichten aktiviert. Neue Nachrichten verschwinden {timer} nach dem Senden, außer wenn gespeichert. Tippe zum Ändern.");
    WAY("German", "disappear_off_you", "Du hast verschwindende Nachrichten deaktiviert. Tippe zum Ändern.");
    WAY("German", "disappear_off2_you", "Du hast verschwindende Nachrichten deaktiviert. Tippe, um mehr zu erfahren.");
    WAY("German", "update_timer_you", "Du hast den Nachrichten-Timer aktualisiert. Neue Nachrichten verschwinden {timer} nach dem Senden, außer wenn gespeichert. Tippe zum Ändern.");
    WAY("German", "update_timer2_you", "Du hast den Nachrichten-Timer aktualisiert. Neue Nachrichten verschwinden {timer} nach dem Senden. Tippe, um mehr zu erfahren.");

    // ── Chinese — 2nd person (您, formal) ────────────────────────────────────
    WAY("Chinese", "created_group_you", "您创建了群组\"{1}\"");
    WAY("Chinese", "created_group_noname_you", "您创建了此群组");
    WAY("Chinese", "left_you", "您已退出");
    WAY("Chinese", "added_you", "您添加了{1}");
    WAY("Chinese", "added_target_you", "{0}添加了您");
    WAY("Chinese", "was_added_you", "您已被添加");
    WAY("Chinese", "removed_you", "您已移除{1}");
    WAY("Chinese", "removed_target_you", "{0}已移除您");
    WAY("Chinese", "joined_link_you", "您通过群组链接加入。");
    WAY("Chinese", "changed_icon_you", "您更改了群组头像");
    WAY("Chinese", "changed_name_you", "您将群组名称更改为\"{1}\"");
    WAY("Chinese", "changed_name_from_to_you", "您将群组名称从\"{1}\"更改为\"{2}\"");
    WAY("Chinese", "changed_desc_you", "您更改了群组描述");
    WAY("Chinese", "admin_approval_on_you", "您已开启管理员审批以加入此群组。点击更改。");
    WAY("Chinese", "admin_approval_off_you", "您已关闭管理员审批。点击更改。");
    WAY("Chinese", "reset_link_you", "您重置了群组邀请链接");
    WAY("Chinese", "settings_only_admins_edit_you", "您更改了设置，现在只有管理员可以编辑群组设置");
    WAY("Chinese", "settings_all_edit_you", "您更改了设置，现在所有成员均可编辑群组设置");
    WAY("Chinese", "settings_only_admins_send_you", "您更改了群组设置，现在只有管理员可以发送消息");
    WAY("Chinese", "settings_only_admins_add_you", "您更改了群组设置，现在只有管理员可以添加其他人。");
    WAY("Chinese", "settings_all_add_you", "您更改了群组设置，现在所有成员均可添加其他人。");
    WAY("Chinese", "settings_all_send_you", "您更改了群组设置，现在所有成员均可发送消息");
    WAY("Chinese", "settings_all_invite_link_you", "您更改了群组设置，现在所有成员均可通过群组链接邀请他人。");
    WAY("Chinese", "settings_only_admins_invite_link_you", "您更改了设置，现在只有管理员可以通过链接邀请他人。");
    WAY("Chinese", "disappear_on_you", "您已开启阅后即焚消息。新消息发送后{timer}将从此聊天中消失（已保留的除外）。点击更改。");
    WAY("Chinese", "disappear_off_you", "您已关闭阅后即焚消息。点击更改。");
    WAY("Chinese", "disappear_off2_you", "您已关闭阅后即焚消息。点击了解更多。");
    WAY("Chinese", "update_timer_you", "您已更新消息计时器。新消息发送后{timer}将从此聊天中消失（已保留的除外）。点击更改。");
    WAY("Chinese", "update_timer2_you", "您已更新消息计时器。新消息发送后{timer}将从此聊天中消失（已保留的除外）。点击了解更多。");

    // ── Hindi — 2nd person (आप, formal) ──────────────────────────────────────
    WAY("Hindi", "created_group_you", "आपने \"{1}\" समूह बनाया");
    WAY("Hindi", "created_group_noname_you", "आपने यह समूह बनाया");
    WAY("Hindi", "left_you", "आप चले गए");
    WAY("Hindi", "added_you", "आपने {1} को जोड़ा");
    WAY("Hindi", "added_target_you", "{0} ने आपको जोड़ा");
    WAY("Hindi", "was_added_you", "आपको जोड़ा गया");
    WAY("Hindi", "removed_you", "आपने {1} को हटाया");
    WAY("Hindi", "removed_target_you", "{0} ने आपको हटाया");
    WAY("Hindi", "joined_link_you", "आप समूह लिंक के माध्यम से शामिल हुए।");
    WAY("Hindi", "changed_icon_you", "आपने समूह का आइकन बदला");
    WAY("Hindi", "changed_name_you", "आपने समूह का नाम \"{1}\" में बदला");
    WAY("Hindi", "changed_name_from_to_you", "आपने समूह का नाम \"{1}\" से \"{2}\" में बदला");
    WAY("Hindi", "changed_desc_you", "आपने समूह का विवरण बदला");
    WAY("Hindi", "admin_approval_on_you", "आपने इस समूह में शामिल होने के लिए व्यवस्थापक अनुमोदन चालू किया। बदलने के लिए टैप करें।");
    WAY("Hindi", "admin_approval_off_you", "आपने व्यवस्थापक अनुमोदन बंद किया। बदलने के लिए टैप करें।");
    WAY("Hindi", "reset_link_you", "आपने समूह के आमंत्रण लिंक को रीसेट किया");
    WAY("Hindi", "settings_only_admins_edit_you", "आपने सेटिंग्स बदली ताकि केवल व्यवस्थापक समूह सेटिंग्स संपादित कर सकें");
    WAY("Hindi", "settings_all_edit_you", "आपने सेटिंग्स बदली ताकि सभी सदस्य समूह सेटिंग्स संपादित कर सकें");
    WAY("Hindi", "settings_only_admins_send_you", "आपने समूह सेटिंग्स बदली ताकि केवल व्यवस्थापक संदेश भेज सकें");
    WAY("Hindi", "settings_only_admins_add_you", "आपने समूह सेटिंग्स बदली ताकि केवल व्यवस्थापक अन्य लोगों को जोड़ सकें।");
    WAY("Hindi", "settings_all_add_you", "आपने समूह सेटिंग्स बदली ताकि सभी सदस्य अन्य लोगों को जोड़ सकें।");
    WAY("Hindi", "settings_all_send_you", "आपने समूह सेटिंग्स बदली ताकि सभी सदस्य संदेश भेज सकें");
    WAY("Hindi", "settings_all_invite_link_you", "आपने समूह सेटिंग्स बदली ताकि सभी लिंक से आमंत्रित कर सकें।");
    WAY("Hindi", "settings_only_admins_invite_link_you", "आपने सेटिंग्स बदली ताकि केवल व्यवस्थापक लिंक से आमंत्रित कर सकें।");
    WAY("Hindi", "disappear_on_you", "आपने गायब होने वाले संदेश चालू किए। नए संदेश भेजने के {timer} बाद इस चैट से गायब हो जाएंगे (सहेजे गए को छोड़कर)। बदलने के लिए टैप करें।");
    WAY("Hindi", "disappear_off_you", "आपने गायब होने वाले संदेश बंद किए। बदलने के लिए टैप करें।");
    WAY("Hindi", "disappear_off2_you", "आपने गायब होने वाले संदेश बंद किए। और जानने के लिए टैप करें।");
    WAY("Hindi", "update_timer_you", "आपने संदेश टाइमर अपडेट किया। नए संदेश भेजने के {timer} बाद इस चैट से गायब हो जाएंगे (सहेजे गए को छोड़कर)। बदलने के लिए टैप करें।");
    WAY("Hindi", "update_timer2_you", "आपने संदेश टाइमर अपडेट किया। नए संदेश भेजने के {timer} बाद इस चैट से गायब हो जाएंगे (सहेजे गए को छोड़कर)। और जानने के लिए टैप करें।");

    // ── Japanese — 2nd person (あなた) ────────────────────────────────────────
    WAY("Japanese", "created_group_you", "あなたがグループ「{1}」を作成しました");
    WAY("Japanese", "created_group_noname_you", "あなたがこのグループを作成しました");
    WAY("Japanese", "left_you", "あなたが退会しました");
    WAY("Japanese", "added_you", "あなたが{1}を追加しました");
    WAY("Japanese", "added_target_you", "{0}があなたを追加しました");
    WAY("Japanese", "was_added_you", "あなたが追加されました");
    WAY("Japanese", "removed_you", "あなたが{1}を削除しました");
    WAY("Japanese", "removed_target_you", "{0}があなたを削除しました");
    WAY("Japanese", "joined_link_you", "あなたがグループリンクで参加しました。");
    WAY("Japanese", "changed_icon_you", "あなたがグループのアイコンを変更しました");
    WAY("Japanese", "changed_name_you", "あなたがグループ名を「{1}」に変更しました");
    WAY("Japanese", "changed_name_from_to_you", "あなたがグループ名を「{1}」から「{2}」に変更しました");
    WAY("Japanese", "changed_desc_you", "あなたがグループの説明を変更しました");
    WAY("Japanese", "admin_approval_on_you", "あなたがグループ参加時の管理者承認をオンにしました。タップして変更。");
    WAY("Japanese", "admin_approval_off_you", "あなたがグループ参加時の管理者承認をオフにしました。タップして変更。");
    WAY("Japanese", "reset_link_you", "あなたがグループの招待リンクをリセットしました");
    WAY("Japanese", "settings_only_admins_edit_you", "あなたが設定を変更し、管理者のみがグループ設定を編集できるようにしました");
    WAY("Japanese", "settings_all_edit_you", "あなたが設定を変更し、すべてのメンバーがグループ設定を編集できるようにしました");
    WAY("Japanese", "settings_only_admins_send_you", "あなたがグループ設定を変更し、管理者のみがメッセージを送信できるようにしました");
    WAY("Japanese", "settings_only_admins_add_you", "あなたがグループ設定を変更し、管理者のみが他の人を追加できるようにしました。");
    WAY("Japanese", "settings_all_add_you", "あなたがグループ設定を変更し、すべてのメンバーが他の人を追加できるようにしました。");
    WAY("Japanese", "settings_all_send_you", "あなたがグループ設定を変更し、すべてのメンバーがメッセージを送信できるようにしました");
    WAY("Japanese", "settings_all_invite_link_you", "あなたがグループ設定を変更し、すべてのメンバーがリンクで招待できるようにしました。");
    WAY("Japanese", "settings_only_admins_invite_link_you", "あなたがグループ設定を変更し、管理者のみがリンクで招待できるようにしました。");
    WAY("Japanese", "disappear_on_you", "あなたが消えるメッセージをオンにしました。新しいメッセージは送信後{timer}でこのチャットから消えます（保存したものを除く）。タップして変更。");
    WAY("Japanese", "disappear_off_you", "あなたが消えるメッセージをオフにしました。タップして変更。");
    WAY("Japanese", "disappear_off2_you", "あなたが消えるメッセージをオフにしました。詳細はタップ。");
    WAY("Japanese", "update_timer_you", "あなたがメッセージタイマーを更新しました。新しいメッセージは送信後{timer}でこのチャットから消えます（保存したものを除く）。タップして変更。");
    WAY("Japanese", "update_timer2_you", "あなたがメッセージタイマーを更新しました。新しいメッセージは送信後{timer}でこのチャットから消えます（保存したものを除く）。詳細はタップ。");

    // ── Korean — 2nd person (당신) ───────────────────────────────────────────
    WAY("Korean", "created_group_you", "당신이 \"{1}\" 그룹을 만들었습니다");
    WAY("Korean", "created_group_noname_you", "당신이 이 그룹을 만들었습니다");
    WAY("Korean", "left_you", "당신이 떠났습니다");
    WAY("Korean", "added_you", "당신이 {1}님을 추가했습니다");
    WAY("Korean", "added_target_you", "{0}님이 당신을 추가했습니다");
    WAY("Korean", "was_added_you", "당신이 추가되었습니다");
    WAY("Korean", "removed_you", "당신이 {1}님을 제거했습니다");
    WAY("Korean", "removed_target_you", "{0}님이 당신을 제거했습니다");
    WAY("Korean", "joined_link_you", "당신이 그룹 링크로 참여했습니다.");
    WAY("Korean", "changed_icon_you", "당신이 그룹 아이콘을 변경했습니다");
    WAY("Korean", "changed_name_you", "당신이 그룹 이름을 \"{1}\"(으)로 변경했습니다");
    WAY("Korean", "changed_name_from_to_you", "당신이 그룹 이름을 \"{1}\"에서 \"{2}\"(으)로 변경했습니다");
    WAY("Korean", "changed_desc_you", "당신이 그룹 설명을 변경했습니다");
    WAY("Korean", "admin_approval_on_you", "당신이 이 그룹 참여를 위한 관리자 승인을 켰습니다. 변경하려면 탭하세요.");
    WAY("Korean", "admin_approval_off_you", "당신이 관리자 승인을 껐습니다. 변경하려면 탭하세요.");
    WAY("Korean", "reset_link_you", "당신이 그룹 초대 링크를 재설정했습니다");
    WAY("Korean", "settings_only_admins_edit_you", "당신이 관리자만 그룹 설정을 편집할 수 있도록 설정을 변경했습니다");
    WAY("Korean", "settings_all_edit_you", "당신이 모든 멤버가 그룹 설정을 편집할 수 있도록 설정을 변경했습니다");
    WAY("Korean", "settings_only_admins_send_you", "당신이 관리자만 메시지를 보낼 수 있도록 그룹 설정을 변경했습니다");
    WAY("Korean", "settings_only_admins_add_you", "당신이 관리자만 다른 사람을 추가할 수 있도록 그룹 설정을 변경했습니다.");
    WAY("Korean", "settings_all_add_you", "당신이 모든 멤버가 다른 사람을 추가할 수 있도록 그룹 설정을 변경했습니다.");
    WAY("Korean", "settings_all_send_you", "당신이 모든 멤버가 메시지를 보낼 수 있도록 그룹 설정을 변경했습니다");
    WAY("Korean", "settings_all_invite_link_you", "당신이 모든 멤버가 그룹 링크로 초대할 수 있도록 그룹 설정을 변경했습니다.");
    WAY("Korean", "settings_only_admins_invite_link_you", "당신이 관리자만 그룹 링크로 초대할 수 있도록 설정을 변경했습니다.");
    WAY("Korean", "disappear_on_you", "당신이 사라지는 메시지를 켰습니다. 새 메시지는 전송 후 {timer} 후에 이 채팅에서 사라집니다(보관된 것 제외). 변경하려면 탭하세요.");
    WAY("Korean", "disappear_off_you", "당신이 사라지는 메시지를 껐습니다. 변경하려면 탭하세요.");
    WAY("Korean", "disappear_off2_you", "당신이 사라지는 메시지를 껐습니다. 자세한 내용은 탭하세요.");
    WAY("Korean", "update_timer_you", "당신이 메시지 타이머를 업데이트했습니다. 새 메시지는 전송 후 {timer} 후에 이 채팅에서 사라집니다(보관된 것 제외). 변경하려면 탭하세요.");
    WAY("Korean", "update_timer2_you", "당신이 메시지 타이머를 업데이트했습니다. 새 메시지는 전송 후 {timer} 후에 이 채팅에서 사라집니다(보관된 것 제외). 자세한 내용은 탭하세요.");

    // ── Mongolian — 2nd person (Та, formal) ──────────────────────────────────
    WAY("Mongolian", "created_group_you", "Та \"{1}\" группыг үүсгэлээ");
    WAY("Mongolian", "created_group_noname_you", "Та энэ группыг үүсгэлээ");
    WAY("Mongolian", "left_you", "Та гарлаа");
    WAY("Mongolian", "added_you", "Та {1}-г нэмлээ");
    WAY("Mongolian", "added_target_you", "{0} таныг нэмэв");
    WAY("Mongolian", "was_added_you", "Та нэмэгдлээ");
    WAY("Mongolian", "removed_you", "Та {1}-г хаслаа");
    WAY("Mongolian", "removed_target_you", "{0} таныг хаслаа");
    WAY("Mongolian", "joined_link_you", "Та группын линкээр элслээ.");
    WAY("Mongolian", "changed_icon_you", "Та группын зургийг солилоо");
    WAY("Mongolian", "changed_name_you", "Та группын нэрийг \"{1}\" болгож солилоо");
    WAY("Mongolian", "changed_name_from_to_you", "Та группын нэрийг \"{1}\"-аас \"{2}\" болгож солилоо");
    WAY("Mongolian", "changed_desc_you", "Та группын тайлбарыг солилоо");
    WAY("Mongolian", "admin_approval_on_you", "Та группд элсэхэд админы зөвшөөрөл шаардахыг идэвхжүүлэв. Өөрчлөхийн тулд дарна уу.");
    WAY("Mongolian", "admin_approval_off_you", "Та админы зөвшөөрлийг идэвхгүй болгов. Өөрчлөхийн тулд дарна уу.");
    WAY("Mongolian", "reset_link_you", "Та группын урилгын линкийг шинэчилэв");
    WAY("Mongolian", "settings_only_admins_edit_you", "Та зөвхөн админууд группын тохиргоог засах боломжтой болгож тохиргоог солилоо");
    WAY("Mongolian", "settings_all_edit_you", "Та бүх гишүүд группын тохиргоог засах боломжтой болгож тохиргоог солилоо");
    WAY("Mongolian", "settings_only_admins_send_you", "Та зөвхөн админууд мессеж илгээх боломжтой болгож группын тохиргоог солилоо");
    WAY("Mongolian", "settings_only_admins_add_you", "Та зөвхөн админууд бусдыг нэмэх боломжтой болгож группын тохиргоог солилоо.");
    WAY("Mongolian", "settings_all_add_you", "Та бүх гишүүд бусдыг нэмэх боломжтой болгож группын тохиргоог солилоо.");
    WAY("Mongolian", "settings_all_send_you", "Та бүх гишүүд мессеж илгээх боломжтой болгож группын тохиргоог солилоо");
    WAY("Mongolian", "settings_all_invite_link_you", "Та бүх гишүүд линкээр урих боломжтой болгож группын тохиргоог солилоо.");
    WAY("Mongolian", "settings_only_admins_invite_link_you", "Та зөвхөн админууд линкээр урих боломжтой болгож тохиргоог солилоо.");
    WAY("Mongolian", "disappear_on_you", "Та алга болдог мессежийг идэвхжүүлэв. Шинэ мессежүүд илгээснээс хойш {timer}-ын дараа энэ чатнаас алга болно (хадгалагдсаныг эс тооцвол). Өөрчлөхийн тулд дарна уу.");
    WAY("Mongolian", "disappear_off_you", "Та алга болдог мессежийг идэвхгүй болгов. Өөрчлөхийн тулд дарна уу.");
    WAY("Mongolian", "disappear_off2_you", "Та алга болдог мессежийг идэвхгүй болгов. Дэлгэрэнгүйг харахын тулд дарна уу.");
    WAY("Mongolian", "update_timer_you", "Та мессежийн таймерыг шинэчлэв. Шинэ мессежүүд илгээснээс хойш {timer}-ын дараа алга болно (хадгалагдсаныг эс тооцвол). Өөрчлөхийн тулд дарна уу.");
    WAY("Mongolian", "update_timer2_you", "Та мессежийн таймерыг шинэчлэв. Шинэ мессежүүд илгээснээс хойш {timer}-ын дараа алга болно (хадгалагдсаныг эс тооцвол). Дэлгэрэнгүйг харахын тулд дарна уу.");

    // ── Polish — 2nd person (Ty, informal) ───────────────────────────────────
    WAY("Polish", "created_group_you", "Utworzyłeś(-aś) grupę \"{1}\"");
    WAY("Polish", "created_group_noname_you", "Utworzyłeś(-aś) tę grupę");
    WAY("Polish", "left_you", "Opuściłeś(-aś) grupę");
    WAY("Polish", "added_you", "Dodałeś(-aś) {1}");
    WAY("Polish", "added_target_you", "{0} dodał(a) Cię");
    WAY("Polish", "was_added_you", "Zostałeś(-aś) dodany(-a)");
    WAY("Polish", "removed_you", "Usunąłeś(-ęłaś) {1}");
    WAY("Polish", "removed_target_you", "{0} usunął(usunęła) Cię");
    WAY("Polish", "joined_link_you", "Dołączyłeś(-aś) za pomocą linku grupy.");
    WAY("Polish", "changed_icon_you", "Zmieniłeś(-aś) ikonę grupy");
    WAY("Polish", "changed_name_you", "Zmieniłeś(-aś) nazwę grupy na \"{1}\"");
    WAY("Polish", "changed_name_from_to_you", "Zmieniłeś(-aś) nazwę grupy z \"{1}\" na \"{2}\"");
    WAY("Polish", "changed_desc_you", "Zmieniłeś(-aś) opis grupy");
    WAY("Polish", "admin_approval_on_you", "Włączyłeś(-aś) zatwierdzanie przez administratora. Stuknij, aby zmienić.");
    WAY("Polish", "admin_approval_off_you", "Wyłączyłeś(-aś) zatwierdzanie przez administratora. Stuknij, aby zmienić.");
    WAY("Polish", "reset_link_you", "Zresetowałeś(-aś) link zaproszenia do grupy");
    WAY("Polish", "settings_only_admins_edit_you", "Zmieniłeś(-aś) ustawienia: tylko administratorzy mogą edytować ustawienia grupy");
    WAY("Polish", "settings_all_edit_you", "Zmieniłeś(-aś) ustawienia: wszyscy członkowie mogą edytować ustawienia grupy");
    WAY("Polish", "settings_only_admins_send_you", "Zmieniłeś(-aś) ustawienia grupy: tylko administratorzy mogą wysyłać wiadomości");
    WAY("Polish", "settings_only_admins_add_you", "Zmieniłeś(-aś) ustawienia grupy: tylko administratorzy mogą dodawać innych.");
    WAY("Polish", "settings_all_add_you", "Zmieniłeś(-aś) ustawienia grupy: wszyscy członkowie mogą dodawać innych.");
    WAY("Polish", "settings_all_send_you", "Zmieniłeś(-aś) ustawienia grupy: wszyscy członkowie mogą wysyłać wiadomości");
    WAY("Polish", "settings_all_invite_link_you", "Zmieniłeś(-aś) ustawienia: wszyscy mogą zapraszać linkiem.");
    WAY("Polish", "settings_only_admins_invite_link_you", "Zmieniłeś(-aś) ustawienia: tylko administratorzy mogą zapraszać linkiem.");
    WAY("Polish", "disappear_on_you", "Włączyłeś(-aś) znikające wiadomości. Nowe wiadomości znikną z czatu po {timer} od wysłania, oprócz zapisanych. Stuknij, aby zmienić.");
    WAY("Polish", "disappear_off_you", "Wyłączyłeś(-aś) znikające wiadomości. Stuknij, aby zmienić.");
    WAY("Polish", "disappear_off2_you", "Wyłączyłeś(-aś) znikające wiadomości. Stuknij, aby dowiedzieć się więcej.");
    WAY("Polish", "update_timer_you", "Zaktualizowałeś(-aś) licznik wiadomości. Nowe wiadomości znikną z czatu po {timer} od wysłania, oprócz zapisanych. Stuknij, aby zmienić.");
    WAY("Polish", "update_timer2_you", "Zaktualizowałeś(-aś) licznik wiadomości. Nowe wiadomości znikną z czatu po {timer} od wysłania, oprócz zapisanych. Stuknij, aby dowiedzieć się więcej.");

    // ── Ukrainian — 2nd person (Ви, formal) ──────────────────────────────────
    WAY("Ukrainian", "created_group_you", "Ви створили групу \"{1}\"");
    WAY("Ukrainian", "created_group_noname_you", "Ви створили цю групу");
    WAY("Ukrainian", "left_you", "Ви вийшли");
    WAY("Ukrainian", "added_you", "Ви додали {1}");
    WAY("Ukrainian", "added_target_you", "{0} додав(ла) вас");
    WAY("Ukrainian", "was_added_you", "Вас додано");
    WAY("Ukrainian", "removed_you", "Ви видалили {1}");
    WAY("Ukrainian", "removed_target_you", "{0} видалив(ла) вас");
    WAY("Ukrainian", "joined_link_you", "Ви приєдналися за посиланням групи.");
    WAY("Ukrainian", "changed_icon_you", "Ви змінили значок групи");
    WAY("Ukrainian", "changed_name_you", "Ви змінили назву групи на \"{1}\"");
    WAY("Ukrainian", "changed_name_from_to_you", "Ви змінили назву групи з \"{1}\" на \"{2}\"");
    WAY("Ukrainian", "changed_desc_you", "Ви змінили опис групи");
    WAY("Ukrainian", "admin_approval_on_you", "Ви увімкнули підтвердження адміністратора для приєднання до групи. Торкніться, щоб змінити.");
    WAY("Ukrainian", "admin_approval_off_you", "Ви вимкнули підтвердження адміністратора. Торкніться, щоб змінити.");
    WAY("Ukrainian", "reset_link_you", "Ви скинули посилання-запрошення групи");
    WAY("Ukrainian", "settings_only_admins_edit_you", "Ви змінили налаштування: лише адміністратори можуть редагувати налаштування групи");
    WAY("Ukrainian", "settings_all_edit_you", "Ви змінили налаштування: всі учасники можуть редагувати налаштування групи");
    WAY("Ukrainian", "settings_only_admins_send_you", "Ви змінили налаштування групи: лише адміністратори можуть надсилати повідомлення");
    WAY("Ukrainian", "settings_only_admins_add_you", "Ви змінили налаштування групи: лише адміністратори можуть додавати інших.");
    WAY("Ukrainian", "settings_all_add_you", "Ви змінили налаштування групи: всі учасники можуть додавати інших.");
    WAY("Ukrainian", "settings_all_send_you", "Ви змінили налаштування групи: всі учасники можуть надсилати повідомлення");
    WAY("Ukrainian", "settings_all_invite_link_you", "Ви змінили налаштування: всі можуть запрошувати за посиланням.");
    WAY("Ukrainian", "settings_only_admins_invite_link_you", "Ви змінили налаштування: лише адміністратори можуть запрошувати за посиланням.");
    WAY("Ukrainian", "disappear_on_you", "Ви увімкнули зникаючі повідомлення. Нові повідомлення зникатимуть з чату через {timer} після надсилання (крім збережених). Торкніться, щоб змінити.");
    WAY("Ukrainian", "disappear_off_you", "Ви вимкнули зникаючі повідомлення. Торкніться, щоб змінити.");
    WAY("Ukrainian", "disappear_off2_you", "Ви вимкнули зникаючі повідомлення. Торкніться, щоб дізнатися більше.");
    WAY("Ukrainian", "update_timer_you", "Ви оновили таймер повідомлень. Нові повідомлення зникатимуть з чату через {timer} після надсилання (крім збережених). Торкніться, щоб змінити.");
    WAY("Ukrainian", "update_timer2_you", "Ви оновили таймер повідомлень. Нові повідомлення зникатимуть з чату через {timer} після надсилання (крім збережених). Торкніться, щоб дізнатися більше.");

    // ── Uzbek — 2nd person (Siz, formal) ─────────────────────────────────────
    WAY("Uzbek", "created_group_you", "Siz \"{1}\" guruhini yaratdingiz");
    WAY("Uzbek", "created_group_noname_you", "Siz bu guruhni yaratdingiz");
    WAY("Uzbek", "left_you", "Siz chiqdingiz");
    WAY("Uzbek", "added_you", "Siz {1}ni qo'shdingiz");
    WAY("Uzbek", "added_target_you", "{0} sizni qo'shdi");
    WAY("Uzbek", "was_added_you", "Siz qo'shildingiz");
    WAY("Uzbek", "removed_you", "Siz {1}ni chiqardingiz");
    WAY("Uzbek", "removed_target_you", "{0} sizni chiqardi");
    WAY("Uzbek", "joined_link_you", "Siz guruh havolasi orqali qo'shildingiz.");
    WAY("Uzbek", "changed_icon_you", "Siz guruh belgisini o'zgartirdingiz");
    WAY("Uzbek", "changed_name_you", "Siz guruh nomini \"{1}\" ga o'zgartirdingiz");
    WAY("Uzbek", "changed_name_from_to_you", "Siz guruh nomini \"{1}\" dan \"{2}\" ga o'zgartirdingiz");
    WAY("Uzbek", "changed_desc_you", "Siz guruh tavsifini o'zgartirdingiz");
    WAY("Uzbek", "admin_approval_on_you", "Siz guruhga qo'shilish uchun admin tasdig'ini yoqdingiz. O'zgartirish uchun bosing.");
    WAY("Uzbek", "admin_approval_off_you", "Siz admin tasdig'ini o'chirdingiz. O'zgartirish uchun bosing.");
    WAY("Uzbek", "reset_link_you", "Siz guruhning taklif havolasini qayta tikladingiz");
    WAY("Uzbek", "settings_only_admins_edit_you", "Siz sozlamalarni o'zgartirdingiz: faqat adminlar guruh sozlamalarini tahrirlay oladi");
    WAY("Uzbek", "settings_all_edit_you", "Siz sozlamalarni o'zgartirdingiz: barcha a'zolar guruh sozlamalarini tahrirlay oladi");
    WAY("Uzbek", "settings_only_admins_send_you", "Siz guruh sozlamalarini o'zgartirdingiz: faqat adminlar xabar yuborishi mumkin");
    WAY("Uzbek", "settings_only_admins_add_you", "Siz guruh sozlamalarini o'zgartirdingiz: faqat adminlar boshqalarni qo'sha oladi.");
    WAY("Uzbek", "settings_all_add_you", "Siz guruh sozlamalarini o'zgartirdingiz: barcha a'zolar boshqalarni qo'sha oladi.");
    WAY("Uzbek", "settings_all_send_you", "Siz guruh sozlamalarini o'zgartirdingiz: barcha a'zolar xabar yuborishi mumkin");
    WAY("Uzbek", "settings_all_invite_link_you", "Siz guruh sozlamalarini o'zgartirdingiz: barchasi havola orqali taklif qila oladi.");
    WAY("Uzbek", "settings_only_admins_invite_link_you", "Siz sozlamalarni o'zgartirdingiz: faqat adminlar havola orqali taklif qila oladi.");
    WAY("Uzbek", "disappear_on_you", "Siz yo'qolib boruvchi xabarlarni yoqdingiz. Yangi xabarlar yuborilgandan {timer} keyin bu chatdan yo'qoladi (saqlanganlardan tashqari). O'zgartirish uchun bosing.");
    WAY("Uzbek", "disappear_off_you", "Siz yo'qolib boruvchi xabarlarni o'chirdingiz. O'zgartirish uchun bosing.");
    WAY("Uzbek", "disappear_off2_you", "Siz yo'qolib boruvchi xabarlarni o'chirdingiz. Batafsil ma'lumot uchun bosing.");
    WAY("Uzbek", "update_timer_you", "Siz xabarlar taymerini yangiladingiz. Yangi xabarlar yuborilgandan {timer} keyin bu chatdan yo'qoladi (saqlanganlardan tashqari). O'zgartirish uchun bosing.");
    WAY("Uzbek", "update_timer2_you", "Siz xabarlar taymerini yangiladingiz. Yangi xabarlar yuborilgandan {timer} keyin bu chatdan yo'qoladi (saqlanganlardan tashqari). Batafsil ma'lumot uchun bosing.");

    // ─────────────────────────────────────────────────────────────────────────
    // Voice / video call: 2nd-person variants  +  duration unit translations
    //
    // Templates use {1} for the duration string ("41 sec") and {0} for the
    // joiner; in the _you variants {0} is omitted because the localised
    // pronoun is baked in. Unit substitution happens *after* placeholder
    // expansion in translateSystemMessage() — it rewrites "41 sec" into the
    // localised abbreviation by replacing the trailing English unit word.
    // ─────────────────────────────────────────────────────────────────────────

    // Azerbaijani
    WAY("Azerbaijani", "voice_call_you", "Səsli zəng. {1} • Sən qoşuldun");
    WAY("Azerbaijani", "video_call_you", "Video zəng. {1} • Sən qoşuldun");
    WAY("Azerbaijani", "unit_sec", "san");
    WAY("Azerbaijani", "unit_min", "dəq");
    WAY("Azerbaijani", "unit_hr",  "saat");

    // English
    WAY("English", "voice_call_you", "Voice call. {1} • You joined");
    WAY("English", "video_call_you", "Video call. {1} • You joined");
    WAY("English", "unit_sec", "sec");
    WAY("English", "unit_min", "min");
    WAY("English", "unit_hr",  "hr");

    // Turkish
    WAY("Turkish", "voice_call_you", "Sesli arama. {1} • Sen katıldın");
    WAY("Turkish", "video_call_you", "Görüntülü arama. {1} • Sen katıldın");
    WAY("Turkish", "unit_sec", "sn");
    WAY("Turkish", "unit_min", "dk");
    WAY("Turkish", "unit_hr",  "sa");

    // Russian
    WAY("Russian", "voice_call_you", "Голосовой вызов. {1} • Вы присоединились");
    WAY("Russian", "video_call_you", "Видеовызов. {1} • Вы присоединились");
    WAY("Russian", "unit_sec", "сек");
    WAY("Russian", "unit_min", "мин");
    WAY("Russian", "unit_hr",  "ч");

    // Arabic
    WAY("Arabic", "voice_call_you", "مكالمة صوتية. {1} • انضممت");
    WAY("Arabic", "video_call_you", "مكالمة مرئية. {1} • انضممت");
    WAY("Arabic", "unit_sec", "ث");
    WAY("Arabic", "unit_min", "د");
    WAY("Arabic", "unit_hr",  "س");

    // Spanish
    WAY("Spanish", "voice_call_you", "Llamada de voz. {1} • Te uniste");
    WAY("Spanish", "video_call_you", "Videollamada. {1} • Te uniste");
    WAY("Spanish", "unit_sec", "s");
    WAY("Spanish", "unit_min", "min");
    WAY("Spanish", "unit_hr",  "h");

    // Portuguese
    WAY("Portuguese", "voice_call_you", "Chamada de voz. {1} • Você entrou");
    WAY("Portuguese", "video_call_you", "Videochamada. {1} • Você entrou");
    WAY("Portuguese", "unit_sec", "s");
    WAY("Portuguese", "unit_min", "min");
    WAY("Portuguese", "unit_hr",  "h");

    // Italian
    WAY("Italian", "voice_call_you", "Chiamata vocale. {1} • Ti sei unito/a");
    WAY("Italian", "video_call_you", "Videochiamata. {1} • Ti sei unito/a");
    WAY("Italian", "unit_sec", "s");
    WAY("Italian", "unit_min", "min");
    WAY("Italian", "unit_hr",  "h");

    // French
    WAY("French", "voice_call_you", "Appel vocal. {1} • Vous avez rejoint");
    WAY("French", "video_call_you", "Appel vidéo. {1} • Vous avez rejoint");
    WAY("French", "unit_sec", "s");
    WAY("French", "unit_min", "min");
    WAY("French", "unit_hr",  "h");

    // German
    WAY("German", "voice_call_you", "Sprachanruf. {1} • Du bist beigetreten");
    WAY("German", "video_call_you", "Videoanruf. {1} • Du bist beigetreten");
    WAY("German", "unit_sec", "Sek.");
    WAY("German", "unit_min", "Min.");
    WAY("German", "unit_hr",  "Std.");

    // Chinese
    WAY("Chinese", "voice_call_you", "语音通话。{1} • 您已加入");
    WAY("Chinese", "video_call_you", "视频通话。{1} • 您已加入");
    WAY("Chinese", "unit_sec", "秒");
    WAY("Chinese", "unit_min", "分钟");
    WAY("Chinese", "unit_hr",  "小时");

    // Hindi
    WAY("Hindi", "voice_call_you", "वॉइस कॉल। {1} • आप शामिल हुए");
    WAY("Hindi", "video_call_you", "वीडियो कॉल। {1} • आप शामिल हुए");
    WAY("Hindi", "unit_sec", "सेक");
    WAY("Hindi", "unit_min", "मिन");
    WAY("Hindi", "unit_hr",  "घं");

    // Japanese
    WAY("Japanese", "voice_call_you", "音声通話。{1} • あなたが参加しました");
    WAY("Japanese", "video_call_you", "ビデオ通話。{1} • あなたが参加しました");
    WAY("Japanese", "unit_sec", "秒");
    WAY("Japanese", "unit_min", "分");
    WAY("Japanese", "unit_hr",  "時間");

    // Korean
    WAY("Korean", "voice_call_you", "음성 통화. {1} • 당신이 참여했습니다");
    WAY("Korean", "video_call_you", "영상 통화. {1} • 당신이 참여했습니다");
    WAY("Korean", "unit_sec", "초");
    WAY("Korean", "unit_min", "분");
    WAY("Korean", "unit_hr",  "시간");

    // Mongolian
    WAY("Mongolian", "voice_call_you", "Дуут дуудлага. {1} • Та нэгдлээ");
    WAY("Mongolian", "video_call_you", "Видео дуудлага. {1} • Та нэгдлээ");
    WAY("Mongolian", "unit_sec", "сек");
    WAY("Mongolian", "unit_min", "мин");
    WAY("Mongolian", "unit_hr",  "цаг");

    // Polish
    WAY("Polish", "voice_call_you", "Połączenie głosowe. {1} • Dołączyłeś(-aś)");
    WAY("Polish", "video_call_you", "Połączenie wideo. {1} • Dołączyłeś(-aś)");
    WAY("Polish", "unit_sec", "sek");
    WAY("Polish", "unit_min", "min");
    WAY("Polish", "unit_hr",  "godz");

    // Ukrainian
    WAY("Ukrainian", "voice_call_you", "Голосовий виклик. {1} • Ви приєдналися");
    WAY("Ukrainian", "video_call_you", "Відеовиклик. {1} • Ви приєдналися");
    WAY("Ukrainian", "unit_sec", "сек");
    WAY("Ukrainian", "unit_min", "хв");
    WAY("Ukrainian", "unit_hr",  "год");

    // Uzbek
    WAY("Uzbek", "voice_call_you", "Ovozli qo'ng'iroq. {1} • Siz qo'shildingiz");
    WAY("Uzbek", "video_call_you", "Video qo'ng'iroq. {1} • Siz qo'shildingiz");
    WAY("Uzbek", "unit_sec", "son");
    WAY("Uzbek", "unit_min", "daq");
    WAY("Uzbek", "unit_hr",  "soat");

    // ─────────────────────────────────────────────────────────────────────────
    // 1:1 voice / video call status messages
    //
    //   *_duration   →  "<Localised call>. {0}"   ({0} is "41 sec" etc., the
    //                   unit is then localised by translateSystemMessage)
    //   *_ended      →  "<Localised call>. <Localised "Ended">"
    //   *_missed     →  "<Localised "Missed call">. <Localised "Tap to call back">"
    //   *_no_answer  →  "<Localised call>. <Localised "No answer">"
    // ─────────────────────────────────────────────────────────────────────────

    // Azerbaijani
    WAY("Azerbaijani", "voice_call_duration",  "Səsli zəng. {0}");
    WAY("Azerbaijani", "video_call_duration",  "Video zəng. {0}");
    WAY("Azerbaijani", "voice_call_ended",     "Səsli zəng. Bitdi");
    WAY("Azerbaijani", "video_call_ended",     "Video zəng. Bitdi");
    WAY("Azerbaijani", "voice_call_missed",    "Buraxılmış səsli zəng. Geri zəng etmək üçün toxunun");
    WAY("Azerbaijani", "video_call_missed",    "Buraxılmış video zəng. Geri zəng etmək üçün toxunun");
    WAY("Azerbaijani", "voice_call_no_answer", "Səsli zəng. Cavab yoxdur");
    WAY("Azerbaijani", "video_call_no_answer", "Video zəng. Cavab yoxdur");

    // English
    WAY("English", "voice_call_duration",  "Voice call. {0}");
    WAY("English", "video_call_duration",  "Video call. {0}");
    WAY("English", "voice_call_ended",     "Voice call. Ended");
    WAY("English", "video_call_ended",     "Video call. Ended");
    WAY("English", "voice_call_missed",    "Missed voice call. Tap to call back");
    WAY("English", "video_call_missed",    "Missed video call. Tap to call back");
    WAY("English", "voice_call_no_answer", "Voice call. No answer");
    WAY("English", "video_call_no_answer", "Video call. No answer");

    // Turkish
    WAY("Turkish", "voice_call_duration",  "Sesli arama. {0}");
    WAY("Turkish", "video_call_duration",  "Görüntülü arama. {0}");
    WAY("Turkish", "voice_call_ended",     "Sesli arama. Sona erdi");
    WAY("Turkish", "video_call_ended",     "Görüntülü arama. Sona erdi");
    WAY("Turkish", "voice_call_missed",    "Cevapsız sesli arama. Geri aramak için dokunun");
    WAY("Turkish", "video_call_missed",    "Cevapsız görüntülü arama. Geri aramak için dokunun");
    WAY("Turkish", "voice_call_no_answer", "Sesli arama. Cevap yok");
    WAY("Turkish", "video_call_no_answer", "Görüntülü arama. Cevap yok");

    // Russian
    WAY("Russian", "voice_call_duration",  "Голосовой вызов. {0}");
    WAY("Russian", "video_call_duration",  "Видеовызов. {0}");
    WAY("Russian", "voice_call_ended",     "Голосовой вызов. Завершён");
    WAY("Russian", "video_call_ended",     "Видеовызов. Завершён");
    WAY("Russian", "voice_call_missed",    "Пропущенный голосовой вызов. Нажмите, чтобы перезвонить");
    WAY("Russian", "video_call_missed",    "Пропущенный видеовызов. Нажмите, чтобы перезвонить");
    WAY("Russian", "voice_call_no_answer", "Голосовой вызов. Нет ответа");
    WAY("Russian", "video_call_no_answer", "Видеовызов. Нет ответа");

    // Arabic
    WAY("Arabic", "voice_call_duration",  "مكالمة صوتية. {0}");
    WAY("Arabic", "video_call_duration",  "مكالمة مرئية. {0}");
    WAY("Arabic", "voice_call_ended",     "مكالمة صوتية. انتهت");
    WAY("Arabic", "video_call_ended",     "مكالمة مرئية. انتهت");
    WAY("Arabic", "voice_call_missed",    "مكالمة صوتية فائتة. اضغط لمعاودة الاتصال");
    WAY("Arabic", "video_call_missed",    "مكالمة مرئية فائتة. اضغط لمعاودة الاتصال");
    WAY("Arabic", "voice_call_no_answer", "مكالمة صوتية. لا يوجد رد");
    WAY("Arabic", "video_call_no_answer", "مكالمة مرئية. لا يوجد رد");

    // Spanish
    WAY("Spanish", "voice_call_duration",  "Llamada de voz. {0}");
    WAY("Spanish", "video_call_duration",  "Videollamada. {0}");
    WAY("Spanish", "voice_call_ended",     "Llamada de voz. Finalizada");
    WAY("Spanish", "video_call_ended",     "Videollamada. Finalizada");
    WAY("Spanish", "voice_call_missed",    "Llamada de voz perdida. Toca para devolver la llamada");
    WAY("Spanish", "video_call_missed",    "Videollamada perdida. Toca para devolver la llamada");
    WAY("Spanish", "voice_call_no_answer", "Llamada de voz. Sin respuesta");
    WAY("Spanish", "video_call_no_answer", "Videollamada. Sin respuesta");

    // Portuguese
    WAY("Portuguese", "voice_call_duration",  "Chamada de voz. {0}");
    WAY("Portuguese", "video_call_duration",  "Videochamada. {0}");
    WAY("Portuguese", "voice_call_ended",     "Chamada de voz. Encerrada");
    WAY("Portuguese", "video_call_ended",     "Videochamada. Encerrada");
    WAY("Portuguese", "voice_call_missed",    "Chamada de voz perdida. Toque para retornar");
    WAY("Portuguese", "video_call_missed",    "Videochamada perdida. Toque para retornar");
    WAY("Portuguese", "voice_call_no_answer", "Chamada de voz. Sem resposta");
    WAY("Portuguese", "video_call_no_answer", "Videochamada. Sem resposta");

    // Italian
    WAY("Italian", "voice_call_duration",  "Chiamata vocale. {0}");
    WAY("Italian", "video_call_duration",  "Videochiamata. {0}");
    WAY("Italian", "voice_call_ended",     "Chiamata vocale. Terminata");
    WAY("Italian", "video_call_ended",     "Videochiamata. Terminata");
    WAY("Italian", "voice_call_missed",    "Chiamata vocale persa. Tocca per richiamare");
    WAY("Italian", "video_call_missed",    "Videochiamata persa. Tocca per richiamare");
    WAY("Italian", "voice_call_no_answer", "Chiamata vocale. Nessuna risposta");
    WAY("Italian", "video_call_no_answer", "Videochiamata. Nessuna risposta");

    // French
    WAY("French", "voice_call_duration",  "Appel vocal. {0}");
    WAY("French", "video_call_duration",  "Appel vidéo. {0}");
    WAY("French", "voice_call_ended",     "Appel vocal. Terminé");
    WAY("French", "video_call_ended",     "Appel vidéo. Terminé");
    WAY("French", "voice_call_missed",    "Appel vocal manqué. Appuyez pour rappeler");
    WAY("French", "video_call_missed",    "Appel vidéo manqué. Appuyez pour rappeler");
    WAY("French", "voice_call_no_answer", "Appel vocal. Pas de réponse");
    WAY("French", "video_call_no_answer", "Appel vidéo. Pas de réponse");

    // German
    WAY("German", "voice_call_duration",  "Sprachanruf. {0}");
    WAY("German", "video_call_duration",  "Videoanruf. {0}");
    WAY("German", "voice_call_ended",     "Sprachanruf. Beendet");
    WAY("German", "video_call_ended",     "Videoanruf. Beendet");
    WAY("German", "voice_call_missed",    "Verpasster Sprachanruf. Tippe für Rückruf");
    WAY("German", "video_call_missed",    "Verpasster Videoanruf. Tippe für Rückruf");
    WAY("German", "voice_call_no_answer", "Sprachanruf. Keine Antwort");
    WAY("German", "video_call_no_answer", "Videoanruf. Keine Antwort");

    // Chinese
    WAY("Chinese", "voice_call_duration",  "语音通话。{0}");
    WAY("Chinese", "video_call_duration",  "视频通话。{0}");
    WAY("Chinese", "voice_call_ended",     "语音通话。已结束");
    WAY("Chinese", "video_call_ended",     "视频通话。已结束");
    WAY("Chinese", "voice_call_missed",    "未接语音来电。点击回拨");
    WAY("Chinese", "video_call_missed",    "未接视频来电。点击回拨");
    WAY("Chinese", "voice_call_no_answer", "语音通话。无人接听");
    WAY("Chinese", "video_call_no_answer", "视频通话。无人接听");

    // Hindi
    WAY("Hindi", "voice_call_duration",  "वॉइस कॉल। {0}");
    WAY("Hindi", "video_call_duration",  "वीडियो कॉल। {0}");
    WAY("Hindi", "voice_call_ended",     "वॉइस कॉल। समाप्त");
    WAY("Hindi", "video_call_ended",     "वीडियो कॉल। समाप्त");
    WAY("Hindi", "voice_call_missed",    "मिस्ड वॉइस कॉल। वापस कॉल करने के लिए टैप करें");
    WAY("Hindi", "video_call_missed",    "मिस्ड वीडियो कॉल। वापस कॉल करने के लिए टैप करें");
    WAY("Hindi", "voice_call_no_answer", "वॉइस कॉल। कोई जवाब नहीं");
    WAY("Hindi", "video_call_no_answer", "वीडियो कॉल। कोई जवाब नहीं");

    // Japanese
    WAY("Japanese", "voice_call_duration",  "音声通話。{0}");
    WAY("Japanese", "video_call_duration",  "ビデオ通話。{0}");
    WAY("Japanese", "voice_call_ended",     "音声通話。終了");
    WAY("Japanese", "video_call_ended",     "ビデオ通話。終了");
    WAY("Japanese", "voice_call_missed",    "不在音声着信。タップしてかけ直す");
    WAY("Japanese", "video_call_missed",    "不在ビデオ着信。タップしてかけ直す");
    WAY("Japanese", "voice_call_no_answer", "音声通話。応答なし");
    WAY("Japanese", "video_call_no_answer", "ビデオ通話。応答なし");

    // Korean
    WAY("Korean", "voice_call_duration",  "음성 통화. {0}");
    WAY("Korean", "video_call_duration",  "영상 통화. {0}");
    WAY("Korean", "voice_call_ended",     "음성 통화. 종료됨");
    WAY("Korean", "video_call_ended",     "영상 통화. 종료됨");
    WAY("Korean", "voice_call_missed",    "부재중 음성 통화. 다시 걸려면 탭하세요");
    WAY("Korean", "video_call_missed",    "부재중 영상 통화. 다시 걸려면 탭하세요");
    WAY("Korean", "voice_call_no_answer", "음성 통화. 응답 없음");
    WAY("Korean", "video_call_no_answer", "영상 통화. 응답 없음");

    // Mongolian
    WAY("Mongolian", "voice_call_duration",  "Дуут дуудлага. {0}");
    WAY("Mongolian", "video_call_duration",  "Видео дуудлага. {0}");
    WAY("Mongolian", "voice_call_ended",     "Дуут дуудлага. Дууссан");
    WAY("Mongolian", "video_call_ended",     "Видео дуудлага. Дууссан");
    WAY("Mongolian", "voice_call_missed",    "Аваагүй дуут дуудлага. Эргэж залгахын тулд дарна уу");
    WAY("Mongolian", "video_call_missed",    "Аваагүй видео дуудлага. Эргэж залгахын тулд дарна уу");
    WAY("Mongolian", "voice_call_no_answer", "Дуут дуудлага. Хариу алга");
    WAY("Mongolian", "video_call_no_answer", "Видео дуудлага. Хариу алга");

    // Polish
    WAY("Polish", "voice_call_duration",  "Połączenie głosowe. {0}");
    WAY("Polish", "video_call_duration",  "Połączenie wideo. {0}");
    WAY("Polish", "voice_call_ended",     "Połączenie głosowe. Zakończone");
    WAY("Polish", "video_call_ended",     "Połączenie wideo. Zakończone");
    WAY("Polish", "voice_call_missed",    "Nieodebrane połączenie głosowe. Stuknij, aby oddzwonić");
    WAY("Polish", "video_call_missed",    "Nieodebrane połączenie wideo. Stuknij, aby oddzwonić");
    WAY("Polish", "voice_call_no_answer", "Połączenie głosowe. Brak odpowiedzi");
    WAY("Polish", "video_call_no_answer", "Połączenie wideo. Brak odpowiedzi");

    // Ukrainian
    WAY("Ukrainian", "voice_call_duration",  "Голосовий виклик. {0}");
    WAY("Ukrainian", "video_call_duration",  "Відеовиклик. {0}");
    WAY("Ukrainian", "voice_call_ended",     "Голосовий виклик. Завершено");
    WAY("Ukrainian", "video_call_ended",     "Відеовиклик. Завершено");
    WAY("Ukrainian", "voice_call_missed",    "Пропущений голосовий виклик. Торкніться, щоб передзвонити");
    WAY("Ukrainian", "video_call_missed",    "Пропущений відеовиклик. Торкніться, щоб передзвонити");
    WAY("Ukrainian", "voice_call_no_answer", "Голосовий виклик. Немає відповіді");
    WAY("Ukrainian", "video_call_no_answer", "Відеовиклик. Немає відповіді");

    // Uzbek
    WAY("Uzbek", "voice_call_duration",  "Ovozli qo'ng'iroq. {0}");
    WAY("Uzbek", "video_call_duration",  "Video qo'ng'iroq. {0}");
    WAY("Uzbek", "voice_call_ended",     "Ovozli qo'ng'iroq. Tugadi");
    WAY("Uzbek", "video_call_ended",     "Video qo'ng'iroq. Tugadi");
    WAY("Uzbek", "voice_call_missed",    "O'tkazib yuborilgan ovozli qo'ng'iroq. Qayta qo'ng'iroq qilish uchun bosing");
    WAY("Uzbek", "video_call_missed",    "O'tkazib yuborilgan video qo'ng'iroq. Qayta qo'ng'iroq qilish uchun bosing");
    WAY("Uzbek", "voice_call_no_answer", "Ovozli qo'ng'iroq. Javob yo'q");
    WAY("Uzbek", "video_call_no_answer", "Video qo'ng'iroq. Javob yo'q");

    #undef WAY
}
