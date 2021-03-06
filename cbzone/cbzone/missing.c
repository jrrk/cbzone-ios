#include <assert.h>
#include "c_includes.h"

typedef struct _xEvent {
    union {
	struct {
		struct {
		    char bytes[20];
		} b;
	} clientMessage;
    } u;
} xEvent;

typedef struct {
    char type;                  /* X_Error */
    char errorCode;
    char pad1;
} xError;

struct _XGC
{   void *ext_data;
    int gid;
    void *rects;
    int dashes;
    int dirty;
    XGCValues values;
};

struct _XDisplay
{
    XExtData *ext_data;     /* hook for extension to hang data */
    struct _XFreeFuncs *free_funcs; /* internal free functions */
    int fd;                 /* Network socket. */
    int conn_checker;         /* ugly thing used by _XEventsQueued */
    int proto_major_version;/* maj. version of server's X protocol */
    int proto_minor_version;/* minor version of server's X protocol */
    char *vendor;           /* vendor of the server hardware */
    XID resource_base;      /* resource ID base */
    XID resource_mask;      /* resource ID mask bits */
    XID resource_id;        /* allocator current ID */
    int resource_shift;     /* allocator shift to correct bits */
    XID (*resource_alloc)(  /* allocator function */
                          struct _XDisplay*
                          );
    int byte_order;         /* screen byte order, LSBFirst, MSBFirst */
    int bitmap_unit;        /* padding and data requirements */
    int bitmap_pad;         /* padding requirements on bitmaps */
    int bitmap_bit_order;   /* LeastSignificant or MostSignificant */
    int nformats;           /* number of pixmap formats in list */
    ScreenFormat *pixmap_format;    /* pixmap format list */
    int vnumber;            /* Xlib's X protocol version number. */
    int release;            /* release of the server */
    struct _XSQEvent *head, *tail;  /* Input event queue. */
    int qlen;               /* Length of input event queue */
    unsigned long last_request_read; /* seq number of last event read */
    unsigned long request;  /* sequence number of last request. */
    char *last_req;         /* beginning of last request, or dummy */
    char *buffer;           /* Output buffer starting address. */
    char *bufptr;           /* Output buffer index pointer. */
    char *bufmax;           /* Output buffer maximum+1 address. */
    unsigned max_request_size; /* maximum number 32 bit words in request*/
    struct _XrmHashBucketRec *db;
    int (*synchandler)(     /* Synchronization handler */
                       struct _XDisplay*
                       );
    char *display_name;     /* "host:display" string used on this connect*/
    int default_screen;     /* default screen for operations */
    int nscreens;           /* number of screens on this server*/
    Screen *screens;        /* pointer to list of screens */
    unsigned long motion_buffer;    /* size of motion buffer */
    volatile unsigned long flags;      /* internal connection flags */
    int min_keycode;        /* minimum defined keycode */
    int max_keycode;        /* maximum defined keycode */
    KeySym *keysyms;        /* This server's keysyms */
    XModifierKeymap *modifiermap;   /* This server's modifier keymap */
    int keysyms_per_keycode;/* number of rows */
    char *xdefaults;        /* contents of defaults from server */
    char *scratch_buffer;   /* place to hang scratch buffer */
    unsigned long scratch_length;   /* length of scratch buffer */
    int ext_number;         /* extension number on this display */
    struct _XExten *ext_procs; /* extensions initialized on this display */
    /*
     * the following can be fixed size, as the protocol defines how
     * much address space is available.
     * While this could be done using the extension vector, there
     * may be MANY events processed, so a search through the extension
     * list to find the right procedure for each event might be
     * expensive if many extensions are being used.
     */
    Bool (*event_vec[128])( /* vector for wire to event */
                           Display *       /* dpy */,
                           XEvent *        /* re */,
                           xEvent *        /* event */
                           );
    KeySym lock_meaning;       /* for XLookupString */
    struct _XLockInfo *lock;   /* multi-thread state, display lock */
    struct _XInternalAsync *async_handlers; /* for internal async */
    unsigned long bigreq_size; /* max size of big requests */
    struct _XLockPtrs *lock_fns; /* pointers to threads functions */
    void (*idlist_alloc)(      /* XID list allocator function */
                         Display *       /* dpy */,
                         XID *           /* ids */,
                         int             /* count */
                         );
    /* things above this line should not move, for binary compatibility */
    struct _XKeytrans *key_bindings; /* for XLookupString */
    Font cursor_font;          /* for XCreateFontCursor */
    struct _XDisplayAtoms *atoms; /* for XInternAtom */
    unsigned int mode_switch;  /* keyboard group modifiers */
    unsigned int num_lock;  /* keyboard numlock modifiers */
    struct _XContextDB *context_db; /* context database */
    Bool (**error_vec)(     /* vector for wire to error */
                       Display     *   /* display */,
                       XErrorEvent *   /* he */,
                       xError      *   /* we */
                       );
    /*
     * Xcms information
     */
    struct {
        XPointer defaultCCCs;  /* pointer to an array of default XcmsCCC */
        XPointer clientCmaps;  /* pointer to linked list of XcmsCmapRec */
        XPointer perVisualIntensityMaps;
        /* linked list of XcmsIntensityMap */
    } cms;
    struct _XIMFilter *im_filters;
    struct _XSQEvent *qfree; /* unallocated event queue elements */
    unsigned long next_event_serial_num; /* inserted into next queue elt */
    struct _XExten *flushes; /* Flush hooks */
    struct _XConnectionInfo *im_fd_info; /* _XRegisterInternalConnection */
    int im_fd_length;       /* number of im_fd_info */
    struct _XConnWatchInfo *conn_watchers; /* XAddConnectionWatch */
    int watcher_count;      /* number of conn_watchers */
    XPointer filedes;       /* struct pollfd cache for _XWaitForReadable */
    int (*savedsynchandler)( /* user synchandler when Xlib usurps */
                            Display *       /* dpy */
                            );
    XID resource_max;       /* allocator max ID */
    int xcmisc_opcode;      /* major opcode for XC-MISC */
    struct _XkbInfoRec *xkb_info; /* XKB info */
    struct _XtransConnInfo *trans_conn; /* transport connection object */
    struct _X11XCBPrivate *xcb; /* XCB glue private data */
    
