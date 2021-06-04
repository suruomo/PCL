


















































































































































































































































CLASS Export_Static


CLASSWIDE WIDGET form_id,loadBCs_toggle_id,material_toggle_id,file_button,list_id,apply_button,cancel_button


CLASSWIDE STRING group_names[100](VIRTUAL)


CLASSWIDE STRING group_labels[100](VIRTUAL)


CLASSWIDE INTEGER group_numbers


FUNCTION init()
GLOBAL WIDGET file_id
REAL x_loc,y_loc
INTEGER i
STRING name[100]




x_loc=uil_form_sizes.unframed_margin( 1 )
y_loc=uil_form_sizes.form_margin( 3 )
group_numbers=0


$ 创建表单
form_id=ui_form_create("",uil_form_sizes.form_x_loc( 1 ),uil_form_sizes.form_y_loc( 1 ), "UL",uil_form_sizes.form_wid( 1 ),uil_form_sizes.form_hgt( 3 ), "Static Analysis Result Export", "" )
$ 创建选择文件
file_id=ui_databox_create(form_id,"",x_loc,y_loc,0.0,uil_form_sizes.dbox_wid( 1 ),"Select *.xdb:","",TRUE,"STRING",1)
y_loc+= uil_form_sizes.dbox_hgt( 1 )+ uil_form_sizes.spacing( 8 )
file_button=ui_button_create(form_id, "select_file", uil_form_sizes.button_x_loc1( 2 ), y_loc, uil_form_sizes.button_wid( 2 ), 0.,"Select File", FALSE, FALSE)
y_loc+= uil_form_sizes.dbox_hgt( 1 )
$ 创建选择项
ui_label_create(form_id,"",x_loc,y_loc,"Model Information:")
y_loc+=uil_form_sizes.spacing( 8 )*2
ui_separator_create(form_id,"s1",x_loc,y_loc,uil_form_sizes.form_wid( 1 ),TRUE)
loadBCs_toggle_id=ui_toggle_create(form_id,"",x_loc,y_loc,"Export Load/BCs")
material_toggle_id=ui_toggle_create(form_id,"",x_loc+ 4.5*uil_form_sizes.spacing( 7 ),y_loc,"Export Material")
y_loc+= uil_form_sizes.dbox_hgt( 1 )+ uil_form_sizes.spacing( 8 )
$ 创建list列表
list_id=ui_listbox_create(form_id,"",x_loc,y_loc,uil_form_sizes.dbox_wid( 1 ),group_numbers,"Select Group:","MULTIPLE",FALSE)
$ 准备组列表数据
FOR(i=1 TO 5000)
IF(db_get_group_name(i,name)==0)THEN
group_numbers=group_numbers+1
END IF
END FOR


sys_allocate_array(group_names,1,group_numbers)
sys_allocate_array(group_labels,1,group_numbers)


FOR(i=1 TO group_numbers)
db_get_group_name(i,name)
group_names(i)=name
group_labels(i)=name
END FOR


$ 创建列表项
ui_listbox_items_create(list_id,group_names,group_labels,group_numbers,WIDGET_NULL)


ui_wid_set(list_id,"ROWS",10)


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
LOGICAL flag
ui_wid_get(loadBCs_toggle_id,"VALUE",flag)
IF(flag==TRUE)THEN
Export_Static.export_loadBCs()
END IF


END FUNCTION




FUNCTION export_loadBCs()




STRING load_case_name[32],load_case_des[100],dynamic_case_name[32],type[32]
INTEGER load_case_id,load_case_type,num_loads,load_ids(32),loads_priorities(32),i
REAL evaluation_point


STRING load_name[32],load_type_string[32],application_type_string[32]
INTEGER application_type_integer,load_type_integer,target_elem_dim,dyn_flag,coord_id


loadsbcs_eval_all()


IF(db_get_all_load_case_names()==0)THEN
IF(db_get_next_load_case_name(load_case_name)==0)THEN
$ 提取各工况
IF(db_get_load_case(load_case_name,load_case_id,load_case_type,load_case_des,num_loads,load_ids,@
dynamic_case_name,evaluation_point,loads_priorities)==0)THEN
$ 工况类型
IF(load_case_type==1)THEN
type="Static"
ELSE IF(load_case_type==2)THEN
type="Time Dependent"
ELSE
type="Frequency Dependent"
END IF


ui_write("Load Case Name:"//load_case_name//"  Load Case Type:"//type//"  Num Loads:"//str_from_integer(num_loads)//"  Description:"//load_case_des)
$ 提取各工况下的载荷约束信息
FOR(i=1 TO num_loads)
db_get_lbc(load_ids(i),load_name,load_type_integer,application_type_integer,target_elem_dim,coord_id,dyn_flag)
load_type_string=Export_Static.get_load_type_string(load_type_integer)
application_type_string=Export_Static.get_application_type_string(application_type_integer)
ui_write(load_case_name//"*"//type//"*"//str_from_integer(load_ids(i))//"*"//load_name//"*"//@
load_type_string//"*"//application_type_string)
END FOR
END IF
END IF
END IF
END FUNCTION


FUNCTION get_load_type_string(load_type_integer)
INTEGER load_type_integer
STRING load_type_string[32]
SWITCH(load_type_integer)
CASE(6)
load_type_string="Displacement"
CASE(7)
load_type_string="Forces"
CASE(8)
load_type_string="Pressure"
END SWITCH
RETURN load_type_string
END FUNCTION


FUNCTION get_application_type_string(application_type_integer)
INTEGER application_type_integer
STRING application_type_string[32]
SWITCH(application_type_integer)
CASE(1)
application_type_string="nodes"
CASE(2)
application_type_string="elements and constant over the element"
CASE(3)
application_type_string="elements and varying over the element"
END SWITCH
RETURN application_type_string
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
file_widget=ui_file_create(form_id,"file_select",uil_form_sizes.form_margin( 1 ),uil_form_sizes.form_margin( 3 ),uil_form_sizes.file_wid( 2 ),6,"Filter",@
"*.xdb","Directories","Database List","Existing Database Name","","OK","Filter","Cancel")
END FUNCTION
FUNCTION display()
	 ui_form_display("File_Form")
END FUNCTION


FUNCTION file_select(pathname,type)
	 STRING pathname[],type[]
GLOBAL WIDGET file_id
IF(type=="CANCEL")THEN
ui_form_hide("File_Form")
ELSE
ui_wid_set(file_id,"VALUE",pathname)
ui_form_hide("File_Form")
END IF
END FUNCTION


END CLASS