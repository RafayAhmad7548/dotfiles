package com.jb;

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
        toggleButton.setToggleGroup(JBrowse.getToggleGroup());
        closeBtn.setTranslateX(120);

        StackPane.setAlignment(toggleButton, Pos.TOP_LEFT);
        StackPane.setAlignment(closeBtn, Pos.TOP_LEFT);

        this.getChildren().addAll(toggleButton, closeBtn);



        toggleButton.setOnAction(e -> {
            if(!toggleButton.isSelected()) toggleButton.setSelected(true);
            tab.bringToFront();
        });

        closeBtn.setOnAction(e -> {
            if(JBrowse.getNoOfTabs() == 1) ((Stage)this.getScene().getWindow()).close();
            else{
                int index = JBrowse.getTabs().indexOf(tab);
                JBrowse.getTabs().remove(tab);
                
                if(index<JBrowse.getNoOfTabs()) JBrowse.getTabs().get(index).getTabButton().toggleButton.setSelected(true);
                else JBrowse.getTabs().get(index-1).getTabButton().toggleButton.setSelected(true);

                ParallelTransition pt = new ParallelTransition();
                TranslateTransition tt = new TranslateTransition(new Duration(250), JBrowse.getNewTabBtn());
                tt.setByX(-155);
                for(int i=index;i<JBrowse.getNoOfTabs();i++){
                    TranslateTransition ttTabs = new TranslateTransition(new Duration(250), JBrowse.getTabs().get(i).getTabButton());
                    ttTabs.setByX(-155);
                    pt.getChildren().add(ttTabs);
                }
                tab.shrink();
                tt.play();
                pt.play();
            }
        });

    }


}
