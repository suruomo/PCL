#ifndef appforms_include
#define appforms_include
#include "uiforms.p"


/*
 *   SPACING
 *
 *
 *   Spacing should be done relative to the active font height in system.
 *   A "single_space" is simply one font height.  The "inter_widget_space"
 *   should be used as the spacing between widgets in a frame.  It is
 *   three quarters of a font height.
 *
 *
 *   Spacing variables:
 * 
 *   INTER_WIDGET_SPACE        - 3/4 of a font height
 *   INTER_GROUP_SPACE         - Twice the size of a "inter_widget_space"
 *
 *   SINGLE_SPACE              - A font height in inches
 *   QTR_SPACE                 - 1/4 of a font height
 *   HALF_SPACE                - 1/2 of a font height
 *   THREE_QTR_SPACE           - 3/4 of a font height
 *   ONE_AND_HALF_SPACE        - 1.5 times a font height
 *   DOUBLE_SPACE              - 2.0 times a font height
 *
 *   FONT_HGT                  - Font height in inches
 *   TEXT_FONT_HGT             - Text font height in inches
 *   SS_FONT_HGT               - Spreadsheet font height in inches
 *
 *   LINE_THICKNESS            - Thickness of a separator
 *   FRAME_1EDGE               - Thickness of a frame edge
 *   FRAME_2EDGE               - Thickness of both frame edges
 *   SFRAME_1EDGE              - Thickness of a select frame edge
 *   SFRAME_2EDGE              - Thickness of both select frame edges
 *   SCROLL_FRAME_1EDGE        - Thickness of a scroll frame edge
 *   SCROLL_FRAME_2EDGE        - Thickness of both scroll frame edges
 *   SPREADSHEET_1EDGE         - Thickness of a spreadsheet edge
 *   SPREADSHEET_2EDGE         - Thickness of both spreadsheet edges
 *   HIGHLITE_1EDGE            - Thickness of a highlight border around widgets
 *   HIGHLITE_2EDGE            - Thickness of both highlight borders
 *
 *   ICON_HGT                  - Height of an icon
 *
 *   LOGO_ICON_WID             - Width of a logo icon
 *   LOGO_ICON_HGT             - Height of a logo icon
 *
 *   BUTTON_ICON_1EDGE         - Thickness of a button icon border  
 *   BUTTON_ICON_2EDGE         - Thickness of a both button icon borders
 *   LABEL_ICON_1EDGE          - Thickness of a label icon border 
 *   LABEL_ICON_2EDGE          - Thickness of a both label icon borders 
 *   ITEM_ICON_1EDGE           - Thickness of a item icon border 
 *   ITEM_ICON_2EDGE           - Thickness of a both item icon borders
 *   TOGGLE_ICON_1EDGE         - Thickness of a toggle icon border 
 *   TOGGLE_ICON_2EDGE         - Thickness of a both toggle icon borders
 *
 *   COLOR_MENU_WID             - Width of a color menu
 *   COLOR_MENU_HGT             - Height of a color menu
 *   COLOR_MENU_LABEL_Y_OFFSET  - Y offset for centering a label next to
 *                               a color menu
 *   COLOR_MENU_TOGGLE_Y_OFFSET - Y offset for centering a toggle next to
 *                               a color menu
 *
 *   COLOR_BOX_WID             - Width of a color box
 *   COLOR_BOX_HGT             - Height of a color box
 *   COLOR_BOX_LABEL_Y_OFFSET  - Y offset for centering a label next to
 *                               a color box
 *   COLOR_BOX_TOGGLE_Y_OFFSET - Y offset for centering a toggle next to
 *                               a color box
 *   COLOR_BAR_WID             - Width of a color bar
 *
 *   INCREMENTAL_ICON_WID      - Width of an incremental button icon
 *   INCREMENTAL_ICON_HGT      - Height of an incremental button icon 
 *
 */

#define INTER_WIDGET_SPACE uil_form_sizes.spacing( 8 )
#define INTER_GROUP_SPACE uil_form_sizes.spacing( 22 )

#define SINGLE_SPACE uil_form_sizes.spacing( 5 )
#define QTR_SPACE uil_form_sizes.spacing( 2 )
#define HALF_SPACE uil_form_sizes.spacing( 3 )
#define THREE_QTR_SPACE uil_form_sizes.spacing( 4 )
#define ONE_AND_HALF_SPACE uil_form_sizes.spacing( 6 )
#define DOUBLE_SPACE uil_form_sizes.spacing( 7 )

#define FONT_HGT uil_form_sizes.spacing( 1 )
#define TEXT_FONT_HGT uil_form_sizes.spacing( 9 )
#define SS_FONT_HGT uil_form_sizes.spacing( 37 )

#define LINE_THICKNESS uil_form_sizes.spacing( 10 )
#define FRAME_1EDGE uil_form_sizes.spacing( 11 )
#define FRAME_2EDGE uil_form_sizes.spacing( 12 )
#define SFRAME_1EDGE uil_form_sizes.spacing( 13 )
#define SFRAME_2EDGE uil_form_sizes.spacing( 14 )
#define SCROLL_FRAME_1EDGE uil_form_sizes.spacing( 23 )
#define SCROLL_FRAME_2EDGE uil_form_sizes.spacing( 24 )
#define SPREADSHEET_1EDGE uil_form_sizes.spacing( 35 )
#define SPREADSHEET_2EDGE uil_form_sizes.spacing( 36 )
#define HIGHLITE_1EDGE uil_form_sizes.spacing( 29 )
#define HIGHLITE_2EDGE uil_form_sizes.spacing( 30 )

#define BUTTON_ICON_1EDGE uil_form_sizes.spacing( 15 )
#define BUTTON_ICON_2EDGE uil_form_sizes.spacing( 16 )
#define LABEL_ICON_1EDGE uil_form_sizes.spacing( 17 )
#define LABEL_ICON_2EDGE uil_form_sizes.spacing( 18 )
#define ITEM_ICON_1EDGE uil_form_sizes.spacing( 19 )
#define ITEM_ICON_2EDGE uil_form_sizes.spacing( 20 )
#define TOGGLE_ICON_1EDGE uil_form_sizes.spacing( 25 )
#define TOGGLE_ICON_2EDGE uil_form_sizes.spacing( 26 )

#define ICON_HGT uil_form_sizes.spacing( 21 )
#define LOGO_ICON_WID uil_form_sizes.spacing( 27 )
#define LOGO_ICON_HGT uil_form_sizes.spacing( 28 )

#define COLOR_MENU_WID uil_form_sizes.spacing( 31 )
#define COLOR_MENU_HGT uil_form_sizes.spacing( 32 )
#define COLOR_MENU_LABEL_Y_OFFSET uil_form_sizes.spacing( 38 )
#define COLOR_MENU_TOGGLE_Y_OFFSET uil_form_sizes.spacing( 39 )
/*
 * colorbox is obsolete
 */
#define COLOR_BOX_WID uil_form_sizes.spacing( 31 )
#define COLOR_BOX_HGT uil_form_sizes.spacing( 32 )
#define COLOR_BOX_LABEL_Y_OFFSET uil_form_sizes.spacing( 38 )
#define COLOR_BOX_TOGGLE_Y_OFFSET uil_form_sizes.spacing( 39 )
#define COLOR_BAR_WID uil_form_sizes.spacing( 40 )

#define INCREMENTAL_ICON_WID uil_form_sizes.spacing( 31 )
#define INCREMENTAL_ICON_HGT uil_form_sizes.spacing( 32 )

/*
 *   FORMS 
 *
 *
 *   Create an application form.  Note that all forms should use the "UL"
 *   screen position, since the values returned by these variables are 
 *   based on that assumption.
 *
 *      ui_form_create( "", FORM_X_LOC,                      @
 *                          FORM_Y_LOC, "UL",                @
 *                          FORM_WID_SML,                    @
 *                          FORM_HGT_TALL, "Label", "Icon" )
 *   
 *   
 *   Create a medium width form next to an application form, and don't
 *   cover the command window.  Use the "Full" height form.
 *   
 *      ui_form_create( "", FORM_X_LOC_MED_NX2_SML,          @
 *                          FORM_Y_LOC, "UL",                @
 *                          FORM_WID_MED,                    @
 *                          FORM_HGT_FULL, "Label", "Icon" )
 *   
 *   
 *   Create a centered, half height, medium width modal form.
 *   
 *      ui_modalform_create( "", FORM_X_LOC_MED_CEN,         @
 *                               FORM_Y_LOC_HALF_CEN, "UL",  @
 *                               FORM_WID_MED,               @
 *                               FORM_HGT_HALF, "Label" )
 *    
 *   
 *   Form Placement - X Location:
 * 
 *   FORM_X_LOC                 - Normal form X location 
 * 
 *   FORM_X_LOC_SML             - Normal form X location (same as FORM_X_LOC)
 *   FORM_X_LOC_SPL             - Special form X location (width is 1.5
 *                                times a normal or small form)
 *   FORM_X_LOC_MED             - Medium form (medium width) X location 
 *   FORM_X_LOC_LRG             - Large form (large width) X location
 * 
 *   FORM_X_LOC_SML_NX2_SML     - Small form next to a small form
 *   FORM_X_LOC_SPL_NX2_SML     - Special form next to a small form
 *   FORM_X_LOC_MED_NX2_SML     - Medium form next to a small form
 *   FORM_X_LOC_LRG_NX2_SML     - Large form next to a small form
 * 
 *   FORM_X_LOC_SML_NX2_SPL     - Small form next to a special form
 *   FORM_X_LOC_SPL_NX2_SPL     - Special form next to a special form
 *   FORM_X_LOC_MED_NX2_SPL     - Medium form next to a special form
 *   FORM_X_LOC_LRG_NX2_SPL     - Large form next to a special form
 * 
 *   FORM_X_LOC_SML_NX2_MED     - Small form next to a medium form
 *   FORM_X_LOC_SPL_NX2_MED     - Special form next to a medium form
 *   FORM_X_LOC_MED_NX2_MED     - Medium form next to a medium form
 *   FORM_X_LOC_LRG_NX2_MED     - Large form next to a medium form
 * 
 *   FORM_X_LOC_SML_NX2_LRG     - Small form next to a large from
 *   FORM_X_LOC_SPL_NX2_LRG     - Special form next to a large form
 *   FORM_X_LOC_MED_NX2_LRG     - Medium form next to a large form
 *   FORM_X_LOC_LRG_NX2_LRG     - Large form next to a large form
 * 
 *   FORM_X_LOC_2ND_SML_NX2_SML - Small form next to a small form which is 
 *                                next to a small form
 *   FORM_X_LOC_2ND_SPL_NX2_SPL - Special form next to a special form
 *                                which is next to a special form
 *
 *   FORM_X_LOC_SML_NX2_SPL_NX2_SML - Small form next to a special form
 *                                    which is next to a small form
 * 
 *   FORM_X_LOC_SPL_NX2_SPL_NX2_SML - Special form next to a special form
 *                                    which is next to a small form
 * 
 *   FORM_X_LOC_SML_CEN         - Small form centered on screen 
 *   FORM_X_LOC_SPL_CEN         - Special form centered on screen 
 *   FORM_X_LOC_MED_CEN         - Medium form centered on screen 
 *   FORM_X_LOC_LRG_CEN         - Large form centered on screen 
 * 
 *   FORM_X_LOC_SML_CEN_AB_COM  - Small form centered above the command 
 *                                window
 *   FORM_X_LOC_SPL_CEN_AB_COM  - Special form centered above the command 
 *                                window
 *   FORM_X_LOC_MED_CEN_AB_COM  - Medium form centered above the command 
 *                                window
 *   FORM_X_LOC_LRG_CEN_AB_COM  - Large form centered above the command 
 *                                window
 * 
 *   FORM_X_LOC_OFFSET_CASCADE_1   - X offset for cascade position 1
 *   FORM_X_LOC_OFFSET_CASCADE_2   - X offset for cascade position 2
 *   FORM_X_LOC_OFFSET_CASCADE_3   - X offset for cascade position 3
 *   FORM_X_LOC_OFFSET_CASCADE_4   - X offset for cascade position 4
 *   FORM_X_LOC_OFFSET_CASCADE_5   - X offset for cascade position 5
 *
 *
 *   Form Placement - Y Location:
 * 
 *   FORM_Y_LOC                 - Y Location for form under Main Menu
 *
 *   FORM_Y_LOC_HALF_CEN        - 1/2 Height form centered on screen
 *   FORM_Y_LOC_QTR_CEN         - 1/4 Height form centered on screen
 *   FORM_Y_LOC_3_8THS_CEN      - 3/8 Height form centered on screen
 *   FORM_Y_LOC_5_8THS_CEN      - 5/8 Height form centered on screen
 *   FORM_Y_LOC_3_QTRS_CEN      - 3/4 Height form centered on screen
 *
 *   FORM_Y_LOC_OFFSET_CASCADE_1   - Y offset for cascade position 1
 *   FORM_Y_LOC_OFFSET_CASCADE_2   - Y offset for cascade position 2
 *   FORM_Y_LOC_OFFSET_CASCADE_3   - Y offset for cascade position 3
 *   FORM_Y_LOC_OFFSET_CASCADE_4   - Y offset for cascade position 4
 *   FORM_Y_LOC_OFFSET_CASCADE_5   - Y offset for cascade position 5
 * 
 *
 *   Form Widths and Heights:
 *
 *   FORM_WID_SML               - Width of a small form
 *   FORM_WID_SPL               - Width of a "special" form (1.5 times 
 *                                a small form)
 *   FORM_WID_MED               - Width of a medium form (medium size) 
 *   FORM_WID_LRG               - Width of a large form (large size) 
 *  
 *   FORM_HGT_TALL              - Height of a tall form (Main Menu to 
 *                                bottom of screen)
 *   FORM_HGT_FULL              - Height of a full form (Main Menu to
 *                                top of Command Window)
 *   FORM_HGT_HALF              - Half of a full form
 *   FORM_HGT_QTR               - One Quarter of a full form
 *   FORM_HGT_3_8THS            - Three Eighths of a full form
 *   FORM_HGT_5_8THS            - Five Eighths of a full form
 *   FORM_HGT_3_QTRS            - Three Quarters of a full form
 * 
 *
 *   Form Margins:
 *  
 *   FORM_L_MARGIN              - Inside Left Margin for widgets in form
 *   FORM_R_MARGIN              - Inside Right Margin for widgets in form
 *   FORM_T_MARGIN              - Inside Top Margin above first widget
 *   FORM_B_MARGIN              - Inside Bottom Margin below last widget
 *   FORM_B_MARGIN_NO_BUTTON    - Inside Bottom Margin below last widget
 *                                when last widget is not a button
 *   
 *   FORM_2H_MARGIN             - Both horizontal margins
 *   FORM_2V_MARGIN             - Both vertical margins
 *   FORM_2V_MARGIN_NO_BUTTON   - Both vertical margins (when last widget
 *                                is not a button)
 * 
 *
 *   Form Borders (the colored areas outside the form):
 *  
 *   FORM_L_BORDER              - Left Border of the form 
 *   FORM_R_BORDER              - Right Border of the form
 *   FORM_T_BORDER              - Top Border of the form (including the label)
 *   FORM_B_BORDER              - Bottom Border of the form
 *   FORM_T_BORDER_NO_LABEL     - Top Border of the form without a label
 *   
 *   FORM_2H_BORDER             - Both horizontal borders
 *   FORM_2V_BORDER             - Both vertical borders (with label)
 *   FORM_2V_BORDER_NO_LABEL    - Both vertical borders (without label)
 *   
 *   FORM_X_ISFRAME             - Compensation for X location of forms
 *                                if they are 'user placed' rather than
 *                                appforms placed 
 *   FORM_Y_ISFRAME             - Compensation for Y location
 *   FORM_Y_ISFRAME_NO_LABEL    - Compensation for Y location for forms
 *                                with no label
 */

