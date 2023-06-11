#include "Exports.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct App App;

APP_EXPORT App*
app_new();

APP_EXPORT const char*
app_title();

APP_EXPORT void
app_init(App* self);

APP_EXPORT void
app_dispose(App* self);

APP_EXPORT void
app_frame(App* self);

#ifdef __cplusplus
}
#endif