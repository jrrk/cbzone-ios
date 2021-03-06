/*
 * c_externs.h
 *  -- Todd W Mummert, December 1990, CMU
 *
 * Mostly a garbage file.  If all the world would get
 * ANSI compilers, this file could actually be useful
 * as we could then do argument checking.  Actually, I should
 * #ifdef the arguments, but haven't gotten around to it yet.
 */

#ifndef FunctionPrototypes
#define FunctionPrototypes 1
#endif

#ifdef __cplusplus
extern "C" {
#endif

    void fcoord(float x0, float y0, float x1, float y1);
    void fline(float x0, float y0, float x1, float y1);

/* now some externs from c_gpr.c */
extern Bool gprcondeventwait(
#if FunctionPrototypes
        char* /* key */,
        Position_t* /* posn */
#endif
);
extern void bitblt(
#if FunctionPrototypes
        Window_t* /* window */
#endif
);
extern void clearentirescreen(
#if FunctionPrototypes
                              void
#endif
);
extern void clearrectangle(
#if FunctionPrototypes
        Window_t* /* window */,
        Position_t* /* dsto */
#endif
);
extern void drawrectangle(
#if FunctionPrototypes
        int /* x */,
        int /* y */,
        int /* width */,
        int /* height */
#endif
);
extern void flushwindow(
#if FunctionPrototypes
                        void
#endif
);
extern void gprcircle(
#if FunctionPrototypes
        Position_t* /* center */,
        int /* radius */
#endif
);
extern void gprcirclefilled(
#if FunctionPrototypes
        Position_t* /* center */,
        int /* radius */
#endif
);
extern void gprinqconfig(
#if FunctionPrototypes
        int* /* argc */,
        const char* const* /* argv */
#endif
);
extern void gprinqcursor(
#if FunctionPrototypes
        Position_t* /* posn */
#endif
);
extern Font gprloadfontfile(
#if FunctionPrototypes
        char* /* name */
#endif
);
extern void gprsetclippingactive(
#if FunctionPrototypes
        Bool /* flag */
#endif
);
extern void gprsetclipwindow(
#if FunctionPrototypes
        Window_t* /* window */
#endif
);
extern void gprsetcursorposition(
#if FunctionPrototypes
        Position_t* /* posn */
#endif
);
extern void gprsetdrawvalue(
#if FunctionPrototypes
        int /* index */
#endif
);
extern void gprsettextbackgroundvalue(
#if FunctionPrototypes
        int /* index */
#endif
);
extern void gprsettextfont(
#if FunctionPrototypes
        Font /* font */
#endif
);
extern void gprsettextvalue(
#if FunctionPrototypes
        int /* index */
#endif
);
    extern void multiline(
#if FunctionPrototypes
                          XSegment* /* segments */,
                          int /* number */
#endif
                          );
    extern void multiline2(
#if FunctionPrototypes
                          XSegment* /* segments */,
                          int /* number */
#endif
                          );
extern void polyline(
#if FunctionPrototypes
        XPoint* /* points */,
        int /* number */
#endif
);
extern void printstring(
#if FunctionPrototypes
        int /* x */,
        int /* y */,
        char* /* string */,
        int /* nchars */,
        float /* scale */
#endif
);
extern void putpixmap(
#if FunctionPrototypes
        int /* i */,
        int* /* p */
#endif
);
extern void removepixmap(
#if FunctionPrototypes
        int /* i */,
        int* /* p */
#endif
);
extern void timeclock(
#if FunctionPrototypes
        struct timeval* /* tval */
#endif
);
extern void tonetime(
#if FunctionPrototypes
                     void
#endif
);
extern void waitforkey(
#if FunctionPrototypes
        char /* c */
#endif
);

/* now some externs from c_graphics.c */
extern void clearscreen(
#if FunctionPrototypes
                        void
#endif
);
extern void drawcracks(
#if FunctionPrototypes
                       void
#endif
);
extern void drawhorizon(
#if FunctionPrototypes
        float /* azm */
#endif
);
extern void joystick(
#if FunctionPrototypes
        int* /* position */,
        Bool /* sens */,
        Genericp /* pl */
#endif
);
extern void message(
#if FunctionPrototypes
        int /* number */,
        Bool /* bell */
#endif
);
extern void scanner(
#if FunctionPrototypes
        Genericp /* o */
#endif
);
extern void screeninit(
#if FunctionPrototypes
                       void
#endif
);
extern void staticscreen(
#if FunctionPrototypes
                         void
#endif
);
extern void updatedisplay(
#if FunctionPrototypes
        Bool /* missile */,
        Bool /* lander */,
	long /* score */,
        int /* numleft */,
        Bool /* sens */,
        Bool /* reset */
#endif
);
extern void xhairs(
#if FunctionPrototypes
        Bool /* aligned */
#endif
);

/* now some externs from c_explode.c */
extern void explodeobject(
#if FunctionPrototypes
                          Genericp, Genericp
#endif
);
extern void explodesalvo(
#if FunctionPrototypes
        Genericp /* g */,
        Genericp /* pl */
#endif
);

/* now some externs from c_move.c */
extern void movecopter(
#if FunctionPrototypes
        Genericp /* g */,
        Genericp /* pl */
#endif
);
extern void movelander(
#if FunctionPrototypes
        Genericp /* g */,
        Genericp /* pl */
#endif
);
extern void movemissile(
#if FunctionPrototypes
        Genericp /* g */,
        Genericp /* pl */,
        Bool
#endif
);
extern void movesuper(
#if FunctionPrototypes
        Genericp /* g */,
        Genericp /* pl */
#endif
);
extern void movetank(
#if FunctionPrototypes
        Genericp /* g */,
        Genericp /* pl */
#endif
);
extern void placeobjects(
#if FunctionPrototypes
        Genericp /* o */,
        Bool /* missilerun */,
	long /* score */
#endif
);

/* now some externs from c_draw.c */
extern void drawobject(
#if FunctionPrototypes
        Genericp /* g */,
        Genericp /* pl */
#endif
);
extern void displayobject(
#if FunctionPrototypes
        DCp /* dc */
#endif
);

/* now some externs from c_scores.c */
extern long scores(
#if FunctionPrototypes
	long /* score */
#endif
);

/* now some externs from c_parseopts.c */
extern void parseopt(
#if FunctionPrototypes
        int /* argc */,
        char** /* argv */,
        Bool /* status */
#endif
);

/* let everybody know the options exist */
extern Optionp opt;

/* also need to know if the player is paused */
extern Bool paused;
    
#ifdef __cplusplus
};
#endif

