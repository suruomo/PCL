


















































































































































































































































CLASS Export_Static


CLASSWIDE WIDGET form_id,file_button,list_id,loadBCs_toggle_id,material_toggle_id,constraintforces_toggle_id,displacement_toggle_id,@
stress_toggle_id,strain_toggle_id,apply_button,cancel_button
CLASSWIDE INTEGER file_channel


FUNCTION init()
GLOBAL WIDGET file_id
REAL x_loc,y_loc
INTEGER i
STRING name[100]
STRING group_names[100](VIRTUAL)
STRING group_labels[100](VIRTUAL)
INTEGER group_numbers


x_loc=uil_form_sizes.unframed_margin( 1 )
y_loc=uil_form_sizes.form_margin( 3 )
group_numbers=0


$ 创建表单
form_id=ui_form_create("",uil_form_sizes.form_x_loc( 1 ),uil_form_sizes.form_y_loc( 1 ), "UL",uil_form_sizes.form_wid( 1 ),uil_form_sizes.form_hgt( 3 ), "Static Analysis Result Export", "" )
$ 创建结果选择文件
file_id=ui_databox_create(form_id,"",x_loc,y_loc,0.0,uil_form_sizes.dbox_wid( 1 ),"Select *.xdb:","",TRUE,"STRING",1)
y_loc+= uil_form_sizes.dbox_hgt( 1 )+ uil_form_sizes.spacing( 8 )
file_button=ui_button_create(form_id, "select_file", uil_form_sizes.button_x_loc1( 2 ), y_loc, uil_form_sizes.button_wid( 2 ), 0.,"Select File", FALSE, FALSE)
y_loc+= uil_form_sizes.dbox_hgt( 1 )
$ 输出模型信息选择项
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


y_loc+= uil_form_sizes.dbox_hgt( 1 )*5+ uil_form_sizes.spacing( 8 )
$ 输出结果类型选择
ui_label_create(form_id,"",x_loc,y_loc,"Select Output Type:")
y_loc+=uil_form_sizes.spacing( 8 )*2
constraintforces_toggle_id=ui_toggle_create(form_id,"",x_loc,y_loc,"Constraint Forces")
displacement_toggle_id=ui_toggle_create(form_id,"",5.5*uil_form_sizes.spacing( 7 ),y_loc,"Displacement")
y_loc+= 2*uil_form_sizes.spacing( 8 )
stress_toggle_id=ui_toggle_create(form_id,"",x_loc,y_loc,"Stress")
strain_toggle_id=ui_toggle_create(form_id,"",x_loc+ 5*uil_form_sizes.spacing( 7 ),y_loc,"Strain")
y_loc+= uil_form_sizes.dbox_hgt( 1 )+ uil_form_sizes.spacing( 8 )
$ 创建按钮
apply_button=ui_button_create(form_id, "apply", uil_form_sizes.button_x_loc1( 2 ), y_loc, uil_form_sizes.button_wid( 2 ), 0.,"Apply", FALSE, FALSE)


cancel_button=ui_button_create(form_id, "cancel", uil_form_sizes.button_x_loc1( 3 ), y_loc, uil_form_sizes.button_wid( 2 ), 0.,"Cancel", FALSE, FALSE)


END FUNCTION


FUNCTION display()
ui_form_display("Export_Static")
END FUNCTION


FUNCTION select_file()
ui_exec_function("XDB_File_Form","display")
END FUNCTION


$ 应用选择
FUNCTION apply()
GLOBAL WIDGET file_id
LOGICAL load_flag,mat_flag,displacement_flag,constrainforces_flag,stress_flag,strain_flag
INTEGER status
STRING dir[200],date[128],time[32],path[300],database_name[256]
$ 获取当前目录
get_current_dir(dir)
$ 初始化存放文件目录
time=sys_time()
date=sys_date()//"-"//str_token(time,":",1,FALSE)//"-"//str_token(time,":",2,FALSE)//"-"//str_token(time,":",3,FALSE)
path=dir//"\export-static-result-"//date//".txt"
$ 选择结果文件
ui_wid_get(file_id,"VALUE",database_name)
IF(database_name=="")THEN
ui_write("Please select a database file!!!!")
ELSE
$ 打开文件
status=text_open(path,"NWA",0,0,file_channel)
IF(status!=0) THEN
msg_to_form( status, 4, 0, 0, 0., "" )
ELSE
$ 1.提取各工况载荷约束信息
ui_wid_get(loadBCs_toggle_id,"VALUE",load_flag)
IF(load_flag==TRUE)THEN
Export_Static.export_loadBCs()
END IF
$ 2.提取模型材料信息
ui_wid_get(material_toggle_id,"VALUE",mat_flag)
IF(mat_flag==TRUE)THEN
Export_Static.export_material()
END IF
$ 3.提取选中组的各工况的位移信息
ui_wid_get(displacement_toggle_id,"VALUE",displacement_flag)
IF(displacement_flag==TRUE)THEN
Export_Static.export_displacement()
END IF
$ 4.提取选中组的各工况的约束力信息
ui_wid_get(constraintforces_toggle_id,"VALUE",constrainforces_flag)
IF(constrainforces_flag==TRUE)THEN
Export_Static.export_constrainforces()
END IF
$ 5.提取选中组的各工况的应力信息
ui_wid_get(stress_toggle_id,"VALUE",stress_flag)
IF(stress_flag==TRUE)THEN
Export_Static.export_stress()
END IF
$ 6.提取选中组的各工况的应变信息
ui_wid_get(strain_toggle_id,"VALUE",strain_flag)
IF(strain_flag==TRUE)THEN
Export_Static.export_strain()
END IF
$ 7.关闭并保存文件
status=text_close (file_channel,"" )
IF(status!=0) THEN
msg_to_form( status, 4, 0, 0, 0., "" )
ELSE
msg_to_form( status, 1, 0, 0, 0., "Export Result Successful" )
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
load_type_string=Export_Static.get_load_type_string(load_type_integer)
application_type_string=Export_Static.get_application_type_string(application_type_integer)
elem_dimension_string=Export_Static.get_elem_dimension_string(elem_dimension_integer)
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
text_write_string(file_channel,"-----Load/BCs Start-----")
text_write_string(file_channel,"-----loadcase name*loadcase type*load id*load name*load type*application type*element dimension-----")
INTEGER p=1
FOR(p=1 TO index-1)
text_write_string(file_channel,lbc_res(p))
END FOR
text_write_string(file_channel,"-----Load/BCs End-----")
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
text_write_string(file_channel,"-----Material Start-----")
text_write_string(file_channel,"-----material name*info-----")
INTEGER o=1
FOR(o=1 TO index-1)
text_write_string(file_channel,material_res(o))
END FOR
text_write_string(file_channel,"-----Material End-----")
END FUNCTION




