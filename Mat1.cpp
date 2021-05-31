


















































































































































































































































CLASS Mat1
	
CLASSWIDE WIDGET form_id,select_button,apply_button,cancel_button


FUNCTION init()


real x_loc,y_loc


GLOBAL WIDGET Material_Name,Elastic_Modulus,Possion_Ratio,Shear_Modulus,Density,Thermal_Expan_Coeff,Structural_Damping_Coeff,Reference_Temperature


x_loc=uil_form_sizes.unframed_margin( 1 )
y_loc=uil_form_sizes.form_margin( 3 )
	
form_id=ui_form_create("",uil_form_sizes.form_x_loc( 1 ),uil_form_sizes.form_y_loc( 1 ), "UL",uil_form_sizes.form_wid( 1 ),uil_form_sizes.form_hgt( 3 ), "Isotropic Material", "" )


	
Material_Name=ui_databox_create(form_id,"",x_loc,y_loc,0.0,uil_form_sizes.dbox_wid( 1 ),"Material Name:","",TRUE,"STRING",1)


y_loc+= uil_form_sizes.dbox_hgt( 1 ) + uil_form_sizes.spacing( 8 )


Elastic_Modulus=ui_databox_create(form_id,"",x_loc,y_loc,0.0,uil_form_sizes.dbox_wid( 1 ),"Elastic Modulus:","",TRUE,"REAL",1)


y_loc+= uil_form_sizes.dbox_hgt( 1 ) + uil_form_sizes.spacing( 8 )


Possion_Ratio=ui_databox_create(form_id,"",x_loc,y_loc,0.0,uil_form_sizes.dbox_wid( 1 ),"Possion Ratio:","",TRUE,"REAL",1)


y_loc+= uil_form_sizes.dbox_hgt( 1 ) + uil_form_sizes.spacing( 8 )


Shear_Modulus=ui_databox_create(form_id,"",x_loc,y_loc,0.0,uil_form_sizes.dbox_wid( 1 ),"Shear Modulus:","",TRUE,"REAL",1)


y_loc+= uil_form_sizes.dbox_hgt( 1 ) + uil_form_sizes.spacing( 8 )


Density=ui_databox_create(form_id,"",x_loc,y_loc,0.0,uil_form_sizes.dbox_wid( 1 ),"Density:","",TRUE,"REAL",1)


y_loc+= uil_form_sizes.dbox_hgt( 1 ) + uil_form_sizes.spacing( 8 )


Thermal_Expan_Coeff=ui_databox_create(form_id,"",x_loc,y_loc,0.0,uil_form_sizes.dbox_wid( 1 ),"Thermal Expan.Coeff:","",TRUE,"REAL",1)


y_loc+= uil_form_sizes.dbox_hgt( 1 ) + uil_form_sizes.spacing( 8 )


Structural_Damping_Coeff=ui_databox_create(form_id,"",x_loc,y_loc,0.0,uil_form_sizes.dbox_wid( 1 ),"Structural Damping Coeff:","",TRUE,"REAL",1)


y_loc+= uil_form_sizes.dbox_hgt( 1 ) + uil_form_sizes.spacing( 8 )


Reference_Temperature=ui_databox_create(form_id,"",x_loc,y_loc,0.0,uil_form_sizes.dbox_wid( 1 ),"Reference Temperature:","",TRUE,"REAL",1)


y_loc+= uil_form_sizes.dbox_hgt( 1 ) + uil_form_sizes.spacing( 8 )

	
select_button=ui_button_create(form_id, "select_mat1_material", uil_form_sizes.button_x_loc1( 1 ), y_loc, uil_form_sizes.button_wid( 1 ), 0.,"Select Material From Database", TRUE, FALSE)


y_loc+= uil_form_sizes.dbox_hgt( 1 ) + uil_form_sizes.spacing( 8 )


apply_button=ui_button_create(form_id, "apply", uil_form_sizes.button_x_loc1( 2 ), y_loc, uil_form_sizes.button_wid( 2 ), 0.,"Apply", FALSE, FALSE)


cancel_button=ui_button_create(form_id, "cancel", uil_form_sizes.button_x_loc1( 3 ), y_loc, uil_form_sizes.button_wid( 2 ), 0.,"Cancel", FALSE, FALSE)


END FUNCTION


FUNCTION display()


	ui_form_display("Mat1")
END FUNCTION




FUNCTION select_mat1_material()
ui_write("Select Isotropic Material From Database.....")
ui_exec_function("Mat1_List","init")
Mat1_List.display()
END FUNCTION


FUNCTION apply()
REAL EM,PR,SM,D,TEC,SDC,RT
STRING name[200]
STRING result[64](8)
GLOBAL WIDGET Material_Name,Elastic_Modulus,Possion_Ratio,Shear_Modulus,Density,Thermal_Expan_Coeff,Structural_Damping_Coeff,Reference_Temperature
ui_wid_get(Material_Name,"VALUE",name)
ui_wid_get(Elastic_Modulus,"VALUE",EM)
ui_wid_get(Possion_Ratio,"VALUE",PR)
ui_wid_get(Shear_Modulus,"VALUE",SM)
ui_wid_get(Density,"VALUE",D)
ui_wid_get(Thermal_Expan_Coeff,"VALUE",TEC)
ui_wid_get(Structural_Damping_Coeff,"VALUE",SDC)
ui_wid_get(Reference_Temperature,"VALUE",RT)


