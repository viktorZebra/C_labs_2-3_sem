#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ui.h"
#include "ui_input.h"

static int onClosing(uiWindow *w, void *data);
static int onShouldQuit(void *data);


int main(void)
{
    uiInitOptions options;
    const char *err;
    uiTab *tab;

    memset(&options, 0, sizeof (uiInitOptions));
    err = uiInit(&options);
    if (err != NULL)
    {
        fprintf(stderr, "error initializing libui: %s", err);
        uiFreeInitError(err);
        return 1;
    }

    mainwin = uiNewWindow("prosto zagolovok", 640, 300, 1);
    uiWindowOnClosing(mainwin, onClosing, NULL);
    uiOnShouldQuit(onShouldQuit, mainwin);

    tab = uiNewTab();
    uiWindowSetChild(mainwin, uiControl(tab));
    uiWindowSetMargined(mainwin, 1);

    uiTabAppend(tab, "Processing array", fileInputOutput());
    uiTabSetMargined(tab, 0, 1);

    uiControlShow(uiControl(mainwin));
    uiMain();

    return 0;
}

static int onClosing(uiWindow *w, void *data)
{
    uiQuit();
    return 1;
}

static int onShouldQuit(void *data)
{
    uiWindow *mainwin = uiWindow(data);
    uiControlDestroy(uiControl(mainwin));
    return 1;
}