FUNCTION export_displacement()
$ 定义组和工况变量
INTEGER groups_selected_number,group_ids(VIRTUAL),group_id,loadcase_number,loadcase_id,loadcase_ids(VIRTUAL),i,status,j,k,g,l,m,s
STRING group_name[32],group_names[32](VIRTUAL),loadcase_name[32],loadcase_names[32](VIRTUAL)
$ 定义子工况变量
INTEGER subcase_number,subcase_ids(VIRTUAL)
$ 定义位移变量
INTEGER displacement_number=4
STRING displacement_labels[5](4)
displacement_labels(1)="XX"
displacement_labels(2)="YY"
displacement_labels(3)="ZZ"
displacement_labels(4)="MAG"
$ 定义提取结果相关变量
INTEGER num_elems,results_ids(5),data_type,resloc,nres,ids(VIRTUAL),nresults(VIRTUAL),minloc(12),maxloc(12),primary_id,secondary_id,primary_ids(VIRTUAL),secondary_ids(VIRTUAL),results_number,layer_number,layer_ids(VIRTUAL)
STRING elem_list[50000],avg_method[20],avg_domain[20],extrap_method[20],complex_form[10],layer_labels[80](VIRTUAL),@
subcase_name[31],location[3]
REAL complex_angle,results(VIRTUAL)
$ 存放结果数组
INTEGER index,number
STRING min_res[128],max_res[128],translational_min[128](VIRTUAL),translational_max[128](VIRTUAL),rotational_min[128](VIRTUAL),rotational_max[128](VIRTUAL)
$ 初始化部分结果变量
avg_method="DeriveAverage"
avg_domain="All"
extrap_method="ShapeFunc"
complex_form=""
complex_angle=0.0
location="N"