    /* Generic event cookie handling */
    unsigned int next_cookie; /* next event cookie */
    /* vector for wire to generic event, index is (extension - 128) */
    Bool (*generic_event_vec[128])(
                                   Display *       /* dpy */,
                                   XGenericEventCookie *   /* Xlib event */,
                                   xEvent *        /* wire event */);
    /* vector for event copy, index is (extension - 128) */
    Bool (*generic_event_copy_vec[128])(
                                        Display *       /* dpy */,
                                        XGenericEventCookie *   /* in */,
                                        XGenericEventCookie *   /* out*/);
    void *cookiejar;  /* cookie events returned but not claimed */
};

WidgetClass shellWidgetClass;
WidgetClass overrideShellWidgetClass;
WidgetClass wmShellWidgetClass;
WidgetClass transientShellWidgetClass;
WidgetClass topLevelShellWidgetClass;
WidgetClass applicationShellWidgetClass;
WidgetClass sessionShellWidgetClass;

Window XCreateSimpleWindow(
                           Display*		arg1,
                           Window		arg2,
                           int			arg3,
                           int			arg4,
                           unsigned int	arg5,
                           unsigned int	arg6,
                           unsigned int	arg7,
                           unsigned long	arg8,
                           unsigned long	arg9
                           )
{
    static Window w;
    return w;
}

extern Pixmap XCreatePixmapFromBitmapData(
                                          Display*		arg1,
                                          Drawable		arg2,
                                          char*		    arg3,
                                          unsigned int	arg4,
                                          unsigned int	arg5,
                                          unsigned long	arg6,
                                          unsigned long	arg7,
                                          unsigned int	arg8
                                          );

extern int XFlush(
                  Display *arg
                  ) { return 0;}
