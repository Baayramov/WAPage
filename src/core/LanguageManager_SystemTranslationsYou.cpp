#include "LanguageManager.h"

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

    // ── Afrikaans — 2nd person (Jy) ──────────────────────────────────────────
    WAY("Afrikaans", "created_group_you", "Jy het groep \"{1}\" geskep");
    WAY("Afrikaans", "created_group_noname_you", "Jy het hierdie groep geskep");
    WAY("Afrikaans", "left_you", "Jy het uitgegaan");
    WAY("Afrikaans", "added_you", "Jy het {1} bygevoeg");
    WAY("Afrikaans", "added_target_you", "{0} het jou bygevoeg");
    WAY("Afrikaans", "was_added_you", "Jy is bygevoeg");
    WAY("Afrikaans", "removed_you", "Jy het {1} verwyder");
    WAY("Afrikaans", "removed_target_you", "{0} het jou verwyder");
    WAY("Afrikaans", "joined_link_you", "Jy het aangesluit deur 'n groepskakel te gebruik.");
    WAY("Afrikaans", "changed_icon_you", "Jy het die groep ikoon verander");
    WAY("Afrikaans", "changed_name_you", "Jy het die groep naam verander na \"{1}\"");
    WAY("Afrikaans", "changed_name_from_to_you", "Jy het die groep naam verander van \"{1}\" na \"{2}\"");
    WAY("Afrikaans", "changed_desc_you", "Jy het die groep beskrywing verander");
    WAY("Afrikaans", "admin_approval_on_you", "Jy het admin goedkeuring aangeskakel om by hierdie groep aan te sluit. Tik om te verander.");
    WAY("Afrikaans", "admin_approval_off_you", "Jy het admin goedkeuring afgeskakel. Tik om te verander.");
    WAY("Afrikaans", "reset_link_you", "Jy het die groep uitnodigingskakel herstel");
    WAY("Afrikaans", "settings_only_admins_edit_you", "Jy het instellings verander: slegs admins kan groep instellings wysig");
    WAY("Afrikaans", "settings_all_edit_you", "Jy het instellings verander: alle lede kan groep instellings wysig");
    WAY("Afrikaans", "settings_only_admins_send_you", "Jy het groep instellings verander: slegs admins kan boodskappe stuur");
    WAY("Afrikaans", "settings_only_admins_add_you", "Jy het groep instellings verander: slegs admins kan ander byvoeg.");
    WAY("Afrikaans", "settings_all_add_you", "Jy het groep instellings verander: alle lede kan ander byvoeg.");
    WAY("Afrikaans", "settings_all_send_you", "Jy het groep instellings verander: alle lede kan boodskappe stuur");
    WAY("Afrikaans", "settings_all_invite_link_you", "Jy het groep instellings verander: almal kan via groepskakel uitnooi.");
    WAY("Afrikaans", "settings_only_admins_invite_link_you", "Jy het instellings verander: slegs admins kan via groepskakel uitnooi.");
    WAY("Afrikaans", "disappear_on_you", "Jy het verdwynende boodskappe aangeskakel. Nuwe boodskappe sal {timer} nadat dit gestuur is uit hierdie klets verdwyn (behalwe gestoordes). Tik om te verander.");
    WAY("Afrikaans", "disappear_off_you", "Jy het verdwynende boodskappe afgeskakel. Tik om te verander.");
    WAY("Afrikaans", "disappear_off2_you", "Jy het verdwynende boodskappe afgeskakel. Tik om meer te leer.");
    WAY("Afrikaans", "update_timer_you", "Jy het die boodskap tydhouer opgedateer. Nuwe boodskappe sal {timer} nadat dit gestuur is uit hierdie klets verdwyn (behalwe gestoordes). Tik om te verander.");
    WAY("Afrikaans", "update_timer2_you", "Jy het die boodskap tydhouer opgedateer. Nuwe boodskappe sal {timer} nadat dit gestuur is uit hierdie klets verdwyn (behalwe gestoordes). Tik om meer te leer.");

    // ── Albanian — 2nd person (Ti) ───────────────────────────────────────────
    WAY("Albanian", "created_group_you", "Ti krijove grupin \"{1}\"");
    WAY("Albanian", "created_group_noname_you", "Ti krijove këtë grup");
    WAY("Albanian", "left_you", "Ti dole");
    WAY("Albanian", "added_you", "Ti shtove {1}");
    WAY("Albanian", "added_target_you", "{0} të shtoi ty");
    WAY("Albanian", "was_added_you", "Ti u shtove");
    WAY("Albanian", "removed_you", "Ti hoqe {1}");
    WAY("Albanian", "removed_target_you", "{0} të hoqi ty");
    WAY("Albanian", "joined_link_you", "Ti u bashkove duke përdorur një lidhje grupi.");
    WAY("Albanian", "changed_icon_you", "Ti ndryshove ikonën e grupit");
    WAY("Albanian", "changed_name_you", "Ti ndryshove emrin e grupit në \"{1}\"");
    WAY("Albanian", "changed_name_from_to_you", "Ti ndryshove emrin e grupit nga \"{1}\" në \"{2}\"");
    WAY("Albanian", "changed_desc_you", "Ti ndryshove përshkrimin e grupit");
    WAY("Albanian", "admin_approval_on_you", "Ti aktivizove miratimin e administratorit për t'u bashkuar me këtë grup. Trokit për të ndryshuar.");
    WAY("Albanian", "admin_approval_off_you", "Ti çaktivizove miratimin e administratorit. Trokit për të ndryshuar.");
    WAY("Albanian", "reset_link_you", "Ti rivendose lidhjen e ftesës së grupit");
    WAY("Albanian", "settings_only_admins_edit_you", "Ti ndryshove cilësimet: vetëm administratorët mund të redaktojnë cilësimet e grupit");
    WAY("Albanian", "settings_all_edit_you", "Ti ndryshove cilësimet: të gjithë anëtarët mund të redaktojnë cilësimet e grupit");
    WAY("Albanian", "settings_only_admins_send_you", "Ti ndryshove cilësimet e grupit: vetëm administratorët mund të dërgojnë mesazhe");
    WAY("Albanian", "settings_only_admins_add_you", "Ti ndryshove cilësimet e grupit: vetëm administratorët mund të shtojnë të tjerë.");
    WAY("Albanian", "settings_all_add_you", "Ti ndryshove cilësimet e grupit: të gjithë anëtarët mund të shtojnë të tjerë.");
    WAY("Albanian", "settings_all_send_you", "Ti ndryshove cilësimet e grupit: të gjithë anëtarët mund të dërgojnë mesazhe");
    WAY("Albanian", "settings_all_invite_link_you", "Ti ndryshove cilësimet e grupit: të gjithë mund të ftojnë përmes lidhjes së grupit.");
    WAY("Albanian", "settings_only_admins_invite_link_you", "Ti ndryshove cilësimet: vetëm administratorët mund të ftojnë përmes lidhjes së grupit.");
    WAY("Albanian", "disappear_on_you", "Ti aktivizove mesazhet që zhduken. Mesazhet e reja do të zhduken nga kjo bisedë {timer} pasi të dërgohen (përveç të ruajturave). Trokit për të ndryshuar.");
    WAY("Albanian", "disappear_off_you", "Ti çaktivizove mesazhet që zhduken. Trokit për të ndryshuar.");
    WAY("Albanian", "disappear_off2_you", "Ti çaktivizove mesazhet që zhduken. Trokit për të mësuar më shumë.");
    WAY("Albanian", "update_timer_you", "Ti përditësove kohëmatësin e mesazhit. Mesazhet e reja do të zhduken nga kjo bisedë {timer} pasi të dërgohen (përveç të ruajturave). Trokit për të ndryshuar.");
    WAY("Albanian", "update_timer2_you", "Ti përditësove kohëmatësin e mesazhit. Mesazhet e reja do të zhduken nga kjo bisedë {timer} pasi të dërgohen (përveç të ruajturave). Trokit për të mësuar më shumë.");

    // ── Bengali — 2nd person (আপনি / তুমি) ────────────────────────────────────
    WAY("Bengali", "created_group_you", "আপনি \"{1}\" গ্রুপ তৈরি করেছেন");
    WAY("Bengali", "created_group_noname_you", "আপনি এই গ্রুপটি তৈরি করেছেন");
    WAY("Bengali", "left_you", "আপনি চলে গেছেন");
    WAY("Bengali", "added_you", "আপনি {1} যোগ করেছেন");
    WAY("Bengali", "added_target_you", "{0} আপনাকে যোগ করেছে");
    WAY("Bengali", "was_added_you", "আপনাকে যোগ করা হয়েছে");
    WAY("Bengali", "removed_you", "আপনি {1} সরিয়ে দিয়েছেন");
    WAY("Bengali", "removed_target_you", "{0} আপনাকে সরিয়ে দিয়েছে");
    WAY("Bengali", "joined_link_you", "আপনি একটি গ্রুপ লিঙ্ক ব্যবহার করে যোগ দিয়েছেন।");
    WAY("Bengali", "changed_icon_you", "আপনি গ্রুপ আইকন পরিবর্তন করেছেন");
    WAY("Bengali", "changed_name_you", "আপনি গ্রুপের নাম \"{1}\" এ পরিবর্তন করেছেন");
    WAY("Bengali", "changed_name_from_to_you", "আপনি গ্রুপের নাম \"{1}\" থেকে \"{2}\" এ পরিবর্তন করেছেন");
    WAY("Bengali", "changed_desc_you", "আপনি গ্রুপ বিবরণ পরিবর্তন করেছেন");
    WAY("Bengali", "admin_approval_on_you", "আপনি এই গ্রুপে যোগদানের জন্য অ্যাডমিন অনুমোদন চালু করেছেন। পরিবর্তন করতে ট্যাপ করুন।");
    WAY("Bengali", "admin_approval_off_you", "আপনি অ্যাডমিন অনুমোদন বন্ধ করেছেন। পরিবর্তন করতে ট্যাপ করুন।");
    WAY("Bengali", "reset_link_you", "আপনি গ্রুপ আমন্ত্রণ লিঙ্ক রিসেট করেছেন");
    WAY("Bengali", "settings_only_admins_edit_you", "আপনি সেটিংস পরিবর্তন করেছেন: শুধুমাত্র অ্যাডমিনরা গ্রুপ সেটিংস সম্পাদনা করতে পারে");
    WAY("Bengali", "settings_all_edit_you", "আপনি সেটিংস পরিবর্তন করেছেন: সকল সদস্য গ্রুপ সেটিংস সম্পাদনা করতে পারে");
    WAY("Bengali", "settings_only_admins_send_you", "আপনি গ্রুপ সেটিংস পরিবর্তন করেছেন: শুধুমাত্র অ্যাডমিনরা বার্তা পাঠাতে পারে");
    WAY("Bengali", "settings_only_admins_add_you", "আপনি গ্রুপ সেটিংস পরিবর্তন করেছেন: শুধুমাত্র অ্যাডমিনরা অন্যদের যোগ করতে পারে।");
    WAY("Bengali", "settings_all_add_you", "আপনি গ্রুপ সেটিংস পরিবর্তন করেছেন: সকল সদস্য অন্যদের যোগ করতে পারে।");
    WAY("Bengali", "settings_all_send_you", "আপনি গ্রুপ সেটিংস পরিবর্তন করেছেন: সকল সদস্য বার্তা পাঠাতে পারে");
    WAY("Bengali", "settings_all_invite_link_you", "আপনি গ্রুপ সেটিংস পরিবর্তন করেছেন: সবাই গ্রুপ লিঙ্কের মাধ্যমে আমন্ত্রণ করতে পারে।");
    WAY("Bengali", "settings_only_admins_invite_link_you", "আপনি সেটিংস পরিবর্তন করেছেন: শুধুমাত্র অ্যাডমিনরা গ্রুপ লিঙ্কের মাধ্যমে আমন্ত্রণ করতে পারে।");
    WAY("Bengali", "disappear_on_you", "আপনি অদৃশ্য হওয়া বার্তা চালু করেছেন। নতুন বার্তাগুলি পাঠানোর {timer} পরে এই চ্যাট থেকে অদৃশ্য হয়ে যাবে (সংরক্ষিত বাদে)। পরিবর্তন করতে ট্যাপ করুন।");
    WAY("Bengali", "disappear_off_you", "আপনি অদৃশ্য হওয়া বার্তা বন্ধ করেছেন। পরিবর্তন করতে ট্যাপ করুন।");
    WAY("Bengali", "disappear_off2_you", "আপনি অদৃশ্য হওয়া বার্তা বন্ধ করেছেন। আরও জানতে ট্যাপ করুন।");
    WAY("Bengali", "update_timer_you", "আপনি বার্তা টাইমার আপডেট করেছেন। নতুন বার্তাগুলি পাঠানোর {timer} পরে এই চ্যাট থেকে অদৃশ্য হয়ে যাবে (সংরক্ষিত বাদে)। পরিবর্তন করতে ট্যাপ করুন।");
    WAY("Bengali", "update_timer2_you", "আপনি বার্তা টাইমার আপডেট করেছেন। নতুন বার্তাগুলি পাঠানোর {timer} পরে এই চ্যাট থেকে অদৃশ্য হয়ে যাবে (সংরক্ষিত বাদে)। আরও জানতে ট্যাপ করুন।");

    // ── Bulgarian — 2nd person (Вие) ─────────────────────────────────────────
    WAY("Bulgarian", "created_group_you", "Вие създадохте група \"{1}\"");
    WAY("Bulgarian", "created_group_noname_you", "Вие създадохте тази група");
    WAY("Bulgarian", "left_you", "Вие напуснахте");
    WAY("Bulgarian", "added_you", "Вие добавихте {1}");
    WAY("Bulgarian", "added_target_you", "{0} ви добави");
    WAY("Bulgarian", "was_added_you", "Вие бяхте добавен");
    WAY("Bulgarian", "removed_you", "Вие премахнахте {1}");
    WAY("Bulgarian", "removed_target_you", "{0} ви премахна");
    WAY("Bulgarian", "joined_link_you", "Вие се присъединихте чрез връзка на групата.");
    WAY("Bulgarian", "changed_icon_you", "Вие променихте иконата на групата");
    WAY("Bulgarian", "changed_name_you", "Вие променихте името на групата на \"{1}\"");
    WAY("Bulgarian", "changed_name_from_to_you", "Вие променихте името на групата от \"{1}\" на \"{2}\"");
    WAY("Bulgarian", "changed_desc_you", "Вие променихте описанието на групата");
    WAY("Bulgarian", "admin_approval_on_you", "Вие включихте одобрение от администратор за присъединяване към тази група. Докоснете за промяна.");
    WAY("Bulgarian", "admin_approval_off_you", "Вие изключихте одобрението от администратор. Докоснете за промяна.");
    WAY("Bulgarian", "reset_link_you", "Вие нулирахте връзката за покана на групата");
    WAY("Bulgarian", "settings_only_admins_edit_you", "Вие променихте настройките: само администраторите могат да редактират настройките на групата");
    WAY("Bulgarian", "settings_all_edit_you", "Вие променихте настройките: всички членове могат да редактират настройките на групата");
    WAY("Bulgarian", "settings_only_admins_send_you", "Вие променихте настройките на групата: само администраторите могат да изпращат съобщения");
    WAY("Bulgarian", "settings_only_admins_add_you", "Вие променихте настройките на групата: само администраторите могат да добавят други.");
    WAY("Bulgarian", "settings_all_add_you", "Вие променихте настройките на групата: всички членове могат да добавят други.");
    WAY("Bulgarian", "settings_all_send_you", "Вие променихте настройките на групата: всички членове могат да изпращат съобщения");
    WAY("Bulgarian", "settings_all_invite_link_you", "Вие променихте настройките на групата: всички могат да поканят чрез връзка на групата.");
    WAY("Bulgarian", "settings_only_admins_invite_link_you", "Вие променихте настройките: само администраторите могат да поканят чрез връзка на групата.");
    WAY("Bulgarian", "disappear_on_you", "Вие включихте изчезващи съобщения. Новите съобщения ще изчезнат от този чат {timer} след изпращането (освен запазените). Докоснете за промяна.");
    WAY("Bulgarian", "disappear_off_you", "Вие изключихте изчезващите съобщения. Докоснете за промяна.");
    WAY("Bulgarian", "disappear_off2_you", "Вие изключихте изчезващите съобщения. Докоснете за повече информация.");
    WAY("Bulgarian", "update_timer_you", "Вие актуализирахте таймера на съобщенията. Новите съобщения ще изчезнат от този чат {timer} след изпращането (освен запазените). Докоснете за промяна.");
    WAY("Bulgarian", "update_timer2_you", "Вие актуализирахте таймера на съобщенията. Новите съобщения ще изчезнат от този чат {timer} след изпращането (освен запазените). Докоснете за повече информация.");

    // ── Catalan — 2nd person (Tu) ───────────────────────────────────────────
    WAY("Catalan", "created_group_you", "Has creat el grup \"{1}\"");
    WAY("Catalan", "created_group_noname_you", "Has creat aquest grup");
    WAY("Catalan", "left_you", "Has sortit");
    WAY("Catalan", "added_you", "Has afegit {1}");
    WAY("Catalan", "added_target_you", "{0} t'ha afegit");
    WAY("Catalan", "was_added_you", "T'han afegit");
    WAY("Catalan", "removed_you", "Has eliminat {1}");
    WAY("Catalan", "removed_target_you", "{0} t'ha eliminat");
    WAY("Catalan", "joined_link_you", "T'has unit mitjançant un enllaç del grup.");
    WAY("Catalan", "changed_icon_you", "Has canviat la icona del grup");
    WAY("Catalan", "changed_name_you", "Has canviat el nom del grup a \"{1}\"");
    WAY("Catalan", "changed_name_from_to_you", "Has canviat el nom del grup de \"{1}\" a \"{2}\"");
    WAY("Catalan", "changed_desc_you", "Has canviat la descripció del grup");
    WAY("Catalan", "admin_approval_on_you", "Has activat l'aprovació de l'administrador per unir-se a aquest grup. Toca per canviar.");
    WAY("Catalan", "admin_approval_off_you", "Has desactivat l'aprovació de l'administrador. Toca per canviar.");
    WAY("Catalan", "reset_link_you", "Has restablert l'enllaç d'invitació del grup");
    WAY("Catalan", "settings_only_admins_edit_you", "Has canviat la configuració: només els administradors poden editar la configuració del grup");
    WAY("Catalan", "settings_all_edit_you", "Has canviat la configuració: tots els membres poden editar la configuració del grup");
    WAY("Catalan", "settings_only_admins_send_you", "Has canviat la configuració del grup: només els administradors poden enviar missatges");
    WAY("Catalan", "settings_only_admins_add_you", "Has canviat la configuració del grup: només els administradors poden afegir altres.");
    WAY("Catalan", "settings_all_add_you", "Has canviat la configuració del grup: tots els membres poden afegir altres.");
    WAY("Catalan", "settings_all_send_you", "Has canviat la configuració del grup: tots els membres poden enviar missatges");
    WAY("Catalan", "settings_all_invite_link_you", "Has canviat la configuració del grup: tots poden convidar mitjançant l'enllaç del grup.");
    WAY("Catalan", "settings_only_admins_invite_link_you", "Has canviat la configuració: només els administradors poden convidar mitjançant l'enllaç del grup.");
    WAY("Catalan", "disappear_on_you", "Has activat els missatges que desapareixen. Els missatges nous desapareixeran d'aquest xat {timer} després d'enviar-se (excepte els desats). Toca per canviar.");
    WAY("Catalan", "disappear_off_you", "Has desactivat els missatges que desapareixen. Toca per canviar.");
    WAY("Catalan", "disappear_off2_you", "Has desactivat els missatges que desapareixen. Toca per obtenir més informació.");
    WAY("Catalan", "update_timer_you", "Has actualitzat el temporitzador de missatges. Els missatges nous desapareixeran d'aquest xat {timer} després d'enviar-se (excepte els desats). Toca per canviar.");
    WAY("Catalan", "update_timer2_you", "Has actualitzat el temporitzador de missatges. Els missatges nous desapareixeran d'aquest xat {timer} després d'enviar-se (excepte els desats). Toca per obtenir més informació.");

    // ── ChineseHongKong — 2nd person (你) ───────────────────────────────────
    WAY("ChineseHongKong", "created_group_you", "你建立了群組「{1}」");
    WAY("ChineseHongKong", "created_group_noname_you", "你建立了此群組");
    WAY("ChineseHongKong", "left_you", "你離開了");
    WAY("ChineseHongKong", "added_you", "你新增了 {1}");
    WAY("ChineseHongKong", "added_target_you", "{0} 新增了你");
    WAY("ChineseHongKong", "was_added_you", "你被新增了");
    WAY("ChineseHongKong", "removed_you", "你移除了 {1}");
    WAY("ChineseHongKong", "removed_target_you", "{0} 移除了你");
    WAY("ChineseHongKong", "joined_link_you", "你使用群組連結加入。");
    WAY("ChineseHongKong", "changed_icon_you", "你變更了群組圖示");
    WAY("ChineseHongKong", "changed_name_you", "你將群組名稱變更為「{1}」");
    WAY("ChineseHongKong", "changed_name_from_to_you", "你將群組名稱從「{1}」變更為「{2}」");
    WAY("ChineseHongKong", "changed_desc_you", "你變更了群組說明");
    WAY("ChineseHongKong", "admin_approval_on_you", "你開啟了管理員核准以加入此群組。點擊以變更。");
    WAY("ChineseHongKong", "admin_approval_off_you", "你關閉了管理員核准。點擊以變更。");
    WAY("ChineseHongKong", "reset_link_you", "你重設了群組邀請連結");
    WAY("ChineseHongKong", "settings_only_admins_edit_you", "你變更了設定：只有管理員才能編輯群組設定");
    WAY("ChineseHongKong", "settings_all_edit_you", "你變更了設定：所有成員都可以編輯群組設定");
    WAY("ChineseHongKong", "settings_only_admins_send_you", "你變更了群組設定：只有管理員才能傳送訊息");
    WAY("ChineseHongKong", "settings_only_admins_add_you", "你變更了群組設定：只有管理員才能新增其他人。");
    WAY("ChineseHongKong", "settings_all_add_you", "你變更了群組設定：所有成員都可以新增其他人。");
    WAY("ChineseHongKong", "settings_all_send_you", "你變更了群組設定：所有成員都可以傳送訊息");
    WAY("ChineseHongKong", "settings_all_invite_link_you", "你變更了群組設定：所有人都可以透過群組連結邀請。");
    WAY("ChineseHongKong", "settings_only_admins_invite_link_you", "你變更了設定：只有管理員才能透過群組連結邀請。");
    WAY("ChineseHongKong", "disappear_on_you", "你開啟了閱後即焚訊息。新訊息將在傳送 {timer} 後從此對話中消失（已儲存的除外）。點擊以變更。");
    WAY("ChineseHongKong", "disappear_off_you", "你關閉了閱後即焚訊息。點擊以變更。");
    WAY("ChineseHongKong", "disappear_off2_you", "你關閉了閱後即焚訊息。點擊以瞭解更多。");
    WAY("ChineseHongKong", "update_timer_you", "你更新了訊息計時器。新訊息將在傳送 {timer} 後從此對話中消失（已儲存的除外）。點擊以變更。");
    WAY("ChineseHongKong", "update_timer2_you", "你更新了訊息計時器。新訊息將在傳送 {timer} 後從此對話中消失（已儲存的除外）。點擊以瞭解更多。");

    // ── ChineseTaiwan — 2nd person (你) ─────────────────────────────────────
    WAY("ChineseTaiwan", "created_group_you", "你建立了群組「{1}」");
    WAY("ChineseTaiwan", "created_group_noname_you", "你建立了此群組");
    WAY("ChineseTaiwan", "left_you", "你離開了");
    WAY("ChineseTaiwan", "added_you", "你新增了 {1}");
    WAY("ChineseTaiwan", "added_target_you", "{0} 新增了你");
    WAY("ChineseTaiwan", "was_added_you", "你被新增了");
    WAY("ChineseTaiwan", "removed_you", "你移除了 {1}");
    WAY("ChineseTaiwan", "removed_target_you", "{0} 移除了你");
    WAY("ChineseTaiwan", "joined_link_you", "你使用群組連結加入。");
    WAY("ChineseTaiwan", "changed_icon_you", "你變更了群組圖示");
    WAY("ChineseTaiwan", "changed_name_you", "你將群組名稱變更為「{1}」");
    WAY("ChineseTaiwan", "changed_name_from_to_you", "你將群組名稱從「{1}」變更為「{2}」");
    WAY("ChineseTaiwan", "changed_desc_you", "你變更了群組說明");
    WAY("ChineseTaiwan", "admin_approval_on_you", "你開啟了管理員核准以加入此群組。點選以變更。");
    WAY("ChineseTaiwan", "admin_approval_off_you", "你關閉了管理員核准。點選以變更。");
    WAY("ChineseTaiwan", "reset_link_you", "你重設了群組邀請連結");
    WAY("ChineseTaiwan", "settings_only_admins_edit_you", "你變更了設定：只有管理員才能編輯群組設定");
    WAY("ChineseTaiwan", "settings_all_edit_you", "你變更了設定：所有成員都可以編輯群組設定");
    WAY("ChineseTaiwan", "settings_only_admins_send_you", "你變更了群組設定：只有管理員才能傳送訊息");
    WAY("ChineseTaiwan", "settings_only_admins_add_you", "你變更了群組設定：只有管理員才能新增其他人。");
    WAY("ChineseTaiwan", "settings_all_add_you", "你變更了群組設定：所有成員都可以新增其他人。");
    WAY("ChineseTaiwan", "settings_all_send_you", "你變更了群組設定：所有成員都可以傳送訊息");
    WAY("ChineseTaiwan", "settings_all_invite_link_you", "你變更了群組設定：所有人都可以透過群組連結邀請。");
    WAY("ChineseTaiwan", "settings_only_admins_invite_link_you", "你變更了設定：只有管理員才能透過群組連結邀請。");
    WAY("ChineseTaiwan", "disappear_on_you", "你開啟了限時訊息。新訊息將在傳送 {timer} 後從此對話中消失（已儲存的除外）。點選以變更。");
    WAY("ChineseTaiwan", "disappear_off_you", "你關閉了限時訊息。點選以變更。");
    WAY("ChineseTaiwan", "disappear_off2_you", "你關閉了限時訊息。點選以瞭解更多。");
    WAY("ChineseTaiwan", "update_timer_you", "你更新了訊息計時器。新訊息將在傳送 {timer} 後從此對話中消失（已儲存的除外）。點選以變更。");
    WAY("ChineseTaiwan", "update_timer2_you", "你更新了訊息計時器。新訊息將在傳送 {timer} 後從此對話中消失（已儲存的除外）。點選以瞭解更多。");

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

    // Afrikaans
    WAY("Afrikaans", "voice_call_you", "Stemoproep. {1} • Jy het aangesluit");
    WAY("Afrikaans", "video_call_you", "Video-oproep. {1} • Jy het aangesluit");
    WAY("Afrikaans", "unit_sec", "s");
    WAY("Afrikaans", "unit_min", "min");
    WAY("Afrikaans", "unit_hr",  "u");

    // Albanian
    WAY("Albanian", "voice_call_you", "Telefonatë zanore. {1} • Ti u bashkove");
    WAY("Albanian", "video_call_you", "Video thirrje. {1} • Ti u bashkove");
    WAY("Albanian", "unit_sec", "sek");
    WAY("Albanian", "unit_min", "min");
    WAY("Albanian", "unit_hr",  "orë");

    // Bengali
    WAY("Bengali", "voice_call_you", "ভয়েস কল। {1} • আপনি যোগ দিয়েছেন");
    WAY("Bengali", "video_call_you", "ভিডিও কল। {1} • আপনি যোগ দিয়েছেন");
    WAY("Bengali", "unit_sec", "সে");
    WAY("Bengali", "unit_min", "মি");
    WAY("Bengali", "unit_hr",  "ঘ");

    // Bulgarian
    WAY("Bulgarian", "voice_call_you", "Гласов разговор. {1} • Вие се присъединихте");
    WAY("Bulgarian", "video_call_you", "Видео разговор. {1} • Вие се присъединихте");
    WAY("Bulgarian", "unit_sec", "сек");
    WAY("Bulgarian", "unit_min", "мин");
    WAY("Bulgarian", "unit_hr",  "ч");

    // Catalan
    WAY("Catalan", "voice_call_you", "Trucada de veu. {1} • T'has unit");
    WAY("Catalan", "video_call_you", "Videotrucada. {1} • T'has unit");
    WAY("Catalan", "unit_sec", "s");
    WAY("Catalan", "unit_min", "min");
    WAY("Catalan", "unit_hr",  "h");

    // ChineseHongKong
    WAY("ChineseHongKong", "voice_call_you", "語音通話。{1} • 你已加入");
    WAY("ChineseHongKong", "video_call_you", "視訊通話。{1} • 你已加入");
    WAY("ChineseHongKong", "unit_sec", "秒");
    WAY("ChineseHongKong", "unit_min", "分");
    WAY("ChineseHongKong", "unit_hr",  "時");

    // ChineseTaiwan
    WAY("ChineseTaiwan", "voice_call_you", "語音通話。{1} • 你已加入");
    WAY("ChineseTaiwan", "video_call_you", "視訊通話。{1} • 你已加入");
    WAY("ChineseTaiwan", "unit_sec", "秒");
    WAY("ChineseTaiwan", "unit_min", "分");
    WAY("ChineseTaiwan", "unit_hr",  "時");

    // ── Croatian — 2nd person (ti) ──────────────────────────────────────────
    WAY("Croatian", "created_group_you", "Stvorio/la si grupu \"{1}\"");
    WAY("Croatian", "created_group_noname_you", "Stvorio/la si ovu grupu");
    WAY("Croatian", "left_you", "Napustio/la si");
    WAY("Croatian", "added_you", "Dodao/la si {1}");
    WAY("Croatian", "added_target_you", "{0} te dodao/la");
    WAY("Croatian", "was_added_you", "Dodan/a si");
    WAY("Croatian", "removed_you", "Uklonio/la si {1}");
    WAY("Croatian", "removed_target_you", "{0} te uklonio/la");
    WAY("Croatian", "joined_link_you", "Pridružio/la si se koristeći grupni link.");
    WAY("Croatian", "changed_icon_you", "Promijenio/la si ikonu grupe");
    WAY("Croatian", "changed_name_you", "Promijenio/la si naziv grupe u \"{1}\"");
    WAY("Croatian", "changed_name_from_to_you", "Promijenio/la si naziv grupe iz \"{1}\" u \"{2}\"");
    WAY("Croatian", "changed_desc_you", "Promijenio/la si opis grupe");
    WAY("Croatian", "admin_approval_on_you", "Uključio/la si odobrenje administratora za pristupanje grupi. Dotakni za promjenu.");
    WAY("Croatian", "admin_approval_off_you", "Isključio/la si odobrenje administratora za pristupanje grupi. Dotakni za promjenu.");
    WAY("Croatian", "reset_link_you", "Resetirao/la si pozivni link grupe");
    WAY("Croatian", "settings_only_admins_edit_you", "Promijenio/la si postavke tako da samo administratori mogu uređivati postavke grupe");
    WAY("Croatian", "settings_all_edit_you", "Promijenio/la si postavke tako da svi članovi mogu uređivati postavke grupe");
    WAY("Croatian", "settings_only_admins_send_you", "Promijenio/la si postavke grupe tako da samo administratori mogu slati poruke");
    WAY("Croatian", "settings_only_admins_add_you", "Promijenio/la si postavke grupe tako da samo administratori mogu dodavati druge.");
    WAY("Croatian", "settings_all_add_you", "Promijenio/la si postavke grupe tako da svi članovi mogu dodavati druge.");
    WAY("Croatian", "settings_all_send_you", "Promijenio/la si postavke grupe tako da svi članovi mogu slati poruke");
    WAY("Croatian", "settings_all_invite_link_you", "Promijenio/la si postavke grupe tako da svi članovi mogu pozivati putem linka.");
    WAY("Croatian", "settings_only_admins_invite_link_you", "Promijenio/la si postavke tako da samo administratori mogu pozivati putem linka.");
    WAY("Croatian", "disappear_on_you", "Uključio/la si poruke koje nestaju. Nove poruke će nestati iz ovog razgovora {timer} nakon slanja, osim ako nisu sačuvane. Dotakni za promjenu.");
    WAY("Croatian", "disappear_off_you", "Isključio/la si poruke koje nestaju. Dotakni za promjenu.");
    WAY("Croatian", "disappear_off2_you", "Isključio/la si poruke koje nestaju. Dotakni za više informacija.");
    WAY("Croatian", "update_timer_you", "Ažurirao/la si mjerač vremena poruka. Nove poruke će nestati iz ovog razgovora {timer} nakon slanja, osim ako nisu sačuvane. Dotakni za promjenu.");
    WAY("Croatian", "update_timer2_you", "Ažurirao/la si mjerač vremena poruka. Nove poruke će nestati {timer} nakon slanja, osim ako nisu sačuvane. Dotakni za više informacija.");
    WAY("Croatian", "voice_call_you", "Glasovni poziv. {1} • Pridružio/la si se");
    WAY("Croatian", "video_call_you", "Video poziv. {1} • Pridružio/la si se");
    WAY("Croatian", "unit_sec", "s");
    WAY("Croatian", "unit_min", "min");
    WAY("Croatian", "unit_hr",  "h");

    // ── Czech — 2nd person (vy, formal) ──────────────────────────────────────
    WAY("Czech", "created_group_you", "Vytvořil/a jste skupinu \"{1}\"");
    WAY("Czech", "created_group_noname_you", "Vytvořil/a jste tuto skupinu");
    WAY("Czech", "left_you", "Odešel/odešla jste");
    WAY("Czech", "added_you", "Přidal/a jste {1}");
    WAY("Czech", "added_target_you", "{0} vás přidal/a");
    WAY("Czech", "was_added_you", "Byl/a jste přidán/a");
    WAY("Czech", "removed_you", "Odstranil/a jste {1}");
    WAY("Czech", "removed_target_you", "{0} vás odstranil/a");
    WAY("Czech", "joined_link_you", "Připojil/a jste se pomocí odkazu skupiny.");
    WAY("Czech", "changed_icon_you", "Změnil/a jste ikonu skupiny");
    WAY("Czech", "changed_name_you", "Změnil/a jste název skupiny na \"{1}\"");
    WAY("Czech", "changed_name_from_to_you", "Změnil/a jste název skupiny z \"{1}\" na \"{2}\"");
    WAY("Czech", "changed_desc_you", "Změnil/a jste popis skupiny");
    WAY("Czech", "admin_approval_on_you", "Zapnul/a jste schválení administrátorem pro připojení k této skupině. Klepnutím změníte.");
    WAY("Czech", "admin_approval_off_you", "Vypnul/a jste schválení administrátorem pro připojení k této skupině. Klepnutím změníte.");
    WAY("Czech", "reset_link_you", "Resetoval/a jste odkaz pozvánky skupiny");
    WAY("Czech", "settings_only_admins_edit_you", "Změnil/a jste nastavení tak, že pouze administrátoři mohou upravovat nastavení skupiny");
    WAY("Czech", "settings_all_edit_you", "Změnil/a jste nastavení tak, že všichni členové mohou upravovat nastavení skupiny");
    WAY("Czech", "settings_only_admins_send_you", "Změnil/a jste nastavení této skupiny tak, že pouze administrátoři mohou posílat zprávy");
    WAY("Czech", "settings_only_admins_add_you", "Změnil/a jste nastavení této skupiny tak, že pouze administrátoři mohou přidávat další osoby.");
    WAY("Czech", "settings_all_add_you", "Změnil/a jste nastavení této skupiny tak, že všichni členové mohou přidávat další osoby.");
    WAY("Czech", "settings_all_send_you", "Změnil/a jste nastavení této skupiny tak, že všichni členové mohou posílat zprávy");
    WAY("Czech", "settings_all_invite_link_you", "Změnil/a jste nastavení této skupiny tak, že všichni členové mohou pozvat pomocí odkazu.");
    WAY("Czech", "settings_only_admins_invite_link_you", "Změnil/a jste nastavení tak, že pouze administrátoři mohou pozvat pomocí odkazu.");
    WAY("Czech", "disappear_on_you", "Zapnul/a jste mizející zprávy. Nové zprávy zmizí z tohoto rozhovoru {timer} po odeslání (kromě uložených). Klepnutím změníte.");
    WAY("Czech", "disappear_off_you", "Vypnul/a jste mizející zprávy. Klepnutím změníte.");
    WAY("Czech", "disappear_off2_you", "Vypnul/a jste mizející zprávy. Klepnutím se dozvíte více.");
    WAY("Czech", "update_timer_you", "Aktualizoval/a jste časovač zpráv. Nové zprávy zmizí z tohoto rozhovoru {timer} po odeslání (kromě uložených). Klepnutím změníte.");
    WAY("Czech", "update_timer2_you", "Aktualizoval/a jste časovač zpráv. Nové zprávy zmizí {timer} po odeslání (kromě uložených). Klepnutím se dozvíte více.");
    WAY("Czech", "voice_call_you", "Hlasový hovor. {1} • Připojil/a jste se");
    WAY("Czech", "video_call_you", "Videohovor. {1} • Připojil/a jste se");
    WAY("Czech", "unit_sec", "s");
    WAY("Czech", "unit_min", "min");
    WAY("Czech", "unit_hr",  "h");

    // ── Danish — 2nd person (du, informal) ───────────────────────────────────
    WAY("Danish", "created_group_you", "Du oprettede gruppen \"{1}\"");
    WAY("Danish", "created_group_noname_you", "Du oprettede denne gruppe");
    WAY("Danish", "left_you", "Du forlod");
    WAY("Danish", "added_you", "Du tilføjede {1}");
    WAY("Danish", "added_target_you", "{0} tilføjede dig");
    WAY("Danish", "was_added_you", "Du blev tilføjet");
    WAY("Danish", "removed_you", "Du fjernede {1}");
    WAY("Danish", "removed_target_you", "{0} fjernede dig");
    WAY("Danish", "joined_link_you", "Du deltog via gruppens link.");
    WAY("Danish", "changed_icon_you", "Du ændrede gruppens ikon");
    WAY("Danish", "changed_name_you", "Du ændrede gruppens navn til \"{1}\"");
    WAY("Danish", "changed_name_from_to_you", "Du ændrede gruppens navn fra \"{1}\" til \"{2}\"");
    WAY("Danish", "changed_desc_you", "Du ændrede gruppebeskrivelsen");
    WAY("Danish", "admin_approval_on_you", "Du aktiverede administratorgodkendelse for at deltage i denne gruppe. Tryk for at ændre.");
    WAY("Danish", "admin_approval_off_you", "Du deaktiverede administratorgodkendelse for at deltage i denne gruppe. Tryk for at ændre.");
    WAY("Danish", "reset_link_you", "Du nulstillede gruppens invitationslink");
    WAY("Danish", "settings_only_admins_edit_you", "Du ændrede indstillingerne, så kun administratorer kan redigere gruppeindstillingerne");
    WAY("Danish", "settings_all_edit_you", "Du ændrede indstillingerne, så alle medlemmer kan redigere gruppeindstillingerne");
    WAY("Danish", "settings_only_admins_send_you", "Du ændrede denne gruppes indstillinger, så kun administratorer kan sende beskeder");
    WAY("Danish", "settings_only_admins_add_you", "Du ændrede denne gruppes indstillinger, så kun administratorer kan tilføje andre.");
    WAY("Danish", "settings_all_add_you", "Du ændrede denne gruppes indstillinger, så alle medlemmer kan tilføje andre.");
    WAY("Danish", "settings_all_send_you", "Du ændrede denne gruppes indstillinger, så alle medlemmer kan sende beskeder");
    WAY("Danish", "settings_all_invite_link_you", "Du ændrede denne gruppes indstillinger, så alle medlemmer kan invitere via link.");
    WAY("Danish", "settings_only_admins_invite_link_you", "Du ændrede indstillingerne, så kun administratorer kan invitere via link.");
    WAY("Danish", "disappear_on_you", "Du aktiverede forsvindende beskeder. Nye beskeder forsvinder fra denne samtale {timer} efter afsendelse (bortset fra gemte). Tryk for at ændre.");
    WAY("Danish", "disappear_off_you", "Du deaktiverede forsvindende beskeder. Tryk for at ændre.");
    WAY("Danish", "disappear_off2_you", "Du deaktiverede forsvindende beskeder. Tryk for at lære mere.");
    WAY("Danish", "update_timer_you", "Du opdaterede beskedtimeren. Nye beskeder forsvinder fra denne samtale {timer} efter afsendelse (bortset fra gemte). Tryk for at ændre.");
    WAY("Danish", "update_timer2_you", "Du opdaterede beskedtimeren. Nye beskeder forsvinder {timer} efter afsendelse (bortset fra gemte). Tryk for at lære mere.");
    WAY("Danish", "voice_call_you", "Taleopkald. {1} • Du deltog");
    WAY("Danish", "video_call_you", "Videoopkald. {1} • Du deltog");
    WAY("Danish", "unit_sec", "s");
    WAY("Danish", "unit_min", "min");
    WAY("Danish", "unit_hr",  "t");

    // ── Dutch — 2nd person (u, formal) ───────────────────────────────────────
    WAY("Dutch", "created_group_you", "U heeft de groep \"{1}\" gemaakt");
    WAY("Dutch", "created_group_noname_you", "U heeft deze groep gemaakt");
    WAY("Dutch", "left_you", "U heeft de groep verlaten");
    WAY("Dutch", "added_you", "U heeft {1} toegevoegd");
    WAY("Dutch", "added_target_you", "{0} heeft u toegevoegd");
    WAY("Dutch", "was_added_you", "U bent toegevoegd");
    WAY("Dutch", "removed_you", "U heeft {1} verwijderd");
    WAY("Dutch", "removed_target_you", "{0} heeft u verwijderd");
    WAY("Dutch", "joined_link_you", "U bent toegetreden via een groepslink.");
    WAY("Dutch", "changed_icon_you", "U heeft het groepspictogram gewijzigd");
    WAY("Dutch", "changed_name_you", "U heeft de groepsnaam gewijzigd naar \"{1}\"");
    WAY("Dutch", "changed_name_from_to_you", "U heeft de groepsnaam gewijzigd van \"{1}\" naar \"{2}\"");
    WAY("Dutch", "changed_desc_you", "U heeft de groepsbeschrijving gewijzigd");
    WAY("Dutch", "admin_approval_on_you", "U heeft beheerdersgoedkeuring ingeschakeld om lid te worden van deze groep. Tik om te wijzigen.");
    WAY("Dutch", "admin_approval_off_you", "U heeft beheerdersgoedkeuring uitgeschakeld om lid te worden van deze groep. Tik om te wijzigen.");
    WAY("Dutch", "reset_link_you", "U heeft de uitnodigingslink van de groep opnieuw ingesteld");
    WAY("Dutch", "settings_only_admins_edit_you", "U heeft de instellingen gewijzigd zodat alleen beheerders de groepsinstellingen kunnen bewerken");
    WAY("Dutch", "settings_all_edit_you", "U heeft de instellingen gewijzigd zodat alle leden de groepsinstellingen kunnen bewerken");
    WAY("Dutch", "settings_only_admins_send_you", "U heeft de instellingen van deze groep gewijzigd zodat alleen beheerders berichten kunnen verzenden");
    WAY("Dutch", "settings_only_admins_add_you", "U heeft de instellingen van deze groep gewijzigd zodat alleen beheerders anderen kunnen toevoegen.");
    WAY("Dutch", "settings_all_add_you", "U heeft de instellingen van deze groep gewijzigd zodat alle leden anderen kunnen toevoegen.");
    WAY("Dutch", "settings_all_send_you", "U heeft de instellingen van deze groep gewijzigd zodat alle leden berichten kunnen verzenden");
    WAY("Dutch", "settings_all_invite_link_you", "U heeft de instellingen van deze groep gewijzigd zodat alle leden mensen kunnen uitnodigen via een link.");
    WAY("Dutch", "settings_only_admins_invite_link_you", "U heeft de instellingen gewijzigd zodat alleen beheerders mensen kunnen uitnodigen via een link.");
    WAY("Dutch", "disappear_on_you", "U heeft verdwijnende berichten ingeschakeld. Nieuwe berichten verdwijnen uit dit gesprek {timer} nadat ze zijn verzonden (behalve bewaard). Tik om te wijzigen.");
    WAY("Dutch", "disappear_off_you", "U heeft verdwijnende berichten uitgeschakeld. Tik om te wijzigen.");
    WAY("Dutch", "disappear_off2_you", "U heeft verdwijnende berichten uitgeschakeld. Tik voor meer informatie.");
    WAY("Dutch", "update_timer_you", "U heeft de berichttimer bijgewerkt. Nieuwe berichten verdwijnen uit dit gesprek {timer} nadat ze zijn verzonden (behalve bewaard). Tik om te wijzigen.");
    WAY("Dutch", "update_timer2_you", "U heeft de berichttimer bijgewerkt. Nieuwe berichten verdwijnen {timer} nadat ze zijn verzonden (behalve bewaard). Tik voor meer informatie.");
    WAY("Dutch", "voice_call_you", "Spraakoproep. {1} • U bent toegetreden");
    WAY("Dutch", "video_call_you", "Videogesprek. {1} • U bent toegetreden");
    WAY("Dutch", "unit_sec", "s");
    WAY("Dutch", "unit_min", "min");
    WAY("Dutch", "unit_hr",  "u");

    // ── Estonian — 2nd person (teie, formal) ─────────────────────────────────
    WAY("Estonian", "created_group_you", "Te lõite grupi \"{1}\"");
    WAY("Estonian", "created_group_noname_you", "Te lõite selle grupi");
    WAY("Estonian", "left_you", "Te lahkusite");
    WAY("Estonian", "added_you", "Te lisasite {1}");
    WAY("Estonian", "added_target_you", "{0} lisas teid");
    WAY("Estonian", "was_added_you", "Teid lisati");
    WAY("Estonian", "removed_you", "Te eemaldasite {1}");
    WAY("Estonian", "removed_target_you", "{0} eemaldas teid");
    WAY("Estonian", "joined_link_you", "Te liitusite grupi lingi kaudu.");
    WAY("Estonian", "changed_icon_you", "Te muutsite grupi ikooni");
    WAY("Estonian", "changed_name_you", "Te muutsite grupi nimeks \"{1}\"");
    WAY("Estonian", "changed_name_from_to_you", "Te muutsite grupi nime \"{1}\" nimeks \"{2}\"");
    WAY("Estonian", "changed_desc_you", "Te muutsite grupi kirjeldust");
    WAY("Estonian", "admin_approval_on_you", "Te lülitasite sisse administraatori kinnituse sellesse gruppi liitumiseks. Puudutage muutmiseks.");
    WAY("Estonian", "admin_approval_off_you", "Te lülitasite välja administraatori kinnituse sellesse gruppi liitumiseks. Puudutage muutmiseks.");
    WAY("Estonian", "reset_link_you", "Te lähtestasiteregrupi kutselingi");
    WAY("Estonian", "settings_only_admins_edit_you", "Te muutsite seadeid nii, et ainult administraatorid saavad grupi seadeid muuta");
    WAY("Estonian", "settings_all_edit_you", "Te muutsite seadeid nii, et kõik liikmed saavad grupi seadeid muuta");
    WAY("Estonian", "settings_only_admins_send_you", "Te muutsite selle grupi seadeid nii, et ainult administraatorid saavad sõnumeid saata");
    WAY("Estonian", "settings_only_admins_add_you", "Te muutsite selle grupi seadeid nii, et ainult administraatorid saavad teisi lisada.");
    WAY("Estonian", "settings_all_add_you", "Te muutsite selle grupi seadeid nii, et kõik liikmed saavad teisi lisada.");
    WAY("Estonian", "settings_all_send_you", "Te muutsite selle grupi seadeid nii, et kõik liikmed saavad sõnumeid saata");
    WAY("Estonian", "settings_all_invite_link_you", "Te muutsite selle grupi seadeid nii, et kõik liikmed saavad lingi kaudu kutsuda.");
    WAY("Estonian", "settings_only_admins_invite_link_you", "Te muutsite seadeid nii, et ainult administraatorid saavad lingi kaudu kutsuda.");
    WAY("Estonian", "disappear_on_you", "Te lülitasite kaduvad sõnumid sisse. Uued sõnumid kaovad sellest vestlusest {timer} pärast saatmist (välja arvatud salvestatud). Puudutage muutmiseks.");
    WAY("Estonian", "disappear_off_you", "Te lülitasite kaduvad sõnumid välja. Puudutage muutmiseks.");
    WAY("Estonian", "disappear_off2_you", "Te lülitasite kaduvad sõnumid välja. Puudutage lisateabe saamiseks.");
    WAY("Estonian", "update_timer_you", "Te uuendasite sõnumi taimerit. Uued sõnumid kaovad sellest vestlusest {timer} pärast saatmist (välja arvatud salvestatud). Puudutage muutmiseks.");
    WAY("Estonian", "update_timer2_you", "Te uuendasite sõnumi taimerit. Uued sõnumid kaovad {timer} pärast saatmist (välja arvatud salvestatud). Puudutage lisateabe saamiseks.");
    WAY("Estonian", "voice_call_you", "Häälkõne. {1} • Te liitusite");
    WAY("Estonian", "video_call_you", "Videokõne. {1} • Te liitusite");
    WAY("Estonian", "unit_sec", "s");
    WAY("Estonian", "unit_min", "min");
    WAY("Estonian", "unit_hr",  "t");

    // ── Filipino — 2nd person (ikaw/ka, informal) ────────────────────────────
    WAY("Filipino", "created_group_you", "Lumikha ka ng grupo na \"{1}\"");
    WAY("Filipino", "created_group_noname_you", "Lumikha ka ng grupong ito");
    WAY("Filipino", "left_you", "Umalis ka");
    WAY("Filipino", "added_you", "Idinagdag mo si {1}");
    WAY("Filipino", "added_target_you", "Idinagdag ka ni {0}");
    WAY("Filipino", "was_added_you", "Idinagdag ka");
    WAY("Filipino", "removed_you", "Inalis mo si {1}");
    WAY("Filipino", "removed_target_you", "Inalis ka ni {0}");
    WAY("Filipino", "joined_link_you", "Sumali ka gamit ang group link.");
    WAY("Filipino", "changed_icon_you", "Binago mo ang icon ng grupo");
    WAY("Filipino", "changed_name_you", "Binago mo ang pangalan ng grupo sa \"{1}\"");
    WAY("Filipino", "changed_name_from_to_you", "Binago mo ang pangalan ng grupo mula \"{1}\" sa \"{2}\"");
    WAY("Filipino", "changed_desc_you", "Binago mo ang deskripsyon ng grupo");
    WAY("Filipino", "admin_approval_on_you", "Binuksan mo ang pag-apruba ng admin upang sumali sa grupong ito. I-tap upang baguhin.");
    WAY("Filipino", "admin_approval_off_you", "Isinara mo ang pag-apruba ng admin upang sumali sa grupong ito. I-tap upang baguhin.");
    WAY("Filipino", "reset_link_you", "Na-reset mo ang invitation link ng grupo");
    WAY("Filipino", "settings_only_admins_edit_you", "Binago mo ang mga setting upang ang mga admin lang ang makakapag-edit ng mga setting ng grupo");
    WAY("Filipino", "settings_all_edit_you", "Binago mo ang mga setting upang lahat ng miyembro ay makakapag-edit ng mga setting ng grupo");
    WAY("Filipino", "settings_only_admins_send_you", "Binago mo ang mga setting ng grupong ito upang ang mga admin lang ang makakapagpadala ng mga mensahe");
    WAY("Filipino", "settings_only_admins_add_you", "Binago mo ang mga setting ng grupong ito upang ang mga admin lang ang makakapagdagdag ng iba.");
    WAY("Filipino", "settings_all_add_you", "Binago mo ang mga setting ng grupong ito upang lahat ng miyembro ay makakapagdagdag ng iba.");
    WAY("Filipino", "settings_all_send_you", "Binago mo ang mga setting ng grupong ito upang lahat ng miyembro ay makakapagpadala ng mga mensahe");
    WAY("Filipino", "settings_all_invite_link_you", "Binago mo ang mga setting ng grupong ito upang lahat ng miyembro ay makakapag-imbita gamit ang link.");
    WAY("Filipino", "settings_only_admins_invite_link_you", "Binago mo ang mga setting upang ang mga admin lang ang makakapag-imbita gamit ang link.");
    WAY("Filipino", "disappear_on_you", "Binuksan mo ang mga nawawalang mensahe. Ang mga bagong mensahe ay mawawala sa pag-uusap na ito {timer} pagkatapos mapadala (maliban sa mga naka-save). I-tap upang baguhin.");
    WAY("Filipino", "disappear_off_you", "Isinara mo ang mga nawawalang mensahe. I-tap upang baguhin.");
    WAY("Filipino", "disappear_off2_you", "Isinara mo ang mga nawawalang mensahe. I-tap upang matuto pa.");
    WAY("Filipino", "update_timer_you", "Na-update mo ang message timer. Ang mga bagong mensahe ay mawawala sa pag-uusap na ito {timer} pagkatapos mapadala (maliban sa mga naka-save). I-tap upang baguhin.");
    WAY("Filipino", "update_timer2_you", "Na-update mo ang message timer. Ang mga bagong mensahe ay mawawala {timer} pagkatapos mapadala (maliban sa mga naka-save). I-tap upang matuto pa.");
    WAY("Filipino", "voice_call_you", "Voice call. {1} • Sumali ka");
    WAY("Filipino", "video_call_you", "Video call. {1} • Sumali ka");
    WAY("Filipino", "unit_sec", "s");
    WAY("Filipino", "unit_min", "min");
    WAY("Filipino", "unit_hr",  "o");

    // ── Finnish — 2nd person (sinä, informal) ────────────────────────────────
    WAY("Finnish", "created_group_you", "Loit ryhmän \"{1}\"");
    WAY("Finnish", "created_group_noname_you", "Loit tämän ryhmän");
    WAY("Finnish", "left_you", "Poistuit");
    WAY("Finnish", "added_you", "Lisäsit käyttäjän {1}");
    WAY("Finnish", "added_target_you", "{0} lisäsi sinut");
    WAY("Finnish", "was_added_you", "Sinut lisättiin");
    WAY("Finnish", "removed_you", "Poistit käyttäjän {1}");
    WAY("Finnish", "removed_target_you", "{0} poisti sinut");
    WAY("Finnish", "joined_link_you", "Liityit ryhmälinkin kautta.");
    WAY("Finnish", "changed_icon_you", "Vaihdoit ryhmän kuvakkeen");
    WAY("Finnish", "changed_name_you", "Vaihdoit ryhmän nimeksi \"{1}\"");
    WAY("Finnish", "changed_name_from_to_you", "Vaihdoit ryhmän nimen \"{1}\" nimeksi \"{2}\"");
    WAY("Finnish", "changed_desc_you", "Muutit ryhmän kuvausta");
    WAY("Finnish", "admin_approval_on_you", "Otit käyttöön ylläpitäjän hyväksynnän tähän ryhmään liittymiseen. Napauta muuttaaksesi.");
    WAY("Finnish", "admin_approval_off_you", "Poistit käytöstä ylläpitäjän hyväksynnän tähän ryhmään liittymiseen. Napauta muuttaaksesi.");
    WAY("Finnish", "reset_link_you", "Nollasit ryhmän kutsulinkin");
    WAY("Finnish", "settings_only_admins_edit_you", "Muutit asetuksia niin, että vain ylläpitäjät voivat muokata ryhmän asetuksia");
    WAY("Finnish", "settings_all_edit_you", "Muutit asetuksia niin, että kaikki jäsenet voivat muokata ryhmän asetuksia");
    WAY("Finnish", "settings_only_admins_send_you", "Muutit tämän ryhmän asetuksia niin, että vain ylläpitäjät voivat lähettää viestejä");
    WAY("Finnish", "settings_only_admins_add_you", "Muutit tämän ryhmän asetuksia niin, että vain ylläpitäjät voivat lisätä muita.");
    WAY("Finnish", "settings_all_add_you", "Muutit tämän ryhmän asetuksia niin, että kaikki jäsenet voivat lisätä muita.");
    WAY("Finnish", "settings_all_send_you", "Muutit tämän ryhmän asetuksia niin, että kaikki jäsenet voivat lähettää viestejä");
    WAY("Finnish", "settings_all_invite_link_you", "Muutit tämän ryhmän asetuksia niin, että kaikki jäsenet voivat kutsua linkin kautta.");
    WAY("Finnish", "settings_only_admins_invite_link_you", "Muutit asetuksia niin, että vain ylläpitäjät voivat kutsua linkin kautta.");
    WAY("Finnish", "disappear_on_you", "Otit käyttöön katoavat viestit. Uudet viestit katoavat tästä keskustelusta {timer} lähettämisen jälkeen (paitsi tallennetut). Napauta muuttaaksesi.");
    WAY("Finnish", "disappear_off_you", "Poistit käytöstä katoavat viestit. Napauta muuttaaksesi.");
    WAY("Finnish", "disappear_off2_you", "Poistit käytöstä katoavat viestit. Napauta saadaksesi lisätietoja.");
    WAY("Finnish", "update_timer_you", "Päivitit viestiajastimen. Uudet viestit katoavat tästä keskustelusta {timer} lähettämisen jälkeen (paitsi tallennetut). Napauta muuttaaksesi.");
    WAY("Finnish", "update_timer2_you", "Päivitit viestiajastimen. Uudet viestit katoavat {timer} lähettämisen jälkeen (paitsi tallennetut). Napauta saadaksesi lisätietoja.");
    WAY("Finnish", "voice_call_you", "Äänipuhelu. {1} • Liityit");
    WAY("Finnish", "video_call_you", "Videopuhelu. {1} • Liityit");
    WAY("Finnish", "unit_sec", "s");
    WAY("Finnish", "unit_min", "min");
    WAY("Finnish", "unit_hr",  "t");

    // ── Greek — 2nd person (εσείς, formal) ───────────────────────────────────
    WAY("Greek", "created_group_you", "Δημιουργήσατε την ομάδα \"{1}\"");
    WAY("Greek", "created_group_noname_you", "Δημιουργήσατε αυτήν την ομάδα");
    WAY("Greek", "left_you", "Αποχωρήσατε");
    WAY("Greek", "added_you", "Προσθέσατε τον/την {1}");
    WAY("Greek", "added_target_you", "Ο/Η {0} σας πρόσθεσε");
    WAY("Greek", "was_added_you", "Προστεθήκατε");
    WAY("Greek", "removed_you", "Αφαιρέσατε τον/την {1}");
    WAY("Greek", "removed_target_you", "Ο/Η {0} σας αφαίρεσε");
    WAY("Greek", "joined_link_you", "Συμμετείχατε χρησιμοποιώντας σύνδεσμο ομάδας.");
    WAY("Greek", "changed_icon_you", "Αλλάξατε το εικονίδιο της ομάδας");
    WAY("Greek", "changed_name_you", "Αλλάξατε το όνομα της ομάδας σε \"{1}\"");
    WAY("Greek", "changed_name_from_to_you", "Αλλάξατε το όνομα της ομάδας από \"{1}\" σε \"{2}\"");
    WAY("Greek", "changed_desc_you", "Αλλάξατε την περιγραφή της ομάδας");
    WAY("Greek", "admin_approval_on_you", "Ενεργοποιήσατε την έγκριση διαχειριστή για συμμετοχή σε αυτήν την ομάδα. Πατήστε για αλλαγή.");
    WAY("Greek", "admin_approval_off_you", "Απενεργοποιήσατε την έγκριση διαχειριστή για συμμετοχή σε αυτήν την ομάδα. Πατήστε για αλλαγή.");
    WAY("Greek", "reset_link_you", "Επαναφέρατε τον σύνδεσμο πρόσκλησης της ομάδας");
    WAY("Greek", "settings_only_admins_edit_you", "Αλλάξατε τις ρυθμίσεις ώστε μόνο οι διαχειριστές να μπορούν να επεξεργαστούν τις ρυθμίσεις της ομάδας");
    WAY("Greek", "settings_all_edit_you", "Αλλάξατε τις ρυθμίσεις ώστε όλα τα μέλη να μπορούν να επεξεργαστούν τις ρυθμίσεις της ομάδας");
    WAY("Greek", "settings_only_admins_send_you", "Αλλάξατε τις ρυθμίσεις αυτής της ομάδας ώστε μόνο οι διαχειριστές να μπορούν να στέλνουν μηνύματα");
    WAY("Greek", "settings_only_admins_add_you", "Αλλάξατε τις ρυθμίσεις αυτής της ομάδας ώστε μόνο οι διαχειριστές να μπορούν να προσθέτουν άλλους.");
    WAY("Greek", "settings_all_add_you", "Αλλάξατε τις ρυθμίσεις αυτής της ομάδας ώστε όλα τα μέλη να μπορούν να προσθέτουν άλλους.");
    WAY("Greek", "settings_all_send_you", "Αλλάξατε τις ρυθμίσεις αυτής της ομάδας ώστε όλα τα μέλη να μπορούν να στέλνουν μηνύματα");
    WAY("Greek", "settings_all_invite_link_you", "Αλλάξατε τις ρυθμίσεις αυτής της ομάδας ώστε όλα τα μέλη να μπορούν να προσκαλούν με σύνδεσμο.");
    WAY("Greek", "settings_only_admins_invite_link_you", "Αλλάξατε τις ρυθμίσεις ώστε μόνο οι διαχειριστές να μπορούν να προσκαλούν με σύνδεσμο.");
    WAY("Greek", "disappear_on_you", "Ενεργοποιήσατε τα μηνύματα που εξαφανίζονται. Τα νέα μηνύματα θα εξαφανιστούν από αυτή τη συνομιλία {timer} μετά την αποστολή τους (εκτός από τα αποθηκευμένα). Πατήστε για αλλαγή.");
    WAY("Greek", "disappear_off_you", "Απενεργοποιήσατε τα μηνύματα που εξαφανίζονται. Πατήστε για αλλαγή.");
    WAY("Greek", "disappear_off2_you", "Απενεργοποιήσατε τα μηνύματα που εξαφανίζονται. Πατήστε για να μάθετε περισσότερα.");
    WAY("Greek", "update_timer_you", "Ενημερώσατε το χρονόμετρο μηνυμάτων. Τα νέα μηνύματα θα εξαφανιστούν από αυτή τη συνομιλία {timer} μετά την αποστολή τους (εκτός από τα αποθηκευμένα). Πατήστε για αλλαγή.");
    WAY("Greek", "update_timer2_you", "Ενημερώσατε το χρονόμετρο μηνυμάτων. Τα νέα μηνύματα θα εξαφανιστούν {timer} μετά την αποστολή τους (εκτός από τα αποθηκευμένα). Πατήστε για να μάθετε περισσότερα.");
    WAY("Greek", "voice_call_you", "Φωνητική κλήση. {1} • Συμμετείχατε");
    WAY("Greek", "video_call_you", "Βιντεοκλήση. {1} • Συμμετείχατε");
    WAY("Greek", "unit_sec", "δ");
    WAY("Greek", "unit_min", "λ");
    WAY("Greek", "unit_hr",  "ώ");

    // ── Gujarati — 2nd person (તમે, formal) ──────────────────────────────────
    WAY("Gujarati", "created_group_you", "તમે જૂથ \"{1}\" બનાવ્યું");
    WAY("Gujarati", "created_group_noname_you", "તમે આ જૂથ બનાવ્યું");
    WAY("Gujarati", "left_you", "તમે છોડી ગયા");
    WAY("Gujarati", "added_you", "તમે {1}ને ઉમેર્યા");
    WAY("Gujarati", "added_target_you", "{0}એ તમને ઉમેર્યા");
    WAY("Gujarati", "was_added_you", "તમે ઉમેરવામાં આવ્યા");
    WAY("Gujarati", "removed_you", "તમે {1}ને દૂર કર્યા");
    WAY("Gujarati", "removed_target_you", "{0}એ તમને દૂર કર્યા");
    WAY("Gujarati", "joined_link_you", "તમે જૂથ લિંકનો ઉપયોગ કરીને જોડાયા.");
    WAY("Gujarati", "changed_icon_you", "તમે જૂથનું આઇકન બદલ્યું");
    WAY("Gujarati", "changed_name_you", "તમે જૂથનું નામ \"{1}\" કર્યું");
    WAY("Gujarati", "changed_name_from_to_you", "તમે જૂથનું નામ \"{1}\"થી \"{2}\" કર્યું");
    WAY("Gujarati", "changed_desc_you", "તમે જૂથનું વર્ણન બદલ્યું");
    WAY("Gujarati", "admin_approval_on_you", "તમે આ જૂથમાં જોડાવા માટે એડમિન મંજૂરી ચાલુ કરી. બદલવા માટે ટૅપ કરો.");
    WAY("Gujarati", "admin_approval_off_you", "તમે આ જૂથમાં જોડાવા માટે એડમિન મંજૂરી બંધ કરી. બદલવા માટે ટૅપ કરો.");
    WAY("Gujarati", "reset_link_you", "તમે જૂથની આમંત્રણ લિંક રીસેટ કરી");
    WAY("Gujarati", "settings_only_admins_edit_you", "તમે સેટિંગ્સ બદલી કે ફક્ત એડમિન જ જૂથ સેટિંગ્સ સંપાદિત કરી શકે");
    WAY("Gujarati", "settings_all_edit_you", "તમે સેટિંગ્સ બદલી કે બધા સભ્યો જૂથ સેટિંગ્સ સંપાદિત કરી શકે");
    WAY("Gujarati", "settings_only_admins_send_you", "તમે આ જૂથની સેટિંગ્સ બદલી કે ફક્ત એડમિન જ સંદેશા મોકલી શકે");
    WAY("Gujarati", "settings_only_admins_add_you", "તમે આ જૂથની સેટિંગ્સ બદલી કે ફક્ત એડમિન જ અન્યને ઉમેરી શકે.");
    WAY("Gujarati", "settings_all_add_you", "તમે આ જૂથની સેટિંગ્સ બદલી કે બધા સભ્યો અન્યને ઉમેરી શકે.");
    WAY("Gujarati", "settings_all_send_you", "તમે આ જૂથની સેટિંગ્સ બદલી કે બધા સભ્યો સંદેશા મોકલી શકે");
    WAY("Gujarati", "settings_all_invite_link_you", "તમે આ જૂથની સેટિંગ્સ બદલી કે બધા સભ્યો લિંકનો ઉપયોગ કરીને આમંત્રિત કરી શકે.");
    WAY("Gujarati", "settings_only_admins_invite_link_you", "તમે સેટિંગ્સ બદલી કે ફક્ત એડમિન જ લિંકનો ઉપયોગ કરીને આમંત્રિત કરી શકે.");
    WAY("Gujarati", "disappear_on_you", "તમે અદૃશ્ય થતા સંદેશાઓ ચાલુ કર્યા. નવા સંદેશાઓ મોકલ્યા પછી {timer} આ ચેટમાંથી અદૃશ્ય થઈ જશે (સાચવેલા સિવાય). બદલવા માટે ટૅપ કરો.");
    WAY("Gujarati", "disappear_off_you", "તમે અદૃશ્ય થતા સંદેશાઓ બંધ કર્યા. બદલવા માટે ટૅપ કરો.");
    WAY("Gujarati", "disappear_off2_you", "તમે અદૃશ્ય થતા સંદેશાઓ બંધ કર્યા. વધુ જાણવા માટે ટૅપ કરો.");
    WAY("Gujarati", "update_timer_you", "તમે સંદેશો ટાઇમર અપડેટ કર્યું. નવા સંદેશાઓ મોકલ્યા પછી {timer} આ ચેટમાંથી અદૃશ્ય થઈ જશે (સાચવેલા સિવાય). બદલવા માટે ટૅપ કરો.");
    WAY("Gujarati", "update_timer2_you", "તમે સંદેશો ટાઇમર અપડેટ કર્યું. નવા સંદેશાઓ {timer} પછી અદૃશ્ય થઈ જશે (સાચવેલા સિવાય). વધુ જાણવા માટે ટૅપ કરો.");
    WAY("Gujarati", "voice_call_you", "વૉઇસ કૉલ. {1} • તમે જોડાયા");
    WAY("Gujarati", "video_call_you", "વિડિયો કૉલ. {1} • તમે જોડાયા");
    WAY("Gujarati", "unit_sec", "સે");
    WAY("Gujarati", "unit_min", "મિ");
    WAY("Gujarati", "unit_hr",  "ક");

    // ── Hebrew — 2nd person (אתה/את) ─────────────────────────────────────────
    WAY("Hebrew", "created_group_you", "יצרת את הקבוצה \"{1}\"");
    WAY("Hebrew", "created_group_noname_you", "יצרת את הקבוצה הזו");
    WAY("Hebrew", "left_you", "עזבת");
    WAY("Hebrew", "added_you", "הוספת את {1}");
    WAY("Hebrew", "added_target_you", "{0} הוסיף/ה אותך");
    WAY("Hebrew", "was_added_you", "נוספת");
    WAY("Hebrew", "removed_you", "הסרת את {1}");
    WAY("Hebrew", "removed_target_you", "{0} הסיר/ה אותך");
    WAY("Hebrew", "joined_link_you", "הצטרפת באמצעות קישור לקבוצה.");
    WAY("Hebrew", "changed_icon_you", "שינית את סמל הקבוצה");
    WAY("Hebrew", "changed_name_you", "שינית את שם הקבוצה ל-\"{1}\"");
    WAY("Hebrew", "changed_name_from_to_you", "שינית את שם הקבוצה מ-\"{1}\" ל-\"{2}\"");
    WAY("Hebrew", "changed_desc_you", "שינית את תיאור הקבוצה");
    WAY("Hebrew", "admin_approval_on_you", "הפעלת אישור מנהל להצטרף לקבוצה זו. הקש כדי לשנות.");
    WAY("Hebrew", "admin_approval_off_you", "כיבית אישור מנהל להצטרף לקבוצה זו. הקש כדי לשנות.");
    WAY("Hebrew", "reset_link_you", "איפסת את קישור ההזמנה לקבוצה");
    WAY("Hebrew", "settings_only_admins_edit_you", "שינית הגדרות כך שרק מנהלים יכולים לערוך הגדרות קבוצה");
    WAY("Hebrew", "settings_all_edit_you", "שינית הגדרות כך שכל החברים יכולים לערוך הגדרות קבוצה");
    WAY("Hebrew", "settings_only_admins_send_you", "שינית את הגדרות הקבוצה כך שרק מנהלים יכולים לשלוח הודעות");
    WAY("Hebrew", "settings_only_admins_add_you", "שינית את הגדרות הקבוצה כך שרק מנהלים יכולים להוסיף אחרים.");
    WAY("Hebrew", "settings_all_add_you", "שינית את הגדרות הקבוצה כך שכל החברים יכולים להוסיף אחרים.");
    WAY("Hebrew", "settings_all_send_you", "שינית את הגדרות הקבוצה כך שכל החברים יכולים לשלוח הודעות");
    WAY("Hebrew", "settings_all_invite_link_you", "שינית את הגדרות הקבוצה כך שכל החברים יכולים להזמין באמצעות קישור.");
    WAY("Hebrew", "settings_only_admins_invite_link_you", "שינית הגדרות כך שרק מנהלים יכולים להזמין באמצעות קישור.");
    WAY("Hebrew", "disappear_on_you", "הפעלת הודעות נעלמות. הודעות חדשות ייעלמו מהצ'אט הזה {timer} לאחר שליחתן (מלבד שמורות). הקש לשינוי.");
    WAY("Hebrew", "disappear_off_you", "כיבית הודעות נעלמות. הקש לשינוי.");
    WAY("Hebrew", "disappear_off2_you", "כיבית הודעות נעלמות. הקש למידע נוסף.");
    WAY("Hebrew", "update_timer_you", "עדכנת את טיימר ההודעות. הודעות חדשות ייעלמו מהצ'אט הזה {timer} לאחר שליחתן (מלבד שמורות). הקש לשינוי.");
    WAY("Hebrew", "update_timer2_you", "עדכנת את טיימר ההודעות. הודעות חדשות ייעלמו {timer} לאחר שליחתן (מלבד שמורות). הקש למידע נוסף.");
    WAY("Hebrew", "voice_call_you", "שיחת קול. {1} • הצטרפת");
    WAY("Hebrew", "video_call_you", "שיחת וידאו. {1} • הצטרפת");
    WAY("Hebrew", "unit_sec", "שנ");
    WAY("Hebrew", "unit_min", "דק");
    WAY("Hebrew", "unit_hr",  "שע");

    // ── Hungarian — 2nd person (te) ──────────────────────────────────────────
    WAY("Hungarian", "created_group_you", "Létrehoztad a(z) \"{1}\" csoportot");
    WAY("Hungarian", "created_group_noname_you", "Létrehoztad ezt a csoportot");
    WAY("Hungarian", "left_you", "Kiléptél");
    WAY("Hungarian", "added_you", "Hozzáadtad: {1}");
    WAY("Hungarian", "added_target_you", "{0} hozzáadott téged");
    WAY("Hungarian", "was_added_you", "Hozzáadtak");
    WAY("Hungarian", "removed_you", "Eltávolítottad: {1}");
    WAY("Hungarian", "removed_target_you", "{0} eltávolított téged");
    WAY("Hungarian", "joined_link_you", "Csoportlinkkel csatlakoztál.");
    WAY("Hungarian", "changed_icon_you", "Megváltoztattad a csoport ikonját");
    WAY("Hungarian", "changed_name_you", "Megváltoztattad a csoport nevét erre: \"{1}\"");
    WAY("Hungarian", "changed_name_from_to_you", "Megváltoztattad a csoport nevét erről: \"{1}\" erre: \"{2}\"");
    WAY("Hungarian", "changed_desc_you", "Megváltoztattad a csoport leírását");
    WAY("Hungarian", "admin_approval_on_you", "Bekapcsoltad az admin jóváhagyást a csoporthoz való csatlakozáshoz. Koppints a módosításhoz.");
    WAY("Hungarian", "admin_approval_off_you", "Kikapcsoltad az admin jóváhagyást a csoporthoz való csatlakozáshoz. Koppints a módosításhoz.");
    WAY("Hungarian", "reset_link_you", "Visszaállítottad a csoport meghívó linkjét");
    WAY("Hungarian", "settings_only_admins_edit_you", "Módosítottad a beállításokat, hogy csak az adminok szerkeszthessék a csoport beállításait");
    WAY("Hungarian", "settings_all_edit_you", "Módosítottad a beállításokat, hogy minden tag szerkeszthesse a csoport beállításait");
    WAY("Hungarian", "settings_only_admins_send_you", "Módosítottad a csoport beállításait, hogy csak az adminok küldhessenek üzeneteket");
    WAY("Hungarian", "settings_only_admins_add_you", "Módosítottad a csoport beállításait, hogy csak az adminok adhassanak hozzá másokat.");
    WAY("Hungarian", "settings_all_add_you", "Módosítottad a csoport beállításait, hogy minden tag hozzáadhasson másokat.");
    WAY("Hungarian", "settings_all_send_you", "Módosítottad a csoport beállításait, hogy minden tag küldhessen üzeneteket");
    WAY("Hungarian", "settings_all_invite_link_you", "Módosítottad a csoport beállításait, hogy minden tag meghívhasson másokat csoportlinkkel.");
    WAY("Hungarian", "settings_only_admins_invite_link_you", "Módosítottad a beállításokat, hogy csak az adminok hívhassanak meg másokat csoportlinkkel.");
    WAY("Hungarian", "disappear_on_you", "Bekapcsoltad az eltűnő üzeneteket. Az új üzenetek {timer} múlva eltűnnek ebből a csevegésből (a mentettek kivételével). Koppints a módosításhoz.");
    WAY("Hungarian", "disappear_off_you", "Kikapcsoltad az eltűnő üzeneteket. Koppints a módosításhoz.");
    WAY("Hungarian", "disappear_off2_you", "Kikapcsoltad az eltűnő üzeneteket. Koppints további információért.");
    WAY("Hungarian", "update_timer_you", "Frissítetted az üzenet időzítőt. Az új üzenetek {timer} múlva eltűnnek ebből a csevegésből (a mentettek kivételével). Koppints a módosításhoz.");
    WAY("Hungarian", "update_timer2_you", "Frissítetted az üzenet időzítőt. Az új üzenetek {timer} múlva eltűnnek (a mentettek kivételével). Koppints további információért.");
    WAY("Hungarian", "voice_call_you", "Hanghívás. {1} • Csatlakoztál");
    WAY("Hungarian", "video_call_you", "Videóhívás. {1} • Csatlakoztál");
    WAY("Hungarian", "unit_sec", "mp");
    WAY("Hungarian", "unit_min", "p");
    WAY("Hungarian", "unit_hr",  "ó");

    // ── Indonesian — 2nd person (Anda) ───────────────────────────────────────
    WAY("Indonesian", "created_group_you", "Anda membuat grup \"{1}\"");
    WAY("Indonesian", "created_group_noname_you", "Anda membuat grup ini");
    WAY("Indonesian", "left_you", "Anda keluar");
    WAY("Indonesian", "added_you", "Anda menambahkan {1}");
    WAY("Indonesian", "added_target_you", "{0} menambahkan Anda");
    WAY("Indonesian", "was_added_you", "Anda ditambahkan");
    WAY("Indonesian", "removed_you", "Anda menghapus {1}");
    WAY("Indonesian", "removed_target_you", "{0} menghapus Anda");
    WAY("Indonesian", "joined_link_you", "Anda bergabung menggunakan tautan grup.");
    WAY("Indonesian", "changed_icon_you", "Anda mengubah ikon grup");
    WAY("Indonesian", "changed_name_you", "Anda mengubah nama grup menjadi \"{1}\"");
    WAY("Indonesian", "changed_name_from_to_you", "Anda mengubah nama grup dari \"{1}\" menjadi \"{2}\"");
    WAY("Indonesian", "changed_desc_you", "Anda mengubah deskripsi grup");
    WAY("Indonesian", "admin_approval_on_you", "Anda mengaktifkan persetujuan admin untuk bergabung ke grup ini. Ketuk untuk mengubah.");
    WAY("Indonesian", "admin_approval_off_you", "Anda menonaktifkan persetujuan admin untuk bergabung ke grup ini. Ketuk untuk mengubah.");
    WAY("Indonesian", "reset_link_you", "Anda mereset tautan undangan grup");
    WAY("Indonesian", "settings_only_admins_edit_you", "Anda mengubah setelan agar hanya admin yang dapat mengedit setelan grup");
    WAY("Indonesian", "settings_all_edit_you", "Anda mengubah setelan agar semua anggota dapat mengedit setelan grup");
    WAY("Indonesian", "settings_only_admins_send_you", "Anda mengubah setelan grup agar hanya admin yang dapat mengirim pesan");
    WAY("Indonesian", "settings_only_admins_add_you", "Anda mengubah setelan grup agar hanya admin yang dapat menambahkan orang lain.");
    WAY("Indonesian", "settings_all_add_you", "Anda mengubah setelan grup agar semua anggota dapat menambahkan orang lain.");
    WAY("Indonesian", "settings_all_send_you", "Anda mengubah setelan grup agar semua anggota dapat mengirim pesan");
    WAY("Indonesian", "settings_all_invite_link_you", "Anda mengubah setelan grup agar semua anggota dapat mengundang dengan tautan.");
    WAY("Indonesian", "settings_only_admins_invite_link_you", "Anda mengubah setelan agar hanya admin yang dapat mengundang dengan tautan.");
    WAY("Indonesian", "disappear_on_you", "Anda mengaktifkan pesan menghilang. Pesan baru akan menghilang dari obrolan ini {timer} setelah dikirim (kecuali yang disimpan). Ketuk untuk mengubah.");
    WAY("Indonesian", "disappear_off_you", "Anda menonaktifkan pesan menghilang. Ketuk untuk mengubah.");
    WAY("Indonesian", "disappear_off2_you", "Anda menonaktifkan pesan menghilang. Ketuk untuk info lebih lanjut.");
    WAY("Indonesian", "update_timer_you", "Anda memperbarui timer pesan. Pesan baru akan menghilang dari obrolan ini {timer} setelah dikirim (kecuali yang disimpan). Ketuk untuk mengubah.");
    WAY("Indonesian", "update_timer2_you", "Anda memperbarui timer pesan. Pesan baru akan menghilang {timer} setelah dikirim (kecuali yang disimpan). Ketuk untuk info lebih lanjut.");
    WAY("Indonesian", "voice_call_you", "Panggilan suara. {1} • Anda bergabung");
    WAY("Indonesian", "video_call_you", "Panggilan video. {1} • Anda bergabung");
    WAY("Indonesian", "unit_sec", "dtk");
    WAY("Indonesian", "unit_min", "mnt");
    WAY("Indonesian", "unit_hr",  "jam");

    // ── Irish — 2nd person (tú) ──────────────────────────────────────────────
    WAY("Irish", "created_group_you", "Chruthaigh tú grúpa \"{1}\"");
    WAY("Irish", "created_group_noname_you", "Chruthaigh tú an grúpa seo");
    WAY("Irish", "left_you", "D'fhág tú");
    WAY("Irish", "added_you", "Chuir tú {1} leis");
    WAY("Irish", "added_target_you", "Chuir {0} tú leis");
    WAY("Irish", "was_added_you", "Cuireadh tú leis");
    WAY("Irish", "removed_you", "Bhain tú {1}");
    WAY("Irish", "removed_target_you", "Bhain {0} thú");
    WAY("Irish", "joined_link_you", "D'úsáid tú nasc grúpa chun dul isteach.");
    WAY("Irish", "changed_icon_you", "D'athraigh tú deilbhín an ghrúpa");
    WAY("Irish", "changed_name_you", "D'athraigh tú ainm an ghrúpa go \"{1}\"");
    WAY("Irish", "changed_name_from_to_you", "D'athraigh tú ainm an ghrúpa ó \"{1}\" go \"{2}\"");
    WAY("Irish", "changed_desc_you", "D'athraigh tú tuairisc an ghrúpa");
    WAY("Irish", "admin_approval_on_you", "Chuir tú ceadú riarthóra ar siúl chun dul isteach sa ghrúpa seo. Tapáil chun athrú.");
    WAY("Irish", "admin_approval_off_you", "Chuir tú ceadú riarthóra as chun dul isteach sa ghrúpa seo. Tapáil chun athrú.");
    WAY("Irish", "reset_link_you", "D'athshocraigh tú nasc cuireadh an ghrúpa");
    WAY("Irish", "settings_only_admins_edit_you", "D'athraigh tú socruithe ionas nach féidir ach le riarthóirí socruithe an ghrúpa a chur in eagar");
    WAY("Irish", "settings_all_edit_you", "D'athraigh tú socruithe ionas gur féidir le gach ball socruithe an ghrúpa a chur in eagar");
    WAY("Irish", "settings_only_admins_send_you", "D'athraigh tú socruithe an ghrúpa ionas nach féidir ach le riarthóirí teachtaireachtaí a sheoladh");
    WAY("Irish", "settings_only_admins_add_you", "D'athraigh tú socruithe an ghrúpa ionas nach féidir ach le riarthóirí daoine eile a chur leis.");
    WAY("Irish", "settings_all_add_you", "D'athraigh tú socruithe an ghrúpa ionas gur féidir le gach ball daoine eile a chur leis.");
    WAY("Irish", "settings_all_send_you", "D'athraigh tú socruithe an ghrúpa ionas gur féidir le gach ball teachtaireachtaí a sheoladh");
    WAY("Irish", "settings_all_invite_link_you", "D'athraigh tú socruithe an ghrúpa ionas gur féidir le gach ball cuireadh a thabhairt le nasc.");
    WAY("Irish", "settings_only_admins_invite_link_you", "D'athraigh tú socruithe ionas nach féidir ach le riarthóirí cuireadh a thabhairt le nasc.");
    WAY("Irish", "disappear_on_you", "Chuir tú teachtaireachtaí atá ag imeacht ar siúl. Imeoidh teachtaireachtaí nua {timer} tar éis a seoladh ón gcomhrá seo (seachas cinn a sábháladh). Tapáil chun athrú.");
    WAY("Irish", "disappear_off_you", "Chuir tú teachtaireachtaí atá ag imeacht as. Tapáil chun athrú.");
    WAY("Irish", "disappear_off2_you", "Chuir tú teachtaireachtaí atá ag imeacht as. Tapáil le haghaidh tuilleadh eolais.");
    WAY("Irish", "update_timer_you", "D'nuashonraigh tú an t-amadóir teachtaireachtaí. Imeoidh teachtaireachtaí nua {timer} tar éis a seoladh ón gcomhrá seo (seachas cinn a sábháladh). Tapáil chun athrú.");
    WAY("Irish", "update_timer2_you", "D'nuashonraigh tú an t-amadóir teachtaireachtaí. Imeoidh teachtaireachtaí nua {timer} tar éis a seoladh (seachas cinn a sábháladh). Tapáil le haghaidh tuilleadh eolais.");
    WAY("Irish", "voice_call_you", "Glao gutha. {1} • Chuaigh tú isteach");
    WAY("Irish", "video_call_you", "Físghlao. {1} • Chuaigh tú isteach");
    WAY("Irish", "unit_sec", "s");
    WAY("Irish", "unit_min", "n");
    WAY("Irish", "unit_hr",  "u");

    // ── Kannada — 2nd person (ನೀವು) ──────────────────────────────────────────
    WAY("Kannada", "created_group_you", "ನೀವು ಗುಂಪು \"{1}\" ರಚಿಸಿದ್ದೀರಿ");
    WAY("Kannada", "created_group_noname_you", "ನೀವು ಈ ಗುಂಪನ್ನು ರಚಿಸಿದ್ದೀರಿ");
    WAY("Kannada", "left_you", "ನೀವು ತೊರೆದಿದ್ದೀರಿ");
    WAY("Kannada", "added_you", "ನೀವು {1} ಅನ್ನು ಸೇರಿಸಿದ್ದೀರಿ");
    WAY("Kannada", "added_target_you", "{0} ನಿಮ್ಮನ್ನು ಸೇರಿಸಿದ್ದಾರೆ");
    WAY("Kannada", "was_added_you", "ನೀವು ಸೇರಿಸಲಾಗಿದೆ");
    WAY("Kannada", "removed_you", "ನೀವು {1} ಅನ್ನು ತೆಗೆದುಹಾಕಿದ್ದೀರಿ");
    WAY("Kannada", "removed_target_you", "{0} ನಿಮ್ಮನ್ನು ತೆಗೆದುಹಾಕಿದ್ದಾರೆ");
    WAY("Kannada", "joined_link_you", "ನೀವು ಗುಂಪು ಲಿಂಕ್ ಬಳಸಿ ಸೇರಿದ್ದೀರಿ.");
    WAY("Kannada", "changed_icon_you", "ನೀವು ಗುಂಪಿನ ಐಕಾನ್ ಬದಲಾಯಿಸಿದ್ದೀರಿ");
    WAY("Kannada", "changed_name_you", "ನೀವು ಗುಂಪಿನ ಹೆಸರನ್ನು \"{1}\" ಗೆ ಬದಲಾಯಿಸಿದ್ದೀರಿ");
    WAY("Kannada", "changed_name_from_to_you", "ನೀವು ಗುಂಪಿನ ಹೆಸರನ್ನು \"{1}\" ನಿಂದ \"{2}\" ಗೆ ಬದಲಾಯಿಸಿದ್ದೀರಿ");
    WAY("Kannada", "changed_desc_you", "ನೀವು ಗುಂಪಿನ ವಿವರಣೆ ಬದಲಾಯಿಸಿದ್ದೀರಿ");
    WAY("Kannada", "admin_approval_on_you", "ನೀವು ಈ ಗುಂಪಿಗೆ ಸೇರಲು ಆಡ್ಮಿನ್ ಅನುಮೋದನೆಯನ್ನು ಆನ್ ಮಾಡಿದ್ದೀರಿ. ಬದಲಾಯಿಸಲು ಟ್ಯಾಪ್ ಮಾಡಿ.");
    WAY("Kannada", "admin_approval_off_you", "ನೀವು ಈ ಗುಂಪಿಗೆ ಸೇರಲು ಆಡ್ಮಿನ್ ಅನುಮೋದನೆಯನ್ನು ಆಫ್ ಮಾಡಿದ್ದೀರಿ. ಬದಲಾಯಿಸಲು ಟ್ಯಾಪ್ ಮಾಡಿ.");
    WAY("Kannada", "reset_link_you", "ನೀವು ಗುಂಪಿನ ಆಹ್ವಾನ ಲಿಂಕ್ ಮರುಹೊಂದಿಸಿದ್ದೀರಿ");
    WAY("Kannada", "settings_only_admins_edit_you", "ನೀವು ಆಡ್ಮಿನ್‌ಗಳು ಮಾತ್ರ ಗುಂಪು ಸೆಟ್ಟಿಂಗ್‌ಗಳನ್ನು ಎಡಿಟ್ ಮಾಡಲು ಸೆಟ್ಟಿಂಗ್‌ಗಳನ್ನು ಬದಲಾಯಿಸಿದ್ದೀರಿ");
    WAY("Kannada", "settings_all_edit_you", "ನೀವು ಎಲ್ಲಾ ಸದಸ್ಯರು ಗುಂಪು ಸೆಟ್ಟಿಂಗ್‌ಗಳನ್ನು ಎಡಿಟ್ ಮಾಡಲು ಸೆಟ್ಟಿಂಗ್‌ಗಳನ್ನು ಬದಲಾಯಿಸಿದ್ದೀರಿ");
    WAY("Kannada", "settings_only_admins_send_you", "ನೀವು ಆಡ್ಮಿನ್‌ಗಳು ಮಾತ್ರ ಸಂದೇಶಗಳನ್ನು ಕಳುಹಿಸಲು ಗುಂಪು ಸೆಟ್ಟಿಂಗ್‌ಗಳನ್ನು ಬದಲಾಯಿಸಿದ್ದೀರಿ");
    WAY("Kannada", "settings_only_admins_add_you", "ನೀವು ಆಡ್ಮಿನ್‌ಗಳು ಮಾತ್ರ ಇತರರನ್ನು ಸೇರಿಸಲು ಗುಂಪು ಸೆಟ್ಟಿಂಗ್‌ಗಳನ್ನು ಬದಲಾಯಿಸಿದ್ದೀರಿ.");
    WAY("Kannada", "settings_all_add_you", "ನೀವು ಎಲ್ಲಾ ಸದಸ್ಯರು ಇತರರನ್ನು ಸೇರಿಸಲು ಗುಂಪು ಸೆಟ್ಟಿಂಗ್‌ಗಳನ್ನು ಬದಲಾಯಿಸಿದ್ದೀರಿ.");
    WAY("Kannada", "settings_all_send_you", "ನೀವು ಎಲ್ಲಾ ಸದಸ್ಯರು ಸಂದೇಶಗಳನ್ನು ಕಳುಹಿಸಲು ಗುಂಪು ಸೆಟ್ಟಿಂಗ್‌ಗಳನ್ನು ಬದಲಾಯಿಸಿದ್ದೀರಿ");
    WAY("Kannada", "settings_all_invite_link_you", "ನೀವು ಎಲ್ಲಾ ಸದಸ್ಯರು ಲಿಂಕ್ ಬಳಸಿ ಆಹ್ವಾನಿಸಲು ಗುಂಪು ಸೆಟ್ಟಿಂಗ್‌ಗಳನ್ನು ಬದಲಾಯಿಸಿದ್ದೀರಿ.");
    WAY("Kannada", "settings_only_admins_invite_link_you", "ನೀವು ಆಡ್ಮಿನ್‌ಗಳು ಮಾತ್ರ ಲಿಂಕ್ ಬಳಸಿ ಆಹ್ವಾನಿಸಲು ಸೆಟ್ಟಿಂಗ್‌ಗಳನ್ನು ಬದಲಾಯಿಸಿದ್ದೀರಿ.");
    WAY("Kannada", "disappear_on_you", "ನೀವು ಕಣ್ಮರೆಯಾಗುವ ಸಂದೇಶಗಳನ್ನು ಆನ್ ಮಾಡಿದ್ದೀರಿ. ಹೊಸ ಸಂದೇಶಗಳು ಕಳುಹಿಸಿದ ನಂತರ {timer} ಈ ಚಾಟ್‌ನಿಂದ ಕಣ್ಮರೆಯಾಗುತ್ತವೆ (ಉಳಿಸಿದವುಗಳನ್ನು ಹೊರತುಪಡಿಸಿ). ಬದಲಾಯಿಸಲು ಟ್ಯಾಪ್ ಮಾಡಿ.");
    WAY("Kannada", "disappear_off_you", "ನೀವು ಕಣ್ಮರೆಯಾಗುವ ಸಂದೇಶಗಳನ್ನು ಆಫ್ ಮಾಡಿದ್ದೀರಿ. ಬದಲಾಯಿಸಲು ಟ್ಯಾಪ್ ಮಾಡಿ.");
    WAY("Kannada", "disappear_off2_you", "ನೀವು ಕಣ್ಮರೆಯಾಗುವ ಸಂದೇಶಗಳನ್ನು ಆಫ್ ಮಾಡಿದ್ದೀರಿ. ಹೆಚ್ಚಿನ ಮಾಹಿತಿಗಾಗಿ ಟ್ಯಾಪ್ ಮಾಡಿ.");
    WAY("Kannada", "update_timer_you", "ನೀವು ಸಂದೇಶ ಟೈಮರ್ ಅಪ್‌ಡೇಟ್ ಮಾಡಿದ್ದೀರಿ. ಹೊಸ ಸಂದೇಶಗಳು ಕಳುಹಿಸಿದ ನಂತರ {timer} ಈ ಚಾಟ್‌ನಿಂದ ಕಣ್ಮರೆಯಾಗುತ್ತವೆ (ಉಳಿಸಿದವುಗಳನ್ನು ಹೊರತುಪಡಿಸಿ). ಬದಲಾಯಿಸಲು ಟ್ಯಾಪ್ ಮಾಡಿ.");
    WAY("Kannada", "update_timer2_you", "ನೀವು ಸಂದೇಶ ಟೈಮರ್ ಅಪ್‌ಡೇಟ್ ಮಾಡಿದ್ದೀರಿ. ಹೊಸ ಸಂದೇಶಗಳು {timer} ನಂತರ ಕಣ್ಮರೆಯಾಗುತ್ತವೆ (ಉಳಿಸಿದವುಗಳನ್ನು ಹೊರತುಪಡಿಸಿ). ಹೆಚ್ಚಿನ ಮಾಹಿತಿಗಾಗಿ ಟ್ಯಾಪ್ ಮಾಡಿ.");
    WAY("Kannada", "voice_call_you", "ವಾಯ್ಸ್ ಕರೆ. {1} • ನೀವು ಸೇರಿದ್ದೀರಿ");
    WAY("Kannada", "video_call_you", "ವೀಡಿಯೊ ಕರೆ. {1} • ನೀವು ಸೇರಿದ್ದೀರಿ");
    WAY("Kannada", "unit_sec", "ಸೆ");
    WAY("Kannada", "unit_min", "ನಿ");
    WAY("Kannada", "unit_hr",  "ಗಂ");

    // ── Kazakh — 2nd person (сіз) ────────────────────────────────────────────
    WAY("Kazakh", "created_group_you", "Сіз \"{1}\" тобын құрдыңыз");
    WAY("Kazakh", "created_group_noname_you", "Сіз бұл топты құрдыңыз");
    WAY("Kazakh", "left_you", "Сіз шықтыңыз");
    WAY("Kazakh", "added_you", "Сіз {1} қостыңыз");
    WAY("Kazakh", "added_target_you", "{0} сізді қосты");
    WAY("Kazakh", "was_added_you", "Сіз қосылдыңыз");
    WAY("Kazakh", "removed_you", "Сіз {1} алып тастадыңыз");
    WAY("Kazakh", "removed_target_you", "{0} сізді алып тастады");
    WAY("Kazakh", "joined_link_you", "Сіз топ сілтемесін пайдаланып қосылдыңыз.");
    WAY("Kazakh", "changed_icon_you", "Сіз топ белгішесін өзгерттіңіз");
    WAY("Kazakh", "changed_name_you", "Сіз топ атын \"{1}\" деп өзгерттіңіз");
    WAY("Kazakh", "changed_name_from_to_you", "Сіз топ атын \"{1}\" деген атаудан \"{2}\" деп өзгерттіңіз");
    WAY("Kazakh", "changed_desc_you", "Сіз топ сипаттамасын өзгерттіңіз");
    WAY("Kazakh", "admin_approval_on_you", "Сіз бұл топқа қосылу үшін әкімшінің рұқсатын қостыңыз. Өзгерту үшін түртіңіз.");
    WAY("Kazakh", "admin_approval_off_you", "Сіз бұл топқа қосылу үшін әкімшінің рұқсатын өшірдіңіз. Өзгерту үшін түртіңіз.");
    WAY("Kazakh", "reset_link_you", "Сіз топ шақыру сілтемесін қалпына келтірдіңіз");
    WAY("Kazakh", "settings_only_admins_edit_you", "Сіз тек әкімшілер топ параметрлерін өңдей алады деп баптауларды өзгерттіңіз");
    WAY("Kazakh", "settings_all_edit_you", "Сіз барлық мүшелер топ параметрлерін өңдей алады деп баптауларды өзгерттіңіз");
    WAY("Kazakh", "settings_only_admins_send_you", "Сіз тек әкімшілер хабар жібере алады деп топ баптауларын өзгерттіңіз");
    WAY("Kazakh", "settings_only_admins_add_you", "Сіз тек әкімшілер басқаларды қоса алады деп топ баптауларын өзгерттіңіз.");
    WAY("Kazakh", "settings_all_add_you", "Сіз барлық мүшелер басқаларды қоса алады деп топ баптауларын өзгерттіңіз.");
    WAY("Kazakh", "settings_all_send_you", "Сіз барлық мүшелер хабар жібере алады деп топ баптауларын өзгерттіңіз");
    WAY("Kazakh", "settings_all_invite_link_you", "Сіз барлық мүшелер сілтеме арқылы шақыра алады деп топ баптауларын өзгерттіңіз.");
    WAY("Kazakh", "settings_only_admins_invite_link_you", "Сіз тек әкімшілер сілтеме арқылы шақыра алады деп баптауларды өзгерттіңіз.");
    WAY("Kazakh", "disappear_on_you", "Сіз жоғалып кететін хабарларды қостыңыз. Жаңа хабарлар жіберілгеннен кейін {timer} бұл чаттан жоғалады (сақталғандардан басқа). Өзгерту үшін түртіңіз.");
    WAY("Kazakh", "disappear_off_you", "Сіз жоғалып кететін хабарларды өшірдіңіз. Өзгерту үшін түртіңіз.");
    WAY("Kazakh", "disappear_off2_you", "Сіз жоғалып кететін хабарларды өшірдіңіз. Қосымша ақпарат алу үшін түртіңіз.");
    WAY("Kazakh", "update_timer_you", "Сіз хабар таймерін жаңарттыңыз. Жаңа хабарлар жіберілгеннен кейін {timer} бұл чаттан жоғалады (сақталғандардан басқа). Өзгерту үшін түртіңіз.");
    WAY("Kazakh", "update_timer2_you", "Сіз хабар таймерін жаңарттыңыз. Жаңа хабарлар {timer} кейін жоғалады (сақталғандардан басқа). Қосымша ақпарат алу үшін түртіңіз.");
    WAY("Kazakh", "voice_call_you", "Дауыстық қоңырау. {1} • Сіз қосылдыңыз");
    WAY("Kazakh", "video_call_you", "Бейне қоңырау. {1} • Сіз қосылдыңыз");
    WAY("Kazakh", "unit_sec", "с");
    WAY("Kazakh", "unit_min", "мин");
    WAY("Kazakh", "unit_hr",  "сағ");

    // ── Lao — 2nd person (ທ່ານ) ──────────────────────────────────────────────
    WAY("Lao", "created_group_you", "ທ່ານສ້າງກຸ່ມ \"{1}\"");
    WAY("Lao", "created_group_noname_you", "ທ່ານສ້າງກຸ່ມນີ້");
    WAY("Lao", "left_you", "ທ່ານອອກໄປແລ້ວ");
    WAY("Lao", "added_you", "ທ່ານເພີ່ມ {1}");
    WAY("Lao", "added_target_you", "{0} ເພີ່ມທ່ານ");
    WAY("Lao", "was_added_you", "ທ່ານຖືກເພີ່ມ");
    WAY("Lao", "removed_you", "ທ່ານລຶບ {1} ອອກ");
    WAY("Lao", "removed_target_you", "{0} ລຶບທ່ານອອກ");
    WAY("Lao", "joined_link_you", "ທ່ານເຂົ້າຮ່ວມໂດຍໃຊ້ລິ້ງກຸ່ມ.");
    WAY("Lao", "changed_icon_you", "ທ່ານປ່ຽນໄອຄອນກຸ່ມ");
    WAY("Lao", "changed_name_you", "ທ່ານປ່ຽນຊື່ກຸ່ມເປັນ \"{1}\"");
    WAY("Lao", "changed_name_from_to_you", "ທ່ານປ່ຽນຊື່ກຸ່ມຈາກ \"{1}\" ເປັນ \"{2}\"");
    WAY("Lao", "changed_desc_you", "ທ່ານປ່ຽນຄຳອະທິບາຍກຸ່ມ");
    WAY("Lao", "admin_approval_on_you", "ທ່ານເປີດການອະນຸມັດຂອງຜູ້ດູແລເພື່ອເຂົ້າຮ່ວມກຸ່ມນີ້. ແຕະເພື່ອປ່ຽນ.");
    WAY("Lao", "admin_approval_off_you", "ທ່ານປິດການອະນຸມັດຂອງຜູ້ດູແລເພື່ອເຂົ້າຮ່ວມກຸ່ມນີ້. ແຕະເພື່ອປ່ຽນ.");
    WAY("Lao", "reset_link_you", "ທ່ານຣີເຊັດລິ້ງເຊີນກຸ່ມ");
    WAY("Lao", "settings_only_admins_edit_you", "ທ່ານປ່ຽນການຕັ້ງຄ່າວ່າມີແຕ່ຜູ້ດູແລສາມາດແກ້ໄຂການຕັ້ງຄ່າກຸ່ມໄດ້");
    WAY("Lao", "settings_all_edit_you", "ທ່ານປ່ຽນການຕັ້ງຄ່າວ່າສະມາຊິກທຸກຄົນສາມາດແກ້ໄຂການຕັ້ງຄ່າກຸ່ມໄດ້");
    WAY("Lao", "settings_only_admins_send_you", "ທ່ານປ່ຽນການຕັ້ງຄ່າກຸ່ມວ່າມີແຕ່ຜູ້ດູແລສາມາດສົ່ງຂໍ້ຄວາມໄດ້");
    WAY("Lao", "settings_only_admins_add_you", "ທ່ານປ່ຽນການຕັ້ງຄ່າກຸ່ມວ່າມີແຕ່ຜູ້ດູແລສາມາດເພີ່ມຄົນອື່ນໄດ້.");
    WAY("Lao", "settings_all_add_you", "ທ່ານປ່ຽນການຕັ້ງຄ່າກຸ່ມວ່າສະມາຊິກທຸກຄົນສາມາດເພີ່ມຄົນອື່ນໄດ້.");
    WAY("Lao", "settings_all_send_you", "ທ່ານປ່ຽນການຕັ້ງຄ່າກຸ່ມວ່າສະມາຊິກທຸກຄົນສາມາດສົ່ງຂໍ້ຄວາມໄດ້");
    WAY("Lao", "settings_all_invite_link_you", "ທ່ານປ່ຽນການຕັ້ງຄ່າກຸ່ມວ່າສະມາຊິກທຸກຄົນສາມາດເຊີນດ້ວຍລິ້ງໄດ້.");
    WAY("Lao", "settings_only_admins_invite_link_you", "ທ່ານປ່ຽນການຕັ້ງຄ່າວ່າມີແຕ່ຜູ້ດູແລສາມາດເຊີນດ້ວຍລິ້ງໄດ້.");
    WAY("Lao", "disappear_on_you", "ທ່ານເປີດຂໍ້ຄວາມທີ່ຫາຍໄປ. ຂໍ້ຄວາມໃໝ່ຈະຫາຍໄປຈາກການສົນທະນານີ້ {timer} ຫຼັງຈາກສົ່ງ (ຍົກເວັ້ນທີ່ບັນທຶກໄວ້). ແຕະເພື່ອປ່ຽນ.");
    WAY("Lao", "disappear_off_you", "ທ່ານປິດຂໍ້ຄວາມທີ່ຫາຍໄປ. ແຕະເພື່ອປ່ຽນ.");
    WAY("Lao", "disappear_off2_you", "ທ່ານປິດຂໍ້ຄວາມທີ່ຫາຍໄປ. ແຕະສຳລັບຂໍ້ມູນເພີ່ມເຕີມ.");
    WAY("Lao", "update_timer_you", "ທ່ານອັບເດດໂມງນັບເວລາຂໍ້ຄວາມ. ຂໍ້ຄວາມໃໝ່ຈະຫາຍໄປຈາກການສົນທະນານີ້ {timer} ຫຼັງຈາກສົ່ງ (ຍົກເວັ້ນທີ່ບັນທຶກໄວ້). ແຕະເພື່ອປ່ຽນ.");
    WAY("Lao", "update_timer2_you", "ທ່ານອັບເດດໂມງນັບເວລາຂໍ້ຄວາມ. ຂໍ້ຄວາມໃໝ່ຈະຫາຍໄປ {timer} ຫຼັງຈາກສົ່ງ (ຍົກເວັ້ນທີ່ບັນທຶກໄວ້). ແຕະສຳລັບຂໍ້ມູນເພີ່ມເຕີມ.");
    WAY("Lao", "voice_call_you", "ການໂທສຽງ. {1} • ທ່ານເຂົ້າຮ່ວມ");
    WAY("Lao", "video_call_you", "ການໂທວິດີໂອ. {1} • ທ່ານເຂົ້າຮ່ວມ");
    WAY("Lao", "unit_sec", "ວິ");
    WAY("Lao", "unit_min", "ນທ");
    WAY("Lao", "unit_hr",  "ຊມ");

    // ── Latvian — 2nd person (jūs) ───────────────────────────────────────────
    WAY("Latvian", "created_group_you", "Jūs izveidojāt grupu \"{1}\"");
    WAY("Latvian", "created_group_noname_you", "Jūs izveidojāt šo grupu");
    WAY("Latvian", "left_you", "Jūs izgājāt");
    WAY("Latvian", "added_you", "Jūs pievienojāt {1}");
    WAY("Latvian", "added_target_you", "{0} pievienoja jūs");
    WAY("Latvian", "was_added_you", "Jūs tikāt pievienots");
    WAY("Latvian", "removed_you", "Jūs noņēmāt {1}");
    WAY("Latvian", "removed_target_you", "{0} noņēma jūs");
    WAY("Latvian", "joined_link_you", "Jūs pievienojāties, izmantojot grupas saiti.");
    WAY("Latvian", "changed_icon_you", "Jūs mainījāt grupas ikonu");
    WAY("Latvian", "changed_name_you", "Jūs mainījāt grupas nosaukumu uz \"{1}\"");
    WAY("Latvian", "changed_name_from_to_you", "Jūs mainījāt grupas nosaukumu no \"{1}\" uz \"{2}\"");
    WAY("Latvian", "changed_desc_you", "Jūs mainījāt grupas aprakstu");
    WAY("Latvian", "admin_approval_on_you", "Jūs ieslēdzāt administratora apstiprinājumu, lai pievienotos šai grupai. Pieskarieties, lai mainītu.");
    WAY("Latvian", "admin_approval_off_you", "Jūs izslēdzāt administratora apstiprinājumu, lai pievienotos šai grupai. Pieskarieties, lai mainītu.");
    WAY("Latvian", "reset_link_you", "Jūs atiestatījāt grupas uzaicinājuma saiti");
    WAY("Latvian", "settings_only_admins_edit_you", "Jūs mainījāt iestatījumus, lai tikai administratori varētu rediģēt grupas iestatījumus");
    WAY("Latvian", "settings_all_edit_you", "Jūs mainījāt iestatījumus, lai visi dalībnieki varētu rediģēt grupas iestatījumus");
    WAY("Latvian", "settings_only_admins_send_you", "Jūs mainījāt grupas iestatījumus, lai tikai administratori varētu sūtīt ziņojumus");
    WAY("Latvian", "settings_only_admins_add_you", "Jūs mainījāt grupas iestatījumus, lai tikai administratori varētu pievienot citus.");
    WAY("Latvian", "settings_all_add_you", "Jūs mainījāt grupas iestatījumus, lai visi dalībnieki varētu pievienot citus.");
    WAY("Latvian", "settings_all_send_you", "Jūs mainījāt grupas iestatījumus, lai visi dalībnieki varētu sūtīt ziņojumus");
    WAY("Latvian", "settings_all_invite_link_you", "Jūs mainījāt grupas iestatījumus, lai visi dalībnieki varētu uzaicināt ar saiti.");
    WAY("Latvian", "settings_only_admins_invite_link_you", "Jūs mainījāt iestatījumus, lai tikai administratori varētu uzaicināt ar saiti.");
    WAY("Latvian", "disappear_on_you", "Jūs ieslēdzāt pazūdošos ziņojumus. Jaunie ziņojumi pazudīs no šī čata {timer} pēc nosūtīšanas (izņemot saglabātos). Pieskarieties, lai mainītu.");
    WAY("Latvian", "disappear_off_you", "Jūs izslēdzāt pazūdošos ziņojumus. Pieskarieties, lai mainītu.");
    WAY("Latvian", "disappear_off2_you", "Jūs izslēdzāt pazūdošos ziņojumus. Pieskarieties, lai iegūtu vairāk informācijas.");
    WAY("Latvian", "update_timer_you", "Jūs atjauninājāt ziņojumu taimeri. Jaunie ziņojumi pazudīs no šī čata {timer} pēc nosūtīšanas (izņemot saglabātos). Pieskarieties, lai mainītu.");
    WAY("Latvian", "update_timer2_you", "Jūs atjauninājāt ziņojumu taimeri. Jaunie ziņojumi pazudīs {timer} pēc nosūtīšanas (izņemot saglabātos). Pieskarieties, lai iegūtu vairāk informācijas.");
    WAY("Latvian", "voice_call_you", "Balss zvans. {1} • Jūs pievienojāties");
    WAY("Latvian", "video_call_you", "Video zvans. {1} • Jūs pievienojāties");
    WAY("Latvian", "unit_sec", "s");
    WAY("Latvian", "unit_min", "min");
    WAY("Latvian", "unit_hr",  "h");

    // ── Lithuanian — 2nd person (jūs) ────────────────────────────────────────
    WAY("Lithuanian", "created_group_you", "Jūs sukūrėte grupę \"{1}\"");
    WAY("Lithuanian", "created_group_noname_you", "Jūs sukūrėte šią grupę");
    WAY("Lithuanian", "left_you", "Jūs išėjote");
    WAY("Lithuanian", "added_you", "Jūs pridėjote {1}");
    WAY("Lithuanian", "added_target_you", "{0} pridėjo jus");
    WAY("Lithuanian", "was_added_you", "Jūs buvote pridėtas");
    WAY("Lithuanian", "removed_you", "Jūs pašalinote {1}");
    WAY("Lithuanian", "removed_target_you", "{0} pašalino jus");
    WAY("Lithuanian", "joined_link_you", "Jūs prisijungėte naudodami grupės nuorodą.");
    WAY("Lithuanian", "changed_icon_you", "Jūs pakeitėte grupės piktogramą");
    WAY("Lithuanian", "changed_name_you", "Jūs pakeitėte grupės pavadinimą į \"{1}\"");
    WAY("Lithuanian", "changed_name_from_to_you", "Jūs pakeitėte grupės pavadinimą iš \"{1}\" į \"{2}\"");
    WAY("Lithuanian", "changed_desc_you", "Jūs pakeitėte grupės aprašymą");
    WAY("Lithuanian", "admin_approval_on_you", "Jūs įjungėte administratoriaus patvirtinimą prisijungti prie šios grupės. Bakstelėkite, kad pakeistumėte.");
    WAY("Lithuanian", "admin_approval_off_you", "Jūs išjungėte administratoriaus patvirtinimą prisijungti prie šios grupės. Bakstelėkite, kad pakeistumėte.");
    WAY("Lithuanian", "reset_link_you", "Jūs iš naujo nustatėte grupės kvietimo nuorodą");
    WAY("Lithuanian", "settings_only_admins_edit_you", "Jūs pakeitėte nustatymus, kad tik administratoriai galėtų redaguoti grupės nustatymus");
    WAY("Lithuanian", "settings_all_edit_you", "Jūs pakeitėte nustatymus, kad visi nariai galėtų redaguoti grupės nustatymus");
    WAY("Lithuanian", "settings_only_admins_send_you", "Jūs pakeitėte grupės nustatymus, kad tik administratoriai galėtų siųsti pranešimus");
    WAY("Lithuanian", "settings_only_admins_add_you", "Jūs pakeitėte grupės nustatymus, kad tik administratoriai galėtų pridėti kitus.");
    WAY("Lithuanian", "settings_all_add_you", "Jūs pakeitėte grupės nustatymus, kad visi nariai galėtų pridėti kitus.");
    WAY("Lithuanian", "settings_all_send_you", "Jūs pakeitėte grupės nustatymus, kad visi nariai galėtų siųsti pranešimus");
    WAY("Lithuanian", "settings_all_invite_link_you", "Jūs pakeitėte grupės nustatymus, kad visi nariai galėtų kviesti su nuoroda.");
    WAY("Lithuanian", "settings_only_admins_invite_link_you", "Jūs pakeitėte nustatymus, kad tik administratoriai galėtų kviesti su nuoroda.");
    WAY("Lithuanian", "disappear_on_you", "Jūs įjungėte nykstančius pranešimus. Nauji pranešimai išnyks iš šio pokalbio po {timer} nuo išsiuntimo (išskyrus išsaugotus). Bakstelėkite, kad pakeistumėte.");
    WAY("Lithuanian", "disappear_off_you", "Jūs išjungėte nykstančius pranešimus. Bakstelėkite, kad pakeistumėte.");
    WAY("Lithuanian", "disappear_off2_you", "Jūs išjungėte nykstančius pranešimus. Bakstelėkite, kad gautumėte daugiau informacijos.");
    WAY("Lithuanian", "update_timer_you", "Jūs atnaujinote pranešimų laikmatį. Nauji pranešimai išnyks iš šio pokalbio po {timer} nuo išsiuntimo (išskyrus išsaugotus). Bakstelėkite, kad pakeistumėte.");
    WAY("Lithuanian", "update_timer2_you", "Jūs atnaujinote pranešimų laikmatį. Nauji pranešimai išnyks po {timer} (išskyrus išsaugotus). Bakstelėkite, kad gautumėte daugiau informacijos.");
    WAY("Lithuanian", "voice_call_you", "Balso skambutis. {1} • Jūs prisijungėte");
    WAY("Lithuanian", "video_call_you", "Vaizdo skambutis. {1} • Jūs prisijungėte");
    WAY("Lithuanian", "unit_sec", "s");
    WAY("Lithuanian", "unit_min", "min");
    WAY("Lithuanian", "unit_hr",  "val");

    // ── Macedonian — 2nd person (вие) ────────────────────────────────────────
    WAY("Macedonian", "created_group_you", "Ја создадовте групата \"{1}\"");
    WAY("Macedonian", "created_group_noname_you", "Ја создадовте оваа група");
    WAY("Macedonian", "left_you", "Излеговте");
    WAY("Macedonian", "added_you", "Го додадовте {1}");
    WAY("Macedonian", "added_target_you", "{0} ве додаде");
    WAY("Macedonian", "was_added_you", "Бевте додадени");
    WAY("Macedonian", "removed_you", "Го отстранивте {1}");
    WAY("Macedonian", "removed_target_you", "{0} ве отстрани");
    WAY("Macedonian", "joined_link_you", "Се придруживте користејќи линк до група.");
    WAY("Macedonian", "changed_icon_you", "Ја промениве иконата на групата");
    WAY("Macedonian", "changed_name_you", "Го промениве името на групата во \"{1}\"");
    WAY("Macedonian", "changed_name_from_to_you", "Го промениве името на групата од \"{1}\" во \"{2}\"");
    WAY("Macedonian", "changed_desc_you", "Го промениве описот на групата");
    WAY("Macedonian", "admin_approval_on_you", "Вклучивте одобрување од администратор за да се придружите на оваа група. Допрете за да промените.");
    WAY("Macedonian", "admin_approval_off_you", "Исклучивте одобрување од администратор за да се придружите на оваа група. Допрете за да промените.");
    WAY("Macedonian", "reset_link_you", "Го ресетиравте линкот за покана до група");
    WAY("Macedonian", "settings_only_admins_edit_you", "Ги промениве поставките за само администраторите да можат да ги уредуваат поставките на групата");
    WAY("Macedonian", "settings_all_edit_you", "Ги промениве поставките за сите членови да можат да ги уредуваат поставките на групата");
    WAY("Macedonian", "settings_only_admins_send_you", "Ги промениве поставките на групата за само администраторите да можат да испраќаат пораки");
    WAY("Macedonian", "settings_only_admins_add_you", "Ги промениве поставките на групата за само администраторите да можат да додаваат други.");
    WAY("Macedonian", "settings_all_add_you", "Ги промениве поставките на групата за сите членови да можат да додаваат други.");
    WAY("Macedonian", "settings_all_send_you", "Ги промениве поставките на групата за сите членови да можат да испраќаат пораки");
    WAY("Macedonian", "settings_all_invite_link_you", "Ги промениве поставките на групата за сите членови да можат да поканат со линк.");
    WAY("Macedonian", "settings_only_admins_invite_link_you", "Ги промениве поставките за само администраторите да можат да поканат со линк.");
    WAY("Macedonian", "disappear_on_you", "Вклучивте исчезнувачки пораки. Новите пораки ќе исчезнат од овој разговор по {timer} од испраќањето (освен зачуваните). Допрете за да промените.");
    WAY("Macedonian", "disappear_off_you", "Исклучивте исчезнувачки пораки. Допрете за да промените.");
    WAY("Macedonian", "disappear_off2_you", "Исклучивте исчезнувачки пораки. Допрете за повеќе информации.");
    WAY("Macedonian", "update_timer_you", "Го ажуриравте тајмерот за пораки. Новите пораки ќе исчезнат од овој разговор по {timer} од испраќањето (освен зачуваните). Допрете за да промените.");
    WAY("Macedonian", "update_timer2_you", "Го ажуриравте тајмерот за пораки. Новите пораки ќе исчезнат по {timer} (освен зачуваните). Допрете за повеќе информации.");
    WAY("Macedonian", "voice_call_you", "Гласовен повик. {1} • Се придруживте");
    WAY("Macedonian", "video_call_you", "Видео повик. {1} • Се придруживте");
    WAY("Macedonian", "unit_sec", "сек");
    WAY("Macedonian", "unit_min", "мин");
    WAY("Macedonian", "unit_hr",  "час");

    // ── Malay — 2nd person (anda) ────────────────────────────────────────────
    WAY("Malay", "created_group_you", "Anda mencipta kumpulan \"{1}\"");
    WAY("Malay", "created_group_noname_you", "Anda mencipta kumpulan ini");
    WAY("Malay", "left_you", "Anda keluar");
    WAY("Malay", "added_you", "Anda menambahkan {1}");
    WAY("Malay", "added_target_you", "{0} menambahkan anda");
    WAY("Malay", "was_added_you", "Anda telah ditambahkan");
    WAY("Malay", "removed_you", "Anda mengalihkan {1}");
    WAY("Malay", "removed_target_you", "{0} mengalihkan anda");
    WAY("Malay", "joined_link_you", "Anda menyertai menggunakan pautan kumpulan.");
    WAY("Malay", "changed_icon_you", "Anda menukar ikon kumpulan");
    WAY("Malay", "changed_name_you", "Anda menukar nama kumpulan kepada \"{1}\"");
    WAY("Malay", "changed_name_from_to_you", "Anda menukar nama kumpulan daripada \"{1}\" kepada \"{2}\"");
    WAY("Malay", "changed_desc_you", "Anda menukar keterangan kumpulan");
    WAY("Malay", "admin_approval_on_you", "Anda menghidupkan kelulusan pentadbir untuk menyertai kumpulan ini. Ketik untuk menukar.");
    WAY("Malay", "admin_approval_off_you", "Anda mematikan kelulusan pentadbir untuk menyertai kumpulan ini. Ketik untuk menukar.");
    WAY("Malay", "reset_link_you", "Anda menetapkan semula pautan jemputan kumpulan");
    WAY("Malay", "settings_only_admins_edit_you", "Anda menukar tetapan supaya hanya pentadbir boleh mengedit maklumat kumpulan");
    WAY("Malay", "settings_all_edit_you", "Anda menukar tetapan supaya semua ahli boleh mengedit maklumat kumpulan");
    WAY("Malay", "settings_only_admins_send_you", "Anda menukar tetapan kumpulan supaya hanya pentadbir boleh menghantar mesej");
    WAY("Malay", "settings_only_admins_add_you", "Anda menukar tetapan kumpulan supaya hanya pentadbir boleh menambah orang lain.");
    WAY("Malay", "settings_all_add_you", "Anda menukar tetapan kumpulan supaya semua ahli boleh menambah orang lain.");
    WAY("Malay", "settings_all_send_you", "Anda menukar tetapan kumpulan supaya semua ahli boleh menghantar mesej");
    WAY("Malay", "settings_all_invite_link_you", "Anda menukar tetapan kumpulan supaya semua ahli boleh menjemput dengan pautan.");
    WAY("Malay", "settings_only_admins_invite_link_you", "Anda menukar tetapan supaya hanya pentadbir boleh menjemput dengan pautan.");
    WAY("Malay", "disappear_on_you", "Anda menghidupkan mesej lesap. Mesej baharu akan hilang dari sembang ini selepas {timer} dari dihantar (kecuali yang disimpan). Ketik untuk menukar.");
    WAY("Malay", "disappear_off_you", "Anda mematikan mesej lesap. Ketik untuk menukar.");
    WAY("Malay", "disappear_off2_you", "Anda mematikan mesej lesap. Ketik untuk maklumat lanjut.");
    WAY("Malay", "update_timer_you", "Anda mengemas kini pemasa mesej. Mesej baharu akan hilang dari sembang ini selepas {timer} dari dihantar (kecuali yang disimpan). Ketik untuk menukar.");
    WAY("Malay", "update_timer2_you", "Anda mengemas kini pemasa mesej. Mesej baharu akan hilang selepas {timer} (kecuali yang disimpan). Ketik untuk maklumat lanjut.");
    WAY("Malay", "voice_call_you", "Panggilan suara. {1} • Anda menyertai");
    WAY("Malay", "video_call_you", "Panggilan video. {1} • Anda menyertai");
    WAY("Malay", "unit_sec", "saat");
    WAY("Malay", "unit_min", "min");
    WAY("Malay", "unit_hr",  "jam");

    // ── Malayalam — 2nd person (നിങ്ങൾ) ──────────────────────────────────────
    WAY("Malayalam", "created_group_you", "നിങ്ങൾ \"{1}\" ഗ്രൂപ്പ് സൃഷ്ടിച്ചു");
    WAY("Malayalam", "created_group_noname_you", "നിങ്ങൾ ഈ ഗ്രൂപ്പ് സൃഷ്ടിച്ചു");
    WAY("Malayalam", "left_you", "നിങ്ങൾ പോയി");
    WAY("Malayalam", "added_you", "നിങ്ങൾ {1}-നെ ചേർത്തു");
    WAY("Malayalam", "added_target_you", "{0} നിങ്ങളെ ചേർത്തു");
    WAY("Malayalam", "was_added_you", "നിങ്ങളെ ചേർത്തു");
    WAY("Malayalam", "removed_you", "നിങ്ങൾ {1}-നെ നീക്കം ചെയ്തു");
    WAY("Malayalam", "removed_target_you", "{0} നിങ്ങളെ നീക്കം ചെയ്തു");
    WAY("Malayalam", "joined_link_you", "നിങ്ങൾ ഗ്രൂപ്പ് ലിങ്ക് ഉപയോഗിച്ച് ചേർന്നു.");
    WAY("Malayalam", "changed_icon_you", "നിങ്ങൾ ഗ്രൂപ്പ് ഐക്കൺ മാറ്റി");
    WAY("Malayalam", "changed_name_you", "നിങ്ങൾ ഗ്രൂപ്പ് പേര് \"{1}\" എന്നാക്കി മാറ്റി");
    WAY("Malayalam", "changed_name_from_to_you", "നിങ്ങൾ ഗ്രൂപ്പ് പേര് \"{1}\"-ൽ നിന്ന് \"{2}\"-ലേക്ക് മാറ്റി");
    WAY("Malayalam", "changed_desc_you", "നിങ്ങൾ ഗ്രൂപ്പ് വിവരണം മാറ്റി");
    WAY("Malayalam", "admin_approval_on_you", "നിങ്ങൾ ഈ ഗ്രൂപ്പിൽ ചേരാൻ അഡ്മിൻ അനുമതി ഓൺ ചെയ്തു. മാറ്റാൻ ടാപ്പ് ചെയ്യുക.");
    WAY("Malayalam", "admin_approval_off_you", "നിങ്ങൾ ഈ ഗ്രൂപ്പിൽ ചേരാൻ അഡ്മിൻ അനുമതി ഓഫ് ചെയ്തു. മാറ്റാൻ ടാപ്പ് ചെയ്യുക.");
    WAY("Malayalam", "reset_link_you", "നിങ്ങൾ ഗ്രൂപ്പ് ക്ഷണ ലിങ്ക് പുനഃസജ്ജമാക്കി");
    WAY("Malayalam", "settings_only_admins_edit_you", "നിങ്ങൾ ഗ്രൂപ്പ് വിവരങ്ങൾ എഡിറ്റ് ചെയ്യാൻ അഡ്മിൻമാർക്ക് മാത്രമേ കഴിയൂ എന്ന് ക്രമീകരണം മാറ്റി");
    WAY("Malayalam", "settings_all_edit_you", "നിങ്ങൾ ഗ്രൂപ്പ് വിവരങ്ങൾ എഡിറ്റ് ചെയ്യാൻ എല്ലാ അംഗങ്ങൾക്കും കഴിയും എന്ന് ക്രമീകരണം മാറ്റി");
    WAY("Malayalam", "settings_only_admins_send_you", "നിങ്ങൾ അഡ്മിൻമാർക്ക് മാത്രമേ സന്ദേശങ്ങൾ അയയ്ക്കാൻ കഴിയൂ എന്ന് ഗ്രൂപ്പ് ക്രമീകരണം മാറ്റി");
    WAY("Malayalam", "settings_only_admins_add_you", "നിങ്ങൾ മറ്റുള്ളവരെ ചേർക്കാൻ അഡ്മിൻമാർക്ക് മാത്രമേ കഴിയൂ എന്ന് ഗ്രൂപ്പ് ക്രമീകരണം മാറ്റി.");
    WAY("Malayalam", "settings_all_add_you", "നിങ്ങൾ മറ്റുള്ളവരെ ചേർക്കാൻ എല്ലാ അംഗങ്ങൾക്കും കഴിയും എന്ന് ഗ്രൂപ്പ് ക്രമീകരണം മാറ്റി.");
    WAY("Malayalam", "settings_all_send_you", "നിങ്ങൾ എല്ലാ അംഗങ്ങൾക്കും സന്ദേശങ്ങൾ അയയ്ക്കാൻ കഴിയും എന്ന് ഗ്രൂപ്പ് ക്രമീകരണം മാറ്റി");
    WAY("Malayalam", "settings_all_invite_link_you", "നിങ്ങൾ എല്ലാ അംഗങ്ങൾക്കും ലിങ്ക് വഴി ക്ഷണിക്കാൻ കഴിയും എന്ന് ഗ്രൂപ്പ് ക്രമീകരണം മാറ്റി.");
    WAY("Malayalam", "settings_only_admins_invite_link_you", "നിങ്ങൾ ലിങ്ക് വഴി ക്ഷണിക്കാൻ അഡ്മിൻമാർക്ക് മാത്രമേ കഴിയൂ എന്ന് ക്രമീകരണം മാറ്റി.");
    WAY("Malayalam", "disappear_on_you", "നിങ്ങൾ അപ്രത്യക്ഷമാകുന്ന സന്ദേശങ്ങൾ ഓൺ ചെയ്തു. പുതിയ സന്ദേശങ്ങൾ അയച്ച് {timer} കഴിഞ്ഞാൽ ഈ ചാറ്റിൽ നിന്ന് അപ്രത്യക്ഷമാകും (സംരക്ഷിച്ചവ ഒഴികെ). മാറ്റാൻ ടാപ്പ് ചെയ്യുക.");
    WAY("Malayalam", "disappear_off_you", "നിങ്ങൾ അപ്രത്യക്ഷമാകുന്ന സന്ദേശങ്ങൾ ഓഫ് ചെയ്തു. മാറ്റാൻ ടാപ്പ് ചെയ്യുക.");
    WAY("Malayalam", "disappear_off2_you", "നിങ്ങൾ അപ്രത്യക്ഷമാകുന്ന സന്ദേശങ്ങൾ ഓഫ് ചെയ്തു. കൂടുതൽ വിവരങ്ങൾക്ക് ടാപ്പ് ചെയ്യുക.");
    WAY("Malayalam", "update_timer_you", "നിങ്ങൾ സന്ദേശ ടൈമർ അപ്ഡേറ്റ് ചെയ്തു. പുതിയ സന്ദേശങ്ങൾ അയച്ച് {timer} കഴിഞ്ഞാൽ ഈ ചാറ്റിൽ നിന്ന് അപ്രത്യക്ഷമാകും (സംരക്ഷിച്ചവ ഒഴികെ). മാറ്റാൻ ടാപ്പ് ചെയ്യുക.");
    WAY("Malayalam", "update_timer2_you", "നിങ്ങൾ സന്ദേശ ടൈമർ അപ്ഡേറ്റ് ചെയ്തു. പുതിയ സന്ദേശങ്ങൾ {timer} കഴിഞ്ഞാൽ അപ്രത്യക്ഷമാകും (സംരക്ഷിച്ചവ ഒഴികെ). കൂടുതൽ വിവരങ്ങൾക്ക് ടാപ്പ് ചെയ്യുക.");
    WAY("Malayalam", "voice_call_you", "വോയ്‌സ് കോൾ. {1} • നിങ്ങൾ ചേർന്നു");
    WAY("Malayalam", "video_call_you", "വീഡിയോ കോൾ. {1} • നിങ്ങൾ ചേർന്നു");
    WAY("Malayalam", "unit_sec", "സെക്കൻഡ്");
    WAY("Malayalam", "unit_min", "മിനിറ്റ്");
    WAY("Malayalam", "unit_hr",  "മണിക്കൂർ");

    // ── Marathi — 2nd person (तुम्ही) ────────────────────────────────────────
    WAY("Marathi", "created_group_you", "तुम्ही \"{1}\" गट तयार केला");
    WAY("Marathi", "created_group_noname_you", "तुम्ही हा गट तयार केला");
    WAY("Marathi", "left_you", "तुम्ही बाहेर पडलात");
    WAY("Marathi", "added_you", "तुम्ही {1} ला जोडले");
    WAY("Marathi", "added_target_you", "{0} ने तुम्हाला जोडले");
    WAY("Marathi", "was_added_you", "तुम्हाला जोडले गेले");
    WAY("Marathi", "removed_you", "तुम्ही {1} ला काढले");
    WAY("Marathi", "removed_target_you", "{0} ने तुम्हाला काढले");
    WAY("Marathi", "joined_link_you", "तुम्ही गट लिंक वापरून सामील झालात.");
    WAY("Marathi", "changed_icon_you", "तुम्ही गट आयकॉन बदलला");
    WAY("Marathi", "changed_name_you", "तुम्ही गटाचे नाव \"{1}\" असे बदलले");
    WAY("Marathi", "changed_name_from_to_you", "तुम्ही गटाचे नाव \"{1}\" वरून \"{2}\" असे बदलले");
    WAY("Marathi", "changed_desc_you", "तुम्ही गट वर्णन बदलले");
    WAY("Marathi", "admin_approval_on_you", "तुम्ही या गटात सामील होण्यासाठी अॅडमिन मान्यता चालू केली. बदलण्यासाठी टॅप करा.");
    WAY("Marathi", "admin_approval_off_you", "तुम्ही या गटात सामील होण्यासाठी अॅडमिन मान्यता बंद केली. बदलण्यासाठी टॅप करा.");
    WAY("Marathi", "reset_link_you", "तुम्ही गट आमंत्रण लिंक रीसेट केली");
    WAY("Marathi", "settings_only_admins_edit_you", "तुम्ही गट माहिती संपादित करण्यासाठी फक्त अॅडमिन असे सेटिंग बदलले");
    WAY("Marathi", "settings_all_edit_you", "तुम्ही गट माहिती संपादित करण्यासाठी सर्व सदस्य असे सेटिंग बदलले");
    WAY("Marathi", "settings_only_admins_send_you", "तुम्ही संदेश पाठवण्यासाठी फक्त अॅडमिन असे गट सेटिंग बदलले");
    WAY("Marathi", "settings_only_admins_add_you", "तुम्ही इतरांना जोडण्यासाठी फक्त अॅडमिन असे गट सेटिंग बदलले.");
    WAY("Marathi", "settings_all_add_you", "तुम्ही इतरांना जोडण्यासाठी सर्व सदस्य असे गट सेटिंग बदलले.");
    WAY("Marathi", "settings_all_send_you", "तुम्ही संदेश पाठवण्यासाठी सर्व सदस्य असे गट सेटिंग बदलले");
    WAY("Marathi", "settings_all_invite_link_you", "तुम्ही लिंकद्वारे आमंत्रित करण्यासाठी सर्व सदस्य असे गट सेटिंग बदलले.");
    WAY("Marathi", "settings_only_admins_invite_link_you", "तुम्ही लिंकद्वारे आमंत्रित करण्यासाठी फक्त अॅडमिन असे सेटिंग बदलले.");
    WAY("Marathi", "disappear_on_you", "तुम्ही गायब होणारे संदेश चालू केले. पाठवल्यानंतर {timer} नंतर नवीन संदेश या चॅटमधून गायब होतील (जतन केलेले वगळता). बदलण्यासाठी टॅप करा.");
    WAY("Marathi", "disappear_off_you", "तुम्ही गायब होणारे संदेश बंद केले. बदलण्यासाठी टॅप करा.");
    WAY("Marathi", "disappear_off2_you", "तुम्ही गायब होणारे संदेश बंद केले. अधिक माहितीसाठी टॅप करा.");
    WAY("Marathi", "update_timer_you", "तुम्ही संदेश टाइमर अपडेट केला. पाठवल्यानंतर {timer} नंतर नवीन संदेश या चॅटमधून गायब होतील (जतन केलेले वगळता). बदलण्यासाठी टॅप करा.");
    WAY("Marathi", "update_timer2_you", "तुम्ही संदेश टाइमर अपडेट केला. {timer} नंतर नवीन संदेश गायब होतील (जतन केलेले वगळता). अधिक माहितीसाठी टॅप करा.");
    WAY("Marathi", "voice_call_you", "व्हॉइस कॉल. {1} • तुम्ही सामील झालात");
    WAY("Marathi", "video_call_you", "व्हिडिओ कॉल. {1} • तुम्ही सामील झालात");
    WAY("Marathi", "unit_sec", "से");
    WAY("Marathi", "unit_min", "मि");
    WAY("Marathi", "unit_hr",  "तास");

    // ── Norwegian — 2nd person (du) ──────────────────────────────────────────
    WAY("Norwegian", "created_group_you", "Du opprettet gruppen \"{1}\"");
    WAY("Norwegian", "created_group_noname_you", "Du opprettet denne gruppen");
    WAY("Norwegian", "left_you", "Du forlot");
    WAY("Norwegian", "added_you", "Du la til {1}");
    WAY("Norwegian", "added_target_you", "{0} la deg til");
    WAY("Norwegian", "was_added_you", "Du ble lagt til");
    WAY("Norwegian", "removed_you", "Du fjernet {1}");
    WAY("Norwegian", "removed_target_you", "{0} fjernet deg");
    WAY("Norwegian", "joined_link_you", "Du ble med via gruppelenke.");
    WAY("Norwegian", "changed_icon_you", "Du endret gruppeikonet");
    WAY("Norwegian", "changed_name_you", "Du endret gruppenavnet til \"{1}\"");
    WAY("Norwegian", "changed_name_from_to_you", "Du endret gruppenavnet fra \"{1}\" til \"{2}\"");
    WAY("Norwegian", "changed_desc_you", "Du endret gruppebeskrivelsen");
    WAY("Norwegian", "admin_approval_on_you", "Du slo på admin-godkjenning for å bli med i denne gruppen. Trykk for å endre.");
    WAY("Norwegian", "admin_approval_off_you", "Du slo av admin-godkjenning for å bli med i denne gruppen. Trykk for å endre.");
    WAY("Norwegian", "reset_link_you", "Du tilbakestilte gruppeinvitasjonslenken");
    WAY("Norwegian", "settings_only_admins_edit_you", "Du endret innstillingene til at bare adminer kan redigere gruppeinfo");
    WAY("Norwegian", "settings_all_edit_you", "Du endret innstillingene til at alle medlemmer kan redigere gruppeinfo");
    WAY("Norwegian", "settings_only_admins_send_you", "Du endret gruppeinnstillingene til at bare adminer kan sende meldinger");
    WAY("Norwegian", "settings_only_admins_add_you", "Du endret gruppeinnstillingene til at bare adminer kan legge til andre.");
    WAY("Norwegian", "settings_all_add_you", "Du endret gruppeinnstillingene til at alle medlemmer kan legge til andre.");
    WAY("Norwegian", "settings_all_send_you", "Du endret gruppeinnstillingene til at alle medlemmer kan sende meldinger");
    WAY("Norwegian", "settings_all_invite_link_you", "Du endret gruppeinnstillingene til at alle medlemmer kan invitere via lenke.");
    WAY("Norwegian", "settings_only_admins_invite_link_you", "Du endret innstillingene til at bare adminer kan invitere via lenke.");
    WAY("Norwegian", "disappear_on_you", "Du slo på forsvinnende meldinger. Nye meldinger vil forsvinne fra denne chatten etter {timer} fra de ble sendt (bortsett fra lagrede). Trykk for å endre.");
    WAY("Norwegian", "disappear_off_you", "Du slo av forsvinnende meldinger. Trykk for å endre.");
    WAY("Norwegian", "disappear_off2_you", "Du slo av forsvinnende meldinger. Trykk for mer informasjon.");
    WAY("Norwegian", "update_timer_you", "Du oppdaterte meldingstimeren. Nye meldinger vil forsvinne fra denne chatten etter {timer} fra de ble sendt (bortsett fra lagrede). Trykk for å endre.");
    WAY("Norwegian", "update_timer2_you", "Du oppdaterte meldingstimeren. Nye meldinger vil forsvinne etter {timer} (bortsett fra lagrede). Trykk for mer informasjon.");
    WAY("Norwegian", "voice_call_you", "Taleanrop. {1} • Du ble med");
    WAY("Norwegian", "video_call_you", "Videoanrop. {1} • Du ble med");
    WAY("Norwegian", "unit_sec", "sek");
    WAY("Norwegian", "unit_min", "min");
    WAY("Norwegian", "unit_hr",  "t");

    // ── Persian — 2nd person (شما) ───────────────────────────────────────────
    WAY("Persian", "created_group_you", "شما گروه \"{1}\" را ایجاد کردید");
    WAY("Persian", "created_group_noname_you", "شما این گروه را ایجاد کردید");
    WAY("Persian", "left_you", "شما خارج شدید");
    WAY("Persian", "added_you", "شما {1} را اضافه کردید");
    WAY("Persian", "added_target_you", "{0} شما را اضافه کرد");
    WAY("Persian", "was_added_you", "شما اضافه شدید");
    WAY("Persian", "removed_you", "شما {1} را حذف کردید");
    WAY("Persian", "removed_target_you", "{0} شما را حذف کرد");
    WAY("Persian", "joined_link_you", "شما با استفاده از لینک گروه پیوستید.");
    WAY("Persian", "changed_icon_you", "شما آیکون گروه را تغییر دادید");
    WAY("Persian", "changed_name_you", "شما نام گروه را به \"{1}\" تغییر دادید");
    WAY("Persian", "changed_name_from_to_you", "شما نام گروه را از \"{1}\" به \"{2}\" تغییر دادید");
    WAY("Persian", "changed_desc_you", "شما توضیحات گروه را تغییر دادید");
    WAY("Persian", "admin_approval_on_you", "شما تأیید ادمین برای پیوستن به این گروه را روشن کردید. برای تغییر ضربه بزنید.");
    WAY("Persian", "admin_approval_off_you", "شما تأیید ادمین برای پیوستن به این گروه را خاموش کردید. برای تغییر ضربه بزنید.");
    WAY("Persian", "reset_link_you", "شما لینک دعوت گروه را بازنشانی کردید");
    WAY("Persian", "settings_only_admins_edit_you", "شما تنظیمات را به فقط ادمین‌ها می‌توانند اطلاعات گروه را ویرایش کنند تغییر دادید");
    WAY("Persian", "settings_all_edit_you", "شما تنظیمات را به همه اعضا می‌توانند اطلاعات گروه را ویرایش کنند تغییر دادید");
    WAY("Persian", "settings_only_admins_send_you", "شما تنظیمات گروه را به فقط ادمین‌ها می‌توانند پیام ارسال کنند تغییر دادید");
    WAY("Persian", "settings_only_admins_add_you", "شما تنظیمات گروه را به فقط ادمین‌ها می‌توانند دیگران را اضافه کنند تغییر دادید.");
    WAY("Persian", "settings_all_add_you", "شما تنظیمات گروه را به همه اعضا می‌توانند دیگران را اضافه کنند تغییر دادید.");
    WAY("Persian", "settings_all_send_you", "شما تنظیمات گروه را به همه اعضا می‌توانند پیام ارسال کنند تغییر دادید");
    WAY("Persian", "settings_all_invite_link_you", "شما تنظیمات گروه را به همه اعضا می‌توانند با لینک دعوت کنند تغییر دادید.");
    WAY("Persian", "settings_only_admins_invite_link_you", "شما تنظیمات را به فقط ادمین‌ها می‌توانند با لینک دعوت کنند تغییر دادید.");
    WAY("Persian", "disappear_on_you", "شما پیام‌های ناپدیدشونده را روشن کردید. پیام‌های جدید {timer} پس از ارسال از این چت ناپدید خواهند شد (به جز ذخیره شده‌ها). برای تغییر ضربه بزنید.");
    WAY("Persian", "disappear_off_you", "شما پیام‌های ناپدیدشونده را خاموش کردید. برای تغییر ضربه بزنید.");
    WAY("Persian", "disappear_off2_you", "شما پیام‌های ناپدیدشونده را خاموش کردید. برای اطلاعات بیشتر ضربه بزنید.");
    WAY("Persian", "update_timer_you", "شما تایمر پیام را به‌روزرسانی کردید. پیام‌های جدید {timer} پس از ارسال از این چت ناپدید خواهند شد (به جز ذخیره شده‌ها). برای تغییر ضربه بزنید.");
    WAY("Persian", "update_timer2_you", "شما تایمر پیام را به‌روزرسانی کردید. پیام‌های جدید {timer} پس از ارسال ناپدید خواهند شد (به جز ذخیره شده‌ها). برای اطلاعات بیشتر ضربه بزنید.");
    WAY("Persian", "voice_call_you", "تماس صوتی. {1} • شما پیوستید");
    WAY("Persian", "video_call_you", "تماس تصویری. {1} • شما پیوستید");
    WAY("Persian", "unit_sec", "ثانیه");
    WAY("Persian", "unit_min", "دقیقه");
    WAY("Persian", "unit_hr",  "ساعت");

    // ── PortugueseBrazil — 2nd person (você) ─────────────────────────────────
    WAY("PortugueseBrazil", "created_group_you", "Você criou o grupo \"{1}\"");
    WAY("PortugueseBrazil", "created_group_noname_you", "Você criou este grupo");
    WAY("PortugueseBrazil", "left_you", "Você saiu");
    WAY("PortugueseBrazil", "added_you", "Você adicionou {1}");
    WAY("PortugueseBrazil", "added_target_you", "{0} adicionou você");
    WAY("PortugueseBrazil", "was_added_you", "Você foi adicionado");
    WAY("PortugueseBrazil", "removed_you", "Você removeu {1}");
    WAY("PortugueseBrazil", "removed_target_you", "{0} removeu você");
    WAY("PortugueseBrazil", "joined_link_you", "Você entrou usando o link do grupo.");
    WAY("PortugueseBrazil", "changed_icon_you", "Você alterou o ícone do grupo");
    WAY("PortugueseBrazil", "changed_name_you", "Você alterou o nome do grupo para \"{1}\"");
    WAY("PortugueseBrazil", "changed_name_from_to_you", "Você alterou o nome do grupo de \"{1}\" para \"{2}\"");
    WAY("PortugueseBrazil", "changed_desc_you", "Você alterou a descrição do grupo");
    WAY("PortugueseBrazil", "admin_approval_on_you", "Você ativou a aprovação do administrador para entrar neste grupo. Toque para alterar.");
    WAY("PortugueseBrazil", "admin_approval_off_you", "Você desativou a aprovação do administrador para entrar neste grupo. Toque para alterar.");
    WAY("PortugueseBrazil", "reset_link_you", "Você redefiniu o link de convite do grupo");
    WAY("PortugueseBrazil", "settings_only_admins_edit_you", "Você alterou as configurações para que apenas administradores possam editar as informações do grupo");
    WAY("PortugueseBrazil", "settings_all_edit_you", "Você alterou as configurações para que todos os membros possam editar as informações do grupo");
    WAY("PortugueseBrazil", "settings_only_admins_send_you", "Você alterou as configurações do grupo para que apenas administradores possam enviar mensagens");
    WAY("PortugueseBrazil", "settings_only_admins_add_you", "Você alterou as configurações do grupo para que apenas administradores possam adicionar outros.");
    WAY("PortugueseBrazil", "settings_all_add_you", "Você alterou as configurações do grupo para que todos os membros possam adicionar outros.");
    WAY("PortugueseBrazil", "settings_all_send_you", "Você alterou as configurações do grupo para que todos os membros possam enviar mensagens");
    WAY("PortugueseBrazil", "settings_all_invite_link_you", "Você alterou as configurações do grupo para que todos os membros possam convidar via link.");
    WAY("PortugueseBrazil", "settings_only_admins_invite_link_you", "Você alterou as configurações para que apenas administradores possam convidar via link.");
    WAY("PortugueseBrazil", "disappear_on_you", "Você ativou as mensagens temporárias. Novas mensagens desaparecerão deste chat após {timer} do envio (exceto as salvas). Toque para alterar.");
    WAY("PortugueseBrazil", "disappear_off_you", "Você desativou as mensagens temporárias. Toque para alterar.");
    WAY("PortugueseBrazil", "disappear_off2_you", "Você desativou as mensagens temporárias. Toque para mais informações.");
    WAY("PortugueseBrazil", "update_timer_you", "Você atualizou o cronômetro de mensagens. Novas mensagens desaparecerão deste chat após {timer} do envio (exceto as salvas). Toque para alterar.");
    WAY("PortugueseBrazil", "update_timer2_you", "Você atualizou o cronômetro de mensagens. Novas mensagens desaparecerão após {timer} (exceto as salvas). Toque para mais informações.");
    WAY("PortugueseBrazil", "voice_call_you", "Chamada de voz. {1} • Você entrou");
    WAY("PortugueseBrazil", "video_call_you", "Chamada de vídeo. {1} • Você entrou");
    WAY("PortugueseBrazil", "unit_sec", "seg");
    WAY("PortugueseBrazil", "unit_min", "min");
    WAY("PortugueseBrazil", "unit_hr",  "h");

    // ── Punjabi — 2nd person (ਤੁਸੀਂ) ───────────────────────────────────────────
    WAY("Punjabi", "created_group_you", "ਤੁਸੀਂ \"{1}\" ਗਰੁੱਪ ਬਣਾਇਆ");
    WAY("Punjabi", "created_group_noname_you", "ਤੁਸੀਂ ਇਹ ਗਰੁੱਪ ਬਣਾਇਆ");
    WAY("Punjabi", "left_you", "ਤੁਸੀਂ ਛੱਡ ਗਏ");
    WAY("Punjabi", "added_you", "ਤੁਸੀਂ {1} ਨੂੰ ਜੋੜਿਆ");
    WAY("Punjabi", "added_target_you", "{0} ਨੇ ਤੁਹਾਨੂੰ ਜੋੜਿਆ");
    WAY("Punjabi", "was_added_you", "ਤੁਹਾਨੂੰ ਜੋੜਿਆ ਗਿਆ");
    WAY("Punjabi", "removed_you", "ਤੁਸੀਂ {1} ਨੂੰ ਹਟਾਇਆ");
    WAY("Punjabi", "removed_target_you", "{0} ਨੇ ਤੁਹਾਨੂੰ ਹਟਾਇਆ");
    WAY("Punjabi", "joined_link_you", "ਤੁਸੀਂ ਗਰੁੱਪ ਲਿੰਕ ਵਰਤ ਕੇ ਸ਼ਾਮਲ ਹੋਏ।");
    WAY("Punjabi", "changed_icon_you", "ਤੁਸੀਂ ਗਰੁੱਪ ਆਈਕਨ ਬਦਲਿਆ");
    WAY("Punjabi", "changed_name_you", "ਤੁਸੀਂ ਗਰੁੱਪ ਦਾ ਨਾਮ \"{1}\" ਵਿੱਚ ਬਦਲਿਆ");
    WAY("Punjabi", "changed_name_from_to_you", "ਤੁਸੀਂ ਗਰੁੱਪ ਦਾ ਨਾਮ \"{1}\" ਤੋਂ \"{2}\" ਵਿੱਚ ਬਦਲਿਆ");
    WAY("Punjabi", "changed_desc_you", "ਤੁਸੀਂ ਗਰੁੱਪ ਵੇਰਵਾ ਬਦਲਿਆ");
    WAY("Punjabi", "admin_approval_on_you", "ਤੁਸੀਂ ਇਸ ਗਰੁੱਪ ਵਿੱਚ ਸ਼ਾਮਲ ਹੋਣ ਲਈ ਐਡਮਿਨ ਮਨਜ਼ੂਰੀ ਚਾਲੂ ਕੀਤੀ। ਬਦਲਣ ਲਈ ਟੈਪ ਕਰੋ।");
    WAY("Punjabi", "admin_approval_off_you", "ਤੁਸੀਂ ਇਸ ਗਰੁੱਪ ਵਿੱਚ ਸ਼ਾਮਲ ਹੋਣ ਲਈ ਐਡਮਿਨ ਮਨਜ਼ੂਰੀ ਬੰਦ ਕੀਤੀ। ਬਦਲਣ ਲਈ ਟੈਪ ਕਰੋ।");
    WAY("Punjabi", "reset_link_you", "ਤੁਸੀਂ ਗਰੁੱਪ ਸੱਦਾ ਲਿੰਕ ਰੀਸੈੱਟ ਕੀਤੀ");
    WAY("Punjabi", "settings_only_admins_edit_you", "ਤੁਸੀਂ ਸੈਟਿੰਗਾਂ ਬਦਲੀਆਂ ਤਾਂ ਜੋ ਸਿਰਫ ਐਡਮਿਨ ਹੀ ਗਰੁੱਪ ਜਾਣਕਾਰੀ ਸੰਪਾਦਤ ਕਰ ਸਕਣ");
    WAY("Punjabi", "settings_all_edit_you", "ਤੁਸੀਂ ਸੈਟਿੰਗਾਂ ਬਦਲੀਆਂ ਤਾਂ ਜੋ ਸਾਰੇ ਮੈਂਬਰ ਗਰੁੱਪ ਜਾਣਕਾਰੀ ਸੰਪਾਦਤ ਕਰ ਸਕਣ");
    WAY("Punjabi", "settings_only_admins_send_you", "ਤੁਸੀਂ ਗਰੁੱਪ ਸੈਟਿੰਗਾਂ ਬਦਲੀਆਂ ਤਾਂ ਜੋ ਸਿਰਫ ਐਡਮਿਨ ਹੀ ਸੁਨੇਹੇ ਭੇਜ ਸਕਣ");
    WAY("Punjabi", "settings_only_admins_add_you", "ਤੁਸੀਂ ਗਰੁੱਪ ਸੈਟਿੰਗਾਂ ਬਦਲੀਆਂ ਤਾਂ ਜੋ ਸਿਰਫ ਐਡਮਿਨ ਹੀ ਹੋਰਾਂ ਨੂੰ ਜੋੜ ਸਕਣ।");
    WAY("Punjabi", "settings_all_add_you", "ਤੁਸੀਂ ਗਰੁੱਪ ਸੈਟਿੰਗਾਂ ਬਦਲੀਆਂ ਤਾਂ ਜੋ ਸਾਰੇ ਮੈਂਬਰ ਹੋਰਾਂ ਨੂੰ ਜੋੜ ਸਕਣ।");
    WAY("Punjabi", "settings_all_send_you", "ਤੁਸੀਂ ਗਰੁੱਪ ਸੈਟਿੰਗਾਂ ਬਦਲੀਆਂ ਤਾਂ ਜੋ ਸਾਰੇ ਮੈਂਬਰ ਸੁਨੇਹੇ ਭੇਜ ਸਕਣ");
    WAY("Punjabi", "settings_all_invite_link_you", "ਤੁਸੀਂ ਗਰੁੱਪ ਸੈਟਿੰਗਾਂ ਬਦਲੀਆਂ ਤਾਂ ਜੋ ਸਾਰੇ ਮੈਂਬਰ ਲਿੰਕ ਰਾਹੀਂ ਸੱਦਾ ਦੇ ਸਕਣ।");
    WAY("Punjabi", "settings_only_admins_invite_link_you", "ਤੁਸੀਂ ਸੈਟਿੰਗਾਂ ਬਦਲੀਆਂ ਤਾਂ ਜੋ ਸਿਰਫ ਐਡਮਿਨ ਹੀ ਲਿੰਕ ਰਾਹੀਂ ਸੱਦਾ ਦੇ ਸਕਣ।");
    WAY("Punjabi", "disappear_on_you", "ਤੁਸੀਂ ਗਾਇਬ ਹੋਣ ਵਾਲੇ ਸੁਨੇਹੇ ਚਾਲੂ ਕੀਤੇ। ਭੇਜੇ ਜਾਣ ਤੋਂ {timer} ਬਾਅਦ ਨਵੇਂ ਸੁਨੇਹੇ ਇਸ ਚੈਟ ਤੋਂ ਗਾਇਬ ਹੋ ਜਾਣਗੇ (ਸੇਵ ਕੀਤੇ ਨੂੰ ਛੱਡ ਕੇ)। ਬਦਲਣ ਲਈ ਟੈਪ ਕਰੋ।");
    WAY("Punjabi", "disappear_off_you", "ਤੁਸੀਂ ਗਾਇਬ ਹੋਣ ਵਾਲੇ ਸੁਨੇਹੇ ਬੰਦ ਕੀਤੇ। ਬਦਲਣ ਲਈ ਟੈਪ ਕਰੋ।");
    WAY("Punjabi", "disappear_off2_you", "ਤੁਸੀਂ ਗਾਇਬ ਹੋਣ ਵਾਲੇ ਸੁਨੇਹੇ ਬੰਦ ਕੀਤੇ। ਹੋਰ ਜਾਣਕਾਰੀ ਲਈ ਟੈਪ ਕਰੋ।");
    WAY("Punjabi", "update_timer_you", "ਤੁਸੀਂ ਸੁਨੇਹਾ ਟਾਈਮਰ ਅੱਪਡੇਟ ਕੀਤਾ। ਭੇਜੇ ਜਾਣ ਤੋਂ {timer} ਬਾਅਦ ਨਵੇਂ ਸੁਨੇਹੇ ਇਸ ਚੈਟ ਤੋਂ ਗਾਇਬ ਹੋ ਜਾਣਗੇ (ਸੇਵ ਕੀਤੇ ਨੂੰ ਛੱਡ ਕੇ)। ਬਦਲਣ ਲਈ ਟੈਪ ਕਰੋ।");
    WAY("Punjabi", "update_timer2_you", "ਤੁਸੀਂ ਸੁਨੇਹਾ ਟਾਈਮਰ ਅੱਪਡੇਟ ਕੀਤਾ। {timer} ਬਾਅਦ ਨਵੇਂ ਸੁਨੇਹੇ ਗਾਇਬ ਹੋ ਜਾਣਗੇ (ਸੇਵ ਕੀਤੇ ਨੂੰ ਛੱਡ ਕੇ)। ਹੋਰ ਜਾਣਕਾਰੀ ਲਈ ਟੈਪ ਕਰੋ।");
    WAY("Punjabi", "voice_call_you", "ਵੌਇਸ ਕਾਲ। {1} • ਤੁਸੀਂ ਸ਼ਾਮਲ ਹੋਏ");
    WAY("Punjabi", "video_call_you", "ਵੀਡੀਓ ਕਾਲ। {1} • ਤੁਸੀਂ ਸ਼ਾਮਲ ਹੋਏ");
    WAY("Punjabi", "unit_sec", "ਸੈਕਿੰਡ");
    WAY("Punjabi", "unit_min", "ਮਿੰਟ");
    WAY("Punjabi", "unit_hr",  "ਘੰਟਾ");

    // ── Romanian — 2nd person (tu) ───────────────────────────────────────────
    WAY("Romanian", "created_group_you", "Ai creat grupul \"{1}\"");
    WAY("Romanian", "created_group_noname_you", "Ai creat acest grup");
    WAY("Romanian", "left_you", "Ai ieșit");
    WAY("Romanian", "added_you", "L-ai adăugat pe {1}");
    WAY("Romanian", "added_target_you", "{0} te-a adăugat");
    WAY("Romanian", "was_added_you", "Ai fost adăugat");
    WAY("Romanian", "removed_you", "L-ai eliminat pe {1}");
    WAY("Romanian", "removed_target_you", "{0} te-a eliminat");
    WAY("Romanian", "joined_link_you", "Te-ai alăturat folosind linkul grupului.");
    WAY("Romanian", "changed_icon_you", "Ai schimbat pictograma grupului");
    WAY("Romanian", "changed_name_you", "Ai schimbat numele grupului în \"{1}\"");
    WAY("Romanian", "changed_name_from_to_you", "Ai schimbat numele grupului de la \"{1}\" la \"{2}\"");
    WAY("Romanian", "changed_desc_you", "Ai schimbat descrierea grupului");
    WAY("Romanian", "admin_approval_on_you", "Ai activat aprobarea administratorului pentru a te alătura acestui grup. Apasă pentru a schimba.");
    WAY("Romanian", "admin_approval_off_you", "Ai dezactivat aprobarea administratorului pentru a te alătura acestui grup. Apasă pentru a schimba.");
    WAY("Romanian", "reset_link_you", "Ai resetat linkul de invitație al grupului");
    WAY("Romanian", "settings_only_admins_edit_you", "Ai schimbat setările astfel încât doar administratorii să poată edita informațiile grupului");
    WAY("Romanian", "settings_all_edit_you", "Ai schimbat setările astfel încât toți membrii să poată edita informațiile grupului");
    WAY("Romanian", "settings_only_admins_send_you", "Ai schimbat setările grupului astfel încât doar administratorii să poată trimite mesaje");
    WAY("Romanian", "settings_only_admins_add_you", "Ai schimbat setările grupului astfel încât doar administratorii să poată adăuga alte persoane.");
    WAY("Romanian", "settings_all_add_you", "Ai schimbat setările grupului astfel încât toți membrii să poată adăuga alte persoane.");
    WAY("Romanian", "settings_all_send_you", "Ai schimbat setările grupului astfel încât toți membrii să poată trimite mesaje");
    WAY("Romanian", "settings_all_invite_link_you", "Ai schimbat setările grupului astfel încât toți membrii să poată invita prin link.");
    WAY("Romanian", "settings_only_admins_invite_link_you", "Ai schimbat setările astfel încât doar administratorii să poată invita prin link.");
    WAY("Romanian", "disappear_on_you", "Ai activat mesajele care dispar. Mesajele noi vor dispărea din acest chat după {timer} de la trimitere (cu excepția celor salvate). Apasă pentru a schimba.");
    WAY("Romanian", "disappear_off_you", "Ai dezactivat mesajele care dispar. Apasă pentru a schimba.");
    WAY("Romanian", "disappear_off2_you", "Ai dezactivat mesajele care dispar. Apasă pentru mai multe informații.");
    WAY("Romanian", "update_timer_you", "Ai actualizat cronometrul pentru mesaje. Mesajele noi vor dispărea din acest chat după {timer} de la trimitere (cu excepția celor salvate). Apasă pentru a schimba.");
    WAY("Romanian", "update_timer2_you", "Ai actualizat cronometrul pentru mesaje. Mesajele noi vor dispărea după {timer} (cu excepția celor salvate). Apasă pentru mai multe informații.");
    WAY("Romanian", "voice_call_you", "Apel vocal. {1} • Te-ai alăturat");
    WAY("Romanian", "video_call_you", "Apel video. {1} • Te-ai alăturat");
    WAY("Romanian", "unit_sec", "sec");
    WAY("Romanian", "unit_min", "min");
    WAY("Romanian", "unit_hr",  "h");

    // ── Serbian — 2nd person (ви) ────────────────────────────────────────────
    WAY("Serbian", "created_group_you", "Направили сте групу \"{1}\"");
    WAY("Serbian", "created_group_noname_you", "Направили сте ову групу");
    WAY("Serbian", "left_you", "Напустили сте");
    WAY("Serbian", "added_you", "Додали сте {1}");
    WAY("Serbian", "added_target_you", "{0} вас је додао");
    WAY("Serbian", "was_added_you", "Додати сте");
    WAY("Serbian", "removed_you", "Уклонили сте {1}");
    WAY("Serbian", "removed_target_you", "{0} вас је уклонио");
    WAY("Serbian", "joined_link_you", "Придружили сте се користећи линк групе.");
    WAY("Serbian", "changed_icon_you", "Променили сте икону групе");
    WAY("Serbian", "changed_name_you", "Променили сте име групе у \"{1}\"");
    WAY("Serbian", "changed_name_from_to_you", "Променили сте име групе са \"{1}\" у \"{2}\"");
    WAY("Serbian", "changed_desc_you", "Променили сте опис групе");
    WAY("Serbian", "admin_approval_on_you", "Укључили сте одобрење администратора за придруживање овој групи. Додирните да промените.");
    WAY("Serbian", "admin_approval_off_you", "Искључили сте одобрење администратора за придруживање овој групи. Додирните да промените.");
    WAY("Serbian", "reset_link_you", "Ресетовали сте линк за позивницу групе");
    WAY("Serbian", "settings_only_admins_edit_you", "Променили сте подешавања тако да само администратори могу да уређују информације о групи");
    WAY("Serbian", "settings_all_edit_you", "Променили сте подешавања тако да сви чланови могу да уређују информације о групи");
    WAY("Serbian", "settings_only_admins_send_you", "Променили сте подешавања групе тако да само администратори могу да шаљу поруке");
    WAY("Serbian", "settings_only_admins_add_you", "Променили сте подешавања групе тако да само администратори могу да додају друге.");
    WAY("Serbian", "settings_all_add_you", "Променили сте подешавања групе тако да сви чланови могу да додају друге.");
    WAY("Serbian", "settings_all_send_you", "Променили сте подешавања групе тако да сви чланови могу да шаљу поруке");
    WAY("Serbian", "settings_all_invite_link_you", "Променили сте подешавања групе тако да сви чланови могу да позивају преко линка.");
    WAY("Serbian", "settings_only_admins_invite_link_you", "Променили сте подешавања тако да само администратори могу да позивају преко линка.");
    WAY("Serbian", "disappear_on_you", "Укључили сте нестајуће поруке. Нове поруке ће нестати из овог ћаскања након {timer} од слања (осим сачуваних). Додирните да промените.");
    WAY("Serbian", "disappear_off_you", "Искључили сте нестајуће поруке. Додирните да промените.");
    WAY("Serbian", "disappear_off2_you", "Искључили сте нестајуће поруке. Додирните за више информација.");
    WAY("Serbian", "update_timer_you", "Ажурирали сте тајмер за поруке. Нове поруке ће нестати из овог ћаскања након {timer} од слања (осим сачуваних). Додирните да промените.");
    WAY("Serbian", "update_timer2_you", "Ажурирали сте тајмер за поруке. Нове поруке ће нестати након {timer} (осим сачуваних). Додирните за више информација.");
    WAY("Serbian", "voice_call_you", "Гласовни позив. {1} • Придружили сте се");
    WAY("Serbian", "video_call_you", "Видео позив. {1} • Придружили сте се");
    WAY("Serbian", "unit_sec", "сек");
    WAY("Serbian", "unit_min", "мин");
    WAY("Serbian", "unit_hr",  "сат");

    // ── Slovak — 2nd person (ty) ─────────────────────────────────────────────
    WAY("Slovak", "created_group_you", "Vytvorili ste skupinu \"{1}\"");
    WAY("Slovak", "created_group_noname_you", "Vytvorili ste túto skupinu");
    WAY("Slovak", "left_you", "Odišli ste");
    WAY("Slovak", "added_you", "Pridali ste {1}");
    WAY("Slovak", "added_target_you", "{0} vás pridal");
    WAY("Slovak", "was_added_you", "Boli ste pridaný");
    WAY("Slovak", "removed_you", "Odstránili ste {1}");
    WAY("Slovak", "removed_target_you", "{0} vás odstránil");
    WAY("Slovak", "joined_link_you", "Pripojili ste sa pomocou odkazu skupiny.");
    WAY("Slovak", "changed_icon_you", "Zmenili ste ikonu skupiny");
    WAY("Slovak", "changed_name_you", "Zmenili ste názov skupiny na \"{1}\"");
    WAY("Slovak", "changed_name_from_to_you", "Zmenili ste názov skupiny z \"{1}\" na \"{2}\"");
    WAY("Slovak", "changed_desc_you", "Zmenili ste popis skupiny");
    WAY("Slovak", "admin_approval_on_you", "Zapli ste schválenie správcom pre pripojenie do tejto skupiny. Ťuknutím zmeníte.");
    WAY("Slovak", "admin_approval_off_you", "Vypli ste schválenie správcom pre pripojenie do tejto skupiny. Ťuknutím zmeníte.");
    WAY("Slovak", "reset_link_you", "Resetovali ste odkaz na pozvánku do skupiny");
    WAY("Slovak", "settings_only_admins_edit_you", "Zmenili ste nastavenia tak, aby len správcovia mohli upravovať informácie o skupine");
    WAY("Slovak", "settings_all_edit_you", "Zmenili ste nastavenia tak, aby všetci členovia mohli upravovať informácie o skupine");
    WAY("Slovak", "settings_only_admins_send_you", "Zmenili ste nastavenia skupiny tak, aby len správcovia mohli posielať správy");
    WAY("Slovak", "settings_only_admins_add_you", "Zmenili ste nastavenia skupiny tak, aby len správcovia mohli pridávať ďalších.");
    WAY("Slovak", "settings_all_add_you", "Zmenili ste nastavenia skupiny tak, aby všetci členovia mohli pridávať ďalších.");
    WAY("Slovak", "settings_all_send_you", "Zmenili ste nastavenia skupiny tak, aby všetci členovia mohli posielať správy");
    WAY("Slovak", "settings_all_invite_link_you", "Zmenili ste nastavenia skupiny tak, aby všetci členovia mohli pozývať odkazom.");
    WAY("Slovak", "settings_only_admins_invite_link_you", "Zmenili ste nastavenia tak, aby len správcovia mohli pozývať odkazom.");
    WAY("Slovak", "disappear_on_you", "Zapli ste miznúce správy. Nové správy zmiznú z tohto chatu po {timer} od odoslania (okrem uložených). Ťuknutím zmeníte.");
    WAY("Slovak", "disappear_off_you", "Vypli ste miznúce správy. Ťuknutím zmeníte.");
    WAY("Slovak", "disappear_off2_you", "Vypli ste miznúce správy. Ťuknutím získate viac informácií.");
    WAY("Slovak", "update_timer_you", "Aktualizovali ste časovač správ. Nové správy zmiznú z tohto chatu po {timer} od odoslania (okrem uložených). Ťuknutím zmeníte.");
    WAY("Slovak", "update_timer2_you", "Aktualizovali ste časovač správ. Nové správy zmiznú po {timer} (okrem uložených). Ťuknutím získate viac informácií.");
    WAY("Slovak", "voice_call_you", "Hlasový hovor. {1} • Pripojili ste sa");
    WAY("Slovak", "video_call_you", "Video hovor. {1} • Pripojili ste sa");
    WAY("Slovak", "unit_sec", "s");
    WAY("Slovak", "unit_min", "min");
    WAY("Slovak", "unit_hr",  "h");

    // ── Slovenian — 2nd person (ti) ──────────────────────────────────────────
    WAY("Slovenian", "created_group_you", "Ustvarili ste skupino \"{1}\"");
    WAY("Slovenian", "created_group_noname_you", "Ustvarili ste to skupino");
    WAY("Slovenian", "left_you", "Zapustili ste");
    WAY("Slovenian", "added_you", "Dodali ste {1}");
    WAY("Slovenian", "added_target_you", "{0} vas je dodal");
    WAY("Slovenian", "was_added_you", "Bili ste dodani");
    WAY("Slovenian", "removed_you", "Odstranili ste {1}");
    WAY("Slovenian", "removed_target_you", "{0} vas je odstranil");
    WAY("Slovenian", "joined_link_you", "Pridružili ste se z uporabo povezave skupine.");
    WAY("Slovenian", "changed_icon_you", "Spremenili ste ikono skupine");
    WAY("Slovenian", "changed_name_you", "Spremenili ste ime skupine v \"{1}\"");
    WAY("Slovenian", "changed_name_from_to_you", "Spremenili ste ime skupine iz \"{1}\" v \"{2}\"");
    WAY("Slovenian", "changed_desc_you", "Spremenili ste opis skupine");
    WAY("Slovenian", "admin_approval_on_you", "Vklopili ste odobritev skrbnika za pridružitev tej skupini. Tapnite za spremembo.");
    WAY("Slovenian", "admin_approval_off_you", "Izklopili ste odobritev skrbnika za pridružitev tej skupini. Tapnite za spremembo.");
    WAY("Slovenian", "reset_link_you", "Ponastavili ste povezavo povabila skupine");
    WAY("Slovenian", "settings_only_admins_edit_you", "Spremenili ste nastavitve, da lahko samo skrbniki urejajo informacije o skupini");
    WAY("Slovenian", "settings_all_edit_you", "Spremenili ste nastavitve, da lahko vsi člani urejajo informacije o skupini");
    WAY("Slovenian", "settings_only_admins_send_you", "Spremenili ste nastavitve skupine, da lahko samo skrbniki pošiljajo sporočila");
    WAY("Slovenian", "settings_only_admins_add_you", "Spremenili ste nastavitve skupine, da lahko samo skrbniki dodajajo druge.");
    WAY("Slovenian", "settings_all_add_you", "Spremenili ste nastavitve skupine, da lahko vsi člani dodajajo druge.");
    WAY("Slovenian", "settings_all_send_you", "Spremenili ste nastavitve skupine, da lahko vsi člani pošiljajo sporočila");
    WAY("Slovenian", "settings_all_invite_link_you", "Spremenili ste nastavitve skupine, da lahko vsi člani vabijo s povezavo.");
    WAY("Slovenian", "settings_only_admins_invite_link_you", "Spremenili ste nastavitve, da lahko samo skrbniki vabijo s povezavo.");
    WAY("Slovenian", "disappear_on_you", "Vklopili ste izginjajoča sporočila. Nova sporočila bodo izginila iz tega klepeta po {timer} od pošiljanja (razen shranjenih). Tapnite za spremembo.");
    WAY("Slovenian", "disappear_off_you", "Izklopili ste izginjajoča sporočila. Tapnite za spremembo.");
    WAY("Slovenian", "disappear_off2_you", "Izklopili ste izginjajoča sporočila. Tapnite za več informacij.");
    WAY("Slovenian", "update_timer_you", "Posodobili ste časovnik sporočil. Nova sporočila bodo izginila iz tega klepeta po {timer} od pošiljanja (razen shranjenih). Tapnite za spremembo.");
    WAY("Slovenian", "update_timer2_you", "Posodobili ste časovnik sporočil. Nova sporočila bodo izginila po {timer} (razen shranjenih). Tapnite za več informacij.");

    // ── Swahili — 2nd person (Wewe) ──────────────────────────────────────────
    WAY("Swahili", "created_group_you", "Wewe uliunda kikundi \"{1}\"");
    WAY("Swahili", "created_group_noname_you", "Wewe uliunda kikundi hiki");
    WAY("Swahili", "left_you", "Wewe uliondoka");
    WAY("Swahili", "added_you", "Wewe uliongeza {1}");
    WAY("Swahili", "added_target_you", "{0} alikuongeza wewe");
    WAY("Swahili", "was_added_you", "Wewe uliongezwa");
    WAY("Swahili", "removed_you", "Wewe uliondoa {1}");
    WAY("Swahili", "removed_target_you", "{0} alikuondoa wewe");
    WAY("Swahili", "joined_link_you", "Wewe ulijiunga kwa kutumia kiungo cha kikundi.");
    WAY("Swahili", "changed_icon_you", "Wewe ulibadilisha ikoni ya kikundi");
    WAY("Swahili", "changed_name_you", "Wewe ulibadilisha jina la kikundi kuwa \"{1}\"");
    WAY("Swahili", "changed_name_from_to_you", "Wewe ulibadilisha jina la kikundi kutoka \"{1}\" hadi \"{2}\"");
    WAY("Swahili", "changed_desc_you", "Wewe ulibadilisha maelezo ya kikundi");
    WAY("Swahili", "admin_approval_on_you", "Wewe uliwasha idhini ya msimamizi kujiunga na kikundi hiki. Gusa kubadilisha.");
    WAY("Swahili", "admin_approval_off_you", "Wewe ulizima idhini ya msimamizi kujiunga na kikundi hiki. Gusa kubadilisha.");
    WAY("Swahili", "reset_link_you", "Wewe ulirejesha kiungo cha mwaliko wa kikundi");
    WAY("Swahili", "settings_only_admins_edit_you", "Wewe ulibadilisha mipangilio ili wasimamizi pekee waweze kuhariri maelezo ya kikundi");
    WAY("Swahili", "settings_all_edit_you", "Wewe ulibadilisha mipangilio ili wanachama wote waweze kuhariri maelezo ya kikundi");
    WAY("Swahili", "settings_only_admins_send_you", "Wewe ulibadilisha mipangilio ya kikundi ili wasimamizi pekee waweze kutuma ujumbe");
    WAY("Swahili", "settings_only_admins_add_you", "Wewe ulibadilisha mipangilio ya kikundi ili wasimamizi pekee waweze kuongeza wengine.");
    WAY("Swahili", "settings_all_add_you", "Wewe ulibadilisha mipangilio ya kikundi ili wanachama wote waweze kuongeza wengine.");
    WAY("Swahili", "settings_all_send_you", "Wewe ulibadilisha mipangilio ya kikundi ili wanachama wote waweze kutuma ujumbe");
    WAY("Swahili", "settings_all_invite_link_you", "Wewe ulibadilisha mipangilio ya kikundi ili wanachama wote waweze kualika kwa kiungo.");
    WAY("Swahili", "settings_only_admins_invite_link_you", "Wewe ulibadilisha mipangilio ya kikundi ili wasimamizi pekee waweze kualika kwa kiungo.");
    WAY("Swahili", "disappear_on_you", "Wewe uliwasha ujumbe unaopotea. Ujumbe mpya utapotea kutoka kwenye mazungumzo haya baada ya {timer} kutoka unapotumwa (isipokuwa uliyohifadhiwa). Gusa kubadilisha.");
    WAY("Swahili", "disappear_off_you", "Wewe ulizima ujumbe unaopotea. Gusa kubadilisha.");
    WAY("Swahili", "disappear_off2_you", "Wewe ulizima ujumbe unaopotea. Gusa kwa maelezo zaidi.");
    WAY("Swahili", "update_timer_you", "Wewe uliosasisha muda wa ujumbe. Ujumbe mpya utapotea kutoka kwenye mazungumzo haya baada ya {timer} kutoka unapotumwa (isipokuwa uliyohifadhiwa). Gusa kubadilisha.");
    WAY("Swahili", "update_timer2_you", "Wewe uliosasisha muda wa ujumbe. Ujumbe mpya utapotea baada ya {timer} (isipokuwa uliyohifadhiwa). Gusa kwa maelezo zaidi.");

    // ── Swedish — 2nd person (Du) ────────────────────────────────────────────
    WAY("Swedish", "created_group_you", "Du skapade gruppen \"{1}\"");
    WAY("Swedish", "created_group_noname_you", "Du skapade denna grupp");
    WAY("Swedish", "left_you", "Du lämnade");
    WAY("Swedish", "added_you", "Du lade till {1}");
    WAY("Swedish", "added_target_you", "{0} lade till dig");
    WAY("Swedish", "was_added_you", "Du lades till");
    WAY("Swedish", "removed_you", "Du tog bort {1}");
    WAY("Swedish", "removed_target_you", "{0} tog bort dig");
    WAY("Swedish", "joined_link_you", "Du gick med via grupplänk.");
    WAY("Swedish", "changed_icon_you", "Du ändrade gruppikonen");
    WAY("Swedish", "changed_name_you", "Du ändrade gruppnamnet till \"{1}\"");
    WAY("Swedish", "changed_name_from_to_you", "Du ändrade gruppnamnet från \"{1}\" till \"{2}\"");
    WAY("Swedish", "changed_desc_you", "Du ändrade gruppbeskrivningen");
    WAY("Swedish", "admin_approval_on_you", "Du aktiverade administratörsgodkännande för att gå med i denna grupp. Tryck för att ändra.");
    WAY("Swedish", "admin_approval_off_you", "Du inaktiverade administratörsgodkännande för att gå med i denna grupp. Tryck för att ändra.");
    WAY("Swedish", "reset_link_you", "Du återställde gruppinbjudningslänken");
    WAY("Swedish", "settings_only_admins_edit_you", "Du ändrade inställningarna så att endast administratörer kan redigera gruppinformation");
    WAY("Swedish", "settings_all_edit_you", "Du ändrade inställningarna så att alla medlemmar kan redigera gruppinformation");
    WAY("Swedish", "settings_only_admins_send_you", "Du ändrade gruppinställningarna så att endast administratörer kan skicka meddelanden");
    WAY("Swedish", "settings_only_admins_add_you", "Du ändrade gruppinställningarna så att endast administratörer kan lägga till andra.");
    WAY("Swedish", "settings_all_add_you", "Du ändrade gruppinställningarna så att alla medlemmar kan lägga till andra.");
    WAY("Swedish", "settings_all_send_you", "Du ändrade gruppinställningarna så att alla medlemmar kan skicka meddelanden");
    WAY("Swedish", "settings_all_invite_link_you", "Du ändrade gruppinställningarna så att alla medlemmar kan bjuda in via länk.");
    WAY("Swedish", "settings_only_admins_invite_link_you", "Du ändrade gruppinställningarna så att endast administratörer kan bjuda in via länk.");
    WAY("Swedish", "disappear_on_you", "Du aktiverade försvinnande meddelanden. Nya meddelanden kommer att försvinna från denna chatt efter {timer} från när de skickas (förutom sparade). Tryck för att ändra.");
    WAY("Swedish", "disappear_off_you", "Du inaktiverade försvinnande meddelanden. Tryck för att ändra.");
    WAY("Swedish", "disappear_off2_you", "Du inaktiverade försvinnande meddelanden. Tryck för mer information.");
    WAY("Swedish", "update_timer_you", "Du uppdaterade meddelandetimern. Nya meddelanden kommer att försvinna från denna chatt efter {timer} från när de skickas (förutom sparade). Tryck för att ändra.");
    WAY("Swedish", "update_timer2_you", "Du uppdaterade meddelandetimern. Nya meddelanden kommer att försvinna efter {timer} (förutom sparade). Tryck för mer information.");

    // ── Tamil — 2nd person (நீங்கள்) ───────────────────────────────────────
    WAY("Tamil", "created_group_you", "நீங்கள் \"{1}\" குழுவை உருவாக்கினீர்கள்");
    WAY("Tamil", "created_group_noname_you", "நீங்கள் இந்தக் குழுவை உருவாக்கினீர்கள்");
    WAY("Tamil", "left_you", "நீங்கள் வெளியேறினீர்கள்");
    WAY("Tamil", "added_you", "நீங்கள் {1} ஐச் சேர்த்தீர்கள்");
    WAY("Tamil", "added_target_you", "{0} உங்களைச் சேர்த்தார்");
    WAY("Tamil", "was_added_you", "நீங்கள் சேர்க்கப்பட்டீர்கள்");
    WAY("Tamil", "removed_you", "நீங்கள் {1} ஐ நீக்கினீர்கள்");
    WAY("Tamil", "removed_target_you", "{0} உங்களை நீக்கினார்");
    WAY("Tamil", "joined_link_you", "நீங்கள் குழு இணைப்பைப் பயன்படுத்தி சேர்ந்தீர்கள்.");
    WAY("Tamil", "changed_icon_you", "நீங்கள் குழு ஐகானை மாற்றினீர்கள்");
    WAY("Tamil", "changed_name_you", "நீங்கள் குழுவின் பெயரை \"{1}\" என மாற்றினீர்கள்");
    WAY("Tamil", "changed_name_from_to_you", "நீங்கள் குழுவின் பெயரை \"{1}\" இலிருந்து \"{2}\" ஆக மாற்றினீர்கள்");
    WAY("Tamil", "changed_desc_you", "நீங்கள் குழு விவரத்தை மாற்றினீர்கள்");
    WAY("Tamil", "admin_approval_on_you", "நீங்கள் இந்தக் குழுவில் சேர நிர்வாகி ஒப்புதலை இயக்கினீர்கள். மாற்ற தட்டவும்.");
    WAY("Tamil", "admin_approval_off_you", "நீங்கள் இந்தக் குழுவில் சேர நிர்வாகி ஒப்புதலை முடக்கினீர்கள். மாற்ற தட்டவும்.");
    WAY("Tamil", "reset_link_you", "நீங்கள் குழு அழைப்பு இணைப்பை மீட்டமைத்தீர்கள்");
    WAY("Tamil", "settings_only_admins_edit_you", "நீங்கள் நிர்வாகிகள் மட்டுமே குழுத் தகவலைத் திருத்த முடியும் என அமைப்புகளை மாற்றினீர்கள்");
    WAY("Tamil", "settings_all_edit_you", "நீங்கள் அனைத்து உறுப்பினர்களும் குழுத் தகவலைத் திருத்த முடியும் என அமைப்புகளை மாற்றினீர்கள்");
    WAY("Tamil", "settings_only_admins_send_you", "நீங்கள் நிர்வாகிகள் மட்டுமே செய்திகளை அனுப்ப முடியும் என குழு அமைப்புகளை மாற்றினீர்கள்");
    WAY("Tamil", "settings_only_admins_add_you", "நீங்கள் நிர்வாகிகள் மட்டுமே மற்றவர்களைச் சேர்க்க முடியும் என குழு அமைப்புகளை மாற்றினீர்கள்.");
    WAY("Tamil", "settings_all_add_you", "நீங்கள் அனைத்து உறுப்பினர்களும் மற்றவர்களைச் சேர்க்க முடியும் என குழு அமைப்புகளை மாற்றினீர்கள்.");
    WAY("Tamil", "settings_all_send_you", "நீங்கள் அனைத்து உறுப்பினர்களும் செய்திகளை அனுப்ப முடியும் என குழு அமைப்புகளை மாற்றினீர்கள்");
    WAY("Tamil", "settings_all_invite_link_you", "நீங்கள் அனைத்து உறுப்பினர்களும் இணைப்பு மூலம் அழைக்க முடியும் என குழு அமைப்புகளை மாற்றினீர்கள்.");
    WAY("Tamil", "settings_only_admins_invite_link_you", "நீங்கள் நிர்வாகிகள் மட்டுமே இணைப்பு மூலம் அழைக்க முடியும் என குழு அமைப்புகளை மாற்றினீர்கள்.");
    WAY("Tamil", "disappear_on_you", "நீங்கள் மறையும் செய்திகளை இயக்கினீர்கள். புதிய செய்திகள் அனுப்பப்பட்ட {timer} க்குப் பிறகு இந்த அரட்டையிலிருந்து மறையும் (சேமிக்கப்பட்டவை தவிர). மாற்ற தட்டவும்.");
    WAY("Tamil", "disappear_off_you", "நீங்கள் மறையும் செய்திகளை முடக்கினீர்கள். மாற்ற தட்டவும்.");
    WAY("Tamil", "disappear_off2_you", "நீங்கள் மறையும் செய்திகளை முடக்கினீர்கள். மேலும் அறிய தட்டவும்.");
    WAY("Tamil", "update_timer_you", "நீங்கள் செய்தி டைமரை புதுப்பித்தீர்கள். புதிய செய்திகள் அனுப்பப்பட்ட {timer} க்குப் பிறகு இந்த அரட்டையிலிருந்து மறையும் (சேமிக்கப்பட்டவை தவிர). மாற்ற தட்டவும்.");
    WAY("Tamil", "update_timer2_you", "நீங்கள் செய்தி டைமரை புதுப்பித்தீர்கள். புதிய செய்திகள் {timer} க்குப் பிறகு மறையும் (சேமிக்கப்பட்டவை தவிர). மேலும் அறிய தட்டவும்.");

    // ── Telugu — 2nd person (మీరు) ───────────────────────────────────────────
    WAY("Telugu", "created_group_you", "మీరు \"{1}\" గ్రూప్‌ను సృష్టించారు");
    WAY("Telugu", "created_group_noname_you", "మీరు ఈ గ్రూప్‌ను సృష్టించారు");
    WAY("Telugu", "left_you", "మీరు నిష్క్రమించారు");
    WAY("Telugu", "added_you", "మీరు {1}ను జోడించారు");
    WAY("Telugu", "added_target_you", "{0} మిమ్మల్ని జోడించారు");
    WAY("Telugu", "was_added_you", "మీరు జోడించబడ్డారు");
    WAY("Telugu", "removed_you", "మీరు {1}ను తొలగించారు");
    WAY("Telugu", "removed_target_you", "{0} మిమ్మల్ని తొలగించారు");
    WAY("Telugu", "joined_link_you", "మీరు గ్రూప్ లింక్ ఉపయోగించి చేరారు.");
    WAY("Telugu", "changed_icon_you", "మీరు గ్రూప్ చిహ్నాన్ని మార్చారు");
    WAY("Telugu", "changed_name_you", "మీరు గ్రూప్ పేరును \"{1}\" గా మార్చారు");
    WAY("Telugu", "changed_name_from_to_you", "మీరు గ్రూప్ పేరును \"{1}\" నుండి \"{2}\" కి మార్చారు");
    WAY("Telugu", "changed_desc_you", "మీరు గ్రూప్ వివరణను మార్చారు");
    WAY("Telugu", "admin_approval_on_you", "మీరు ఈ గ్రూప్‌లో చేరడానికి అడ్మిన్ ఆమోదాన్ని ఆన్ చేశారు. మార్చడానికి ట్యాప్ చేయండి.");
    WAY("Telugu", "admin_approval_off_you", "మీరు ఈ గ్రూప్‌లో చేరడానికి అడ్మిన్ ఆమోదాన్ని ఆఫ్ చేశారు. మార్చడానికి ట్యాప్ చేయండి.");
    WAY("Telugu", "reset_link_you", "మీరు గ్రూప్ ఆహ్వాన లింక్‌ను రీసెట్ చేశారు");
    WAY("Telugu", "settings_only_admins_edit_you", "మీరు అడ్మిన్‌లు మాత్రమే గ్రూప్ సమాచారాన్ని సవరించగలరు అని సెట్టింగ్‌లను మార్చారు");
    WAY("Telugu", "settings_all_edit_you", "మీరు అందరు సభ్యులు గ్రూప్ సమాచారాన్ని సవరించగలరు అని సెట్టింగ్‌లను మార్చారు");
    WAY("Telugu", "settings_only_admins_send_you", "మీరు అడ్మిన్‌లు మాత్రమే సందేశాలు పంపగలరు అని గ్రూప్ సెట్టింగ్‌లను మార్చారు");
    WAY("Telugu", "settings_only_admins_add_you", "మీరు అడ్మిన్‌లు మాత్రమే ఇతరులను జోడించగలరు అని గ్రూప్ సెట్టింగ్‌లను మార్చారు.");
    WAY("Telugu", "settings_all_add_you", "మీరు అందరు సభ్యులు ఇతరులను జోడించగలరు అని గ్రూప్ సెట్టింగ్‌లను మార్చారు.");
    WAY("Telugu", "settings_all_send_you", "మీరు అందరు సభ్యులు సందేశాలు పంపగలరు అని గ్రూప్ సెట్టింగ్‌లను మార్చారు");
    WAY("Telugu", "settings_all_invite_link_you", "మీరు అందరు సభ్యులు లింక్ ద్వారా ఆహ్వానించగలరు అని గ్రూప్ సెట్టింగ్‌లను మార్చారు.");
    WAY("Telugu", "settings_only_admins_invite_link_you", "మీరు అడ్మిన్‌లు మాత్రమే లింక్ ద్వారా ఆహ్వానించగలరు అని గ్రూప్ సెట్టింగ్‌లను మార్చారు.");
    WAY("Telugu", "disappear_on_you", "మీరు అదృశ్యమయ్యే సందేశాలను ఆన్ చేశారు. కొత్త సందేశాలు పంపిన {timer} తర్వాత ఈ చాట్ నుండి అదృశ్యమవుతాయి (సేవ్ చేసినవి మినహా). మార్చడానికి ట్యాప్ చేయండి.");
    WAY("Telugu", "disappear_off_you", "మీరు అదృశ్యమయ్యే సందేశాలను ఆఫ్ చేశారు. మార్చడానికి ట్యాప్ చేయండి.");
    WAY("Telugu", "disappear_off2_you", "మీరు అదృశ్యమయ్యే సందేశాలను ఆఫ్ చేశారు. మరింత తెలుసుకోవడానికి ట్యాప్ చేయండి.");
    WAY("Telugu", "update_timer_you", "మీరు సందేశ టైమర్‌ను అప్‌డేట్ చేశారు. కొత్త సందేశాలు పంపిన {timer} తర్వాత ఈ చాట్ నుండి అదృశ్యమవుతాయి (సేవ్ చేసినవి మినహా). మార్చడానికి ట్యాప్ చేయండి.");
    WAY("Telugu", "update_timer2_you", "మీరు సందేశ టైమర్‌ను అప్‌డేట్ చేశారు. కొత్త సందేశాలు {timer} తర్వాత అదృశ్యమవుతాయి (సేవ్ చేసినవి మినహా). మరింత తెలుసుకోవడానికి ట్యాప్ చేయండి.");

    // ── Thai — 2nd person (คุณ) ──────────────────────────────────────────────
    WAY("Thai", "created_group_you", "คุณสร้างกลุ่ม \"{1}\"");
    WAY("Thai", "created_group_noname_you", "คุณสร้างกลุ่มนี้");
    WAY("Thai", "left_you", "คุณออกไปแล้ว");
    WAY("Thai", "added_you", "คุณเพิ่ม {1}");
    WAY("Thai", "added_target_you", "{0} เพิ่มคุณ");
    WAY("Thai", "was_added_you", "คุณถูกเพิ่ม");
    WAY("Thai", "removed_you", "คุณลบ {1}");
    WAY("Thai", "removed_target_you", "{0} ลบคุณ");
    WAY("Thai", "joined_link_you", "คุณเข้าร่วมโดยใช้ลิงก์กลุ่ม");
    WAY("Thai", "changed_icon_you", "คุณเปลี่ยนไอคอนกลุ่ม");
    WAY("Thai", "changed_name_you", "คุณเปลี่ยนชื่อกลุ่มเป็น \"{1}\"");
    WAY("Thai", "changed_name_from_to_you", "คุณเปลี่ยนชื่อกลุ่มจาก \"{1}\" เป็น \"{2}\"");
    WAY("Thai", "changed_desc_you", "คุณเปลี่ยนคำอธิบายกลุ่ม");
    WAY("Thai", "admin_approval_on_you", "คุณเปิดการอนุมัติของผู้ดูแลระบบเพื่อเข้าร่วมกลุ่มนี้ แตะเพื่อเปลี่ยน");
    WAY("Thai", "admin_approval_off_you", "คุณปิดการอนุมัติของผู้ดูแลระบบเพื่อเข้าร่วมกลุ่มนี้ แตะเพื่อเปลี่ยน");
    WAY("Thai", "reset_link_you", "คุณรีเซ็ตลิงก์เชิญเข้ากลุ่ม");
    WAY("Thai", "settings_only_admins_edit_you", "คุณเปลี่ยนการตั้งค่าให้เฉพาะผู้ดูแลระบบแก้ไขข้อมูลกลุ่มได้");
    WAY("Thai", "settings_all_edit_you", "คุณเปลี่ยนการตั้งค่าให้สมาชิกทุกคนแก้ไขข้อมูลกลุ่มได้");
    WAY("Thai", "settings_only_admins_send_you", "คุณเปลี่ยนการตั้งค่ากลุ่มให้เฉพาะผู้ดูแลระบบส่งข้อความได้");
    WAY("Thai", "settings_only_admins_add_you", "คุณเปลี่ยนการตั้งค่ากลุ่มให้เฉพาะผู้ดูแลระบบเพิ่มคนอื่นได้");
    WAY("Thai", "settings_all_add_you", "คุณเปลี่ยนการตั้งค่ากลุ่มให้สมาชิกทุกคนเพิ่มคนอื่นได้");
    WAY("Thai", "settings_all_send_you", "คุณเปลี่ยนการตั้งค่ากลุ่มให้สมาชิกทุกคนส่งข้อความได้");
    WAY("Thai", "settings_all_invite_link_you", "คุณเปลี่ยนการตั้งค่ากลุ่มให้สมาชิกทุกคนเชิญผ่านลิงก์ได้");
    WAY("Thai", "settings_only_admins_invite_link_you", "คุณเปลี่ยนการตั้งค่ากลุ่มให้เฉพาะผู้ดูแลระบบเชิญผ่านลิงก์ได้");
    WAY("Thai", "disappear_on_you", "คุณเปิดข้อความที่หายไป ข้อความใหม่จะหายไปจากแชทนี้หลังจาก {timer} นับจากที่ส่ง (ยกเว้นที่บันทึกไว้) แตะเพื่อเปลี่ยน");
    WAY("Thai", "disappear_off_you", "คุณปิดข้อความที่หายไป แตะเพื่อเปลี่ยน");
    WAY("Thai", "disappear_off2_you", "คุณปิดข้อความที่หายไป แตะเพื่อข้อมูลเพิ่มเติม");
    WAY("Thai", "update_timer_you", "คุณอัปเดตตัวจับเวลาข้อความ ข้อความใหม่จะหายไปจากแชทนี้หลังจาก {timer} นับจากที่ส่ง (ยกเว้นที่บันทึกไว้) แตะเพื่อเปลี่ยน");
    WAY("Thai", "update_timer2_you", "คุณอัปเดตตัวจับเวลาข้อความ ข้อความใหม่จะหายไปหลังจาก {timer} (ยกเว้นที่บันทึกไว้) แตะเพื่อข้อมูลเพิ่มเติม");

    // ── UrduPakistan — 2nd person (آپ) ───────────────────────────────────────
    WAY("UrduPakistan", "created_group_you", "آپ نے \"{1}\" گروپ بنایا");
    WAY("UrduPakistan", "created_group_noname_you", "آپ نے یہ گروپ بنایا");
    WAY("UrduPakistan", "left_you", "آپ نے چھوڑ دیا");
    WAY("UrduPakistan", "added_you", "آپ نے {1} کو شامل کیا");
    WAY("UrduPakistan", "added_target_you", "{0} نے آپ کو شامل کیا");
    WAY("UrduPakistan", "was_added_you", "آپ شامل کیے گئے");
    WAY("UrduPakistan", "removed_you", "آپ نے {1} کو ہٹایا");
    WAY("UrduPakistan", "removed_target_you", "{0} نے آپ کو ہٹایا");
    WAY("UrduPakistan", "joined_link_you", "آپ گروپ لنک استعمال کر کے شامل ہوئے۔");
    WAY("UrduPakistan", "changed_icon_you", "آپ نے گروپ آئیکن تبدیل کیا");
    WAY("UrduPakistan", "changed_name_you", "آپ نے گروپ کا نام \"{1}\" رکھا");
    WAY("UrduPakistan", "changed_name_from_to_you", "آپ نے گروپ کا نام \"{1}\" سے \"{2}\" میں تبدیل کیا");
    WAY("UrduPakistan", "changed_desc_you", "آپ نے گروپ کی تفصیل تبدیل کی");
    WAY("UrduPakistan", "admin_approval_on_you", "آپ نے اس گروپ میں شامل ہونے کے لیے ایڈمن کی منظوری آن کر دی۔ تبدیل کرنے کے لیے ٹیپ کریں۔");
    WAY("UrduPakistan", "admin_approval_off_you", "آپ نے اس گروپ میں شامل ہونے کے لیے ایڈمن کی منظوری آف کر دی۔ تبدیل کرنے کے لیے ٹیپ کریں۔");
    WAY("UrduPakistan", "reset_link_you", "آپ نے گروپ دعوت نامہ لنک ری سیٹ کیا");
    WAY("UrduPakistan", "settings_only_admins_edit_you", "آپ نے ترتیبات تبدیل کیں تاکہ صرف ایڈمنز گروپ کی معلومات میں ترمیم کر سکیں");
    WAY("UrduPakistan", "settings_all_edit_you", "آپ نے ترتیبات تبدیل کیں تاکہ تمام ممبران گروپ کی معلومات میں ترمیم کر سکیں");
    WAY("UrduPakistan", "settings_only_admins_send_you", "آپ نے گروپ کی ترتیبات تبدیل کیں تاکہ صرف ایڈمنز پیغامات بھیج سکیں");
    WAY("UrduPakistan", "settings_only_admins_add_you", "آپ نے گروپ کی ترتیبات تبدیل کیں تاکہ صرف ایڈمنز دوسروں کو شامل کر سکیں۔");
    WAY("UrduPakistan", "settings_all_add_you", "آپ نے گروپ کی ترتیبات تبدیل کیں تاکہ تمام ممبران دوسروں کو شامل کر سکیں۔");
    WAY("UrduPakistan", "settings_all_send_you", "آپ نے گروپ کی ترتیبات تبدیل کیں تاکہ تمام ممبران پیغامات بھیج سکیں");
    WAY("UrduPakistan", "settings_all_invite_link_you", "آپ نے گروپ کی ترتیبات تبدیل کیں تاکہ تمام ممبران لنک سے دعوت دے سکیں۔");
    WAY("UrduPakistan", "settings_only_admins_invite_link_you", "آپ نے گروپ کی ترتیبات تبدیل کیں تاکہ صرف ایڈمنز لنک سے دعوت دے سکیں۔");
    WAY("UrduPakistan", "disappear_on_you", "آپ نے غائب ہونے والے پیغامات آن کیے۔ نئے پیغامات بھیجے جانے کے {timer} بعد اس چیٹ سے غائب ہو جائیں گے (محفوظ شدہ کو چھوڑ کر)۔ تبدیل کرنے کے لیے ٹیپ کریں۔");
    WAY("UrduPakistan", "disappear_off_you", "آپ نے غائب ہونے والے پیغامات آف کیے۔ تبدیل کرنے کے لیے ٹیپ کریں۔");
    WAY("UrduPakistan", "disappear_off2_you", "آپ نے غائب ہونے والے پیغامات آف کیے۔ مزید معلومات کے لیے ٹیپ کریں۔");
    WAY("UrduPakistan", "update_timer_you", "آپ نے پیغام ٹائمر اپ ڈیٹ کیا۔ نئے پیغامات بھیجے جانے کے {timer} بعد اس چیٹ سے غائب ہو جائیں گے (محفوظ شدہ کو چھوڑ کر)۔ تبدیل کرنے کے لیے ٹیپ کریں۔");
    WAY("UrduPakistan", "update_timer2_you", "آپ نے پیغام ٹائمر اپ ڈیٹ کیا۔ نئے پیغامات {timer} بعد غائب ہو جائیں گے (محفوظ شدہ کو چھوڑ کر)۔ مزید معلومات کے لیے ٹیپ کریں۔");

    // ── Vietnamese — 2nd person (Bạn) ────────────────────────────────────────
    WAY("Vietnamese", "created_group_you", "Bạn đã tạo nhóm \"{1}\"");
    WAY("Vietnamese", "created_group_noname_you", "Bạn đã tạo nhóm này");
    WAY("Vietnamese", "left_you", "Bạn đã rời đi");
    WAY("Vietnamese", "added_you", "Bạn đã thêm {1}");
    WAY("Vietnamese", "added_target_you", "{0} đã thêm bạn");
    WAY("Vietnamese", "was_added_you", "Bạn đã được thêm");
    WAY("Vietnamese", "removed_you", "Bạn đã xóa {1}");
    WAY("Vietnamese", "removed_target_you", "{0} đã xóa bạn");
    WAY("Vietnamese", "joined_link_you", "Bạn đã tham gia bằng liên kết nhóm.");
    WAY("Vietnamese", "changed_icon_you", "Bạn đã thay đổi biểu tượng nhóm");
    WAY("Vietnamese", "changed_name_you", "Bạn đã đổi tên nhóm thành \"{1}\"");
    WAY("Vietnamese", "changed_name_from_to_you", "Bạn đã đổi tên nhóm từ \"{1}\" thành \"{2}\"");
    WAY("Vietnamese", "changed_desc_you", "Bạn đã thay đổi mô tả nhóm");
    WAY("Vietnamese", "admin_approval_on_you", "Bạn đã bật phê duyệt của quản trị viên để tham gia nhóm này. Nhấn để thay đổi.");
    WAY("Vietnamese", "admin_approval_off_you", "Bạn đã tắt phê duyệt của quản trị viên để tham gia nhóm này. Nhấn để thay đổi.");
    WAY("Vietnamese", "reset_link_you", "Bạn đã đặt lại liên kết mời nhóm");
    WAY("Vietnamese", "settings_only_admins_edit_you", "Bạn đã thay đổi cài đặt để chỉ quản trị viên có thể chỉnh sửa thông tin nhóm");
    WAY("Vietnamese", "settings_all_edit_you", "Bạn đã thay đổi cài đặt để tất cả thành viên có thể chỉnh sửa thông tin nhóm");
    WAY("Vietnamese", "settings_only_admins_send_you", "Bạn đã thay đổi cài đặt nhóm để chỉ quản trị viên có thể gửi tin nhắn");
    WAY("Vietnamese", "settings_only_admins_add_you", "Bạn đã thay đổi cài đặt nhóm để chỉ quản trị viên có thể thêm người khác.");
    WAY("Vietnamese", "settings_all_add_you", "Bạn đã thay đổi cài đặt nhóm để tất cả thành viên có thể thêm người khác.");
    WAY("Vietnamese", "settings_all_send_you", "Bạn đã thay đổi cài đặt nhóm để tất cả thành viên có thể gửi tin nhắn");
    WAY("Vietnamese", "settings_all_invite_link_you", "Bạn đã thay đổi cài đặt nhóm để tất cả thành viên có thể mời qua liên kết.");
    WAY("Vietnamese", "settings_only_admins_invite_link_you", "Bạn đã thay đổi cài đặt nhóm để chỉ quản trị viên có thể mời qua liên kết.");
    WAY("Vietnamese", "disappear_on_you", "Bạn đã bật tin nhắn biến mất. Tin nhắn mới sẽ biến mất khỏi cuộc trò chuyện này sau {timer} kể từ khi được gửi (ngoại trừ đã lưu). Nhấn để thay đổi.");
    WAY("Vietnamese", "disappear_off_you", "Bạn đã tắt tin nhắn biến mất. Nhấn để thay đổi.");
    WAY("Vietnamese", "disappear_off2_you", "Bạn đã tắt tin nhắn biến mất. Nhấn để biết thêm thông tin.");
    WAY("Vietnamese", "update_timer_you", "Bạn đã cập nhật bộ đếm thời gian tin nhắn. Tin nhắn mới sẽ biến mất khỏi cuộc trò chuyện này sau {timer} kể từ khi được gửi (ngoại trừ đã lưu). Nhấn để thay đổi.");
    WAY("Vietnamese", "update_timer2_you", "Bạn đã cập nhật bộ đếm thời gian tin nhắn. Tin nhắn mới sẽ biến mất sau {timer} (ngoại trừ đã lưu). Nhấn để biết thêm thông tin.");

    WAY("Slovenian", "voice_call_you", "Glasovni klic. {1} • Pridružili ste se");
    WAY("Slovenian", "video_call_you", "Video klic. {1} • Pridružili ste se");
    WAY("Slovenian", "unit_sec", "s");
    WAY("Slovenian", "unit_min", "min");
    WAY("Slovenian", "unit_hr",  "h");

    WAY("Swahili", "voice_call_you", "Simu ya sauti. {1} • Wewe ulijiunga");
    WAY("Swahili", "video_call_you", "Simu ya video. {1} • Wewe ulijiunga");
    WAY("Swahili", "unit_sec", "s");
    WAY("Swahili", "unit_min", "dak");
    WAY("Swahili", "unit_hr",  "saa");

    WAY("Swedish", "voice_call_you", "Röstsamtal. {1} • Du gick med");
    WAY("Swedish", "video_call_you", "Videosamtal. {1} • Du gick med");
    WAY("Swedish", "unit_sec", "s");
    WAY("Swedish", "unit_min", "min");
    WAY("Swedish", "unit_hr",  "tim");

    WAY("Tamil", "voice_call_you", "குரல் அழைப்பு. {1} • நீங்கள் சேர்ந்தீர்கள்");
    WAY("Tamil", "video_call_you", "வீடியோ அழைப்பு. {1} • நீங்கள் சேர்ந்தீர்கள்");
    WAY("Tamil", "unit_sec", "வி");
    WAY("Tamil", "unit_min", "நிமி");
    WAY("Tamil", "unit_hr",  "ம");

    WAY("Telugu", "voice_call_you", "వాయిస్ కాల్. {1} • మీరు చేరారు");
    WAY("Telugu", "video_call_you", "వీడియో కాల్. {1} • మీరు చేరారు");
    WAY("Telugu", "unit_sec", "సె");
    WAY("Telugu", "unit_min", "నిమి");
    WAY("Telugu", "unit_hr",  "గం");

    WAY("Thai", "voice_call_you", "สายเสียง {1} • คุณเข้าร่วม");
    WAY("Thai", "video_call_you", "วิดีโอคอล {1} • คุณเข้าร่วม");
    WAY("Thai", "unit_sec", "วิ");
    WAY("Thai", "unit_min", "นาที");
    WAY("Thai", "unit_hr",  "ชม.");

    WAY("UrduPakistan", "voice_call_you", "وائس کال۔ {1} • آپ شامل ہوئے");
    WAY("UrduPakistan", "video_call_you", "ویڈیو کال۔ {1} • آپ شامل ہوئے");
    WAY("UrduPakistan", "unit_sec", "سیکنڈ");
    WAY("UrduPakistan", "unit_min", "منٹ");
    WAY("UrduPakistan", "unit_hr",  "گھنٹے");

    WAY("Vietnamese", "voice_call_you", "Cuộc gọi thoại. {1} • Bạn đã tham gia");
    WAY("Vietnamese", "video_call_you", "Cuộc gọi video. {1} • Bạn đã tham gia");
    WAY("Vietnamese", "unit_sec", "giây");
    WAY("Vietnamese", "unit_min", "phút");
    WAY("Vietnamese", "unit_hr",  "giờ");

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

    // Afrikaans
    WAY("Afrikaans", "voice_call_duration",  "Stemoproep. {0}");
    WAY("Afrikaans", "video_call_duration",  "Video-oproep. {0}");
    WAY("Afrikaans", "voice_call_ended",     "Stemoproep. Beëindig");
    WAY("Afrikaans", "video_call_ended",     "Video-oproep. Beëindig");
    WAY("Afrikaans", "voice_call_missed",    "Gemiste stemoproep. Tik om terug te bel");
    WAY("Afrikaans", "video_call_missed",    "Gemiste video-oproep. Tik om terug te bel");
    WAY("Afrikaans", "voice_call_no_answer", "Stemoproep. Geen antwoord");
    WAY("Afrikaans", "video_call_no_answer", "Video-oproep. Geen antwoord");

    // Albanian
    WAY("Albanian", "voice_call_duration",  "Telefonatë zanore. {0}");
    WAY("Albanian", "video_call_duration",  "Video thirrje. {0}");
    WAY("Albanian", "voice_call_ended",     "Telefonatë zanore. Përfundoi");
    WAY("Albanian", "video_call_ended",     "Video thirrje. Përfundoi");
    WAY("Albanian", "voice_call_missed",    "Telefonatë zanore e humbur. Trokit për të rithirrur");
    WAY("Albanian", "video_call_missed",    "Video thirrje e humbur. Trokit për të rithirrur");
    WAY("Albanian", "voice_call_no_answer", "Telefonatë zanore. Nuk u përgjigj");
    WAY("Albanian", "video_call_no_answer", "Video thirrje. Nuk u përgjigj");

    // Bengali
    WAY("Bengali", "voice_call_duration",  "ভয়েস কল। {0}");
    WAY("Bengali", "video_call_duration",  "ভিডিও কল। {0}");
    WAY("Bengali", "voice_call_ended",     "ভয়েস কল। শেষ হয়েছে");
    WAY("Bengali", "video_call_ended",     "ভিডিও কল। শেষ হয়েছে");
    WAY("Bengali", "voice_call_missed",    "মিসড ভয়েস কল। কলব্যাক করতে ট্যাপ করুন");
    WAY("Bengali", "video_call_missed",    "মিসড ভিডিও কল। কলব্যাক করতে ট্যাপ করুন");
    WAY("Bengali", "voice_call_no_answer", "ভয়েস কল। কোন উত্তর নেই");
    WAY("Bengali", "video_call_no_answer", "ভিডিও কল। কোন উত্তর নেই");

    // Bulgarian
    WAY("Bulgarian", "voice_call_duration",  "Гласов разговор. {0}");
    WAY("Bulgarian", "video_call_duration",  "Видео разговор. {0}");
    WAY("Bulgarian", "voice_call_ended",     "Гласов разговор. Приключи");
    WAY("Bulgarian", "video_call_ended",     "Видео разговор. Приключи");
    WAY("Bulgarian", "voice_call_missed",    "Пропуснат гласов разговор. Докоснете за обратно обаждане");
    WAY("Bulgarian", "video_call_missed",    "Пропуснат видео разговор. Докоснете за обратно обаждане");
    WAY("Bulgarian", "voice_call_no_answer", "Гласов разговор. Няма отговор");
    WAY("Bulgarian", "video_call_no_answer", "Видео разговор. Няма отговор");

    // Catalan
    WAY("Catalan", "voice_call_duration",  "Trucada de veu. {0}");
    WAY("Catalan", "video_call_duration",  "Videotrucada. {0}");
    WAY("Catalan", "voice_call_ended",     "Trucada de veu. Finalitzada");
    WAY("Catalan", "video_call_ended",     "Videotrucada. Finalitzada");
    WAY("Catalan", "voice_call_missed",    "Trucada de veu perduda. Toca per tornar a trucar");
    WAY("Catalan", "video_call_missed",    "Videotrucada perduda. Toca per tornar a trucar");
    WAY("Catalan", "voice_call_no_answer", "Trucada de veu. Sense resposta");
    WAY("Catalan", "video_call_no_answer", "Videotrucada. Sense resposta");

    // ChineseHongKong
    WAY("ChineseHongKong", "voice_call_duration",  "語音通話。{0}");
    WAY("ChineseHongKong", "video_call_duration",  "視訊通話。{0}");
    WAY("ChineseHongKong", "voice_call_ended",     "語音通話。已結束");
    WAY("ChineseHongKong", "video_call_ended",     "視訊通話。已結束");
    WAY("ChineseHongKong", "voice_call_missed",    "未接語音通話。點擊以回撥");
    WAY("ChineseHongKong", "video_call_missed",    "未接視訊通話。點擊以回撥");
    WAY("ChineseHongKong", "voice_call_no_answer", "語音通話。無人接聽");
    WAY("ChineseHongKong", "video_call_no_answer", "視訊通話。無人接聽");

    // ChineseTaiwan
    WAY("ChineseTaiwan", "voice_call_duration",  "語音通話。{0}");
    WAY("ChineseTaiwan", "video_call_duration",  "視訊通話。{0}");
    WAY("ChineseTaiwan", "voice_call_ended",     "語音通話。已結束");
    WAY("ChineseTaiwan", "video_call_ended",     "視訊通話。已結束");
    WAY("ChineseTaiwan", "voice_call_missed",    "未接語音通話。點選以回撥");
    WAY("ChineseTaiwan", "video_call_missed",    "未接視訊通話。點選以回撥");
    WAY("ChineseTaiwan", "voice_call_no_answer", "語音通話。無人接聽");
    WAY("ChineseTaiwan", "video_call_no_answer", "視訊通話。無人接聽");

    // Croatian
    WAY("Croatian", "voice_call_duration",  "Glasovni poziv. {0}");
    WAY("Croatian", "video_call_duration",  "Video poziv. {0}");
    WAY("Croatian", "voice_call_ended",     "Glasovni poziv. Završeno");
    WAY("Croatian", "video_call_ended",     "Video poziv. Završeno");
    WAY("Croatian", "voice_call_missed",    "Propušten glasovni poziv. Dotakni za povratni poziv");
    WAY("Croatian", "video_call_missed",    "Propušten video poziv. Dotakni za povratni poziv");
    WAY("Croatian", "voice_call_no_answer", "Glasovni poziv. Nema odgovora");
    WAY("Croatian", "video_call_no_answer", "Video poziv. Nema odgovora");

    // Czech
    WAY("Czech", "voice_call_duration",  "Hlasový hovor. {0}");
    WAY("Czech", "video_call_duration",  "Videohovor. {0}");
    WAY("Czech", "voice_call_ended",     "Hlasový hovor. Ukončeno");
    WAY("Czech", "video_call_ended",     "Videohovor. Ukončeno");
    WAY("Czech", "voice_call_missed",    "Zmeškaný hlasový hovor. Klepnutím zavoláte zpět");
    WAY("Czech", "video_call_missed",    "Zmeškaný videohovor. Klepnutím zavoláte zpět");
    WAY("Czech", "voice_call_no_answer", "Hlasový hovor. Žádná odpověď");
    WAY("Czech", "video_call_no_answer", "Videohovor. Žádná odpověď");

    // Danish
    WAY("Danish", "voice_call_duration",  "Taleopkald. {0}");
    WAY("Danish", "video_call_duration",  "Videoopkald. {0}");
    WAY("Danish", "voice_call_ended",     "Taleopkald. Afsluttet");
    WAY("Danish", "video_call_ended",     "Videoopkald. Afsluttet");
    WAY("Danish", "voice_call_missed",    "Mistet taleopkald. Tryk for at ringe tilbage");
    WAY("Danish", "video_call_missed",    "Mistet videoopkald. Tryk for at ringe tilbage");
    WAY("Danish", "voice_call_no_answer", "Taleopkald. Intet svar");
    WAY("Danish", "video_call_no_answer", "Videoopkald. Intet svar");

    // Dutch
    WAY("Dutch", "voice_call_duration",  "Spraakoproep. {0}");
    WAY("Dutch", "video_call_duration",  "Videogesprek. {0}");
    WAY("Dutch", "voice_call_ended",     "Spraakoproep. Beëindigd");
    WAY("Dutch", "video_call_ended",     "Videogesprek. Beëindigd");
    WAY("Dutch", "voice_call_missed",    "Gemiste spraakoproep. Tik om terug te bellen");
    WAY("Dutch", "video_call_missed",    "Gemist videogesprek. Tik om terug te bellen");
    WAY("Dutch", "voice_call_no_answer", "Spraakoproep. Geen antwoord");
    WAY("Dutch", "video_call_no_answer", "Videogesprek. Geen antwoord");

    // Estonian
    WAY("Estonian", "voice_call_duration",  "Häälkõne. {0}");
    WAY("Estonian", "video_call_duration",  "Videokõne. {0}");
    WAY("Estonian", "voice_call_ended",     "Häälkõne. Lõppenud");
    WAY("Estonian", "video_call_ended",     "Videokõne. Lõppenud");
    WAY("Estonian", "voice_call_missed",    "Vastamata häälkõne. Puudutage tagasihelistamiseks");
    WAY("Estonian", "video_call_missed",    "Vastamata videokõne. Puudutage tagasihelistamiseks");
    WAY("Estonian", "voice_call_no_answer", "Häälkõne. Vastust pole");
    WAY("Estonian", "video_call_no_answer", "Videokõne. Vastust pole");

    // Filipino
    WAY("Filipino", "voice_call_duration",  "Voice call. {0}");
    WAY("Filipino", "video_call_duration",  "Video call. {0}");
    WAY("Filipino", "voice_call_ended",     "Voice call. Natapos");
    WAY("Filipino", "video_call_ended",     "Video call. Natapos");
    WAY("Filipino", "voice_call_missed",    "Missed voice call. I-tap upang tumawag pabalik");
    WAY("Filipino", "video_call_missed",    "Missed video call. I-tap upang tumawag pabalik");
    WAY("Filipino", "voice_call_no_answer", "Voice call. Walang sumagot");
    WAY("Filipino", "video_call_no_answer", "Video call. Walang sumagot");

    // Finnish
    WAY("Finnish", "voice_call_duration",  "Äänipuhelu. {0}");
    WAY("Finnish", "video_call_duration",  "Videopuhelu. {0}");
    WAY("Finnish", "voice_call_ended",     "Äänipuhelu. Päättynyt");
    WAY("Finnish", "video_call_ended",     "Videopuhelu. Päättynyt");
    WAY("Finnish", "voice_call_missed",    "Vastaamaton äänipuhelu. Napauta soittaaksesi takaisin");
    WAY("Finnish", "video_call_missed",    "Vastaamaton videopuhelu. Napauta soittaaksesi takaisin");
    WAY("Finnish", "voice_call_no_answer", "Äänipuhelu. Ei vastausta");
    WAY("Finnish", "video_call_no_answer", "Videopuhelu. Ei vastausta");

    // Greek
    WAY("Greek", "voice_call_duration",  "Φωνητική κλήση. {0}");
    WAY("Greek", "video_call_duration",  "Βιντεοκλήση. {0}");
    WAY("Greek", "voice_call_ended",     "Φωνητική κλήση. Ολοκληρώθηκε");
    WAY("Greek", "video_call_ended",     "Βιντεοκλήση. Ολοκληρώθηκε");
    WAY("Greek", "voice_call_missed",    "Αναπάντητη φωνητική κλήση. Πατήστε για επανάκληση");
    WAY("Greek", "video_call_missed",    "Αναπάντητη βιντεοκλήση. Πατήστε για επανάκληση");
    WAY("Greek", "voice_call_no_answer", "Φωνητική κλήση. Χωρίς απάντηση");
    WAY("Greek", "video_call_no_answer", "Βιντεοκλήση. Χωρίς απάντηση");

    // Gujarati
    WAY("Gujarati", "voice_call_duration",  "વૉઇસ કૉલ. {0}");
    WAY("Gujarati", "video_call_duration",  "વિડિયો કૉલ. {0}");
    WAY("Gujarati", "voice_call_ended",     "વૉઇસ કૉલ. સમાપ્ત");
    WAY("Gujarati", "video_call_ended",     "વિડિયો કૉલ. સમાપ્ત");
    WAY("Gujarati", "voice_call_missed",    "મિસ થયેલ વૉઇસ કૉલ. પાછા કૉલ કરવા ટૅપ કરો");
    WAY("Gujarati", "video_call_missed",    "મિસ થયેલ વિડિયો કૉલ. પાછા કૉલ કરવા ટૅપ કરો");
    WAY("Gujarati", "voice_call_no_answer", "વૉઇસ કૉલ. કોઈ જવાબ નથી");
    WAY("Gujarati", "video_call_no_answer", "વિડિયો કૉલ. કોઈ જવાબ નથી");

    // Hebrew
    WAY("Hebrew", "voice_call_duration",  "שיחת קול. {0}");
    WAY("Hebrew", "video_call_duration",  "שיחת וידאו. {0}");
    WAY("Hebrew", "voice_call_ended",     "שיחת קול. הסתיימה");
    WAY("Hebrew", "video_call_ended",     "שיחת וידאו. הסתיימה");
    WAY("Hebrew", "voice_call_missed",    "שיחת קול שלא נענתה. הקש לחיוג חזרה");
    WAY("Hebrew", "video_call_missed",    "שיחת וידאו שלא נענתה. הקש לחיוג חזרה");
    WAY("Hebrew", "voice_call_no_answer", "שיחת קול. אין מענה");
    WAY("Hebrew", "video_call_no_answer", "שיחת וידאו. אין מענה");

    // Hungarian
    WAY("Hungarian", "voice_call_duration",  "Hanghívás. {0}");
    WAY("Hungarian", "video_call_duration",  "Videóhívás. {0}");
    WAY("Hungarian", "voice_call_ended",     "Hanghívás. Befejezve");
    WAY("Hungarian", "video_call_ended",     "Videóhívás. Befejezve");
    WAY("Hungarian", "voice_call_missed",    "Nem fogadott hanghívás. Koppints a visszahíváshoz");
    WAY("Hungarian", "video_call_missed",    "Nem fogadott videóhívás. Koppints a visszahíváshoz");
    WAY("Hungarian", "voice_call_no_answer", "Hanghívás. Nincs válasz");
    WAY("Hungarian", "video_call_no_answer", "Videóhívás. Nincs válasz");

    // Indonesian
    WAY("Indonesian", "voice_call_duration",  "Panggilan suara. {0}");
    WAY("Indonesian", "video_call_duration",  "Panggilan video. {0}");
    WAY("Indonesian", "voice_call_ended",     "Panggilan suara. Berakhir");
    WAY("Indonesian", "video_call_ended",     "Panggilan video. Berakhir");
    WAY("Indonesian", "voice_call_missed",    "Panggilan suara tak terjawab. Ketuk untuk menelepon kembali");
    WAY("Indonesian", "video_call_missed",    "Panggilan video tak terjawab. Ketuk untuk menelepon kembali");
    WAY("Indonesian", "voice_call_no_answer", "Panggilan suara. Tidak ada jawaban");
    WAY("Indonesian", "video_call_no_answer", "Panggilan video. Tidak ada jawaban");

    // Irish
    WAY("Irish", "voice_call_duration",  "Glao gutha. {0}");
    WAY("Irish", "video_call_duration",  "Físghlao. {0}");
    WAY("Irish", "voice_call_ended",     "Glao gutha. Críochnaithe");
    WAY("Irish", "video_call_ended",     "Físghlao. Críochnaithe");
    WAY("Irish", "voice_call_missed",    "Glao gutha caillte. Tapáil chun glaoch ar ais");
    WAY("Irish", "video_call_missed",    "Físghlao caillte. Tapáil chun glaoch ar ais");
    WAY("Irish", "voice_call_no_answer", "Glao gutha. Gan freagra");
    WAY("Irish", "video_call_no_answer", "Físghlao. Gan freagra");

    // Kannada
    WAY("Kannada", "voice_call_duration",  "ವಾಯ್ಸ್ ಕರೆ. {0}");
    WAY("Kannada", "video_call_duration",  "ವೀಡಿಯೊ ಕರೆ. {0}");
    WAY("Kannada", "voice_call_ended",     "ವಾಯ್ಸ್ ಕರೆ. ಮುಗಿದಿದೆ");
    WAY("Kannada", "video_call_ended",     "ವೀಡಿಯೊ ಕರೆ. ಮುಗಿದಿದೆ");
    WAY("Kannada", "voice_call_missed",    "ತಪ್ಪಿದ ವಾಯ್ಸ್ ಕರೆ. ಮರಳಿ ಕರೆ ಮಾಡಲು ಟ್ಯಾಪ್ ಮಾಡಿ");
    WAY("Kannada", "video_call_missed",    "ತಪ್ಪಿದ ವೀಡಿಯೊ ಕರೆ. ಮರಳಿ ಕರೆ ಮಾಡಲು ಟ್ಯಾಪ್ ಮಾಡಿ");
    WAY("Kannada", "voice_call_no_answer", "ವಾಯ್ಸ್ ಕರೆ. ಉತ್ತರವಿಲ್ಲ");
    WAY("Kannada", "video_call_no_answer", "ವೀಡಿಯೊ ಕರೆ. ಉತ್ತರವಿಲ್ಲ");

    // Kazakh
    WAY("Kazakh", "voice_call_duration",  "Дауыстық қоңырау. {0}");
    WAY("Kazakh", "video_call_duration",  "Бейне қоңырау. {0}");
    WAY("Kazakh", "voice_call_ended",     "Дауыстық қоңырау. Аяқталды");
    WAY("Kazakh", "video_call_ended",     "Бейне қоңырау. Аяқталды");
    WAY("Kazakh", "voice_call_missed",    "Жауапсыз дауыстық қоңырау. Қайта қоңырау шалу үшін түртіңіз");
    WAY("Kazakh", "video_call_missed",    "Жауапсыз бейне қоңырау. Қайта қоңырау шалу үшін түртіңіз");
    WAY("Kazakh", "voice_call_no_answer", "Дауыстық қоңырау. Жауап жоқ");
    WAY("Kazakh", "video_call_no_answer", "Бейне қоңырау. Жауап жоқ");

    // Lao
    WAY("Lao", "voice_call_duration",  "ການໂທສຽງ. {0}");
    WAY("Lao", "video_call_duration",  "ການໂທວິດີໂອ. {0}");
    WAY("Lao", "voice_call_ended",     "ການໂທສຽງ. ສິ້ນສຸດແລ້ວ");
    WAY("Lao", "video_call_ended",     "ການໂທວິດີໂອ. ສິ້ນສຸດແລ້ວ");
    WAY("Lao", "voice_call_missed",    "ການໂທສຽງທີ່ພາດ. ແຕະເພື່ອໂທກັບ");
    WAY("Lao", "video_call_missed",    "ການໂທວິດີໂອທີ່ພາດ. ແຕະເພື່ອໂທກັບ");
    WAY("Lao", "voice_call_no_answer", "ການໂທສຽງ. ບໍ່ຮັບສາຍ");
    WAY("Lao", "video_call_no_answer", "ການໂທວິດີໂອ. ບໍ່ຮັບສາຍ");

    // Latvian
    WAY("Latvian", "voice_call_duration",  "Balss zvans. {0}");
    WAY("Latvian", "video_call_duration",  "Video zvans. {0}");
    WAY("Latvian", "voice_call_ended",     "Balss zvans. Beidzies");
    WAY("Latvian", "video_call_ended",     "Video zvans. Beidzies");
    WAY("Latvian", "voice_call_missed",    "Neatbildēts balss zvans. Pieskarieties, lai atzvanītu");
    WAY("Latvian", "video_call_missed",    "Neatbildēts video zvans. Pieskarieties, lai atzvanītu");
    WAY("Latvian", "voice_call_no_answer", "Balss zvans. Nav atbildes");
    WAY("Latvian", "video_call_no_answer", "Video zvans. Nav atbildes");

    // Lithuanian
    WAY("Lithuanian", "voice_call_duration",  "Balso skambutis. {0}");
    WAY("Lithuanian", "video_call_duration",  "Vaizdo skambutis. {0}");
    WAY("Lithuanian", "voice_call_ended",     "Balso skambutis. Baigtas");
    WAY("Lithuanian", "video_call_ended",     "Vaizdo skambutis. Baigtas");
    WAY("Lithuanian", "voice_call_missed",    "Praleistas balso skambutis. Bakstelėkite, kad perskambintumėte");
    WAY("Lithuanian", "video_call_missed",    "Praleistas vaizdo skambutis. Bakstelėkite, kad perskambintumėte");
    WAY("Lithuanian", "voice_call_no_answer", "Balso skambutis. Neatsakė");
    WAY("Lithuanian", "video_call_no_answer", "Vaizdo skambutis. Neatsakė");

    // Macedonian
    WAY("Macedonian", "voice_call_duration",  "Гласовен повик. {0}");
    WAY("Macedonian", "video_call_duration",  "Видео повик. {0}");
    WAY("Macedonian", "voice_call_ended",     "Гласовен повик. Завршен");
    WAY("Macedonian", "video_call_ended",     "Видео повик. Завршен");
    WAY("Macedonian", "voice_call_missed",    "Пропуштен гласовен повик. Допрете за да повикате назад");
    WAY("Macedonian", "video_call_missed",    "Пропуштен видео повик. Допрете за да повикате назад");
    WAY("Macedonian", "voice_call_no_answer", "Гласовен повик. Без одговор");
    WAY("Macedonian", "video_call_no_answer", "Видео повик. Без одговор");

    // Malay
    WAY("Malay", "voice_call_duration",  "Panggilan suara. {0}");
    WAY("Malay", "video_call_duration",  "Panggilan video. {0}");
    WAY("Malay", "voice_call_ended",     "Panggilan suara. Tamat");
    WAY("Malay", "video_call_ended",     "Panggilan video. Tamat");
    WAY("Malay", "voice_call_missed",    "Panggilan suara terlepas. Ketik untuk menghubungi semula");
    WAY("Malay", "video_call_missed",    "Panggilan video terlepas. Ketik untuk menghubungi semula");
    WAY("Malay", "voice_call_no_answer", "Panggilan suara. Tiada jawapan");
    WAY("Malay", "video_call_no_answer", "Panggilan video. Tiada jawapan");

    // Malayalam
    WAY("Malayalam", "voice_call_duration",  "വോയ്‌സ് കോൾ. {0}");
    WAY("Malayalam", "video_call_duration",  "വീഡിയോ കോൾ. {0}");
    WAY("Malayalam", "voice_call_ended",     "വോയ്‌സ് കോൾ. അവസാനിച്ചു");
    WAY("Malayalam", "video_call_ended",     "വീഡിയോ കോൾ. അവസാനിച്ചു");
    WAY("Malayalam", "voice_call_missed",    "മിസ്ഡ് വോയ്‌സ് കോൾ. തിരികെ വിളിക്കാൻ ടാപ്പ് ചെയ്യുക");
    WAY("Malayalam", "video_call_missed",    "മിസ്ഡ് വീഡിയോ കോൾ. തിരികെ വിളിക്കാൻ ടാപ്പ് ചെയ്യുക");
    WAY("Malayalam", "voice_call_no_answer", "വോയ്‌സ് കോൾ. ഉത്തരമില്ല");
    WAY("Malayalam", "video_call_no_answer", "വീഡിയോ കോൾ. ഉത്തരമില്ല");

    // Marathi
    WAY("Marathi", "voice_call_duration",  "व्हॉइस कॉल. {0}");
    WAY("Marathi", "video_call_duration",  "व्हिडिओ कॉल. {0}");
    WAY("Marathi", "voice_call_ended",     "व्हॉइस कॉल. समाप्त");
    WAY("Marathi", "video_call_ended",     "व्हिडिओ कॉल. समाप्त");
    WAY("Marathi", "voice_call_missed",    "मिस्ड व्हॉइस कॉल. परत कॉल करण्यासाठी टॅप करा");
    WAY("Marathi", "video_call_missed",    "मिस्ड व्हिडिओ कॉल. परत कॉल करण्यासाठी टॅप करा");
    WAY("Marathi", "voice_call_no_answer", "व्हॉइस कॉल. उत्तर नाही");
    WAY("Marathi", "video_call_no_answer", "व्हिडिओ कॉल. उत्तर नाही");

    // Norwegian
    WAY("Norwegian", "voice_call_duration",  "Taleanrop. {0}");
    WAY("Norwegian", "video_call_duration",  "Videoanrop. {0}");
    WAY("Norwegian", "voice_call_ended",     "Taleanrop. Avsluttet");
    WAY("Norwegian", "video_call_ended",     "Videoanrop. Avsluttet");
    WAY("Norwegian", "voice_call_missed",    "Tapt taleanrop. Trykk for å ringe tilbake");
    WAY("Norwegian", "video_call_missed",    "Tapt videoanrop. Trykk for å ringe tilbake");
    WAY("Norwegian", "voice_call_no_answer", "Taleanrop. Ingen svar");
    WAY("Norwegian", "video_call_no_answer", "Videoanrop. Ingen svar");

    // Persian
    WAY("Persian", "voice_call_duration",  "تماس صوتی. {0}");
    WAY("Persian", "video_call_duration",  "تماس تصویری. {0}");
    WAY("Persian", "voice_call_ended",     "تماس صوتی. پایان یافت");
    WAY("Persian", "video_call_ended",     "تماس تصویری. پایان یافت");
    WAY("Persian", "voice_call_missed",    "تماس صوتی از دست رفته. برای تماس مجدد ضربه بزنید");
    WAY("Persian", "video_call_missed",    "تماس تصویری از دست رفته. برای تماس مجدد ضربه بزنید");
    WAY("Persian", "voice_call_no_answer", "تماس صوتی. بدون پاسخ");
    WAY("Persian", "video_call_no_answer", "تماس تصویری. بدون پاسخ");

    // PortugueseBrazil
    WAY("PortugueseBrazil", "voice_call_duration",  "Chamada de voz. {0}");
    WAY("PortugueseBrazil", "video_call_duration",  "Chamada de vídeo. {0}");
    WAY("PortugueseBrazil", "voice_call_ended",     "Chamada de voz. Encerrada");
    WAY("PortugueseBrazil", "video_call_ended",     "Chamada de vídeo. Encerrada");
    WAY("PortugueseBrazil", "voice_call_missed",    "Chamada de voz perdida. Toque para ligar de volta");
    WAY("PortugueseBrazil", "video_call_missed",    "Chamada de vídeo perdida. Toque para ligar de volta");
    WAY("PortugueseBrazil", "voice_call_no_answer", "Chamada de voz. Sem resposta");
    WAY("PortugueseBrazil", "video_call_no_answer", "Chamada de vídeo. Sem resposta");

    // Punjabi
    WAY("Punjabi", "voice_call_duration",  "ਵੌਇਸ ਕਾਲ। {0}");
    WAY("Punjabi", "video_call_duration",  "ਵੀਡੀਓ ਕਾਲ। {0}");
    WAY("Punjabi", "voice_call_ended",     "ਵੌਇਸ ਕਾਲ। ਸਮਾਪਤ");
    WAY("Punjabi", "video_call_ended",     "ਵੀਡੀਓ ਕਾਲ। ਸਮਾਪਤ");
    WAY("Punjabi", "voice_call_missed",    "ਖੁੰਝੀ ਵੌਇਸ ਕਾਲ। ਵਾਪਸ ਕਾਲ ਕਰਨ ਲਈ ਟੈਪ ਕਰੋ");
    WAY("Punjabi", "video_call_missed",    "ਖੁੰਝੀ ਵੀਡੀਓ ਕਾਲ। ਵਾਪਸ ਕਾਲ ਕਰਨ ਲਈ ਟੈਪ ਕਰੋ");
    WAY("Punjabi", "voice_call_no_answer", "ਵੌਇਸ ਕਾਲ। ਕੋਈ ਜਵਾਬ ਨਹੀਂ");
    WAY("Punjabi", "video_call_no_answer", "ਵੀਡੀਓ ਕਾਲ। ਕੋਈ ਜਵਾਬ ਨਹੀਂ");

    // Romanian
    WAY("Romanian", "voice_call_duration",  "Apel vocal. {0}");
    WAY("Romanian", "video_call_duration",  "Apel video. {0}");
    WAY("Romanian", "voice_call_ended",     "Apel vocal. Încheiat");
    WAY("Romanian", "video_call_ended",     "Apel video. Încheiat");
    WAY("Romanian", "voice_call_missed",    "Apel vocal pierdut. Apasă pentru a suna înapoi");
    WAY("Romanian", "video_call_missed",    "Apel video pierdut. Apasă pentru a suna înapoi");
    WAY("Romanian", "voice_call_no_answer", "Apel vocal. Fără răspuns");
    WAY("Romanian", "video_call_no_answer", "Apel video. Fără răspuns");

    // Serbian
    WAY("Serbian", "voice_call_duration",  "Гласовни позив. {0}");
    WAY("Serbian", "video_call_duration",  "Видео позив. {0}");
    WAY("Serbian", "voice_call_ended",     "Гласовни позив. Завршен");
    WAY("Serbian", "video_call_ended",     "Видео позив. Завршен");
    WAY("Serbian", "voice_call_missed",    "Пропуштен гласовни позив. Додирните да позовете назад");
    WAY("Serbian", "video_call_missed",    "Пропуштен видео позив. Додирните да позовете назад");
    WAY("Serbian", "voice_call_no_answer", "Гласовни позив. Без одговора");
    WAY("Serbian", "video_call_no_answer", "Видео позив. Без одговора");

    // Slovak
    WAY("Slovak", "voice_call_duration",  "Hlasový hovor. {0}");
    WAY("Slovak", "video_call_duration",  "Video hovor. {0}");
    WAY("Slovak", "voice_call_ended",     "Hlasový hovor. Ukončený");
    WAY("Slovak", "video_call_ended",     "Video hovor. Ukončený");
    WAY("Slovak", "voice_call_missed",    "Zmeškané hlasový hovor. Ťuknutím zavoláte späť");
    WAY("Slovak", "video_call_missed",    "Zmeškané video hovor. Ťuknutím zavoláte späť");
    WAY("Slovak", "voice_call_no_answer", "Hlasový hovor. Bez odpovede");
    WAY("Slovak", "video_call_no_answer", "Video hovor. Bez odpovede");

    // Slovenian
    WAY("Slovenian", "voice_call_duration",  "Glasovni klic. {0}");
    WAY("Slovenian", "video_call_duration",  "Video klic. {0}");
    WAY("Slovenian", "voice_call_ended",     "Glasovni klic. Končan");
    WAY("Slovenian", "video_call_ended",     "Video klic. Končan");
    WAY("Slovenian", "voice_call_missed",    "Zamujeni glasovni klic. Tapnite za povratni klic");
    WAY("Slovenian", "video_call_missed",    "Zamujeni video klic. Tapnite za povratni klic");
    WAY("Slovenian", "voice_call_no_answer", "Glasovni klic. Brez odziva");
    WAY("Slovenian", "video_call_no_answer", "Video klic. Brez odziva");

    // Swahili
    WAY("Swahili", "voice_call_duration",  "Simu ya sauti. {0}");
    WAY("Swahili", "video_call_duration",  "Simu ya video. {0}");
    WAY("Swahili", "voice_call_ended",     "Simu ya sauti. Imekwisha");
    WAY("Swahili", "video_call_ended",     "Simu ya video. Imekwisha");
    WAY("Swahili", "voice_call_missed",    "Simu ya sauti iliyokosekana. Gusa kupiga tena");
    WAY("Swahili", "video_call_missed",    "Simu ya video iliyokosekana. Gusa kupiga tena");
    WAY("Swahili", "voice_call_no_answer", "Simu ya sauti. Hakuna jibu");
    WAY("Swahili", "video_call_no_answer", "Simu ya video. Hakuna jibu");

    // Swedish
    WAY("Swedish", "voice_call_duration",  "Röstsamtal. {0}");
    WAY("Swedish", "video_call_duration",  "Videosamtal. {0}");
    WAY("Swedish", "voice_call_ended",     "Röstsamtal. Avslutades");
    WAY("Swedish", "video_call_ended",     "Videosamtal. Avslutades");
    WAY("Swedish", "voice_call_missed",    "Missat röstsamtal. Tryck för att ringa tillbaka");
    WAY("Swedish", "video_call_missed",    "Missat videosamtal. Tryck för att ringa tillbaka");
    WAY("Swedish", "voice_call_no_answer", "Röstsamtal. Inget svar");
    WAY("Swedish", "video_call_no_answer", "Videosamtal. Inget svar");

    // Tamil
    WAY("Tamil", "voice_call_duration",  "குரல் அழைப்பு. {0}");
    WAY("Tamil", "video_call_duration",  "வீடியோ அழைப்பு. {0}");
    WAY("Tamil", "voice_call_ended",     "குரல் அழைப்பு. முடிந்தது");
    WAY("Tamil", "video_call_ended",     "வீடியோ அழைப்பு. முடிந்தது");
    WAY("Tamil", "voice_call_missed",    "தவறிய குரல் அழைப்பு. திரும்ப அழைக்க தட்டவும்");
    WAY("Tamil", "video_call_missed",    "தவறிய வீடியோ அழைப்பு. திரும்ப அழைக்க தட்டவும்");
    WAY("Tamil", "voice_call_no_answer", "குரல் அழைப்பு. பதில் இல்லை");
    WAY("Tamil", "video_call_no_answer", "வீடியோ அழைப்பு. பதில் இல்லை");

    // Telugu
    WAY("Telugu", "voice_call_duration",  "వాయిస్ కాల్. {0}");
    WAY("Telugu", "video_call_duration",  "వీడియో కాల్. {0}");
    WAY("Telugu", "voice_call_ended",     "వాయిస్ కాల్. ముగిసింది");
    WAY("Telugu", "video_call_ended",     "వీడియో కాల్. ముగిసింది");
    WAY("Telugu", "voice_call_missed",    "మిస్డ్ వాయిస్ కాల్. తిరిగి కాల్ చేయడానికి ట్యాప్ చేయండి");
    WAY("Telugu", "video_call_missed",    "మిస్డ్ వీడియో కాల్. తిరిగి కాల్ చేయడానికి ట్యాప్ చేయండి");
    WAY("Telugu", "voice_call_no_answer", "వాయిస్ కాల్. సమాధానం లేదు");
    WAY("Telugu", "video_call_no_answer", "వీడియో కాల్. సమాధానం లేదు");

    // Thai
    WAY("Thai", "voice_call_duration",  "สายเสียง {0}");
    WAY("Thai", "video_call_duration",  "วิดีโอคอล {0}");
    WAY("Thai", "voice_call_ended",     "สายเสียง สิ้นสุดแล้ว");
    WAY("Thai", "video_call_ended",     "วิดีโอคอล สิ้นสุดแล้ว");
    WAY("Thai", "voice_call_missed",    "สายเสียงที่ไม่ได้รับ แตะเพื่อโทรกลับ");
    WAY("Thai", "video_call_missed",    "วิดีโอคอลที่ไม่ได้รับ แตะเพื่อโทรกลับ");
    WAY("Thai", "voice_call_no_answer", "สายเสียง ไม่มีคำตอบ");
    WAY("Thai", "video_call_no_answer", "วิดีโอคอล ไม่มีคำตอบ");

    // UrduPakistan
    WAY("UrduPakistan", "voice_call_duration",  "وائس کال۔ {0}");
    WAY("UrduPakistan", "video_call_duration",  "ویڈیو کال۔ {0}");
    WAY("UrduPakistan", "voice_call_ended",     "وائس کال۔ ختم ہو گئی");
    WAY("UrduPakistan", "video_call_ended",     "ویڈیو کال۔ ختم ہو گئی");
    WAY("UrduPakistan", "voice_call_missed",    "مسڈ وائس کال۔ واپس کال کرنے کے لیے ٹیپ کریں");
    WAY("UrduPakistan", "video_call_missed",    "مسڈ ویڈیو کال۔ واپس کال کرنے کے لیے ٹیپ کریں");
    WAY("UrduPakistan", "voice_call_no_answer", "وائس کال۔ کوئی جواب نہیں");
    WAY("UrduPakistan", "video_call_no_answer", "ویڈیو کال۔ کوئی جواب نہیں");

    // Vietnamese
    WAY("Vietnamese", "voice_call_duration",  "Cuộc gọi thoại. {0}");
    WAY("Vietnamese", "video_call_duration",  "Cuộc gọi video. {0}");
    WAY("Vietnamese", "voice_call_ended",     "Cuộc gọi thoại. Đã kết thúc");
    WAY("Vietnamese", "video_call_ended",     "Cuộc gọi video. Đã kết thúc");
    WAY("Vietnamese", "voice_call_missed",    "Cuộc gọi thoại nhỡ. Nhấn để gọi lại");
    WAY("Vietnamese", "video_call_missed",    "Cuộc gọi video nhỡ. Nhấn để gọi lại");
    WAY("Vietnamese", "voice_call_no_answer", "Cuộc gọi thoại. Không trả lời");
    WAY("Vietnamese", "video_call_no_answer", "Cuộc gọi video. Không trả lời");

    #undef WAY
}