result(1)=str_from_real(EM)
result(2)=str_from_real(PR)
result(3)=str_from_real(SM)
result(4)=str_from_real(D)
result(5)=str_from_real(TEC)
result(6)=str_from_real(SDC)
result(7)=str_from_real(RT)
result(8)=""




material.create( "Analysis code ID", 1, "Analysis type ID", 1, name, 0, @
"Date: 27-Nov-12 Time: 04:59:56", "Isotropic", 1, "Directionality", @
1, "Linearity", 1, "Homogeneous", 0, "Linear Elastic", 1, @
"Model Options & IDs", ["", "", "", "", ""], [0, 0, 0, 0, 0], "Active Flag", @
1, "Create", 10, "External Flag", FALSE, "Property IDs", ["Elastic Modulus", @
"Poisson Ratio", "Shear Modulus", "Density", "Thermal Expan. Coeff", @
"Structural Damping Coeff", "Reference Temperature"], [2, 5, 8, 16, 24, 30, @
1,0], "Property Values",result )


ui_write("Create Material Successful")
END FUNCTION


FUNCTION cancel()
ui_form_hide("Mat1")
END FUNCTION


END CLASS




CLASS Mat1_List


CLASSWIDE WIDGET form_id,list_id,apply_button,cancel_button


CLASSWIDE STRING widget_names[200](420)


CLASSWIDE STRING widget_labels[200](420)


CLASSWIDE INTEGER item_numbers
$ 选择项
CLASSWIDE STRING res[200]


FUNCTION init()
REAL x_loc,y_loc
INTEGER status,file,str_length,index=1
STRING str[200],path[200]


x_loc=uil_form_sizes.unframed_margin( 1 )
y_loc=uil_form_sizes.form_margin( 3 )


$ 创建表单
form_id=ui_form_create("",uil_form_sizes.form_x_loc( 1 ),uil_form_sizes.form_y_loc( 1 ), "UL",uil_form_sizes.form_wid( 1 ),uil_form_sizes.form_hgt( 3 ), "Isotropic Database", "" )


$ 读取材料库中数据
file_get_p3_home(path)
status=text_open(path//"\material_database\metal.txt","OR",0,0,file)
IF(status==0)THEN
WHILE(text_read_string(file,str,str_length)==0)
widget_names(index)=str
widget_labels(index)=str_token(str,"*",1,FALSE)
index+=1
END WHILE
item_numbers=index
ELSE
xf_error_start("No Material Database Exists!")
xf_error_end()


END IF


$ 创建list列表
list_id=ui_listbox_create(form_id,"get_item",x_loc,y_loc,uil_form_sizes.form_wid( 1 ),item_numbers,"Isotropic Database","SINGLE",FALSE)


ui_listbox_items_create(list_id,widget_names,widget_labels,item_numbers,WIDGET_NULL)


ui_wid_set(list_id,"ROWS",25)


y_loc+= uil_form_sizes.dbox_hgt( 1 )*10+ uil_form_sizes.spacing( 8 )*8


$ 创建按钮
apply_button=ui_button_create(form_id, "apply", uil_form_sizes.button_x_loc1( 2 ), y_loc, uil_form_sizes.button_wid( 2 ), 0.,"Apply", FALSE, FALSE)


cancel_button=ui_button_create(form_id, "cancel", uil_form_sizes.button_x_loc1( 3 ), y_loc, uil_form_sizes.button_wid( 2 ), 0.,"Cancel", FALSE, FALSE)


END FUNCTION


FUNCTION display()
	ui_form_display("Mat1_List")
END FUNCTION


$ 获取列表选择项
FUNCTION get_item(num,item_selected)
	INTEGER num,i=1,j
STRING item_selected[](),res_selected[200](1)
FOR(j=1 To 1)
res_selected(j)=item_selected(j)
BREAK
END FOR


$ 循环查找列表选择项
WHILE(i<420)
IF(widget_labels(i)==res_selected(1))THEN
res=widget_names(i)
BREAK
ELSE
i+=1
END IF
END WHILE
ui_write("Select Material:"//res)
END FUNCTION


$ 应用选择
FUNCTION apply()
GLOBAL WIDGET Material_Name,Elastic_Modulus,Possion_Ratio,Shear_Modulus,Density
STRING EM[64],SM[64],PR[64],D[64],name[200]
$ 截取字符串结果
name=str_token(res,"*",1,FALSE)
D=str_token(res,"*",2,FALSE)
EM=str_token(res,"*",3,FALSE)
SM=str_token(res,"*",4,FALSE)
PR=str_token(res,"*",5,FALSE)
$ 赋值输入框
ui_wid_set(Material_Name,"VALUE",name)
ui_wid_set(Elastic_Modulus,"VALUE",EM)
ui_wid_set(Possion_Ratio,"VALUE",PR)
ui_wid_set(Shear_Modulus,"VALUE",SM)
ui_wid_set(Density,"VALUE",D)
ui_write("Select Material Successful")
ui_form_display("Mat1")
END FUNCTION


FUNCTION cancel()
ui_form_hide("Mat1_List")
END FUNCTION


END CLASS
