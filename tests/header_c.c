/* sms_mod.h builds as strict C99 with every warning an error. */
#include <sms_mod.h>

SMS_MOD_DEFINE()

static int on_frame(SmsMod* mod, SmsEvent* ev, void* user)
{
	(void)mod; (void)ev; (void)user;
	return SMS_CONTINUE;
}

SMS_MOD_EXPORT int sms_mod_load(SmsMod* mod, const SmsApi* api)
{
	if (!SMS_API_HAS(api->core, subscribe))
		return 1;
	api->core->subscribe(mod, SMS_EV_FRAME, on_frame, NULL, SMS_PRIORITY_NORMAL);
	if (SMS_API_HAS(api->core, mod_info))
		api->core->log(mod, SMS_LOG_INFO, "%s", api->core->mod_info(mod, "name"));
	return 0;
}
