package com.jb;

import java.util.ArrayList;

import javafx.geometry.Pos;
import javafx.scene.Node;
import javafx.scene.layout.StackPane;
import javafx.scene.web.WebEngine;
import javafx.scene.web.WebView;

public class BrowserTab{

    private TabButton tabButton;
    private StackPane stackPane;
    private WebView webView;
    private WebEngine webEngine;

    private ArrayList<Node> nodes;

    public BrowserTab(){
        tabButton = new TabButton();
        stackPane = new StackPane();
        webView = new WebView();
        webEngine = webView.getEngine();

        webEngine.load("https://google.com");
        stackPane.getChildren().add(webView);

        stackPane.setId("tab-pane");
        tabButton.setTranslateX((Main.getNoOfTabs()-1)*155 + 5);

        StackPane.setAlignment(stackPane, Pos.TOP_LEFT);
        StackPane.setAlignment(tabButton, Pos.TOP_LEFT);

        nodes = new ArrayList<>();
        nodes.add(tabButton);
        nodes.add(stackPane);

    }

    public ArrayList<Node> getNodes(){
        return nodes;
    }

}
