#define None                 0L	/* universal null resource or null atom */

#define NoEventMask			0L
#define KeyPressMask			(1L<<0)
#define KeyReleaseMask			(1L<<1)
#define ButtonPressMask			(1L<<2)
#define ButtonReleaseMask		(1L<<3)
#define EnterWindowMask			(1L<<4)
#define LeaveWindowMask			(1L<<5)
#define PointerMotionMask		(1L<<6)
#define PointerMotionHintMask		(1L<<7)
#define Button1MotionMask		(1L<<8)
#define Button2MotionMask		(1L<<9)
#define Button3MotionMask		(1L<<10)
#define Button4MotionMask		(1L<<11)
#define Button5MotionMask		(1L<<12)
#define ButtonMotionMask		(1L<<13)
#define KeymapStateMask			(1L<<14)
#define ExposureMask			(1L<<15)
#define VisibilityChangeMask		(1L<<16)
#define StructureNotifyMask		(1L<<17)
#define ResizeRedirectMask		(1L<<18)
#define SubstructureNotifyMask		(1L<<19)
#define SubstructureRedirectMask	(1L<<20)
#define FocusChangeMask			(1L<<21)
#define PropertyChangeMask		(1L<<22)
#define ColormapChangeMask		(1L<<23)
#define OwnerGrabButtonMask		(1L<<24)

#define GrabModeSync		0
#define GrabModeAsync		1

/* GrabPointer, GrabKeyboard reply status */

#define GrabSuccess		0
#define AlreadyGrabbed		1
#define GrabInvalidTime		2
#define GrabNotViewable		3
#define GrabFrozen		4

#define CurrentTime          0L	/* special Time */

#define StaticGray		0
#define GrayScale		1
#define StaticColor		2
#define PseudoColor		3
#define TrueColor		4
#define DirectColor		5

#define XYBitmap		0	/* depth 1, XYFormat */
#define XYPixmap		1	/* depth == drawable depth */
#define ZPixmap			2	/* depth == drawable depth */

/*****************************************************************
 *  COLOR MAP STUFF
 *****************************************************************/

/* For CreateColormap */

#define AllocNone		0	/* create map with no entries */
#define AllocAll		1	/* allocate entire map writeable */


/* Flags used in StoreNamedColor, StoreColors */

#define DoRed			(1<<0)
#define DoGreen			(1<<1)
#define DoBlue			(1<<2)

#define GCFunction              (1L<<0)
#define GCPlaneMask             (1L<<1)
#define GCForeground            (1L<<2)
#define GCBackground            (1L<<3)
#define GCLineWidth             (1L<<4)
#define GCLineStyle             (1L<<5)
#define GCCapStyle              (1L<<6)
#define GCJoinStyle		(1L<<7)
#define GCFillStyle		(1L<<8)
#define GCFillRule		(1L<<9)
#define GCTile			(1L<<10)
#define GCStipple		(1L<<11)
#define GCTileStipXOrigin	(1L<<12)
#define GCTileStipYOrigin	(1L<<13)
#define GCFont 			(1L<<14)
#define GCSubwindowMode		(1L<<15)
#define GCGraphicsExposures     (1L<<16)
#define GCClipXOrigin		(1L<<17)
#define GCClipYOrigin		(1L<<18)
#define GCClipMask		(1L<<19)
#define GCDashOffset		(1L<<20)
#define GCDashList		(1L<<21)
#define GCArcMode		(1L<<22)

#define	GXclear			0x0		/* 0 */
#define GXand			0x1		/* src AND dst */
#define GXandReverse		0x2		/* src AND NOT dst */
#define GXcopy			0x3		/* src */
#define GXandInverted		0x4		/* NOT src AND dst */
#define	GXnoop			0x5		/* dst */
#define GXxor			0x6		/* src XOR dst */
#define GXor			0x7		/* src OR dst */
#define GXnor			0x8		/* NOT src AND NOT dst */
#define GXequiv			0x9		/* NOT src XOR dst */
#define GXinvert		0xa		/* NOT dst */
#define GXorReverse		0xb		/* src OR NOT dst */
#define GXcopyInverted		0xc		/* NOT src */
#define GXorInverted		0xd		/* NOT src OR dst */
#define GXnand			0xe		/* NOT src OR NOT dst */
#define GXset			0xf		/* 1 */

/* LineStyle */

#define LineSolid		0
#define LineOnOffDash		1
#define LineDoubleDash		2

/* capStyle */

#define CapNotLast		0
#define CapButt			1
#define CapRound		2
#define CapProjecting		3

/* joinStyle */

#define JoinMiter		0
#define JoinRound		1
#define JoinBevel		2

/* fillStyle */

#define FillSolid		0
#define FillTiled		1
#define FillStippled		2
#define FillOpaqueStippled	3

/* fillRule */

#define EvenOddRule		0
#define WindingRule		1

/* subwindow mode */

#define ClipByChildren		0
#define IncludeInferiors	1

/* SetClipRectangles ordering */

#define Unsorted		0
#define YSorted			1
#define YXSorted		2
#define YXBanded		3

/* CoordinateMode for drawing routines */

#define CoordModeOrigin		0	/* relative to the origin */
#define CoordModePrevious       1	/* relative to previous point */

/* Polygon shapes */

#define Complex			0	/* paths may intersect */
#define Nonconvex		1	/* no paths intersect, but not convex */
#define Convex			2	/* wholly convex */

/* Arc modes for PolyFillArc */

#define ArcChord		0	/* join endpoints of arc */
#define ArcPieSlice		1	/* join endpoints to center of arc */

#define XtRInt ((char*)&XtStrings[1718])
#define XtRImmediate ((char*)&XtStrings[1695])
#define XtRString ((char*)&XtStrings[1797])
#define XtRBoolean ((char*)&XtStrings[1561])
#define XtOffset(p_type,field) \
((Cardinal) (((char *) (&(((p_type)NULL)->field))) - ((char *) NULL)))

#define USPosition      (1L << 0) /* user specified x, y */
#define USSize          (1L << 1) /* user specified width, height */

#define PPosition       (1L << 2) /* program specified position */
#define PSize           (1L << 3) /* program specified size */
#define PMinSize        (1L << 4) /* program specified minimum size */
#define PMaxSize        (1L << 5) /* program specified maximum size */
#define PResizeInc      (1L << 6) /* program specified resize increments */
#define PAspect         (1L << 7) /* program specified min and max aspect ratios */
#define PBaseSize       (1L << 8) /* program specified base for incrementing */
#define PWinGravity     (1L << 9) /* program specified window gravity */

#define KeyPress		2
#define KeyRelease		3
#define ButtonPress		4
#define ButtonRelease		5
#define MotionNotify		6
#define EnterNotify		7
#define LeaveNotify		8
#define FocusIn			9
#define FocusOut		10
#define KeymapNotify		11
#define Expose			12
#define GraphicsExpose		13
#define NoExpose		14
#define VisibilityNotify	15
#define CreateNotify		16
#define DestroyNotify		17
#define UnmapNotify		18
#define MapNotify		19
#define MapRequest		20
#define ReparentNotify		21
#define ConfigureNotify		22
#define ConfigureRequest	23
#define GravityNotify		24
#define ResizeRequest		25
#define CirculateNotify		26
#define CirculateRequest	27
#define PropertyNotify		28
#define SelectionClear		29
#define SelectionRequest	30
#define SelectionNotify		31
#define ColormapNotify		32
#define ClientMessage		33
#define MappingNotify		34
#define GenericEvent		35

#define InputHint               (1L << 0)
#define StateHint               (1L << 1)
#define IconPixmapHint          (1L << 2)
#define IconWindowHint          (1L << 3)
#define IconPositionHint        (1L << 4)
#define IconMaskHint            (1L << 5)
#define WindowGroupHint         (1L << 6)
#define AllHints (InputHint|StateHint|IconPixmapHint|IconWindowHint| \
IconPositionHint|IconMaskHint|WindowGroupHint)
#define XUrgencyHint            (1L << 8)

#define XtNumber(arr)		((Cardinal) (sizeof(arr) / sizeof(arr[0])))

#define ConnectionNumber(dpy)   (((_XPrivDisplay)dpy)->fd)
#define RootWindow(dpy, scr)    (ScreenOfDisplay(dpy,scr)->root)
#define DefaultScreen(dpy)      (((_XPrivDisplay)dpy)->default_screen)
#define DefaultRootWindow(dpy)  (ScreenOfDisplay(dpy,DefaultScreen(dpy))->root)
#define DefaultVisual(dpy, scr) (ScreenOfDisplay(dpy,scr)->root_visual)
#define DefaultGC(dpy, scr)     (ScreenOfDisplay(dpy,scr)->default_gc)
#define BlackPixel(dpy, scr)    (ScreenOfDisplay(dpy,scr)->black_pixel)
#define WhitePixel(dpy, scr)    (ScreenOfDisplay(dpy,scr)->white_pixel)
#define AllPlanes               ((unsigned long)~0L)
#define QLength(dpy)            (((_XPrivDisplay)dpy)->qlen)
#define DisplayWidth(dpy, scr)  (ScreenOfDisplay(dpy,scr)->width)
#define DisplayHeight(dpy, scr) (ScreenOfDisplay(dpy,scr)->height)
#define DisplayWidthMM(dpy, scr)(ScreenOfDisplay(dpy,scr)->mwidth)
#define DisplayHeightMM(dpy, scr)(ScreenOfDisplay(dpy,scr)->mheight)
#define DisplayPlanes(dpy, scr) (ScreenOfDisplay(dpy,scr)->root_depth)
#define DisplayCells(dpy, scr)  (DefaultVisual(dpy,scr)->map_entries)
#define ScreenCount(dpy)        (((_XPrivDisplay)dpy)->nscreens)
#define ServerVendor(dpy)       (((_XPrivDisplay)dpy)->vendor)
#define ProtocolVersion(dpy)    (((_XPrivDisplay)dpy)->proto_major_version)
#define ProtocolRevision(dpy)   (((_XPrivDisplay)dpy)->proto_minor_version)
#define VendorRelease(dpy)      (((_XPrivDisplay)dpy)->release)
#define DisplayString(dpy)      (((_XPrivDisplay)dpy)->display_name)
#define DefaultDepth(dpy, scr)  (ScreenOfDisplay(dpy,scr)->root_depth)
#define DefaultColormap(dpy, scr)(ScreenOfDisplay(dpy,scr)->cmap)
#define BitmapUnit(dpy)         (((_XPrivDisplay)dpy)->bitmap_unit)
#define BitmapBitOrder(dpy)     (((_XPrivDisplay)dpy)->bitmap_bit_order)
#define BitmapPad(dpy)          (((_XPrivDisplay)dpy)->bitmap_pad)
#define ImageByteOrder(dpy)     (((_XPrivDisplay)dpy)->byte_order)
#define NextRequest(dpy)        (((_XPrivDisplay)dpy)->request + 1)
#define LastKnownRequestProcessed(dpy)  (((_XPrivDisplay)dpy)->last_request_read)
#define ScreenOfDisplay(dpy, scr)(&((_XPrivDisplay)dpy)->screens[scr])
#define DefaultScreenOfDisplay(dpy) ScreenOfDisplay(dpy,DefaultScreen(dpy))
#define DisplayOfScreen(s)      ((s)->display)
#define RootWindowOfScreen(s)   ((s)->root)
#define BlackPixelOfScreen(s)   ((s)->black_pixel)
#define WhitePixelOfScreen(s)   ((s)->white_pixel)
#define DefaultColormapOfScreen(s)((s)->cmap)
#define DefaultDepthOfScreen(s) ((s)->root_depth)
#define DefaultGCOfScreen(s)    ((s)->default_gc)
#define DefaultVisualOfScreen(s)((s)->root_visual)
#define WidthOfScreen(s)        ((s)->width)
#define HeightOfScreen(s)       ((s)->height)
#define WidthMMOfScreen(s)      ((s)->mwidth)
#define HeightMMOfScreen(s)     ((s)->mheight)
#define PlanesOfScreen(s)       ((s)->root_depth)
#define CellsOfScreen(s)        (DefaultVisualOfScreen((s))->map_entries)
#define MinCmapsOfScreen(s)     ((s)->min_maps)
#define MaxCmapsOfScreen(s)     ((s)->max_maps)
#define DoesSaveUnders(s)       ((s)->save_unders)
#define DoesBackingStore(s)     ((s)->backing_store)
#define EventMaskOfScreen(s)    ((s)->root_input_mask)

