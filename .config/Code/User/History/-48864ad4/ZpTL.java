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

    private ArrayList<Node> nodes;

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

        TranslateTransition tt = new TranslateTransition(new Duration(250), tabButton);
        tt.setByX(75);
        ScaleTransition st = new ScaleTransition(new Duration(250), tabButton);
        st.setByX(1);
        ParallelTransition pt = new ParallelTransition(tt, st);
        pt.play();

        StackPane.setAlignment(stackPane, Pos.TOP_LEFT);
        StackPane.setAlignment(tabButton, Pos.TOP_LEFT);

        nodes = new ArrayList<>();
        nodes.add(tabButton);
        nodes.add(stackPane);

    }

    public void grow(){
        
    }
    public void shrink(){
        
    }

    public ArrayList<Node> getNodes(){
        return nodes;
    }

}
