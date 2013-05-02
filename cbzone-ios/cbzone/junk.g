
typedef struct _xEvent {
    union {
	struct {
	    BYTE type;
	    BYTE detail;
	    CARD16 sequenceNumber B16;
	    } u;
	struct {
            CARD32 pad00 B32;
	    Time time B32;
	    Window root B32, event B32, child B32;
	    INT16 rootX B16, rootY B16, eventX B16, eventY B16;
	    KeyButMask state B16;
	    BOOL sameScreen;		
	    BYTE pad1;
	} keyButtonPointer;
	struct {
            CARD32 pad00 B32;
            Time time B32;
	    Window root B32, event B32, child B32;
	    INT16 rootX B16, rootY B16, eventX B16, eventY B16;
	    KeyButMask state B16;
	    BYTE mode; 			/* really XMode */
	    BYTE flags;		/* sameScreen and focus booleans, packed together */
#define ELFlagFocus        (1<<0)
#define ELFlagSameScreen   (1<<1)
	} enterLeave;
	struct {
            CARD32 pad00 B32;
	    Window window B32;
	    BYTE mode; 			/* really XMode */
	    BYTE pad1, pad2, pad3;
	} focus;
	struct {
            CARD32 pad00 B32;
	    Window window B32;
	    CARD16 x B16, y B16, width B16, height B16;
	    CARD16 count B16;
	    CARD16 pad2 B16;
	} expose;
	struct {
            CARD32 pad00 B32;
	    Drawable drawable B32;
	    CARD16 x B16, y B16, width B16, height B16;
	    CARD16 minorEvent B16;
	    CARD16 count B16;
	    BYTE majorEvent;
	    BYTE pad1, pad2, pad3;
	} graphicsExposure;
	struct {
            CARD32 pad00 B32;
	    Drawable drawable B32;
	    CARD16 minorEvent B16;
	    BYTE majorEvent;
	    BYTE bpad;
	} noExposure;
	struct {
            CARD32 pad00 B32;
	    Window window B32;
	    CARD8 state;
	    BYTE pad1, pad2, pad3;
	} visibility;
	struct {
            CARD32 pad00 B32;
	    Window parent B32, window B32;
	    INT16 x B16, y B16;
	    CARD16 width B16, height B16, borderWidth B16;
	    BOOL override;
	    BYTE bpad;
        } createNotify;
/*
 * The event fields in the structures for DestroyNotify, UnmapNotify,
 * MapNotify, ReparentNotify, ConfigureNotify, CirculateNotify, GravityNotify,
 * must be at the same offset because server internal code is depending upon
 * this to patch up the events before they are delivered.
 * Also note that MapRequest, ConfigureRequest and CirculateRequest have
 * the same offset for the event window.
 */
	struct {
            CARD32 pad00 B32;
	    Window event B32, window B32;
	} destroyNotify;
	struct {
            CARD32 pad00 B32;
	    Window event B32, window B32;
	    BOOL fromConfigure;
	    BYTE pad1, pad2, pad3;
        } unmapNotify;
	struct {
            CARD32 pad00 B32;
	    Window event B32, window B32;
	    BOOL override;
	    BYTE pad1, pad2, pad3;
        } mapNotify;
	struct {
            CARD32 pad00 B32;
	    Window parent B32, window B32;
        } mapRequest;
	struct {
            CARD32 pad00 B32;
	    Window event B32, window B32, parent B32;
	    INT16 x B16, y B16;
	    BOOL override;
	    BYTE pad1, pad2, pad3;
	} reparent;
	struct {
            CARD32 pad00 B32;
	    Window event B32, window B32, aboveSibling B32;
	    INT16 x B16, y B16;
	    CARD16 width B16, height B16, borderWidth B16;
	    BOOL override;		
	    BYTE bpad;
	} configureNotify;
	struct {
            CARD32 pad00 B32;
	    Window parent B32, window B32, sibling B32;
	    INT16 x B16, y B16;
	    CARD16 width B16, height B16, borderWidth B16;
	    CARD16 valueMask B16;
	    CARD32 pad1 B32;
	} configureRequest;
	struct {
            CARD32 pad00 B32;
	    Window event B32, window B32;
	    INT16 x B16, y B16;
	    CARD32 pad1 B32, pad2 B32, pad3 B32, pad4 B32;
	} gravity;
	struct {
            CARD32 pad00 B32;
	    Window window B32;
	    CARD16 width B16, height B16;
	} resizeRequest;
	struct {
/* The event field in the circulate record is really the parent when this
   is used as a CirculateRequest instead of a CirculateNotify */
            CARD32 pad00 B32;
	    Window event B32, window B32, parent B32;
	    BYTE place;			/* Top or Bottom */
	    BYTE pad1, pad2, pad3;
	} circulate;
	struct {
            CARD32 pad00 B32;
	    Window window B32;
	    Atom atom B32;
	    Time time B32;
	    BYTE state;			/* NewValue or Deleted */
	    BYTE pad1;
	    CARD16 pad2 B16;
	} property;
	struct {
            CARD32 pad00 B32;
            Time time B32;     
	    Window window B32;
	    Atom atom B32;
	} selectionClear;
	struct {
            CARD32 pad00 B32;
            Time time B32;    
	    Window owner B32, requestor B32;
	    Atom selection B32, target B32, property B32;
	} selectionRequest;
	struct {
            CARD32 pad00 B32;
            Time time B32;   
	    Window requestor B32;
	    Atom selection B32, target B32, property B32;
	} selectionNotify;
	struct {
            CARD32 pad00 B32;
	    Window window B32;
	    Colormap colormap B32;
#if defined(__cplusplus) || defined(c_plusplus)
	    BOOL c_new;
#else
	    BOOL new;
#endif
	    BYTE state;			/* Installed or UnInstalled */
	    BYTE pad1, pad2;
	} colormap;
	struct {
	    CARD32 pad00 B32;
	    CARD8 request;
	    KeyCode firstKeyCode;
	    CARD8 count;
	    BYTE pad1;
	} mappingNotify;
	struct {
            CARD32 pad00 B32;
	    Window window B32;
	    union {
		struct {
		    Atom type B32;
		    INT32 longs0 B32;
		    INT32 longs1 B32;
		    INT32 longs2 B32;
		    INT32 longs3 B32;
		    INT32 longs4 B32;
		} l;
		struct {
		    Atom type B32;
		    INT16 shorts0 B16;
		    INT16 shorts1 B16;
		    INT16 shorts2 B16;
		    INT16 shorts3 B16;
		    INT16 shorts4 B16;
		    INT16 shorts5 B16;
		    INT16 shorts6 B16;
		    INT16 shorts7 B16;
		    INT16 shorts8 B16;
		    INT16 shorts9 B16;
		} s;
		struct {
		    Atom type B32;
		    INT8 bytes[20];
		} b;
	    } u; 
	} clientMessage;
    } u;
} xEvent;
