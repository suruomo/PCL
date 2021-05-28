


















































































































































































































































CLASS Mat8
	
CLASSWIDE WIDGET form_id,select_button,apply_button,cancel_button


FUNCTION init()


real x_loc,y_loc


GLOBAL WIDGET Material_Name,Elastic_Modulus_11,Elastic_Modulus_22,Possion_Ratio_12,@
Shear_Modulus_12,Shear_Modulus_23,Shear_Modulus_13,Density,Thermal_Expan_Coeff_11,Thermal_Expan_Coeff_22,Structural_Damping_Coeff,Reference_Temperature


x_loc=uil_form_sizes.unframed_margin( 1 )
y_loc=uil_form_sizes.form_margin( 3 )
	
form_id=ui_form_create("",uil_form_sizes.form_x_loc( 1 ),uil_form_sizes.form_y_loc( 1 ), "UL",uil_form_sizes.form_wid( 1 ),uil_form_sizes.form_hgt( 3 ), "2D Orthotropic Material", "" )


	
Material_Name=ui_databox_create(form_id,"",x_loc,y_loc,0.0,uil_form_sizes.dbox_wid( 1 ),"Material Name:","",TRUE,"STRING",1)


y_loc+= uil_form_sizes.dbox_hgt( 1 ) + uil_form_sizes.spacing( 8 )


Elastic_Modulus_11=ui_databox_create(form_id,"",x_loc,y_loc,0.0,uil_form_sizes.dbox_wid( 1 ),"Elastic Modulus 11:","",TRUE,"REAL",1)


y_loc+= uil_form_sizes.dbox_hgt( 1 ) + uil_form_sizes.spacing( 8 )


Elastic_Modulus_22=ui_databox_create(form_id,"",x_loc,y_loc,0.0,uil_form_sizes.dbox_wid( 1 ),"Elastic Modulus 22:","",TRUE,"REAL",1)


y_loc+= uil_form_sizes.dbox_hgt( 1 ) + uil_form_sizes.spacing( 8 )


Possion_Ratio_12=ui_databox_create(form_id,"",x_loc,y_loc,0.0,uil_form_sizes.dbox_wid( 1 ),"Possion Ratio 12:","",TRUE,"REAL",1)


y_loc+= uil_form_sizes.dbox_hgt( 1 ) + uil_form_sizes.spacing( 8 )


Shear_Modulus_12=ui_databox_create(form_id,"",x_loc,y_loc,0.0,uil_form_sizes.dbox_wid( 1 ),"Shear Modulus 12:","",TRUE,"REAL",1)


y_loc+= uil_form_sizes.dbox_hgt( 1 ) + uil_form_sizes.spacing( 8 )


Shear_Modulus_23=ui_databox_create(form_id,"",x_loc,y_loc,0.0,uil_form_sizes.dbox_wid( 1 ),"Shear Modulus 23:","",TRUE,"REAL",1)


y_loc+= uil_form_sizes.dbox_hgt( 1 ) + uil_form_sizes.spacing( 8 )


Shear_Modulus_13=ui_databox_create(form_id,"",x_loc,y_loc,0.0,uil_form_sizes.dbox_wid( 1 ),"Shear Modulus 13:","",TRUE,"REAL",1)


y_loc+= uil_form_sizes.dbox_hgt( 1 ) + uil_form_sizes.spacing( 8 )


Density=ui_databox_create(form_id,"",x_loc,y_loc,0.0,uil_form_sizes.dbox_wid( 1 ),"Density:","",TRUE,"REAL",1)


y_loc+= uil_form_sizes.dbox_hgt( 1 ) + uil_form_sizes.spacing( 8 )


Thermal_Expan_Coeff_11=ui_databox_create(form_id,"",x_loc,y_loc,0.0,uil_form_sizes.dbox_wid( 1 ),"Thermal Expan.Coeff 11:","",TRUE,"REAL",1)


y_loc+= uil_form_sizes.dbox_hgt( 1 ) + uil_form_sizes.spacing( 8 )