int XDrawArc(
             Display*		arg1,
             Drawable		arg2,
             GC             arg3,
             int			cx_r,
             int			cy_r,
             unsigned int	r2_1,
             unsigned int	r2_2,
             int			start,
             int			stop
             )
{
    float wid = arg1->screens->width;
    float height = arg1->screens->height;
    float oldx, oldy;
    for (float ang = start; ang < stop; ang += 256)
    {
        float xinc = r2_1/2*sin(ang/64*M_PI/180);
        float yinc = r2_2/2*cos(ang/64*M_PI/180);
        float x = cx_r + r2_1/2 + xinc;
        float y = cy_r + r2_2/2 + yinc;
        if (ang != start)
            drawLineRel(x/wid,y/height,oldx/wid,oldy/height, arg3->values.foreground);
        oldx = x;
        oldy = y;
    }
    return 0;
}

int XSetFont(
             Display*		arg1,
             GC             arg2,
             Font           arg3
             )
{
    arg2->values.font = arg3;
    return 0;
}

int XSetForeground(
                   Display*		arg1,
                   GC			arg2,
                   unsigned long arg3
                   )
{
    arg2->values.foreground = arg3;
    return 0;
}

int XUngrabPointer(
                   Display*		arg1,
                   Time         arg2
                   )
 {
     return 0;
 }

int XWarpPointer(
                 Display*		arg1,
                 Window         arg2,
                 Window         arg3,
                 int			arg4,
                 int			arg5,
                 unsigned int	arg6,
                 unsigned int	arg7,
                 int			arg8,
                 int			arg9
                 )
{
    return 0;
}

static int myhead;
static int mytail;
static XEvent myevent[256], *eventptr;
static Position_t myposn;
static float rot11, rot12, rot21, rot22, offx, offy;

void init_event(void)
{
    myevent[0].type = Expose;
    myevent[0].xexpose.x = 500;
    myevent[0].xexpose.y = 355;
    myhead = 1;
    mytail = 0;
}

static float min(float a, float b)
{
    return a < b ? a : b;
}

void rot(float r11,float r12,float r21,float r22, float ox, float oy)
{
    rot11 = r11;
    rot12 = r12;
    rot21 = r21;
    rot22 = r22;
    offx = ox;
    offy = oy;
}

static double turbo(double x)
{
    return opt->hypersensitivity > 0.1 ? exp(x*opt->hypersensitivity) : min(1, x);
}

void myaccel(float acceleration_x, float acceleration_y)
{
	static CGPoint levelPosition;
	static float tiltDirection;
	static float tiltMagnitude;
	
	tiltDirection = atan2(acceleration_y, acceleration_x);
	tiltMagnitude = turbo( acceleration_x*acceleration_x+acceleration_y*acceleration_y);
	levelPosition.y = sin(tiltDirection)*tiltMagnitude;
	levelPosition.x = -cos(tiltDirection)*tiltMagnitude;

    myposn.x = 500 * (1.0 + rot11 * levelPosition.x + rot12 * levelPosition.y + offx);
    myposn.y = 355 * (1.0 + rot21 * levelPosition.x + rot22 * levelPosition.y + offy);
    eventptr = myevent + myhead;
    eventptr->type = MotionNotify;
    eventptr->xmotion.x = myposn.x;
    eventptr->xmotion.y = myposn.y;
    myhead = (myhead+1)&255;
}

void mytouch(void)
{
    myevent[myhead].type = ButtonPress;
    myevent[myhead].xbutton.x = myposn.x;
    myevent[myhead].xbutton.y = myposn.y;
    myevent[myhead].xbutton.button = 1;
    myhead = (myhead+1)&255;
    myevent[myhead].type = ButtonRelease;
    myevent[myhead].xbutton.x = myposn.x;
    myevent[myhead].xbutton.y = myposn.y;
    myevent[myhead].xbutton.button = 1;
    myhead = (myhead+1)&255;
}

int XPending(
             Display* arg
             )
{
    return myhead != mytail;
}

int XSetBackground(
                   Display*	arg1	,
                   GC		arg2	,
                   unsigned long arg3
                   )
{
    arg2->values.background = arg3;
    return 0;
}

