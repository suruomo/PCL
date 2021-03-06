


















































































































































































































































CLASS Export_Mode


CLASSWIDE WIDGET form_id,file_button,list_id,loadBCs_toggle_id,material_toggle_id,frequency_toggle_id,@
factors_toggle_id,spcforce_toggle_id,displacement_toggle_id,apply_button,cancel_button
CLASSWIDE INTEGER in_channel,out_channel


FUNCTION init()
GLOBAL WIDGET file_id
REAL x_loc,y_loc


$ 结果集列表
STRING result_cases_names[256](50)
STRING result_cases_labels[256](50)
INTEGER result_cases_numbers


x_loc=uil_form_sizes.unframed_margin( 1 )
y_loc=uil_form_sizes.form_margin( 3 )
result_cases_numbers=0


$ 创建表单
form_id=ui_form_create("",uil_form_sizes.form_x_loc( 1 ),uil_form_sizes.form_y_loc( 1 ), "UL",uil_form_sizes.form_wid( 1 ),uil_form_sizes.form_hgt( 3 ), "Modal Analysis Result Export", "" )
$ 创建结果选择文件
file_id=ui_databox_create(form_id,"",x_loc,y_loc,0.0,uil_form_sizes.dbox_wid( 1 ),"Select *.f06:","",TRUE,"STRING",1)
y_loc+= uil_form_sizes.dbox_hgt( 1 )+ uil_form_sizes.spacing( 8 )
file_button=ui_button_create(form_id, "select_file", uil_form_sizes.button_x_loc1( 2 ), y_loc, uil_form_sizes.button_wid( 2 ), 0.,"Select File", FALSE, FALSE)
y_loc+= uil_form_sizes.dbox_hgt( 1 )
$ 输出模型信息选择项
ui_label_create(form_id,"",x_loc,y_loc,"Modal Information:")
y_loc+=uil_form_sizes.spacing( 8 )*2
ui_separator_create(form_id,"s1",x_loc,y_loc,uil_form_sizes.form_wid( 1 ),TRUE)
loadBCs_toggle_id=ui_toggle_create(form_id,"",x_loc,y_loc,"Export Load/BCs")
material_toggle_id=ui_toggle_create(form_id,"",x_loc+ 4.5*uil_form_sizes.spacing( 7 ),y_loc,"Export Material")
y_loc+= uil_form_sizes.dbox_hgt( 1 )+ uil_form_sizes.spacing( 8 )
$ 创建result cases list列表
list_id=ui_listbox_create(form_id,"",x_loc,y_loc,uil_form_sizes.dbox_wid( 1 ),result_cases_numbers,"Result Cases:","MULTIPLE",FALSE)
$ 准备组列表数据
Export_Mode.get_result_cases(result_cases_names,result_cases_labels,result_cases_numbers)


$ $ 创建列表项
ui_listbox_items_create(list_id,result_cases_names,result_cases_labels,result_cases_numbers,WIDGET_NULL)


ui_wid_set(list_id,"ROWS",10)


y_loc+= uil_form_sizes.dbox_hgt( 1 )*5+ uil_form_sizes.spacing( 8 )
$ 输出结果类型选择
ui_label_create(form_id,"",x_loc,y_loc,"Select Output Type:")
y_loc+=uil_form_sizes.spacing( 8 )*2
frequency_toggle_id=ui_toggle_create(form_id,"",x_loc,y_loc,"Modal Frequency")
factors_toggle_id=ui_toggle_create(form_id,"",x_loc+ 4*uil_form_sizes.spacing( 7 ),y_loc,"Modal Participation Factors")
y_loc+= 2*uil_form_sizes.spacing( 8 )
spcforce_toggle_id=ui_toggle_create(form_id,"",x_loc,y_loc,"SpcForce")
displacement_toggle_id=ui_toggle_create(form_id,"",x_loc+ 4*uil_form_sizes.spacing( 7 ),y_loc,"Displacemnet")
y_loc+= uil_form_sizes.dbox_hgt( 1 )+ uil_form_sizes.spacing( 8 )
$ 创建按钮
apply_button=ui_button_create(form_id, "apply", uil_form_sizes.button_x_loc1( 2 ), y_loc, uil_form_sizes.button_wid( 2 ), 0.,"Apply", FALSE, FALSE)


