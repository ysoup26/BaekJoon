<Page x:Class="WpfGUI.View.Login1"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
        xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
        xmlns:local="clr-namespace:WpfGUI.View"
        mc:Ignorable="d"
        Title="Window1" Height="1080"  Width="1920" >
    <Page.Resources>
        <ControlTemplate x:Key="roundbutton" TargetType="Button">
            <Grid>
                <Ellipse Fill="{TemplateBinding Background}" Stroke="{TemplateBinding Foreground}"/>
                <ContentPresenter HorizontalAlignment="Center" VerticalAlignment="Center"/>
            </Grid>
        </ControlTemplate>
    </Page.Resources>
    <Grid>
        <Image Source="/View/1-1.jpg" Stretch="Fill">
            <Image.Effect>
                <!-- BlurEffect 설정 -->
                <BlurEffect Radius="0"/>
            </Image.Effect>
        </Image>
        <Grid>
            <Grid.RowDefinitions>
                <RowDefinition Height="1*"></RowDefinition>
                <RowDefinition Height="5*"></RowDefinition>
                <RowDefinition Height="1*"></RowDefinition>
            </Grid.RowDefinitions>
            <Grid.ColumnDefinitions>
                <ColumnDefinition Width="2*"></ColumnDefinition>
                <ColumnDefinition Width="1.7*"></ColumnDefinition>
                <ColumnDefinition Width="2*"></ColumnDefinition>
            </Grid.ColumnDefinitions>
            <Border Grid.Row="1" Grid.Column="1" BorderBrush="Transparent" BorderThickness="2" CornerRadius="20" Background="#FF2E4567">
                <Grid>
                    
                    <Grid.Clip>
                        <RectangleGeometry RadiusX="20" RadiusY="20" Rect="0,0,568.63,767.43"/>
                    </Grid.Clip>
                    <Grid.RowDefinitions>
                        <RowDefinition Height="1.5*"></RowDefinition>
                        <RowDefinition Height="3*"></RowDefinition>
                        <RowDefinition Height="1*"></RowDefinition>
                    </Grid.RowDefinitions>
                    <Grid Grid.Row="0">
                        <StackPanel Orientation="Vertical" VerticalAlignment="Bottom">
                            <StackPanel Orientation="Horizontal" HorizontalAlignment="Center">
                                <Border Padding="30 6" Margin="0 0 10 0" Background="#FF4C5F7C" CornerRadius="15" BorderBrush="Transparent" BorderThickness="1">
                                    <Grid>
                                        <Button  Background="Transparent" BorderBrush="Transparent" Foreground="White" >Sign In</Button>
                                    </Grid>
                                </Border>
                                <Border Padding="30 5" Background="#FF14233F" CornerRadius="15" BorderBrush="Transparent" BorderThickness="1">
                                    <Grid>
                                        <Button  Background="Transparent" BorderBrush="Transparent" Foreground="White" >Sign Up</Button>
                                    </Grid>
                                </Border>
                            </StackPanel>
                            <TextBlock Margin="20" Text="Sign Up" Foreground="White" FontSize="30" HorizontalAlignment="Center" VerticalAlignment="Bottom" FontWeight="Bold"/>
                        </StackPanel>
                    </Grid>
                    <Grid Grid.Row="1">
                        <Grid.RowDefinitions>
                            <RowDefinition Height="1*"/>
                            <RowDefinition Height="1*"/>
                            <RowDefinition Height="1*"/>
                            <RowDefinition Height="0.5*"/>
                            <RowDefinition Height="1*"/>
                        </Grid.RowDefinitions>
                        <Border Grid.Row="0" Margin="30 15" CornerRadius="25" 
                                BorderBrush="Transparent" BorderThickness="1" Background="#FF4C5F7C">
                            <Grid>
                                <TextBox 
                                    Foreground="White" 
                                    Background="Transparent" 
                                    BorderThickness="0" 
                                    Padding="15,5" 
                                    VerticalContentAlignment="Center">Email
                                </TextBox>
                                <Image Source="/View/mail.256x185.png" Width="20" Height="20" Margin="5 0 15 0"
                                        HorizontalAlignment="Right"/>
                            </Grid>
                        </Border>
                        <Border Grid.Row="1" Margin="30 15" CornerRadius="25" 
                                BorderBrush="Transparent" BorderThickness="1" Background="#FF4C5F7C">
                            <Grid>
                                <TextBox 
                                    Foreground="White" 
                                    Background="Transparent" 
                                    BorderThickness="0" 
                                    Padding="15,5" 
                                    VerticalContentAlignment="Center">Username
                                </TextBox>
                                <Image Source="/View/user-profile.256x256.png" Width="20" Height="20" Margin="5 0 15 0"
                                        HorizontalAlignment="Right"/>
                            </Grid>
                        </Border>
                        <Border Grid.Row="2" Margin="30 15" CornerRadius="25" 
                                BorderBrush="Transparent" BorderThickness="1" Background="#FF4C5F7C">
                            <Grid>
                                <TextBox 
                                    Foreground="White" 
                                    Background="Transparent" 
                                    BorderThickness="0" 
                                    Padding="15,5" 
                                    VerticalContentAlignment="Center">Password
                                </TextBox>
                                <Image Source="/View/locked.211x256.png" Width="20" Height="20" Margin="5 0 15 0"
                                    HorizontalAlignment="Right"/>
                            </Grid>
                        </Border>
                        <Border  Grid.Row="3" Margin="30 0 " CornerRadius="25" BorderBrush="Transparent" BorderThickness="1">
                            <CheckBox Foreground="White" HorizontalAlignment="Right" VerticalAlignment="Center">Remember me</CheckBox>
                        </Border>
                        <Border Grid.Row="4" Margin="30 15" Background="#FF14233F" CornerRadius="25" BorderBrush="Transparent" BorderThickness="1">
                            <Grid>
                                <Button  Background="Transparent" BorderBrush="Transparent" Foreground="White" Click="Button_Click" >Sign up -></Button>
                            </Grid>
                        </Border>
                    </Grid>
                    <Grid Grid.Row="2">

                        <StackPanel Orientation="Vertical" VerticalAlignment="Center">
                            <StackPanel Orientation="Horizontal" HorizontalAlignment="Center">

                            </StackPanel>
                            <StackPanel Margin="10" Orientation="Horizontal" HorizontalAlignment="Center">
                                <Button Template="{StaticResource roundbutton}" Width="40" Height="40" 
                                       Margin="0 0 15 0"
                                        Background="#FF4C5F7C" BorderBrush="Transparent" Foreground="White">G</Button>
                                <Button Template="{StaticResource roundbutton}" Width="40" Height="40" 
                                        Margin="0 0 15 0"
                                        Background="#FF4C5F7C" BorderBrush="Transparent" Foreground="White">F</Button>
                                <Button Template="{StaticResource roundbutton}" Width="40" Height="40" 
                                        Margin="0 0 15 0"
                                        Background="#FF4C5F7C" BorderBrush="Transparent" Foreground="White">T</Button>
                                <Button Template="{StaticResource roundbutton}" Width="40" Height="40" 
                                    Background="#FF4C5F7C" BorderBrush="Transparent" Foreground="White">G</Button>
                            </StackPanel>
                            
                        </StackPanel>
                    </Grid>
                </Grid>
            </Border>
        </Grid>
    </Grid>
</Page>
   