#define FORM_X_LOC uil_form_sizes.form_x_loc( 1 )
#define FORM_X_LOC_SML uil_form_sizes.form_x_loc( 1 )
#define FORM_X_LOC_SPL uil_form_sizes.form_x_loc( 13 )
#define FORM_X_LOC_MED uil_form_sizes.form_x_loc( 2 )
#define FORM_X_LOC_LRG uil_form_sizes.form_x_loc( 3 )

#define FORM_X_LOC_SML_NX2_SML uil_form_sizes.form_x_loc( 4 )
#define FORM_X_LOC_SPL_NX2_SML uil_form_sizes.form_x_loc( 16 )
#define FORM_X_LOC_MED_NX2_SML uil_form_sizes.form_x_loc( 5 )
#define FORM_X_LOC_LRG_NX2_SML uil_form_sizes.form_x_loc( 6 )

#define FORM_X_LOC_SML_NX2_SPL uil_form_sizes.form_x_loc( 25 )
#define FORM_X_LOC_SPL_NX2_SPL uil_form_sizes.form_x_loc( 19 )
#define FORM_X_LOC_MED_NX2_SPL uil_form_sizes.form_x_loc( 26 )
#define FORM_X_LOC_LRG_NX2_SPL uil_form_sizes.form_x_loc( 27 )

#define FORM_X_LOC_SML_NX2_MED uil_form_sizes.form_x_loc( 7 )
#define FORM_X_LOC_SPL_NX2_MED uil_form_sizes.form_x_loc( 17 )
#define FORM_X_LOC_MED_NX2_MED uil_form_sizes.form_x_loc( 8 )
#define FORM_X_LOC_LRG_NX2_MED uil_form_sizes.form_x_loc( 28 )

#define FORM_X_LOC_SML_NX2_LRG uil_form_sizes.form_x_loc( 9 )
#define FORM_X_LOC_SPL_NX2_LRG uil_form_sizes.form_x_loc( 29 )
#define FORM_X_LOC_MED_NX2_LRG uil_form_sizes.form_x_loc( 30 )
#define FORM_X_LOC_LRG_NX2_LRG uil_form_sizes.form_x_loc( 31 )

#define FORM_X_LOC_2ND_SML_NX2_SML uil_form_sizes.form_x_loc( 15 )
#define FORM_X_LOC_2ND_SPL_NX2_SPL uil_form_sizes.form_x_loc( 20 )

#define FORM_X_LOC_SML_NX2_SPL_NX2_SML uil_form_sizes.form_x_loc( 32 )
#define FORM_X_LOC_SPL_NX2_SPL_NX2_SML uil_form_sizes.form_x_loc( 18 )

#define FORM_X_LOC_SML_CEN uil_form_sizes.form_x_loc( 10 )
#define FORM_X_LOC_MED_CEN uil_form_sizes.form_x_loc( 11 )
#define FORM_X_LOC_LRG_CEN uil_form_sizes.form_x_loc( 12 )
#define FORM_X_LOC_SPL_CEN uil_form_sizes.form_x_loc( 14 )

#define FORM_X_LOC_SML_CEN_AB_COM uil_form_sizes.form_x_loc( 21 )
#define FORM_X_LOC_SPL_CEN_AB_COM uil_form_sizes.form_x_loc( 22 )
#define FORM_X_LOC_MED_CEN_AB_COM uil_form_sizes.form_x_loc( 23 )
#define FORM_X_LOC_LRG_CEN_AB_COM uil_form_sizes.form_x_loc( 24 )

#define FORM_X_LOC_OFFSET_CASCADE_1 uil_form_sizes.form_x_cascade( 1 )
#define FORM_X_LOC_OFFSET_CASCADE_2 uil_form_sizes.form_x_cascade( 2 )
#define FORM_X_LOC_OFFSET_CASCADE_3 uil_form_sizes.form_x_cascade( 3 )
#define FORM_X_LOC_OFFSET_CASCADE_4 uil_form_sizes.form_x_cascade( 4 )
#define FORM_X_LOC_OFFSET_CASCADE_5 uil_form_sizes.form_x_cascade( 5 )

#define FORM_Y_LOC uil_form_sizes.form_y_loc( 1 )
#define FORM_Y_LOC_HALF_CEN uil_form_sizes.form_y_loc( 2 )
#define FORM_Y_LOC_3_8THS_CEN uil_form_sizes.form_y_loc( 3 )
#define FORM_Y_LOC_QTR_CEN uil_form_sizes.form_y_loc( 4 )
#define FORM_Y_LOC_3_QTRS_CEN uil_form_sizes.form_y_loc( 5 )
#define FORM_Y_LOC_5_8THS_CEN uil_form_sizes.form_y_loc( 6 )

#define FORM_Y_LOC_OFFSET_CASCADE_1 uil_form_sizes.form_y_cascade( 1 )
#define FORM_Y_LOC_OFFSET_CASCADE_2 uil_form_sizes.form_y_cascade( 2 )
#define FORM_Y_LOC_OFFSET_CASCADE_3 uil_form_sizes.form_y_cascade( 3 )
#define FORM_Y_LOC_OFFSET_CASCADE_4 uil_form_sizes.form_y_cascade( 4 )
#define FORM_Y_LOC_OFFSET_CASCADE_5 uil_form_sizes.form_y_cascade( 5 )

#define FORM_WID_SML uil_form_sizes.form_wid( 1 )
#define FORM_WID_MED uil_form_sizes.form_wid( 2 )
#define FORM_WID_LRG uil_form_sizes.form_wid( 3 )
#define FORM_WID_SPL uil_form_sizes.form_wid( 4 )

#define FORM_HGT_TALL uil_form_sizes.form_hgt( 1 )
#define FORM_HGT_FULL uil_form_sizes.form_hgt( 2 )
#define FORM_HGT_HALF uil_form_sizes.form_hgt( 3 )
#define FORM_HGT_3_8THS uil_form_sizes.form_hgt( 4 )
#define FORM_HGT_QTR uil_form_sizes.form_hgt( 5 )
#define FORM_HGT_3_QTRS uil_form_sizes.form_hgt( 6 )
#define FORM_HGT_5_8THS uil_form_sizes.form_hgt( 7 )

#define FORM_L_MARGIN uil_form_sizes.form_margin( 1 )
#define FORM_R_MARGIN uil_form_sizes.form_margin( 2 )
#define FORM_T_MARGIN uil_form_sizes.form_margin( 3 )
#define FORM_B_MARGIN uil_form_sizes.form_margin( 4 )
#define FORM_B_MARGIN_NO_BUTTON uil_form_sizes.form_margin( 7 )
#define FORM_2H_MARGIN uil_form_sizes.form_margin( 5 )
#define FORM_2V_MARGIN uil_form_sizes.form_margin( 6 )
#define FORM_2V_MARGIN_NO_BUTTON uil_form_sizes.form_margin( 8 )

#define FORM_L_BORDER uil_form_sizes.form_border( 1 )
#define FORM_R_BORDER uil_form_sizes.form_border( 2 )
#define FORM_T_BORDER uil_form_sizes.form_border( 3 )
#define FORM_B_BORDER uil_form_sizes.form_border( 4 )
#define FORM_T_BORDER_NO_LABEL uil_form_sizes.form_border( 5 )
#define FORM_2H_BORDER uil_form_sizes.form_border( 6 )
#define FORM_2V_BORDER uil_form_sizes.form_border( 7 )
#define FORM_2V_BORDER_NO_LABEL uil_form_sizes.form_border( 8 )
#define FORM_X_ISFRAME uil_form_sizes.form_border( 9 )
#define FORM_Y_ISFRAME uil_form_sizes.form_border( 10 )
#define FORM_Y_ISFRAME_NO_LABEL uil_form_sizes.form_border( 11 )


/*
 *   ACTION - OBJECT - METHOD MENUS 
 *
 *
 *   Create the Application Action, Object, Method menus and place the
 *   separator underneath them.
 *
 *                               FORM_WID_MED,               @
 *      ui_optionmenu_create( form_id, "callback",           @
 *                            AOM_MENU_X_LOC,                @
 *                            ACTION_MENU_Y_LOC,             @
 *                            AOM_MENU_LABEL_LEN,            @
 *                            ACTION, FALSE )
 *   
 *      ui_optionmenu_create( form_id, "callback",           @
 *                            AOM_MENU_X_LOC,                @
 *                            OBJECT_MENU_Y_LOC,             @
 *                            AOM_MENU_LABEL_LEN,            @
 *                            OBJECT, FALSE )
 *   
 *      ui_optionmenu_create( form_id, "callback",           @
 *                            AOM_MENU_X_LOC,                @
 *                            METHOD_MENU_Y_LOC,             @
 *                            AOM_MENU_LABEL_LEN,            @
 *                            METHOD, FALSE )
 *   
 *      ui_separator_create ( form_id, "", 0.0,              @
 *                            AOM_SEPARATOR_Y_LOC,           @
 *                            FORM_WID_SML, TRUE )
 *   
 * 
 *   AOM Menu Placement:
 * 
 *   AOM_MENU_X_LOC       - X Location of the AOM menus (margin included)
 *   AOM_MENU_LABEL_LEN   - Label length for AOM menus (language dependent)
 *   ACTION_MENU_Y_LOC    - Y Location for the Action menu (margin included)
 *   OBJECT_MENU_Y_LOC    - Y Location for the Object menu (margin included)
 *   METHOD_MENU_Y_LOC    - Y Location for the Method menu (margin included)
 *   AOM_SEPARATOR_Y_LOC  - Y Location for separator under the AOM menus
 *   APP_FORM_FIRST_Y_LOC - Y Location for the first widget in an 
 *                          application form 
 */

#define AOM_MENU_X_LOC uil_form_sizes.aom_menu( 1 )
#define AOM_MENU_LABEL_LEN uil_form_sizes.aom_menu( 2 )
#define ACTION_MENU_Y_LOC uil_form_sizes.aom_menu( 3 )
#define OBJECT_MENU_Y_LOC uil_form_sizes.aom_menu( 4 )
#define METHOD_MENU_Y_LOC uil_form_sizes.aom_menu( 5 )
#define AOM_SEPARATOR_Y_LOC uil_form_sizes.aom_menu( 6 )
#define APP_FORM_FIRST_Y_LOC uil_form_sizes.aom_menu( 7 )


/*
 *   FRAMES
 *
 *
 *   Create a frame in an application form.  Assume this is the first
 *   widget in the form and that the frame contains a three line listbox
 *   with a label and a databox with a label.  Then locate the Y position
 *   for an unframed databox under the frame.  Note that the frame's label
 *   must be considered in determining the next widget location as does
 *   the thickness of the frame edges.
 *
 *   Since this is an application form, the first Y location is the
 *   variable "app_form_first_y_loc".
 *
 *      y_loc = APP_FORM_FIRST_Y_LOC
 *
 *      height = FRAME_T_MARGIN +                            @
 *               LBOX_3L_HGT_LABOVE +                        @
 *               INTER_WIDGET_SPACE +                        @
 *               DBOX_HGT_LABOVE +                           @
 *               FRAME_B_MARGIN
 *
 *      ui_frame_create ( form_id, "",                       @
 *                        FORM_L_MARGIN,                     @
 *                        y_loc,                             @
 *                        FRAME_WID_SINGLE,                  @
 *                        height, "Label" )
 *
 *      ui_listbox_create ( frame_id, "callback",            @
 *                          FRAME_L_MARGIN,                  @
 *                          FRAME_T_MARGIN,                  @
 *                          LBOX_WID_SINGLE,                 @
 *                          3, "Listbox Label",              @
 *                          selection_type, sort_flag )
 *
 *      y_frame_loc = FRAME_T_MARGIN +                       @
 *                    LBOX_3L_HGT_LABOVE +                   @
 *                    INTER_WIDGET_SPACE
 *
 *      ui_databox_create ( frame_id, "",                    @
 *                          FRAME_L_MARGIN,                  @
 *                          y_frame_loc, 0.0,                @
 *                          DBOX_WID_SINGLE,                 @
 *                          "Databox Label", value,          @
 *                          TRUE, datatype, num_vals )
 *
 *      y_loc = y_loc +                                      @
 *              FRAME_LABEL_HGT +                            @
 *              height +                                     @
 *              FRAME_2EDGE +                                @
 *              INTER_WIDGET_SPACE
 *
 *      ui_databox_create ( frame_id, "",                    @
 *                          UNFRAMED_L_MARGIN,               @
 *                          y_loc, 0.0,                      @
 *                          DBOX_WID_SINGLE,                 @
 *                          "Second Databox Label", value,   @
 *                          TRUE, datatype, num_vals )
 *
 *
 *   Create two single width frames in a medium form that is 
 *   next to a small application form.  These frames will be
 *   at the top of the form.  Their heights are the same as
 *   in the above example.
 *
 *      ui_form_create( "", FORM_X_LOC_MED_NX2_SML,          @
 *                          FORM_Y_LOC, "UL",                @
 *                          FORM_WID_MED,                    @
 *                          FORM_HGT_FULL, "Label", "Icon" )
 *   
 *
 *      ui_frame_create ( form_id, "",                       @
 *                        FRAME_X_LOC_COL1,                  @
 *                        FORM_Y_MARGIN,                     @
 *                        FRAME_WID_SINGLE,                  @
 *                        height, "Left Label" )
 *
 *      ui_frame_create ( form_id, "",                       @
 *                        FRAME_X_LOC_COL2,                  @
 *                        FORM_Y_MARGIN,                     @
 *                        FRAME_WID_SINGLE,                  @
 *                        height, "Right Label" )
 *   
 *
 *   Frame Widths and Heights:
 *
 *   FRAME_WID_SINGLE    - Width of a single width frame   
 *   FRAME_WID_SPECIAL   - Width of a special width frame  
 *   FRAME_WID_DOUBLE    - Width of a double width frame  
 *   FRAME_WID_TRIPLE    - Width of a triple width frame  
 *
 *   FRAME_LABEL_HGT     - Height of the label above a frame
 *   
 *
 *   Frame Margins:
 *
 *   FRAME_L_MARGIN      - Inside left margin for widgets in the frame
 *   FRAME_R_MARGIN      - Inside right margin for widgets in the frame
 *   FRAME_T_MARGIN      - Inside top margin above first widget 
 *   FRAME_B_MARGIN      - Inside bottom margin below last widget 
 *   
 *   FRAME_2H_MARGIN     - Both horizontal margins
 *   FRAME_2V_MARGIN     - Both vertical margins
 *   
 *
 *   Frame Placement:
 *
 *   FRAME_X_LOC_COL1    - X Location for a frame in column 1
 *                         (same as "form_l_margin")
 *   FRAME_X_LOC_COL2    - X Location for a frame in column 2
 *   FRAME_X_LOC_COL3    - X Location for a frame in column 3
 *
 *
 *   Unframed Widget Placement:
 *
 *   UNFRAMED_L_MARGIN   - Left margin for an unframed widget
 *   UNFRAMED_R_MARGIN   - Right margin for an unframed widget
 *                        
 *   UNFRAMED_X_LOC_COL1 - X Location of an unframed widget in column 1
 *   UNFRAMED_X_LOC_COL2 - X Location of an unframed widget in column 2
 *   UNFRAMED_X_LOC_COL3 - X Location of an unframed widget in column 3
 */

