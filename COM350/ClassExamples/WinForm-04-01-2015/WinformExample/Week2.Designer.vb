<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Week2
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.fbdSelector = New System.Windows.Forms.FolderBrowserDialog()
        Me.textboxStartingLocation = New System.Windows.Forms.TextBox()
        Me.buttonLauncher = New System.Windows.Forms.Button()
        Me.buttonWhatever = New System.Windows.Forms.Button()
        Me.comboBoxColors = New System.Windows.Forms.ComboBox()
        Me.comboBoxManual = New System.Windows.Forms.ComboBox()
        Me.comboBoxGenerics = New System.Windows.Forms.ComboBox()
        Me.comboBoxStates = New System.Windows.Forms.ComboBox()
        Me.textboxIndex = New System.Windows.Forms.TextBox()
        Me.textboxValue = New System.Windows.Forms.TextBox()
        Me.MenuStrip1 = New System.Windows.Forms.MenuStrip()
        Me.FileToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem()
        Me.NewToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem()
        Me.ToolStripSeparator1 = New System.Windows.Forms.ToolStripSeparator()
        Me.ExitToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem()
        Me.EditToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem()
        Me.LaunchTimerToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem()
        Me.MenuStrip1.SuspendLayout()
        Me.SuspendLayout()
        '
        'textboxStartingLocation
        '
        Me.textboxStartingLocation.Location = New System.Drawing.Point(13, 28)
        Me.textboxStartingLocation.Name = "textboxStartingLocation"
        Me.textboxStartingLocation.Size = New System.Drawing.Size(258, 20)
        Me.textboxStartingLocation.TabIndex = 0
        '
        'buttonLauncher
        '
        Me.buttonLauncher.Location = New System.Drawing.Point(404, 25)
        Me.buttonLauncher.Name = "buttonLauncher"
        Me.buttonLauncher.Size = New System.Drawing.Size(79, 23)
        Me.buttonLauncher.TabIndex = 1
        Me.buttonLauncher.Text = "Launch"
        Me.buttonLauncher.UseVisualStyleBackColor = True
        '
        'buttonWhatever
        '
        Me.buttonWhatever.Location = New System.Drawing.Point(404, 72)
        Me.buttonWhatever.Name = "buttonWhatever"
        Me.buttonWhatever.Size = New System.Drawing.Size(79, 23)
        Me.buttonWhatever.TabIndex = 2
        Me.buttonWhatever.Text = "Whatever"
        Me.buttonWhatever.UseVisualStyleBackColor = True
        '
        'comboBoxColors
        '
        Me.comboBoxColors.FormattingEnabled = True
        Me.comboBoxColors.Items.AddRange(New Object() {"Red", "Orange", "Yellow", "Green", "Blue", "Indigo", "Violet"})
        Me.comboBoxColors.Location = New System.Drawing.Point(13, 75)
        Me.comboBoxColors.Name = "comboBoxColors"
        Me.comboBoxColors.Size = New System.Drawing.Size(258, 21)
        Me.comboBoxColors.TabIndex = 3
        '
        'comboBoxManual
        '
        Me.comboBoxManual.FormattingEnabled = True
        Me.comboBoxManual.Location = New System.Drawing.Point(13, 119)
        Me.comboBoxManual.Name = "comboBoxManual"
        Me.comboBoxManual.Size = New System.Drawing.Size(258, 21)
        Me.comboBoxManual.TabIndex = 4
        '
        'comboBoxGenerics
        '
        Me.comboBoxGenerics.FormattingEnabled = True
        Me.comboBoxGenerics.Location = New System.Drawing.Point(13, 162)
        Me.comboBoxGenerics.Name = "comboBoxGenerics"
        Me.comboBoxGenerics.Size = New System.Drawing.Size(258, 21)
        Me.comboBoxGenerics.TabIndex = 5
        '
        'comboBoxStates
        '
        Me.comboBoxStates.FormattingEnabled = True
        Me.comboBoxStates.Location = New System.Drawing.Point(13, 211)
        Me.comboBoxStates.Name = "comboBoxStates"
        Me.comboBoxStates.Size = New System.Drawing.Size(258, 21)
        Me.comboBoxStates.TabIndex = 6
        '
        'textboxIndex
        '
        Me.textboxIndex.Location = New System.Drawing.Point(277, 212)
        Me.textboxIndex.Name = "textboxIndex"
        Me.textboxIndex.Size = New System.Drawing.Size(76, 20)
        Me.textboxIndex.TabIndex = 7
        '
        'textboxValue
        '
        Me.textboxValue.Location = New System.Drawing.Point(388, 212)
        Me.textboxValue.Name = "textboxValue"
        Me.textboxValue.Size = New System.Drawing.Size(76, 20)
        Me.textboxValue.TabIndex = 8
        '
        'MenuStrip1
        '
        Me.MenuStrip1.Items.AddRange(New System.Windows.Forms.ToolStripItem() {Me.FileToolStripMenuItem, Me.EditToolStripMenuItem})
        Me.MenuStrip1.Location = New System.Drawing.Point(0, 0)
        Me.MenuStrip1.Name = "MenuStrip1"
        Me.MenuStrip1.Size = New System.Drawing.Size(539, 24)
        Me.MenuStrip1.TabIndex = 9
        Me.MenuStrip1.Text = "MenuStrip1"
        '
        'FileToolStripMenuItem
        '
        Me.FileToolStripMenuItem.DropDownItems.AddRange(New System.Windows.Forms.ToolStripItem() {Me.NewToolStripMenuItem, Me.ToolStripSeparator1, Me.ExitToolStripMenuItem})
        Me.FileToolStripMenuItem.Name = "FileToolStripMenuItem"
        Me.FileToolStripMenuItem.Size = New System.Drawing.Size(37, 20)
        Me.FileToolStripMenuItem.Text = "&File"
        '
        'NewToolStripMenuItem
        '
        Me.NewToolStripMenuItem.Name = "NewToolStripMenuItem"
        Me.NewToolStripMenuItem.ShortcutKeys = CType((System.Windows.Forms.Keys.Control Or System.Windows.Forms.Keys.N), System.Windows.Forms.Keys)
        Me.NewToolStripMenuItem.Size = New System.Drawing.Size(152, 22)
        Me.NewToolStripMenuItem.Text = "&New"
        '
        'ToolStripSeparator1
        '
        Me.ToolStripSeparator1.Name = "ToolStripSeparator1"
        Me.ToolStripSeparator1.Size = New System.Drawing.Size(149, 6)
        '
        'ExitToolStripMenuItem
        '
        Me.ExitToolStripMenuItem.Name = "ExitToolStripMenuItem"
        Me.ExitToolStripMenuItem.ShortcutKeys = CType((System.Windows.Forms.Keys.Alt Or System.Windows.Forms.Keys.F4), System.Windows.Forms.Keys)
        Me.ExitToolStripMenuItem.Size = New System.Drawing.Size(152, 22)
        Me.ExitToolStripMenuItem.Text = "E&xit"
        '
        'EditToolStripMenuItem
        '
        Me.EditToolStripMenuItem.DropDownItems.AddRange(New System.Windows.Forms.ToolStripItem() {Me.LaunchTimerToolStripMenuItem})
        Me.EditToolStripMenuItem.Name = "EditToolStripMenuItem"
        Me.EditToolStripMenuItem.Size = New System.Drawing.Size(39, 20)
        Me.EditToolStripMenuItem.Text = "&Edit"
        '
        'LaunchTimerToolStripMenuItem
        '
        Me.LaunchTimerToolStripMenuItem.Name = "LaunchTimerToolStripMenuItem"
        Me.LaunchTimerToolStripMenuItem.Size = New System.Drawing.Size(152, 22)
        Me.LaunchTimerToolStripMenuItem.Text = "&Launch Timer"
        '
        'Week2
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(539, 282)
        Me.Controls.Add(Me.textboxValue)
        Me.Controls.Add(Me.textboxIndex)
        Me.Controls.Add(Me.comboBoxStates)
        Me.Controls.Add(Me.comboBoxGenerics)
        Me.Controls.Add(Me.comboBoxManual)
        Me.Controls.Add(Me.comboBoxColors)
        Me.Controls.Add(Me.buttonWhatever)
        Me.Controls.Add(Me.buttonLauncher)
        Me.Controls.Add(Me.textboxStartingLocation)
        Me.Controls.Add(Me.MenuStrip1)
        Me.MainMenuStrip = Me.MenuStrip1
        Me.Name = "Week2"
        Me.Text = "Form1"
        Me.MenuStrip1.ResumeLayout(False)
        Me.MenuStrip1.PerformLayout()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents fbdSelector As System.Windows.Forms.FolderBrowserDialog
    Friend WithEvents textboxStartingLocation As System.Windows.Forms.TextBox
    Friend WithEvents buttonLauncher As System.Windows.Forms.Button
    Friend WithEvents buttonWhatever As System.Windows.Forms.Button
    Friend WithEvents comboBoxColors As System.Windows.Forms.ComboBox
    Friend WithEvents comboBoxManual As System.Windows.Forms.ComboBox
    Friend WithEvents comboBoxGenerics As System.Windows.Forms.ComboBox
    Friend WithEvents comboBoxStates As System.Windows.Forms.ComboBox
    Friend WithEvents textboxIndex As System.Windows.Forms.TextBox
    Friend WithEvents textboxValue As System.Windows.Forms.TextBox
    Friend WithEvents MenuStrip1 As System.Windows.Forms.MenuStrip
    Friend WithEvents FileToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
    Friend WithEvents NewToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
    Friend WithEvents ToolStripSeparator1 As System.Windows.Forms.ToolStripSeparator
    Friend WithEvents ExitToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
    Friend WithEvents EditToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
    Friend WithEvents LaunchTimerToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem

End Class
