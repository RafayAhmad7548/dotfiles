package com.jb;

import javafx.animation.TranslateTransition;
import javafx.scene.control.Tab;
import javafx.scene.control.TabPane;
import javafx.scene.web.WebEngine;
import javafx.scene.web.WebView;
import javafx.stage.Stage;
import javafx.util.Duration;

public class BrowserTab1 extends Tab{
    
    private WebEngine webEngine;
    private WebView webView;
    private TabPane tabPane;
    
    public BrowserTab1(){
        super();
        webView = new WebView();
        webEngine = webView.getEngine();
        this.setContent(webView);
        this.setText("Home ");

        
        this.setOnCloseRequest(e -> {
            tabPane = super.getTabPane();
            if(tabPane.getTabs().size() == 1){
               ((Stage)(tabPane.getParent().getScene().getWindow())).close();
            }
            else{
                TranslateTransition transition = new TranslateTransition(new Duration(250), Main.getNewTabBtn());
                transition.setByX(-150);
                transition.play();
            }
        });
    }

    public WebEngine getWebEngine(){
        return webEngine;
    }
    public WebView getWebView(){
        return webView;
    }


}