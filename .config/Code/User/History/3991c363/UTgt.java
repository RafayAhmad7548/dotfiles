package com.jb;

import javafx.animation.ParallelTransition;
import javafx.animation.ScaleTransition;
import javafx.animation.TranslateTransition;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.control.ToggleButton;
import javafx.scene.layout.StackPane;
import javafx.scene.web.WebEngine;
import javafx.scene.web.WebView;
import javafx.stage.Stage;
import javafx.util.Duration;

public class BrowserTab1 extends StackPane{
    
    private ToggleButton button;
    private StackPane pane;
    private Button closeBtn;

    private WebView webView;
    private WebEngine webEngine;

    public BrowserTab1(){
        button = new ToggleButton("Home");
        pane = new StackPane();
        closeBtn = new Button("");

        webView = new WebView();
        webEngine = webView.getEngine();

        webEngine.load("https://google.com");
        pane.getChildren().add(webView);
        
        StackPane.setAlignment(button, Pos.TOP_LEFT);
        StackPane.setAlignment(closeBtn, Pos.TOP_LEFT);
        StackPane.setAlignment(pane, Pos.TOP_LEFT);
        
        // button.setId("tab-button");
        // closeBtn.setId("tab-close-button");
        // pane.setId("tab-pane");

        this.getChildren().add(button);
        this.getChildren().add(closeBtn);
        this.getChildren().add(pane);
        
        button.setTranslateX((Main.getNoOfTabs()-1)*155 + 5);
        closeBtn.setTranslateX(button.getTranslateX()+120);

        button.setScaleX(0);
        button.setTranslateX(button.getTranslateX() - 75);

        TranslateTransition tt = new TranslateTransition(new Duration(250), button);
        tt.setByX(75);
        ScaleTransition st = new ScaleTransition(new Duration(250), button);
        st.setByX(1);
        ParallelTransition animate = new ParallelTransition(tt, st);
        animate.play();



        closeBtn.setOnAction(e -> {
            if(Main.getNoOfTabs() == 1) ((Stage)this.getScene().getWindow()).close();
            else{
                ((StackPane)this.getScene().getRoot()).getChildren().remove(Main.getNoOfTabs());
                Main.setNoOfTabs(Main.getNoOfTabs()-1);

                tt.setByX(-75);
                st.setByX(-1);
                animate.play();


            }
        });
        
    }


}