#define FRAME_WID_SINGLE uil_form_sizes.frame_wid( 1 )
#define FRAME_WID_DOUBLE uil_form_sizes.frame_wid( 2 )
#define FRAME_WID_TRIPLE uil_form_sizes.frame_wid( 3 )
#define FRAME_WID_SPECIAL uil_form_sizes.frame_wid( 4 )

#define FRAME_LABEL_HGT uil_form_sizes.frame_wid( 5 )

#define FRAME_L_MARGIN uil_form_sizes.frame_margin( 1 )
#define FRAME_R_MARGIN uil_form_sizes.frame_margin( 2 )
#define FRAME_T_MARGIN uil_form_sizes.frame_margin( 3 )
#define FRAME_B_MARGIN uil_form_sizes.frame_margin( 4 )
#define FRAME_2H_MARGIN uil_form_sizes.frame_margin( 8 )
#define FRAME_2V_MARGIN uil_form_sizes.frame_margin( 9 )

#define FRAME_X_LOC_COL1 uil_form_sizes.frame_margin( 5 )
#define FRAME_X_LOC_COL2 uil_form_sizes.frame_margin( 6 )
#define FRAME_X_LOC_COL3 uil_form_sizes.frame_margin( 7 )

#define UNFRAMED_L_MARGIN uil_form_sizes.unframed_margin( 1 )
#define UNFRAMED_R_MARGIN uil_form_sizes.unframed_margin( 2 )

#define UNFRAMED_X_LOC_COL1 uil_form_sizes.unframed_margin( 3 )
#define UNFRAMED_X_LOC_COL2 uil_form_sizes.unframed_margin( 4 )
#define UNFRAMED_X_LOC_COL3 uil_form_sizes.unframed_margin( 5 )


/*
 *   SELECT FRAMES
 *
 *
 *   Create a select frame in an application form.  Put two select databoxes
 *   in the select frame.  Then compute the Y location for the next widget.
 *   Note the use of the supplied Y locations for the select databoxes as 
 *   well as the height of the select frame.
 *
 *      y_loc = APP_FORM_FIRST_Y_LOC
 *
 *      ui_selectframe_create( form_id, "callback",          @
 *                             FORM_L_MARGIN,                @
 *                             y_loc,                        @
 *                             SFRAME_WID_SINGLE,            @
 *                             SFRAME_2SDB_HGT_LABOVE,       @
 *                             "Select Frame Label",         @
 *                             recycle_flag )
 *                               
 *      ui_selectdatabox_create ( sel_frame_id, "",          @
 *                                SFRAME_L_MARGIN,           @
 *                                SDBOX_Y_LOC1, 0.0,         @
 *                                SDBOX_WID_SINGLE,          @
 *                                "Select Databox One",      @
 *                                value, TRUE, datatype,     @
 *                                prompt )
 *
 *      ui_selectdatabox_create ( sel_frame_id, "",          @
 *                                SFRAME_L_MARGIN,           @
 *                                SDBOX_Y_LOC2, 0.0,         @
 *                                SDBOX_WID_SINGLE,          @
 *                                "Select Databox One",      @
 *                                value, TRUE, datatype,     @
 *                                prompt )
 *
 *      y_loc = y_loc + SFRAME_LABEL_HGT +                   @
 *                      SFRAME_2SDB_HGT_LABOVE +             @
 *                      SFRAME_2EDGE +                       @
 *                      INTER_WIDGET_SPACE
 *
 *
 *   Select Frame Widths and Heights:
 *
 *   SFRAME_WID_SINGLE         - Width of a single width select frame
 *   SFRAME_WID_SPECIAL        - Width of a special width select frame
 *   SFRAME_WID_DOUBLE         - Width of a double width select frame
 *   SFRAME_WID_TRIPLE         - Width of a triple width select frame
 *
 *   SFRAME_LABEL_HGT          - Height of the label above a select frame
 *
 *   SFRAME_1SDB_HGT_LABOVE    - Height of a select frame with
 *                               1 select databox with a label
 *   SFRAME_2SDB_HGT_LABOVE    - Height of a select frame with
 *                               2 select databoxes with labels
 *   SFRAME_3SDB_HGT_LABOVE    - Height of a select frame with
 *                               3 select databoxes with labels
 *   SFRAME_4SDB_HGT_LABOVE    - Height of a select frame with
 *                               4 select databoxes with labels
 *   SFRAME_5SDB_HGT_LABOVE    - Height of a select frame with
 *                               5 select databoxes with labels
 *
 *   SFRAME_HGT_LABOVE_INCR    - Increment for making select frames with 
 *                               more than 5 select databoxes with labels
 *
 *   SFRAME_1SDB_HGT_NO_LABOVE - Height of a select frame with
 *                               1 select databox without a label
 *   SFRAME_2SDB_HGT_NO_LABOVE - Height of a select frame with
 *                               2 select databoxes without labels
 *   SFRAME_3SDB_HGT_NO_LABOVE - Height of a select frame with
 *                               3 select databoxes without labels
 *   SFRAME_4SDB_HGT_NO_LABOVE - Height of a select frame with
 *                               4 select databoxes without labels
 *   SFRAME_5SDB_HGT_NO_LABOVE - Height of a select frame with
 *                               5 select databoxes without labels
 *
 *   SFRAME_HGT_NO_LABOVE_INCR - Increment for making select frames with 
 *                               more than 5 select databoxes without labels
 *
 *
 *   Select Frame Margins:
 *
 *   SFRAME_L_MARGIN           - Inside left margin for select databoxes
 *   SFRAME_R_MARGIN           - Inside right margin for select databoxes
 *   SFRAME_T_MARGIN           - Inside top margin for select databoxes
 *   SFRAME_B_MARGIN           - Inside bottom margin for select databoxes
 *   
 *   SFRAME_2H_MARGIN          - Both horizontal margins
 *   SFRAME_2V_MARGIN          - Both vertical margins
 *
 *
 *   Select Frame Placement:
 *
 *   SFRAME_X_LOC_COL1         - X Location for a select frame in column 1
 *                              (same as "form_l_margin")
 *   SFRAME_X_LOC_COL2         - X Location for a select frame in column 2
 *   SFRAME_X_LOC_COL3         - X Location for a select frame in column 3
 */

#define SFRAME_WID_SINGLE uil_form_sizes.selframe_wid( 1 )
#define SFRAME_WID_DOUBLE uil_form_sizes.selframe_wid( 2 )
#define SFRAME_WID_TRIPLE uil_form_sizes.selframe_wid( 3 )
#define SFRAME_WID_SPECIAL uil_form_sizes.selframe_wid( 4 )

#define SFRAME_LABEL_HGT uil_form_sizes.selframe_wid( 5 )

#define SFRAME_1SDB_HGT_LABOVE uil_form_sizes.selframe_hgt( 1, 1 )
#define SFRAME_2SDB_HGT_LABOVE uil_form_sizes.selframe_hgt( 2, 1 )
#define SFRAME_3SDB_HGT_LABOVE uil_form_sizes.selframe_hgt( 3, 1 )
#define SFRAME_4SDB_HGT_LABOVE uil_form_sizes.selframe_hgt( 4, 1 )
#define SFRAME_5SDB_HGT_LABOVE uil_form_sizes.selframe_hgt( 5, 1 )
#define SFRAME_HGT_LABOVE_INCR uil_form_sizes.selframe_hgt( 6, 1 )

#define SFRAME_1SDB_HGT_NO_LABOVE uil_form_sizes.selframe_hgt( 1, 2 )
#define SFRAME_2SDB_HGT_NO_LABOVE uil_form_sizes.selframe_hgt( 2, 2 )
#define SFRAME_3SDB_HGT_NO_LABOVE uil_form_sizes.selframe_hgt( 3, 2 )
#define SFRAME_4SDB_HGT_NO_LABOVE uil_form_sizes.selframe_hgt( 4, 2 )
#define SFRAME_5SDB_HGT_NO_LABOVE uil_form_sizes.selframe_hgt( 5, 2 )
#define SFRAME_HGT_NO_LABOVE_INCR uil_form_sizes.selframe_hgt( 6, 2 )

#define SFRAME_L_MARGIN uil_form_sizes.selframe_margin( 1 )
#define SFRAME_R_MARGIN uil_form_sizes.selframe_margin( 2 )
#define SFRAME_T_MARGIN uil_form_sizes.selframe_margin( 3 )
#define SFRAME_B_MARGIN uil_form_sizes.selframe_margin( 4 )
#define SFRAME_2H_MARGIN uil_form_sizes.selframe_margin( 8 )
#define SFRAME_2V_MARGIN uil_form_sizes.selframe_margin( 9 )

#define SFRAME_X_LOC_COL1 uil_form_sizes.selframe_margin( 5 )
#define SFRAME_X_LOC_COL2 uil_form_sizes.selframe_margin( 6 )
#define SFRAME_X_LOC_COL3 uil_form_sizes.selframe_margin( 7 )



/*
 *   SCROLL_FRAMES
 *
 *
 *   Create a scroll frame in a form.
 *
 *
 *   Scroll Frame Widths and Heights:
 *
 *   SCROLL_FRAME_WID_SINGLE       - Width of a single width scroll frame   
 *   SCROLL_FRAME_WID_SPECIAL      - Width of a special width scroll frame  
 *   SCROLL_FRAME_WID_DOUBLE       - Width of a double width scroll frame  
 *   SCROLL_FRAME_WID_TRIPLE       - Width of a triple width scroll frame  
 *
 *   
 *   SCROLL_FRAME_WORK_WID_SINGLE  - Working width of a single width
 *                                   scroll frame   
 *   SCROLL_FRAME_WORK_WID_SPECIAL - Working width of a special width 
 *                                   scroll frame   
 *   SCROLL_FRAME_WORK_WID_DOUBLE  - Working width of a double width 
 *                                   scroll frame   
 *   SCROLL_FRAME_WORK_WID_TRIPLE  - Working width of a triple width
 *                                   scroll frame   
 *
 *   SCROLL_FRAME_DBOX_WID_SINGLE  - Width of a single width scroll frame   
 *                                   databox
 *   SCROLL_FRAME_DBOX_WID_SPECIAL - Width of a special width scroll frame  
 *                                   databox
 *   SCROLL_FRAME_DBOX_WID_DOUBLE  - Width of a double width scroll frame  
 *                                   databox
 *   SCROLL_FRAME_DBOX_WID_TRIPLE  - Width of a triple width scroll frame  
 *                                   databox
 *
 *   SCROLL_FRAME_LABEL_HGT        - Height of the label above a
 *                                   scroll frame   
 *
 *   SCROLL_FRAME_1DBOX_HGT        - Scroll frame height with 1 databox
 *   SCROLL_FRAME_2DBOX_HGT        - Scroll frame height with 2 databoxes
 *   SCROLL_FRAME_3DBOX_HGT        - Scroll frame height with 3 databoxes
 *   SCROLL_FRAME_4DBOX_HGT        - Scroll frame height with 4 databoxes
 *   SCROLL_FRAME_5DBOX_HGT        - Scroll frame height with 5 databoxes
 *
 *   SCROLL_FRAME_DBOX_HGT_INCR    - Scroll frame height increment
 *
 *   SCROLL_FRAME_1DBOX_WORK_HGT   - Scroll frame work height for 1 databox
 *   SCROLL_FRAME_2DBOX_WORK_HGT   - Scroll frame work height for 2 databoxes
 *   SCROLL_FRAME_3DBOX_WORK_HGT   - Scroll frame work height for 3 databoxes
 *   SCROLL_FRAME_4DBOX_WORK_HGT   - Scroll frame work height for 4 databoxes
 *   SCROLL_FRAME_5DBOX_WORK_HGT   - Scroll frame work height for 5 databoxes
 * 
 *   SCROLL_FRAME_DBOX_WORK_HGT_INCR - Scroll frame working height increment
 *
 *   SCROLL_FRAME_SLIDER_WID       - Width of the slider on the right 
 *                                   of a scroll frame   
 *   SCROLL_FRAME_SLIDER_HGT       - Height of the slider at the bottom 
 *                                   of a scroll frame   
 *   
 *   Frame Margins:
 *
 *   SCROLL_FRAME_L_MARGIN         - Inside left margin for widgets in 
 *                                   a scroll frame
 *   SCROLL_FRAME_R_MARGIN         - Inside right margin for widgets in 
 *                                   a scroll frame
 *   SCROLL_FRAME_T_MARGIN         - Inside top margin above first widget 
 *   SCROLL_FRAME_B_MARGIN         - Inside bottom margin below last widget 
 *   
 *   SCROLL_FRAME_2H_MARGIN        - Both horizontal margins
 *   SCROLL_FRAME_2V_MARGIN        - Both vertical margins
 */