Thermal_Expan_Coeff_22=ui_databox_create(form_id,"",x_loc,y_loc,0.0,uil_form_sizes.dbox_wid( 1 ),"Thermal Expan.Coeff 22:","",TRUE,"REAL",1)


y_loc+= uil_form_sizes.dbox_hgt( 1 ) + uil_form_sizes.spacing( 8 )


Structural_Damping_Coeff=ui_databox_create(form_id,"",x_loc,y_loc,0.0,uil_form_sizes.dbox_wid( 1 ),"Structural Damping Coeff:","",TRUE,"REAL",1)


y_loc+= uil_form_sizes.dbox_hgt( 1 ) + uil_form_sizes.spacing( 8 )


Reference_Temperature=ui_databox_create(form_id,"",x_loc,y_loc,0.0,uil_form_sizes.dbox_wid( 1 ),"Reference Temperature:","",TRUE,"REAL",1)


y_loc+= uil_form_sizes.dbox_hgt( 1 ) + uil_form_sizes.spacing( 8 )

	
select_button=ui_button_create(form_id, "select_mat8_material", uil_form_sizes.button_x_loc1( 1 ), y_loc, uil_form_sizes.button_wid( 1 ), 0.,"Select Material From Database", TRUE, FALSE)


y_loc+= uil_form_sizes.dbox_hgt( 1 ) + uil_form_sizes.spacing( 8 )


apply_button=ui_button_create(form_id, "apply", uil_form_sizes.button_x_loc1( 2 ), y_loc, uil_form_sizes.button_wid( 2 ), 0.,"Apply", FALSE, FALSE)


cancel_button=ui_button_create(form_id, "cancel", uil_form_sizes.button_x_loc1( 3 ), y_loc, uil_form_sizes.button_wid( 2 ), 0.,"Cancel", FALSE, FALSE)


END FUNCTION


FUNCTION display()


	ui_form_display("Mat8")
END FUNCTION




FUNCTION select_mat8_material()
ui_write("Select Isotropic Material From Database.....")
ui_exec_function("Mat8_List","init")
Mat8_List.display()
END FUNCTION


FUNCTION apply()
REAL EM11,EM22,PR,SM12,SM23,SM13,D,TEC11,TEC22,SDC,RT
STRING result[64](12)
STRING name[200]
GLOBAL WIDGET Material_Name,Elastic_Modulus_11,Elastic_Modulus_22,Possion_Ratio_12,@
Shear_Modulus_12,Shear_Modulus_23,Shear_Modulus_13,Density,Thermal_Expan_Coeff_11,Thermal_Expan_Coeff_22,Structural_Damping_Coeff,Reference_Temperature
ui_wid_get(Material_Name,"VALUE",name)
ui_wid_get(Elastic_Modulus_11,"VALUE",EM11)
ui_wid_get(Elastic_Modulus_22,"VALUE",EM22)
ui_wid_get(Possion_Ratio_12,"VALUE",PR)
ui_wid_get(Shear_Modulus_12,"VALUE",SM12)
ui_wid_get(Shear_Modulus_23,"VALUE",SM23)
ui_wid_get(Shear_Modulus_13,"VALUE",SM13)
ui_wid_get(Density,"VALUE",D)
ui_wid_get(Thermal_Expan_Coeff_11,"VALUE",TEC11)
ui_wid_get(Thermal_Expan_Coeff_22,"VALUE",TEC22)
ui_wid_get(Structural_Damping_Coeff,"VALUE",SDC)
ui_wid_get(Reference_Temperature,"VALUE",RT)


result(1)=str_from_real(EM11)
result(2)=str_from_real(EM22)
result(3)=str_from_real(PR)
result(4)=str_from_real(SM12)
result(5)=str_from_real(SM23)
result(6)=str_from_real(SM13)
result(7)=str_from_real(D)
result(8)=str_from_real(TEC11)
result(9)=str_from_real(TEC22)
result(10)=str_from_real(SDC)
result(11)=str_from_real(RT)
result(12)=""


