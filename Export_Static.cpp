


















































































































































































































































CLASS Export_Static


CLASSWIDE WIDGET form_id,file_button,list_id,apply_button,cancel_button


CLASSWIDE STRING group_names[100](VIRTUAL)


CLASSWIDE STRING group_labels[100](VIRTUAL)


CLASSWIDE INTEGER group_numbers


FUNCTION init()
GLOBAL WIDGET file_id
REAL x_loc,y_loc


x_loc=uil_form_sizes.unframed_margin( 1 )
y_loc=uil_form_sizes.form_margin( 3 )
group_numbers=20


$ 创建表单
form_id=ui_form_create("",uil_form_sizes.form_x_loc( 1 ),uil_form_sizes.form_y_loc( 1 ), "UL",uil_form_sizes.form_wid( 1 ),uil_form_sizes.form_hgt( 3 ), "Static Analysis Result Export", "" )
$ 选择文件
file_id=ui_databox_create(form_id,"",x_loc,y_loc,0.0,uil_form_sizes.dbox_wid( 1 ),"Select *.xdb:","",TRUE,"STRING",1)
y_loc+= uil_form_sizes.dbox_hgt( 1 )+ uil_form_sizes.spacing( 8 )
file_button=ui_button_create(form_id, "select_file", uil_form_sizes.button_x_loc1( 2 ), y_loc, uil_form_sizes.button_wid( 2 ), 0.,"Select File", FALSE, FALSE)
y_loc+= uil_form_sizes.dbox_hgt( 1 )+ uil_form_sizes.spacing( 8 )
$ 创建list列表
list_id=ui_listbox_create(form_id,"",x_loc,y_loc,uil_form_sizes.dbox_wid( 1 ),group_numbers,"Select Group:","MULTIPLE",FALSE)


$ ui_listbox_items_create(list_id,group_names,group_labels,group_numbers,WIDGET_NULL)


ui_wid_set(list_id,"ROWS",20)


y_loc+= uil_form_sizes.dbox_hgt( 1 )*10+ uil_form_sizes.spacing( 8 )


$ 创建按钮
apply_button=ui_button_create(form_id, "apply", uil_form_sizes.button_x_loc1( 2 ), y_loc, uil_form_sizes.button_wid( 2 ), 0.,"Apply", FALSE, FALSE)


cancel_button=ui_button_create(form_id, "cancel", uil_form_sizes.button_x_loc1( 3 ), y_loc, uil_form_sizes.button_wid( 2 ), 0.,"Cancel", FALSE, FALSE)


END FUNCTION


FUNCTION display()
ui_form_display("Export_Static")
END FUNCTION


FUNCTION select_file()
ui_exec_function("File_Form","display")
END FUNCTION
$ 应用选择
FUNCTION apply()


END FUNCTION


FUNCTION cancel()
ui_form_hide("Export_Static")
END FUNCTION


END CLASS


CLASS File_Form


CLASSWIDE WIDGET form_id,file_widget


FUNCTION init()
REAL x_loc,y_loc


x_loc=uil_form_sizes.unframed_margin( 1 )
y_loc=uil_form_sizes.form_margin( 3 )


$ 创建表单
form_id=ui_form_create("",uil_form_sizes.form_x_loc( 11 ),uil_form_sizes.form_y_loc( 2 ), "UL",uil_form_sizes.form_wid( 2 ),uil_form_sizes.form_hgt( 3 ), "Select Result File", "" )
$ 选择文件
file_widget=ui_file_create(form_id,"file_select",uil_form_sizes.form_margin( 1 ),uil_form_sizes.form_margin( 3 ),uil_form_sizes.file_wid( 2 ),6,"Filter","*.xdb","Directories","Database List","Existing Database Name","","OK","Filter","Cancel")
END FUNCTION
FUNCTION display()
	 ui_form_display("File_Form")
END FUNCTION


FUNCTION file_select(pathname,type)
	 STRING pathname[],type[]
GLOBAL STRING name[100]
GLOBAL WIDGET file_id
IF(type=="CANCEL")THEN
ui_form_hide("File_Form")
ELSE
ui_wid_set(file_id,"VALUE",pathname)
ui_form_hide("File_Form")
END IF
END FUNCTION


END CLASS