#define SCROLL_FRAME_WID_SINGLE uil_form_sizes.scroll_frame_wid( 1 )
#define SCROLL_FRAME_WID_DOUBLE uil_form_sizes.scroll_frame_wid( 2 )
#define SCROLL_FRAME_WID_TRIPLE uil_form_sizes.scroll_frame_wid( 3 )
#define SCROLL_FRAME_WID_SPECIAL uil_form_sizes.scroll_frame_wid( 4 )

#define SCROLL_FRAME_WORK_WID_SINGLE uil_form_sizes.scroll_frame_wid( 5 )
#define SCROLL_FRAME_WORK_WID_DOUBLE uil_form_sizes.scroll_frame_wid( 6 )
#define SCROLL_FRAME_WORK_WID_TRIPLE uil_form_sizes.scroll_frame_wid( 7 )
#define SCROLL_FRAME_WORK_WID_SPECIAL uil_form_sizes.scroll_frame_wid( 8 )

#define SCROLL_FRAME_DBOX_WID_SINGLE uil_form_sizes.scroll_frame_wid( 9 )
#define SCROLL_FRAME_DBOX_WID_DOUBLE uil_form_sizes.scroll_frame_wid( 10 )
#define SCROLL_FRAME_DBOX_WID_TRIPLE uil_form_sizes.scroll_frame_wid( 11 )
#define SCROLL_FRAME_DBOX_WID_SPECIAL uil_form_sizes.scroll_frame_wid( 12 )

#define SCROLL_FRAME_SLIDER_WID uil_form_sizes.scroll_frame_wid( 13 )
#define SCROLL_FRAME_SLIDER_HGT uil_form_sizes.scroll_frame_hgt( 14 )

#define SCROLL_FRAME_LABEL_HGT uil_form_sizes.scroll_frame_hgt( 1 )

#define SCROLL_FRAME_1DBOX_HGT uil_form_sizes.scroll_frame_hgt( 2 )
#define SCROLL_FRAME_2DBOX_HGT uil_form_sizes.scroll_frame_hgt( 3 )
#define SCROLL_FRAME_3DBOX_HGT uil_form_sizes.scroll_frame_hgt( 4 )
#define SCROLL_FRAME_4DBOX_HGT uil_form_sizes.scroll_frame_hgt( 5 )
#define SCROLL_FRAME_5DBOX_HGT uil_form_sizes.scroll_frame_hgt( 6 )

#define SCROLL_FRAME_DBOX_HGT_INCR uil_form_sizes.scroll_frame_hgt( 7 )

#define SCROLL_FRAME_1DBOX_WORK_HGT uil_form_sizes.scroll_frame_hgt( 8 )
#define SCROLL_FRAME_2DBOX_WORK_HGT uil_form_sizes.scroll_frame_hgt( 9 )
#define SCROLL_FRAME_3DBOX_WORK_HGT uil_form_sizes.scroll_frame_hgt( 10 )
#define SCROLL_FRAME_4DBOX_WORK_HGT uil_form_sizes.scroll_frame_hgt( 11 )
#define SCROLL_FRAME_5DBOX_WORK_HGT uil_form_sizes.scroll_frame_hgt( 12 )

#define SCROLL_FRAME_DBOX_WORK_HGT_INCR uil_form_sizes.scroll_frame_hgt( 13 )

#define SCROLL_FRAME_L_MARGIN uil_form_sizes.scroll_frame_margin( 1 )
#define SCROLL_FRAME_R_MARGIN uil_form_sizes.scroll_frame_margin( 2 )
#define SCROLL_FRAME_T_MARGIN uil_form_sizes.scroll_frame_margin( 3 )
#define SCROLL_FRAME_B_MARGIN uil_form_sizes.scroll_frame_margin( 4 )
#define SCROLL_FRAME_2H_MARGIN uil_form_sizes.scroll_frame_margin( 5 )
#define SCROLL_FRAME_2V_MARGIN uil_form_sizes.scroll_frame_margin( 6 )



/*
 *   BUTTONS
 *
 *
 *   Create two buttons in a small form.  The button on the left is a
 *   default button.  Use "half" size buttons.
 *
 *      ui_button_create ( form_id, "callback",              @
 *                         BUTTON_HALF_X_LOC1,               @
 *                         y_loc,                            @
 *                         BUTTON_WID_HALF,                  @
 *                         0.0, "Left Button",               @
 *                         TRUE, TRUE ) 
 *
 *      y_loc = y_loc + BUTTON_Y_OFFSET
 *
 *      ui_button_create ( form_id, "callback",              @
 *                         BUTTON_HALF_X_LOC2,               @
 *                         y_loc,                            @
 *                         BUTTON_WID_HALF,                  @
 *                         0.0, "Right Button",              @
 *                         TRUE, FALSE ) 
 *
 *      y_loc = y_loc + BUTTON_Y_OFFSET +                    @
 *                      BUTTON_HGT +                         @
 *                      INTER_WIDGET_SPACE
 *
 *
 *   Button Widths and Heights:
 *
 *   BUTTON_WID_FULL               - Width of a wide button on a small form
 *   BUTTON_WID_HALF               - Width of a medium button on a small form
 *   BUTTON_WID_THIRD              - Width of a small button on a small form
 *
 *   BUTTON_WID_FULL_NT            - Width of a non_troughed wide button on
 *                                   a small form
 *   BUTTON_WID_HALF_NT            - Width of a non_troughed medium button on
 *                                   a small form
 *   BUTTON_WID_THIRD_NT           - Width of a non_troughed small button on
 *                                   a small form
 *
 *   BUTTON_HGT                    - Button height
 *   BUTTON_DEFAULT_HGT            - Default button height (includes top and
 *                                   bottom borders)
 *   BUTTON_HGT_NT                 - Button height of non_troughed button
 *
 *   BUTTON_DEFAULT_BORDER_WID     - Default button border width
 *   BUTTON_DEFAULT_BORDER_HGT     - Default button border height
 *
 *
 *   Button Location Offsets:
 *
 *   BUTTON_IN_FRAME_X_OFFSET      - X offset for placing buttons inside
 *                                   frames using the X Positions defined
 *                                   below
 *
 *   BUTTON_1XTRA_WID              - X width for one trough for user placement
 *                                   of troughed buttons.
 *   BUTTON_2XTRA_WID              - X width for two troughs for user placement
 *                                   of troughed buttons.
 *
 *   BUTTON_Y_OFFSET               - Y offset for placing a non-highlighted 
 *                                   button next to a highlighted button
 *   BUTTON_Y_OFFSET_NT            - Y offset for placing a non-highlighted 
 *                                   button next to a highlighted button
 *
 *   BUTTON_LABEL_Y_OFFSET         - Y offset for placing a label to the right
 *                                   of a button
 *   BUTTON_DEFAULT_LABEL_Y_OFFSET - Y offset for placing a label to the right 
 *                                   of a default button
 *   BUTTON_LABEL_Y_OFFSET_NT      - Y offset for placing a label to the right
 *                                   of a non_troughed button
 *
 *
 *   Button X Positions:
 *
 *   BUTTON_FULL_X_LOC1            - Wide button on the left
 *   BUTTON_HALF_X_LOC1            - Medium button on the left
 *   BUTTON_HALF_X_LOC2            - Medium button on the right
 *   BUTTON_THIRD_X_LOC1           - Small button on the left
 *   BUTTON_THIRD_X_LOC2           - Small button centered
 *   BUTTON_THIRD_X_LOC3           - Small button on the right
 *
 *   BUTTON_FULL_X_LOC1_COL2       - Wide button on the left of column 2
 *   BUTTON_HALF_X_LOC1_COL2       - Medium button on the left of column 2
 *   BUTTON_HALF_X_LOC2_COL2       - Medium button on the right of column 2
 *   BUTTON_THIRD_X_LOC1_COL2      - Small button on the left of column 2
 *   BUTTON_THIRD_X_LOC2_COL2      - Small button centered of column 2
 *   BUTTON_THIRD_X_LOC3_COL2      - Small button on the right of column 2
 *
 *   BUTTON_FULL_X_LOC1_COL3       - Wide button on the left of column 3
 *   BUTTON_HALF_X_LOC1_COL3       - Medium button on the left of column 3
 *   BUTTON_HALF_X_LOC2_COL3       - Medium button on the right of column 3
 *   BUTTON_THIRD_X_LOC1_COL3      - Small button on the left of column 3
 *   BUTTON_THIRD_X_LOC2_COL3      - Small button centered of column 3
 *   BUTTON_THIRD_X_LOC3_COL3      - Small button on the right of column 3
 *
 *   BUTTON_FULL_X_LOC1_SPL        - Wide button centered on a special form
 *   BUTTON_HALF_X_LOC1_SPL        - Medium button on the left of a special form
 *   BUTTON_HALF_X_LOC2_SPL        - Medium button on the right of a special form
 *   BUTTON_THIRD_X_LOC1_SPL       - Small button on the left of a special form
 *   BUTTON_THIRD_X_LOC2_SPL       - Small button centered of a special form
 *   BUTTON_THIRD_X_LOC3_SPL       - Small button on the right of a special form
 *
 *   BUTTON_FULL_X_LOC_CEN         - Centered wide button on a small form
 *   BUTTON_HALF_X_LOC_CEN         - Centered medium button on a small form
 *   BUTTON_THIRD_X_LOC_CEN        - Centered small button on a small form
 *
 *   BUTTON_FULL_X_LOC_CEN_MED     - Centered wide button on a medium form 
 *   BUTTON_HALF_X_LOC_CEN_MED     - Centered medium button on a medium form 
 *   BUTTON_THIRD_X_LOC_CEN_MED    - Centered small button on a medium form 
 *
 *   BUTTON_FULL_X_LOC_CEN_LRG     - Centered wide button on a large form 
 *   BUTTON_HALF_X_LOC_CEN_LRG     - Centered medium button on a large form 
 *   BUTTON_THIRD_X_LOC_CEN_LRG    - Centered small button on a large form 
 *
 *   BUTTON_FULL_X_LOC_CEN_SPL     - Centered wide button on a special form 
 *   BUTTON_HALF_X_LOC_CEN_SPL     - Centered medium button on a special form 
 *   BUTTON_THIRD_X_LOC_CEN_SPL    - Centered small button on a special form 
 */

#define BUTTON_WID_FULL uil_form_sizes.button_wid( 1 )
#define BUTTON_WID_HALF uil_form_sizes.button_wid( 2 )
#define BUTTON_WID_THIRD uil_form_sizes.button_wid( 3 )
#define BUTTON_WID_FULL_NT uil_form_sizes.button_wid( 4 )
#define BUTTON_WID_HALF_NT uil_form_sizes.button_wid( 5 )
#define BUTTON_WID_THIRD_NT uil_form_sizes.button_wid( 6 )

#define BUTTON_HGT uil_form_sizes.button_hgt( 1 )
#define BUTTON_DEFAULT_HGT uil_form_sizes.button_hgt( 2 )
#define BUTTON_DEFAULT_BORDER_WID uil_form_sizes.button_hgt( 3 )
#define BUTTON_DEFAULT_BORDER_HGT uil_form_sizes.button_hgt( 4 )
#define BUTTON_LABEL_Y_OFFSET uil_form_sizes.button_hgt( 5 )
#define BUTTON_DEFAULT_LABEL_Y_OFFSET uil_form_sizes.button_hgt( 6 )
#define BUTTON_HGT_NT uil_form_sizes.button_hgt( 7 )
#define BUTTON_Y_OFFSET uil_form_sizes.button_hgt( 8 )
#define BUTTON_Y_OFFSET_NT uil_form_sizes.button_hgt( 9 )
#define BUTTON_LABEL_Y_OFFSET_NT uil_form_sizes.button_hgt( 10 )
#define BUTTON_IN_FRAME_X_OFFSET uil_form_sizes.button_hgt( 11 )
#define BUTTON_1XTRA_WID uil_form_sizes.button_hgt( 12 )
#define BUTTON_2XTRA_WID uil_form_sizes.button_hgt( 13 )

#define BUTTON_FULL_X_LOC1 uil_form_sizes.button_x_loc1( 1 )

#define BUTTON_HALF_X_LOC1 uil_form_sizes.button_x_loc1( 2 )
#define BUTTON_HALF_X_LOC2 uil_form_sizes.button_x_loc1( 3 )

#define BUTTON_THIRD_X_LOC1 uil_form_sizes.button_x_loc1( 4 )
#define BUTTON_THIRD_X_LOC2 uil_form_sizes.button_x_loc1( 5 )
#define BUTTON_THIRD_X_LOC3 uil_form_sizes.button_x_loc1( 6 )

#define BUTTON_FULL_X_LOC1_COL2 uil_form_sizes.button_x_loc2( 1 )

#define BUTTON_HALF_X_LOC1_COL2 uil_form_sizes.button_x_loc2( 2 )
#define BUTTON_HALF_X_LOC2_COL2 uil_form_sizes.button_x_loc2( 3 )

#define BUTTON_THIRD_X_LOC1_COL2 uil_form_sizes.button_x_loc2( 4 )
#define BUTTON_THIRD_X_LOC2_COL2 uil_form_sizes.button_x_loc2( 5 )
#define BUTTON_THIRD_X_LOC3_COL2 uil_form_sizes.button_x_loc2( 6 )

#define BUTTON_FULL_X_LOC1_COL3 uil_form_sizes.button_x_loc3( 1 )

#define BUTTON_HALF_X_LOC1_COL3 uil_form_sizes.button_x_loc3( 2 )
#define BUTTON_HALF_X_LOC2_COL3 uil_form_sizes.button_x_loc3( 3 )

#define BUTTON_THIRD_X_LOC1_COL3 uil_form_sizes.button_x_loc3( 4 )
#define BUTTON_THIRD_X_LOC2_COL3 uil_form_sizes.button_x_loc3( 5 )
#define BUTTON_THIRD_X_LOC3_COL3 uil_form_sizes.button_x_loc3( 6 )

#define BUTTON_FULL_X_LOC1_SPL uil_form_sizes.button_x_loc4( 1 )

#define BUTTON_HALF_X_LOC1_SPL uil_form_sizes.button_x_loc4( 2 )
#define BUTTON_HALF_X_LOC2_SPL uil_form_sizes.button_x_loc4( 3 )

