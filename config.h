/* See LICENSE file for copyright and license details. */
 
 /* appearance */
 static const unsigned int borderpx  = 1;        /* border pixel of windows */
 static const unsigned int snap      = 32;       /* snap pixel */
 static const int showbar            = 1;        /* 0 means no bar */
 static const int topbar             = 1;        /* 0 means bottom bar */
 static const char *fonts[]          = { "Terminus:size=12" };
 static const char dmenufont[]       = "Terminus:size=12";
 static const char col_gray1[]       = "#DDDDDD";
 static const char col_gray2[]       = "#BBBBBB";
 static const char col_gray3[]       = "#444444";
 static const char col_gray4[]       = "#111111";
 static const char col_cyan[]        = "#FFAA88";
 
 
 static const char nfg[]        = "#90D090";
 static const char nbg[]        = "#FFFFFF";
 static const char nbor[]        = "#FFFFFF";
 
 static const char sfg[]        = "#000000";
 static const char sbg[]        = "#A0D0A0";
 static const char sbor[]        = "#D9D9D9";
 static const char h[]           = "#ffffff"; // v kvadratnem stilu edina barva?
 static const char z[]           = "#000000"; // v kvadratnem stilu edina barva?
 static const char *colors[][3]      = {
 	/*               fg         bg         border   */
/* 	[SchemeNorm] = { nfg, nbg, nbor },
 	[SchemeSel]  = { sfg, sbg, sbor },
*/
/*
 	[SchemeNorm] = { col_gray3, col_gray4, col_gray1 },
 	[SchemeSel]  = { col_gray4, col_gray3, col_cyan },
*/
// gothic
// 	[SchemeNorm] = { "#3f303f", "#000000", "#000000"},
// 	[SchemeSel] =  { "#3f3f3f", "#2d1f2d", "#4f3f4f"},


 	[SchemeNorm] = { h, z, z},
 	[SchemeSel] =  { z, h, h},
 };
 
 /* tagging */
 //static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
 static const char *tags[] = { "I", "II", "III", "IV", "V", "VI", "VII", "IIX", "IX" };
 
 static const Rule rules[] = {
 	/* xprop(1):
 	 *	WM_CLASS(STRING) = instance, class
 	 *	WM_NAME(STRING) = title
 	 */
 	/* class      instance    title       tags mask     isfloating   monitor */
 	{ "Gimp",     NULL,       NULL,       0,            0,           -1 },
 	{ "Firefox",  NULL,       NULL,       0,       0,           -1 },
 /*	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 }, */
 };
 
 /* layout(s) */
 static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
 static const int nmaster     = 1;    /* number of clients in master area */
 static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
 static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */
 
 static const Layout layouts[] = {
 	/* symbol     arrange function */
 	{ "[]=",      tile },    /* first entry is default */
 	{ "><>",      NULL },    /* no layout function means floating behavior */
 	{ "[M]",      monocle },
 };
 
 /* key definitions */
 #define MODKEY Mod4Mask
 #define TAGKEYS(KEY,TAG) \
 	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
 	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
 	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
 	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
 
 /* helper for spawning shell commands in the pre dwm-5.0 fashion */
 #define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
 
 /* commands */
 static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
 static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
	/* MQTT */	
 static const char *zaluzijecmd[] = { "/usr/local/sbin/dm.sh","percent", NULL };
 static const char *luccmd[] = { "/usr/local/sbin/switch.py","luc", NULL };
 static const char *searchcmd[] = { "/usr/local/sbin/search.sh", NULL };

 static const char *termcmd[]  = { "st", NULL };
 
 static const Key keys[] = {
 	/* modifier                     key        function        argument */
 	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
 	{ MODKEY|ShiftMask,             XK_p,      spawn,          {.v = zaluzijecmd} },
 	{ MODKEY,             		XK_g,      spawn,          {.v = searchcmd} },
 	{ MODKEY,      		        XK_Return, spawn,          {.v = termcmd } },
 	{ MODKEY|ShiftMask,             XK_b,      togglebar,      {0} },
 	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
 	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
 	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
 	{ MODKEY|ShiftMask,             XK_i,      spawn,     {.v = luccmd } },
 	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
 	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
 	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
 	{ MODKEY|ShiftMask,                       XK_Return, zoom,           {0} },
	{ MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },
 	{ MODKEY,                       XK_Tab,    view,           {0} },
 	{ MODKEY|ShiftMask,             XK_q,      killclient,     {0} },
 	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
 	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
 	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
 	{ MODKEY,                       XK_space,  setlayout,      {0} },
 	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
 	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
 	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
 	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
 	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
 	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
 	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
 	TAGKEYS(                        XK_1,                      0)
 	TAGKEYS(                        XK_2,                      1)
 	TAGKEYS(                        XK_3,                      2)
 	TAGKEYS(                        XK_4,                      3)
 	TAGKEYS(                        XK_5,                      4)
 	TAGKEYS(                        XK_6,                      5)
 	TAGKEYS(                        XK_7,                      6)
 	TAGKEYS(                        XK_8,                      7)
 	TAGKEYS(                        XK_9,                      8)
 	{ MODKEY|ShiftMask,             XK_c,      quit,           {0} },
 };
 
 /* button definitions */
 /* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
 static const Button buttons[] = {
 	/* click                event mask      button          function        argument */
 	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
 	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
 	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
 	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
 	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
 	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
 	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
 	{ ClkTagBar,            0,              Button1,        view,           {0} },
 	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
 	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
 	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
 };
 
