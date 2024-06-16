package com.jb;

import java.util.concurrent.atomic.AtomicInteger;

import javafx.animation.ParallelTransition;
import javafx.animation.TranslateTransition;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.control.ToggleButton;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;
import javafx.util.Duration;

public class TabButton extends StackPane{
    
    private ToggleButton toggleButton;
    private Button closeBtn;
    @SuppressWarnings("unused")
    private BrowserTab tab;

    public TabButton(BrowserTab tab){
        toggleButton = new ToggleButton("Home");
        closeBtn = new Button("");
        this.tab = tab;
        
        this.setId("tab-button-container");
        toggleButton.setId("tab-button");
        closeBtn.setId("tab-close-button");

        toggleButton.setSelected(true);
        toggleButton.setToggleGroup(Main.getToggleGroup());
        closeBtn.setTranslateX(120);

        StackPane.setAlignment(toggleButton, Pos.TOP_LEFT);
        StackPane.setAlignment(closeBtn, Pos.TOP_LEFT);

        this.getChildren().addAll(toggleButton, closeBtn);



        toggleButton.setOnAction(e -> {
            if(!toggleButton.isSelected()) toggleButton.setSelected(true);
            tab.bringToFront();
        });

        closeBtn.setOnAction(e -> {
            if(Main.getNoOfTabs() == 1) ((Stage)this.getScene().getWindow()).close();
            else{
                ((StackPane)(this.getScene().getRoot())).getChildren().removeAll(tab.getNodes());
                int index = Main.getTabs().indexOf(tab);
                Main.getTabs().remove(tab);

                ParallelTransition pt = new ParallelTransition();
                TranslateTransition tt = new TranslateTransition(new Duration(250), Main.getNewTabBtn());
                tt.setByX(-155);
                for(int i=index;i<Main.getNoOfTabs();i++){
                    TranslateTransition ttTabs = new TranslateTransition(new Duration(250), Main.getTabs().get(i).getNodes().get(0));
                    ttTabs.setByX(-155);
                    pt.getChildren().add(ttTabs);
                }
                pt.getChildren().add(tt);
                tab.shrink();
                pt.play();

                
                
                // if(index.get()<Main.getNoOfTabs()){
                //     TranslateTransition ttTabs = new TranslateTransition(new Duration(250), Main.getTabs().get(index.get()).getNodes().get(0));
                //     ttTabs.setByX(-155);
                //     ttTabs.play();
                //     ttTabs.setOnFinished(ev -> {
                //         index.incrementAndGet();
                //         if(index.get()<Main.getNoOfTabs()){
                //             ttTabs.setNode(Main.getTabs().get(index.get()).getNodes().get(0));
                //             ttTabs.play();
                //             // pt.getChildren().add(ttTabs);
                //         }
                //     });
                // }
            }
        });

    }


}