#define BUTTON_THIRD_X_LOC1_SPL uil_form_sizes.button_x_loc4( 4 )
#define BUTTON_THIRD_X_LOC2_SPL uil_form_sizes.button_x_loc4( 5 )
#define BUTTON_THIRD_X_LOC3_SPL uil_form_sizes.button_x_loc4( 6 )

#define BUTTON_FULL_X_LOC_CEN uil_form_sizes.button_x_cen( 1 )
#define BUTTON_HALF_X_LOC_CEN uil_form_sizes.button_x_cen( 2 )
#define BUTTON_THIRD_X_LOC_CEN uil_form_sizes.button_x_cen( 3 )

#define BUTTON_FULL_X_LOC_CEN_MED uil_form_sizes.button_x_cen( 4 )
#define BUTTON_HALF_X_LOC_CEN_MED uil_form_sizes.button_x_cen( 5 )
#define BUTTON_THIRD_X_LOC_CEN_MED uil_form_sizes.button_x_cen( 6 )

#define BUTTON_FULL_X_LOC_CEN_LRG uil_form_sizes.button_x_cen( 7 )
#define BUTTON_HALF_X_LOC_CEN_LRG uil_form_sizes.button_x_cen( 8 )
#define BUTTON_THIRD_X_LOC_CEN_LRG uil_form_sizes.button_x_cen( 9 )

#define BUTTON_FULL_X_LOC_CEN_SPL uil_form_sizes.button_x_cen( 10 )
#define BUTTON_HALF_X_LOC_CEN_SPL uil_form_sizes.button_x_cen( 11 )
#define BUTTON_THIRD_X_LOC_CEN_SPL uil_form_sizes.button_x_cen( 12 )



/*
 *   DATABOXES
 *
 *
 *   Create a framed databox with a label above the databox.  Then
 *   compute the Y location for the next widget inside the frame.
 *
 *      y_frame_loc = FRAME_T_MARGIN
 *
 *      ui_databox_create ( frame_id, "",                    @
 *                          FRAME_L_MARGIN,                  @
 *                          y_frame_loc, 0.0,                @
 *                          DBOX_WID_SINGLE,                 @
 *                          "Databox Label", value,          @
 *                          TRUE, datatype, num_vals )
 *
 *      y_frame_loc = y_frame_loc +                          @
 *                    DBOX_HGT_LABOVE +                      @
 *                    INTER_WIDGET_SPACE
 *                      
 *
 *   Create a framed databox with a label to the side.  Use the 
 *   default label length for a single column databox and compute
 *   the databox width.
 *
 *      y_frame_loc = FRAME_T_MARGIN
 *
 *      wid = DBOX_WID_SINGLE -                              @
 *            DBOX_LABEL_LEN_SINGLE
 *   
 *   
 *      ui_databox_create ( frame_id, "",                    @
 *                          FRAME_L_MARGIN,                  @
 *                          y_frame_loc,                     @
 *                          DBOX_LABEL_LEN_SINGLE,           @
 *                          wid,                             @
 *                          "Databox Label", value,          @
 *                          FALSE, datatype, num_vals )
 *
 *
 *   Databox Width and Height:
 *
 *   DBOX_WID_SINGLE        - Width of a single width databox   
 *   DBOX_WID_SPECIAL       - Width of a special width databox   
 *   DBOX_WID_DOUBLE        - Width of a double width databox   
 *   DBOX_WID_TRIPLE        - Width of a triple width databox   
 *
 *   DBOX_HGT_LABOVE        - Height of a databox with a label on the top
 *                            (even if the label is blank)
 *   DBOX_HGT_NO_LABOVE     - Height of a databox with a label to the side
 *
 *   DBOX_LABEL_LEN_SINGLE  - Default label length for a single width databox
 *                            (used when "label_above" is false)
 *   DBOX_LABEL_LEN_SPECIAL - Default label length for a special width databox
 *   DBOX_LABEL_LEN_DOUBLE  - Default label length for a double width databox
 *   DBOX_LABEL_LEN_TRIPLE  - Default label length for a triple width databox
 *
 *   DBOX_LABEL_X_OFFSET    - REMOVED
 *   DBOX_LABEL_Y_OFFSET    - Y offset for placing a label to the right of
 *                            a databox with "labelabove" false.
 */

#define DBOX_WID_SINGLE uil_form_sizes.dbox_wid( 1 )
#define DBOX_WID_DOUBLE uil_form_sizes.dbox_wid( 2 )
#define DBOX_WID_TRIPLE uil_form_sizes.dbox_wid( 3 )
#define DBOX_WID_SPECIAL uil_form_sizes.dbox_wid( 4 )

#define DBOX_HGT_LABOVE uil_form_sizes.dbox_hgt( 1 )
#define DBOX_HGT_NO_LABOVE uil_form_sizes.dbox_hgt( 2 )

#define DBOX_LABEL_LEN_SINGLE uil_form_sizes.dbox_data( 1 )
#define DBOX_LABEL_LEN_DOUBLE uil_form_sizes.dbox_data( 2 )
#define DBOX_LABEL_LEN_TRIPLE uil_form_sizes.dbox_data( 3 )
#define DBOX_LABEL_LEN_SPECIAL uil_form_sizes.dbox_data( 4 )

#define DBOX_LABEL_X_OFFSET 0.0
#define DBOX_LABEL_Y_OFFSET uil_form_sizes.dbox_data( 5 )


/*
 *   FILES
 *
 *
 *   Create a form centered under the main menu that has a file
 *   widget inside the a frame.  The file widget is placed at
 *   ( 0.0, 0.0 ) inside the frame (a top margin is not needed).
 *   The height of the file widget includes a bottom margin
 *   and therefore can be used as the height of the frame that
 *   contains the file widget.  The file widget has 5 lines in 
 *   the list boxes.
 *
 *      form_hgt = FILE_5L_HGT + FORM_2V_MARGIN + FRAME_2EDGE
 *      x_loc = WINDOW_CEN_X_LOC - 0.5 * ( wid + FORM_2H_BORDER )
 *      y_loc = WINDOW_CEN_Y_LOC - 0.5 * ( form_hgt + FORM_2V_BORDER )
 *
 *      form_id = ui_form_create( "", x_loc, y_loc, "UL",    @
 *                                wid, form_hgt,             @
 *                                "Form Label", "" )
 *
 *      frame_id = ui_frame_create( form_id, "",             @
 *                                  FORM_L_MARGIN,           @
 *                                  FORM_T_MARGIN,           @
 *                                  FRAME_WID_SPECIAL,       @
 *                                  FILE_5L_HGT, "" )
 *
 *      file_id = ui_file_create( frame_id, "",              @
 *                                0.0, 0.0,                  @
 *                                FILE_WID_SPECIAL, 5,       @
 *                                "Filter Label",            @
 *                                "Filter Mask",             @
 *                                "Files Label",             @
 *                                "Directory Label",         @
 *                                "Files Label",             @
 *                                "Selection Label",         @
 *                                "Default Selection",       @
 *                                "Left Button Label",       @
 *                                "Right Button Label" )
 *
 *
 *   File Width:
 *
 *   FILE_WID_SINGLE     - Width of a single width file widget
 *   FILE_WID_SPECIAL    - Width of a special width file widget
 *   FILE_WID_DOUBLE     - Width of a double width file widget
 *   FILE_WID_TRIPLE     - Width of a triple width file widget
 *
 *   File Height:
 *
 *   FILE_1L_HGT         - Height of a 1 line file widget
 *   FILE_2L_HGT         - Height of a 2 line file widget
 *   FILE_3L_HGT         - Height of a 3 line file widget
 *   FILE_4L_HGT         - Height of a 4 line file widget
 *   FILE_5L_HGT         - Height of a 5 line file widget
 *   FILE_6L_HGT         - Height of a 6 line file widget
 *   FILE_7L_HGT         - Height of a 7 line file widget
 *   FILE_8L_HGT         - Height of a 8 line file widget
 *   FILE_9L_HGT         - Height of a 9 line file widget
 *   FILE_HGT_INCR       - Increment for making bigger file widgets
 */

#define FILE_WID_SINGLE uil_form_sizes.file_wid( 1 )
#define FILE_WID_DOUBLE uil_form_sizes.file_wid( 2 )
#define FILE_WID_TRIPLE uil_form_sizes.file_wid( 3 )
#define FILE_WID_SPECIAL uil_form_sizes.file_wid( 4 )

#define FILE_1L_HGT uil_form_sizes.file_hgt( 1 )
#define FILE_2L_HGT uil_form_sizes.file_hgt( 2 )
#define FILE_3L_HGT uil_form_sizes.file_hgt( 3 )
#define FILE_4L_HGT uil_form_sizes.file_hgt( 4 )
#define FILE_5L_HGT uil_form_sizes.file_hgt( 5 )
#define FILE_6L_HGT uil_form_sizes.file_hgt( 6 )
#define FILE_7L_HGT uil_form_sizes.file_hgt( 7 )
#define FILE_8L_HGT uil_form_sizes.file_hgt( 8 )
#define FILE_9L_HGT uil_form_sizes.file_hgt( 9 )
#define FILE_HGT_INCR uil_form_sizes.file_hgt( 10 )


/*
 *   LABELS and INFO INDENTS
 *
 *
 *   Create a label inside a frame and then compute the y location
 *   of the next widget inside the frame.
 *
 *      y_frame_loc = FRAME_T_MARGIN
 *
 *      ui_label_create ( frame_id, "",                      @
 *                        FRAME_L_MARGIN,                    @
 *                        y_frame_loc,                       @
 *                        "A Label" )
 *
 *      y_frame_loc = y_frame_loc +                          @
 *                    LABEL_HGT +                            @
 *                    INTER_WIDGET_SPACE
 *
 *
 *   Label Height:
 *
 *   LABEL_HGT        - Height of a label
 *   LABEL_Y_OFFSET   - Y offset of label
 *   LABEL_HGT_TIGHT  - Height of a label when showing multiple
 *                      labels
 *
 *   INFO_INDENT      - X location of information label
 *   INFO_INDENT_COL1 - X location of information label in column 1
 *   INFO_INDENT_COL2 - X location of information label in column 2
 *   INFO_INDENT_COL3 - X location of information label in column 3
 */

#define LABEL_HGT uil_form_sizes.toggle_data( 3 )
#define LABEL_Y_OFFSET uil_form_sizes.toggle_data( 4 )
#define LABEL_HGT_TIGHT uil_form_sizes.toggle_data( 5 )

#define INFO_INDENT uil_form_sizes.info_indent(1)
#define INFO_INDENT_COL1 uil_form_sizes.info_indent(1)
#define INFO_INDENT_COL2 uil_form_sizes.info_indent(2)
#define INFO_INDENT_COL3 uil_form_sizes.info_indent(3)


/*
 *   LISTBOXES
 *
 *
 *   Create a framed three line listbox with a label above the listbox.  Note
 *   that the widths and heights include the vertical and horizontal sliders.
 *
 *      y_frame_loc = FRAME_T_MARGIN
 *
 *      ui_listbox_create ( frame_id, "callback",            @
 *                          FRAME_L_MARGIN,                  @
 *                          y_frame_loc,                     @
 *                          LBOX_WID_SINGLE,                 @
 *                          3, "Listbox Label",              @
 *                          selection_type, sort_flag )
 *
 *      y_frame_loc = y_frame_loc +                          @
 *                    LBOX_3L_HGT_LABOVE +                   @
 *                    INTER_WIDGET_SPACE
 *
 *
 *   To determine the height for a six line listbox, add the variable
 *   LBOX_HGT_LABOVE_INCR to LBOX_5L_HGT_LABOVE.
 *
 *
 *   Listbox Width and Height:
 *
 *   LBOX_WID_SINGLE         - Width of a single width listbox   
 *   LBOX_WID_SPECIAL        - Width of a special width listbox   
 *   LBOX_WID_DOUBLE         - Width of a double width listbox   
 *   LBOX_WID_TRIPLE         - Width of a triple width listbox   
 *
 *   LBOX_1L_HGT_LABOVE      - Height of a 1 line listbox with a top label
 *   LBOX_2L_HGT_LABOVE      - Height of a 2 line listbox with a top label
 *   LBOX_3L_HGT_LABOVE      - Height of a 3 line listbox with a top label
 *   LBOX_4L_HGT_LABOVE      - Height of a 4 line listbox with a top label
 *   LBOX_5L_HGT_LABOVE      - Height of a 5 line listbox with a top label
 *   LBOX_8L_HGT_LABOVE      - Height of a 8 line listbox with a top label
 *
 *   LBOX_HGT_LABOVE_INCR    - Increment for computing a listbox height that
 *                             has more than 5 lines in it
 *
 *   LBOX_1L_HGT_NO_LABOVE   - Height of a 1 line listbox with no label
 *                             (label is blank)
 *   LBOX_2L_HGT_NO_LABOVE   - Height of a 2 line listbox with no label
 *   LBOX_3L_HGT_NO_LABOVE   - Height of a 3 line listbox with no label
 *   LBOX_4L_HGT_NO_LABOVE   - Height of a 4 line listbox with no label
 *   LBOX_5L_HGT_NO_LABOVE   - Height of a 5 line listbox with no label
 *   LBOX_8L_HGT_NO_LABOVE   - Height of a 8 line listbox with no label
 *
 *   LBOX_HGT_NO_LABOVE_INCR - Increment for computing a listbox height that
 *                             has more than 5 lines in it
 *
 *   LBOX_SELBTNS_HGT, LBOX_SELBTNS_WID - Height and combined width of
 *                                        (Un)Select All buttons
 */

#define LBOX_WID_SINGLE uil_form_sizes.lbox_wid( 1 )
#define LBOX_WID_DOUBLE uil_form_sizes.lbox_wid( 2 )
#define LBOX_WID_TRIPLE uil_form_sizes.lbox_wid( 3 )
#define LBOX_WID_SPECIAL uil_form_sizes.lbox_wid( 4 )

#define LBOX_1L_HGT_LABOVE uil_form_sizes.lbox_hgt( 1, 1 )
#define LBOX_2L_HGT_LABOVE uil_form_sizes.lbox_hgt( 2, 1 )
#define LBOX_3L_HGT_LABOVE uil_form_sizes.lbox_hgt( 3, 1 )
#define LBOX_4L_HGT_LABOVE uil_form_sizes.lbox_hgt( 4, 1 )
#define LBOX_5L_HGT_LABOVE uil_form_sizes.lbox_hgt( 5, 1 )
#define LBOX_8L_HGT_LABOVE uil_form_sizes.lbox_hgt( 6, 1 )
#define LBOX_HGT_LABOVE_INCR uil_form_sizes.lbox_hgt( 7, 1 )