cancel_button=ui_button_create(form_id, "cancel", uil_form_sizes.button_x_loc1( 3 ), y_loc, uil_form_sizes.button_wid( 2 ), 0.,"Cancel", FALSE, FALSE)


END FUNCTION


FUNCTION display()
ui_form_display("Export_Mode")
END FUNCTION


$ 获取结果填充列表
FUNCTION get_result_cases(result_cases_names,result_cases_labels,result_cases_numbers)
$ 传递参数
STRING result_cases_names[]()
STRING result_cases_labels[]()
INTEGER result_cases_numbers
$ 自定义参数
INTEGER i=1,j=1,k=0,loadcase_number=0,loadcase_ids(VIRTUAL),status,loadcase_id,subcase_number,subcase_ids(VIRTUAL)
STRING loadcase_name[128],subcase_name[128],loadcase_names[128](VIRTUAL),res[300]


loadsbcs_eval_all()
$ 获取工况
IF(db_get_all_load_case_names()==0)THEN
IF(db_get_next_load_case_name(loadcase_name)==0)THEN
loadcase_number+=1
END IF
END IF
sys_allocate_array(loadcase_ids,1,loadcase_number)
sys_allocate_array(loadcase_names,1,loadcase_number)
IF(db_get_all_load_case_names()==0)THEN
IF(db_get_next_load_case_name(loadcase_name)==0)THEN
loadcase_names(i)=loadcase_name
db_get_load_case_id(loadcase_name,loadcase_id)
loadcase_ids(i)=loadcase_id
i+=1
END IF
END IF
$ 获取结果工况
FOR(i=1 TO loadcase_number)
loadcase_id=loadcase_ids(i)
loadcase_name=loadcase_names(i)
status=res_utl_get_subcases(loadcase_id,subcase_number,subcase_ids)
IF(status!=0) THEN
msg_to_form( status, 4, 0, 0, 0., "" )
ELSE
ui_write("subcase num:"//str_from_integer(subcase_number))
FOR(j=1 TO subcase_number)
res_data_get_subcase_name(loadcase_id,subcase_ids(j),subcase_name)
k+=1
res=loadcase_name//";"//subcase_name
result_cases_labels(k)=res
result_cases_names(k)=subcase_name
END FOR
END IF
END FOR
result_cases_numbers=k
END FUNCTION


FUNCTION select_file()
ui_exec_function("F06_File_Form","display")
END FUNCTION


$ 应用选择
FUNCTION apply()
GLOBAL WIDGET file_id
LOGICAL load_flag,mat_flag,frequency_flag,factors_flag,spcforce_flag,displacement_flag
INTEGER status0,status1
STRING dir[200],date[128],time[32],path_out[300],path_in[300]




$ 获取当前目录
get_current_dir(dir)
$ 初始化存放文件目录
time=sys_time()
date=sys_date()//"-"//str_token(time,":",1,FALSE)//"-"//str_token(time,":",2,FALSE)//"-"//str_token(time,":",3,FALSE)
path_out=dir//"\export-mode-result-"//date//".txt"
$ 选择结果文件
ui_wid_get(file_id,"VALUE",path_in)
IF(path_in=="")THEN
ui_write("Please select a database file!!!!")
ELSE
$ 打开文件
status0=text_open(path_out,"NWA",0,0,out_channel)
status1=text_open(path_in,"OR",0,0,in_channel)
IF(status1!=0) THEN
msg_to_form( status1, 4, 0, 0, 0., "" )
ELSE
IF(status0!=0) THEN
msg_to_form( status0, 4, 0, 0, 0., "" )
ELSE
$ 1.提取各工况载荷约束信息
ui_wid_get(loadBCs_toggle_id,"VALUE",load_flag)
IF(load_flag==TRUE)THEN
Export_Mode.export_loadBCs()
END IF
$ 2.提取模型材料信息
ui_wid_get(material_toggle_id,"VALUE",mat_flag)
IF(mat_flag==TRUE)THEN
Export_Mode.export_material()
END IF
$ 3.提取模态频率
ui_wid_get(frequency_toggle_id,"VALUE",frequency_flag)
IF(frequency_flag==TRUE)THEN
Export_Mode.export_frequency()
END IF
$ 4.提取模态参与系数
ui_wid_get(factors_toggle_id,"VALUE",factors_flag)
IF(factors_flag==TRUE)THEN
text_open(path_in,"OR",0,0,in_channel)
Export_Mode.export_factors()
END IF
$ 5.提取单点约束spcforce
ui_wid_get(spcforce_toggle_id,"VALUE",spcforce_flag)
IF(spcforce_flag==TRUE)THEN
text_open(path_in,"OR",0,0,in_channel)
Export_Mode.export_spcforce()
END IF
$ 6.提取位移
ui_wid_get(displacement_toggle_id,"VALUE",displacement_flag)
IF(displacement_flag==TRUE)THEN
text_open(path_in,"OR",0,0,in_channel)
Export_Mode.export_displacement()
END IF
$ 7.关闭并保存文件
status0=text_close (out_channel,"")
IF(status0!=0) THEN
msg_to_form( status0, 4, 0, 0, 0., "" )
ELSE
msg_to_form( status0, 1, 0, 0, 0., "Export Result Successful" )
END IF
status1=text_close (in_channel,"")
IF(status1!=0) THEN
msg_to_form( status1, 4, 0, 0, 0., "" )
ELSE
msg_to_form( status1, 1, 0, 0, 0., "" )
END IF
END IF
END IF
END IF
END FUNCTION


FUNCTION export_loadBCs()




STRING load_case_name[32],load_case_des[100],dynamic_case_name[32],type[32]
INTEGER load_case_id,load_case_type,num_loads,load_ids(32),loads_priorities(32),i
REAL evaluation_point


STRING load_name[32],load_type_string[32],application_type_string[64],elem_dimension_string[32]
INTEGER application_type_integer,load_type_integer,elem_dimension_integer,dyn_flag,coord_id
$ 存放结果
INTEGER index=1
STRING lbc_res[128](15)


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


$ ui_write("Load Case Name:"//load_case_name//"  Load Case Type:"//type//"  Num Loads:"//str_from_integer(num_loads)//"  Description:"//load_case_des)
$ 提取各工况下的载荷约束信息
FOR(i=1 TO num_loads)
db_get_lbc(load_ids(i),load_name,load_type_integer,application_type_integer,elem_dimension_integer,coord_id,dyn_flag)
load_type_string=Export_Mode.get_load_type_string(load_type_integer)
application_type_string=Export_Mode.get_application_type_string(application_type_integer)
elem_dimension_string=Export_Mode.get_elem_dimension_string(elem_dimension_integer)
$ ui_write(load_case_name//"*"//type//"*"//str_from_integer(load_ids(i))//"*"//load_name//"*"//@
$ load_type_string//"*"//application_type_string//"*"//elem_dimension_string)
lbc_res(index)=load_case_name//"*"//type//"*"//str_from_integer(load_ids(i))//"*"//load_name//"*"//@
load_type_string//"*"//application_type_string//"*"//elem_dimension_string
index+=1
END FOR
END IF
END IF
END IF
$ 测试输出结果数组到文件
text_write_string(out_channel,"-----Load/BCs Start-----")
text_write_string(out_channel,"-----loadcase name*loadcase type*load id*load name*load type*application type*element dimension-----")
INTEGER p=1
FOR(p=1 TO index-1)
text_write_string(out_channel,lbc_res(p))
END FOR
text_write_string(out_channel,"-----Load/BCs End-----")
END FUNCTION




FUNCTION export_material()
STRING material_name[64]
INTEGER material_id,cat,lin,dir,type,word_ids(VIRTUAL),field_ids(VIRTUAL),num_words,p
REAL word_values(VIRTUAL)
$ Isotropic材料属性
REAL EM,PR,SM,D,TEC,SDC,RT
$ 2D Orthotropic材料属性
REAL EM11,EM22,PR12,SM12,SM23,SM13,D1,TEC11,TEC22,SDC1,RT1
$ 保存结果
INTEGER index=1
STRING res[256],material_res[256](15)


IF(db_get_all_material_names()==0)THEN
IF(db_get_next_material_name(material_name,material_id,cat,lin,dir,type)==0)THEN
IF(cat==1)THEN
res=material_name//"*"
db_get_matl_prop_value_count(material_id,num_words)
sys_allocate_array(word_ids,1,num_words)
sys_allocate_array(field_ids,1,num_words)
sys_allocate_array(word_values,1,num_words)
db_get_matl_prop_value(material_id,word_ids,field_ids,word_values)
$ 赋值材料属性
p=mth_array_search(word_ids,2,FALSE)
IF(p!=0)THEN
IF(field_ids(p)==0)THEN
EM=word_values(p)
res=res//"Elastic Modulus:"//str_from_real(EM)//","
END IF
END IF
p=mth_array_search(word_ids,5,FALSE)
IF(p!=0)THEN
IF(field_ids(p)==0)THEN
PR=word_values(p)
res=res//"Possion Ratio:"//str_from_real(PR)//","
END IF
END IF
p=mth_array_search(word_ids,8,FALSE)
IF(p!=0)THEN
IF(field_ids(p)==0)THEN
SM=word_values(p)
res=res//"Shear Modulus:"//str_from_real(SM)//","
END IF
END IF
p=mth_array_search(word_ids,16,FALSE)
IF(p!=0)THEN
IF(field_ids(p)==0)THEN
D=word_values(p)
res=res//"Density:"//str_from_real(D)//","
END IF
END IF
p=mth_array_search(word_ids,24,FALSE)
IF(p!=0)THEN
IF(field_ids(p)==0)THEN
TEC=word_values(p)
res=res//"Thermal Expan Coeff:"//str_from_real(TEC)//","
END IF
END IF
p=mth_array_search(word_ids,30,FALSE)
IF(p!=0)THEN
IF(field_ids(p)==0)THEN
SDC=word_values(p)
res=res//"Structural Damping Coeff:"//str_from_real(SDC)//","
END IF
END IF
p=mth_array_search(word_ids,1,FALSE)
IF(p!=0)THEN
IF(field_ids(p)==0)THEN
RT=word_values(p)
res=res//"Reference Temperature:"//str_from_real(RT)//","
END IF
END IF
material_res(index)=res
index+=1
ELSE IF(cat==5)THEN
res=""
db_get_matl_prop_value_count(material_id,num_words)
sys_allocate_array(word_ids,1,num_words)
sys_allocate_array(field_ids,1,num_words)
sys_allocate_array(word_values,1,num_words)
db_get_matl_prop_value(material_id,word_ids,field_ids,word_values)


$ 赋值材料属性
p=mth_array_search(word_ids,2,FALSE)
IF(p!=0)THEN
IF(field_ids(p)==0)THEN
EM11=word_values(p)
res=res//"Elastic Modulus 11:"//str_from_real(EM11)//","
END IF
END IF
p=mth_array_search(word_ids,5,FALSE)
IF(p!=0)THEN
IF(field_ids(p)==0)THEN
EM22=word_values(p)
res=res//"Elastic Modulus 22:"//str_from_real(EM22)//","
END IF
END IF
p=mth_array_search(word_ids,8,FALSE)
IF(p!=0)THEN
IF(field_ids(p)==0)THEN
PR12=word_values(p)
res=res//"Possion Ratio 12:"//str_from_real(PR12)//","
END IF
END IF
p=mth_array_search(word_ids,16,FALSE)
IF(p!=0)THEN
IF(field_ids(p)==0)THEN
SM12=word_values(p)
res=res//"Shear Modulus 12:"//str_from_real(SM12)//","
END IF
END IF
p=mth_array_search(word_ids,24,FALSE)
IF(p!=0)THEN
IF(field_ids(p)==0)THEN
SM23=word_values(p)
res=res//"Shear Modulus 23:"//str_from_real(SM23)//","
END IF
END IF
p=mth_array_search(word_ids,30,FALSE)
IF(p!=0)THEN
IF(field_ids(p)==0)THEN
SM13=word_values(p)
res=res//"Shear Modulus 13:"//str_from_real(SM13)//","
END IF
END IF
p=mth_array_search(word_ids,1,FALSE)
IF(p!=0)THEN
IF(field_ids(p)==0)THEN
D1=word_values(p)
res=res//"Density:"//str_from_real(D1)//","
END IF
END IF
p=mth_array_search(word_ids,1,FALSE)
IF(p!=0)THEN
IF(field_ids(p)==0)THEN
TEC11=word_values(p)
res=res//"Thermal Expan Coeff 11:"//str_from_real(TEC11)//","
END IF
END IF
p=mth_array_search(word_ids,1,FALSE)
IF(p!=0)THEN
IF(field_ids(p)==0)THEN
TEC22=word_values(p)
res=res//"Thermal Expan Coeff 22:"//str_from_real(TEC22)//","
END IF
END IF
p=mth_array_search(word_ids,1,FALSE)
IF(p!=0)THEN
IF(field_ids(p)==0)THEN
SDC1=word_values(p)
res=res//"Structural Damping Coeff:"//str_from_real(SDC1)//","
END IF
END IF
p=mth_array_search(word_ids,1,FALSE)
IF(p!=0)THEN
IF(field_ids(p)==0)THEN
RT1=word_values(p)
res=res//"Reference Temperature:"//str_from_real(RT1)//","
END IF
END IF
material_res(index)=res
index+=1
END IF
END IF
END IF
$ 测试输出结果数组到文件
text_write_string(out_channel,"-----Material Start-----")
text_write_string(out_channel,"-----material name*info-----")
INTEGER o=1
FOR(o=1 TO index-1)
text_write_string(out_channel,material_res(o))
END FOR
text_write_string(out_channel,"-----Material End-----")
END FUNCTION




FUNCTION export_frequency()
INTEGER str_length,index,status
STRING str[500]


$ 在.f06文件中找到模态频率结果写入结果文件中
WHILE(TRUE)
status=text_read_string(in_channel,str,str_length)
IF(status<0) THEN
BREAK
ELSE IF(status>0)THEN
msg_to_form( status, 4, 0, 0, 0., "" )
ELSE
index=str_index(str,"R E A L   E I G E N V A L U E S")
IF(index!=0)THEN
text_write_string(out_channel,"-----Modal Frequency Start-----")
text_write_string(out_channel,str)
WHILE(text_read_string(in_channel,str,str_length)==0)
index=str_index(str,"MSC Nastran")
IF(index==0)THEN
text_write_string(out_channel,str)
ELSE
BREAK
END IF
END WHILE
text_write_string(out_channel,"-----Modal Frequency End-----")
BREAK
END IF
END IF
END WHILE
END FUNCTION




FUNCTION export_factors()
INTEGER str_length,index,status
STRING str[500]


$ 在.f06文件中找到模态参与系数结果写入结果文件中
WHILE(TRUE)
status=text_read_string(in_channel,str,str_length)
IF(status<0) THEN
BREAK
ELSE IF(status>0)THEN
msg_to_form( status, 4, 0, 0, 0., "" )
ELSE
index=str_index(str,"MODAL PARTICIPATION FACTORS")
IF(index!=0)THEN
text_write_string(out_channel,"-----Modal Participation Factors Start-----")
text_write_string(out_channel,str)
WHILE(text_read_string(in_channel,str,str_length)==0)
index=str_index(str,"TOTAL")
IF(index==0)THEN
text_write_string(out_channel,str)
ELSE
BREAK
END IF
END WHILE
text_write_string(out_channel,"-----Modal Participation Factors End-----")
BREAK
END IF
END IF
END WHILE
END FUNCTION




FUNCTION export_spcforce()
INTEGER str_length,index,status
STRING str[500]
$ 在.f06文件中找到结果写入结果文件中
WHILE(TRUE)
status=text_read_string(in_channel,str,str_length)
IF(status<0) THEN
BREAK
ELSE IF(status>0)THEN
msg_to_form( status, 4, 0, 0, 0., "" )
ELSE
index=str_index(str,"MAXIMUM  SPCFORCES")
IF(index!=0)THEN
text_write_string(out_channel,"-----SpcForces Start-----")
text_write_string(out_channel,str)
WHILE(text_read_string(in_channel,str,str_length)==0)
index=str_index(str,"Nastran")
IF(index==0)THEN
text_write_string(out_channel,str)
ELSE
$ text_write_string(out_channel,str)
BREAK
END IF
END WHILE
text_write_string(out_channel,"-----SpcForces End-----")
BREAK
END IF
END IF
END WHILE
END FUNCTION




FUNCTION export_displacement()
INTEGER str_length,index,status
STRING str[500]
$ 在.f06文件中找到结果写入结果文件中
WHILE(TRUE)
status=text_read_string(in_channel,str,str_length)
IF(status<0) THEN
BREAK
ELSE IF(status>0)THEN
msg_to_form( status, 4, 0, 0, 0., "" )
ELSE
index=str_index(str,"MAXIMUM  DISPLACEMENTS")
IF(index!=0)THEN
text_write_string(out_channel,"-----Max Displacement Start-----")
text_write_string(out_channel,str)
WHILE(text_read_string(in_channel,str,str_length)==0)
index=str_index(str,"astran")
IF(index==0)THEN
text_write_string(out_channel,str)
ELSE
$ text_write_string(out_channel,str)
BREAK
END IF
END WHILE
text_write_string(out_channel,"-----Max Displacement End-----")
BREAK
END IF
END IF
END WHILE
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
STRING application_type_string[64]
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


FUNCTION get_elem_dimension_string(elem_dimension_integer)
INTEGER elem_dimension_integer
STRING elem_dimension_string[32]
SWITCH(elem_dimension_integer)
CASE(1)
elem_dimension_string="line elements"
CASE(2)
elem_dimension_string="surface elements"
CASE(3)
elem_dimension_string="solid elements"
DEFAULT
elem_dimension_string="node"
END SWITCH
RETURN elem_dimension_string
END FUNCTION


FUNCTION cancel()
ui_form_hide("Export_Mode")
END FUNCTION


END CLASS


CLASS F06_File_Form


CLASSWIDE WIDGET form_id,file_widget


FUNCTION init()
REAL x_loc,y_loc


x_loc=uil_form_sizes.unframed_margin( 1 )
y_loc=uil_form_sizes.form_margin( 3 )


$ 创建表单
form_id=ui_form_create("",uil_form_sizes.form_x_loc( 11 ),uil_form_sizes.form_y_loc( 2 ), "UL",uil_form_sizes.form_wid( 2 ),uil_form_sizes.form_hgt( 3 ), "Select Result File", "" )
$ 选择文件
file_widget=ui_file_create(form_id,"file_select",uil_form_sizes.form_margin( 1 ),uil_form_sizes.form_margin( 3 ),uil_form_sizes.file_wid( 2 ),6,"Filter",@
"*.f06","Directories","Database List","Existing Database Name","","OK","Filter","Cancel")
END FUNCTION


FUNCTION display()
	 ui_form_display("F06_File_Form")
END FUNCTION


FUNCTION file_select(pathname,type)
	 STRING pathname[],type[]
GLOBAL WIDGET file_id
IF(type=="CANCEL")THEN
ui_form_hide("F06_File_Form")
ELSE
ui_wid_set(file_id,"VALUE",pathname)
ui_form_hide("F06_File_Form")
END IF
END FUNCTION


END CLASS