#ifdef __cplusplus
extern "C" {
#endif
    
typedef unsigned long XID;

typedef unsigned long Mask;

typedef unsigned long Atom;		

typedef unsigned long VisualID;
typedef unsigned long Time;

typedef XID Window;
typedef XID Drawable;

typedef XID Font;

typedef XID Pixmap;
typedef XID Cursor;
typedef XID Colormap;
typedef XID GContext;
typedef XID KeySym;

typedef unsigned char KeyCode;

		       

//typedef long int ptrdiff_t;

extern int
_Xmblen(

    char *str,
    int len

    );

typedef char *XPointer;

typedef struct _XExtData {
	int number;		
	struct _XExtData *next;	
	int (*free_private)(	
	struct _XExtData *extension
	);
	XPointer private_data;	
} XExtData;

typedef struct {		
	int extension;		
	int major_opcode;	
	int first_event;	
	int first_error;	
} XExtCodes;

typedef struct {
    int depth;
    int bits_per_pixel;
    int scanline_pad;
} XPixmapFormatValues;

typedef struct {
	int function;		
	unsigned long plane_mask;
	unsigned long foreground;
	unsigned long background;
	int line_width;		
	int line_style;	 	
	int cap_style;	  	

	int join_style;	 	
	int fill_style;	 	

	int fill_rule;	  	
	int arc_mode;		
	Pixmap tile;		
	Pixmap stipple;		
	int ts_x_origin;	
	int ts_y_origin;
        Font font;	        
	int subwindow_mode;     
	int graphics_exposures;
	int clip_x_origin;	
	int clip_y_origin;
	Pixmap clip_mask;	
	int dash_offset;	
	char dashes;
} XGCValues;

typedef struct _XGC

*GC;

typedef struct {
	XExtData *ext_data;	
	VisualID visualid;	

	int vclass;

	unsigned long red_mask, green_mask, blue_mask;	
	int bits_per_rgb;	
	int map_entries;	
} Visual;

typedef struct {
	int depth;		
	int nvisuals;		
	Visual *visuals;	
} Depth;

struct _XDisplay;		

typedef struct {
	XExtData *ext_data;	
	struct _XDisplay *display;
	Window root;		
	int width, height;	
	int mwidth, mheight;	
	int ndepths;		
	Depth *depths;		
	int root_depth;		
	Visual *root_visual;	
	GC default_gc;		
	Colormap cmap;		
	unsigned long white_pixel;
	unsigned long black_pixel;	
	int max_maps, min_maps;	
	int backing_store;	
	int save_unders;
	long root_input_mask;	
} Screen;

typedef struct {
	XExtData *ext_data;	
	int depth;		
	int bits_per_pixel;	
	int scanline_pad;	
} ScreenFormat;

typedef struct {
    Pixmap background_pixmap;	
    unsigned long background_pixel;	
    Pixmap border_pixmap;	
    unsigned long border_pixel;	
    int bit_gravity;		
    int win_gravity;		
    int backing_store;		
    unsigned long backing_planes;
    unsigned long backing_pixel;
    int save_under;		
    long event_mask;		
    long do_not_propagate_mask;	
    int override_redirect;	
    Colormap colormap;		
    Cursor cursor;		
} XSetWindowAttributes;

typedef struct {
    int x, y;			
    int width, height;		
    int border_width;		
    int depth;          	
    Visual *visual;		
    Window root;        	

    int xclass;

    int bit_gravity;		
    int win_gravity;		
    int backing_store;		
    unsigned long backing_planes;
    unsigned long backing_pixel;
    int save_under;		
    Colormap colormap;		
    int map_installed;		
    int map_state;		
    long all_event_masks;	
    long your_event_mask;	
    long do_not_propagate_mask; 
    int override_redirect;	
    Screen *screen;		
} XWindowAttributes;

typedef struct {
	int family;		
	int length;		
	char *address;		
} XHostAddress;

typedef struct {
	int typelength;		
	int valuelength;	
	char *type;		
	char *value;		
} XServerInterpretedAddress;

typedef struct _XImage {
    int width, height;		
    int xoffset;		
    int format;			
    char *data;			
    int byte_order;		
    int bitmap_unit;		
    int bitmap_bit_order;	
    int bitmap_pad;		
    int depth;			
    int bytes_per_line;		
    int bits_per_pixel;		
    unsigned long red_mask;	
    unsigned long green_mask;
    unsigned long blue_mask;
    XPointer obdata;		
    struct funcs {		
	struct _XImage *(*create_image)(
		struct _XDisplay* ,
		Visual*		,
		unsigned int	,
		int		,
		int		,
		char*		,
		unsigned int	,
		unsigned int	,
		int		,
		int		);
	int (*destroy_image)        (struct _XImage *);
	unsigned long (*get_pixel)  (struct _XImage *, int, int);
	int (*put_pixel)            (struct _XImage *, int, int, unsigned long);
	struct _XImage *(*sub_image)(struct _XImage *, int, int, unsigned int, unsigned int);
	int (*add_pixel)            (struct _XImage *, long);
	} f;
} XImage;

typedef struct {
    int x, y;
    int width, height;
    int border_width;
    Window sibling;
    int stack_mode;
} XWindowChanges;

typedef struct {
	unsigned long pixel;
	unsigned short red, green, blue;
	char flags;  
	char pad;
} XColor;

typedef struct {
    short x1, y1, x2, y2;
} XSegment;

typedef struct {
    short x, y;
} XPoint;

typedef struct {
    short x, y;
    unsigned short width, height;
} XRectangle;

typedef struct {
    short x, y;
    unsigned short width, height;
    short angle1, angle2;
} XArc;

typedef struct {
        int key_click_percent;
        int bell_percent;
        int bell_pitch;
        int bell_duration;
        int led;
        int led_mode;
        int key;
        int auto_repeat_mode;   
} XKeyboardControl;

typedef struct {
        int key_click_percent;
	int bell_percent;
	unsigned int bell_pitch, bell_duration;
	unsigned long led_mask;
	int global_auto_repeat;
	char auto_repeats[32];
} XKeyboardState;

typedef struct {
        Time time;
	short x, y;
} XTimeCoord;

typedef struct {
 	int max_keypermod;	
 	KeyCode *modifiermap;	
} XModifierKeymap;

typedef struct _XDisplay Display;

struct _XPrivate;		
struct _XrmHashBucketRec;

typedef struct

{
	XExtData *ext_data;	
	struct _XPrivate *private1;
	int fd;			
	int private2;
	int proto_major_version;
	int proto_minor_version;
	char *vendor;		
        XID private3;
	XID private4;
	XID private5;
	int private6;
	XID (*resource_alloc)(	
		struct _XDisplay*
	);
	int byte_order;		
	int bitmap_unit;	
	int bitmap_pad;		
	int bitmap_bit_order;	
	int nformats;		
	ScreenFormat *pixmap_format;	
	int private8;
	int release;		
	struct _XPrivate *private9, *private10;
	int qlen;		
	unsigned long last_request_read; 
	unsigned long request;	
	XPointer private11;
	XPointer private12;
	XPointer private13;
	XPointer private14;
	unsigned max_request_size; 
	struct _XrmHashBucketRec *db;
	int (*private15)(
		struct _XDisplay*
		);
	char *display_name;	
	int default_screen;	
	int nscreens;		
	Screen *screens;	
	unsigned long motion_buffer;	
	unsigned long private16;
	int min_keycode;	
	int max_keycode;	
	XPointer private17;
	XPointer private18;
	int private19;
	char *xdefaults;	
	
}

*_XPrivDisplay;

typedef struct {
	int type;		
	unsigned long serial;	
	int send_event;	
	Display *display;	
	Window window;	        
	Window root;	        
	Window subwindow;	
	Time time;		
	int x, y;		
	int x_root, y_root;	
	unsigned int state;	
	unsigned int keycode;	
	int same_screen;	
} XKeyEvent;
typedef XKeyEvent XKeyPressedEvent;
typedef XKeyEvent XKeyReleasedEvent;

typedef struct {
	int type;		
	unsigned long serial;	
	int send_event;	
	Display *display;	
	Window window;	        
	Window root;	        
	Window subwindow;	
	Time time;		
	int x, y;		
	int x_root, y_root;	
	unsigned int state;	
	unsigned int button;	
	int same_screen;	
} XButtonEvent;
typedef XButtonEvent XButtonPressedEvent;
typedef XButtonEvent XButtonReleasedEvent;

typedef struct {
	int type;		
	unsigned long serial;	
	int send_event;	
	Display *display;	
	Window window;	        
	Window root;	        
	Window subwindow;	
	Time time;		
	int x, y;		
	int x_root, y_root;	
	unsigned int state;	
	char is_hint;		
	int same_screen;	
} XMotionEvent;
typedef XMotionEvent XPointerMovedEvent;

typedef struct {
	int type;		
	unsigned long serial;	
	int send_event;	
	Display *display;	
	Window window;	        
	Window root;	        
	Window subwindow;	
	Time time;		
	int x, y;		
	int x_root, y_root;	
	int mode;		
	int detail;
	

	int same_screen;	
	int focus;		
	unsigned int state;	
} XCrossingEvent;
typedef XCrossingEvent XEnterWindowEvent;
typedef XCrossingEvent XLeaveWindowEvent;

typedef struct {
	int type;		
	unsigned long serial;	
	int send_event;	
	Display *display;	
	Window window;		
	int mode;		

	int detail;
	

} XFocusChangeEvent;
typedef XFocusChangeEvent XFocusInEvent;
typedef XFocusChangeEvent XFocusOutEvent;

typedef struct {
	int type;
	unsigned long serial;	
	int send_event;	
	Display *display;	
	Window window;
	char key_vector[32];
} XKeymapEvent;

typedef struct {
	int type;
	unsigned long serial;	
	int send_event;	
	Display *display;	
	Window window;
	int x, y;
	int width, height;
	int count;		
} XExposeEvent;

typedef struct {
	int type;
	unsigned long serial;	
	int send_event;	
	Display *display;	
	Drawable drawable;
	int x, y;
	int width, height;
	int count;		
	int major_code;		
	int minor_code;		
} XGraphicsExposeEvent;

typedef struct {
	int type;
	unsigned long serial;	
	int send_event;	
	Display *display;	
	Drawable drawable;
	int major_code;		
	int minor_code;		
} XNoExposeEvent;

typedef struct {
	int type;
	unsigned long serial;	
	int send_event;	
	Display *display;	
	Window window;
	int state;		
} XVisibilityEvent;

typedef struct {
	int type;
	unsigned long serial;	
	int send_event;	
	Display *display;	
	Window parent;		
	Window window;		
	int x, y;		
	int width, height;	
	int border_width;	
	int override_redirect;	
} XCreateWindowEvent;

typedef struct {
	int type;
	unsigned long serial;	
	int send_event;	
	Display *display;	
	Window event;
	Window window;
} XDestroyWindowEvent;

typedef struct {
	int type;
	unsigned long serial;	
	int send_event;	
	Display *display;	
	Window event;
	Window window;
	int from_configure;
} XUnmapEvent;

typedef struct {
	int type;
	unsigned long serial;	
	int send_event;	
	Display *display;	
	Window event;
	Window window;
	int override_redirect;	
} XMapEvent;

typedef struct {
	int type;
	unsigned long serial;	
	int send_event;	
	Display *display;	
	Window parent;
	Window window;
} XMapRequestEvent;

typedef struct {
	int type;
	unsigned long serial;	
	int send_event;	
	Display *display;	
	Window event;
	Window window;
	Window parent;
	int x, y;
	int override_redirect;
} XReparentEvent;

typedef struct {
	int type;
	unsigned long serial;	
	int send_event;	
	Display *display;	
	Window event;
	Window window;
	int x, y;
	int width, height;
	int border_width;
	Window above;
	int override_redirect;
} XConfigureEvent;

typedef struct {
	int type;
	unsigned long serial;	
	int send_event;	
	Display *display;	
	Window event;
	Window window;
	int x, y;
} XGravityEvent;

typedef struct {
	int type;
	unsigned long serial;	
	int send_event;	
	Display *display;	
	Window window;
	int width, height;
} XResizeRequestEvent;

typedef struct {
	int type;
	unsigned long serial;	
	int send_event;	
	Display *display;	
	Window parent;
	Window window;
	int x, y;
	int width, height;
	int border_width;
	Window above;
	int detail;		
	unsigned long value_mask;
} XConfigureRequestEvent;

typedef struct {
	int type;
	unsigned long serial;	
	int send_event;	
	Display *display;	
	Window event;
	Window window;
	int place;		
} XCirculateEvent;

typedef struct {
	int type;
	unsigned long serial;	
	int send_event;	
	Display *display;	
	Window parent;
	Window window;
	int place;		
} XCirculateRequestEvent;

typedef struct {
	int type;
	unsigned long serial;	
	int send_event;	
	Display *display;	
	Window window;
	Atom atom;
	Time time;
	int state;		
} XPropertyEvent;

typedef struct {
	int type;
	unsigned long serial;	
	int send_event;	
	Display *display;	
	Window window;
	Atom selection;
	Time time;
} XSelectionClearEvent;

typedef struct {
	int type;
	unsigned long serial;	
	int send_event;	
	Display *display;	
	Window owner;
	Window requestor;
	Atom selection;
	Atom target;
	Atom property;
	Time time;
} XSelectionRequestEvent;

typedef struct {
	int type;
	unsigned long serial;	
	int send_event;	
	Display *display;	
	Window requestor;
	Atom selection;
	Atom target;
	Atom property;		
	Time time;
} XSelectionEvent;

typedef struct {
	int type;
	unsigned long serial;	
	int send_event;	
	Display *display;	
	Window window;
	Colormap colormap;	

	int xnew;

	int state;		
} XColormapEvent;

typedef struct {
	int type;
	unsigned long serial;	
	int send_event;	
	Display *display;	
	Window window;
	Atom message_type;
	int format;
	union {
		char b[20];
		short s[10];
		long l[5];
		} data;
} XClientMessageEvent;

typedef struct {
	int type;
	unsigned long serial;	
	int send_event;	
	Display *display;	
	Window window;		
	int request;		

	int first_keycode;	
	int count;		
} XMappingEvent;

typedef struct {
	int type;
	Display *display;	
	XID resourceid;		
	unsigned long serial;	
	unsigned char error_code;	
	unsigned char request_code;	
	unsigned char minor_code;	
} XErrorEvent;

typedef struct {
	int type;
	unsigned long serial;	
	int send_event;	
	Display *display;
	Window window;	
} XAnyEvent;

typedef struct
    {
    int            type;         
    unsigned long  serial;       
    int           send_event;   
    Display        *display;     
    int            extension;    
    int            evtype;       
    } XGenericEvent;

typedef struct {
    int            type;         
    unsigned long  serial;       
    int           send_event;   
    Display        *display;     
    int            extension;    
    int            evtype;       
    unsigned int   cookie;
    void           *data;
} XGenericEventCookie;

typedef union _XEvent {
        int type;		
	XAnyEvent xany;
	XKeyEvent xkey;
	XButtonEvent xbutton;
	XMotionEvent xmotion;
	XCrossingEvent xcrossing;
	XFocusChangeEvent xfocus;
	XExposeEvent xexpose;
	XGraphicsExposeEvent xgraphicsexpose;
	XNoExposeEvent xnoexpose;
	XVisibilityEvent xvisibility;
	XCreateWindowEvent xcreatewindow;
	XDestroyWindowEvent xdestroywindow;
	XUnmapEvent xunmap;
	XMapEvent xmap;
	XMapRequestEvent xmaprequest;
	XReparentEvent xreparent;
	XConfigureEvent xconfigure;
	XGravityEvent xgravity;
	XResizeRequestEvent xresizerequest;
	XConfigureRequestEvent xconfigurerequest;
	XCirculateEvent xcirculate;
	XCirculateRequestEvent xcirculaterequest;
	XPropertyEvent xproperty;
	XSelectionClearEvent xselectionclear;
	XSelectionRequestEvent xselectionrequest;
	XSelectionEvent xselection;
	XColormapEvent xcolormap;
	XClientMessageEvent xclient;
	XMappingEvent xmapping;
	XErrorEvent xerror;
	XKeymapEvent xkeymap;
	XGenericEvent xgeneric;
	XGenericEventCookie xcookie;
	long pad[24];
} XEvent;

typedef struct {
    short	lbearing;	
    short	rbearing;	
    short	width;		
    short	ascent;		
    short	descent;	
    unsigned short attributes;	
} XCharStruct;

typedef struct {
    Atom name;
    unsigned long card32;
} XFontProp;

typedef struct {
    XExtData	*ext_data;	
    Font        fid;            
    unsigned	direction;	
    unsigned	min_char_or_byte2;
    unsigned	max_char_or_byte2;
    unsigned	min_byte1;	
    unsigned	max_byte1;	
    int	all_chars_exist;
    unsigned	default_char;	
    int         n_properties;   
    XFontProp	*properties;	
    XCharStruct	min_bounds;	
    XCharStruct	max_bounds;	
    XCharStruct	*per_char;	
    int		ascent;		
    int		descent;	
} XFontStruct;

typedef struct {
    char *chars;		
    int nchars;			
    int delta;			
    Font font;			
} XTextItem;

typedef struct {		
    unsigned char byte1;
    unsigned char byte2;
} XChar2b;

typedef struct {
    XChar2b *chars;		
    int nchars;			
    int delta;			
    Font font;			
} XTextItem16;

typedef union { Display *display;
		GC gc;
		Visual *visual;
		Screen *screen;
		ScreenFormat *pixmap_format;
		XFontStruct *font; } XEDataObject;

typedef struct {
    XRectangle      max_ink_extent;
    XRectangle      max_logical_extent;
} XFontSetExtents;

typedef struct _XOM *XOM;
typedef struct _XOC *XOC, *XFontSet;

typedef struct {
    char           *chars;
    int             nchars;
    int             delta;
    XFontSet        font_set;
} XmbTextItem;

typedef struct {
    wchar_t        *chars;
    int             nchars;
    int             delta;
    XFontSet        font_set;
} XwcTextItem;

typedef struct {
    int charset_count;
    char **charset_list;
} XOMCharSetList;

typedef enum {
    XOMOrientation_LTR_TTB,
    XOMOrientation_RTL_TTB,
    XOMOrientation_TTB_LTR,
    XOMOrientation_TTB_RTL,
    XOMOrientation_Context
} XOrientation;

typedef struct {
    int num_orientation;
    XOrientation *orientation;	
} XOMOrientation;

typedef struct {
    int num_font;
    XFontStruct **font_struct_list;
    char **font_name_list;
} XOMFontInfo;

typedef struct _XIM *XIM;
typedef struct _XIC *XIC;

typedef void (*XIMProc)(
    XIM,
    XPointer,
    XPointer
);

typedef int (*XICProc)(
    XIC,
    XPointer,
    XPointer
);

typedef void (*XIDProc)(
    Display*,
    XPointer,
    XPointer
);

typedef unsigned long XIMStyle;

typedef struct {
    unsigned short count_styles;
    XIMStyle *supported_styles;
} XIMStyles;

typedef void *XVaNestedList;

typedef struct {
    XPointer client_data;
    XIMProc callback;
} XIMCallback;

typedef struct {
    XPointer client_data;
    XICProc callback;
} XICCallback;

typedef unsigned long XIMFeedback;

typedef struct _XIMText {
    unsigned short length;
    XIMFeedback *feedback;
    int encoding_is_wchar;
    union {
	char *multi_byte;
	wchar_t *wide_char;
    } string;
} XIMText;

typedef	unsigned long	 XIMPreeditState;

typedef	struct	_XIMPreeditStateNotifyCallbackStruct {
    XIMPreeditState state;
} XIMPreeditStateNotifyCallbackStruct;

typedef	unsigned long	 XIMResetState;

typedef unsigned long XIMStringConversionFeedback;

typedef struct _XIMStringConversionText {
    unsigned short length;
    XIMStringConversionFeedback *feedback;
    int encoding_is_wchar;
    union {
	char *mbs;
	wchar_t *wcs;
    } string;
} XIMStringConversionText;

typedef	unsigned short	XIMStringConversionPosition;

typedef	unsigned short	XIMStringConversionType;

typedef	unsigned short	XIMStringConversionOperation;

typedef enum {
    XIMForwardChar, XIMBackwardChar,
    XIMForwardWord, XIMBackwardWord,
    XIMCaretUp, XIMCaretDown,
    XIMNextLine, XIMPreviousLine,
    XIMLineStart, XIMLineEnd,
    XIMAbsolutePosition,
    XIMDontChange
} XIMCaretDirection;

typedef struct _XIMStringConversionCallbackStruct {
    XIMStringConversionPosition position;
    XIMCaretDirection direction;
    XIMStringConversionOperation operation;
    unsigned short factor;
    XIMStringConversionText *text;
} XIMStringConversionCallbackStruct;

typedef struct _XIMPreeditDrawCallbackStruct {
    int caret;		
    int chg_first;	
    int chg_length;	
    XIMText *text;
} XIMPreeditDrawCallbackStruct;

typedef enum {
    XIMIsInvisible,	
    XIMIsPrimary,	
    XIMIsSecondary	
} XIMCaretStyle;

typedef struct _XIMPreeditCaretCallbackStruct {
    int position;		 
    XIMCaretDirection direction; 
    XIMCaretStyle style;	 
} XIMPreeditCaretCallbackStruct;

typedef enum {
    XIMTextType,
    XIMBitmapType
} XIMStatusDataType;

typedef struct _XIMStatusDrawCallbackStruct {
    XIMStatusDataType type;
    union {
	XIMText *text;
	Pixmap  bitmap;
    } data;
} XIMStatusDrawCallbackStruct;

typedef struct _XIMHotKeyTrigger {
    KeySym	 keysym;
    int		 modifier;
    int		 modifier_mask;
} XIMHotKeyTrigger;

typedef struct _XIMHotKeyTriggers {
    int			 num_hot_key;
    XIMHotKeyTrigger	*key;
} XIMHotKeyTriggers;

typedef	unsigned long	 XIMHotKeyState;

typedef struct {
    unsigned short count_values;
    char **supported_values;
} XIMValuesList;

extern int _Xdebug;

extern XFontStruct *XLoadQueryFont(
    Display*		,
    __const char*	
);

extern XFontStruct *XQueryFont(
    Display*		,
    XID			
);

extern XTimeCoord *XGetMotionEvents(
    Display*		,
    Window		,
    Time		,
    Time		,
    int*		
);

extern XModifierKeymap *XDeleteModifiermapEntry(
    XModifierKeymap*	,

    unsigned int	,

    int			
);

extern XModifierKeymap	*XGetModifierMapping(
    Display*		
);

extern XModifierKeymap	*XInsertModifiermapEntry(
    XModifierKeymap*	,

    unsigned int	,

    int			
);

extern XModifierKeymap *XNewModifiermap(
    int			
);

extern XImage *XCreateImage(
    Display*		,
    Visual*		,
    unsigned int	,
    int			,
    int			,
    char*		,
    unsigned int	,
    unsigned int	,
    int			,
    int			
);
extern int XInitImage(
    XImage*		
);
extern XImage *XGetImage(
    Display*		,
    Drawable		,
    int			,
    int			,
    unsigned int	,
    unsigned int	,
    unsigned long	,
    int			
);
extern XImage *XGetSubImage(
    Display*		,
    Drawable		,
    int			,
    int			,
    unsigned int	,
    unsigned int	,
    unsigned long	,
    int			,
    XImage*		,
    int			,
    int			
);

extern Display *XOpenDisplay(
    __const char*	
);

extern void XrmInitialize(
    void
);

extern char *XFetchBytes(
    Display*		,
    int*		
);
extern char *XFetchBuffer(
    Display*		,
    int*		,
    int			
);
extern char *XGetAtomName(
    Display*		,
    Atom		
);
extern int XGetAtomNames(
    Display*		,
    Atom*		,
    int			,
    char**		
);
extern char *XGetDefault(
    Display*		,
    __const char*	,
    __const char*	
);
extern char *XDisplayName(
    __const char*	
);
extern char *XKeysymToString(
    KeySym		
);

extern int (*XSynchronize(
    Display*		,
    int		
))(
    Display*		
);
extern int (*XSetAfterFunction(
    Display*		,
    int (*) (
	     Display*	
            )		
))(
    Display*		
);
extern Atom XInternAtom(
    Display*		,
    __const char*	,
    int		
);
extern int XInternAtoms(
    Display*		,
    char**		,
    int			,
    int		,
    Atom*		
);
extern Colormap XCopyColormapAndFree(
    Display*		,
    Colormap		
);
extern Colormap XCreateColormap(
    Display*		,
    Window		,
    Visual*		,
    int			
);
extern Cursor XCreatePixmapCursor(
    Display*		,
    Pixmap		,
    Pixmap		,
    XColor*		,
    XColor*		,
    unsigned int	,
    unsigned int	
);
extern Cursor XCreateGlyphCursor(
    Display*		,
    Font		,
    Font		,
    unsigned int	,
    unsigned int	,
    XColor __const *	,
    XColor __const *	
);
extern Cursor XCreateFontCursor(
    Display*		,
    unsigned int	
);
extern Font XLoadFont(
    Display*		,
    __const char*	
);
extern GC XCreateGC(
    Display*		,
    Drawable		,
    unsigned long	,
    XGCValues*		
);
extern GContext XGContextFromGC(
    GC			
);
extern void XFlushGC(
    Display*		,
    GC			
);
extern Pixmap XCreatePixmap(
    Display*		,
    Drawable		,
    unsigned int	,
    unsigned int	,
    unsigned int	
);
extern Pixmap XCreateBitmapFromData(
    Display*		,
    Drawable		,
    __const char*	,
    unsigned int	,
    unsigned int	
);
extern Pixmap XCreatePixmapFromBitmapData(
    Display*		,
    Drawable		,
    char*		,
    unsigned int	,
    unsigned int	,
    unsigned long	,
    unsigned long	,
    unsigned int	
);
extern Window XCreateSimpleWindow(
    Display*		,
    Window		,
    int			,
    int			,
    unsigned int	,
    unsigned int	,
    unsigned int	,
    unsigned long	,
    unsigned long	
);
extern Window XGetSelectionOwner(
    Display*		,
    Atom		
);
extern Window XCreateWindow(
    Display*		,
    Window		,
    int			,
    int			,
    unsigned int	,
    unsigned int	,
    unsigned int	,
    int			,
    unsigned int	,
    Visual*		,
    unsigned long	,
    XSetWindowAttributes*	
);
extern Colormap *XListInstalledColormaps(
    Display*		,
    Window		,
    int*		
);
extern char **XListFonts(
    Display*		,
    __const char*	,
    int			,
    int*		
);
extern char **XListFontsWithInfo(
    Display*		,
    __const char*	,
    int			,
    int*		,
    XFontStruct**	
);
extern char **XGetFontPath(
    Display*		,
    int*		
);
extern char **XListExtensions(
    Display*		,
    int*		
);
extern Atom *XListProperties(
    Display*		,
    Window		,
    int*		
);
extern XHostAddress *XListHosts(
    Display*		,
    int*		,
    int*		
);
extern KeySym XKeycodeToKeysym(
    Display*		,

    unsigned int	,

    int			
);
extern KeySym XLookupKeysym(
    XKeyEvent*		,
    int			
);
extern KeySym *XGetKeyboardMapping(
    Display*		,

    unsigned int	,

    int			,
    int*		
);
extern KeySym XStringToKeysym(
    __const char*	
);
extern long XMaxRequestSize(
    Display*		
);
extern long XExtendedMaxRequestSize(
    Display*		
);
extern char *XResourceManagerString(
    Display*		
);
extern char *XScreenResourceString(
	Screen*		
);
extern unsigned long XDisplayMotionBufferSize(
    Display*		
);
extern VisualID XVisualIDFromVisual(
    Visual*		
);

extern int XInitThreads(
    void
);

extern void XLockDisplay(
    Display*		
);

extern void XUnlockDisplay(
    Display*		
);

extern XExtCodes *XInitExtension(
    Display*		,
    __const char*	
);

extern XExtCodes *XAddExtension(
    Display*		
);
extern XExtData *XFindOnExtensionList(
    XExtData**		,
    int			
);
extern XExtData **XEHeadOfExtensionList(
    XEDataObject	
);

extern Window XRootWindow(
    Display*		,
    int			
);
extern Window XDefaultRootWindow(
    Display*		
);
extern Window XRootWindowOfScreen(
    Screen*		
);
extern Visual *XDefaultVisual(
    Display*		,
    int			
);
extern Visual *XDefaultVisualOfScreen(
    Screen*		
);
extern GC XDefaultGC(
    Display*		,
    int			
);
extern GC XDefaultGCOfScreen(
    Screen*		
);
extern unsigned long XBlackPixel(
    Display*		,
    int			
);
extern unsigned long XWhitePixel(
    Display*		,
    int			
);
extern unsigned long XAllPlanes(
    void
);
extern unsigned long XBlackPixelOfScreen(
    Screen*		
);
extern unsigned long XWhitePixelOfScreen(
    Screen*		
);
extern unsigned long XNextRequest(
    Display*		
);
extern unsigned long XLastKnownRequestProcessed(
    Display*		
);
extern char *XServerVendor(
    Display*		
);
extern char *XDisplayString(
    Display*		
);
extern Colormap XDefaultColormap(
    Display*		,
    int			
);
extern Colormap XDefaultColormapOfScreen(
    Screen*		
);
extern Display *XDisplayOfScreen(
    Screen*		
);
extern Screen *XScreenOfDisplay(
    Display*		,
    int			
);
extern Screen *XDefaultScreenOfDisplay(
    Display*		
);
extern long XEventMaskOfScreen(
    Screen*		
);

extern int XScreenNumberOfScreen(
    Screen*		
);

typedef int (*XErrorHandler) (	    
    Display*		,
    XErrorEvent*	
);

extern XErrorHandler XSetErrorHandler (
    XErrorHandler	
);

typedef int (*XIOErrorHandler) (    
    Display*		
);

extern XIOErrorHandler XSetIOErrorHandler (
    XIOErrorHandler	
);

extern XPixmapFormatValues *XListPixmapFormats(
    Display*		,
    int*		
);
extern int *XListDepths(
    Display*		,
    int			,
    int*		
);

extern int XReconfigureWMWindow(
    Display*		,
    Window		,
    int			,
    unsigned int	,
    XWindowChanges*	
);

extern int XGetWMProtocols(
    Display*		,
    Window		,
    Atom**		,
    int*		
);
extern int XSetWMProtocols(
    Display*		,
    Window		,
    Atom*		,
    int			
);
extern int XIconifyWindow(
    Display*		,
    Window		,
    int			
);
extern int XWithdrawWindow(
    Display*		,
    Window		,
    int			
);
extern int XGetCommand(
    Display*		,
    Window		,
    char***		,
    int*		
);
extern int XGetWMColormapWindows(
    Display*		,
    Window		,
    Window**		,
    int*		
);
extern int XSetWMColormapWindows(
    Display*		,
    Window		,
    Window*		,
    int			
);
extern void XFreeStringList(
    char**		
);
extern int XSetTransientForHint(
    Display*		,
    Window		,
    Window		
);

extern int XActivateScreenSaver(
    Display*		
);

extern int XAddHost(
    Display*		,
    XHostAddress*	
);

extern int XAddHosts(
    Display*		,
    XHostAddress*	,
    int			
);

extern int XAddToExtensionList(
    struct _XExtData**	,
    XExtData*		
);

extern int XAddToSaveSet(
    Display*		,
    Window		
);

extern int XAllocColor(
    Display*		,
    Colormap		,
    XColor*		
);

extern int XAllocColorCells(
    Display*		,
    Colormap		,
    int	        ,
    unsigned long*	,
    unsigned int	,
    unsigned long*	,
    unsigned int 	
);

extern int XAllocColorPlanes(
    Display*		,
    Colormap		,
    int		,
    unsigned long*	,
    int			,
    int			,
    int			,
    int			,
    unsigned long*	,
    unsigned long*	,
    unsigned long*	
);

extern int XAllocNamedColor(
    Display*		,
    Colormap		,
    __const char*	,
    XColor*		,
    XColor*		
);

extern int XAllowEvents(
    Display*		,
    int			,
    Time		
);

extern int XAutoRepeatOff(
    Display*		
);

extern int XAutoRepeatOn(
    Display*		
);

extern int XBell(
    Display*		,
    int			
);

extern int XBitmapBitOrder(
    Display*		
);

extern int XBitmapPad(
    Display*		
);

extern int XBitmapUnit(
    Display*		
);

extern int XCellsOfScreen(
    Screen*		
);

extern int XChangeActivePointerGrab(
    Display*		,
    unsigned int	,
    Cursor		,
    Time		
);

extern int XChangeGC(
    Display*		,
    GC			,
    unsigned long	,
    XGCValues*		
);

extern int XChangeKeyboardControl(
    Display*		,
    unsigned long	,
    XKeyboardControl*	
);

extern int XChangeKeyboardMapping(
    Display*		,
    int			,
    int			,
    KeySym*		,
    int			
);

extern int XChangePointerControl(
    Display*		,
    int		,
    int		,
    int			,
    int			,
    int			
);

extern int XChangeProperty(
    Display*		,
    Window		,
    Atom		,
    Atom		,
    int			,
    int			,
    __const unsigned char*	,
    int			
);

extern int XChangeSaveSet(
    Display*		,
    Window		,
    int			
);

extern int XChangeWindowAttributes(
    Display*		,
    Window		,
    unsigned long	,
    XSetWindowAttributes* 
);

extern int XCheckIfEvent(
    Display*		,
    XEvent*		,
    int (*) (
	       Display*			,
               XEvent*			,
               XPointer			
             )		,
    XPointer		
);

extern int XCheckMaskEvent(
    Display*		,
    long		,
    XEvent*		
);

extern int XCheckTypedEvent(
    Display*		,
    int			,
    XEvent*		
);

extern int XCheckTypedWindowEvent(
    Display*		,
    Window		,
    int			,
    XEvent*		
);

extern int XCheckWindowEvent(
    Display*		,
    Window		,
    long		,
    XEvent*		
);

extern int XCirculateSubwindows(
    Display*		,
    Window		,
    int			
);

extern int XCirculateSubwindowsDown(
    Display*		,
    Window		
);

extern int XCirculateSubwindowsUp(
    Display*		,
    Window		
);

extern int XClearArea(
    Display*		,
    Window		,
    int			,
    int			,
    unsigned int	,
    unsigned int	,
    int		
);

extern int XClearWindow(
    Display*		,
    Window		
);

extern int XCloseDisplay(
    Display*		
);

extern int XConfigureWindow(
    Display*		,
    Window		,
    unsigned int	,
    XWindowChanges*	
);

extern int XConnectionNumber(
    Display*		
);

extern int XConvertSelection(
    Display*		,
    Atom		,
    Atom 		,
    Atom		,
    Window		,
    Time		
);

extern int XCopyArea(
    Display*		,
    Drawable		,
    Drawable		,
    GC			,
    int			,
    int			,
    unsigned int	,
    unsigned int	,
    int			,
    int			
);

extern int XCopyGC(
    Display*		,
    GC			,
    unsigned long	,
    GC			
);

extern int XCopyPlane(
    Display*		,
    Drawable		,
    Drawable		,
    GC			,
    int			,
    int			,
    unsigned int	,
    unsigned int	,
    int			,
    int			,
    unsigned long	
);

extern int XDefaultDepth(
    Display*		,
    int			
);

extern int XDefaultDepthOfScreen(
    Screen*		
);

extern int XDefaultScreen(
    Display*		
);

extern int XDefineCursor(
    Display*		,
    Window		,
    Cursor		
);

extern int XDeleteProperty(
    Display*		,
    Window		,
    Atom		
);

extern int XDestroyWindow(
    Display*		,
    Window		
);

extern int XDestroySubwindows(
    Display*		,
    Window		
);

extern int XDoesBackingStore(
    Screen*		
);

extern int XDoesSaveUnders(
    Screen*		
);

extern int XDisableAccessControl(
    Display*		
);

extern int XDisplayCells(
    Display*		,
    int			
);

extern int XDisplayHeight(
    Display*		,
    int			
);

extern int XDisplayHeightMM(
    Display*		,
    int			
);

extern int XDisplayKeycodes(
    Display*		,
    int*		,
    int*		
);

extern int XDisplayPlanes(
    Display*		,
    int			
);

extern int XDisplayWidth(
    Display*		,
    int			
);

extern int XDisplayWidthMM(
    Display*		,
    int			
);

extern int XDrawArc(
    Display*		,
    Drawable		,
    GC			,
    int			,
    int			,
    unsigned int	,
    unsigned int	,
    int			,
    int			
);

extern int XDrawArcs(
    Display*		,
    Drawable		,
    GC			,
    XArc*		,
    int			
);

extern int XDrawLine(
    Display*		,
    Drawable		,
    GC			,
    int			,
    int			,
    int			,
    int			
);

extern int XDrawLines(
    Display*		,
    Drawable		,
    GC			,
    XPoint*		,
    int			,
    int			
);

extern int XDrawPoint(
    Display*		,
    Drawable		,
    GC			,
    int			,
    int			
);

extern int XDrawPoints(
    Display*		,
    Drawable		,
    GC			,
    XPoint*		,
    int			,
    int			
);

extern int XDrawRectangle(
    Display*		,
    Drawable		,
    GC			,
    int			,
    int			,
    unsigned int	,
    unsigned int	
);

extern int XDrawRectangles(
    Display*		,
    Drawable		,
    GC			,
    XRectangle*		,
    int			
);

extern int XDrawSegments(
    Display*		,
    Drawable		,
    GC			,
    XSegment*		,
    int			
);

extern int XDrawString(
    Display*		,
    Drawable		,
    GC			,
    int			,
    int			,
    __const char*	,
    int			
);

extern int XDrawString16(
    Display*		,
    Drawable		,
    GC			,
    int			,
    int			,
    __const XChar2b*	,
    int			
);

extern int XDrawText(
    Display*		,
    Drawable		,
    GC			,
    int			,
    int			,
    XTextItem*		,
    int			
);

extern int XDrawText16(
    Display*		,
    Drawable		,
    GC			,
    int			,
    int			,
    XTextItem16*	,
    int			
);

extern int XEnableAccessControl(
    Display*		
);

extern int XEventsQueued(
    Display*		,
    int			
);

extern int XFetchName(
    Display*		,
    Window		,
    char**		
);

extern int XFillArc(
    Display*		,
    Drawable		,
    GC			,
    int			,
    int			,
    unsigned int	,
    unsigned int	,
    int			,
    int			
);

extern int XFillArcs(
    Display*		,
    Drawable		,
    GC			,
    XArc*		,
    int			
);

extern int XFillPolygon(
    Display*		,
    Drawable		,
    GC			,
    XPoint*		,
    int			,
    int			,
    int			
);

extern int XFillRectangle(
    Display*		,
    Drawable		,
    GC			,
    int			,
    int			,
    unsigned int	,
    unsigned int	
);

extern int XFillRectangles(
    Display*		,
    Drawable		,
    GC			,
    XRectangle*		,
    int			
);

extern int XFlush(
    Display*		
);

extern int XForceScreenSaver(
    Display*		,
    int			
);

extern int XFree(
    void*		
);

extern int XFreeColormap(
    Display*		,
    Colormap		
);

extern int XFreeColors(
    Display*		,
    Colormap		,
    unsigned long*	,
    int			,
    unsigned long	
);

extern int XFreeCursor(
    Display*		,
    Cursor		
);

extern int XFreeExtensionList(
    char**		
);

extern int XFreeFont(
    Display*		,
    XFontStruct*	
);

extern int XFreeFontInfo(
    char**		,
    XFontStruct*	,
    int			
);

extern int XFreeFontNames(
    char**		
);

extern int XFreeFontPath(
    char**		
);

extern int XFreeGC(
    Display*		,
    GC			
);

extern int XFreeModifiermap(
    XModifierKeymap*	
);

extern int XFreePixmap(
    Display*		,
    Pixmap		
);

extern int XGeometry(
    Display*		,
    int			,
    __const char*	,
    __const char*	,
    unsigned int	,
    unsigned int	,
    unsigned int	,
    int			,
    int			,
    int*		,
    int*		,
    int*		,
    int*		
);

extern int XGetErrorDatabaseText(
    Display*		,
    __const char*	,
    __const char*	,
    __const char*	,
    char*		,
    int			
);

extern int XGetErrorText(
    Display*		,
    int			,
    char*		,
    int			
);

extern int XGetFontProperty(
    XFontStruct*	,
    Atom		,
    unsigned long*	
);

extern int XGetGCValues(
    Display*		,
    GC			,
    unsigned long	,
    XGCValues*		
);

extern int XGetGeometry(
    Display*		,
    Drawable		,
    Window*		,
    int*		,
    int*		,
    unsigned int*	,
    unsigned int*	,
    unsigned int*	,
    unsigned int*	
);

extern int XGetIconName(
    Display*		,
    Window		,
    char**		
);

extern int XGetInputFocus(
    Display*		,
    Window*		,
    int*		
);

extern int XGetKeyboardControl(
    Display*		,
    XKeyboardState*	
);

extern int XGetPointerControl(
    Display*		,
    int*		,
    int*		,
    int*		
);

extern int XGetPointerMapping(
    Display*		,
    unsigned char*	,
    int			
);

extern int XGetScreenSaver(
    Display*		,
    int*		,
    int*		,
    int*		,
    int*		
);

extern int XGetTransientForHint(
    Display*		,
    Window		,
    Window*		
);

extern int XGetWindowProperty(
    Display*		,
    Window		,
    Atom		,
    long		,
    long		,
    int		,
    Atom		,
    Atom*		,
    int*		,
    unsigned long*	,
    unsigned long*	,
    unsigned char**	
);

extern int XGetWindowAttributes(
    Display*		,
    Window		,
    XWindowAttributes*	
);

extern int XGrabButton(
    Display*		,
    unsigned int	,
    unsigned int	,
    Window		,
    int		,
    unsigned int	,
    int			,
    int			,
    Window		,
    Cursor		
);

extern int XGrabKey(
    Display*		,
    int			,
    unsigned int	,
    Window		,
    int		,
    int			,
    int			
);

extern int XGrabKeyboard(
    Display*		,
    Window		,
    int		,
    int			,
    int			,
    Time		
);

extern int XGrabPointer(
    Display*		,
    Window		,
    int		,
    unsigned int	,
    int			,
    int			,
    Window		,
    Cursor		,
    Time		
);

extern int XGrabServer(
    Display*		
);

extern int XHeightMMOfScreen(
    Screen*		
);

extern int XHeightOfScreen(
    Screen*		
);

extern int XIfEvent(
    Display*		,
    XEvent*		,
    int (*) (
	       Display*			,
               XEvent*			,
               XPointer			
             )		,
    XPointer		
);

extern int XImageByteOrder(
    Display*		
);

extern int XInstallColormap(
    Display*		,
    Colormap		
);

extern KeyCode XKeysymToKeycode(
    Display*		,
    KeySym		
);

extern int XKillClient(
    Display*		,
    XID			
);

extern int XLookupColor(
    Display*		,
    Colormap		,
    __const char*	,
    XColor*		,
    XColor*		
);

extern int XLowerWindow(
    Display*		,
    Window		
);

extern int XMapRaised(
    Display*		,
    Window		
);

extern int XMapSubwindows(
    Display*		,
    Window		
);

extern int XMapWindow(
    Display*		,
    Window		
);

extern int XMaskEvent(
    Display*		,
    long		,
    XEvent*		
);

extern int XMaxCmapsOfScreen(
    Screen*		
);

extern int XMinCmapsOfScreen(
    Screen*		
);

extern int XMoveResizeWindow(
    Display*		,
    Window		,
    int			,
    int			,
    unsigned int	,
    unsigned int	
);

extern int XMoveWindow(
    Display*		,
    Window		,
    int			,
    int			
);

extern int XNextEvent(
    Display*		,
    XEvent*		
);

extern int XNoOp(
    Display*		
);

extern int XParseColor(
    Display*		,
    Colormap		,
    __const char*	,
    XColor*		
);

extern int XParseGeometry(
    __const char*	,
    int*		,
    int*		,
    unsigned int*	,
    unsigned int*	
);

extern int XPeekEvent(
    Display*		,
    XEvent*		
);

extern int XPeekIfEvent(
    Display*		,
    XEvent*		,
    int (*) (
	       Display*		,
               XEvent*		,
               XPointer		
             )		,
    XPointer		
);

extern int XPending(
    Display*		
);

extern int XPlanesOfScreen(
    Screen*		
);

extern int XProtocolRevision(
    Display*		
);

extern int XProtocolVersion(
    Display*		
);

extern int XPutBackEvent(
    Display*		,
    XEvent*		
);

extern int XPutImage(
    Display*		,
    Drawable		,
    GC			,
    XImage*		,
    int			,
    int			,
    int			,
    int			,
    unsigned int	,
    unsigned int	
);

extern int XQLength(
    Display*		
);

extern int XQueryBestCursor(
    Display*		,
    Drawable		,
    unsigned int        ,
    unsigned int	,
    unsigned int*	,
    unsigned int*	
);

extern int XQueryBestSize(
    Display*		,
    int			,
    Drawable		,
    unsigned int	,
    unsigned int	,
    unsigned int*	,
    unsigned int*	
);

extern int XQueryBestStipple(
    Display*		,
    Drawable		,
    unsigned int	,
    unsigned int	,
    unsigned int*	,
    unsigned int*	
);

extern int XQueryBestTile(
    Display*		,
    Drawable		,
    unsigned int	,
    unsigned int	,
    unsigned int*	,
    unsigned int*	
);

extern int XQueryColor(
    Display*		,
    Colormap		,
    XColor*		
);

extern int XQueryColors(
    Display*		,
    Colormap		,
    XColor*		,
    int			
);

extern int XQueryExtension(
    Display*		,
    __const char*	,
    int*		,
    int*		,
    int*		
);

extern int XQueryKeymap(
    Display*		,
    char [32]		
);

extern int XQueryPointer(
    Display*		,
    Window		,
    Window*		,
    Window*		,
    int*		,
    int*		,
    int*		,
    int*		,
    unsigned int*       
);

extern int XQueryTextExtents(
    Display*		,
    XID			,
    __const char*	,
    int			,
    int*		,
    int*		,
    int*		,
    XCharStruct*	
);

extern int XQueryTextExtents16(
    Display*		,
    XID			,
    __const XChar2b*	,
    int			,
    int*		,
    int*		,
    int*		,
    XCharStruct*	
);

extern int XQueryTree(
    Display*		,
    Window		,
    Window*		,
    Window*		,
    Window**		,
    unsigned int*	
);

extern int XRaiseWindow(
    Display*		,
    Window		
);

extern int XReadBitmapFile(
    Display*		,
    Drawable 		,
    __const char*	,
    unsigned int*	,
    unsigned int*	,
    Pixmap*		,
    int*		,
    int*		
);

extern int XReadBitmapFileData(
    __const char*	,
    unsigned int*	,
    unsigned int*	,
    unsigned char**	,
    int*		,
    int*		
);

extern int XRebindKeysym(
    Display*		,
    KeySym		,
    KeySym*		,
    int			,
    __const unsigned char*	,
    int			
);

extern int XRecolorCursor(
    Display*		,
    Cursor		,
    XColor*		,
    XColor*		
);

extern int XRefreshKeyboardMapping(
    XMappingEvent*	
);

extern int XRemoveFromSaveSet(
    Display*		,
    Window		
);

extern int XRemoveHost(
    Display*		,
    XHostAddress*	
);

extern int XRemoveHosts(
    Display*		,
    XHostAddress*	,
    int			
);

extern int XReparentWindow(
    Display*		,
    Window		,
    Window		,
    int			,
    int			
);

extern int XResetScreenSaver(
    Display*		
);

extern int XResizeWindow(
    Display*		,
    Window		,
    unsigned int	,
    unsigned int	
);

extern int XRestackWindows(
    Display*		,
    Window*		,
    int			
);

extern int XRotateBuffers(
    Display*		,
    int			
);

extern int XRotateWindowProperties(
    Display*		,
    Window		,
    Atom*		,
    int			,
    int			
);

extern int XScreenCount(
    Display*		
);

extern int XSelectInput(
    Display*		,
    Window		,
    long		
);

extern int XSendEvent(
    Display*		,
    Window		,
    int		,
    long		,
    XEvent*		
);

extern int XSetAccessControl(
    Display*		,
    int			
);

extern int XSetArcMode(
    Display*		,
    GC			,
    int			
);

extern int XSetBackground(
    Display*		,
    GC			,
    unsigned long	
);

extern int XSetClipMask(
    Display*		,
    GC			,
    Pixmap		
);

extern int XSetClipOrigin(
    Display*		,
    GC			,
    int			,
    int			
);

extern int XSetClipRectangles(
    Display*		,
    GC			,
    int			,
    int			,
    XRectangle*		,
    int			,
    int			
);

extern int XSetCloseDownMode(
    Display*		,
    int			
);

extern int XSetCommand(
    Display*		,
    Window		,
    char**		,
    int			
);

extern int XSetDashes(
    Display*		,
    GC			,
    int			,
    __const char*	,
    int			
);

extern int XSetFillRule(
    Display*		,
    GC			,
    int			
);

extern int XSetFillStyle(
    Display*		,
    GC			,
    int			
);

extern int XSetFont(
    Display*		,
    GC			,
    Font		
);

extern int XSetFontPath(
    Display*		,
    char**		,
    int			
);

extern int XSetForeground(
    Display*		,
    GC			,
    unsigned long	
);

extern int XSetFunction(
    Display*		,
    GC			,
    int			
);

extern int XSetGraphicsExposures(
    Display*		,
    GC			,
    int		
);

extern int XSetIconName(
    Display*		,
    Window		,
    __const char*	
);

extern int XSetInputFocus(
    Display*		,
    Window		,
    int			,
    Time		
);

extern int XSetLineAttributes(
    Display*		,
    GC			,
    unsigned int	,
    int			,
    int			,
    int			
);

extern int XSetModifierMapping(
    Display*		,
    XModifierKeymap*	
);

extern int XSetPlaneMask(
    Display*		,
    GC			,
    unsigned long	
);

extern int XSetPointerMapping(
    Display*		,
    __const unsigned char*	,
    int			
);

extern int XSetScreenSaver(
    Display*		,
    int			,
    int			,
    int			,
    int			
);

extern int XSetSelectionOwner(
    Display*		,
    Atom	        ,
    Window		,
    Time		
);

extern int XSetState(
    Display*		,
    GC			,
    unsigned long 	,
    unsigned long	,
    int			,
    unsigned long	
);

extern int XSetStipple(
    Display*		,
    GC			,
    Pixmap		
);

extern int XSetSubwindowMode(
    Display*		,
    GC			,
    int			
);

extern int XSetTSOrigin(
    Display*		,
    GC			,
    int			,
    int			
);

extern int XSetTile(
    Display*		,
    GC			,
    Pixmap		
);

extern int XSetWindowBackground(
    Display*		,
    Window		,
    unsigned long	
);

extern int XSetWindowBackgroundPixmap(
    Display*		,
    Window		,
    Pixmap		
);

extern int XSetWindowBorder(
    Display*		,
    Window		,
    unsigned long	
);

extern int XSetWindowBorderPixmap(
    Display*		,
    Window		,
    Pixmap		
);

extern int XSetWindowBorderWidth(
    Display*		,
    Window		,
    unsigned int	
);

extern int XSetWindowColormap(
    Display*		,
    Window		,
    Colormap		
);

extern int XStoreBuffer(
    Display*		,
    __const char*	,
    int			,
    int			
);

extern int XStoreBytes(
    Display*		,
    __const char*	,
    int			
);

extern int XStoreColor(
    Display*		,
    Colormap		,
    XColor*		
);

extern int XStoreColors(
    Display*		,
    Colormap		,
    XColor*		,
    int			
);

extern int XStoreName(
    Display*		,
    Window		,
    __const char*	
);

extern int XStoreNamedColor(
    Display*		,
    Colormap		,
    __const char*	,
    unsigned long	,
    int			
);

extern int XSync(
    Display*		,
    int		
);

extern int XTextExtents(
    XFontStruct*	,
    __const char*	,
    int			,
    int*		,
    int*		,
    int*		,
    XCharStruct*	
);

extern int XTextExtents16(
    XFontStruct*	,
    __const XChar2b*	,
    int			,
    int*		,
    int*		,
    int*		,
    XCharStruct*	
);

extern int XTextWidth(
    XFontStruct*	,
    __const char*	,
    int			
);

extern int XTextWidth16(
    XFontStruct*	,
    __const XChar2b*	,
    int			
);

extern int XTranslateCoordinates(
    Display*		,
    Window		,
    Window		,
    int			,
    int			,
    int*		,
    int*		,
    Window*		
);

extern int XUndefineCursor(
    Display*		,
    Window		
);

extern int XUngrabButton(
    Display*		,
    unsigned int	,
    unsigned int	,
    Window		
);

extern int XUngrabKey(
    Display*		,
    int			,
    unsigned int	,
    Window		
);

extern int XUngrabKeyboard(
    Display*		,
    Time		
);

extern int XUngrabPointer(
    Display*		,
    Time		
);

extern int XUngrabServer(
    Display*		
);

extern int XUninstallColormap(
    Display*		,
    Colormap		
);

extern int XUnloadFont(
    Display*		,
    Font		
);

extern int XUnmapSubwindows(
    Display*		,
    Window		
);

extern int XUnmapWindow(
    Display*		,
    Window		
);

extern int XVendorRelease(
    Display*		
);

extern int XWarpPointer(
    Display*		,
    Window		,
    Window		,
    int			,
    int			,
    unsigned int	,
    unsigned int	,
    int			,
    int			
);

extern int XWidthMMOfScreen(
    Screen*		
);

extern int XWidthOfScreen(
    Screen*		
);

extern int XWindowEvent(
    Display*		,
    Window		,
    long		,
    XEvent*		
);

extern int XWriteBitmapFile(
    Display*		,
    __const char*	,
    Pixmap		,
    unsigned int	,
    unsigned int	,
    int			,
    int			
);

extern int XSupportsLocale (void);

extern char *XSetLocaleModifiers(
    __const char*		
);

extern XOM XOpenOM(
    Display*			,
    struct _XrmHashBucketRec*	,
    __const char*		,
    __const char*		
);

extern int XCloseOM(
    XOM			
);

extern char *XSetOMValues(
    XOM			,
    ...
) __attribute__ ((__sentinel__(0)));

extern char *XGetOMValues(
    XOM			,
    ...
) __attribute__ ((__sentinel__(0)));

extern Display *XDisplayOfOM(
    XOM			
);

extern char *XLocaleOfOM(
    XOM			
);

extern XOC XCreateOC(
    XOM			,
    ...
) __attribute__ ((__sentinel__(0)));

extern void XDestroyOC(
    XOC			
);

extern XOM XOMOfOC(
    XOC			
);

extern char *XSetOCValues(
    XOC			,
    ...
) __attribute__ ((__sentinel__(0)));

extern char *XGetOCValues(
    XOC			,
    ...
) __attribute__ ((__sentinel__(0)));

extern XFontSet XCreateFontSet(
    Display*		,
    __const char*	,
    char***		,
    int*		,
    char**		
);

extern void XFreeFontSet(
    Display*		,
    XFontSet		
);

extern int XFontsOfFontSet(
    XFontSet		,
    XFontStruct***	,
    char***		
);

extern char *XBaseFontNameListOfFontSet(
    XFontSet		
);

extern char *XLocaleOfFontSet(
    XFontSet		
);

extern int XContextDependentDrawing(
    XFontSet		
);

extern int XDirectionalDependentDrawing(
    XFontSet		
);

extern int XContextualDrawing(
    XFontSet		
);

extern XFontSetExtents *XExtentsOfFontSet(
    XFontSet		
);

extern int XmbTextEscapement(
    XFontSet		,
    __const char*	,
    int			
);

extern int XwcTextEscapement(
    XFontSet		,
    __const wchar_t*	,
    int			
);

extern int Xutf8TextEscapement(
    XFontSet		,
    __const char*	,
    int			
);

extern int XmbTextExtents(
    XFontSet		,
    __const char*	,
    int			,
    XRectangle*		,
    XRectangle*		
);

extern int XwcTextExtents(
    XFontSet		,
    __const wchar_t*	,
    int			,
    XRectangle*		,
    XRectangle*		
);

extern int Xutf8TextExtents(
    XFontSet		,
    __const char*	,
    int			,
    XRectangle*		,
    XRectangle*		
);

extern int XmbTextPerCharExtents(
    XFontSet		,
    __const char*	,
    int			,
    XRectangle*		,
    XRectangle*		,
    int			,
    int*		,
    XRectangle*		,
    XRectangle*		
);

extern int XwcTextPerCharExtents(
    XFontSet		,
    __const wchar_t*	,
    int			,
    XRectangle*		,
    XRectangle*		,
    int			,
    int*		,
    XRectangle*		,
    XRectangle*		
);

extern int Xutf8TextPerCharExtents(
    XFontSet		,
    __const char*	,
    int			,
    XRectangle*		,
    XRectangle*		,
    int			,
    int*		,
    XRectangle*		,
    XRectangle*		
);

extern void XmbDrawText(
    Display*		,
    Drawable		,
    GC			,
    int			,
    int			,
    XmbTextItem*	,
    int			
);

extern void XwcDrawText(
    Display*		,
    Drawable		,
    GC			,
    int			,
    int			,
    XwcTextItem*	,
    int			
);

extern void Xutf8DrawText(
    Display*		,
    Drawable		,
    GC			,
    int			,
    int			,
    XmbTextItem*	,
    int			
);

extern void XmbDrawString(
    Display*		,
    Drawable		,
    XFontSet		,
    GC			,
    int			,
    int			,
    __const char*	,
    int			
);

extern void XwcDrawString(
    Display*		,
    Drawable		,
    XFontSet		,
    GC			,
    int			,
    int			,
    __const wchar_t*	,
    int			
);

extern void Xutf8DrawString(
    Display*		,
    Drawable		,
    XFontSet		,
    GC			,
    int			,
    int			,
    __const char*	,
    int			
);

extern void XmbDrawImageString(
    Display*		,
    Drawable		,
    XFontSet		,
    GC			,
    int			,
    int			,
    __const char*	,
    int			
);

extern void XwcDrawImageString(
    Display*		,
    Drawable		,
    XFontSet		,
    GC			,
    int			,
    int			,
    __const wchar_t*	,
    int			
);

extern void Xutf8DrawImageString(
    Display*		,
    Drawable		,
    XFontSet		,
    GC			,
    int			,
    int			,
    __const char*	,
    int			
);

extern XIM XOpenIM(
    Display*			,
    struct _XrmHashBucketRec*	,
    char*			,
    char*			
);

extern int XCloseIM(
    XIM 
);

extern char *XGetIMValues(
    XIM , ...
) __attribute__ ((__sentinel__(0)));

extern char *XSetIMValues(
    XIM , ...
) __attribute__ ((__sentinel__(0)));

extern Display *XDisplayOfIM(
    XIM 
);

extern char *XLocaleOfIM(
    XIM 
);

extern XIC XCreateIC(
    XIM , ...
) __attribute__ ((__sentinel__(0)));

extern void XDestroyIC(
    XIC 
);

extern void XSetICFocus(
    XIC 
);

extern void XUnsetICFocus(
    XIC 
);

extern wchar_t *XwcResetIC(
    XIC 
);

extern char *XmbResetIC(
    XIC 
);

extern char *Xutf8ResetIC(
    XIC 
);

extern char *XSetICValues(
    XIC , ...
) __attribute__ ((__sentinel__(0)));

extern char *XGetICValues(
    XIC , ...
) __attribute__ ((__sentinel__(0)));

extern XIM XIMOfIC(
    XIC 
);

extern int XFilterEvent(
    XEvent*	,
    Window	
);

extern int XmbLookupString(
    XIC			,
    XKeyPressedEvent*	,
    char*		,
    int			,
    KeySym*		,
    int*		
);

extern int XwcLookupString(
    XIC			,
    XKeyPressedEvent*	,
    wchar_t*		,
    int			,
    KeySym*		,
    int*		
);

extern int Xutf8LookupString(
    XIC			,
    XKeyPressedEvent*	,
    char*		,
    int			,
    KeySym*		,
    int*		
);

extern XVaNestedList XVaCreateNestedList(
    int , ...
) __attribute__ ((__sentinel__(0)));

extern int XRegisterIMInstantiateCallback(
    Display*			,
    struct _XrmHashBucketRec*	,
    char*			,
    char*			,
    XIDProc			,
    XPointer			
);

extern int XUnregisterIMInstantiateCallback(
    Display*			,
    struct _XrmHashBucketRec*	,
    char*			,
    char*			,
    XIDProc			,
    XPointer			
);

typedef void (*XConnectionWatchProc)(
    Display*			,
    XPointer			,
    int				,
    int			,	 
    XPointer*			 
);

extern int XInternalConnectionNumbers(
    Display*			,
    int**			,
    int*			
);

extern void XProcessInternalConnection(
    Display*			,
    int				
);

extern int XAddConnectionWatch(
    Display*			,
    XConnectionWatchProc	,
    XPointer			
);

extern void XRemoveConnectionWatch(
    Display*			,
    XConnectionWatchProc	,
    XPointer			
);

extern void XSetAuthorization(
    char *			,
    int				,
    char *			,
    int				
);

extern int _Xmbtowc(
    wchar_t *			,

    char *			,
    int				

);

extern int _Xwctomb(
    char *			,
    wchar_t			
);

extern int XGetEventData(
    Display*			,
    XGenericEventCookie*	
);

extern void XFreeEventData(
    Display*			,
    XGenericEventCookie*	
);

 

typedef struct {
    	long flags;	
	int x, y;		
	int width, height;	
	int min_width, min_height;
	int max_width, max_height;
    	int width_inc, height_inc;
	struct {
		int x;	
		int y;	
	} min_aspect, max_aspect;
	int base_width, base_height;		
	int win_gravity;			
} XSizeHints;

typedef struct {
	long flags;	
	int input;	

	int initial_state;	
	Pixmap icon_pixmap;	
	Window icon_window; 	
	int icon_x, icon_y; 	
	Pixmap icon_mask;	
	XID window_group;	
	
} XWMHints;

			

typedef struct {
    unsigned char *value;		
    Atom encoding;			
    int format;				
    unsigned long nitems;		
} XTextProperty;

typedef enum {
    XStringStyle,		
    XCompoundTextStyle,		
    XTextStyle,			
    XStdICCTextStyle,		
    
    XUTF8StringStyle		
} XICCEncodingStyle;

typedef struct {
	int min_width, min_height;
	int max_width, max_height;
	int width_inc, height_inc;
} XIconSize;

typedef struct {
	char *res_name;
	char *res_class;
} XClassHint;

typedef struct _XComposeStatus {
    XPointer compose_ptr;	
    int chars_matched;		
} XComposeStatus;

typedef struct _XRegion *Region;

typedef struct {
  Visual *visual;
  VisualID visualid;
  int screen;
  int depth;

  int xclass;

  unsigned long red_mask;
  unsigned long green_mask;
  unsigned long blue_mask;
  int colormap_size;
  int bits_per_rgb;
} XVisualInfo;

typedef struct {
	Colormap colormap;
	unsigned long red_max;
	unsigned long red_mult;
	unsigned long green_max;
	unsigned long green_mult;
	unsigned long blue_max;
	unsigned long blue_mult;
	unsigned long base_pixel;
	VisualID visualid;		
	XID killid;			
} XStandardColormap;

typedef int XContext;

extern XClassHint *XAllocClassHint (
    void
);

extern XIconSize *XAllocIconSize (
    void
);

extern XSizeHints *XAllocSizeHints (
    void
);

extern XStandardColormap *XAllocStandardColormap (
    void
);

extern XWMHints *XAllocWMHints (
    void
);

extern int XClipBox(
    Region		,
    XRectangle*		
);

extern Region XCreateRegion(
    void
);

extern __const char *XDefaultString (void);

extern int XDeleteContext(
    Display*		,
    XID			,
    XContext		
);

extern int XDestroyRegion(
    Region		
);

extern int XEmptyRegion(
    Region		
);

extern int XEqualRegion(
    Region		,
    Region		
);

extern int XFindContext(
    Display*		,
    XID			,
    XContext		,
    XPointer*		
);

extern int XGetClassHint(
    Display*		,
    Window		,
    XClassHint*		
);

extern int XGetIconSizes(
    Display*		,
    Window		,
    XIconSize**		,
    int*		
);

extern int XGetNormalHints(
    Display*		,
    Window		,
    XSizeHints*		
);

extern int XGetRGBColormaps(
    Display*		,
    Window		,
    XStandardColormap** ,
    int*		,
    Atom		
);

extern int XGetSizeHints(
    Display*		,
    Window		,
    XSizeHints*		,
    Atom		
);

extern int XGetStandardColormap(
    Display*		,
    Window		,
    XStandardColormap*	,
    Atom		
);

extern int XGetTextProperty(
    Display*		,
    Window		,
    XTextProperty*	,
    Atom		
);

extern XVisualInfo *XGetVisualInfo(
    Display*		,
    long		,
    XVisualInfo*	,
    int*		
);

extern int XGetWMClientMachine(
    Display*		,
    Window		,
    XTextProperty*	
);

extern XWMHints *XGetWMHints(
    Display*		,
    Window		
);

extern int XGetWMIconName(
    Display*		,
    Window		,
    XTextProperty*	
);

extern int XGetWMName(
    Display*		,
    Window		,
    XTextProperty*	
);

extern int XGetWMNormalHints(
    Display*		,
    Window		,
    XSizeHints*		,
    long*		
);

extern int XGetWMSizeHints(
    Display*		,
    Window		,
    XSizeHints*		,
    long*		,
    Atom		
);

extern int XGetZoomHints(
    Display*		,
    Window		,
    XSizeHints*		
);

extern int XIntersectRegion(
    Region		,
    Region		,
    Region		
);

extern void XConvertCase(
    KeySym		,
    KeySym*		,
    KeySym*		
);

extern int XLookupString(
    XKeyEvent*		,
    char*		,
    int			,
    KeySym*		,
    XComposeStatus*	
);

extern int XMatchVisualInfo(
    Display*		,
    int			,
    int			,
    int			,
    XVisualInfo*	
);

extern int XOffsetRegion(
    Region		,
    int			,
    int			
);

extern int XPointInRegion(
    Region		,
    int			,
    int			
);

extern Region XPolygonRegion(
    XPoint*		,
    int			,
    int			
);

extern int XRectInRegion(
    Region		,
    int			,
    int			,
    unsigned int	,
    unsigned int	
);

extern int XSaveContext(
    Display*		,
    XID			,
    XContext		,
    __const char*	
);

extern int XSetClassHint(
    Display*		,
    Window		,
    XClassHint*		
);

extern int XSetIconSizes(
    Display*		,
    Window		,
    XIconSize*		,
    int			
);

extern int XSetNormalHints(
    Display*		,
    Window		,
    XSizeHints*		
);

extern void XSetRGBColormaps(
    Display*		,
    Window		,
    XStandardColormap*	,
    int			,
    Atom		
);

extern int XSetSizeHints(
    Display*		,
    Window		,
    XSizeHints*		,
    Atom		
);

extern int XSetStandardProperties(
    Display*		,
    Window		,
    __const char*	,
    __const char*	,
    Pixmap		,
    char**		,
    int			,
    XSizeHints*		
);

extern void XSetTextProperty(
    Display*		,
    Window		,
    XTextProperty*	,
    Atom		
);

extern void XSetWMClientMachine(
    Display*		,
    Window		,
    XTextProperty*	
);

extern int XSetWMHints(
    Display*		,
    Window		,
    XWMHints*		
);

extern void XSetWMIconName(
    Display*		,
    Window		,
    XTextProperty*	
);

extern void XSetWMName(
    Display*		,
    Window		,
    XTextProperty*	
);

extern void XSetWMNormalHints(
    Display*		,
    Window		,
    XSizeHints*		
);

extern void XSetWMProperties(
    Display*		,
    Window		,
    XTextProperty*	,
    XTextProperty*	,
    char**		,
    int			,
    XSizeHints*		,
    XWMHints*		,
    XClassHint*		
);

extern void XmbSetWMProperties(
    Display*		,
    Window		,
    __const char*	,
    __const char*	,
    char**		,
    int			,
    XSizeHints*		,
    XWMHints*		,
    XClassHint*		
);

extern void Xutf8SetWMProperties(
    Display*		,
    Window		,
    __const char*	,
    __const char*	,
    char**		,
    int			,
    XSizeHints*		,
    XWMHints*		,
    XClassHint*		
);

extern void XSetWMSizeHints(
    Display*		,
    Window		,
    XSizeHints*		,
    Atom		
);

extern int XSetRegion(
    Display*		,
    GC			,
    Region		
);

extern void XSetStandardColormap(
    Display*		,
    Window		,
    XStandardColormap*	,
    Atom		
);

extern int XSetZoomHints(
    Display*		,
    Window		,
    XSizeHints*		
);

extern int XShrinkRegion(
    Region		,
    int			,
    int			
);

extern int XStringListToTextProperty(
    char**		,
    int			,
    XTextProperty*	
);

extern int XSubtractRegion(
    Region		,
    Region		,
    Region		
);

extern int XmbTextListToTextProperty(
    Display*		display,
    char**		list,
    int			count,
    XICCEncodingStyle	style,
    XTextProperty*	text_prop_return
);

extern int XwcTextListToTextProperty(
    Display*		display,
    wchar_t**		list,
    int			count,
    XICCEncodingStyle	style,
    XTextProperty*	text_prop_return
);

extern int Xutf8TextListToTextProperty(
    Display*		display,
    char**		list,
    int			count,
    XICCEncodingStyle	style,
    XTextProperty*	text_prop_return
);

extern void XwcFreeStringList(
    wchar_t**		list
);

extern int XTextPropertyToStringList(
    XTextProperty*	,
    char***		,
    int*		
);

extern int XmbTextPropertyToTextList(
    Display*		display,
    __const XTextProperty* text_prop,
    char***		list_return,
    int*		count_return
);

extern int XwcTextPropertyToTextList(
    Display*		display,
    __const XTextProperty* text_prop,
    wchar_t***		list_return,
    int*		count_return
);

extern int Xutf8TextPropertyToTextList(
    Display*		display,
    __const XTextProperty* text_prop,
    char***		list_return,
    int*		count_return
);

extern int XUnionRectWithRegion(
    XRectangle*		,
    Region		,
    Region		
);

extern int XUnionRegion(
    Region		,
    Region		,
    Region		
);

extern int XWMGeometry(
    Display*		,
    int			,
    __const char*	,
    __const char*	,
    unsigned int	,
    XSizeHints*		,
    int*		,
    int*		,
    int*		,
    int*		,
    int*		
);

extern int XXorRegion(
    Region		,
    Region		,
    Region		
);

extern char *Xpermalloc(
    unsigned int	
);

typedef int       XrmQuark, *XrmQuarkList;

typedef char *XrmString;

extern XrmQuark XrmStringToQuark(
    __const char* 	
);

extern XrmQuark XrmPermStringToQuark(
    __const char* 	
);

extern XrmString XrmQuarkToString(
    XrmQuark 		
);

extern XrmQuark XrmUniqueQuark(
    void
);

typedef enum {XrmBindTightly, XrmBindLoosely} XrmBinding, *XrmBindingList;

extern void XrmStringToQuarkList(
    __const char*	,
    XrmQuarkList	
);

extern void XrmStringToBindingQuarkList(
    __const char*	,
    XrmBindingList	,
    XrmQuarkList	
);

typedef XrmQuark     XrmName;
typedef XrmQuarkList XrmNameList;

typedef XrmQuark     XrmClass;
typedef XrmQuarkList XrmClassList;

typedef XrmQuark     XrmRepresentation;

typedef struct {
    unsigned int    size;
    XPointer	    addr;
} XrmValue, *XrmValuePtr;

typedef struct _XrmHashBucketRec *XrmHashBucket;
typedef XrmHashBucket *XrmHashTable;
typedef XrmHashTable XrmSearchList[];
typedef struct _XrmHashBucketRec *XrmDatabase;

extern void XrmDestroyDatabase(
    XrmDatabase		
);

extern void XrmQPutResource(
    XrmDatabase*	,
    XrmBindingList	,
    XrmQuarkList	,
    XrmRepresentation	,
    XrmValue*		
);

extern void XrmPutResource(
    XrmDatabase*	,
    __const char*	,
    __const char*	,
    XrmValue*		
);

extern void XrmQPutStringResource(
    XrmDatabase*	,
    XrmBindingList      ,
    XrmQuarkList	,
    __const char*	
);

extern void XrmPutStringResource(
    XrmDatabase*	,
    __const char*	,
    __const char*	
);

extern void XrmPutLineResource(
    XrmDatabase*	,
    __const char*	
);

extern int XrmQGetResource(
    XrmDatabase		,
    XrmNameList		,
    XrmClassList	,
    XrmRepresentation*	,
    XrmValue*		
);

extern int XrmGetResource(
    XrmDatabase		,
    __const char*	,
    __const char*	,
    char**		,
    XrmValue*		
);

extern int XrmQGetSearchList(
    XrmDatabase		,
    XrmNameList		,
    XrmClassList	,
    XrmSearchList	,
    int			
);

extern int XrmQGetSearchResource(
    XrmSearchList	,
    XrmName		,
    XrmClass		,
    XrmRepresentation*	,
    XrmValue*		
);

extern void XrmSetDatabase(
    Display*		,
    XrmDatabase		
);

extern XrmDatabase XrmGetDatabase(
    Display*		
);

extern XrmDatabase XrmGetFileDatabase(
    __const char*	
);

extern int XrmCombineFileDatabase(
    __const char* 	,
    XrmDatabase*	,
    int		
);

extern XrmDatabase XrmGetStringDatabase(
    __const char*	  
);

extern void XrmPutFileDatabase(
    XrmDatabase		,
    __const char*	
);

extern void XrmMergeDatabases(
    XrmDatabase		,
    XrmDatabase*	
);

extern void XrmCombineDatabase(
    XrmDatabase		,
    XrmDatabase*	,
    int		
);

extern int XrmEnumerateDatabase(
    XrmDatabase		,
    XrmNameList		,
    XrmClassList	,
    int			,
    int (*)(
	     XrmDatabase*	,
	     XrmBindingList	,
	     XrmQuarkList	,
	     XrmRepresentation*	,
	     XrmValue*		,
	     XPointer		
	     )		,
    XPointer		
);

extern __const char *XrmLocaleOfDatabase(
    XrmDatabase 	
);

typedef enum {
    XrmoptionNoArg,	
    XrmoptionIsArg,     
    XrmoptionStickyArg, 
    XrmoptionSepArg,    
    XrmoptionResArg,	
    XrmoptionSkipArg,   
    XrmoptionSkipLine,  
    XrmoptionSkipNArgs	

} XrmOptionKind;

typedef struct {
    char	    *option;	    
    char	    *specifier;     
    XrmOptionKind   argKind;	    
    XPointer	    value;	    
} XrmOptionDescRec, *XrmOptionDescList;

extern void XrmParseCommand(
    XrmDatabase*	,
    XrmOptionDescList	,
    int			,
    __const char*	,
    int*		,
    char**		
);

typedef char *String;

typedef struct _WidgetRec *Widget;
typedef Widget *WidgetList;
typedef struct _WidgetClassRec *WidgetClass;
typedef struct _CompositeRec *CompositeWidget;
typedef struct _XtActionsRec *XtActionList;
typedef struct _XtEventRec *XtEventTable;

typedef struct _XtAppStruct *XtAppContext;
typedef unsigned long	XtValueMask;
typedef unsigned long	XtIntervalId;
typedef unsigned long	XtInputId;
typedef unsigned long	XtWorkProcId;
typedef unsigned long	XtSignalId;
typedef unsigned int	XtGeometryMask;
typedef unsigned long	XtGCMask;   
typedef unsigned long	Pixel;	    
typedef int		XtCacheType;

//typedef char		Boolean;
typedef long		XtArgVal;
typedef unsigned char	XtEnum;

typedef unsigned int	Cardinal;
typedef unsigned short	Dimension;  
typedef short		Position;   

typedef void*		XtPointer;

typedef XtPointer	Opaque;

typedef struct _WidgetClassRec *CoreWidgetClass;
typedef struct _WidgetRec *CoreWidget;
extern WidgetClass coreWidgetClass;

extern WidgetClass widgetClass;

typedef struct _CompositeClassRec *CompositeWidgetClass;

typedef Cardinal (*XtOrderProc)(
    Widget 	
);

extern void XtManageChildren(
    WidgetList 		,
    Cardinal 		
);

extern void XtManageChild(
    Widget 		
);

extern void XtUnmanageChildren(
    WidgetList 		,
    Cardinal 		
);

extern void XtUnmanageChild(
    Widget 		
);

typedef void (*XtDoChangeProc)(
    Widget		,
    WidgetList		,
    Cardinal *		,
    WidgetList		,
    Cardinal *		,
    XtPointer		
);

extern void XtChangeManagedSet(
    WidgetList		,
    Cardinal		,
    XtDoChangeProc	,
    XtPointer		,
    WidgetList		,
    Cardinal		
);

extern WidgetClass compositeWidgetClass;

typedef struct _ConstraintClassRec *ConstraintWidgetClass;

extern WidgetClass constraintWidgetClass;

typedef struct _ObjectRec *Object;
typedef struct _ObjectClassRec *ObjectClass;

extern WidgetClass objectClass;

typedef struct _RectObjRec *RectObj;
typedef struct _RectObjClassRec *RectObjClass;

extern WidgetClass rectObjClass;

typedef struct _TranslationData *XtTranslations;
typedef struct _TranslationData *XtAccelerators;
typedef unsigned int Modifiers;

typedef void (*XtActionProc)(
    Widget 		,
    XEvent*		,
    String*		,
    Cardinal*		
);

typedef XtActionProc* XtBoundActions;

typedef struct _XtActionsRec{
    String	 string;
    XtActionProc proc;
} XtActionsRec;

typedef enum {

    XtAddress,		
    XtBaseOffset,	
    XtImmediate,	
    XtResourceString,	
    XtResourceQuark,	
    XtWidgetBaseOffset,	
    XtProcedureArg	
} XtAddressMode;

typedef struct {
    XtAddressMode   address_mode;
    XtPointer	    address_id;
    Cardinal	    size;
} XtConvertArgRec, *XtConvertArgList;

typedef void (*XtConvertArgProc)(
    Widget 		,
    Cardinal*		,
    XrmValue*		
);

typedef struct {
    XtGeometryMask request_mode;
    Position x, y;
    Dimension width, height, border_width;
    Widget sibling;
    int stack_mode;   
} XtWidgetGeometry;

typedef void (*XtConverter)( 
    XrmValue*		,
    Cardinal*		,
    XrmValue*		,
    XrmValue*		
);

typedef Boolean (*XtTypeConverter)(
    Display*		,
    XrmValue*		,
    Cardinal*		,
    XrmValue*		,
    XrmValue*		,
    XtPointer*		
);

typedef void (*XtDestructor)(
    XtAppContext	,
    XrmValue*		,
    XtPointer 		,
    XrmValue*		,
    Cardinal*		
);

typedef Opaque XtCacheRef;

typedef Opaque XtActionHookId;

typedef void (*XtActionHookProc)(
    Widget		,
    XtPointer		,
    String		,
    XEvent*		,
    String*		,
    Cardinal*		
);

typedef unsigned long XtBlockHookId;

typedef void (*XtBlockHookProc)(
    XtPointer		
);

typedef void (*XtKeyProc)(
    Display*		,
    unsigned int 		,
    Modifiers		,
    Modifiers*		,
    KeySym*		
);

typedef void (*XtCaseProc)(
    Display*		,
    KeySym		,
    KeySym*		,
    KeySym*		
);

typedef void (*XtEventHandler)(
    Widget 		,
    XtPointer 		,
    XEvent*		,
    Boolean*		
);
typedef unsigned long EventMask;

typedef enum {XtListHead, XtListTail } XtListPosition;

typedef unsigned long	XtInputMask;

typedef void (*XtTimerCallbackProc)(
    XtPointer 		,
    XtIntervalId*	
);

typedef void (*XtInputCallbackProc)(
    XtPointer 		,
    int*		,
    XtInputId*		
);

typedef void (*XtSignalCallbackProc)(
    XtPointer		,
    XtSignalId*		
);

typedef struct {
    String	name;
    XtArgVal	value;
} Arg, *ArgList;

typedef XtPointer	XtVarArgsList;

typedef void (*XtCallbackProc)(
    Widget 		,
    XtPointer 		,	
    XtPointer 			
);

typedef struct _XtCallbackRec {
    XtCallbackProc  callback;
    XtPointer	    closure;
} XtCallbackRec, *XtCallbackList;

typedef enum {
	XtCallbackNoList,
	XtCallbackHasNone,
	XtCallbackHasSome
} XtCallbackStatus;

typedef enum  {
    XtGeometryYes,	  
    XtGeometryNo,	  
    XtGeometryAlmost,	  
    XtGeometryDone	  
} XtGeometryResult;

typedef enum {XtGrabNone, XtGrabNonexclusive, XtGrabExclusive} XtGrabKind;

typedef struct {
    Widget  shell_widget;
    Widget  enable_widget;
} XtPopdownIDRec, *XtPopdownID;

typedef struct _XtResource {
    String	resource_name;	
    String	resource_class;	
    String	resource_type;	
    Cardinal	resource_size;	
    Cardinal	resource_offset;
    String	default_type;	
    XtPointer	default_addr;	
} XtResource, *XtResourceList;

typedef void (*XtResourceDefaultProc)(
    Widget	,
    int		,
    XrmValue*	
);

typedef String (*XtLanguageProc)(
    Display*	,
    String	,
    XtPointer	
);

typedef void (*XtErrorMsgHandler)(
    String 		,
    String		,
    String		,
    String		,
    String*		,
    Cardinal*		
);

typedef void (*XtErrorHandler)(
  String		
);

typedef void (*XtCreatePopupChildProc)(
    Widget	
);

typedef Boolean (*XtWorkProc)(
    XtPointer 			
);

typedef struct {
    char match;
    String substitution;
} SubstitutionRec, *Substitution;

typedef Boolean (*XtFilePredicate)(
   String 
);

typedef XtPointer XtRequestId;

typedef Boolean (*XtConvertSelectionProc)(
    Widget 		,
    Atom*		,
    Atom*		,
    Atom*		,
    XtPointer*		,
    unsigned long*	,
    int*		
);

typedef void (*XtLoseSelectionProc)(
    Widget 		,
    Atom*		
);

typedef void (*XtSelectionDoneProc)(
    Widget 		,
    Atom*		,
    Atom*		
);

typedef void (*XtSelectionCallbackProc)(
    Widget 		,
    XtPointer 		,
    Atom*		,
    Atom*		,
    XtPointer 		,
    unsigned long*	,
    int*		
);

typedef void (*XtLoseSelectionIncrProc)(
    Widget 		,
    Atom*		,
    XtPointer 		
);

typedef void (*XtSelectionDoneIncrProc)(
    Widget 		,
    Atom*		,
    Atom*		,
    XtRequestId*	,
    XtPointer 		
);

typedef Boolean (*XtConvertSelectionIncrProc)(
    Widget 		,
    Atom*		,
    Atom*		,
    Atom*		,
    XtPointer*		,
    unsigned long*	,
    int*		,
    unsigned long*	,
    XtPointer 		,
    XtRequestId*	
);

typedef void (*XtCancelConvertSelectionProc)(
    Widget 		,
    Atom*		,
    Atom*		,
    XtRequestId*	,
    XtPointer 		
);

typedef Boolean (*XtEventDispatchProc)(
    XEvent*		
);

typedef void (*XtExtensionSelectProc)(
    Widget		,
    int*		,
    XtPointer*		,
    int			,
    XtPointer		
);

extern Boolean XtConvertAndStore(
    Widget 		,
    __const char* 	,
    XrmValue*		,
    __const char* 	,
    XrmValue*		
);

extern Boolean XtCallConverter(
    Display*		,
    XtTypeConverter 	,
    XrmValuePtr 	,
    Cardinal 		,
    XrmValuePtr 	,
    XrmValue*		,
    XtCacheRef*		
);

extern Boolean XtDispatchEvent(
    XEvent* 		
);

extern Boolean XtCallAcceptFocus(
    Widget 		,
    Time*		
);

extern Boolean XtPeekEvent( 
    XEvent*		
);

extern Boolean XtAppPeekEvent(
    XtAppContext 	,
    XEvent*		
);

extern Boolean XtIsSubclass(
    Widget 		,
    WidgetClass 	
);

extern Boolean XtIsObject(
    Widget 		
);

extern Boolean _XtCheckSubclassFlag( 
    Widget		,
    unsigned int		
);

extern Boolean _XtIsSubclassOf( 
    Widget		,
    WidgetClass		,
    WidgetClass		,
    unsigned int		
);

extern Boolean XtIsManaged(
    Widget 		
);

extern Boolean XtIsRealized(
    Widget 		
);

extern Boolean XtIsSensitive(
    Widget 		
);

extern Boolean XtOwnSelection(
    Widget 		,
    Atom 		,
    Time 		,
    XtConvertSelectionProc ,
    XtLoseSelectionProc	,
    XtSelectionDoneProc 
);

extern Boolean XtOwnSelectionIncremental(
    Widget 		,
    Atom 		,
    Time 		,
    XtConvertSelectionIncrProc	,
    XtLoseSelectionIncrProc	,
    XtSelectionDoneIncrProc	,
    XtCancelConvertSelectionProc ,
    XtPointer 		
);

extern XtGeometryResult XtMakeResizeRequest(
    Widget 		,
    unsigned int	,
    unsigned int	,
    Dimension*		,
    Dimension*		
);

extern void XtTranslateCoords(
    Widget 		,
    int		,
    int		,
    Position*		,
    Position*		
);

extern KeySym* XtGetKeysymTable(
    Display*		,
    KeyCode*		,
    int*		
);

extern void XtKeysymToKeycodeList(
    Display*		,
    KeySym 		,
    KeyCode**		,
    Cardinal*		
);

extern void XtStringConversionWarning( 
    __const char*	,
    __const char*	
);

extern void XtDisplayStringConversionWarning(
    Display*	 	,
    __const char*	,
    __const char*	
);

extern XtConvertArgRec __const colorConvertArgs[];
extern XtConvertArgRec __const screenConvertArg[];

extern void XtAppAddConverter( 
    XtAppContext	,
    __const char*	,
    __const char*	,
    XtConverter 	,
    XtConvertArgList	,
    Cardinal 		
);

extern void XtAddConverter( 
    __const char*	,
    __const char* 	,
    XtConverter 	,
    XtConvertArgList 	,
    Cardinal 		
);

extern void XtSetTypeConverter(
    __const char* 	,
    __const char* 	,
    XtTypeConverter 	,
    XtConvertArgList 	,
    Cardinal 		,
    XtCacheType 	,
    XtDestructor 	
);

extern void XtAppSetTypeConverter(
    XtAppContext 	,
    __const char* 	,
    __const char* 	,
    XtTypeConverter 	,
    XtConvertArgList 	,
    Cardinal 		,
    XtCacheType 	,
    XtDestructor 	
);

extern void XtConvert( 
    Widget 		,
    __const char* 	,
    XrmValue*		,
    __const char* 	,
    XrmValue*		
);

extern void XtDirectConvert( 
    XtConverter 	,
    XrmValuePtr 	,
    Cardinal 		,
    XrmValuePtr 	,
    XrmValue*		
);

extern XtTranslations XtParseTranslationTable(
    __const char*	
);

extern XtAccelerators XtParseAcceleratorTable(
    __const char*	
);

extern void XtOverrideTranslations(
    Widget 		,
    XtTranslations 	
);

extern void XtAugmentTranslations(
    Widget 		,
    XtTranslations 	
);

extern void XtInstallAccelerators(
    Widget 		,
    Widget		
);

extern void XtInstallAllAccelerators(
    Widget 		,
    Widget		
);

extern void XtUninstallTranslations(
    Widget 		
);

extern void XtAppAddActions(
    XtAppContext 	,
    XtActionList 	,
    Cardinal 		
);

extern void XtAddActions( 
    XtActionList 	,
    Cardinal 		
);

extern XtActionHookId XtAppAddActionHook(
    XtAppContext 	,
    XtActionHookProc 	,
    XtPointer 		
);

extern void XtRemoveActionHook(
    XtActionHookId 	
);

extern void XtGetActionList(
    WidgetClass		,
    XtActionList*	,
    Cardinal*		
);

extern void XtCallActionProc(
    Widget		,
    __const char*	,
    XEvent*		,
    String*		,
    Cardinal		
);

extern void XtRegisterGrabAction(
    XtActionProc 	,
    int 		,
    unsigned int 	,
    int			,
    int	 		
);

extern void XtSetMultiClickTime(
    Display*		,
    int 		
);

extern int XtGetMultiClickTime(
    Display*		
);

extern KeySym XtGetActionKeysym(
    XEvent*		,
    Modifiers*		
);

extern void XtTranslateKeycode(
    Display*		,
    unsigned int 		,
    Modifiers 		,
    Modifiers*		,
    KeySym*		
);

extern void XtTranslateKey(
    Display*		,
    unsigned int		,
    Modifiers		,
    Modifiers*		,
    KeySym*		
);

extern void XtSetKeyTranslator(
    Display*		,
    XtKeyProc 		
);

extern void XtRegisterCaseConverter(
    Display*		,
    XtCaseProc 		,
    KeySym 		,
    KeySym 		
);

extern void XtConvertCase(
    Display*		,
    KeySym 		,
    KeySym*		,
    KeySym*		
);

extern void XtAddEventHandler(
    Widget 		,
    EventMask 		,
    int 		,
    XtEventHandler 	,
    XtPointer 		
);

extern void XtRemoveEventHandler(
    Widget 		,
    EventMask 		,
    int 		,
    XtEventHandler 	,
    XtPointer 		
);

extern void XtAddRawEventHandler(
    Widget 		,
    EventMask 		,
    int 		,
    XtEventHandler 	,
    XtPointer 		
);

extern void XtRemoveRawEventHandler(
    Widget 		,
    EventMask 		,
    int 		,
    XtEventHandler 	,
    XtPointer 		
);

extern void XtInsertEventHandler(
    Widget 		,
    EventMask 		,
    int 		,
    XtEventHandler 	,
    XtPointer 		,
    XtListPosition 	
);

extern void XtInsertRawEventHandler(
    Widget 		,
    EventMask 		,
    int 		,
    XtEventHandler 	,
    XtPointer 		,
    XtListPosition 	
);

extern XtEventDispatchProc XtSetEventDispatcher(
    Display*		,
    int			,
    XtEventDispatchProc	
);

extern Boolean XtDispatchEventToWidget(
    Widget		,
    XEvent*		
);

extern void XtInsertEventTypeHandler(
    Widget		,
    int			,
    XtPointer		,
    XtEventHandler	,
    XtPointer		,
    XtListPosition	
);

extern void XtRemoveEventTypeHandler(
    Widget		,
    int			,
    XtPointer		,
    XtEventHandler	,
    XtPointer		
);

extern EventMask XtBuildEventMask(
    Widget 		
);

extern void XtRegisterExtensionSelector(
    Display*		,
    int			,
    int			,
    XtExtensionSelectProc ,
    XtPointer		
);

extern void XtAddGrab(
    Widget 		,
    int 		,
    int 		
);

extern void XtRemoveGrab(
    Widget 		
);

extern void XtProcessEvent( 
    XtInputMask 		
);

extern void XtAppProcessEvent(
    XtAppContext 		,
    XtInputMask 		
);

extern void XtMainLoop( 
    void
);

extern void XtAppMainLoop(
    XtAppContext 		
);

extern void XtAddExposureToRegion(
    XEvent*		,
    Region 		
);

extern void XtSetKeyboardFocus(
    Widget		,
    Widget 		
);

extern Widget XtGetKeyboardFocusWidget(
    Widget		
);

extern XEvent* XtLastEventProcessed(
    Display*		
);

extern Time XtLastTimestampProcessed(
    Display*		
);

extern XtIntervalId XtAddTimeOut( 
    unsigned long 	,
    XtTimerCallbackProc ,
    XtPointer 		
);

extern XtIntervalId XtAppAddTimeOut(
    XtAppContext 	,
    unsigned long 	,
    XtTimerCallbackProc ,
    XtPointer 		
);

extern void XtRemoveTimeOut(
    XtIntervalId 	
);

extern XtInputId XtAddInput( 
    int 		,
    XtPointer 		,
    XtInputCallbackProc ,
    XtPointer 		
);

extern XtInputId XtAppAddInput(
    XtAppContext       	,
    int 		,
    XtPointer 		,
    XtInputCallbackProc ,
    XtPointer 		
);

extern void XtRemoveInput(
    XtInputId 		
);

extern XtSignalId XtAddSignal(
    XtSignalCallbackProc ,
    XtPointer		);

extern XtSignalId XtAppAddSignal(
    XtAppContext       	,
    XtSignalCallbackProc ,
    XtPointer 		
);

extern void XtRemoveSignal(
    XtSignalId 		
);

extern void XtNoticeSignal(
    XtSignalId		
);

extern void XtNextEvent( 
    XEvent* 		
);

extern void XtAppNextEvent(
    XtAppContext 	,
    XEvent*		
);

extern Boolean XtPending( 
    void
);

extern XtInputMask XtAppPending(
    XtAppContext 	
);

extern XtBlockHookId XtAppAddBlockHook(
    XtAppContext 	,
    XtBlockHookProc 	,
    XtPointer 		
);

extern void XtRemoveBlockHook(
    XtBlockHookId 	
);

extern Boolean XtIsOverrideShell(Widget );

extern Boolean XtIsVendorShell(Widget );

extern Boolean XtIsTransientShell(Widget );

extern Boolean XtIsApplicationShell(Widget );

extern Boolean XtIsSessionShell(Widget );

extern void XtRealizeWidget(
    Widget 		
);

void XtUnrealizeWidget(
    Widget 		
);

extern void XtDestroyWidget(
    Widget 		
);

extern void XtSetSensitive(
    Widget 		,
    int 		
);

extern void XtSetMappedWhenManaged(
    Widget 		,
    int 		
);

extern Widget XtNameToWidget(
    Widget 		,
    __const char*	
);

extern Widget XtWindowToWidget(
    Display*		,
    Window 		
);

extern XtPointer XtGetClassExtension(
    WidgetClass		,
    Cardinal		,
    XrmQuark		,
    long		,
    Cardinal		
);

extern ArgList XtMergeArgLists(
    ArgList 		,
    Cardinal 		,
    ArgList 		,
    Cardinal 		
);

extern XtVarArgsList XtVaCreateArgsList(
    XtPointer		, ...
) __attribute__ ((__sentinel__(0)));

extern Display *XtDisplay(
    Widget 		
);

extern Display *XtDisplayOfObject(
    Widget 		
);

extern Screen *XtScreen(
    Widget 		
);

extern Screen *XtScreenOfObject(
    Widget 		
);

extern Window XtWindow(
    Widget 		
);

extern Window XtWindowOfObject(
    Widget 		
);

extern String XtName(
    Widget 		
);

extern WidgetClass XtSuperclass(
    Widget 		
);

extern WidgetClass XtClass(
    Widget 		
);

extern Widget XtParent(
    Widget 		
);

extern void XtMapWidget(Widget );

extern void XtUnmapWidget(Widget );

extern void XtAddCallback(
    Widget 		,
    __const char* 	,
    XtCallbackProc 	,
    XtPointer 		
);

extern void XtRemoveCallback(
    Widget 		,
    __const char* 	,
    XtCallbackProc 	,
    XtPointer 		
);

extern void XtAddCallbacks(
    Widget 		,
    __const char*	,
    XtCallbackList 	
);

extern void XtRemoveCallbacks(
    Widget 		,
    __const char* 	,
    XtCallbackList 	
);

extern void XtRemoveAllCallbacks(
    Widget 		,
    __const char* 	
);

extern void XtCallCallbacks(
    Widget 		,
    __const char* 	,
    XtPointer 		
);

extern void XtCallCallbackList(
    Widget		,
    XtCallbackList 	,
    XtPointer 		
);

extern XtCallbackStatus XtHasCallbacks(
    Widget 		,
    __const char* 	
);

extern XtGeometryResult XtMakeGeometryRequest(
    Widget 		,
    XtWidgetGeometry*	,
    XtWidgetGeometry*	
);

extern XtGeometryResult XtQueryGeometry(
    Widget 		,
    XtWidgetGeometry*	,
    XtWidgetGeometry*	
);

extern Widget XtCreatePopupShell(
    __const char*	,
    WidgetClass 	,
    Widget 		,
    ArgList 		,
    Cardinal 		
);

extern Widget XtVaCreatePopupShell(
    __const char*	,
    WidgetClass		,
    Widget		,
    ...
) __attribute__ ((__sentinel__(0)));

extern void XtPopup(
    Widget 		,
    XtGrabKind 		
);

extern void XtPopupSpringLoaded(
    Widget 		
);

extern void XtCallbackNone(
    Widget 		,
    XtPointer 		,
    XtPointer 		
);

extern void XtCallbackNonexclusive(
    Widget 		,
    XtPointer 		,
    XtPointer 		
);

extern void XtCallbackExclusive(
    Widget 		,
    XtPointer 		,
    XtPointer 		
);

extern void XtPopdown(
    Widget 		
);

extern void XtCallbackPopdown(
    Widget 		,
    XtPointer 		,
    XtPointer 		
);

extern void XtMenuPopupAction(
    Widget 		,
    XEvent*		,
    String*		,
    Cardinal*		
);

extern Widget XtCreateWidget(
    __const char* 	,
    WidgetClass 	,
    Widget 		,
    ArgList 		,
    Cardinal 		
);

extern Widget XtCreateManagedWidget(
    __const char* 	,
    WidgetClass 	,
    Widget 		,
    ArgList 		,
    Cardinal 		
);

extern Widget XtVaCreateWidget(
    __const char*	,
    WidgetClass		,
    Widget		,
    ...
) __attribute__ ((__sentinel__(0)));

extern Widget XtVaCreateManagedWidget(
    __const char*	,
    WidgetClass		,
    Widget		,
    ...
) __attribute__ ((__sentinel__(0)));

extern Widget XtCreateApplicationShell( 
    __const char* 	,
    WidgetClass 	,
    ArgList 		,
    Cardinal 		
);

extern Widget XtAppCreateShell(
    __const char*	,
    __const char*	,
    WidgetClass 	,
    Display*		,
    ArgList 		,
    Cardinal 		
);

extern Widget XtVaAppCreateShell(
    __const char*	,
    __const char*	,
    WidgetClass		,
    Display*		,
    ...
) __attribute__ ((__sentinel__(0)));

extern void XtToolkitInitialize(
    void
);

extern XtLanguageProc XtSetLanguageProc(
    XtAppContext	,
    XtLanguageProc	,
    XtPointer		
);

extern void XtDisplayInitialize(
    XtAppContext 	,
    Display*		,
    __const char*	,
    __const char*	,
    XrmOptionDescRec* 	,
    Cardinal 		,
    int*		,
    char**		
);

extern Widget XtOpenApplication(
    XtAppContext*	,
    __const char*	,
    XrmOptionDescList 	,
    Cardinal 		,
    int*		,
    String*		,
    String*		,
    WidgetClass		,
    ArgList 		,
    Cardinal 		
);

extern Widget XtVaOpenApplication(
    XtAppContext*	,
    __const char*	,
    XrmOptionDescList	,
    Cardinal		,
    int*		,
    String*		,
    String*		,
    WidgetClass		,
    ...
) __attribute__ ((__sentinel__(0)));

extern Widget XtAppInitialize( 
    XtAppContext*	,
    __const char*	,
    XrmOptionDescList 	,
    Cardinal 		,
    int*		,
    String*		,
    String*		,
    ArgList 		,
    Cardinal 		
);

extern Widget XtVaAppInitialize( 
    XtAppContext*	,
    __const char*	,
    XrmOptionDescList	,
    Cardinal		,
    int*		,
    String*		,
    String*		,
    ...
) __attribute__ ((__sentinel__(0)));

extern Widget XtInitialize( 
    __const char* 	,
    __const char* 	,
    XrmOptionDescRec* 	,
    Cardinal 		,
    int*		,
    char**		
);

extern Display *XtOpenDisplay(
    XtAppContext 	,
    __const char*	,
    __const char*	,
    __const char*	,
    XrmOptionDescRec*	,
    Cardinal 		,
    int*		,
    char**		
);

extern XtAppContext XtCreateApplicationContext(
    void
);

extern void XtAppSetFallbackResources(
    XtAppContext 	,
    String*		
);

extern void XtDestroyApplicationContext(
    XtAppContext 	
);

extern void XtInitializeWidgetClass(
    WidgetClass 	
);

extern XtAppContext XtWidgetToApplicationContext(
    Widget 		
);

extern XtAppContext XtDisplayToApplicationContext(
    Display*		
);

extern XrmDatabase XtDatabase(
    Display*		
);

extern XrmDatabase XtScreenDatabase(
    Screen*		
);

extern void XtCloseDisplay(
    Display*		
);

extern void XtGetApplicationResources(
    Widget 		,
    XtPointer 		,
    XtResourceList 	,
    Cardinal 		,
    ArgList 		,
    Cardinal 		
);

extern void XtVaGetApplicationResources(
    Widget		,
    XtPointer		,
    XtResourceList	,
    Cardinal		,
    ...
) __attribute__ ((__sentinel__(0)));

extern void XtGetSubresources(
    Widget 		,
    XtPointer 		,
    __const char* 	,
    __const char* 	,
    XtResourceList 	,
    Cardinal 		,
    ArgList 		,
    Cardinal 		
);

extern void XtVaGetSubresources(
    Widget		,
    XtPointer		,
    __const char*	,
    __const char*	,
    XtResourceList	,
    Cardinal		,
    ...
) __attribute__ ((__sentinel__(0)));

extern void XtSetValues(
    Widget 		,
    ArgList 		,
    Cardinal 		
);

extern void XtVaSetValues(
    Widget		,
    ...
) __attribute__ ((__sentinel__(0)));

extern void XtGetValues(
    Widget 		,
    ArgList 		,
    Cardinal 		
);

extern void XtVaGetValues(
    Widget		,
    ...
) __attribute__ ((__sentinel__(0)));

extern void XtSetSubvalues(
    XtPointer 		,
    XtResourceList 	,
    Cardinal 		,
    ArgList 		,
    Cardinal 		
);

extern void XtVaSetSubvalues(
    XtPointer		,
    XtResourceList	,
    Cardinal		,
    ...
) __attribute__ ((__sentinel__(0)));

extern void XtGetSubvalues(
    XtPointer 		,
    XtResourceList 	,
    Cardinal 		,
    ArgList 		,
    Cardinal 		
);

extern void XtVaGetSubvalues(
    XtPointer		,
    XtResourceList	,
    Cardinal		,
    ...
) __attribute__ ((__sentinel__(0)));

extern void XtGetResourceList(
    WidgetClass 	,
    XtResourceList*	,
    Cardinal*		
);

extern void XtGetConstraintResourceList(
    WidgetClass 	,
    XtResourceList*	,
    Cardinal*		
);

typedef struct _XtCheckpointTokenRec {
    int		save_type;
    int		interact_style;
    Boolean	shutdown;
    Boolean	fast;
    Boolean	cancel_shutdown;
    int		phase;
    int		interact_dialog_type;	
    Boolean	request_cancel;		
    Boolean	request_next_phase;	
    Boolean	save_success;		
    int		type;		
    Widget	widget;		
} XtCheckpointTokenRec, *XtCheckpointToken;

XtCheckpointToken XtSessionGetToken(
    Widget		
);

void XtSessionReturnToken(
    XtCheckpointToken	
);

extern XtErrorMsgHandler XtAppSetErrorMsgHandler(
    XtAppContext 	,
    XtErrorMsgHandler 	
);

extern void XtSetErrorMsgHandler( 
    XtErrorMsgHandler 	
);

extern XtErrorMsgHandler XtAppSetWarningMsgHandler(
    XtAppContext 	,
    XtErrorMsgHandler 	
);

extern void XtSetWarningMsgHandler( 
    XtErrorMsgHandler 	
);

extern void XtAppErrorMsg(
    XtAppContext 	,
    __const char* 	,
    __const char*	,
    __const char*	,
    __const char*	,
    String*		,
    Cardinal*		
);

extern void XtErrorMsg( 
    __const char* 	,
    __const char*	,
    __const char*	,
    __const char*	,
    String*		,
    Cardinal*		
);

extern void XtAppWarningMsg(
    XtAppContext 	,
    __const char* 	,
    __const char* 	,
    __const char* 	,
    __const char* 	,
    String*		,
    Cardinal*		
);

extern void XtWarningMsg( 
    __const char*	,
    __const char*	,
    __const char*	,
    __const char*	,
    String*		,
    Cardinal*		
);

extern XtErrorHandler XtAppSetErrorHandler(
    XtAppContext 	,
    XtErrorHandler 	
);

extern void XtSetErrorHandler( 
    XtErrorHandler 	
);

extern XtErrorHandler XtAppSetWarningHandler(
    XtAppContext 	,
    XtErrorHandler 	
);

extern void XtSetWarningHandler( 
    XtErrorHandler 	
);

extern void XtAppError(
    XtAppContext 	,
    __const char*	
);

extern void XtError( 
    __const char*	
);

extern void XtAppWarning(
    XtAppContext 	,
    __const char*	
);

extern void XtWarning( 
    __const char*	
);

extern XrmDatabase *XtAppGetErrorDatabase(
    XtAppContext 	
);

extern XrmDatabase *XtGetErrorDatabase( 
    void
);

extern void XtAppGetErrorDatabaseText(
    XtAppContext 	,
    __const char*	,
    __const char*	,
    __const char*	,
    __const char* 	,
    String 		,
    int 		,
    XrmDatabase 	
);

extern void XtGetErrorDatabaseText( 
    __const char*	,
    __const char*	,
    __const char*	,
    __const char* 	,
    String 		,
    int 		
);

extern char *XtMalloc(
    Cardinal 		
);

extern char *XtCalloc(
    Cardinal		,
    Cardinal 		
);

extern char *XtRealloc(
    char* 		,
    Cardinal 		
);

extern void XtFree(
    char*		
);

extern Cardinal XtAsprintf(
    String *new_string,
    __const char * __restrict__ format,
    ...
) __attribute__((__format__(__printf__,2,3)));

extern String XtNewString(String );

extern XtWorkProcId XtAddWorkProc( 
    XtWorkProc 		,
    XtPointer 		
);

extern XtWorkProcId XtAppAddWorkProc(
    XtAppContext 	,
    XtWorkProc 		,
    XtPointer 		
);

extern void  XtRemoveWorkProc(
    XtWorkProcId 	
);

extern GC XtGetGC(
    Widget 		,
    XtGCMask 		,
    XGCValues* 		
);

extern GC XtAllocateGC(
    Widget 		,
    Cardinal		,
    XtGCMask 		,
    XGCValues* 		,
    XtGCMask		,
    XtGCMask		
);

extern void XtDestroyGC( 
    GC 			
);

extern void XtReleaseGC(
    Widget 		,
    GC 			
);

extern void XtAppReleaseCacheRefs(
    XtAppContext	,
    XtCacheRef*		
);

extern void XtCallbackReleaseCacheRef(
    Widget 		,
    XtPointer 		,	
    XtPointer 		
);

extern void XtCallbackReleaseCacheRefList(
    Widget 		,
    XtPointer 		,	
    XtPointer 		
);

extern void XtSetWMColormapWindows(
    Widget 		,
    Widget*		,
    Cardinal		
);

extern String XtFindFile(
    __const char*	,
    Substitution	,
    Cardinal 		,
    XtFilePredicate	
);

extern String XtResolvePathname(
    Display*		,
    __const char*	,
    __const char*	,
    __const char*	,
    __const char*	,
    Substitution	,
    Cardinal		,
    XtFilePredicate 	
);

extern void XtDisownSelection(
    Widget 		,
    Atom 		,
    Time 		
);

extern void XtGetSelectionValue(
    Widget 		,
    Atom 		,
    Atom 		,
    XtSelectionCallbackProc ,
    XtPointer 		,
    Time 		
);

extern void XtGetSelectionValues(
    Widget 		,
    Atom 		,
    Atom*		,
    int 		,
    XtSelectionCallbackProc ,
    XtPointer*		,
    Time 		
);

extern void XtAppSetSelectionTimeout(
    XtAppContext 	,
    unsigned long 	
);

extern void XtSetSelectionTimeout( 
    unsigned long 	
);

extern unsigned long XtAppGetSelectionTimeout(
    XtAppContext 	
);

extern unsigned long XtGetSelectionTimeout( 
    void
);

extern XSelectionRequestEvent *XtGetSelectionRequest(
    Widget 		,
    Atom 		,
    XtRequestId 	
);

extern void XtGetSelectionValueIncremental(
    Widget 		,
    Atom 		,
    Atom 		,
    XtSelectionCallbackProc ,
    XtPointer 		,
    Time 		
);

extern void XtGetSelectionValuesIncremental(
    Widget 		,
    Atom 		,
    Atom*		,
    int 		,
    XtSelectionCallbackProc ,
    XtPointer*		,
    Time 		
);

extern void XtSetSelectionParameters(
    Widget		,
    Atom		,
    Atom		,
    XtPointer		,
    unsigned long	,
    int			
);

extern void XtGetSelectionParameters(
    Widget		,
    Atom		,
    XtRequestId		,
    Atom*		,
    XtPointer*		,
    unsigned long*	,
    int*		
);

extern void XtCreateSelectionRequest(
    Widget		,
    Atom		
);

extern void XtSendSelectionRequest(
    Widget		,
    Atom		,
    Time		
);

extern void XtCancelSelectionRequest(
    Widget		,
    Atom		
);

extern Atom XtReservePropertyAtom(
    Widget		
);

extern void XtReleasePropertyAtom(
    Widget		,
    Atom		
);

extern void XtGrabKey(
    Widget 		,
    unsigned int 		,
    Modifiers	 	,
    int 		,
    int 		,
    int 		
);

extern void XtUngrabKey(
    Widget 		,
    unsigned int 		,
    Modifiers	 	
);

extern int XtGrabKeyboard(
    Widget 		,
    int 		,
    int 		,
    int 		,
    Time 		
);

extern void XtUngrabKeyboard(
    Widget 		,
    Time 		
);

extern void XtGrabButton(
    Widget 		,
    int 		,
    Modifiers	 	,
    int 		,
    unsigned int	,
    int 		,
    int 		,
    Window 		,
    Cursor 		
);

extern void XtUngrabButton(
    Widget 		,
    unsigned int	,
    Modifiers	 	
);

extern int XtGrabPointer(
    Widget 		,
    int 		,
    unsigned int	,
    int 		,
    int 		,
    Window 		,
    Cursor 		,
    Time 		
);

extern void XtUngrabPointer(
    Widget 		,
    Time 		
);

extern void XtGetApplicationNameAndClass(
    Display*		,
    String*		,
    String*		
);

extern void XtRegisterDrawable(
    Display*		,
    Drawable		,
    Widget		
);

extern void XtUnregisterDrawable(
    Display*		,
    Drawable		
);

extern Widget XtHooksOfDisplay(
    Display*		
);

typedef struct {
    String type;
    Widget widget;
    ArgList args;
    Cardinal num_args;
} XtCreateHookDataRec, *XtCreateHookData;

typedef struct {
    String type;
    Widget widget;
    XtPointer event_data;
    Cardinal num_event_data;
} XtChangeHookDataRec, *XtChangeHookData;

typedef struct {
    Widget old, req;
    ArgList args;
    Cardinal num_args;
} XtChangeHookSetValuesDataRec, *XtChangeHookSetValuesData;

typedef struct {
    String type;
    Widget widget;
    XtGeometryMask changeMask;
    XWindowChanges changes;
} XtConfigureHookDataRec, *XtConfigureHookData;

typedef struct {
    String type;
    Widget widget;
    XtWidgetGeometry* request;
    XtWidgetGeometry* reply;
    XtGeometryResult result;
} XtGeometryHookDataRec, *XtGeometryHookData;

typedef struct {
    String type;
    Widget widget;
} XtDestroyHookDataRec, *XtDestroyHookData;

extern void XtGetDisplays(
    XtAppContext	,
    Display***		,
    Cardinal*		
);

extern Boolean XtToolkitThreadInitialize(
    void
);

extern void XtAppSetmyexitFlag(
    XtAppContext	
);

extern Boolean XtAppGetmyexitFlag(
    XtAppContext	
);

extern void XtAppLock(
    XtAppContext	
);

extern void XtAppUnlock(
    XtAppContext	
);

extern Boolean XtCvtStringToAcceleratorTable(
    Display*	,
    XrmValuePtr ,	
    Cardinal*   ,
    XrmValuePtr	,
    XrmValuePtr	,
    XtPointer*	
);

extern Boolean XtCvtStringToAtom(
    Display*	,
    XrmValuePtr ,	
    Cardinal*   ,
    XrmValuePtr	,
    XrmValuePtr	,
    XtPointer*	
);

extern Boolean XtCvtStringToBool(
    Display*	,
    XrmValuePtr ,	
    Cardinal*   ,
    XrmValuePtr	,
    XrmValuePtr	,
    XtPointer*	
);

extern Boolean XtCvtStringToBoolean(
    Display*	,
    XrmValuePtr ,	
    Cardinal*   ,
    XrmValuePtr	,
    XrmValuePtr	,
    XtPointer*	
);

extern Boolean XtCvtStringToCommandArgArray(
    Display*	,
    XrmValuePtr ,	
    Cardinal*   ,
    XrmValuePtr	,
    XrmValuePtr	,
    XtPointer*	
);

extern Boolean XtCvtStringToCursor(
    Display*	,
    XrmValuePtr ,	
    Cardinal*   ,
    XrmValuePtr	,
    XrmValuePtr	,
    XtPointer*	
);

extern Boolean XtCvtStringToDimension(
    Display*	,
    XrmValuePtr ,	
    Cardinal*   ,
    XrmValuePtr	,
    XrmValuePtr	,
    XtPointer*	
);

extern Boolean XtCvtStringToDirectoryString(
    Display*	,
    XrmValuePtr ,	
    Cardinal*   ,
    XrmValuePtr	,
    XrmValuePtr	,
    XtPointer*	
);

extern Boolean XtCvtStringToDisplay(
    Display*	,
    XrmValuePtr ,	
    Cardinal*   ,
    XrmValuePtr	,
    XrmValuePtr	,
    XtPointer*	
);

extern Boolean XtCvtStringToFile(
    Display*	,
    XrmValuePtr ,	
    Cardinal*   ,
    XrmValuePtr	,
    XrmValuePtr	,
    XtPointer*	
);

extern Boolean XtCvtStringToFloat(
    Display*	,
    XrmValuePtr ,	
    Cardinal*   ,
    XrmValuePtr	,
    XrmValuePtr	,
    XtPointer*	
);

extern Boolean XtCvtStringToFont(
    Display*	,
    XrmValuePtr ,	
    Cardinal*   ,
    XrmValuePtr	,
    XrmValuePtr	,
    XtPointer*	
);

extern Boolean XtCvtStringToFontSet(
    Display*	,
    XrmValuePtr ,	
    Cardinal*   ,
    XrmValuePtr	,
    XrmValuePtr	,
    XtPointer*	
);

extern Boolean XtCvtStringToFontStruct(
    Display*	,
    XrmValuePtr ,	
    Cardinal*   ,
    XrmValuePtr	,
    XrmValuePtr	,
    XtPointer*	
);

extern Boolean XtCvtStringToGravity(
    Display*	,
    XrmValuePtr ,
    Cardinal*   ,
    XrmValuePtr	,
    XrmValuePtr	,
    XtPointer*	
);

extern Boolean XtCvtStringToInitialState(
    Display*	,
    XrmValuePtr ,	
    Cardinal*   ,
    XrmValuePtr	,
    XrmValuePtr	,
    XtPointer*	
);

extern Boolean XtCvtStringToInt(
    Display*	,
    XrmValuePtr ,	
    Cardinal*   ,
    XrmValuePtr	,
    XrmValuePtr	,
    XtPointer*	
);

extern Boolean XtCvtStringToPixel(
    Display*	,
    XrmValuePtr ,	
    Cardinal*   ,
    XrmValuePtr	,
    XrmValuePtr	,
    XtPointer*	
);

extern Boolean XtCvtStringToRestartStyle(
    Display*	,
    XrmValuePtr ,	
    Cardinal*   ,
    XrmValuePtr	,
    XrmValuePtr	,
    XtPointer*	
);

extern Boolean XtCvtStringToShort(
    Display*	,
    XrmValuePtr ,	
    Cardinal*   ,
    XrmValuePtr	,
    XrmValuePtr	,
    XtPointer*	
);

extern Boolean XtCvtStringToTranslationTable(
    Display*	,
    XrmValuePtr ,	
    Cardinal*   ,
    XrmValuePtr	,
    XrmValuePtr	,
    XtPointer*	
);

extern Boolean XtCvtStringToUnsignedChar(
    Display*	,
    XrmValuePtr ,	
    Cardinal*   ,
    XrmValuePtr	,
    XrmValuePtr	,
    XtPointer*	
);

extern Boolean XtCvtStringToVisual(
    Display*	,
    XrmValuePtr ,	
    Cardinal*   ,
    XrmValuePtr	,
    XrmValuePtr	,
    XtPointer*	
);

extern Boolean XtCvtIntToBool(
    Display*	,
    XrmValuePtr ,	
    Cardinal*   ,
    XrmValuePtr	,
    XrmValuePtr	,
    XtPointer*	
);

extern Boolean XtCvtIntToBoolean(
    Display*	,
    XrmValuePtr ,	
    Cardinal*   ,
    XrmValuePtr	,
    XrmValuePtr	,
    XtPointer*	
);

extern Boolean XtCvtIntToColor(
    Display*	,
    XrmValuePtr ,	
    Cardinal*   ,
    XrmValuePtr	,
    XrmValuePtr	,
    XtPointer*	
);

extern Boolean XtCvtIntToFloat(
    Display*	,
    XrmValuePtr ,	
    Cardinal*   ,
    XrmValuePtr	,
    XrmValuePtr	,
    XtPointer*	
);

extern Boolean XtCvtIntToFont(
    Display*	,
    XrmValuePtr ,	
    Cardinal*   ,
    XrmValuePtr	,
    XrmValuePtr	,
    XtPointer*	
);

extern Boolean XtCvtIntToPixel(
    Display*	,
    XrmValuePtr ,	
    Cardinal*   ,
    XrmValuePtr	,
    XrmValuePtr	,
    XtPointer*	
);

extern Boolean XtCvtIntToPixmap(
    Display*	,
    XrmValuePtr ,	
    Cardinal*   ,
    XrmValuePtr	,
    XrmValuePtr	,
    XtPointer*	
);

extern Boolean XtCvtIntToShort(
    Display*	,
    XrmValuePtr ,	
    Cardinal*   ,
    XrmValuePtr	,
    XrmValuePtr	,
    XtPointer*	
);

extern Boolean XtCvtIntToUnsignedChar(
    Display*	,
    XrmValuePtr ,	
    Cardinal*   ,
    XrmValuePtr	,
    XrmValuePtr	,
    XtPointer*	
);

extern Boolean XtCvtColorToPixel(
    Display*	,
    XrmValuePtr ,	
    Cardinal*   ,
    XrmValuePtr	,
    XrmValuePtr	,
    XtPointer*	
);

extern __const char XtStrings[];

typedef void *IcePointer;

typedef enum {
    IcePoAuthHaveReply,
    IcePoAuthRejected,
    IcePoAuthFailed,
    IcePoAuthDoneCleanup
} IcePoAuthStatus;

typedef enum {
    IcePaAuthContinue,
    IcePaAuthAccepted,
    IcePaAuthRejected,
    IcePaAuthFailed
} IcePaAuthStatus;

typedef enum {
    IceConnectPending,
    IceConnectAccepted,
    IceConnectRejected,
    IceConnectIOError
} IceConnectStatus;

typedef enum {
    IceProtocolSetupSuccess,
    IceProtocolSetupFailure,
    IceProtocolSetupIOError,
    IceProtocolAlreadyActive
} IceProtocolSetupStatus;

typedef enum {
    IceAcceptSuccess,
    IceAcceptFailure,
    IceAcceptBadMalloc
} IceAcceptStatus;

typedef enum {
    IceClosedNow,
    IceClosedASAP,
    IceConnectionInUse,
    IceStartedShutdownNegotiation
} IceCloseStatus;

typedef enum {
    IceProcessMessagesSuccess,
    IceProcessMessagesIOError,
    IceProcessMessagesConnectionClosed
} IceProcessMessagesStatus;

typedef struct {
    unsigned long	sequence_of_request;
    int			major_opcode_of_request;
    int			minor_opcode_of_request;
    IcePointer		reply;
} IceReplyWaitInfo;

typedef struct _IceConn *IceConn;
typedef struct _IceListenObj *IceListenObj;

typedef void (*IceWatchProc) (
    IceConn		,
    IcePointer		,
    int		,
    IcePointer *	
);

typedef void (*IcePoProcessMsgProc) (
    IceConn 		,
    IcePointer		,
    int			,
    unsigned long	,
    int		,
    IceReplyWaitInfo *  ,
    int *		
);

typedef void (*IcePaProcessMsgProc) (
    IceConn 		,
    IcePointer		,
    int			,
    unsigned long	,
    int		
);

typedef struct {
    int			 major_version;
    int			 minor_version;
    IcePoProcessMsgProc  process_msg_proc;
} IcePoVersionRec;

typedef struct {
    int			 major_version;
    int			 minor_version;
    IcePaProcessMsgProc  process_msg_proc;
} IcePaVersionRec;

typedef IcePoAuthStatus (*IcePoAuthProc) (
    IceConn		,
    IcePointer *	,
    int		,
    int		,
    int			,
    IcePointer		,
    int *		,
    IcePointer *	,
    char **		
);

typedef IcePaAuthStatus (*IcePaAuthProc) (
    IceConn		,
    IcePointer *	,
    int		,
    int			,
    IcePointer		,
    int *		,
    IcePointer *	,
    char **		
);

typedef int (*IceHostBasedAuthProc) (
    char *		
);

typedef int (*IceProtocolSetupProc) (
    IceConn 		,
    int			,
    int			,
    char *		,
    char *		,
    IcePointer *	,
    char **		
);

typedef void (*IceProtocolActivateProc) (
    IceConn 		,
    IcePointer		
);

typedef void (*IceIOErrorProc) (
    IceConn 		
);

typedef void (*IcePingReplyProc) (
    IceConn 		,
    IcePointer		
);

typedef void (*IceErrorHandler) (
    IceConn 		,
    int		,
    int			,
    unsigned long 	,
    int 		,
    int			,
    IcePointer		
);

typedef void (*IceIOErrorHandler) (
    IceConn 		
);

extern int IceRegisterForProtocolSetup (
    char *			,
    char *			,
    char *			,
    int				,
    IcePoVersionRec *		,
    int				,
    __const char **		,
    IcePoAuthProc *		,
    IceIOErrorProc		
);

extern int IceRegisterForProtocolReply (
    char *			,
    char *			,
    char *			,
    int				,
    IcePaVersionRec *		,
    int				,
    __const char **		,
    IcePaAuthProc *		,
    IceHostBasedAuthProc	,
    IceProtocolSetupProc	,
    IceProtocolActivateProc	,
    IceIOErrorProc		
);

extern IceConn IceOpenConnection (
    char *		,
    IcePointer		,
    int		,
    int			,
    int			,
    char *		
);

extern IcePointer IceGetConnectionContext (
    IceConn		
);

extern int IceListenForConnections (
    int *		,
    IceListenObj **	,
    int			,
    char *		
);

extern int IceListenForWellKnownConnections (
    char *		,
    int *		,
    IceListenObj **	,
    int			,
    char *		
);

extern int IceGetListenConnectionNumber (
    IceListenObj	
);

extern char *IceGetListenConnectionString (
    IceListenObj	
);

extern char *IceComposeNetworkIdList (
    int			,
    IceListenObj *	
);

extern void IceFreeListenObjs (
    int			,
    IceListenObj *	
);

extern void IceSetHostBasedAuthProc (
    IceListenObj		,
    IceHostBasedAuthProc   	
);

extern IceConn IceAcceptConnection (
    IceListenObj	,
    IceAcceptStatus *	
);

extern void IceSetShutdownNegotiation (
    IceConn		,
    int		
);

extern int IceCheckShutdownNegotiation (
    IceConn		
);

extern IceCloseStatus IceCloseConnection (
    IceConn		
);

extern int IceAddConnectionWatch (
    IceWatchProc		,
    IcePointer			
);

extern void IceRemoveConnectionWatch (
    IceWatchProc		,
    IcePointer			
);

extern IceProtocolSetupStatus IceProtocolSetup (
    IceConn		,
    int 		,
    IcePointer		,
    int		,
    int	*		,
    int	*		,
    char **		,
    char **		,
    int			,
    char *		
);

extern int IceProtocolShutdown (
    IceConn		,
    int			
);

extern IceProcessMessagesStatus IceProcessMessages (
    IceConn		,
    IceReplyWaitInfo *	,
    int *		
);

extern int IcePing (
   IceConn		,
   IcePingReplyProc	,
   IcePointer		
);

extern char *IceAllocScratch (
   IceConn		,
   unsigned long	
);

extern int IceFlush (
   IceConn		
);

extern int IceGetOutBufSize (
   IceConn		
);

extern int IceGetInBufSize (
   IceConn		
);

extern IceConnectStatus IceConnectionStatus (
    IceConn		
);

extern char *IceVendor (
    IceConn		
);

extern char *IceRelease (
    IceConn		
);

extern int IceProtocolVersion (
    IceConn		
);

extern int IceProtocolRevision (
    IceConn		
);

extern int IceConnectionNumber (
    IceConn		
);

extern char *IceConnectionString (
    IceConn		
);

extern unsigned long IceLastSentSequenceNumber (
    IceConn		
);

extern unsigned long IceLastReceivedSequenceNumber (
    IceConn		
);

extern int IceSwapping (
    IceConn		
);

extern IceErrorHandler IceSetErrorHandler (
    IceErrorHandler 	
);

extern IceIOErrorHandler IceSetIOErrorHandler (
    IceIOErrorHandler 	
);

extern char *IceGetPeerName (
    IceConn		
);

extern int IceInitThreads (
    void
);

extern void IceAppLockConn (
    IceConn		
);

extern void IceAppUnlockConn (
    IceConn		
);

typedef IcePointer SmPointer;

typedef struct _SmcConn *SmcConn;
typedef struct _SmsConn *SmsConn;

typedef struct {
    int		length;		
    SmPointer   value;		
} SmPropValue;

typedef struct {
    char	*name;		
    char	*type;		
    int		num_vals;	
    SmPropValue *vals;		
} SmProp;



typedef enum {
    SmcClosedNow,
    SmcClosedASAP,
    SmcConnectionInUse
} SmcCloseStatus;



typedef void (*SmcSaveYourselfProc) (
    SmcConn		,
    SmPointer		,
    int  		,
    int		,
    int			,
    int		
);

typedef void (*SmcSaveYourselfPhase2Proc) (
    SmcConn		,
    SmPointer		
);

typedef void (*SmcInteractProc) (
    SmcConn		,
    SmPointer		
);

typedef void (*SmcDieProc) (
    SmcConn		,
    SmPointer		
);

typedef void (*SmcShutdownCancelledProc) (
    SmcConn		,
    SmPointer		
);

typedef void (*SmcSaveCompleteProc) (
    SmcConn		,
    SmPointer		
);

typedef void (*SmcPropReplyProc) (
    SmcConn		,
    SmPointer		,
    int			,
    SmProp **		
);

typedef struct {

    struct {
	SmcSaveYourselfProc	 callback;
	SmPointer		 client_data;
    } save_yourself;

    struct {
	SmcDieProc		 callback;
	SmPointer		 client_data;
    } die;

    struct {
	SmcSaveCompleteProc	 callback;
	SmPointer		 client_data;
    } save_complete;

    struct {
	SmcShutdownCancelledProc callback;
	SmPointer		 client_data;
    } shutdown_cancelled;

} SmcCallbacks;



typedef int (*SmsRegisterClientProc) (
    SmsConn 		,
    SmPointer		,
    char *						     
);

typedef void (*SmsInteractRequestProc) (
    SmsConn		,
    SmPointer		,
    int			
);

typedef void (*SmsInteractDoneProc) (
    SmsConn		,
    SmPointer		,
    int		
);

typedef void (*SmsSaveYourselfRequestProc) (
    SmsConn		,
    SmPointer		,
    int  		,
    int		,
    int			,
    int		,
    int		
);

typedef void (*SmsSaveYourselfPhase2RequestProc) (
    SmsConn		,
    SmPointer		
);

typedef void (*SmsSaveYourselfDoneProc) (
    SmsConn		,
    SmPointer		,
    int		
);

typedef void (*SmsCloseConnectionProc) (
    SmsConn		,
    SmPointer		,
    int			,
    char **		
);

typedef void (*SmsSetPropertiesProc) (
    SmsConn		,
    SmPointer		,
    int			,
    SmProp **		
);

typedef void (*SmsDeletePropertiesProc) (
    SmsConn		,
    SmPointer		,
    int			,
    char **		
);

typedef void (*SmsGetPropertiesProc) (
    SmsConn		,
    SmPointer		
);

typedef struct {

    struct {
	SmsRegisterClientProc	callback;
	SmPointer		manager_data;
    } register_client;

    struct {
	SmsInteractRequestProc	callback;
	SmPointer		manager_data;
    } interact_request;

    struct {
	SmsInteractDoneProc	callback;
	SmPointer		manager_data;
    } interact_done;

    struct {
	SmsSaveYourselfRequestProc	callback;
	SmPointer			manager_data;
    } save_yourself_request;

    struct {
	SmsSaveYourselfPhase2RequestProc	callback;
	SmPointer				manager_data;
    } save_yourself_phase2_request;

    struct {
	SmsSaveYourselfDoneProc	callback;
	SmPointer		manager_data;
    } save_yourself_done;

    struct {
	SmsCloseConnectionProc	callback;
	SmPointer		manager_data;
    } close_connection;

    struct {
	SmsSetPropertiesProc	callback;
	SmPointer		manager_data;
    } set_properties;

    struct {
	SmsDeletePropertiesProc	callback;
	SmPointer		manager_data;
    } delete_properties;

    struct {
	SmsGetPropertiesProc	callback;
	SmPointer		manager_data;
    } get_properties;

} SmsCallbacks;

typedef int (*SmsNewClientProc) (
    SmsConn 		,
    SmPointer		,
    unsigned long *	,
    SmsCallbacks *	,
    char **		
);



typedef void (*SmcErrorHandler) (
    SmcConn		,
    int		,
    int			,
    unsigned long 	,
    int 		,
    int			,
    SmPointer		
);

typedef void (*SmsErrorHandler) (
    SmsConn		,
    int		,
    int			,
    unsigned long 	,
    int 		,
    int			,
    SmPointer		
);



extern SmcConn SmcOpenConnection (
    char *		,
    SmPointer		,
    int			,
    int			,
    unsigned long	,
    SmcCallbacks *	,
    char *		,
    char **		,
    int			,
    char *		
);

extern SmcCloseStatus SmcCloseConnection (
    SmcConn		,
    int			,
    char **		
);

extern void SmcModifyCallbacks (
    SmcConn		,
    unsigned long	,
    SmcCallbacks *	
);

extern void SmcSetProperties (
    SmcConn		,
    int      	        ,
    SmProp **		
);

extern void SmcDeleteProperties (
    SmcConn		,
    int      	        ,
    char **		
);

extern int SmcGetProperties (
    SmcConn		,
    SmcPropReplyProc	,
    SmPointer		
);

extern int SmcInteractRequest (
    SmcConn		,
    int			,
    SmcInteractProc	,
    SmPointer		
);

extern void SmcInteractDone (
    SmcConn		,
    int 		
);

extern void SmcRequestSaveYourself (
    SmcConn		,
    int			,
    int 		,
    int			,
    int		,
    int		
);

extern int SmcRequestSaveYourselfPhase2 (
    SmcConn			,
    SmcSaveYourselfPhase2Proc	,
    SmPointer			
);

extern void SmcSaveYourselfDone (
    SmcConn		,
    int		
);

extern int SmcProtocolVersion (
    SmcConn		
);

extern int SmcProtocolRevision (
    SmcConn		
);

extern char *SmcVendor (
    SmcConn		
);

extern char *SmcRelease (
    SmcConn		
);

extern char *SmcClientID (
    SmcConn		
);

extern IceConn SmcGetIceConnection (
    SmcConn		
);

extern int SmsInitialize (
    char *			,
    char *			,
    SmsNewClientProc		,
    SmPointer			,
    IceHostBasedAuthProc	,
    int				,
    char *			
);

extern char *SmsClientHostName (
    SmsConn		
);

extern char *SmsGenerateClientID (
    SmsConn		
);

extern int SmsRegisterClientReply (
    SmsConn		,
    char *		
);

extern void SmsSaveYourself (
    SmsConn		,
    int			,
    int 		,
    int			,
    int		
);

extern void SmsSaveYourselfPhase2 (
    SmsConn		
);

extern void SmsInteract (
    SmsConn		
);

extern void SmsDie (
    SmsConn		
);

extern void SmsSaveComplete (
    SmsConn		
);

extern void SmsShutdownCancelled (
    SmsConn		
);

extern void SmsReturnProperties (
    SmsConn		,
    int			,
    SmProp **		
);

extern void SmsCleanUp (
    SmsConn		
);

extern int SmsProtocolVersion (
    SmsConn		
);

extern int SmsProtocolRevision (
    SmsConn		
);

extern char *SmsClientID (
    SmsConn		
);

extern IceConn SmsGetIceConnection (
    SmsConn		
);

extern SmcErrorHandler SmcSetErrorHandler (
    SmcErrorHandler 	
);

extern SmsErrorHandler SmsSetErrorHandler (
    SmsErrorHandler 	
);

extern void SmFreeProperty (
    SmProp *		
);

extern void SmFreeReasons (
    int			,
    char **		
);

#ifdef __cplusplus
};
#endif

extern __const char XtShellStrings[];

typedef struct _ShellClassRec *ShellWidgetClass;
typedef struct _OverrideShellClassRec *OverrideShellWidgetClass;
typedef struct _WMShellClassRec *WMShellWidgetClass;
typedef struct _TransientShellClassRec *TransientShellWidgetClass;
typedef struct _TopLevelShellClassRec *TopLevelShellWidgetClass;
typedef struct _ApplicationShellClassRec *ApplicationShellWidgetClass;
typedef struct _SessionShellClassRec *SessionShellWidgetClass;

extern WidgetClass shellWidgetClass;
extern WidgetClass overrideShellWidgetClass;
extern WidgetClass wmShellWidgetClass;
extern WidgetClass transientShellWidgetClass;
extern WidgetClass topLevelShellWidgetClass;
extern WidgetClass applicationShellWidgetClass;
extern WidgetClass sessionShellWidgetClass;

extern Screen _s[1];
extern Visual _v[1];