material.create( "Analysis code ID", 1, "Analysis type ID", 1,name, 16, "Date: 28-May-21           Time: 12:49:28", "2d Orthotropic", 5,@
"Directionality", 4, "Linearity", 1, "Homogeneous", 0, "Linear Elastic", 1, @
"Model Options & IDs", ["", "", "", "", ""], [0, 0, 0, 0, 0], "Active Flag", 1, "Create", 11, "External Flag", FALSE,@
"Property IDs", ["Elastic Modulus 11", "Elastic Modulus 22", "Poisson Ratio 12", "Shear Modulus 12", "Shear Modulus 23", "Shear Modulus 13", @
"Density""Thermal Expan. Coeff 11", "Thermal Expan. Coeff 22", "Structural Damping Coeff", "Reference Temperature"], @
[2, 3, 5, 8, 9, 10, 16,24, 25, 30, 1, 0], "Property Values", result)
ui_write("Create Material Successful")
END FUNCTION


FUNCTION cancel()
ui_form_hide("Mat8")
END FUNCTION


END CLASS




CLASS Mat8_List


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
form_id=ui_form_create("",uil_form_sizes.form_x_loc( 1 ),uil_form_sizes.form_y_loc( 1 ), "UL",uil_form_sizes.form_wid( 1 ),uil_form_sizes.form_hgt( 3 ), "2D Orthotropic Database", "" )


$ 读取材料库中数据
file_get_p3_home(path)
status=text_open(path//"\material_database\composite.txt","OR",0,0,file)
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
list_id=ui_listbox_create(form_id,"get_item",x_loc,y_loc,uil_form_sizes.form_wid( 1 ),item_numbers,"2D Orthotropic Database","SINGLE",FALSE)


ui_listbox_items_create(list_id,widget_names,widget_labels,item_numbers,WIDGET_NULL)


ui_wid_set(list_id,"ROWS",25)


y_loc+= uil_form_sizes.dbox_hgt( 1 )*10+ uil_form_sizes.spacing( 8 )*8


$ 创建按钮
apply_button=ui_button_create(form_id, "apply", uil_form_sizes.button_x_loc1( 2 ), y_loc, uil_form_sizes.button_wid( 2 ), 0.,"Apply", FALSE, FALSE)


cancel_button=ui_button_create(form_id, "cancel", uil_form_sizes.button_x_loc1( 3 ), y_loc, uil_form_sizes.button_wid( 2 ), 0.,"Cancel", FALSE, FALSE)


END FUNCTION


FUNCTION display()
	ui_form_display("Mat8_List")
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
GLOBAL WIDGET Material_Name,Elastic_Modulus_11,Elastic_Modulus_22,Possion_Ratio_12,@
Shear_Modulus_12,Shear_Modulus_23,Shear_Modulus_13,Density
STRING EM11[64],EM22[64],SM12[64],SM23[64],SM13[64],PR[64],D[64],name[200]
$ 截取字符串结果
name=str_token(res,"*",1,FALSE)
D=str_token(res,"*",2,FALSE)
EM11=str_token(res,"*",3,FALSE)
EM22=str_token(res,"*",4,FALSE)
PR=str_token(res,"*",5,FALSE)
SM12=str_token(res,"*",6,FALSE)
SM23=str_token(res,"*",7,FALSE)
SM13=str_token(res,"*",8,FALSE)


$ 赋值输入框
ui_wid_set(Material_Name,"VALUE",name)
ui_wid_set(Elastic_Modulus_11,"VALUE",EM11)
ui_wid_set(Elastic_Modulus_22,"VALUE",EM22)
ui_wid_set(Possion_Ratio_12,"VALUE",PR)
ui_wid_set(Shear_Modulus_12,"VALUE",SM12)
ui_wid_set(Shear_Modulus_23,"VALUE",SM23)
ui_wid_set(Shear_Modulus_13,"VALUE",SM13)
ui_wid_set(Density,"VALUE",D)
ui_write("Select Material Successful")
ui_form_display("Mat8")
END FUNCTION


FUNCTION cancel()
ui_form_hide("Mat8_List")
END FUNCTION


END CLASS