extern int XNextEvent(
                      Display*		arg1,
                      XEvent*		ev
                      )
{
    if (myhead != mytail)
    {
        memcpy(ev, myevent+mytail, sizeof(XEvent));
        mytail = (mytail+1)&255;
    }
    else memset(ev, 0, sizeof(XEvent));
   return 0;
}

int XWindowEvent(
                 Display*		arg1,
                 Window		arg2,
                 long		arg3,
                 XEvent*	ev
                 )
{
    if (myhead != mytail)
    {
        memcpy(ev, myevent+mytail, sizeof(XEvent));
        mytail = (mytail+1)&255;
    }
    else memset(ev, 0, sizeof(XEvent));
    return 0;
}

extern int XIconifyWindow(
                          Display*		arg1,
                          Window		arg2,
                          int			arg3
                          ) { return 0;}
int XDrawRectangle(
                   Display*		arg1,
                   Drawable		arg2,
                   GC			arg3,
                   int			x,
                   int			y,
                   unsigned int	w,
                   unsigned int	h
                   )
{
    float wid = arg1->screens->width;
    float height = arg1->screens->height;
    drawLineRel(x/wid,y/height,(x+w)/wid,y/height, arg3->values.foreground);
    drawLineRel((x+w)/wid,y/height,(x+w)/wid,(y+h)/height, arg3->values.foreground);
    drawLineRel((x+w)/wid,(y+h)/height,x/wid,(y+h)/height, arg3->values.foreground);
    drawLineRel(x/wid,(y+h)/height,x/wid,y/height, arg3->values.foreground);
    return 0;
}
int XBell(
          Display*		arg1,
          int           arg2
          ) { return 0; }

int XSetClipRectangles(
                       Display*		arg1,
                       GC			arg2,
                       int			arg3,
                       int			arg4,
                       XRectangle*	arg5	,
                       int			arg6,
                       int			arg7
                       ) { return 0; }
int XFillArc(
             Display*		arg1,
             Drawable		arg2,
             GC             arg3,
             int			arg4,
             int			arg5,
             unsigned int	arg6,
             unsigned int	arg7,
             int			arg8,
             int			arg9
             )
{
    return 0;
}

int XFillRectangle(
                   Display*		arg1,
                   Drawable		arg2,
                   GC			arg3,
                   int			x,
                   int			y,
                   unsigned int	w,
                   unsigned int	h
                   )
{
    float wid = arg1->screens->width;
    float height = arg1->screens->height;
    drawLineRel(x/wid,y/height,(x+w)/wid,y/height, arg3->values.foreground);
    drawLineRel((x+w)/wid,y/height,(x+w)/wid,(y+h)/height, arg3->values.foreground);
    drawLineRel((x+w)/wid,(y+h)/height,x/wid,(y+h)/height, arg3->values.foreground);
    drawLineRel(x/wid,(y+h)/height,x/wid,y/height, arg3->values.foreground);
    return 0;
    return 0;
}
int XCopyArea(
              Display*		arg1,
              Drawable		arg2,
              Drawable		arg3,
              GC			arg4,
              int			arg5,
              int			arg6,
              unsigned int	arg7,
              unsigned int	arg8,
              int			arg9,
              int			arg10
              )
{
    return 0;
}

int XDrawLines(
               Display*		dsp,
               Drawable		d,
               GC			gc,
               XPoint*		pnt,
               int			npnts,
               int			mode
               )
{
    float wid = dsp->screens->width;
    float height = dsp->screens->height;
	for (int it = 0; it < npnts-1; it++)
	{
        drawLineRel(pnt[it].x/wid,pnt[it].y/height,
                    pnt[it+1].x/wid,pnt[it+1].y/height,
                    gc->values.foreground);
    }
    return 0;
}

void XtToolkitInitialize() { return ; }
XtAppContext XtCreateApplicationContext()
{
    static XtAppContext a;
    return a;
}

static Display _d;
Screen _s[1];
Visual _v[1];