#define LBOX_1L_HGT_NO_LABOVE uil_form_sizes.lbox_hgt( 1, 2 )
#define LBOX_2L_HGT_NO_LABOVE uil_form_sizes.lbox_hgt( 2, 2 )
#define LBOX_3L_HGT_NO_LABOVE uil_form_sizes.lbox_hgt( 3, 2 )
#define LBOX_4L_HGT_NO_LABOVE uil_form_sizes.lbox_hgt( 4, 2 )
#define LBOX_5L_HGT_NO_LABOVE uil_form_sizes.lbox_hgt( 5, 2 )
#define LBOX_8L_HGT_NO_LABOVE uil_form_sizes.lbox_hgt( 6, 2 )
#define LBOX_HGT_NO_LABOVE_INCR uil_form_sizes.lbox_hgt( 7, 2 )

#define LBOX_SELBTNS_HGT uil_form_sizes.lbox_selbtn_dims( 1 )
#define LBOX_SELBTNS_WID uil_form_sizes.lbox_selbtn_dims( 2 )

/*
 *   OPTION MENUS
 *
 *
 *   Create an option menu with a label to the side.  Then set the 
 *   Y location for the next widget.  Assume this is an unframed widget.
 *
 *      y_loc = APP_FORM_FIRST_Y_LOC
 *   
 *      ui_optionmenu_create( form_id, "callback",           @
 *                            UNFRAMED_L_MARGIN,             @
 *                            y_loc,                         @
 *                            OPT_MENU_LABEL_LEN,            @
 *                            "Label", FALSE )
 *   
 *      y_loc = y_loc + OPT_MENU_HGT_NO_LABOVE +             @
 *                      INTER_WIDGET_SPACE
 *   
 *
 *   Option menu Placement:
 *
 *   OPT_MENU_LABEL_LEN          - Default label length for an option menu
 *                                 with a label to the side
 *
 *   OPT_MENU_HGT_LABOVE         - Height of an option menu with a label
 *                                 on the top
 *   OPT_MENU_HGT_NO_LABOVE      - Height of an option menu with a label
 *                                 on the side
 *
 *   OPT_MENU_Y_OFFSET           - Y offset for placing a label to the
 *                                 right of a select databox with 
 *                                 "labelabove" false
 */

#define OPT_MENU_LABEL_LEN uil_form_sizes.optionmenu_data( 1 )

#define OPT_MENU_HGT_LABOVE uil_form_sizes.optionmenu_data( 2 )
#define OPT_MENU_HGT_NO_LABOVE uil_form_sizes.optionmenu_data( 3 )

#define OPT_MENU_Y_OFFSET uil_form_sizes.optionmenu_data( 4 )


/*
 *   SELECT DATABOXES
 *
 *
 *   Create a framed select databox with a label above the select databox.
 *   Then compute the Y location for the next widget.
 *
 *      y_sframe_loc = SFRAME_T_MARGIN
 *
 *      ui_selectdatabox_create ( sel_frame_id, "",          @
 *                                SFRAME_L_MARGIN,           @
 *                                y_sframe_loc, 0.0,         @
 *                                SDBOX_WID_SINGLE,          @
 *                                "Select Databox Label",    @
 *                                value, TRUE, datatype,     @
 *                                prompt )
 *
 *      y_sframe_loc = y_sframe_loc +                        @
 *                     SDBOX_HGT_LABOVE +                    @
 *                     INTER_WIDGET_SPACE
 *                      
 *
 *   Create a framed select databox with a label to the side.  Use the 
 *   default label length for a single column select databox and compute
 *   the select databox width.
 *
 *      y_sframe_loc = SFRAME_T_MARGIN
 *
 *      wid = SDBOX_WID_SINGLE -                             @
 *            SDBOX_LABEL_LEN_SINGLE
 *   
 *   
 *      ui_selectdatabox_create ( sel_frame_id, "",          @
 *                                SFRAME_L_MARGIN,           @
 *                                y_sframe_loc,              @
 *                                SDBOX_LABEL_LEN_SINGLE,    @
 *                                wid,                       @
 *                                "Select Databox Label",    @
 *                                value, FALSE, datatype,    @
 *                                prompt )
 *
 *      y_sframe_loc = y_sframe_loc +                        @
 *                     SDBOX_HGT_NO_LABOVE +                 @
 *                     INTER_WIDGET_SPACE
 *
 *
 *   Select Databox Width and Height:
 *
 *   SDBOX_WID_SINGLE       - Width of a single width select databox   
 *   SDBOX_WID_SPECIAL      - Width of a special width select databox   
 *   SDBOX_WID_DOUBLE       - Width of a double width select databox   
 *   SDBOX_WID_TRIPLE       - Width of a triple width select databox   
 *
 *   SDBOX_HGT_LABOVE       - Height of a select databox with a top label
 *   SDBOX_HGT_NO_LABOVE    - Height of a select databox with a side label
 *
 *   SDBOX_Y_LOC1_LABOVE    - Y location of select databox 1 in a selectframe
 *                            (select databox has a label above)
 *   SDBOX_Y_LOC2_LABOVE    - Y location of select databox 2 in a selectframe
 *                            (select databox has a label above)
 *   SDBOX_Y_LOC3_LABOVE    - Y location of select databox 3 in a selectframe
 *                            (select databox has a label above)
 *   SDBOX_Y_LOC4_LABOVE    - Y location of select databox 4 in a selectframe
 *                            (select databox has a label above)
 *   SDBOX_Y_LOC5_LABOVE    - Y location of select databox 5 in a selectframe
 *                            (select databox has a label above)
 *
 *   SDBOX_Y_LABOVE_INCR    - Increment for creating the Y location for than
 *                            than 5 select databoxes with labels in a select
 *                            frame
 *
 *   SDBOX_Y_LOC1_NO_LABOVE - Y location of select databox 1 in a selectframe
 *                            (select databox does not have a label above)
 *   SDBOX_Y_LOC2_NO_LABOVE - Y location of select databox 2 in a selectframe
 *                            (select databox does not have a label above)
 *   SDBOX_Y_LOC3_NO_LABOVE - Y location of select databox 3 in a selectframe
 *                            (select databox does not have a label above)
 *   SDBOX_Y_LOC4_NO_LABOVE - Y location of select databox 4 in a selectframe
 *                            (select databox does not have a label above)
 *   SDBOX_Y_LOC5_NO_LABOVE - Y location of select databox 5 in a selectframe
 *                            (select databox does not have a label above)
 *
 *   SDBOX_Y_NO_LABOVE_INCR - Increment for creating the Y location for than
 *                            than 5 select databoxes without labels in a
 *                            select frame
 *
 *   SDBOX_LABEL_LEN_SINGLE - Default label length for a single width select
 *                            databox (used when "label_above" is false)
 *   SDBOX_LABEL_LEN_SPECIAL- Default label length for a special width select
 *                            databox
 *   SDBOX_LABEL_LEN_DOUBLE - Default label length for a double width select
 *                            databox
 *   SDBOX_LABEL_LEN_TRIPLE - Default label length for a triple width select 
 *                            databox
 *
 *   SDBOX_LABEL_X_OFFSET   - REMOVED
 *   SDBOX_LABEL_Y_OFFSET   - Y offset for placing a label to the right
 *                            of a select databox with "labelabove" false.
 */

#define SDBOX_WID_SINGLE uil_form_sizes.sdbox_wid( 1 )
#define SDBOX_WID_DOUBLE uil_form_sizes.sdbox_wid( 2 )
#define SDBOX_WID_TRIPLE uil_form_sizes.sdbox_wid( 3 )
#define SDBOX_WID_SPECIAL uil_form_sizes.sdbox_wid( 4 )

#define SDBOX_HGT_LABOVE uil_form_sizes.sdbox_hgt( 1 )
#define SDBOX_HGT_NO_LABOVE uil_form_sizes.sdbox_hgt( 2 )

#define SDBOX_Y_LOC1_LABOVE uil_form_sizes.sdbox_hgt2( 1, 1 )
#define SDBOX_Y_LOC2_LABOVE uil_form_sizes.sdbox_hgt2( 2, 1 )
#define SDBOX_Y_LOC3_LABOVE uil_form_sizes.sdbox_hgt2( 3, 1 )
#define SDBOX_Y_LOC4_LABOVE uil_form_sizes.sdbox_hgt2( 4, 1 )
#define SDBOX_Y_LOC5_LABOVE uil_form_sizes.sdbox_hgt2( 5, 1 )
#define SDBOX_Y_LABOVE_INCR uil_form_sizes.sdbox_hgt2( 6, 1 )

#define SDBOX_Y_LOC1_NO_LABOVE uil_form_sizes.sdbox_hgt2( 1, 2 )
#define SDBOX_Y_LOC2_NO_LABOVE uil_form_sizes.sdbox_hgt2( 2, 2 )
#define SDBOX_Y_LOC3_NO_LABOVE uil_form_sizes.sdbox_hgt2( 3, 2 )
#define SDBOX_Y_LOC4_NO_LABOVE uil_form_sizes.sdbox_hgt2( 4, 2 )
#define SDBOX_Y_LOC5_NO_LABOVE uil_form_sizes.sdbox_hgt2( 5, 2 )
#define SDBOX_Y_NO_LABOVE_INCR uil_form_sizes.sdbox_hgt2( 6, 2 )

#define SDBOX_LABEL_LEN_SINGLE uil_form_sizes.sdbox_data( 1 )
#define SDBOX_LABEL_LEN_DOUBLE uil_form_sizes.sdbox_data( 2 )
#define SDBOX_LABEL_LEN_TRIPLE uil_form_sizes.sdbox_data( 3 )
#define SDBOX_LABEL_LEN_SPECIAL uil_form_sizes.sdbox_data( 4 )

#define SDBOX_LABEL_X_OFFSET 0.0
#define SDBOX_LABEL_Y_OFFSET uil_form_sizes.sdbox_data( 5 )


/*
 *   SLIDEBARS
 *
 *
 *   Create a slidebar inside a frame and then compute the y location
 *   of the next widget inside the frame.  The slidebar has a label
 *   as well as min/max labels above the displayed values.
 *
 *      y_frame_loc = FRAME_T_MARGIN
 *
 *      ui_slidebar_create ( frame_id, "callback",           @
 *                           FRAME_L_MARGIN,                 @
 *                           y_frame_loc,                    @
 *                           SLIDER_WID_SINGLE,              @
 *                           "Slidebar Label", value,        @
 *                           num_digits, TRUE, "Min", "Max", @
 *                           TRUE, 0, 10 )                   @
 *
 *      y_frame_loc = y_frame_loc +                          @
 *                    SLIDER_HGT_COMPLETE +                  @
 *                    INTER_WIDGET_SPACE
 *
 *
 *   Sliderbar Width and Height:
 *
 *   SLIDER_WID_SINGLE           - Width of a single width slidebar
 *   SLIDER_WID_SPECIAL          - Width of a special width slidebar
 *   SLIDER_WID_DOUBLE           - Width of a double width slidebar
 *   SLIDER_WID_TRIPLE           - Width of a triple width slidebar
 *
 *   SLIDER_HGT_COMPLETE         - Height of slidebar with min/max labels,
 *                                 the values shown and a label below the 
 *                                 slidebar
 *   SLIDER_HGT_MINMAX           - Height of slidebar with min/max labels only
 *   SLIDER_HGT_VALUES           - Height of slidebar with values only
 *   SLIDER_HGT_LABEL            - Height of slidebar with label only (values 
 *                                 not shown and no min/max labels)
 *   SLIDER_HGT_MINMAX_VALUES    - Height of slidebar with min/max labels and
 *                                 values shown (no label)
 *   SLIDER_HGT_MINMAX_LABEL     - Height of slidebar with min/max labels and
 *                                 a label below slidebar (values not shown)
 *   SLIDER_HGT_VALUES_LABEL     - Height of slidebar with values shown and
 *                                 a label below the slidebar (no min/max 
 *                                 labels)
 *   SLIDER_HGT_BAR_ONLY         - Height of just the slidebar
 *
 *   SLIDER_LABEL_Y_LOC_MM_VAL   - Location of label to side of slidebar when
 *                                 the slidebar has both min/max labels and
 *                                 values
 *   SLIDER_LABEL_Y_LOC_MINMAX   - Location of label to side of slidebar when
 *                                 the slidebar has only min/max labels
 *   SLIDER_LABEL_Y_LOC_VALUES   - Location of label to side of slidebar when
 *                                 the slidebar has only values 
 *   SLIDER_LABEL_Y_LOC_BAR_ONLY - Location of label to side of slidebar when
 *                                 the slidebar has neither min/max labels
 *                                 nor values
 */

#define SLIDER_WID_SINGLE uil_form_sizes.slider_wid( 1 )
#define SLIDER_WID_DOUBLE uil_form_sizes.slider_wid( 2 )
#define SLIDER_WID_TRIPLE uil_form_sizes.slider_wid( 3 )
#define SLIDER_WID_SPECIAL uil_form_sizes.slider_wid( 4 )

#define SLIDER_HGT_COMPLETE uil_form_sizes.slider_hgt( 1 )
#define SLIDER_HGT_MINMAX uil_form_sizes.slider_hgt( 2 )
#define SLIDER_HGT_VALUES uil_form_sizes.slider_hgt( 3 )
#define SLIDER_HGT_LABEL uil_form_sizes.slider_hgt( 4 )
#define SLIDER_HGT_MINMAX_VALUES uil_form_sizes.slider_hgt( 5 )
#define SLIDER_HGT_MINMAX_LABEL uil_form_sizes.slider_hgt( 6 )
#define SLIDER_HGT_VALUES_LABEL uil_form_sizes.slider_hgt( 7 )
#define SLIDER_HGT_BAR_ONLY uil_form_sizes.slider_hgt( 8 )

#define SLIDER_LABEL_Y_LOC_MM_VAL uil_form_sizes.slider_data( 1 )
#define SLIDER_LABEL_Y_LOC_MINMAX uil_form_sizes.slider_data( 2 )
#define SLIDER_LABEL_Y_LOC_VALUES uil_form_sizes.slider_data( 3 )
#define SLIDER_LABEL_Y_LOC_BAR_ONLY uil_form_sizes.slider_data( 4 )


