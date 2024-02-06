#define _GNU_SOURCE
#include <handy.h>
#include <dlfcn.h>

void hdy_style_manager_set_color_scheme(HdyStyleManager* self, HdyColorScheme color_scheme)
{
    void (*hdy_style_manager_set_color_scheme_orig)(HdyStyleManager* self, HdyColorScheme color_scheme) = dlsym(RTLD_NEXT, "hdy_style_manager_set_color_scheme");
    if(hdy_style_manager_set_color_scheme_orig)
        hdy_style_manager_set_color_scheme_orig(self, HDY_COLOR_SCHEME_DEFAULT);
}