Display *XtOpenDisplay(
                              XtAppContext 	arg1,
                              __const char*	arg2,
                              __const char*	arg3,
                              __const char*	arg4,
                              XrmOptionDescRec*	arg5,
                              Cardinal 		arg6,
                              int*          arg7,
                              char**		arg8
                              )
{
    _s->root_visual = _v;
    _s->root_depth = 8;
    _s->width = 1000;
    _s->height = 710;
    _v->map_entries = 256;
    _v->vclass = TrueColor;
    _v->visualid = 34;
    _v->red_mask = 0xFF0000;
    _v->green_mask = 0xFF00;
    _v->blue_mask = 0xFF;
    _v->bits_per_rgb = 8;
    _d.screens = _s;
    _d.nscreens = 1;
        return &_d;
    }

int XFreeColors(
                       Display*		arg1,
                       Colormap		arg2,
                       unsigned long*	arg3,
                       int			arg4,
                       unsigned long arg5
                       )
{
    return 256;
}

typedef int Status;

int XParseColor(
                   Display*       arg1     /* display */,
                   Colormap       arg2     /* colormap */,
                   const char*    arg3     /* spec */,
                   XColor*        arg4     /* exact_def_return */
                   )
{
    struct cnv {
        const char *idx;
        const struct { unsigned short r,g,b; } rgb;
    } cols[] =
{
    {"black", {0,0,0}},
    {"gray50", {32639,32639,32639}},
    {"green", {0,65535,0}},
    {"red", {65535,0,0}},
    {"skyblue", {34695,52942,60395}},
    {"yellow", {65535,65535,0}}
};
    memset(arg4, 0, sizeof(XColor));
    for (int i = 0; i < sizeof(cols)/sizeof(*cols); i++)
    {
    if (!strcmp(arg3,cols[i].idx))
        {
            arg4->red = cols[i].rgb.r;
            arg4->green = cols[i].rgb.g;
            arg4->blue = cols[i].rgb.b;
            return 0;
        }
        
    }
    if (*arg3 == '#')
    {
        unsigned int r, g, b, cnt = sscanf(arg3,"#%4X%4X%4X", &r, &g, &b);
        if (cnt == 3)
        {
            arg4->red = r;
            arg4->green = g;
            arg4->blue = b;
            return 0;
        }        
    }
    return -1;
}

int XSelectInput(
                 Display*		arg1,
                 Window         arg2,
                 long           arg3
                 ) { return 0; }

int XStoreName(
               Display*		arg1,
               Window		arg2,
               const char*	arg3
               ) { return 0; }

enum styles {titlestyle,controlstyle,generalstyle,warningstyle};

static unsigned long _drawforeground;
static float _wid, _w;
static float _height, _h;
static float _x0, _y0, _x1, _y1;
static enum styles _style;

void fcoord(float x0, float y0, float x1, float y1)
{
    float xscale, yscale;
    switch(_style)
    {
        case titlestyle:
            xscale = 1.0;
            yscale = 0.5;
            break;
        case controlstyle:
            xscale = 0.5;
            yscale = 0.5;
            break;
        case generalstyle:
            xscale = 0.7;
            yscale = 0.5;
            break;
        case warningstyle:
            xscale = 1.0;
            yscale = 0.7;
            break;
    }
    _x1 += x1*xscale*_w;
    _y1 = y1*yscale*_h;
}

void fline(float x0, float y0, float x1, float y1)
{
        drawLineRel((x0*_w+_x0+_x1)/_wid,(_y0+_y1-y0*_h)/_height,
                    (x1*_w+_x0+_x1)/_wid,(_y0+_y1-y1*_h)/_height,
                    _drawforeground);
}

extern Font controlfont, titlefont, generalfont, warningfont;
extern Display *d;
extern Window w, root;
extern GC BitBltGC, DrawGC, TextGC, EraseGC;