/*
 *   SPREADSHEETS
 *
 *
 *   Create a spreadsheet in a form. 
 *
 *
 *   Spreadsheet Widths and Heights:
 *
 *   SPREADSHEET_WID_SINGLE    - Width of a single width select frame
 *   SPREADSHEET_WID_SPECIAL   - Width of a special width select frame
 *   SPREADSHEET_WID_DOUBLE    - Width of a double width select frame
 *   SPREADSHEET_WID_TRIPLE    - Width of a triple width select frame
 *
 *   SPREADSHEET_LABEL_HGT     - Height of the spreadsheet label (to be
 *                               subtracted from the following heights
 *                               in the case that a label is NOT used)
 *
 *   SPREADSHEET_HGT_2D_1ROW   - Height of a 2D spreadsheet with 1 row
 *   SPREADSHEET_HGT_2D_2ROW   - Height of a 2D spreadsheet with 2 rows
 *   SPREADSHEET_HGT_2D_3ROW   - Height of a 2D spreadsheet with 3 rows
 *   SPREADSHEET_HGT_2D_4ROW   - Height of a 2D spreadsheet with 4 rows
 *   SPREADSHEET_HGT_2D_5ROW   - Height of a 2D spreadsheet with 5 rows
 *   SPREADSHEET_HGT_2D_6ROW   - Height of a 2D spreadsheet with 6 rows
 *   SPREADSHEET_HGT_2D_7ROW   - Height of a 2D spreadsheet with 7 rows
 *   SPREADSHEET_HGT_2D_8ROW   - Height of a 2D spreadsheet with 8 rows
 *   SPREADSHEET_HGT_2D_9ROW   - Height of a 2D spreadsheet with 9 rows
 *   SPREADSHEET_HGT_2D_10ROW  - Height of a 2D spreadsheet with 10 rows
 *   SPREADSHEET_HGT_2D_INCR   - Height increment for 2D spreadsheet
 *
 *   SPREADSHEET_HGT_3D_1ROW   - Height of a 3D spreadsheet with 1 row
 *   SPREADSHEET_HGT_3D_2ROW   - Height of a 3D spreadsheet with 2 rows
 *   SPREADSHEET_HGT_3D_3ROW   - Height of a 3D spreadsheet with 3 rows
 *   SPREADSHEET_HGT_3D_4ROW   - Height of a 3D spreadsheet with 4 rows
 *   SPREADSHEET_HGT_3D_5ROW   - Height of a 3D spreadsheet with 5 rows
 *   SPREADSHEET_HGT_3D_6ROW   - Height of a 3D spreadsheet with 6 rows
 *   SPREADSHEET_HGT_3D_7ROW   - Height of a 3D spreadsheet with 7 rows
 *   SPREADSHEET_HGT_3D_8ROW   - Height of a 3D spreadsheet with 8 rows
 *   SPREADSHEET_HGT_3D_9ROW   - Height of a 3D spreadsheet with 9 rows
 *   SPREADSHEET_HGT_3D_10ROW  - Height of a 3D spreadsheet with 10 rows
 *   SPREADSHEET_HGT_3D_INCR   - Height increment for 3D spreadsheet
 */

#define SPREADSHEET_WID_SINGLE uil_form_sizes.spread_sheet_wid( 1 )
#define SPREADSHEET_WID_DOUBLE uil_form_sizes.spread_sheet_wid( 2 )
#define SPREADSHEET_WID_TRIPLE uil_form_sizes.spread_sheet_wid( 3 )
#define SPREADSHEET_WID_SPECIAL uil_form_sizes.spread_sheet_wid( 4 )

#define SPREADSHEET_LABEL_HGT uil_form_sizes.spread_sheet_hgt( 12, 1 )

#define SPREADSHEET_HGT_2D_1ROW uil_form_sizes.spread_sheet_hgt( 1, 1 )
#define SPREADSHEET_HGT_2D_2ROW uil_form_sizes.spread_sheet_hgt( 2, 1 )
#define SPREADSHEET_HGT_2D_3ROW uil_form_sizes.spread_sheet_hgt( 3, 1 )
#define SPREADSHEET_HGT_2D_4ROW uil_form_sizes.spread_sheet_hgt( 4, 1 )
#define SPREADSHEET_HGT_2D_5ROW uil_form_sizes.spread_sheet_hgt( 5, 1 )
#define SPREADSHEET_HGT_2D_6ROW uil_form_sizes.spread_sheet_hgt( 6, 1 )
#define SPREADSHEET_HGT_2D_7ROW uil_form_sizes.spread_sheet_hgt( 7, 1 )
#define SPREADSHEET_HGT_2D_8ROW uil_form_sizes.spread_sheet_hgt( 8, 1 )
#define SPREADSHEET_HGT_2D_9ROW uil_form_sizes.spread_sheet_hgt( 9, 1 )
#define SPREADSHEET_HGT_2D_10ROW uil_form_sizes.spread_sheet_hgt( 10, 1 )
#define SPREADSHEET_HGT_2D_INCR uil_form_sizes.spread_sheet_hgt( 11, 1 )

#define SPREADSHEET_HGT_3D_1ROW uil_form_sizes.spread_sheet_hgt( 1, 2 )
#define SPREADSHEET_HGT_3D_2ROW uil_form_sizes.spread_sheet_hgt( 2, 2 )
#define SPREADSHEET_HGT_3D_3ROW uil_form_sizes.spread_sheet_hgt( 3, 2 )
#define SPREADSHEET_HGT_3D_4ROW uil_form_sizes.spread_sheet_hgt( 4, 2 )
#define SPREADSHEET_HGT_3D_5ROW uil_form_sizes.spread_sheet_hgt( 5, 2 )
#define SPREADSHEET_HGT_3D_6ROW uil_form_sizes.spread_sheet_hgt( 6, 2 )
#define SPREADSHEET_HGT_3D_7ROW uil_form_sizes.spread_sheet_hgt( 7, 2 )
#define SPREADSHEET_HGT_3D_8ROW uil_form_sizes.spread_sheet_hgt( 8, 2 )
#define SPREADSHEET_HGT_3D_9ROW uil_form_sizes.spread_sheet_hgt( 9, 2 )
#define SPREADSHEET_HGT_3D_10ROW uil_form_sizes.spread_sheet_hgt( 10, 2 )
#define SPREADSHEET_HGT_3D_INCR uil_form_sizes.spread_sheet_hgt( 11, 2 )


/*
 *   SWITCHES
 *
 *
 *   Create a framed two row switch with a label.  Note that the
 *   number of rows is a function of the "num_cols" variable and the
 *   number of items created for the switch.
 *
 *      y_frame_loc = FRAME_T_MARGIN
 *
 *      ui_switch_create( frame_id, "callback",              @
 *                        FRAME_L_MARGIN,                    @
 *                        y_frame_loc,                       @
 *                        num_cols, "Switch Label",          @
 *                        alwaysone_flag )
 *
 *      y_frame_loc = y_frame_loc +                          @
 *                    SWITCH_2R_HGT_LABEL +                  @
 *                    INTER_WIDGET_SPACE
 *
 *
 *   Switch Height:
 *
 *
 *   SWITCH_1R_HGT_LABEL      - Height of a 1 row switch with a label
 *   SWITCH_2R_HGT_LABEL      - Height of a 2 row switch with a label
 *   SWITCH_3R_HGT_LABEL      - Height of a 3 row switch with a label
 *   SWITCH_4R_HGT_LABEL      - Height of a 4 row switch with a label
 *
 *   SWITCH_HGT_LABEL_INCR    - Increment for creating a switch height with
 *                              more than 4 rows in it
 *
 *   SWITCH_1R_HGT_NO_LABEL   - Height of a 1 row switch with no label
 *   SWITCH_2R_HGT_NO_LABEL   - Height of a 2 row switch with no label
 *   SWITCH_3R_HGT_NO_LABEL   - Height of a 3 row switch with no label
 *   SWITCH_4R_HGT_NO_LABEL   - Height of a 4 row switch with no label
 *
 *   SWITCH_HGT_NO_LABEL_INCR - Increment for creating a switch height with
 *                              more than 4 rows in it
 */

#define SWITCH_1R_HGT_LABEL uil_form_sizes.switch_hgt( 1, 1 )
#define SWITCH_2R_HGT_LABEL uil_form_sizes.switch_hgt( 2, 1 )
#define SWITCH_3R_HGT_LABEL uil_form_sizes.switch_hgt( 3, 1 )
#define SWITCH_4R_HGT_LABEL uil_form_sizes.switch_hgt( 4, 1 )
#define SWITCH_HGT_LABEL_INCR uil_form_sizes.switch_hgt( 5, 1 )

#define SWITCH_1R_HGT_NO_LABEL uil_form_sizes.switch_hgt( 1, 2 )
#define SWITCH_2R_HGT_NO_LABEL uil_form_sizes.switch_hgt( 2, 2 )
#define SWITCH_3R_HGT_NO_LABEL uil_form_sizes.switch_hgt( 3, 2 )
#define SWITCH_4R_HGT_NO_LABEL uil_form_sizes.switch_hgt( 4, 2 )
#define SWITCH_HGT_NO_LABEL_INCR uil_form_sizes.switch_hgt( 5, 2 )


/*
 *   TEXTBOXES
 *
 *
 *   Create a framed three line textbox with a label.  Note that the
 *   widths and heights include the vertical and horizontal sliders.
 *
 *      y_frame_loc = FRAME_T_MARGIN
 *
 *      ui_text_create ( frame_id, "",                       @
 *                       FRAME_L_MARGIN,                     @
 *                       y_frame_loc,                        @
 *                       TBOX_WID_SINGLE,                    @
 *                       3, "Textbox Label",                 @
 *                       "This is text", editable_flag )
 *
 *      y_frame_loc = y_frame_loc +                          @
 *                    TBOX_3L_HGT_LABOVE +                   @
 *                    INTER_WIDGET_SPACE
 *
 *
 *   To determine the height for a six line textbox, add the value
 *   of "TBOX_HGT_LABOVE_INCR" to "TBOX_5L_HGT_LABOVE".
 *
 *
 *   Textbox Width and Height:
 *
 *   TBOX_WID_SINGLE         - Width of a single width textbox   
 *   TBOX_WID_SPECIAL        - Width of a special width textbox   
 *   TBOX_WID_DOUBLE         - Width of a double width textbox   
 *   TBOX_WID_TRIPLE         - Width of a triple width textbox   
 *
 *   TBOX_1L_HGT_LABOVE      - Height of a 1 line textbox with a top label
 *   TBOX_2L_HGT_LABOVE      - Height of a 2 line textbox with a top label
 *   TBOX_3L_HGT_LABOVE      - Height of a 3 line textbox with a top label
 *   TBOX_4L_HGT_LABOVE      - Height of a 4 line textbox with a top label
 *   TBOX_5L_HGT_LABOVE      - Height of a 5 line textbox with a top label
 *
 *   TBOX_HGT_LABOVE_INCR    - Increment for computing a textbox height that
 *                             has more than 5 lines in it
 *
 *   TBOX_1L_HGT_NO_LABOVE   - Height of a 1 line textbox with no label
 *                             (label is blank)
 *   TBOX_2L_HGT_NO_LABOVE   - Height of a 2 line textbox with no label
 *   TBOX_3L_HGT_NO_LABOVE   - Height of a 3 line textbox with no label
 *   TBOX_4L_HGT_NO_LABOVE   - Height of a 4 line textbox with no label
 *   TBOX_5L_HGT_NO_LABOVE   - Height of a 5 line textbox with no label
 *
 *   TBOX_HGT_NO_LABOVE_INCR - Increment for computing a textbox height that
 *                             has more than 5 lines in it
 */

#define TBOX_WID_SINGLE uil_form_sizes.tbox_wid( 1 )
#define TBOX_WID_DOUBLE uil_form_sizes.tbox_wid( 2 )
#define TBOX_WID_TRIPLE uil_form_sizes.tbox_wid( 3 )
#define TBOX_WID_SPECIAL uil_form_sizes.tbox_wid( 4 )

#define TBOX_1L_HGT_LABOVE uil_form_sizes.tbox_hgt( 1, 1 )
#define TBOX_2L_HGT_LABOVE uil_form_sizes.tbox_hgt( 2, 1 )
#define TBOX_3L_HGT_LABOVE uil_form_sizes.tbox_hgt( 3, 1 )
#define TBOX_4L_HGT_LABOVE uil_form_sizes.tbox_hgt( 4, 1 )
#define TBOX_5L_HGT_LABOVE uil_form_sizes.tbox_hgt( 5, 1 )
#define TBOX_HGT_LABOVE_INCR uil_form_sizes.tbox_hgt( 6, 1 )

#define TBOX_1L_HGT_NO_LABOVE uil_form_sizes.tbox_hgt( 1, 2 )
#define TBOX_2L_HGT_NO_LABOVE uil_form_sizes.tbox_hgt( 2, 2 )
#define TBOX_3L_HGT_NO_LABOVE uil_form_sizes.tbox_hgt( 3, 2 )
#define TBOX_4L_HGT_NO_LABOVE uil_form_sizes.tbox_hgt( 4, 2 )
#define TBOX_5L_HGT_NO_LABOVE uil_form_sizes.tbox_hgt( 5, 2 )
#define TBOX_HGT_NO_LABOVE_INCR uil_form_sizes.tbox_hgt( 6, 2 )


/*
 *   TOGGLES
 *
 *
 *   Create a toggle inside a frame and then compute the y location
 *   of the next widget in the frame.
 *
 *      y_frame_loc = FRAME_T_MARGIN
 *
 *      ui_toggle_create ( frame_id, "callback",             @
 *                         FRAME_L_MARGIN,                   @
 *                         y_frame_loc,                      @
 *                         "Toggle Label" )
 *
 *      y_frame_loc = y_frame_loc +                          @
 *                    TOGGLE_HGT +                           @
 *                    INTER_WIDGET_SPACE
 *
 *
 *   Toggle Height:
 *
 *   TOGGLE_HGT       - Height of a toggle
 *   TOGGLE_Y_OFFSET  - Y offset for placing a label to the side
 *                      of a toggle
 */

#define TOGGLE_HGT uil_form_sizes.toggle_data( 1 )
#define TOGGLE_Y_OFFSET uil_form_sizes.toggle_data( 2 )


/*
 *   LANGUAGE
 *
 *
 *   Language variables:
 *
 *   ENGLISH      - "English"
 *   GERMAN       - "German"
 *   SPANISH      - "Spanish"
 *   FRENCH       - "French"
 *   KANJI        - "Kanji"
 *
 *   LANGUAGE     - Current language (see above)
 *   HANDEDNESS   - Determines whether forms appear on right of left side
 *                  of screen
 */

#define ENGLISH "English"
#define GERMAN "German"
#define SPANISH "Spanish"
#define FRENCH "French"
#define KANJI "Kanji"

#define LANGUAGE uil_form_sizes.language()
#define HANDEDNESS uil_form_sizes.handedness()


