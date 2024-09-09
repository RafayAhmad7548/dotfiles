package com.rutils;

import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;
import javafx.scene.layout.Region;
import javafx.scene.layout.VBox;
import javafx.scene.text.Font;

public class SceneCreator{
	
	public static void createLoginScene(){
		VBox root = new VBox();
        Scene scene = new Scene(root);

        root.requestFocus();
        root.setAlignment(Pos.CENTER);
        root.setSpacing(25);
        root.minWidthProperty().bind(stage.widthProperty());
        root.minHeightProperty().bind(stage.heightProperty());

        Label label = new Label("Login");
        label.setFont(new Font(40));

        Region spcr1 = new Region();
        spcr1.setPrefHeight(20);

        TextField username = new TextField();
        username.setPromptText("username");
        username.setFont(new Font(20));
        username.maxWidthProperty().bind(scene.widthProperty().divide(3));
        username.setPrefHeight(50);

        PasswordField password = new PasswordField();
        password.setPromptText("password");
        password.setFont(new Font(20));
        password.maxWidthProperty().bind(scene.widthProperty().divide(3));
        password.setPrefHeight(50);

        Label info = new Label();
        info.setPrefHeight(20);

        Button login = new Button("Login");
        login.setFont(new Font(20));
        login.maxWidthProperty().bind(scene.widthProperty().divide(3));
        login.setPrefHeight(50);
        login.setOnAction(e -> handleLogin(username, password, info));

        Label or = new Label("OR");
        or.setFont(new Font(30));

        Button signup = new Button("Sign Up");
        signup.setFont(new Font(20));
        signup.maxWidthProperty().bind(scene.widthProperty().divide(3));
        signup.setPrefHeight(50);
        signup.setOnAction(e -> stage.setScene(registerScene));

        root.getChildren().addAll(label, spcr1, username, password, info, login, or, signup);
        return scene;

	}

	public static void createRegisterScene(){
		
	}

}