static int myDrawImageString(
                     Display*		arg1,
                     Drawable		arg2,
                     GC             arg3,
                     int			x,
                     int			y,
                     __const char*	arg6,
                     int			arg7,
                     float          scale
                     )
{
    float xoff, yoff;
    if (arg3->values.font == titlefont) _style = titlestyle;
    if (arg3->values.font == controlfont) _style = controlstyle;
    if (arg3->values.font == warningfont) _style = warningstyle;
    if (arg3->values.font == generalfont) _style = generalstyle;
    _w = scale;
    _h = scale;
    switch(_style)
    {
        case titlestyle:
            xoff = -50.0;
            yoff = -20.0;
            break;
        case controlstyle:
            xoff = -15.0;
            yoff = +30.0;
            break;
        case generalstyle:
            xoff = -50.0;
            yoff = -8.0;
            break;
        case warningstyle:
            xoff = -15.0;
            yoff = +30.0;
            break;
    }
    _drawforeground = arg3->values.foreground;
    _wid = arg1->screens->width;
    _height = arg1->screens->height;
    _x0 = x+xoff;
    _y0 = y+yoff;
    _x1 = 0;
    _y1 = 0;
    const char *msg = arg6;
    while (*msg) char_tab(*msg++);
    return 0;
}

void printstring(x, y, string, nchars, scale)
int x, y;
char* string;
int nchars;
float scale;
{
    myDrawImageString (d, w, TextGC, x, y, string, nchars, scale);
}

int XSetIconName(
                 Display*		arg1,
                 Window         arg2,
                 __const char*  arg3
                 ) { return 0; }
int XDefineCursor(
                  Display*		arg1,
                  Window		arg2,
                  Cursor		arg3
                  ) { return 0; }
int XMapRaised(
               Display*		arg1,
               Window       arg2
               ) { return 0; }
int XQueryColor(
                Display*	arg1	,
                Colormap	arg2	,
                XColor*		arg3
                )
{
    return 0;
}

int XClearWindow(
                 Display*	arg1	,
                 Window     arg2
                 )
{
    resetdraw();
    return 0;
}

extern int XLookupString(
                         XKeyEvent*		arg1,
                         char*          arg2,
                         int			arg3,
                         KeySym*		arg4,
                         XComposeStatus*arg5
                         ) { return 0; }

int XSetNormalHints(
                    Display*		arg1,
                    Window          arg2,
                    XSizeHints*     arg3
                    ) { return 0; }
int XSetClipMask(
                 Display*	arg1	,
                 GC			arg2,
                 Pixmap		arg3
                 )
{
    return 0;
}

int XSetWindowColormap(
                       Display*		arg1,
                       Window		arg2,
                       Colormap		arg3
                       )
{
    return 0;
}

int XSetWMHints(
                Display*	arg1	,
                Window		arg2,
                XWMHints*	arg3
                ) { return 0; }

void XtGetApplicationResources(
                               Widget           arg1,
                               XtPointer 		arg2,
                               XtResourceList 	arg3,
                               Cardinal 		arg4,
                               ArgList          arg5,
                               Cardinal 		arg6
                               )
 {
     Optionp opt = (Optionp) arg2;
     const char* cname[] = {"black", "skyblue", "skyblue", "skyblue", "skyblue", "gray50", "gray50",  "gray50", "red", "red", "red", "green", "green", "green", "green",  "green", "green", "yellow", "yellow"};
     memcpy(opt->cname, cname, sizeof cname);
     memset(opt->cpi, 0, sizeof(opt->cpi));
     opt->mono = 0;
     //     opt->fullscreen = 0;
     opt->fullscreen = 1;
     opt->defaultcolormap = 0;
     opt->fading_colors = 0;
     opt->max_colors = 0;
     return;
 }
int XGrabPointer(
                 Display*        arg1    /* display */,
                 Window          arg2    /* grab_window */,
                 Bool            arg3    /* owner_events */,
                 unsigned int    arg4    /* event_mask */,
                 int             arg5    /* pointer_mode */,
                 int             arg6    /* keyboard_mode */,
                 Window          arg7    /* confine_to */,
                 Cursor          arg8    /* cursor */,
                 Time            arg9    /* time */
                 )
{
    return 0;
}

int XSync(
          Display*		arg1,
          int           arg2
          )
{
    return 0;
}

int XFreeColormap(
                  Display*	arg1	,
                  Colormap  arg2
                  )
{
    return 0;
}

int XAllocColor(
                Display*	d	,
                Colormap	cmaparg	,
                XColor*		color
                )
{
    color->pixel = ((color->red >> 8)<<16)|((color->green >> 8)<<8)|(color->blue >> 8);
    return 1 ;
}

