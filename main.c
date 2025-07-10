
/**
 * @file main
 *
 */

/*********************
 *      INCLUDES
 *********************/
#define _DEFAULT_SOURCE /* needed for usleep() */
#include <stdlib.h>
#include <unistd.h>
#define SDL_MAIN_HANDLED /*To fix SDL's "undefined reference to WinMain" issue*/
#include <SDL2/SDL.h>
#include "lvgl/lvgl.h"
#include "lvgl/examples/lv_examples.h"
#include "lvgl/demos/lv_demos.h"
#include "lv_drivers/sdl/sdl.h"
#include "lvgl/examples/widgets/lv_example_widgets.h"
/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void hal_init(void);

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *      VARIABLES
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
static int contributions_last_7_days[] = {1, 2, 3, 2, 4, 3, 2}; // 示例数据
static lv_obj_t *main_obj;

int main(int argc, char **argv)
{
  (void)argc; /*Unused*/
  (void)argv; /*Unused*/

  /*Initialize LVGL*/
  lv_init();

  /*Initialize the HAL (display, input devices, tick) for LVGL*/
  hal_init();

  //lv_example_switch_1();//开关
//  lv_example_calendar_1();//日历
//  lv_example_btnmatrix_2();//按钮矩阵
//  lv_example_checkbox_1();//复选框
//  lv_example_colorwheel_1();//颜色轮
//  lv_example_chart_6();//图表
//  lv_example_table_2();//表格
//  lv_example_scroll_2();//滚动
//  lv_example_textarea_1();//文本框
//  lv_example_msgbox_1();//消息框
//  lv_example_dropdown_2();//下拉菜单
//  lv_example_btn_1();//按钮
//  lv_example_scroll_1();//滚动
//  lv_example_tabview_1();//标签视图
//  lv_example_flex_3();//弹性布局
//  lv_example_label_1();//标签

    //lv_demo_widgets();

    // 创建主界面基本对象
    // lv_obj_set_style_bg_color(lv_scr_act(), lv_color_hex(0xffffff), 0); // 修改背景为黑色

    // static lv_style_t style;
    // lv_style_init(&style);
    // lv_style_set_radius(&style, 10);  
    // lv_style_set_bg_opa( &style, LV_OPA_COVER );
    //lv_style_set_bg_color(&style, lv_color_hex(0xffffff));
    //lv_style_set_bg_grad_color( &style, lv_color_hex( 0x00BF00 ) );
    //lv_style_set_bg_grad_dir( &style, LV_GRAD_DIR_VER );
    // lv_style_set_border_width(&style, 0);
    // lv_style_set_pad_all(&style, 0);
    // lv_style_set_width(&style, 320);  
    // lv_style_set_height(&style, 240); 
    
    
    // main_obj = lv_obj_create(lv_scr_act());
    // lv_obj_add_style(main_obj, &style, 0);

  
    
    
    // lv_obj_t * label = lv_label_create(lv_scr_act());
    // lv_obj_set_style_text_font(label, &lv_font_montserrat_12, 0);    
    // lv_label_set_text(label, "GITHUB_USERNAME");      // 设置文本
    // lv_obj_align(label, LV_ALIGN_TOP_MID, 0, 20);  // 居中上对齐，向下偏移20像素
    
    //这里创建了一个柱形统计图，表示近七天的github贡献，柱形宽度30，间隔15
    // static lv_style_t square_style;
    // lv_style_init(&square_style);
    // lv_style_set_bg_color(&square_style, lv_color_hex(0x00FF00)); // 背景绿色
    // lv_style_set_border_color(&square_style, lv_color_black());
    // lv_style_set_border_width(&square_style, 2);
    
    
    // for(int i = 0; i < 7; i++) 
    // {
    //     lv_obj_t * square = lv_obj_create(lv_scr_act());
    //     lv_obj_set_size(square, 24,  40 * contributions_last_7_days[i]);
    //     lv_obj_add_style(square, &square_style, 0);
    //     lv_obj_set_pos(square, 25+ (i * 41), 220-(40*contributions_last_7_days[i]));  
    // }
    
    
    // //模拟了坐标轴
    // static lv_point_t line_points_x[] = { {10, 220}, {310, 220} };
    // static lv_point_t line_points_y[] = { {20, 10}, {20, 230} };
    
  //   lv_obj_t * line_x = lv_line_create(lv_scr_act());
  //   lv_line_set_points(line_x, line_points_x, 2);   // 设置线的两个端点
  //   lv_obj_set_pos(line_x, 0, 0);                 // 线整体偏移
  //   lv_obj_set_style_line_width(line_x, 2, LV_PART_MAIN);         // 线宽
  //   lv_obj_set_style_line_color(line_x, lv_color_hex(0xADD8E6), LV_PART_MAIN); 
    
  //   lv_obj_t * line_y = lv_line_create(lv_scr_act());
  //   lv_line_set_points(line_y, line_points_y, 2);   // 设置线的两个端点
  //   lv_obj_set_pos(line_y, 0, 0);                 // 线整体偏移
  //   lv_obj_set_style_line_width(line_y, 2, LV_PART_MAIN);         // 线宽
  //   lv_obj_set_style_line_color(line_y, lv_color_hex(0xADD8E6), LV_PART_MAIN); 
  while(1) {
      /* Periodically call the lv_task handler.
       * It could be done in a timer interrupt or an OS task too.*/
      lv_timer_handler();
      usleep(5 * 1000);
  }

  return 0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/**
 * Initialize the Hardware Abstraction Layer (HAL) for the LVGL graphics
 * library
 */
static void hal_init(void)
{
  /* Use the 'monitor' driver which creates window on PC's monitor to simulate a display*/
  sdl_init();

  /*Create a display buffer*/
  static lv_disp_draw_buf_t disp_buf1;
  static lv_color_t buf1_1[SDL_HOR_RES * 100];
  lv_disp_draw_buf_init(&disp_buf1, buf1_1, NULL, SDL_HOR_RES * 100);

  /*Create a display*/
  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv); /*Basic initialization*/
  disp_drv.draw_buf = &disp_buf1;
  disp_drv.flush_cb = sdl_display_flush;
  disp_drv.hor_res = SDL_HOR_RES;
  disp_drv.ver_res = SDL_VER_RES;

  lv_disp_t * disp = lv_disp_drv_register(&disp_drv);

  lv_theme_t * th = lv_theme_default_init(disp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), LV_THEME_DEFAULT_DARK, LV_FONT_DEFAULT);
  lv_disp_set_theme(disp, th);

  lv_group_t * g = lv_group_create();
  lv_group_set_default(g);

  /* Add the mouse as input device
   * Use the 'mouse' driver which reads the PC's mouse*/
  static lv_indev_drv_t indev_drv_1;
  lv_indev_drv_init(&indev_drv_1); /*Basic initialization*/
  indev_drv_1.type = LV_INDEV_TYPE_POINTER;

  /*This function will be called periodically (by the library) to get the mouse position and state*/
  indev_drv_1.read_cb = sdl_mouse_read;
  lv_indev_t *mouse_indev = lv_indev_drv_register(&indev_drv_1);

  static lv_indev_drv_t indev_drv_2;
  lv_indev_drv_init(&indev_drv_2); /*Basic initialization*/
  indev_drv_2.type = LV_INDEV_TYPE_KEYPAD;
  indev_drv_2.read_cb = sdl_keyboard_read;
  lv_indev_t *kb_indev = lv_indev_drv_register(&indev_drv_2);
  lv_indev_set_group(kb_indev, g);

  static lv_indev_drv_t indev_drv_3;
  lv_indev_drv_init(&indev_drv_3); /*Basic initialization*/
  indev_drv_3.type = LV_INDEV_TYPE_ENCODER;
  indev_drv_3.read_cb = sdl_mousewheel_read;
  lv_indev_t * enc_indev = lv_indev_drv_register(&indev_drv_3);
  lv_indev_set_group(enc_indev, g);

  /*Set a cursor for the mouse*/
  LV_IMG_DECLARE(mouse_cursor_icon); /*Declare the image file.*/
  lv_obj_t * cursor_obj = lv_img_create(lv_scr_act()); /*Create an image object for the cursor */
  lv_img_set_src(cursor_obj, &mouse_cursor_icon);           /*Set the image source*/
  lv_indev_set_cursor(mouse_indev, cursor_obj);             /*Connect the image  object to the driver*/
}