ui_wid_get(list_id,"NSELECTED",groups_selected_number)
IF(groups_selected_number==0)THEN
xf_error_start("Please select one group at least!")
xf_error_end()
ELSE
$ 1.获取组
sys_allocate_array(group_ids,1,groups_selected_number)
sys_allocate_array(group_names,1,groups_selected_number)
FOR(i=1 TO groups_selected_number)
db_get_group_name(i,group_name)
group_names(i)=group_name
db_get_group_id(group_name,group_id)
group_ids(i)=group_id
END FOR
loadsbcs_eval_all()
$ 2.获取工况
i=1
IF(db_get_all_load_case_names()==0)THEN
IF(db_get_next_load_case_name(loadcase_name)==0)THEN
loadcase_number+=1
END IF
END IF
sys_allocate_array(loadcase_ids,1,loadcase_number)
sys_allocate_array(loadcase_names,1,loadcase_number)
$ ui_write("---------------------------------load case start")
IF(db_get_all_load_case_names()==0)THEN
IF(db_get_next_load_case_name(loadcase_name)==0)THEN
loadcase_names(i)=loadcase_name
db_get_load_case_id(loadcase_name,loadcase_id)
loadcase_ids(i)=loadcase_id
$ ui_write("loadcase name:"//loadcase_name//"   loadcase id:"//str_from_integer(loadcase_id))
i+=1
END IF
END IF
$ ui_write("---------------------------------load case end")
$ 3.遍历每组，每个工况下的子工况位移结果
FOR(g=1 TO groups_selected_number)
group_id=group_ids(g)
group_name=group_names(g)
Export_Static.get_elem_list(group_id,group_name,elem_list,num_elems)
$ 遍历
FOR(l=1 TO loadcase_number)
loadcase_id=loadcase_ids(l)
status=res_utl_get_subcases(loadcase_id,subcase_number,subcase_ids)
IF(status!=0) THEN
msg_to_form( status, 4, 0, 0, 0., "" )
ELSE
ui_write("subcase num:"//str_from_integer(subcase_number))
$ 获取结果
status=res_utl_get_result_ids(loadcase_number,loadcase_ids,subcase_ids,results_number,primary_ids,secondary_ids)
IF(status!=0) THEN
msg_to_form( status, 4, 0, 0, 0., "" )
ELSE


$ 遍历子工况-----Displacements Translational
ui_write("---------------------------------Displacements Translational Start")
FOR(k=1 TO subcase_number)
db_get_sub_case_title(loadcase_id,subcase_ids(k),subcase_name)
db_get_primary_res_id("Displacements",primary_id)
db_get_secondary_res_id(primary_id,"Translational",secondary_id)
results_ids(1)=loadcase_id
results_ids(2)=subcase_ids(k)
results_ids(3)=primary_id
results_ids(4)=secondary_id
status=res_utl_get_result_layers(results_ids,layer_number,layer_ids,layer_labels)
IF(status!=0) THEN
msg_to_form( status, 4, 0, 0, 0., "" )
ELSE
$ 初始化结果数组
number=groups_selected_number*loadcase_number*subcase_number*layer_number
index=1
min_res=""
max_res=""
sys_allocate_array(translational_min,1,number)
sys_allocate_array(translational_max,1,number)
$ 遍历每个位移值
FOR(m=1 TO layer_number)
FOR(s=1 TO displacement_number)
results_ids(5)=layer_ids(m)
status=res_utl_extract_elem_results2(results_ids,elem_list,displacement_labels(s),location,@
"",avg_method,avg_domain,extrap_method,complex_form,complex_angle,data_type,@
resloc,nres,ids,nresults,results,minloc,maxloc)
IF(status!=0) THEN
msg_to_form( status, 4, 0, 0, 0., "" )
ELSE


j = minloc(1)
ui_writec(" Group:%s,LoadCase:%s,SubCase:%s,layer:%s,Min Id= %d,%s= %g", group_name,loadcase_names(l),subcase_name,layer_labels(m),ids(j), displacement_labels(s), results(j) )
min_res=min_res//str_from_real(results(j))//"*"
j = maxloc(1)
ui_writec(" Group:%s,Loadcase:%s,subcase:%s,layer:%s,Max Id= %d,%s= %g", group_name,loadcase_names(l),subcase_name,layer_labels(m),ids(j), displacement_labels(s),results(j) )
max_res=max_res//str_from_real(results(j))//"*"
END IF
END FOR
translational_min(index)=group_name//"*"//loadcase_names(l)//"*"//subcase_name//"*"//layer_labels(m)//"*"//str_token(min_res,"*",1,FALSE)//"*"//@
str_token(min_res,"*",2,FALSE)//"*"//str_token(min_res,"*",3,FALSE)//"*"//str_token(min_res,"*",4,FALSE)
translational_max(index)=group_name//"*"//loadcase_names(l)//"*"//subcase_name//"*"//layer_labels(m)//"*"//str_token(max_res,"*",1,FALSE)//"*"//@
str_token(max_res,"*",2,FALSE)//"*"//str_token(max_res,"*",3,FALSE)//"*"//str_token(max_res,"*",4,FALSE)
index+=1
END FOR
$ 测试输出结果数组到文件
text_write_string(file_channel,"-----Displacements Translational Min Start-----")
text_write_string(file_channel,"-----group name*loadcase name*subcase name*layer name*XX*YY*ZZ*MAG-----")
INTEGER p
FOR(p=1 TO number)
text_write_string(file_channel,translational_min(p))
END FOR
text_write_string(file_channel,"-----Displacements Translational Min End-----")
text_write_string(file_channel,"-----Displacements Translational Max Start-----")
text_write_string(file_channel,"-----group name*loadcase name*subcase name*layer name*XX*YY*ZZ*MAG-----")
FOR(p=1 TO number)
text_write_string(file_channel,translational_max(p))
END FOR
text_write_string(file_channel,"-----Displacements Translational Max End-----")
END IF
END FOR
ui_write("---------------------------------Displacements Translational END")
$ 遍历子工况-----Displacements Rotational
ui_write("---------------------------------Displacements Rotational Start")
FOR(k=1 TO subcase_number)
db_get_sub_case_title(loadcase_id,subcase_ids(k),subcase_name)
db_get_primary_res_id("Displacements",primary_id)
db_get_secondary_res_id(primary_id,"Rotational",secondary_id)
results_ids(1)=loadcase_id
results_ids(2)=subcase_ids(k)
results_ids(3)=primary_id
results_ids(4)=secondary_id
status=res_utl_get_result_layers(results_ids,layer_number,layer_ids,layer_labels)
IF(status!=0) THEN
msg_to_form( status, 4, 0, 0, 0., "" )
ELSE
$ 初始化结果数组
number=groups_selected_number*loadcase_number*subcase_number*layer_number
index=1
min_res=""
max_res=""
sys_allocate_array(rotational_min,1,number)
sys_allocate_array(rotational_max,1,number)
$ 遍历每个位移值
FOR(m=1 TO layer_number)
FOR(s=1 TO displacement_number)
results_ids(5)=layer_ids(m)
status=res_utl_extract_elem_results2(results_ids,elem_list,displacement_labels(s),location,@
"",avg_method,avg_domain,extrap_method,complex_form,complex_angle,data_type,@
resloc,nres,ids,nresults,results,minloc,maxloc)
IF(status!=0) THEN
msg_to_form( status, 4, 0, 0, 0., "" )
ELSE


j = minloc(1)
ui_writec(" Group:%s,LoadCase:%s,SubCase:%s,layer:%s,Min Id= %d,%s= %g", group_name,loadcase_names(l),subcase_name,layer_labels(m),ids(j), displacement_labels(s), results(j) )
min_res=min_res//str_from_real(results(j))//"*"
j = maxloc(1)
ui_writec(" Group:%s,Loadcase:%s,subcase:%s,layer:%s,Max Id= %d,%s= %g", group_name,loadcase_names(l),subcase_name,layer_labels(m),ids(j), displacement_labels(s),results(j) )
max_res=max_res//str_from_real(results(j))//"*"
END IF
END FOR
rotational_min(index)=group_name//"*"//loadcase_names(l)//"*"//subcase_name//"*"//layer_labels(m)//"*"//str_token(min_res,"*",1,FALSE)//"*"//@
str_token(min_res,"*",2,FALSE)//"*"//str_token(min_res,"*",3,FALSE)//"*"//str_token(min_res,"*",4,FALSE)
rotational_max(index)=group_name//"*"//loadcase_names(l)//"*"//subcase_name//"*"//layer_labels(m)//"*"//str_token(max_res,"*",1,FALSE)//"*"//@
str_token(max_res,"*",2,FALSE)//"*"//str_token(max_res,"*",3,FALSE)//"*"//str_token(max_res,"*",4,FALSE)
index+=1
END FOR
$ 测试输出结果数组到文件
text_write_string(file_channel,"-----Displacements Rotational Min Start-----")
text_write_string(file_channel,"-----group name*loadcase name*subcase name*layer name*XX*YY*ZZ*MAG-----")
FOR(p=1 TO number)
text_write_string(file_channel,rotational_min(p))
END FOR
text_write_string(file_channel,"-----Displacements Rotational Min End-----")
text_write_string(file_channel,"-----Displacements Rotational Max Start-----")
text_write_string(file_channel,"-----group name*loadcase name*subcase name*layer name*XX*YY*ZZ*MAG-----")
FOR(p=1 TO number)
text_write_string(file_channel,rotational_max(p))
END FOR
text_write_string(file_channel,"-----Displacements Rotational Max End-----")
END IF
END FOR
ui_write("---------------------------------Displacements Rotational END")
END IF
END IF
END FOR
END FOR
END IF
END FUNCTION




FUNCTION export_constrainforces()
$ 定义组和工况变量
INTEGER groups_selected_number,group_ids(VIRTUAL),group_id,loadcase_number,loadcase_id,loadcase_ids(VIRTUAL),i,status,j,k,g,l,m,s
STRING group_name[32],group_names[32](VIRTUAL),loadcase_name[32],loadcase_names[32](VIRTUAL)
$ 定义子工况变量
INTEGER subcase_number,subcase_ids(VIRTUAL)
$ 定义约束力变量
INTEGER constrainforces_number=4
STRING constrainforces_labels[5](4)
constrainforces_labels(1)="XX"
constrainforces_labels(2)="YY"
constrainforces_labels(3)="ZZ"
constrainforces_labels(4)="MAG"
$ 定义提取结果相关变量
INTEGER num_elems,results_ids(5),data_type,resloc,nres,ids(VIRTUAL),nresults(VIRTUAL),minloc(12),maxloc(12),primary_id,secondary_id,primary_ids(VIRTUAL),secondary_ids(VIRTUAL),results_number,layer_number,layer_ids(VIRTUAL)
STRING elem_list[50000],avg_method[20],avg_domain[20],extrap_method[20],complex_form[10],layer_labels[80](VIRTUAL),@
subcase_name[31],location[3]
REAL complex_angle,results(VIRTUAL)
$ 存放结果数组
INTEGER index,number
STRING min_res[128],max_res[128],translational_min[128](VIRTUAL),translational_max[128](VIRTUAL),rotational_min[128](VIRTUAL),rotational_max[128](VIRTUAL)
$ 初始化部分结果变量
avg_method="DeriveAverage"
avg_domain="All"
extrap_method="ShapeFunc"
complex_form=""
complex_angle=0.0
location="N"


ui_wid_get(list_id,"NSELECTED",groups_selected_number)
IF(groups_selected_number==0)THEN
xf_error_start("Please select one group at least!")
xf_error_end()
ELSE
$ 1.获取组
sys_allocate_array(group_ids,1,groups_selected_number)
sys_allocate_array(group_names,1,groups_selected_number)
FOR(i=1 TO groups_selected_number)
db_get_group_name(i,group_name)
group_names(i)=group_name
db_get_group_id(group_name,group_id)
group_ids(i)=group_id
END FOR
loadsbcs_eval_all()
$ 2.获取工况
i=1
IF(db_get_all_load_case_names()==0)THEN
IF(db_get_next_load_case_name(loadcase_name)==0)THEN
loadcase_number+=1
END IF
END IF
sys_allocate_array(loadcase_ids,1,loadcase_number)
sys_allocate_array(loadcase_names,1,loadcase_number)
$ ui_write("---------------------------------load case start")
IF(db_get_all_load_case_names()==0)THEN
IF(db_get_next_load_case_name(loadcase_name)==0)THEN
loadcase_names(i)=loadcase_name
db_get_load_case_id(loadcase_name,loadcase_id)
loadcase_ids(i)=loadcase_id
$ ui_write("loadcase name:"//loadcase_name//"   loadcase id:"//str_from_integer(loadcase_id))
i+=1
END IF
END IF
$ ui_write("---------------------------------load case end")
$ 3.遍历每组，每个工况下的子工况位移结果
FOR(g=1 TO groups_selected_number)
group_id=group_ids(g)
group_name=group_names(g)
Export_Static.get_elem_list(group_id,group_name,elem_list,num_elems)
$ 遍历
FOR(l=1 TO loadcase_number)
loadcase_id=loadcase_ids(l)
status=res_utl_get_subcases(loadcase_id,subcase_number,subcase_ids)
IF(status!=0) THEN
msg_to_form( status, 4, 0, 0, 0., "" )
ELSE
ui_write("subcase num:"//str_from_integer(subcase_number))
$ 获取结果
status=res_utl_get_result_ids(loadcase_number,loadcase_ids,subcase_ids,results_number,primary_ids,secondary_ids)
IF(status!=0) THEN
msg_to_form( status, 4, 0, 0, 0., "" )
ELSE


$ 遍历子工况-----Constraint Forces Translational
ui_write("---------------------------------Constraint Forces Translational Start")
FOR(k=1 TO subcase_number)
db_get_sub_case_title(loadcase_id,subcase_ids(k),subcase_name)
db_get_primary_res_id("Constraint Forces",primary_id)
db_get_secondary_res_id(primary_id,"Translational",secondary_id)
results_ids(1)=loadcase_id
results_ids(2)=subcase_ids(k)
results_ids(3)=primary_id
results_ids(4)=secondary_id
status=res_utl_get_result_layers(results_ids,layer_number,layer_ids,layer_labels)
IF(status!=0) THEN
msg_to_form( status, 4, 0, 0, 0., "" )
ELSE
$ 初始化结果数组
number=groups_selected_number*loadcase_number*subcase_number*layer_number
index=1
min_res=""
max_res=""
sys_allocate_array(translational_min,1,number)
sys_allocate_array(translational_max,1,number)
$ 遍历每个结果值
FOR(m=1 TO layer_number)
FOR(s=1 TO constrainforces_number)
results_ids(5)=layer_ids(m)
status=res_utl_extract_elem_results2(results_ids,elem_list,constrainforces_labels(s),location,@
"",avg_method,avg_domain,extrap_method,complex_form,complex_angle,data_type,@
resloc,nres,ids,nresults,results,minloc,maxloc)
IF(status!=0) THEN
msg_to_form( status, 4, 0, 0, 0., "" )
ELSE


j = minloc(1)
ui_writec(" Group:%s,LoadCase:%s,SubCase:%s,layer:%s,Min Id= %d,%s= %g", group_name,loadcase_names(l),subcase_name,layer_labels(m),ids(j), constrainforces_labels(s), results(j) )
min_res=min_res//str_from_real(results(j))//"*"
j = maxloc(1)
ui_writec(" Group:%s,Loadcase:%s,subcase:%s,layer:%s,Max Id= %d,%s= %g", group_name,loadcase_names(l),subcase_name,layer_labels(m),ids(j), constrainforces_labels(s),results(j) )
max_res=max_res//str_from_real(results(j))//"*"
END IF
END FOR
translational_min(index)=group_name//"*"//loadcase_names(l)//"*"//subcase_name//"*"//layer_labels(m)//"*"//str_token(min_res,"*",1,FALSE)//"*"//@
str_token(min_res,"*",2,FALSE)//"*"//str_token(min_res,"*",3,FALSE)//"*"//str_token(min_res,"*",4,FALSE)
translational_max(index)=group_name//"*"//loadcase_names(l)//"*"//subcase_name//"*"//layer_labels(m)//"*"//str_token(max_res,"*",1,FALSE)//"*"//@
str_token(max_res,"*",2,FALSE)//"*"//str_token(max_res,"*",3,FALSE)//"*"//str_token(max_res,"*",4,FALSE)
index+=1
END FOR
$ 测试输出结果数组到文件
text_write_string(file_channel,"-----Constraint Forces Translational Min Start-----")
text_write_string(file_channel,"-----group name*loadcase name*subcase name*layer name*XX*YY*ZZ*MAG-----")
INTEGER p
FOR(p=1 TO number)
text_write_string(file_channel,translational_min(p))
END FOR
text_write_string(file_channel,"-----Constraint Forces Translational Min End-----")
text_write_string(file_channel,"-----Constraint Forces Translational Max Start-----")
text_write_string(file_channel,"-----group name*loadcase name*subcase name*layer name*XX*YY*ZZ*MAG-----")
FOR(p=1 TO number)
text_write_string(file_channel,translational_max(p))
END FOR
text_write_string(file_channel,"-----Constraint Forces Translational Max End-----")
END IF
END FOR
ui_write("---------------------------------Constraint Forces Translational END")
$ 遍历子工况-----Constraint Forces Rotational
ui_write("---------------------------------Constraint Forces Rotational Start")
FOR(k=1 TO subcase_number)
db_get_sub_case_title(loadcase_id,subcase_ids(k),subcase_name)
db_get_primary_res_id("Constraint Forces",primary_id)
db_get_secondary_res_id(primary_id,"Rotational",secondary_id)
results_ids(1)=loadcase_id
results_ids(2)=subcase_ids(k)
results_ids(3)=primary_id
results_ids(4)=secondary_id
status=res_utl_get_result_layers(results_ids,layer_number,layer_ids,layer_labels)
IF(status!=0) THEN
msg_to_form( status, 4, 0, 0, 0., "" )
ELSE
$ 初始化结果数组
number=groups_selected_number*loadcase_number*subcase_number*layer_number
index=1
min_res=""
max_res=""
sys_allocate_array(rotational_min,1,number)
sys_allocate_array(rotational_max,1,number)
$ 遍历每个结果值
FOR(m=1 TO layer_number)
FOR(s=1 TO constrainforces_number)
results_ids(5)=layer_ids(m)
status=res_utl_extract_elem_results2(results_ids,elem_list,constrainforces_labels(s),location,@
"",avg_method,avg_domain,extrap_method,complex_form,complex_angle,data_type,@
resloc,nres,ids,nresults,results,minloc,maxloc)
IF(status!=0) THEN
msg_to_form( status, 4, 0, 0, 0., "" )
ELSE


j = minloc(1)
ui_writec(" Group:%s,LoadCase:%s,SubCase:%s,layer:%s,Min Id= %d,%s= %g", group_name,loadcase_names(l),subcase_name,layer_labels(m),ids(j), constrainforces_labels(s), results(j) )
min_res=min_res//str_from_real(results(j))//"*"
j = maxloc(1)
ui_writec(" Group:%s,Loadcase:%s,subcase:%s,layer:%s,Max Id= %d,%s= %g", group_name,loadcase_names(l),subcase_name,layer_labels(m),ids(j), constrainforces_labels(s),results(j) )
max_res=max_res//str_from_real(results(j))//"*"
END IF
END FOR
rotational_min(index)=group_name//"*"//loadcase_names(l)//"*"//subcase_name//"*"//layer_labels(m)//"*"//str_token(min_res,"*",1,FALSE)//"*"//@
str_token(min_res,"*",2,FALSE)//"*"//str_token(min_res,"*",3,FALSE)//"*"//str_token(min_res,"*",4,FALSE)
rotational_max(index)=group_name//"*"//loadcase_names(l)//"*"//subcase_name//"*"//layer_labels(m)//"*"//str_token(max_res,"*",1,FALSE)//"*"//@
str_token(max_res,"*",2,FALSE)//"*"//str_token(max_res,"*",3,FALSE)//"*"//str_token(max_res,"*",4,FALSE)
index+=1
END FOR
$ 测试输出结果数组到文件
text_write_string(file_channel,"-----Constraint Forces Rotational Min Start-----")
text_write_string(file_channel,"-----group name*loadcase name*subcase name*layer name*XX*YY*ZZ*MAG-----")
FOR(p=1 TO number)
text_write_string(file_channel,rotational_min(p))
END FOR
text_write_string(file_channel,"-----Constraint Forces Rotational Min End-----")
text_write_string(file_channel,"-----Constraint Forces Rotational Max Start-----")
text_write_string(file_channel,"-----group name*loadcase name*subcase name*layer name*XX*YY*ZZ*MAG-----")
FOR(p=1 TO number)
text_write_string(file_channel,rotational_max(p))
END FOR
text_write_string(file_channel,"-----Constraint Forces Rotational Max End-----")
END IF
END FOR
ui_write("---------------------------------Constraint Forces Rotational END")
END IF
END IF
END FOR
END FOR
END IF
END FUNCTION




FUNCTION export_stress()
$ 定义组和工况变量
INTEGER groups_selected_number,group_ids(VIRTUAL),group_id,loadcase_number,loadcase_id,loadcase_ids(VIRTUAL),i,status,j,k,g,l,m,s
STRING group_name[32],group_names[32](VIRTUAL),loadcase_name[32],loadcase_names[32](VIRTUAL)
$ 定义子工况变量
INTEGER subcase_number,subcase_ids(VIRTUAL)
$ 定义应力变量
INTEGER stress_number=7
STRING stress_labels[10](7)
stress_labels(1)="XX"
stress_labels(2)="YY"
stress_labels(3)="ZZ"
stress_labels(4)="XY"
stress_labels(5)="YZ"
stress_labels(6)="ZX"
stress_labels(7)="VONM"
$ 定义提取结果相关变量
INTEGER num_elems,results_ids(5),data_type,resloc,nres,ids(VIRTUAL),nresults(VIRTUAL),minloc(12),maxloc(12),primary_id,secondary_id,primary_ids(VIRTUAL),secondary_ids(VIRTUAL),results_number,layer_number,layer_ids(VIRTUAL)
STRING elem_list[50000],avg_method[20],avg_domain[20],extrap_method[20],complex_form[10],layer_labels[80](VIRTUAL),@
subcase_name[31],location[3]
REAL complex_angle,results(VIRTUAL)
$ 存放结果数组
INTEGER index,number
STRING min_res[128],max_res[128],stress_min[128](VIRTUAL),stress_max[128](VIRTUAL)
$ 初始化部分结果变量
avg_method="DeriveAverage"
avg_domain="All"
extrap_method="ShapeFunc"
complex_form=""
complex_angle=0.0
location="N"


ui_wid_get(list_id,"NSELECTED",groups_selected_number)
IF(groups_selected_number==0)THEN
xf_error_start("Please select one group at least!")
xf_error_end()
ELSE
$ 1.获取组
sys_allocate_array(group_ids,1,groups_selected_number)
sys_allocate_array(group_names,1,groups_selected_number)
FOR(i=1 TO groups_selected_number)
db_get_group_name(i,group_name)
group_names(i)=group_name
db_get_group_id(group_name,group_id)
group_ids(i)=group_id
END FOR
loadsbcs_eval_all()
$ 2.获取工况
i=1
IF(db_get_all_load_case_names()==0)THEN
IF(db_get_next_load_case_name(loadcase_name)==0)THEN
loadcase_number+=1
END IF
END IF
sys_allocate_array(loadcase_ids,1,loadcase_number)
sys_allocate_array(loadcase_names,1,loadcase_number)
$ ui_write("---------------------------------load case start")
IF(db_get_all_load_case_names()==0)THEN
IF(db_get_next_load_case_name(loadcase_name)==0)THEN
loadcase_names(i)=loadcase_name
db_get_load_case_id(loadcase_name,loadcase_id)
loadcase_ids(i)=loadcase_id
$ ui_write("loadcase name:"//loadcase_name//"   loadcase id:"//str_from_integer(loadcase_id))
i+=1
END IF
END IF
$ ui_write("---------------------------------load case end")
$ 3.遍历每组，每个工况下的子工况应力结果
ui_write("---------------------------------Stress Tensor Start")
FOR(g=1 TO groups_selected_number)
group_id=group_ids(g)
group_name=group_names(g)
Export_Static.get_elem_list(group_id,group_name,elem_list,num_elems)
$ 遍历工况
FOR(l=1 TO loadcase_number)
loadcase_id=loadcase_ids(l)
status=res_utl_get_subcases(loadcase_id,subcase_number,subcase_ids)
ui_write(str_from_integer(status))
IF(status!=0) THEN
msg_to_form( status, 4, 0, 0, 0., "" )
ELSE
$ ui_write("subcase num:"//str_from_integer(subcase_number))
$ 获取结果
status=res_utl_get_result_ids(loadcase_number,loadcase_ids,subcase_ids,results_number,primary_ids,secondary_ids)
IF(status==0)THEN
$ 遍历子工况
FOR(k=1 TO subcase_number)
db_get_sub_case_title(loadcase_id,subcase_ids(k),subcase_name)
db_get_primary_res_id("Stress Tensor",primary_id)
db_get_secondary_res_id(primary_id,"",secondary_id)
results_ids(1)=loadcase_id
results_ids(2)=subcase_ids(k)
results_ids(3)=primary_id
results_ids(4)=secondary_id
status=res_utl_get_result_layers(results_ids,layer_number,layer_ids,layer_labels)
IF(status==0)THEN
$ 初始化结果数组
number=groups_selected_number*loadcase_number*subcase_number*layer_number
index=1
min_res=""
max_res=""
sys_allocate_array(stress_min,1,number)
sys_allocate_array(stress_max,1,number)
$ 遍历每层的每个应力值
FOR(m=1 TO layer_number)
FOR(s=1 TO stress_number)
results_ids(5)=layer_ids(m)
status=res_utl_extract_elem_results2(results_ids,elem_list,stress_labels(s),location,@
"",avg_method,avg_domain,extrap_method,complex_form,complex_angle,data_type,@
resloc,nres,ids,nresults,results,minloc,maxloc)
IF(status!=0) THEN
msg_to_form( status, 4, 0, 0, 0., "" )
ELSE


j = minloc(1)
ui_writec(" Group:%s,LoadCase:%s,SubCase:%s,layer:%s,Min Id= %d,%s= %g", group_name,loadcase_names(l),subcase_name,layer_labels(m),ids(j), stress_labels(s), results(j) )
min_res=min_res//str_from_real(results(j))//"*"
j = maxloc(1)
ui_writec(" Group:%s,Loadcase:%s,subcase:%s,layer:%s,Max Id= %d,%s= %g", group_name,loadcase_names(l),subcase_name,layer_labels(m),ids(j), stress_labels(s),results(j) )
max_res=max_res//str_from_real(results(j))//"*"
END IF
END FOR
stress_min(index)=group_name//"*"//loadcase_names(l)//"*"//subcase_name//"*"//layer_labels(m)//"*"//str_token(min_res,"*",1,FALSE)//"*"//@
str_token(min_res,"*",2,FALSE)//"*"//str_token(min_res,"*",3,FALSE)//"*"//str_token(min_res,"*",4,FALSE)//"*"//str_token(min_res,"*",5,FALSE)//"*"//str_token(min_res,"*",6,FALSE)//"*"//str_token(min_res,"*",7,FALSE)
stress_max(index)=group_name//"*"//loadcase_names(l)//"*"//subcase_name//"*"//layer_labels(m)//"*"//str_token(max_res,"*",1,FALSE)//"*"//@
str_token(max_res,"*",2,FALSE)//"*"//str_token(max_res,"*",3,FALSE)//"*"//str_token(max_res,"*",4,FALSE)//"*"//str_token(max_res,"*",5,FALSE)//"*"//str_token(max_res,"*",6,FALSE)//"*"//str_token(max_res,"*",7,FALSE)
index+=1
END FOR
$ 测试输出结果数组到文件
text_write_string(file_channel,"-----Stress Tensor Min Start-----")
text_write_string(file_channel,"-----group name*loadcase name*subcase name*layer name*XX*YY*ZZ*XY*YZ*ZX*VON MISES-----")
INTEGER p
FOR(p=1 TO number)
text_write_string(file_channel,stress_min(p))
END FOR
text_write_string(file_channel,"-----Stress Tensor Min End-----")
text_write_string(file_channel,"-----Stress Tensor Max Start-----")
text_write_string(file_channel,"-----group name*loadcase name*subcase name*layer name*XX*YY*ZZ*XY*YZ*ZX*VON MISES-----")
FOR(p=1 TO number)
text_write_string(file_channel,stress_max(p))
END FOR
text_write_string(file_channel,"-----Stress Tensor Max End-----")
END IF
END FOR
END IF
END IF
END FOR
END FOR
ui_write("---------------------------------Stress Tensor END")
END IF
END FUNCTION




FUNCTION export_strain()
$ 定义组和工况变量
INTEGER groups_selected_number,group_ids(VIRTUAL),group_id,loadcase_number,loadcase_id,loadcase_ids(VIRTUAL),i,status,j,k,g,l,m,s
STRING group_name[32],group_names[32](VIRTUAL),loadcase_name[32],loadcase_names[32](VIRTUAL)
$ 定义子工况变量
INTEGER subcase_number,subcase_ids(VIRTUAL)
$ 定义应变相关变量
INTEGER strain_number=7
STRING strain_labels[10](7)
strain_labels(1)="XX"
strain_labels(2)="YY"
strain_labels(3)="ZZ"
strain_labels(4)="XY"
strain_labels(5)="YZ"
strain_labels(6)="ZX"
strain_labels(7)="VONM"
$ 定义提取结果相关变量
INTEGER num_elems,results_ids(5),data_type,resloc,nres,ids(VIRTUAL),nresults(VIRTUAL),minloc(12),maxloc(12),primary_id,secondary_id,primary_ids(VIRTUAL),secondary_ids(VIRTUAL),results_number,layer_number,layer_ids(VIRTUAL)
STRING elem_list[50000],avg_method[20],avg_domain[20],extrap_method[20],complex_form[10],layer_labels[80](VIRTUAL),@
subcase_name[31],location[3]
REAL complex_angle,results(VIRTUAL)
$ 存放结果数组
INTEGER index,number
STRING min_res[128],max_res[128],strain_min[128](VIRTUAL),strain_max[128](VIRTUAL)


$ 初始化部分结果变量
avg_method="DeriveAverage"
avg_domain="All"
extrap_method="ShapeFunc"
complex_form=""
complex_angle=0.0
location="N"


ui_wid_get(list_id,"NSELECTED",groups_selected_number)
IF(groups_selected_number==0)THEN
xf_error_start("Please select one group at least!")
xf_error_end()
ELSE
$ 1.获取组
sys_allocate_array(group_ids,1,groups_selected_number)
sys_allocate_array(group_names,1,groups_selected_number)
FOR(i=1 TO groups_selected_number)
db_get_group_name(i,group_name)
group_names(i)=group_name
db_get_group_id(group_name,group_id)
group_ids(i)=group_id
END FOR
loadsbcs_eval_all()
$ 2.获取工况
i=1
IF(db_get_all_load_case_names()==0)THEN
IF(db_get_next_load_case_name(loadcase_name)==0)THEN
loadcase_number+=1
END IF
END IF
sys_allocate_array(loadcase_ids,1,loadcase_number)
sys_allocate_array(loadcase_names,1,loadcase_number)
$ ui_write("---------------------------------load case start")
IF(db_get_all_load_case_names()==0)THEN
IF(db_get_next_load_case_name(loadcase_name)==0)THEN
loadcase_names(i)=loadcase_name
db_get_load_case_id(loadcase_name,loadcase_id)
loadcase_ids(i)=loadcase_id
$ ui_write("loadcase name:"//loadcase_name//"   loadcase id:"//str_from_integer(loadcase_id))
i+=1
END IF
END IF
$ ui_write("---------------------------------load case end")
$ 3.遍历每组，每个工况下的子工况应变结果
ui_write("---------------------------------Strain Tensor Start")
FOR(g=1 TO groups_selected_number)
group_id=group_ids(g)
group_name=group_names(g)
Export_Static.get_elem_list(group_id,group_name,elem_list,num_elems)
$ 遍历工况
FOR(l=1 TO loadcase_number)
loadcase_id=loadcase_ids(l)
status=res_utl_get_subcases(loadcase_id,subcase_number,subcase_ids)
ui_write(str_from_integer(status))
IF(status!=0) THEN
msg_to_form( status, 4, 0, 0, 0., "" )
ELSE
ui_write("subcase num:"//str_from_integer(subcase_number))
$ 获取结果
status=res_utl_get_result_ids(loadcase_number,loadcase_ids,subcase_ids,results_number,primary_ids,secondary_ids)
IF(status==0)THEN
$ 遍历子工况
FOR(k=1 TO subcase_number)
db_get_sub_case_title(loadcase_id,subcase_ids(k),subcase_name)
db_get_primary_res_id("Strain Tensor",primary_id)
db_get_secondary_res_id(primary_id,"",secondary_id)
results_ids(1)=loadcase_id
results_ids(2)=subcase_ids(k)
results_ids(3)=primary_id
results_ids(4)=secondary_id
status=res_utl_get_result_layers(results_ids,layer_number,layer_ids,layer_labels)
IF(status==0)THEN
$ 初始化结果数组
number=groups_selected_number*loadcase_number*subcase_number*layer_number
index=1
min_res=""
max_res=""
sys_allocate_array(strain_min,1,number)
sys_allocate_array(strain_max,1,number)
$ 遍历每层的每个应变值
FOR(m=1 TO layer_number)
FOR(s=1 TO strain_number)
results_ids(5)=layer_ids(m)
status=res_utl_extract_elem_results2(results_ids,elem_list,strain_labels(s),location,@
"",avg_method,avg_domain,extrap_method,complex_form,complex_angle,data_type,@
resloc,nres,ids,nresults,results,minloc,maxloc)
IF(status!=0) THEN
msg_to_form( status, 4, 0, 0, 0., "" )
ELSE


j = minloc(1)
ui_writec(" Group:%s,LoadCase:%s,SubCase:%s,layer:%s,Min Id= %d,%s= %g", group_name,loadcase_names(l),subcase_name,layer_labels(m),ids(j), strain_labels(s), results(j) )
min_res=min_res//str_from_real(results(j))//"*"
j = maxloc(1)
ui_writec(" Group:%s,Loadcase:%s,subcase:%s,layer:%s,Max Id= %d,%s= %g", group_name,loadcase_names(l),subcase_name,layer_labels(m),ids(j), strain_labels(s),results(j) )
max_res=max_res//str_from_real(results(j))//"*"
END IF
END FOR
strain_min(index)=group_name//"*"//loadcase_names(l)//"*"//subcase_name//"*"//layer_labels(m)//"*"//str_token(min_res,"*",1,FALSE)//"*"//@
str_token(min_res,"*",2,FALSE)//"*"//str_token(min_res,"*",3,FALSE)//"*"//str_token(min_res,"*",4,FALSE)//"*"//str_token(min_res,"*",5,FALSE)//"*"//str_token(min_res,"*",6,FALSE)//"*"//str_token(min_res,"*",7,FALSE)
strain_max(index)=group_name//"*"//loadcase_names(l)//"*"//subcase_name//"*"//layer_labels(m)//"*"//str_token(max_res,"*",1,FALSE)//"*"//@
str_token(max_res,"*",2,FALSE)//"*"//str_token(max_res,"*",3,FALSE)//"*"//str_token(max_res,"*",4,FALSE)//"*"//str_token(max_res,"*",5,FALSE)//"*"//str_token(max_res,"*",6,FALSE)//"*"//str_token(max_res,"*",7,FALSE)
index+=1
END FOR
$ 测试输出结果数组到文件
text_write_string(file_channel,"-----Strain Tensor Min Start-----")
text_write_string(file_channel,"-----group name*loadcase name*subcase name*layer name*XX*YY*ZZ*XY*YZ*ZX*VON MISES-----")
INTEGER p
FOR(p=1 TO number)
text_write_string(file_channel,strain_min(p))
END FOR
text_write_string(file_channel,"-----Strain Tensor Min End-----")
text_write_string(file_channel,"-----Strain Tensor Max Start-----")
text_write_string(file_channel,"-----group name*loadcase name*subcase name*layer name*XX*YY*ZZ*XY*YZ*ZX*VON MISES-----")
FOR(p=1 TO number)
text_write_string(file_channel,strain_max(p))
END FOR
text_write_string(file_channel,"-----Strain Tensor Max End-----")
END IF
END FOR
END IF
END IF
END FOR
END FOR
ui_write("---------------------------------Strain Tensor END")
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




FUNCTION get_elem_list(group_id,group_name,elem_list,num_elems)
STRING group_name[],elem_list[]
INTEGER i,sum=0,group_id,num_elems
INTEGER elem_ids(VIRTUAL),elem_id(1),topo_code(VIRTUAL)




db_count_elems_in_group(group_id,num_elems)
sys_allocate_array(elem_ids,1,num_elems)
sys_allocate_array(topo_code,1,num_elems)
db_get_elem_ids_in_group(num_elems,group_id,elem_ids)
elem_list=""
FOR(i=1 TO num_elems)
elem_id(1)=elem_ids(i)
$ ui_write(str_from_integer(elem_ids(i)))
db_get_elem_etop(1,elem_id,topo_code)
elem_list=elem_list//str_from_integer(elem_ids(i))//" "
sum=sum+1
END FOR
elem_list="Elm "//elem_list
num_elems=sum
ui_write(elem_list)
ui_write("num elems:"//str_from_integer(num_elems))
END FUNCTION


FUNCTION cancel()
ui_form_hide("Export_Static")
END FUNCTION


END CLASS


CLASS XDB_File_Form


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
	 ui_form_display("XDB_File_Form")
END FUNCTION


FUNCTION file_select(pathname,type)
	 STRING pathname[],type[]
GLOBAL WIDGET file_id
IF(type=="CANCEL")THEN
ui_form_hide("XDB_File_Form")
ELSE
ui_wid_set(file_id,"VALUE",pathname)
ui_form_hide("XDB_File_Form")
END IF
END FUNCTION


END CLASS