Pixmap XCreatePixmapFromBitmapData(
                                   Display*       arg1     /* display */,
                                   Drawable       arg2     /* d */,
                                   char*          arg3     /* data */,
                                   unsigned int   arg4     /* width */,
                                   unsigned int   arg5     /* height */,
                                   unsigned long  arg6     /* fg */,
                                   unsigned long  arg7     /* bg */,
                                   unsigned int   arg8     /* depth */
                                   ) { static Pixmap p; return p; };

Pixmap XCreateBitmapFromData(
                             Display*        arg1    /* display */,
                             Drawable        arg2    /* d */,
                             const char*   arg3    /* data */,
                             unsigned int    arg4    /* width */,
                             unsigned int    arg5    /* height */
                             ) { static Pixmap p; return p; }

Cursor XCreatePixmapCursor(
                           Display*       arg1     /* display */,
                           Pixmap         arg2     /* source */,
                           Pixmap         arg3     /* mask */,
                           XColor*        arg4     /* foreground_color */,
                           XColor*        arg5     /* background_color */,
                           unsigned int   arg6     /* x */,
                           unsigned int   arg7     /* y */
                           ) { static Cursor c; return c; }

Cursor XCreateGlyphCursor(
                          Display*         arg1   /* display */,
                          Font             arg2  /* source_font */,
                          Font             arg3   /* mask_font */,
                          unsigned int     arg4   /* source_char */,
                          unsigned int     arg5   /* mask_char */,
                          XColor const * arg6   /* foreground_color */,
                          XColor const * arg7  /* background_color */
                          ) { static Cursor c; return c; }


Font XLoadFont(
               Display*    arg1        /* display */,
               const char*  arg2     /* name */
               )
{
    static Font f;
    return f;
}

Colormap XCreateColormap(
                         Display*    arg1        /* display */,
                         Window      arg2        /* w */,
                         Visual*     arg3        /* visual */,
                         int         arg4        /* alloc */
                         )
{
    static Colormap cmap;
    return cmap;
}

Widget XtAppCreateShell(
                        const char *  arg1 /* application_name */,
                        const char *  arg2 /* application_class */,
                        WidgetClass      arg3   /* widget_class */,
                        Display*         arg4   /* display */,
                        ArgList          arg5   /* args */,
                        Cardinal         arg6   /* num_args */
                        )
{
    static Widget w;
    return w;
}

GC XCreateGC(
             Display*        arg1    /* display */,
             Drawable        arg2    /* d */,
             unsigned long   arg3    /* valuemask */,
             XGCValues*      arg4    /* values */
             )
{
    GC ptr = calloc(1, sizeof(struct _XGC));
    memcpy(&(ptr->values), arg4, sizeof(XGCValues));
    return ptr;
}

int XDrawSegments(
                         Display*   arg1         /* display */,
                         Drawable   arg2         /* d */,
                         GC         arg3         /* gc */,
                         XSegment*  pnt          /* segments */,
                         int        npnts        /* nsegments */
                  )
{
    unsigned long drawforeground = arg3->values.foreground;
    float wid = arg1->screens->width;
    float height = arg1->screens->height;
	for (int it = 0; it < npnts; it++)
	{
        drawLineRel(pnt[it].x1/wid,pnt[it].y1/height,
                    pnt[it].x2/wid,pnt[it].y2/height,
                    drawforeground);
    }
return 0;
}

XFontStruct *XLoadQueryFont(
                                   Display* arg1           /* display */,
                                   const char* arg2       /* name */
                            )
{
    XFontStruct *f = calloc(sizeof(XFontStruct),1);
    XExtData *e = calloc(sizeof(XExtData),1);
    unsigned long i, tot = 0;
    char *ptr;
    e->private_data = malloc(strlen(arg2)+1);
    ptr = e->private_data;
    for (i= 0; i < strlen(arg2); i++)
    {
        *ptr++ = arg2[i];
        tot  = (tot * 31) + arg2[i];
    }
    *ptr = 0;
    f->fid = tot & 0xFFFF;
    f->ext_data = e;
    return f;
}

const char XtStrings[3000] = {"hello"};