/*
 *   SCREEN
 *
 *
 *   Screen variables:
 *
 *   PIXEL_WID   - Width of a pixel (in inches)
 *   PIXEL_HGT   - Height of a pixel (in inches)
 *
 *   SCREEN_WID  - Width of logical screen (in inches)
 *   SCREEN_HGT  - Height of logical screen (in inches)
 */

#define PIXEL_WID uil_form_sizes.pixel_size( 1 )
#define PIXEL_HGT uil_form_sizes.pixel_size( 2 )

#define SCREEN_WID uil_form_sizes.screen( 1 )
#define SCREEN_HGT uil_form_sizes.screen( 2 )


/*
 *   BASIC LAYOUT
 *
 *
 *   Basic layout variables:
 *
 *   MAIN_MENU_X_LOC          - Main menu X location
 *   MAIN_MENU_Y_LOC          - Main menu Y location
 *   MAIN_MENU_WID            - Main menu width
 *   MAIN_MENU_HGT            - Main menu height
 *   MAIN_MENU_L_EDGE         - Left edge of main menu (incl border)
 *   MAIN_MENU_R_EDGE         - Right edge of main menu (incl border)
 *   MAIN_MENU_T_EDGE         - Top edge of main menu (incl border)
 *   MAIN_MENU_B_EDGE         - Bottom edge of main menu (incl border)
 *   MAIN_MENU_SWITCH_Y_LOC   - Switch Y location
 *   MAIN_MENU_ICON_Y_LOC     - Icon Y location
 *   MAIN_MENU_ICON_HGT       - Main Menu Icon Height
 *   MAIN_MENU_ICON_WID       - Main Menu Icon Width
 *   MAIN_MENU_LOGO_ICON_WID  - Main Menu Logo Icon Width
 *   MAIN_MENU_HEART_ICON_WID - Main Menu Heartbeat Icon Width
 *   MAIN_MENU_HEART_ICON_HGT - Main Menu Heartbeat Icon Height
 *   MAIN_MENU_MARGIN         - Main menu switch margin
 *   MAIN_MENU_ICON_MARGIN    - Main menu margin between icons
 *   MAIN_MENU_HEART_MARGIN   - Main menu margin between last icon and
 *                              heartbeat icon
 *   MAIN_MENU_HEART_X_LOC    - Heartbeat icon X location
 *   MAIN_MENU_HEART_Y_LOC    - Heartbeat icon Y location
 *
 *   COMMAND_WINDOW_X_LOC     - Command window X location
 *   COMMAND_WINDOW_Y_LOC     - Command window Y location
 *   COMMAND_WINDOW_WID       - Command window width
 *   COMMAND_WINDOW_HGT       - Command window height
 *   COMMAND_WINDOW_NUM_ROWS  - Number of history rows in the command window
 *   COMMAND_WINDOW_L_EDGE    - Left edge of command window (incl border)
 *   COMMAND_WINDOW_R_EDGE    - Right edge of command window (incl border)
 *   COMMAND_WINDOW_T_EDGE    - Top edge of command window (incl border)
 *   COMMAND_WINDOW_B_EDGE    - Bottom edge of command window (incl border)
 *
 *   GRAPHICS_WINDOW_X_LOC    - Graphics window X location
 *   GRAPHICS_WINDOW_Y_LOC    - Graphics window Y location
 *   GRAPHICS_WINDOW_WID      - Graphics window width
 *   GRAPHICS_WINDOW_HGT      - Graphics window height
 *   GRAPHICS_WINDOW_L_EDGE   - Left edge of graphics window (incl border)
 *   GRAPHICS_WINDOW_R_EDGE   - Right edge of graphics window (incl border)
 *   GRAPHICS_WINDOW_T_EDGE   - Top edge of graphics window (incl border)
 *   GRAPHICS_WINDOW_B_EDGE   - Bottom edge of graphics window (incl border)
 *
 *   SHOW_SPREADSHEET_NUM_ROWS - Number of rows in the show spreadsheet widget
 *
 *   GRAPHICS_WINDOW_WID_QTR  - Quarter width graphics window
 *   GRAPHICS_WINDOW_HGT_QTR  - Quarter width graphics window
 *
 *   GRAPHICS_WINDOW_X_LOC_UL - Quarter size graphics window upper left X loc
 *   GRAPHICS_WINDOW_Y_LOC_UL - Quarter size graphics window upper left Y loc
 *   GRAPHICS_WINDOW_X_LOC_UR - Quarter size graphics window upper right X loc
 *   GRAPHICS_WINDOW_Y_LOC_UR - Quarter size graphics window upper right Y loc
 *   GRAPHICS_WINDOW_X_LOC_LL - Quarter size graphics window lower left X loc
 *   GRAPHICS_WINDOW_Y_LOC_LL - Quarter size graphics window lower left Y loc
 *   GRAPHICS_WINDOW_X_LOC_LR - Quarter size graphics window lower right X loc
 *   GRAPHICS_WINDOW_Y_LOC_LR - Quarter size graphics window lower right Y loc
 *
 *   GRAPHICS_CEN_X_LOC       - Center of graphics area X location
 *   GRAPHICS_CEN_Y_LOC       - Center of graphics area Y location
 *
 *   WINDOW_CEN_X_LOC         - Center of area beneath main menu X location
 *   WINDOW_CEN_Y_LOC         - Center of area beneath main menu Y location
 *
 *   MAIN_MENU_SWITCH_COLS    - Number of columns for main menu switch
 *
 *   ENABLE_MAIN_MENU_SWITCH  - Hidden code to enable the main menu switch
 *                              without having to open a database
 */

#define MAIN_MENU_X_LOC uil_form_sizes.main_menu( 1 )
#define MAIN_MENU_Y_LOC uil_form_sizes.main_menu( 2 )
#define MAIN_MENU_WID uil_form_sizes.main_menu( 3 )
#define MAIN_MENU_HGT uil_form_sizes.main_menu( 4 )
#define MAIN_MENU_L_EDGE uil_form_sizes.main_menu( 5 )
#define MAIN_MENU_R_EDGE uil_form_sizes.main_menu( 6 )
#define MAIN_MENU_T_EDGE uil_form_sizes.main_menu( 7 )
#define MAIN_MENU_B_EDGE uil_form_sizes.main_menu( 8 )
#define MAIN_MENU_SWITCH_Y_LOC uil_form_sizes.main_menu( 9 )
#define MAIN_MENU_ICON_Y_LOC uil_form_sizes.main_menu( 10 )
#define MAIN_MENU_ICON_HGT  uil_form_sizes.main_menu( 11 )
#define MAIN_MENU_ICON_WID  uil_form_sizes.main_menu( 12 )
#define MAIN_MENU_LOGO_ICON_WID  uil_form_sizes.main_menu( 13 )
#define MAIN_MENU_HEART_ICON_WID  uil_form_sizes.main_menu( 16 )
#define MAIN_MENU_HEART_ICON_HGT  uil_form_sizes.main_menu( 20 )
#define MAIN_MENU_MARGIN uil_form_sizes.main_menu( 14 )
#define MAIN_MENU_ICON_MARGIN uil_form_sizes.main_menu( 15 )
#define MAIN_MENU_HEART_MARGIN uil_form_sizes.main_menu( 17 )
#define MAIN_MENU_HEART_X_LOC uil_form_sizes.main_menu( 18 )
#define MAIN_MENU_HEART_Y_LOC uil_form_sizes.main_menu( 19 )
#define MAIN_MENU_SWITCH_COLS uil_form_sizes.main_menu( 0 ) 

#define COMMAND_WINDOW_X_LOC uil_form_sizes.command_window( 1 )
#define COMMAND_WINDOW_Y_LOC uil_form_sizes.command_window( 2 )
#define COMMAND_WINDOW_WID uil_form_sizes.command_window( 3 )
#define COMMAND_WINDOW_HGT uil_form_sizes.command_window( 4 )
#define COMMAND_WINDOW_NUM_ROWS uil_form_sizes.command_window( 9 )
#define COMMAND_WINDOW_L_EDGE uil_form_sizes.command_window( 5 )
#define COMMAND_WINDOW_R_EDGE uil_form_sizes.command_window( 6 )
#define COMMAND_WINDOW_T_EDGE uil_form_sizes.command_window( 7 )
#define COMMAND_WINDOW_B_EDGE uil_form_sizes.command_window( 8 )
#define COMMAND_WINDOW_X_LOC_TWO uil_form_sizes.command_window_two( 1 )
#define COMMAND_WINDOW_Y_LOC_TWO uil_form_sizes.command_window_two( 2 )
#define COMMAND_WINDOW_WID_TWO uil_form_sizes.command_window_two( 3 )
#define COMMAND_WINDOW_HGT_TWO uil_form_sizes.command_window_two( 4 )

#define SHOW_SPREADSHEET_NUM_ROWS uil_form_sizes.spread_sheet_wid( -1 )

#define GRAPHICS_WINDOW_X_LOC uil_form_sizes.graphics_window( 1 )
#define GRAPHICS_WINDOW_Y_LOC uil_form_sizes.graphics_window( 2 )
#define GRAPHICS_WINDOW_WID uil_form_sizes.graphics_window( 3 )
#define GRAPHICS_WINDOW_HGT uil_form_sizes.graphics_window( 4 )
#define GRAPHICS_WINDOW_L_EDGE uil_form_sizes.graphics_window( 5 )
#define GRAPHICS_WINDOW_R_EDGE uil_form_sizes.graphics_window( 6 )
#define GRAPHICS_WINDOW_T_EDGE uil_form_sizes.graphics_window( 7 )
#define GRAPHICS_WINDOW_B_EDGE uil_form_sizes.graphics_window( 8 )

#define GRAPHICS_WINDOW_WID_QTR uil_form_sizes.graphics_window( 9 )
#define GRAPHICS_WINDOW_HGT_QTR uil_form_sizes.graphics_window( 10 )

#define GRAPHICS_WINDOW_X_LOC_UL uil_form_sizes.graphics_window( 1 )
#define GRAPHICS_WINDOW_Y_LOC_UL uil_form_sizes.graphics_window( 2 )
#define GRAPHICS_WINDOW_X_LOC_UR uil_form_sizes.graphics_window( 11 )
#define GRAPHICS_WINDOW_Y_LOC_UR uil_form_sizes.graphics_window( 12 )
#define GRAPHICS_WINDOW_X_LOC_LL uil_form_sizes.graphics_window( 13 )
#define GRAPHICS_WINDOW_Y_LOC_LL uil_form_sizes.graphics_window( 14 )
#define GRAPHICS_WINDOW_X_LOC_LR uil_form_sizes.graphics_window( 15 )
#define GRAPHICS_WINDOW_Y_LOC_LR uil_form_sizes.graphics_window( 16 )

#define GRAPHICS_CEN_X_LOC uil_form_sizes.graphics_window( 17 )
#define GRAPHICS_CEN_Y_LOC uil_form_sizes.graphics_window( 18 )

#define WINDOW_CEN_X_LOC uil_form_sizes.graphics_window( 19 )
#define WINDOW_CEN_Y_LOC uil_form_sizes.graphics_window( 20 )

#define ENABLE_MAIN_MENU_SWITCH uil_form_sizes.main_menu_switch( 1 ) 


/*  OLD APPFORMS VARIABLES ***********NEW VARIABLE NAMES*****************
 */


/*
 *  Application Panels
 */
#define APP_FORM_X_LOC 0.0
#define APP_FORM_Y_LOC 0.9
#define APP_FORM_WID 2.5
#define APP_FORM_HGT 7.0
#define APP_LABEL_WID 1.0
#define APP_LABEL_Y_OFFSET 0.2
/*#define APP_DBOX_WID 1.85*/
#define INTER_WIDGET_Y_OFFSET 0.15

 
/*
 *  Selection Frames
 */
#define SELFR_WID 2.2
#define A_1LINE_SELFR_HGT 0.6
#define A_2LINE_SELFR_HGT 1.2
#define A_3LINE_SELFR_HGT 1.75
#define A_4LINE_SELFR_HGT 2.40
#define A_8LINE_SELFR_HGT 4.80
#define SELFR_LEFT_MARGIN 0.05
#define SELFR_TOP_MARGIN 0.05
#define SELFR_DBOX_LABOVE_LEN 2.10
 
/*
 *  Data Box
 */
#define DBOX_LABOVE_LEN 2.15
#define DBOX_LABOVE_YOFFSET 0.55
#define DBOX_YOFFSET 0.35
#define LEFT_MARGIN_UNFRAMED 0.15
 
/*
 *  List Box
 */
#define APP_LBOX_WID 2.2


/*
 *  Object Menu
 */

#define OPTION_MENU2_Y ( TOP_MARGIN + OPTION_MENU_HGT + 0.1 )
/*
 *  Option Menu
 */

#define OPTION_MENU3_Y ( OPTION_MENU2_Y + OPTION_MENU_HGT + 0.1 )
#define APP_OMENU_YOFFSET OPTION_MENU_HGT + 0.1
#define APP_METHOD_MENU_Y OPTION_MENU3_Y
#define OPTION_MENU_LABEL_LEN ( 0.32 * APP_FORM_WID )
 

/*
 *  Keyword area
 */

#define KEY_WORD_AREA_HGT 1.1
#define KEY_WORD_AREA ( OPTION_MENU3_Y + OPTION_MENU_HGT + INTER_WIDGET_Y_OFFSET + WIDGET_BUFFER + SEPARATOR_HGT ) - 0.15

/*
 *  Full Width Frames
 */
#define APP_FULL_WID_FRAME_WID 2.25
#define A_1DBOX_FR_HGT 0.6
#define A_2DBOX_FR_HGT 1.15
#define A_3DBOX_FR_HGT 1.70
#define A_4DBOX_FR_HGT 2.25
#define A_8DBOX_FR_HGT 4.80
#define FR_LEFT_MARGIN 0.05
#define FR_TOP_MARGIN 0.05

/*
 *  Switch Frames
 */
#define A_1SWITCH_FR_HGT 0.3
#define A_2SWITCH_FR_HGT 0.55
#define A_3SWITCH_FR_HGT 0.8
#define A_4SWITCH_FR_HGT 1.05

/*
 *  Buttons
 */
#define SM_BUTTON 0.9
#define LG_BUTTON 2.1
#define CENTER_SM_BUTTON 0.65
#define BETWEEN_2SM_BUTTON 0.3
#define SM_ICON_HEIGHT 0.28

/*
 *  Full Width slidebars
 */
#define SLIDEBAR_WIDTH ( APP_FORM_WID - 2. * LEFT_MARGIN_UNFRAMED )



#endif
