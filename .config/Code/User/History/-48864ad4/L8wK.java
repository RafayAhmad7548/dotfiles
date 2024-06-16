package com.jb;

import java.util.ArrayList;

import javafx.animation.ParallelTransition;
import javafx.animation.ScaleTransition;
import javafx.animation.TranslateTransition;
import javafx.geometry.Pos;
import javafx.scene.Node;
import javafx.scene.layout.StackPane;
import javafx.scene.web.WebEngine;
import javafx.scene.web.WebView;
import javafx.util.Duration;

public class BrowserTab{

    private TabButton tabButton;
    private StackPane stackPane;
    private WebView webView;
    private WebEngine webEngine;

    private TranslateTransition tt;
    private ScaleTransition st;
    private ParallelTransition pt;

    public BrowserTab(){
        tabButton = new TabButton(this);
        stackPane = new StackPane();
        webView = new WebView();
        webEngine = webView.getEngine();

        webEngine.load("https://google.com");
        stackPane.getChildren().add(webView);

        stackPane.setId("tab-pane");
        tabButton.setTranslateX((Main.getNoOfTabs()-1)*155 + 5 + 80);
        tabButton.setScaleX(0);

        tt = new TranslateTransition(new Duration(250), tabButton);
        st = new ScaleTransition(new Duration(250), tabButton);
        pt = new ParallelTransition(tt, st);
        grow();

        StackPane.setAlignment(stackPane, Pos.TOP_LEFT);
        StackPane.setAlignment(tabButton, Pos.TOP_LEFT);

    }

    public void bringToFront(){
        stackPane.toFront();
    }

    public void grow(){
        tt.setByX(75);
        st.setByX(1);
        pt.play();
    }
    public void shrink(){
        tt.setByX(-75);
        st.setByX(-1);
        pt.play();
    }

    

}
