  main(){
    bool C1, C2, C3, C4, C5, C6, work, reset;
    float fill;
    float fill2;
    float fill3;
    float fill4;
      while (1){
        TEXT_FIELD2.visible(FALSE);
        dpGet("System1:auto.", work);
        // AUTOMATIC MODE
        while(work){
          dpGet("System1:auto.", work);
          dpGet("System1:C1.", C1);
          dpGet("System1:C2.", C2);
          dpGet("System1:C3.", C3);
          dpGet("System1:C4.", C4);
          dpGet("System1:C5.", C5);
          dpGet("System1:C6.", C6);
          dpGet("System1:Fill.", fill);
          dpGet("System1:Fill2.", fill2);
          dpGet("System1:Fill3.", fill3);
          dpGet("System1:Fill4.", fill4);
          if(work){
            while (fill < 5000){ //PUMP 1 
            if (fill == 5000){
              SHAPE_GROUP1.color("red");
            } else {
              SHAPE_GROUP1.color("green");
              SHAPE_GROUP2.color("red");
              SHAPE_GROUP3.color("red");
              SHAPE_GROUP4.color("red");
              SHAPE_GROUP6.color("red");
              fill += 20;
              dpSet("System1:Fill.", fill);
              delay(0.7);
            }}
            while(fill > 0 && fill2 < 5000){ //DUMP 1 TO 2
              SHAPE_GROUP1.color("red");
              SHAPE_GROUP2.color("green");
              fill += -10;
              fill2 += +10;
              dpSet("System1:Fill.", fill);
              dpSet("System1:Fill2.", fill2);
              delay(0.7);
            }
            while(fill > 0 && fill3 < 5000 && fill2 == 5000){ //DUMP 1 TO 3
              SHAPE_GROUP1.color("red");
              SHAPE_GROUP2.color("red");
              SHAPE_GROUP3.color("green");
              fill += -10;
              fill3 += +10;
              dpSet("System1:Fill.", fill);
              dpSet("System1:Fill3.", fill3);
              delay(0.7);
            }
            while(fill3 > 4000){ // PUMP FILL4 FROM FILL3
              SHAPE_GROUP5.color("green");
              SHAPE_GROUP3.color("red");
              fill3 -= 20;
              fill4 += 20;
              dpSet("System1:Fill3.", fill3);
              dpSet("System1:Fill4.", fill4);
              delay(0.7);
            }
            while(fill2 > 4000){ // PUMP FILL4 FROM FILL2
              SHAPE_GROUP4.color("green");
              fill2 -= 20;
              fill4 += 20;
              dpSet("System1:Fill2.", fill2);
              dpSet("System1:Fill4.", fill4);
              delay(0.7);
            }
            while(fill4 > 4000 && fill4 < 9000){ // DAMP FROM FILL4
              SHAPE_GROUP6.color("green");
              SHAPE_GROUP4.color("red");
              SHAPE_GROUP5.color("red");
              fill4 -= 20;
              dpSet("System1:Fill4.", fill4);
              delay(0.7);
            }
            // if (fill3 == 5000){
            //   SHAPE_GROUP5.color("green");
            //   fill3 += -20;
            //   fill4 += +20;
            //   dpSet("System1:Fill3.", fill3);
            //   dpSet("System1:Fill4.", fill4);
            //   delay(0.7);
            // }
            // while(fill4 > 0 && fill4 < 6000){ //DUMP 4 TO OUT
            //   SHAPE_GROUP6.color("green");
            //   fill4 += -10;
            //   dpSet("System1:Fill4.", fill4);
            //   delay(0.7);
            // }
          }else{
            reset = true;
          }
        }
        // END OF AUTOMATIC MODE
        dpGet("System1:C1.", C1);
        dpGet("System1:C2.", C2);
        dpGet("System1:C3.", C3);
        dpGet("System1:C4.", C4);
        dpGet("System1:C5.", C5);
        dpGet("System1:C6.", C6);
        dpGet("System1:Fill.", fill);
        dpGet("System1:Fill2.", fill2);
        dpGet("System1:Fill3.", fill3);
        dpGet("System1:Fill4.", fill4);
        dpGet("System1:reset.", reset);
        if (C1){
          if (fill > 10000){
            TEXT_FIELD2.visible(TRUE);
            TEXT_FIELD2.text("Бачок #1 потiк");
            delay(2);
            reset = true;
          }else if(fill >= -20){
            SHAPE_GROUP1.color("green");
            fill += 10;
            dpSet("System1:Fill.", fill);
          }
        }else{
          SHAPE_GROUP1.color("red");
        }
        if (C2){
          if (fill2 > 10000){
            TEXT_FIELD2.visible(TRUE);
            TEXT_FIELD2.text("Бачок #2 потiк");
            delay(2);
            reset = true;
          }else if (fill >= 0){
            SHAPE_GROUP2.color("green");
            fill2 += 20;
            fill += -20;
            dpSet("System1:Fill.",fill);
            dpSet("System1:Fill2.",fill2);
          }else if (!C1 && fill <= 0){
            SHAPE_GROUP2.color("green");
          }
        }else{
          SHAPE_GROUP2.color("red");
        }
        if (C3){
          if (fill3 > 10000){
            TEXT_FIELD2.visible(TRUE);
            TEXT_FIELD2.text("Бачок #3 потiк");
            delay(2);
            reset = true;
          }else if (fill >= 0){
            SHAPE_GROUP3.color("green");
            fill3 += 20;
            fill += -20;
            dpSet("System1:Fill.",fill);
            dpSet("System1:Fill3.",fill3);
          }else if (!C1 && fill <= 0){
            SHAPE_GROUP3.color("green");
          }
        }else{
          SHAPE_GROUP3.color("red");
        }
        if (C4){
            if (fill4 > 10000){
            TEXT_FIELD2.visible(TRUE);
            TEXT_FIELD2.text("Бачок #4 потiк");
            delay(2);
            reset = true;
            }else if (fill2 >= 0){
              SHAPE_GROUP4.color("green");
              fill4 += 20;
              fill2 += -20;
              dpSet("System1:Fill4.",fill4);
              dpSet("System1:Fill2.",fill2);
            } else if (!C2 && fill2 <= 0){
              SHAPE_GROUP4.color("green");
            }
        }else{
          SHAPE_GROUP4.color("red");
        }
        if (C5){
          if (fill4 > 10000){
            TEXT_FIELD2.visible(TRUE);
            TEXT_FIELD2.text("Бачок #4 потiк");
            delay(2);
            reset = true;
            }else if (fill3 >= 0){
              SHAPE_GROUP5.color("green");
              fill4 += 20;
              fill3 += -20;
              dpSet("System1:Fill4.",fill4);
              dpSet("System1:Fill3.",fill3);
            } else if (!C3 && fill3 <= 0){
              SHAPE_GROUP5.color("green");
          }
        }else{
          SHAPE_GROUP5.color("red");
        }
        if (C6){
          if (fill4 >= 0){
            SHAPE_GROUP6.color("green");
            fill4 += -15;
            dpSet("System1:Fill4.",fill4);
          }else if ((!C4 && fill2 <= 0) || (!C5 && fill3 <= 0)){
            SHAPE_GROUP6.color("green");
          }
        }else{
          SHAPE_GROUP6.color("red");
        }
        if(reset){
          C1 = 0;
          C2 = 0;
          C3 = 0;
          C4 = 0;
          C5 = 0;
          C6 = 0;
          fill = 0;
          fill2 = 0;
          fill3 = 0;
          fill4 = 0;
          reset = 0;
          dpSet("System1:C1.", C1);
          dpSet("System1:C2.", C2);
          dpSet("System1:C3.", C3);
          dpSet("System1:C4.", C4);
          dpSet("System1:C5.", C5);
          dpSet("System1:C6.", C6);
          dpSet("System1:Fill.", fill);
          dpSet("System1:Fill2.", fill2);
          dpSet("System1:Fill3.", fill3);
          dpSet("System1:Fill4.", fill4);
          dpSet("System1:reset.", reset);
          TEXT_FIELD2.visible(FALSE);
        }
        delay(0.5);
    }
  }